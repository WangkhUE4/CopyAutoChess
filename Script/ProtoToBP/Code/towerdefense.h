/*
Proto buf => BP

*/
#pragma once


#include "CoreMinimal.h"
#include "towerdefense.pb.h"
#include "common.h"
#include "common.pb.h"
#include "towerdefense.generated.h"


UENUM(BlueprintType)
enum class ETDITEMTYPE: uint8 {
	TDITEMTYPE_MIN_NUM = 0 UMETA(DisplayName="TDITEMTYPE_MIN_NUM"),
	TDITEMTYPE_CHESS_MAN = 1 UMETA(DisplayName="TDITEMTYPE_CHESS_MAN"),	// 棋子
	TDITEMTYPE_CHESS_PLAYER = 2 UMETA(DisplayName="TDITEMTYPE_CHESS_PLAYER"),	// 棋手
	TDITEMTYPE_CHESS_BOARD = 3 UMETA(DisplayName="TDITEMTYPE_CHESS_BOARD"),	// 棋盘
	TDITEMTYPE_CHESS_EQUIP = 4 UMETA(DisplayName="TDITEMTYPE_CHESS_EQUIP"),	// 棋子装备
	TDITEMTYPE_MONEY = 5 UMETA(DisplayName="TDITEMTYPE_MONEY"),	// 钱
	TDITEMTYPE_EXP = 6 UMETA(DisplayName="TDITEMTYPE_EXP"),	// 经验
	TDITEMTYPE_MATERIAL = 7 UMETA(DisplayName="TDITEMTYPE_MATERIAL"),	// 材料
	TDITEMTYPE_BLUE_PRINT = 8 UMETA(DisplayName="TDITEMTYPE_BLUE_PRINT"),	// 图纸
	TDITEMTYPE_AUTO_OPEN_CHEST = 9 UMETA(DisplayName="TDITEMTYPE_AUTO_OPEN_CHEST"),	//宝箱自动开启
	TDITEMTYPE_MAX_NUM = 10 UMETA(DisplayName="TDITEMTYPE_MAX_NUM"),
};

UENUM(BlueprintType)
enum class ETDLEVELUP_TYPE: uint8 {
	TDLEVELUP_TYPE_CHESS_UNLOCK = 0 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_UNLOCK"),	//棋子、棋盘、棋手升级
	TDLEVELUP_TYPE_CHESS_WHITE_EQUIP = 1 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_WHITE_EQUIP"),	//白装升级
	TDLEVELUP_TYPE_CHESS_BLUE_EQUIP = 3 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_BLUE_EQUIP"),	//蓝装升级
	TDLEVELUP_TYPE_CHESS_PURE_EQUIP = 4 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_PURE_EQUIP"),	//紫装升级
	TDLEVELUP_TYPE_CHESS_ORIGiN_EQUIP = 5 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_ORIGiN_EQUIP"),	//橙装升级
	TDLEVELUP_TYPE_COMPOSE = 6 UMETA(DisplayName="TDLEVELUP_TYPE_COMPOSE"),	//装备合成
	TDLEVELUP_TYPE_CHESS_BOARD_TALENT = 9 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_BOARD_TALENT"),
	TDLEVELUP_TYPE_CHESS_MAN_QUALITY = 10 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_MAN_QUALITY"),	//升级类型对应的费用
	TDLEVELUP_TYPE_CHESS_MAN_QUALITY_1 = 11 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_MAN_QUALITY_1"),	//1费棋子升级
	TDLEVELUP_TYPE_CHESS_MAN_QUALITY_2 = 12 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_MAN_QUALITY_2"),	//2费棋子升级
	TDLEVELUP_TYPE_CHESS_MAN_QUALITY_3 = 13 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_MAN_QUALITY_3"),	//3费棋子升级
	TDLEVELUP_TYPE_CHESS_MAN_QUALITY_4 = 14 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_MAN_QUALITY_4"),	//4费棋子升级
	TDLEVELUP_TYPE_CHESS_MAN_QUALITY_5 = 15 UMETA(DisplayName="TDLEVELUP_TYPE_CHESS_MAN_QUALITY_5"),	//5费棋子升级
};

