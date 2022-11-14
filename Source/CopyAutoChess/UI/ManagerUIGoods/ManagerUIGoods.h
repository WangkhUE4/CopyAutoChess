// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../UIManager.h"
#include "ManagerUIGoods.generated.h"

UCLASS()
class COPYAUTOCHESS_API AManagerUIGoods : public AUIManager
{
	GENERATED_BODY()

public:
	virtual bool init() override;
	virtual void end() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Goods|Fun")
		void testPrint(const FString inStr);
};
