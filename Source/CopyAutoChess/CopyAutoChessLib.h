// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CopyAutoChessLib.generated.h"


UCLASS()
class COPYAUTOCHESS_API UCopyAutoChessLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//
	UFUNCTION(BlueprintCallable, meta = (UnsafeDuringActorConstruction = "true"), Category = "CAC")
		static class AManagerUIGoods* GetManagerUIGoods();
	
};

