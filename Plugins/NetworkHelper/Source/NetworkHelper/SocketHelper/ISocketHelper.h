// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


class NETWORKHELPER_API ISocketHelper
{
public:
	virtual ~ISocketHelper() {}
	virtual void testPrint() = 0;

	virtual void connect(const FString ip, int32 port) = 0;
};
