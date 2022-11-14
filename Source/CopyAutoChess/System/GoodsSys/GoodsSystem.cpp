// Fill out your copyright notice in the Description page of Project Settings.


#include "GoodsSystem.h"

GoodsSystem::GoodsSystem() : SystemBase("GoodsSystem")
{
}

GoodsSystem::~GoodsSystem()
{
}

void GoodsSystem::addGoods()
{

}

void GoodsSystem::testPrint(const FString inStr)
{
	UE_LOG(LogCopyAutoChess, Log, TEXT("GoodsSystem::testPrint : %s"), *inStr);
}
