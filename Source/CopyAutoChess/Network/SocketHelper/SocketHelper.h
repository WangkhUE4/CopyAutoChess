// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "ISocketHelper.h"
#include "Sockets.h"
#include <thread>


class FSocketHelper : public ISocketHelper
{
private:
	struct FastBuffer
	{
		uint8* buffer;
		int32  bufferCapacity;

		void reserve(int32 size)
		{
			if (size > bufferCapacity || 
				 size < bufferCapacity / 8 && bufferCapacity > 1024 * 1024)
			{
				delete[]buffer;

				bufferCapacity = size * 2;
				buffer = new uint8[bufferCapacity];
			}
			//memset(buffer, 0, bufferCapacity);
		}

		void copy(uint8* src, int32 srcLen)
		{
			this->reserve(srcLen);

			memcpy(this->buffer, src, srcLen);
		}

		FastBuffer()
		{
			bufferCapacity = 1024 * 5;
			buffer = new uint8[bufferCapacity];
		}
		~FastBuffer()
		{
			bufferCapacity = 0;
			delete[]buffer;
		}
	};

public:
	virtual ~FSocketHelper();

	virtual void testPrint() override;

	virtual void connect(const FString ip, int32 port) override;
	virtual void disconnect() override;
	virtual void send(msg::CSMsgID reqMsgId, const msg::CSReqBody& msgBody, msg::CSMsgID rspMsgId, const RspCall& rspCall) override;

private:
	void recv();
	void sendMsg(msg::CSMsgID reqMsgId, const msg::CSReqBody& msgBody);
	void recvMsg();

private:
	FSocket* m_socket = nullptr;
	bool m_isConnect = false;
	std::thread m_thread;

	TMap<int32, RspCall> m_msgRspCallMap;

	FastBuffer m_sendBufferTempSerialize;
	FastBuffer m_sendBufferTempZip;
	FastBuffer m_sendBufferTempEncrypt;
	FastBuffer m_sendBufferTempEncryptOut;
	FastBuffer m_sendBufferKey;
	FastBuffer m_sendBuffer;
	FastBuffer m_recvBufferTemp;
	TArray<uint8> m_recvBuffer;
	FastBuffer m_recvBufferKey;
	FastBuffer m_recvBufferTempDecrypt;
	FastBuffer m_recvBufferTempUnZip;

	std::string m_key = "DanJuanGame@2016";
	int32 m_serverId;
};
