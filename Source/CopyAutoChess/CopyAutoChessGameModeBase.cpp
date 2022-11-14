// Copyright Epic Games, Inc. All Rights Reserved.
#include "CopyAutoChessGameModeBase.h"
#include "CopyAutoChessMacro.h"


ACopyAutoChessGameModeBase* GGM;

ExternUIManager(AManagerUIGoods);

void ACopyAutoChessGameModeBase::initGame()
{
	AsyncTask(ENamedThreads::GameThread, [this](){
		this->initGameObject();
	});
}

void ACopyAutoChessGameModeBase::initGameObject()
{
	m_sys = MakeShared<Sys>();
	m_sys->onCreateSys();

	ManangerUIGoods = createAManagerUIGoods(RootActor);
}

void ACopyAutoChessGameModeBase::BeginPlay()
{
	GGM = this;
	Super::BeginPlay();

	RootActor = GetWorld()->SpawnActor<AActor>();

	initGame();
}

void ACopyAutoChessGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GGM = nullptr;
}
