// Fill out your copyright notice in the Description page of Project Settings.


#include "CACLib.h"
#include "System/GoodsSys/GoodsSystem.h"
#include "CopyAutoChessGameModeBase.h"
#include "System/SystemEnum.h"

class IGoodsSystem* CACLib::GetGoodsSystem()
{
	return GGM->getSystemByName<GoodsSystem>(ESystemName::GoodsSystem);
}