UENUM(BlueprintType)
enum class ETDSKILLTYPE: uint8 {
	TDSKILLTYPE_LIMIT_MIN = 0 UMETA(DisplayName="TDSKILLTYPE_LIMIT_MIN"),
	TDSKILLTYPE_SKIL = 1 UMETA(DisplayName="TDSKILLTYPE_SKIL"),
	TDSKILLTYPE_EQUIP = 2 UMETA(DisplayName="TDSKILLTYPE_EQUIP"),
	TDSKILLTYPE_SPECIAL_BUFF = 3 UMETA(DisplayName="TDSKILLTYPE_SPECIAL_BUFF"),
	TDSKILLTYPE_BUFF = 4 UMETA(DisplayName="TDSKILLTYPE_BUFF"),
	TDSKILLTYPE_LIMIT_MAX = 5 UMETA(DisplayName="TDSKILLTYPE_LIMIT_MAX"),
};

USTRUCT(BlueprintType)
struct  FTDConsume {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

};
static void _ConvertPbToFTDConsume(FTDConsume &msg, const msg::TDConsume *pb) {
	msg.Id=pb->id();
	msg.Count=pb->count();
	msg.Level=pb->level();
}


USTRUCT(BlueprintType)
struct  FTDOutPut {
	GENERATED_BODY()

	int64 Interval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;

};
static void _ConvertPbToFTDOutPut(FTDOutPut &msg, const msg::TDOutPut *pb) {
	msg.Interval=pb->interval();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FSkillItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETDSKILLTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString value;

};
static void _ConvertPbToFSkillItem(FSkillItem &msg, const msg::SkillItem *pb) {
	msg.Id=pb->id();
	msg.Type=(ETDSKILLTYPE)pb->type();
	msg.Level=pb->level();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.value=UTF8_TO_TCHAR(pb->value().c_str());
}


USTRUCT(BlueprintType)
struct  FTDBuy {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> ExAwards;

};
static void _ConvertPbToFTDBuy(FTDBuy &msg, const msg::TDBuy *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->exawards().size(); i++) {
		auto &a = pb->exawards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.ExAwards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FOnHookOutPutData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StageId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDOutPut> Effect;

};
static void _ConvertPbToFOnHookOutPutData(FOnHookOutPutData &msg, const msg::OnHookOutPutData *pb) {
	msg.StageId=pb->stageid();
	for (int i = 0; i < pb->effect().size(); i++) {
		auto &a = pb->effect().Get(i);
		FTDOutPut tmp;
		_ConvertPbToFTDOutPut(tmp, &a);
		msg.Effect.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDRandCardData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EndTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Background;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDConsume> Consume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDConsume> TenDrawConsumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChestId;	// 关联制图工坊塔防模式随机掉落池表

};
static void _ConvertPbToFTDRandCardData(FTDRandCardData &msg, const msg::TDRandCardData *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.StartTime=UTF8_TO_TCHAR(pb->starttime().c_str());
	msg.EndTime=UTF8_TO_TCHAR(pb->endtime().c_str());
	msg.Background=UTF8_TO_TCHAR(pb->background().c_str());
	for (int i = 0; i < pb->consume().size(); i++) {
		auto &a = pb->consume().Get(i);
		FTDConsume tmp;
		_ConvertPbToFTDConsume(tmp, &a);
		msg.Consume.Add(tmp);
	}
	for (int i = 0; i < pb->tendrawconsumes().size(); i++) {
		auto &a = pb->tendrawconsumes().Get(i);
		FTDConsume tmp;
		_ConvertPbToFTDConsume(tmp, &a);
		msg.TenDrawConsumes.Add(tmp);
	}
	msg.ChestId=pb->chestid();
}


USTRUCT(BlueprintType)
struct  FTDRandPoolData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDItem AwardItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;

};
static void _ConvertPbToFTDRandPoolData(FTDRandPoolData &msg, const msg::TDRandPoolData *pb) {
	msg.Id=pb->id();
	msg.PoolId=pb->poolid();
	_ConvertPbToFTDItem(msg.AwardItem, &pb->awarditem());
	msg.Weight=pb->weight();
}


