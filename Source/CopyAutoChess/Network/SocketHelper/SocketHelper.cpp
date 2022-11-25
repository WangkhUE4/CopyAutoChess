// Copyright Epic Games, Inc. All Rights Reserved.
#include "SocketHelper.h"
#include "CopyAutoChess/CopyAutoChessDefine.h"
#include "SocketSubsystem.h"
#include "Networking/Public/Interfaces/IPv4/IPv4Address.h"
#include "../Protobuf/csprotocol.pb.h"
#include "Misc/AssertionMacros.h"
#include "zconf.h"
#include "zlib.h"
#include "openssl/aes.h"


FSocketHelper::~FSocketHelper()
{
	disconnect();
}

void FSocketHelper::testPrint()
{
	UE_LOG(LogCopyAutoChess, Error, TEXT("FSocketHelper::testPrint"));
}

void FSocketHelper::connect(const FString ip, int32 port)
{
	FIPv4Address ipAddress;
	ensureMsgf(FIPv4Address::Parse(ip, ipAddress), TEXT("解析地址错误"));

	//创建一个addr存放ip地址和端口
	TSharedPtr<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ipAddress.Value);
	addr->SetPort(port);

	//创建客户端socket
	m_socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);
	ensureMsgf(m_socket, TEXT("创建套接字失败"));
	int32 sendBufferSize = 0;
	m_socket->SetSendBufferSize(1024 * 15, sendBufferSize);

	//连接成功
	if (m_socket->Connect(*addr))
	{
		UE_LOG(LogCopyAutoChess, Warning, TEXT("Connect Succeed!"));
		m_isConnect = true;

		ensureMsgf(m_thread.get_id() == std::thread::id(), TEXT("FSocketHelper, m_thread is not exit!"));
		m_thread = std::thread{ std::bind(&FSocketHelper::recv, this) };
	}
	//连接失败
	else
	{
		UE_LOG(LogCopyAutoChess, Warning, TEXT("Connect Failed!"));
		m_isConnect = false;
	}
}

void FSocketHelper::disconnect()
{
	m_isConnect = false;
	if (m_thread.joinable())
	{
		m_thread.join();
	}
	
	if (m_socket)
	{
		m_socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(m_socket);
		m_socket = nullptr;
	}
}

void FSocketHelper::send(msg::CSMsgID reqMsgId, const msg::CSReqBody& msgBody, msg::CSMsgID rspMsgId, const RspCall& rspCall)
{
	m_msgRspCallMap.Add(rspMsgId, rspCall);

	sendMsg(reqMsgId, msgBody);
}


