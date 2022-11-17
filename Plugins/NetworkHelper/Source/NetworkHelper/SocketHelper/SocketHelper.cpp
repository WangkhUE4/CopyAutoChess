// Copyright Epic Games, Inc. All Rights Reserved.
#include "SocketHelper.h"
#include "../Public/NetworkHelperDefine.h"
#include "SocketSubsystem.h"
#include "Networking/Public/Interfaces/IPv4/IPv4Address.h"


FSocketHelper::~FSocketHelper()
{
	if (m_socket)
	{
		m_socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(m_socket);
		m_socket = nullptr;
	}
	m_isConnect = false;
}

void FSocketHelper::testPrint()
{
	UE_LOG(LogNetworkHelper, Error, TEXT("FSocketHelper::testPrint"));
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

	//连接成功
	if (m_socket->Connect(*addr))
	{
		UE_LOG(LogNetworkHelper, Warning, TEXT("Connect Succeed!"));
		m_isConnect = true;
	}
	//连接失败
	else
	{
		UE_LOG(LogNetworkHelper, Warning, TEXT("Connect Failed!"));
		m_isConnect = false;
	}
}
