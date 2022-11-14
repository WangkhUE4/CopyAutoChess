// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IGoodsSystem.h"
#include "../SystemBase.h"


class COPYAUTOCHESS_API GoodsSystem : public IGoodsSystem
	, public SystemBase
{
public:
	GoodsSystem();
	virtual ~GoodsSystem();

	virtual void addGoods() override;
	virtual void testPrint(const FString inStr) override;
};