void FSocketHelper::recv()
{
	while (m_isConnect)
	{
		recvMsg();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void FSocketHelper::sendMsg(msg::CSMsgID reqMsgId, const msg::CSReqBody& msgBody)
{
	uint32 bodySize = msgBody.ByteSize();

	bool needCompress = false;
	if (bodySize >= 1024 * 2)
	{
		needCompress = true;
	}

	//1.序列化
	m_sendBufferTempSerialize.reserve(bodySize);
	if (!msgBody.SerializeToArray(m_sendBufferTempSerialize.buffer, bodySize))
	{
		return;
	}
	uint8* bufferEncrypt = m_sendBufferTempSerialize.buffer;

	char dataStr[22];
	memcpy((uint8*)dataStr, bufferEncrypt, 8);
	dataStr[8] = '\0';
	UE_LOG(LogCopyAutoChess, Warning, TEXT("m_socket->Send Success! msgId : %d, bodySize : %d, bufferEncrypt : %s"), reqMsgId, bodySize, dataStr);

	//2.压缩
	if (needCompress)
	{
		uLongf temLen = compressBound(bodySize);
		m_sendBufferTempZip.reserve(temLen);
		ensureMsgf(compress(m_sendBufferTempZip.buffer, &temLen, m_sendBufferTempSerialize.buffer, bodySize) == 0, TEXT("FSocketHelper::sendMsg, compress error!"));
		bufferEncrypt = m_sendBufferTempZip.buffer;
		bodySize = temLen;
	}

	memcpy((uint8*)dataStr, bufferEncrypt, 8);
	dataStr[8] = '\0';
	UE_LOG(LogCopyAutoChess, Warning, TEXT("m_socket->Send Success! msgId : %d, bodySize : %d, bufferEncrypt compress : %s"), reqMsgId, bodySize, dataStr);

	//3.加密
	int encryptLen = (16 - bodySize%16) + bodySize;
	m_sendBufferTempEncrypt.reserve(encryptLen);
	m_sendBufferTempEncrypt.copy(bufferEncrypt, bodySize);
	const std::string& key = m_key;
	m_sendBufferKey.reserve(key.size());
	m_sendBufferKey.copy((uint8*)key.c_str(), key.size());
	m_sendBufferTempEncryptOut.reserve(bodySize);//bodySize是不是应该换为encryptLen？
	AES_KEY aes;
	if (AES_set_encrypt_key((unsigned char*)key.c_str(), 128, &aes) != 0)
	{
		return;
	}
	AES_cbc_encrypt(m_sendBufferTempEncrypt.buffer, m_sendBufferTempEncryptOut.buffer, encryptLen, &aes, m_sendBufferKey.buffer, AES_ENCRYPT);
	bodySize = encryptLen;

	memcpy((uint8*)dataStr, m_sendBufferTempEncryptOut.buffer, 16);
	dataStr[16] = '\0';
	UE_LOG(LogCopyAutoChess, Warning, TEXT("m_socket->Send Success! msgId : %d, bodySize : %d, Out.buffer : %s, key : %s"), reqMsgId, bodySize, dataStr, key.c_str());

	//4.构造包头
	msg::CSHead head;
	head.set_msgid(reqMsgId);
	head.set_compress(needCompress);
	head.set_bodylen(bodySize);
	head.set_serverid(m_serverId);

	//5.构造发送缓冲区
	int32 dataSize = head.ByteSize() + bodySize + 1;
	m_sendBuffer.reserve(dataSize);
	uint8* data = m_sendBuffer.buffer;
	uint8* ptr = data;
	//head size
	ptr[0] = (uint8)head.ByteSize();
	ptr++;
	//head data
	if (!head.SerializeToArray(ptr, head.ByteSize()))
	{
		return;
	}
	ptr += head.ByteSize();

	memcpy((uint8*)dataStr, data, 5);
	dataStr[5] = '\0';
	UE_LOG(LogCopyAutoChess, Warning, TEXT("m_socket->Send Success! msgId : %d, headSize : %d, bodySize : %d, headdata : %s"), reqMsgId, head.ByteSize(), bodySize, dataStr);

	//body data
	memcpy(ptr, m_sendBufferTempEncryptOut.buffer, bodySize);

	//6.发送
	int32 sendDataSize = dataSize;
	while (sendDataSize > 0)
	{
		memcpy((uint8*)dataStr, data, 21);
		dataStr[21] = '\0';
		UE_LOG(LogCopyAutoChess, Warning, TEXT("m_socket->Send Success! msgId : %d, headSize : %d, bodySize : %d, dataStr : %s"), reqMsgId, head.ByteSize(), bodySize, dataStr);

		int32 sendSizeOnce = 0;
		if (!m_socket->Send(data, dataSize, sendSizeOnce))
		{
			UE_LOG(LogCopyAutoChess, Error, TEXT("m_socket->Send Error!"));
			return;
		}

		sendDataSize -= sendSizeOnce;
		data += sendSizeOnce;
	}

}

void FSocketHelper::recvMsg()
{
	uint32 pendingSize = 0;
	if (!m_socket->HasPendingData(pendingSize))
	{
		return;
	}
	m_recvBufferTemp.reserve(FMath::Min(pendingSize, 65507u));
	int32 recvSize = 0;
	if (!m_socket->Recv(m_recvBufferTemp.buffer, m_recvBufferTemp.bufferCapacity, recvSize))
	{
		return;
	}
	m_recvBuffer.Append(m_recvBufferTemp.buffer, recvSize);

_RECV_MSG:
	uint8* ptr = m_recvBuffer.GetData();
	
	//1.解析包头
	uint32 headSize = uint16(ptr[0]);
	if ((uint32)m_recvBuffer.Num() < headSize + 1)
	{
		return;
	}
	msg::CSHead head;
	if (!head.ParseFromArray((void*)(ptr + 1), headSize))
	{
		return;
	}

	//解析包体
	int32 totalSize = 1 + headSize + head.bodylen();
	if (m_recvBuffer.Num() < totalSize)
	{
		return;
	}
	uint8* bodyPtr = ptr + 1 + headSize;

	//2.解密
	int bodySize = head.bodylen();
	ensureMsgf(bodySize % 16 == 0, TEXT("FSocketHelper::recvMsg, Error: bodySize 不是16的倍数"));
	const std::string& key = m_key;
	m_recvBufferKey.reserve(key.size());
	m_recvBufferKey.copy((uint8*)key.c_str(), key.size());
	m_recvBufferTempDecrypt.reserve(bodySize);
	AES_KEY aes;
	if (bodySize % 16 != 0 || AES_set_decrypt_key((unsigned char*)key.c_str(), 128, &aes) != 0)
	{
		FString path = FPaths::ProjectSavedDir() / FString::Printf(TEXT("%s_%s"), *FDateTime::Now().ToString(), UTF8_TO_TCHAR(key.c_str()));
		FFileHelper::SaveStringToFile(FString::FromHexBlob(bodyPtr, bodySize), *path);
		return;
	}
	AES_cbc_encrypt(bodyPtr, m_recvBufferTempDecrypt.buffer, bodySize, &aes, m_recvBufferKey.buffer, AES_DECRYPT);
	int32 extraSize = m_recvBufferTempDecrypt.buffer[bodySize - 1];
	ensureMsgf(extraSize >=0 && extraSize <= 16, TEXT("FSocketHelper::recvMsg, extraSize Error"));
	bodySize -= extraSize;
	bodyPtr = m_recvBufferTempDecrypt.buffer;

	//3.解压
	if (head.compress())
	{
		uint32 unZipSize = bodySize;
		uLongf retUnZipSize = 0;
		while (true)
		{
			unZipSize *= 16;
			m_recvBufferTempUnZip.reserve(unZipSize);
			int retUnCompress = uncompress(m_recvBufferTempUnZip.buffer, &retUnZipSize, bodyPtr, bodySize);
			ensureMsgf(retUnCompress == 0, TEXT("FSocketHelper::recvMsg, uncompress Error"));
			if (retUnCompress != 0)
			{
				return;
			}
			if (retUnZipSize <= unZipSize)
			{
				break;
			}
		}
		bodyPtr = m_recvBufferTempUnZip.buffer;
		bodySize = retUnZipSize;
	}

	//4.反序列化
	int32 msgId = head.msgid();
	if (msgId > 2000 && msgId < 3000)
	{
		//ntf
	}
	else
	{
		//rsp
		auto rspBody = std::make_shared<msg::CSRspBody>();
		if (!rspBody->ParsePartialFromArray(bodyPtr, bodySize))
		{
			return;
		}
		if (msgId == msg::RSP_HEART)
		{
		}
		else 
		{
			if (msgId == msg::RSP_APPLY_HALL_SERVER)
			{
				auto msgData = rspBody->applyhallserver();
				m_key = msgData.key();
				m_serverId = msgData.serverid();
			}

			RspCall* resCall = m_msgRspCallMap.Find(msgId);
			if (resCall)
			{
				(*resCall)(*rspBody);
			}
		}
	}

	m_recvBuffer.RemoveAt(0, 1 + headSize + head.bodylen());
	if (m_recvBuffer.Num() > 0)
	{
		goto _RECV_MSG;
	}
}