USTRUCT(BlueprintType)
struct  FPlayerInitchessData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

};
static void _ConvertPbToFPlayerInitchessData(FPlayerInitchessData &msg, const msg::PlayerInitchessData *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FChessManMaterialData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Quality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;

};
static void _ConvertPbToFChessManMaterialData(FChessManMaterialData &msg, const msg::ChessManMaterialData *pb) {
	msg.Quality=pb->quality();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDChessboardPeople {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Num;

};
static void _ConvertPbToFTDChessboardPeople(FTDChessboardPeople &msg, const msg::TDChessboardPeople *pb) {
	msg.Level=pb->level();
	msg.Num=pb->num();
}


USTRUCT(BlueprintType)
struct  FTDLevelUpData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// 唯一值，没其他作用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETDITEMTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETDLEVELUP_TYPE SubType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> EquipQualityConsumes;

};
static void _ConvertPbToFTDLevelUpData(FTDLevelUpData &msg, const msg::TDLevelUpData *pb) {
	msg.Id=pb->id();
	msg.Level=pb->level();
	msg.Type=(ETDITEMTYPE)pb->type();
	msg.SubType=(ETDLEVELUP_TYPE)pb->subtype();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FTDConsume tmp;
		_ConvertPbToFTDConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->equipqualityconsumes().size(); i++) {
		auto &a = pb->equipqualityconsumes().Get(i);
		int tmp;
		tmp=a;
		msg.EquipQualityConsumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDComposeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RouteId;	//相当于需要合成的物品Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DrawingId;	//图纸Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Award;

};
static void _ConvertPbToFTDComposeData(FTDComposeData &msg, const msg::TDComposeData *pb) {
	msg.RouteId=pb->routeid();
	msg.DrawingId=pb->drawingid();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FTDConsume tmp;
		_ConvertPbToFTDConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->award().size(); i++) {
		auto &a = pb->award().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Award.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDSkillData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETDITEMTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSkillItem> Skills;

};
static void _ConvertPbToFTDSkillData(FTDSkillData &msg, const msg::TDSkillData *pb) {
	msg.Id=pb->id();
	msg.ItemId=pb->itemid();
	msg.Type=(ETDITEMTYPE)pb->type();
	msg.Level=pb->level();
	for (int i = 0; i < pb->skills().size(); i++) {
		auto &a = pb->skills().Get(i);
		FSkillItem tmp;
		_ConvertPbToFSkillItem(tmp, &a);
		msg.Skills.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDStageData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;	//通关奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ItemIds;	//相比上一关卡,挂机产出的额外奖励

};
static void _ConvertPbToFTDStageData(FTDStageData &msg, const msg::TDStageData *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Level=pb->level();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->itemids().size(); i++) {
		auto &a = pb->itemids().Get(i);
		int tmp;
		tmp=a;
		msg.ItemIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDItemData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETDITEMTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Quality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ItemIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ChessId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InitLevel;	//初始化等级

};
static void _ConvertPbToFTDItemData(FTDItemData &msg, const msg::TDItemData *pb) {
	msg.Id=pb->id();
	msg.Type=(ETDITEMTYPE)pb->type();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.Quality=pb->quality();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	for (int i = 0; i < pb->itemids().size(); i++) {
		auto &a = pb->itemids().Get(i);
		int tmp;
		tmp=a;
		msg.ItemIds.Add(tmp);
	}
	for (int i = 0; i < pb->chessid().size(); i++) {
		auto &a = pb->chessid().Get(i);
		int tmp;
		tmp=a;
		msg.ChessId.Add(tmp);
	}
	msg.Cost=pb->cost();
	msg.InitLevel=pb->initlevel();
}


USTRUCT(BlueprintType)
struct  FTDPlayerInfo {
	GENERATED_BODY()

	int64 OnHookTime;	//挂机时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OnHookStage;	//挂机关卡等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LastStage;	//最后一次通关等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDItemGroup ItemGroup;	//卡组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Items;	//背包

	TMap<int64, int64> OnHookTimeRecord;	//挂机时间记录

};
static void _ConvertPbToFTDPlayerInfo(FTDPlayerInfo &msg, const msg::TDPlayerInfo *pb) {
	msg.OnHookTime=pb->onhooktime();
	msg.OnHookStage=pb->onhookstage();
	msg.LastStage=pb->laststage();
	_ConvertPbToFTDItemGroup(msg.ItemGroup, &pb->itemgroup());
	for (int i = 0; i < pb->items().size(); i++) {
		auto &a = pb->items().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Items.Add(tmp);
	}

    for (auto it = pb->onhooktimerecord().begin(); it != pb->onhooktimerecord().end(); it++) {
        int64 tmp_value;
        tmp_value=it->second;
        int64 tmp_key;
        tmp_key=it->first;
        msg.OnHookTimeRecord.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FOnHookOutPutInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FOnHookOutPutData> Datas;

};
static void _ConvertPbToFOnHookOutPutInfo(FOnHookOutPutInfo &msg, const msg::OnHookOutPutInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FOnHookOutPutData tmp;
		_ConvertPbToFOnHookOutPutData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDRandCardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDRandCardData> Datas;

};
static void _ConvertPbToFTDRandCardInfo(FTDRandCardInfo &msg, const msg::TDRandCardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTDRandCardData tmp;
		_ConvertPbToFTDRandCardData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDRandPoolInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDRandPoolData> Datas;

};
static void _ConvertPbToFTDRandPoolInfo(FTDRandPoolInfo &msg, const msg::TDRandPoolInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTDRandPoolData tmp;
		_ConvertPbToFTDRandPoolData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDCardGroupConfigInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ChessBoardCount;	// 1,3

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ChessPlayerCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ChessManCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> PlayerInitItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPlayerInitchessData PlayerInitchess;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StoreLimit;	//物品上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDChessboardPeople> PopLimit;	//棋盘等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessBoardLvLimit;	//棋盘等级上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessPlayerLvLimit;	//棋子等级上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessManLvLimit;	//棋手等级上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessEquipLimit;	//棋子装备数量上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessEquipLvLimit;	//棋子装备等级上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessBoardTalentLvLimit;	//棋盘天赋等级上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDBuy BuyCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MapKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PopSpecialBuffId;	//棋盘等级的BuffId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxStage;	//最大关卡等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> CostPoolCount;	//费用对应卡池的数量

	int64 LimitTime;	//挂机最大限制时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessManMaterialData> ChessManMaterials;	//棋子费用对应的材料

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowRate;	//概率显示

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpChessPoolKey;	//内核卡池key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LimitTimeStage;	//时间阶段限制,客户端用

};
static void _ConvertPbToFTDCardGroupConfigInfo(FTDCardGroupConfigInfo &msg, const msg::TDCardGroupConfigInfo *pb) {
	for (int i = 0; i < pb->chessboardcount().size(); i++) {
		auto &a = pb->chessboardcount().Get(i);
		int tmp;
		tmp=a;
		msg.ChessBoardCount.Add(tmp);
	}
	for (int i = 0; i < pb->chessplayercount().size(); i++) {
		auto &a = pb->chessplayercount().Get(i);
		int tmp;
		tmp=a;
		msg.ChessPlayerCount.Add(tmp);
	}
	for (int i = 0; i < pb->chessmancount().size(); i++) {
		auto &a = pb->chessmancount().Get(i);
		int tmp;
		tmp=a;
		msg.ChessManCount.Add(tmp);
	}
	for (int i = 0; i < pb->playerinititems().size(); i++) {
		auto &a = pb->playerinititems().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.PlayerInitItems.Add(tmp);
	}
	_ConvertPbToFPlayerInitchessData(msg.PlayerInitchess, &pb->playerinitchess());
	msg.StoreLimit=pb->storelimit();
	for (int i = 0; i < pb->poplimit().size(); i++) {
		auto &a = pb->poplimit().Get(i);
		FTDChessboardPeople tmp;
		_ConvertPbToFTDChessboardPeople(tmp, &a);
		msg.PopLimit.Add(tmp);
	}
	msg.ChessBoardLvLimit=pb->chessboardlvlimit();
	msg.ChessPlayerLvLimit=pb->chessplayerlvlimit();
	msg.ChessManLvLimit=pb->chessmanlvlimit();
	msg.ChessEquipLimit=pb->chessequiplimit();
	msg.ChessEquipLvLimit=pb->chessequiplvlimit();
	msg.ChessBoardTalentLvLimit=pb->chessboardtalentlvlimit();
	_ConvertPbToFTDBuy(msg.BuyCard, &pb->buycard());
	msg.MapKey=UTF8_TO_TCHAR(pb->mapkey().c_str());
	msg.PopSpecialBuffId=pb->popspecialbuffid();
	msg.MaxStage=pb->maxstage();
	for (int i = 0; i < pb->costpoolcount().size(); i++) {
		auto &a = pb->costpoolcount().Get(i);
		int tmp;
		tmp=a;
		msg.CostPoolCount.Add(tmp);
	}
	msg.LimitTime=pb->limittime();
	for (int i = 0; i < pb->chessmanmaterials().size(); i++) {
		auto &a = pb->chessmanmaterials().Get(i);
		FChessManMaterialData tmp;
		_ConvertPbToFChessManMaterialData(tmp, &a);
		msg.ChessManMaterials.Add(tmp);
	}
	msg.ShowRate=UTF8_TO_TCHAR(pb->showrate().c_str());
	msg.PvpChessPoolKey=UTF8_TO_TCHAR(pb->pvpchesspoolkey().c_str());
	msg.LimitTimeStage=UTF8_TO_TCHAR(pb->limittimestage().c_str());
}


USTRUCT(BlueprintType)
struct  FItemTypeLimit {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LevelLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CardGroupMinNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CardGroupMaxNum;

};
static void _ConvertPbToFItemTypeLimit(FItemTypeLimit &msg, const msg::ItemTypeLimit *pb) {
	msg.LevelLimit=pb->levellimit();
	msg.CardGroupMinNum=pb->cardgroupminnum();
	msg.CardGroupMaxNum=pb->cardgroupmaxnum();
}


USTRUCT(BlueprintType)
struct  FTDLevelUpInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDLevelUpData> Datas;

};
static void _ConvertPbToFTDLevelUpInfo(FTDLevelUpInfo &msg, const msg::TDLevelUpInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTDLevelUpData tmp;
		_ConvertPbToFTDLevelUpData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDComposeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDComposeData> Datas;

};
static void _ConvertPbToFTDComposeInfo(FTDComposeInfo &msg, const msg::TDComposeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTDComposeData tmp;
		_ConvertPbToFTDComposeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDSkillInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDSkillData> Datas;

};
static void _ConvertPbToFTDSkillInfo(FTDSkillInfo &msg, const msg::TDSkillInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTDSkillData tmp;
		_ConvertPbToFTDSkillData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDStageInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDStageData> Datas;

};
static void _ConvertPbToFTDStageInfo(FTDStageInfo &msg, const msg::TDStageInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTDStageData tmp;
		_ConvertPbToFTDStageData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTDItemInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItemData> Datas;

};
static void _ConvertPbToFTDItemInfo(FTDItemInfo &msg, const msg::TDItemInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTDItemData tmp;
		_ConvertPbToFTDItemData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqTDGetOnHookAward {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqTDGetOnHookAward(FCSReqTDGetOnHookAward &msg, const msg::CSReqTDGetOnHookAward *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspTDGetOnHookAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;

	int64 OnHookTime;	//挂机开始时间

	TMap<int64, int64> OnHookTimeRecord;	//挂机时间记录

};
static void _ConvertPbToFCSRspTDGetOnHookAward(FCSRspTDGetOnHookAward &msg, const msg::CSRspTDGetOnHookAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.OnHookTime=pb->onhooktime();

    for (auto it = pb->onhooktimerecord().begin(); it != pb->onhooktimerecord().end(); it++) {
        int64 tmp_value;
        tmp_value=it->second;
        int64 tmp_key;
        tmp_key=it->first;
        msg.OnHookTimeRecord.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCsReqTDDraw {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Ten;

};
static void _ConvertPbToFCsReqTDDraw(FCsReqTDDraw &msg, const msg::CsReqTDDraw *pb) {
	msg.PoolId=pb->poolid();
	msg.Ten=pb->ten();
}


USTRUCT(BlueprintType)
struct  FCsRspTDDraw {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDConsume> Consumes;

};
static void _ConvertPbToFCsRspTDDraw(FCsRspTDDraw &msg, const msg::CsRspTDDraw *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FTDConsume tmp;
		_ConvertPbToFTDConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCsReqTDBuyCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CardCount;	//需要购买卡券的数量

};
static void _ConvertPbToFCsReqTDBuyCard(FCsReqTDBuyCard &msg, const msg::CsReqTDBuyCard *pb) {
	msg.CardCount=pb->cardcount();
}


USTRUCT(BlueprintType)
struct  FCsRspTDBuyCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDBuy BuyCard;

};
static void _ConvertPbToFCsRspTDBuyCard(FCsRspTDBuyCard &msg, const msg::CsRspTDBuyCard *pb) {
	_ConvertPbToFTDBuy(msg.BuyCard, &pb->buycard());
}


USTRUCT(BlueprintType)
struct  FCSNtfTDPlayerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDPlayerInfo PlayerInfo;

};
static void _ConvertPbToFCSNtfTDPlayerInfo(FCSNtfTDPlayerInfo &msg, const msg::CSNtfTDPlayerInfo *pb) {
	_ConvertPbToFTDPlayerInfo(msg.PlayerInfo, &pb->playerinfo());
}


USTRUCT(BlueprintType)
struct  FCSReqTDSetCardGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETDITEMTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDCardGroup CardGroup;

};
static void _ConvertPbToFCSReqTDSetCardGroup(FCSReqTDSetCardGroup &msg, const msg::CSReqTDSetCardGroup *pb) {
	msg.Type=(ETDITEMTYPE)pb->type();
	_ConvertPbToFTDCardGroup(msg.CardGroup, &pb->cardgroup());
}


USTRUCT(BlueprintType)
struct  FCSRspTDSetCardGroup {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspTDSetCardGroup(FCSRspTDSetCardGroup &msg, const msg::CSRspTDSetCardGroup *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqTDLevelUp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDItemId Id;	// 要升级的物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Equip;	// 是否装备中

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETDLEVELUP_TYPE LvUpType;	// 升级类型，

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDItem BluePrint;	// 合成,突破时才需要

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDItemId ChessId;	// 穿戴装备所属棋手id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	// 装备槽位

};
static void _ConvertPbToFCSReqTDLevelUp(FCSReqTDLevelUp &msg, const msg::CSReqTDLevelUp *pb) {
	_ConvertPbToFTDItemId(msg.Id, &pb->id());
	msg.Equip=pb->equip();
	msg.LvUpType=(ETDLEVELUP_TYPE)pb->lvuptype();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FTDConsume tmp;
		_ConvertPbToFTDConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	_ConvertPbToFTDItem(msg.BluePrint, &pb->blueprint());
	_ConvertPbToFTDItemId(msg.ChessId, &pb->chessid());
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspTDLevelUp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;

};
static void _ConvertPbToFCSRspTDLevelUp(FCSRspTDLevelUp &msg, const msg::CSRspTDLevelUp *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FTDConsume tmp;
		_ConvertPbToFTDConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqTDEquip {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDItemId ChessId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	// 0-5

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool TakeOff;	// 是否脱下

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDItemId EquipId;

};
static void _ConvertPbToFCSReqTDEquip(FCSReqTDEquip &msg, const msg::CSReqTDEquip *pb) {
	_ConvertPbToFTDItemId(msg.ChessId, &pb->chessid());
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
	msg.TakeOff=pb->takeoff();
	_ConvertPbToFTDItemId(msg.EquipId, &pb->equipid());
}


USTRUCT(BlueprintType)
struct  FCSRspTDEquip {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;

};
static void _ConvertPbToFCSRspTDEquip(FCSRspTDEquip &msg, const msg::CSRspTDEquip *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FTDConsume tmp;
		_ConvertPbToFTDConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


