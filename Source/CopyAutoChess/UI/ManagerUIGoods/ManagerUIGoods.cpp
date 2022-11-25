// Fill out your copyright notice in the Description page of Project Settings.
#include "ManagerUIGoods.h"
#include "../../CACLib.h"
#include "../../System/GoodsSys/IGoodsSystem.h"
#include "CopyAutoChess/Network/SocketHelper/SocketHelper.h"
#include "CopyAutoChess/Network/Protobuf/Student.pb.h"
#include "CopyAutoChess/Network/Protobuf/csprotocol.pb.h"

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
	//test system
	UE_LOG(LogCopyAutoChess, Warning, TEXT("AManagerUIGoods, testPrint : %s"), *inStr);
	CACLib::GetGoodsSystem()->testPrint(inStr); 

	//test socket connect
	ISocketHelper*  ptr = new FSocketHelper();
	ptr->testPrint();
	ptr->connect("47.108.85.170", 3063);
	//ptr->connect("172.20.12.40", 3063);
	//delete ptr;
	//ptr = nullptr;

	//test 接入protobuf
	int32 sid = 666666;
	FString name = TEXT("XiaoMing");
	TSharedPtr<School::Student> XiaoMing = MakeShared<School::Student>();
	XiaoMing->set_sid(sid);
	XiaoMing->set_name(TCHAR_TO_UTF8(*name));
	FString _name = XiaoMing->name().c_str();
	UE_LOG(LogCopyAutoChess, Warning, TEXT("AManagerUIGoods, xiaoming, sid : %d , name : %s"), XiaoMing->sid(), *_name);
	//序列化
	const std::string msg = XiaoMing->SerializeAsString();
	//反序列化
	School::Student XiaoMingCopy;
	XiaoMingCopy.ParseFromString(msg);
	FString _nameCopy = XiaoMingCopy.name().c_str();
	UE_LOG(LogCopyAutoChess, Warning, TEXT("AManagerUIGoods, xiaoming Copy, sid : %d , name : %s"), XiaoMingCopy.sid(), *_nameCopy);

	//获取加密的key和serverId
	msg::CSReqBody body;
	auto data = body.mutable_applyhallserver();
	FString deviceId = FPlatformMisc::GetHashedMacAddressString();
	FString channelId = "LongYuan-channel";
	FString apkversion = "1.0.2";
	data->set_deviceid(TCHAR_TO_UTF8(*deviceId));
	data->set_channelid(TCHAR_TO_UTF8(*channelId));
	data->set_apkversion(TCHAR_TO_UTF8(*apkversion));
	data->set_platformtype(msg::PLATFORMTYPE::PLATFORMTYPE_PC);
	data->set_ts(0);
	body.set_seq(11);

	UE_LOG(LogCopyAutoChess, Warning, TEXT("AManagerUIGoods, REQ_APPLY_HALL_SERVER , deviceId:%s, channelId:%s, apkversion:%s"), data->deviceid().c_str(), data->channelid().c_str(), data->apkversion().c_str());

	ptr->send(msg::CSMsgID::REQ_APPLY_HALL_SERVER, body, msg::CSMsgID::RSP_APPLY_HALL_SERVER, [](const msg::CSRspBody& message){
		if (message.errcode() == msg::RESULT::SUCCESS)
		{
			auto applyHallServer = message.applyhallserver();
			UE_LOG(LogCopyAutoChess, Warning, TEXT("AManagerUIGoods, REQ_APPLY_HALL_SERVER SUCCESS, key : %s, serverId : %d"), applyHallServer.key().c_str(), applyHallServer.serverid());
		}
		else
		{
			UE_LOG(LogCopyAutoChess, Error, TEXT("AManagerUIGoods, REQ_APPLY_HALL_SERVER Error : %d"), message.errcode());
		}
	});

}

