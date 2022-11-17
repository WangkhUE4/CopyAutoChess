// Fill out your copyright notice in the Description page of Project Settings.
#include "ManagerUIGoods.h"
#include "../../CACLib.h"
#include "../../System/GoodsSys/IGoodsSystem.h"
#include "../Plugins/NetworkHelper/Source/NetworkHelper/SocketHelper/SocketHelper.h"

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
	UE_LOG(LogCopyAutoChess, Warning, TEXT("AManagerUIGoods, testPrint : %s"), *inStr);
	CACLib::GetGoodsSystem()->testPrint(inStr); 

	ISocketHelper*  ptr = new FSocketHelper();
	ptr->testPrint();
	ptr->connect("47.108.85.170", 3063);
	delete ptr;
	ptr = nullptr;
}

