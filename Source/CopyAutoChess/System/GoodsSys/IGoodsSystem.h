// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


class COPYAUTOCHESS_API IGoodsSystem
{
public:
	//增加道具  
	virtual void addGoods() = 0;
	//  
	virtual void testPrint(const FString inStr) = 0;
};
