// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "System/Sys.h"
#include "CopyAutoChessGameModeBase.generated.h"

class AManagerUIGoods;

enum class ESystemName : uint8;

UCLASS()
class COPYAUTOCHESS_API ACopyAutoChessGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void initGame();

private:
	void initGameObject();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	template<typename Type>
	Type* getSystemByName(ESystemName name)
	{
		if (m_sys)
		{
			return m_sys->getSystemByName<Type>(name);
		}
		return nullptr;
	}

public:
	AActor* RootActor;

	AManagerUIGoods* ManangerUIGoods;

private:
	TSharedPtr<Sys> m_sys;
	
};

extern ACopyAutoChessGameModeBase* GGM;
