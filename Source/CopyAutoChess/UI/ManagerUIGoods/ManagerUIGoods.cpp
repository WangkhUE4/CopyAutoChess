// Fill out your copyright notice in the Description page of Project Settings.
#include "ManagerUIGoods.h"
#include "../../CACLib.h"
#include "../../System/GoodsSys/IGoodsSystem.h"

RegisterUIManager(AManagerUIGoods);

bool AManagerUIGoods::init()
{
	return true;
}

void AManagerUIGoods::end()
{

}

void AManagerUIGoods::testPrint(const FString inStr)
{
	UE_LOG(LogCopyAutoChess, Error, TEXT("AManagerUIGoods, testPrint : %s"), *inStr);
	CACLib::GetGoodsSystem()->testPrint(inStr); 
}

