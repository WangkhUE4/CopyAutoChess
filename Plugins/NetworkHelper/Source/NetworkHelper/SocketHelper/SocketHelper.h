// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "ISocketHelper.h"
#include "Sockets.h"


class NETWORKHELPER_API FSocketHelper : public ISocketHelper
{
public:
	virtual ~FSocketHelper();

	virtual void testPrint() override;

	virtual void connect(const FString ip, int32 port) override;

private:
	FSocket* m_socket = nullptr;
	bool m_isConnect = false;
};
