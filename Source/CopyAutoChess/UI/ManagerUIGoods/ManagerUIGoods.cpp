// Fill out your copyright notice in the Description page of Project Settings.
#include "ManagerUIGoods.h"
#include "../../CACLib.h"
#include "../../System/GoodsSys/IGoodsSystem.h"
#include "../Plugins/NetworkHelper/Source/NetworkHelper/SocketHelper/SocketHelper.h"
#include "CopyAutoChess/Network/Protobuf/Student.pb.h"

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

	int32 sid = 666666;
	FString name = TEXT("XiaoMing");
	TSharedPtr<School::Student> XiaoMing = MakeShared<School::Student>();
	XiaoMing->set_sid(sid);
	XiaoMing->set_name(TCHAR_TO_UTF8(*name));
	FString _name = XiaoMing->name().c_str();
	UE_LOG(LogCopyAutoChess, Warning, TEXT("AManagerUIGoods, xiaoming, sid : %d , name : %s"), XiaoMing->sid(), *_name);

}

