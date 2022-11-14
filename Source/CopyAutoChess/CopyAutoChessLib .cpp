// Copyright Epic Games, Inc. All Rights Reserved.
#include "CopyAutoChessLib.h"
#include "CopyAutoChessGameModeBase.h"


class AManagerUIGoods* UCopyAutoChessLib::GetManagerUIGoods()
{
	if (GGM)
	{
		return GGM->ManangerUIGoods;
	}
	return nullptr;
}
