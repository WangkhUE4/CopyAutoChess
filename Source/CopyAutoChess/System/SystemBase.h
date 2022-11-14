#pragma once
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "../CopyAutoChessDefine.h"

class SystemBase
	:public TSharedFromThis<SystemBase>
{
public:
	SystemBase(const FString& sysName);
	virtual ~SystemBase();

	const FString& getSystemName()const;
	int32 getPriority()const;

private:

	FString m_name;
	int32 m_priority;

	friend class ACSys;
};

