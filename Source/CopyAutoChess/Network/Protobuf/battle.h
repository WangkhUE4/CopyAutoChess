/*
Proto buf => BP

*/
#pragma once


#include "CoreMinimal.h"
#include "battle.pb.h"
#include "common.h"
#include "common.pb.h"
#include "battle.generated.h"


UENUM(BlueprintType)
enum class EGameStage: uint8 {
	RoundStart = 0 UMETA(DisplayName="RoundStart"),
	GetReady = 1 UMETA(DisplayName="GetReady"),
	Freeze = 2 UMETA(DisplayName="Freeze"),
	Battle = 3 UMETA(DisplayName="Battle"),
	End = 4 UMETA(DisplayName="End"),
	StageCount = 5 UMETA(DisplayName="StageCount"),
};

UENUM(BlueprintType)
enum class EGamePhase: uint8 {
	Early = 0 UMETA(DisplayName="Early"),
	Late = 1 UMETA(DisplayName="Late"),
};

UENUM(BlueprintType)
enum class EAddictionState: uint8 {
	Healthy = 0 UMETA(DisplayName="Healthy"),
	Tired = 1 UMETA(DisplayName="Tired"),
	Unhealthy = 2 UMETA(DisplayName="Unhealthy"),
};

UENUM(BlueprintType)
enum class EMessengerMoveType: uint8 {
	_ = 0 UMETA(DisplayName="_"),
	Normal = 1 UMETA(DisplayName="Normal"),
	Flash = 2 UMETA(DisplayName="Flash"),
};

UENUM(BlueprintType)
enum class EPvpOfflineType: uint8 {
	Normally = 0 UMETA(DisplayName="Normally"),
	LeaveEarly = 1 UMETA(DisplayName="LeaveEarly"),
};

USTRUCT(BlueprintType)
struct  FPositionInt2D {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Y;

};
static void _ConvertPbToFPositionInt2D(FPositionInt2D &msg, const msg::PositionInt2D *pb) {
	msg.X=pb->x();
	msg.Y=pb->y();
}


USTRUCT(BlueprintType)
struct  FItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipmentId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

};
static void _ConvertPbToFItem(FItem &msg, const msg::Item *pb) {
	msg.EquipmentId=pb->equipmentid();
	msg.NetId=pb->netid();
}


USTRUCT(BlueprintType)
struct  FItemInTheBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItem BaseInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;

};
static void _ConvertPbToFItemInTheBag(FItemInTheBag &msg, const msg::ItemInTheBag *pb) {
	_ConvertPbToFItem(msg.BaseInfo, &pb->baseinfo());
	msg.Index=pb->index();
}


USTRUCT(BlueprintType)
struct  FCharacter_PB {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CharacterId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemInTheBag> CharacterEquips;

};
static void _ConvertPbToFCharacter_PB(FCharacter_PB &msg, const msg::Character *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.CharacterId=pb->characterid();
	for (int i = 0; i < pb->characterequips().size(); i++) {
		auto &a = pb->characterequips().Get(i);
		FItemInTheBag tmp;
		_ConvertPbToFItemInTheBag(tmp, &a);
		msg.CharacterEquips.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemOnTheGround {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItem BaseInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapY;

};
static void _ConvertPbToFItemOnTheGround(FItemOnTheGround &msg, const msg::ItemOnTheGround *pb) {
	_ConvertPbToFItem(msg.BaseInfo, &pb->baseinfo());
	msg.MapX=pb->mapx();
	msg.MapY=pb->mapy();
}


USTRUCT(BlueprintType)
struct  FCharacterInTheBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCharacter_PB BaseInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

};
static void _ConvertPbToFCharacterInTheBag(FCharacterInTheBag &msg, const msg::CharacterInTheBag *pb) {
	_ConvertPbToFCharacter_PB(msg.BaseInfo, &pb->baseinfo());
	msg.BagIndex=pb->bagindex();
}


USTRUCT(BlueprintType)
struct  FCharacterOnTheMap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCharacter_PB BaseInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ty;

};
static void _ConvertPbToFCharacterOnTheMap(FCharacterOnTheMap &msg, const msg::CharacterOnTheMap *pb) {
	_ConvertPbToFCharacter_PB(msg.BaseInfo, &pb->baseinfo());
	msg.Tx=pb->tx();
	msg.Ty=pb->ty();
}


USTRUCT(BlueprintType)
struct  FReflushChessData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isAuto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> chessIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> sellChessIdx;	// 存储被卖掉的棋子对应商店里的下标值

};
static void _ConvertPbToFReflushChessData(FReflushChessData &msg, const msg::ReflushChessData *pb) {
	msg.isAuto=pb->isauto();
	for (int i = 0; i < pb->chessids().size(); i++) {
		auto &a = pb->chessids().Get(i);
		int tmp;
		tmp=a;
		msg.chessIds.Add(tmp);
	}
	for (int i = 0; i < pb->sellchessidx().size(); i++) {
		auto &a = pb->sellchessidx().Get(i);
		int tmp;
		tmp=a;
		msg.sellChessIdx.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessPiecesData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int extractProb;	// 抽取概率

};
static void _ConvertPbToFChessPiecesData(FChessPiecesData &msg, const msg::ChessPiecesData *pb) {
	msg.Id=pb->id();
	msg.extractProb=pb->extractprob();
}


USTRUCT(BlueprintType)
struct  FChessNumber {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Number;	// 棋子数量

};
static void _ConvertPbToFChessNumber(FChessNumber &msg, const msg::ChessNumber *pb) {
	msg.Id=pb->id();
	msg.Number=pb->number();
}


USTRUCT(BlueprintType)
struct  FBattleRoundData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoundNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Damage;	// 回合受到的伤害

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyGained;	// 获取的金币

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyCostByBuyExp;	// 购买经验消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyCostByRefreshShop;	// 刷新商店消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyCostByBuyChess;	// 本回合购买棋子花费

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsMonster;	// 是否是怪物关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EnemyIdx;	// 敌方idx或者是怪物关卡的index

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Exp;	// 本回合获得的经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWINTYPE winType;	// 本回合是否胜利

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FReflushChessData> refreshChess;	// 刷新的棋子序列

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> intoBattleChess;	// 上阵棋子

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyGainedBySellChess;	// 出售棋子获得的金币

};
static void _ConvertPbToFBattleRoundData(FBattleRoundData &msg, const msg::BattleRoundData *pb) {
	msg.RoundNum=pb->roundnum();
	msg.Damage=pb->damage();
	msg.MoneyGained=pb->moneygained();
	msg.MoneyCostByBuyExp=pb->moneycostbybuyexp();
	msg.MoneyCostByRefreshShop=pb->moneycostbyrefreshshop();
	msg.MoneyCostByBuyChess=pb->moneycostbybuychess();
	msg.IsMonster=pb->ismonster();
	msg.EnemyIdx=pb->enemyidx();
	msg.Exp=pb->exp();
	msg.winType=(EWINTYPE)pb->wintype();
	for (int i = 0; i < pb->refreshchess().size(); i++) {
		auto &a = pb->refreshchess().Get(i);
		FReflushChessData tmp;
		_ConvertPbToFReflushChessData(tmp, &a);
		msg.refreshChess.Add(tmp);
	}
	for (int i = 0; i < pb->intobattlechess().size(); i++) {
		auto &a = pb->intobattlechess().Get(i);
		int tmp;
		tmp=a;
		msg.intoBattleChess.Add(tmp);
	}
	msg.MoneyGainedBySellChess=pb->moneygainedbysellchess();
}


USTRUCT(BlueprintType)
struct  FPositionFloat2D {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Y;

};
static void _ConvertPbToFPositionFloat2D(FPositionFloat2D &msg, const msg::PositionFloat2D *pb) {
	msg.X=pb->x();
	msg.Y=pb->y();
}


USTRUCT(BlueprintType)
struct  FPlayerBasicInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPvpPlayerData PvpPlayer;

};
static void _ConvertPbToFPlayerBasicInfo(FPlayerBasicInfo &msg, const msg::PlayerBasicInfo *pb) {
	msg.Index=pb->index();
	_ConvertPbToFPvpPlayerData(msg.PvpPlayer, &pb->pvpplayer());
}


USTRUCT(BlueprintType)
struct  FEquipmentInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipBagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D TilePos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OwnerHandle;

};
static void _ConvertPbToFEquipmentInfo(FEquipmentInfo &msg, const msg::EquipmentInfo *pb) {
	msg.NetId=pb->netid();
	msg.EquipId=pb->equipid();
	msg.EquipBagIdx=pb->equipbagidx();
	msg.PlayerIdx=pb->playeridx();
	_ConvertPbToFPositionInt2D(msg.TilePos, &pb->tilepos());
	msg.OwnerHandle=pb->ownerhandle();
}


USTRUCT(BlueprintType)
struct  FChessPiecesMapLevData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessPiecesData> chessPieces;

};
static void _ConvertPbToFChessPiecesMapLevData(FChessPiecesMapLevData &msg, const msg::ChessPiecesMapLevData *pb) {
	msg.level=pb->level();
	for (int i = 0; i < pb->chesspieces().size(); i++) {
		auto &a = pb->chesspieces().Get(i);
		FChessPiecesData tmp;
		_ConvertPbToFChessPiecesData(tmp, &a);
		msg.chessPieces.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPlayerChessNumber {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	// 玩家ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessNumber> chess;

};
static void _ConvertPbToFPlayerChessNumber(FPlayerChessNumber &msg, const msg::PlayerChessNumber *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	for (int i = 0; i < pb->chess().size(); i++) {
		auto &a = pb->chess().Get(i);
		FChessNumber tmp;
		_ConvertPbToFChessNumber(tmp, &a);
		msg.chess.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPlayerStatisticsInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int pidx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int winStreak;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBattleRoundData> roundData;

};
static void _ConvertPbToFPlayerStatisticsInfo(FPlayerStatisticsInfo &msg, const msg::PlayerStatisticsInfo *pb) {
	msg.pidx=pb->pidx();
	msg.winStreak=pb->winstreak();
	for (int i = 0; i < pb->rounddata().size(); i++) {
		auto &a = pb->rounddata().Get(i);
		FBattleRoundData tmp;
		_ConvertPbToFBattleRoundData(tmp, &a);
		msg.roundData.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCorrectFormation {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCharacterInTheBag> BagCharacters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCharacterOnTheMap> MapCharacters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemInTheBag> BagItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemOnTheGround> GroundItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIndex;

};
static void _ConvertPbToFCorrectFormation(FCorrectFormation &msg, const msg::CorrectFormation *pb) {
	for (int i = 0; i < pb->bagcharacters().size(); i++) {
		auto &a = pb->bagcharacters().Get(i);
		FCharacterInTheBag tmp;
		_ConvertPbToFCharacterInTheBag(tmp, &a);
		msg.BagCharacters.Add(tmp);
	}
	for (int i = 0; i < pb->mapcharacters().size(); i++) {
		auto &a = pb->mapcharacters().Get(i);
		FCharacterOnTheMap tmp;
		_ConvertPbToFCharacterOnTheMap(tmp, &a);
		msg.MapCharacters.Add(tmp);
	}
	for (int i = 0; i < pb->bagitems().size(); i++) {
		auto &a = pb->bagitems().Get(i);
		FItemInTheBag tmp;
		_ConvertPbToFItemInTheBag(tmp, &a);
		msg.BagItems.Add(tmp);
	}
	for (int i = 0; i < pb->grounditems().size(); i++) {
		auto &a = pb->grounditems().Get(i);
		FItemOnTheGround tmp;
		_ConvertPbToFItemOnTheGround(tmp, &a);
		msg.GroundItems.Add(tmp);
	}
	msg.PlayerIndex=pb->playerindex();
}


USTRUCT(BlueprintType)
struct  FDivision {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DestPlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TY;

};
static void _ConvertPbToFDivision(FDivision &msg, const msg::Division *pb) {
	msg.NetID=pb->netid();
	msg.EquipID=pb->equipid();
	msg.DestPlayerIndex=pb->destplayerindex();
	msg.TX=pb->tx();
	msg.TY=pb->ty();
}


USTRUCT(BlueprintType)
struct  FAffixTriggerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AffixId;	// (tag.json)="affix_id,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;	// (tag.json)="value,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessHandle;	// (tag.json)="chs_handle,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessId;	// (tag.json)="phone_id,omitempty" 棋盘 棋手 棋子id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FrameIdx;	// (tag.json)="frame_idx,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOnlyTrigger;	// (tag.json)="is_only_trigger,omitempty"

};
static void _ConvertPbToFAffixTriggerInfo(FAffixTriggerInfo &msg, const msg::AffixTriggerInfo *pb) {
	msg.AffixId=pb->affixid();
	msg.Value=pb->value();
	msg.ChessHandle=pb->chesshandle();
	msg.ChessId=pb->chessid();
	msg.FrameIdx=pb->frameidx();
	msg.IsOnlyTrigger=pb->isonlytrigger();
}


USTRUCT(BlueprintType)
struct  FReconnectPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentGold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ShopContents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPvpPlayerData PlayerData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MessengerPosX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MessengerPosY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCharacterInTheBag> BagCharacters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCharacterOnTheMap> MapCharacters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemInTheBag> BagItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemOnTheGround> GroundItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EnemyPlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WinStreak;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WinRoundCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LoseRoundCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rank;

};
static void _ConvertPbToFReconnectPlayer(FReconnectPlayer &msg, const msg::ReconnectPlayer *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.CurrentHp=pb->currenthp();
	msg.CurrentGold=pb->currentgold();
	msg.CurrentLevel=pb->currentlevel();
	msg.CurrentExp=pb->currentexp();
	for (int i = 0; i < pb->shopcontents().size(); i++) {
		auto &a = pb->shopcontents().Get(i);
		int tmp;
		tmp=a;
		msg.ShopContents.Add(tmp);
	}
	_ConvertPbToFPvpPlayerData(msg.PlayerData, &pb->playerdata());
	msg.MessengerPosX=pb->messengerposx();
	msg.MessengerPosY=pb->messengerposy();
	for (int i = 0; i < pb->bagcharacters().size(); i++) {
		auto &a = pb->bagcharacters().Get(i);
		FCharacterInTheBag tmp;
		_ConvertPbToFCharacterInTheBag(tmp, &a);
		msg.BagCharacters.Add(tmp);
	}
	for (int i = 0; i < pb->mapcharacters().size(); i++) {
		auto &a = pb->mapcharacters().Get(i);
		FCharacterOnTheMap tmp;
		_ConvertPbToFCharacterOnTheMap(tmp, &a);
		msg.MapCharacters.Add(tmp);
	}
	for (int i = 0; i < pb->bagitems().size(); i++) {
		auto &a = pb->bagitems().Get(i);
		FItemInTheBag tmp;
		_ConvertPbToFItemInTheBag(tmp, &a);
		msg.BagItems.Add(tmp);
	}
	for (int i = 0; i < pb->grounditems().size(); i++) {
		auto &a = pb->grounditems().Get(i);
		FItemOnTheGround tmp;
		_ConvertPbToFItemOnTheGround(tmp, &a);
		msg.GroundItems.Add(tmp);
	}
	msg.EnemyPlayerIndex=pb->enemyplayerindex();
	msg.WinStreak=pb->winstreak();
	msg.WinRoundCount=pb->winroundcount();
	msg.LoseRoundCount=pb->loseroundcount();
	msg.Rank=pb->rank();
}


USTRUCT(BlueprintType)
struct  FRoundInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Seed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Round;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GameFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameStage CurrentPhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RemainTime;

};
static void _ConvertPbToFRoundInfo(FRoundInfo &msg, const msg::RoundInfo *pb) {
	msg.Seed=pb->seed();
	msg.Round=pb->round();
	msg.GameFrame=pb->gameframe();
	msg.CurrentPhase=(EGameStage)pb->currentphase();
	msg.RemainTime=pb->remaintime();
}


USTRUCT(BlueprintType)
struct  FCSReqSetMessengerPos {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionFloat2D Pos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMessengerMoveType Type;

};
static void _ConvertPbToFCSReqSetMessengerPos(FCSReqSetMessengerPos &msg, const msg::CSReqSetMessengerPos *pb) {
	_ConvertPbToFPositionFloat2D(msg.Pos, &pb->pos());
	msg.Type=(EMessengerMoveType)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSReqPvpSetReadyState {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool State;

};
static void _ConvertPbToFCSReqPvpSetReadyState(FCSReqPvpSetReadyState &msg, const msg::CSReqPvpSetReadyState *pb) {
	msg.State=pb->state();
}


USTRUCT(BlueprintType)
struct  FCSReqSetRefreshShopLock {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsLock;

};
static void _ConvertPbToFCSReqSetRefreshShopLock(FCSReqSetRefreshShopLock &msg, const msg::CSReqSetRefreshShopLock *pb) {
	msg.IsLock=pb->islock();
}


USTRUCT(BlueprintType)
struct  FCSReqRetrieveChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D ChessPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

};
static void _ConvertPbToFCSReqRetrieveChess(FCSReqRetrieveChess &msg, const msg::CSReqRetrieveChess *pb) {
	_ConvertPbToFPositionInt2D(msg.ChessPos, &pb->chesspos());
	msg.BagIndex=pb->bagindex();
}


USTRUCT(BlueprintType)
struct  FCSReqBuyChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShopIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsToBag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDrag;

};
static void _ConvertPbToFCSReqBuyChess(FCSReqBuyChess &msg, const msg::CSReqBuyChess *pb) {
	msg.ShopIndex=pb->shopindex();
	msg.IsToBag=pb->istobag();
	msg.BagIndex=pb->bagindex();
	msg.Tx=pb->tx();
	msg.Ty=pb->ty();
	msg.IsDrag=pb->isdrag();
}


USTRUCT(BlueprintType)
struct  FCSReqSellChessInBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

};
static void _ConvertPbToFCSReqSellChessInBag(FCSReqSellChessInBag &msg, const msg::CSReqSellChessInBag *pb) {
	msg.BagIndex=pb->bagindex();
}


USTRUCT(BlueprintType)
struct  FCSReqSellChessOnBoard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D ChessPos;

};
static void _ConvertPbToFCSReqSellChessOnBoard(FCSReqSellChessOnBoard &msg, const msg::CSReqSellChessOnBoard *pb) {
	_ConvertPbToFPositionInt2D(msg.ChessPos, &pb->chesspos());
}


USTRUCT(BlueprintType)
struct  FCSReqMoveChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D SrcChessPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D DestChessPos;

};
static void _ConvertPbToFCSReqMoveChess(FCSReqMoveChess &msg, const msg::CSReqMoveChess *pb) {
	_ConvertPbToFPositionInt2D(msg.SrcChessPos, &pb->srcchesspos());
	_ConvertPbToFPositionInt2D(msg.DestChessPos, &pb->destchesspos());
}


USTRUCT(BlueprintType)
struct  FCSReqBuyExp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Exp;

};
static void _ConvertPbToFCSReqBuyExp(FCSReqBuyExp &msg, const msg::CSReqBuyExp *pb) {
	msg.Exp=pb->exp();
}


USTRUCT(BlueprintType)
struct  FCSReqRefreshShop {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqRefreshShop(FCSReqRefreshShop &msg, const msg::CSReqRefreshShop *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqMoveChessInBagToMap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D DestPos;

};
static void _ConvertPbToFCSReqMoveChessInBagToMap(FCSReqMoveChessInBagToMap &msg, const msg::CSReqMoveChessInBagToMap *pb) {
	msg.BagIdx=pb->bagidx();
	_ConvertPbToFPositionInt2D(msg.DestPos, &pb->destpos());
}


USTRUCT(BlueprintType)
struct  FCSReqMoveChessWithinBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SrcBagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DestBagIdx;

};
static void _ConvertPbToFCSReqMoveChessWithinBag(FCSReqMoveChessWithinBag &msg, const msg::CSReqMoveChessWithinBag *pb) {
	msg.SrcBagIdx=pb->srcbagidx();
	msg.DestBagIdx=pb->destbagidx();
}


USTRUCT(BlueprintType)
struct  FCSReqPlayerLoaded {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqPlayerLoaded(FCSReqPlayerLoaded &msg, const msg::CSReqPlayerLoaded *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPlayerRoundEnd {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqPlayerRoundEnd(FCSReqPlayerRoundEnd &msg, const msg::CSReqPlayerRoundEnd *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPickupEquipment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

};
static void _ConvertPbToFCSReqPickupEquipment(FCSReqPickupEquipment &msg, const msg::CSReqPickupEquipment *pb) {
	msg.NetId=pb->netid();
}


USTRUCT(BlueprintType)
struct  FCSReqCraftEquip {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> EquipNetIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsToChess;

};
static void _ConvertPbToFCSReqCraftEquip(FCSReqCraftEquip &msg, const msg::CSReqCraftEquip *pb) {
	for (int i = 0; i < pb->equipnetids().size(); i++) {
		auto &a = pb->equipnetids().Get(i);
		int tmp;
		tmp=a;
		msg.EquipNetIds.Add(tmp);
	}
	msg.IsToChess=pb->istochess();
}


USTRUCT(BlueprintType)
struct  FCSReqUseEquipment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsChessInBag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D Pos;

};
static void _ConvertPbToFCSReqUseEquipment(FCSReqUseEquipment &msg, const msg::CSReqUseEquipment *pb) {
	msg.NetId=pb->netid();
	msg.IsChessInBag=pb->ischessinbag();
	msg.BagIndex=pb->bagindex();
	_ConvertPbToFPositionInt2D(msg.Pos, &pb->pos());
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateAntiAddictionTime {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqUpdateAntiAddictionTime(FCSReqUpdateAntiAddictionTime &msg, const msg::CSReqUpdateAntiAddictionTime *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqCancelReconnect {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqCancelReconnect(FCSReqCancelReconnect &msg, const msg::CSReqCancelReconnect *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSetAutoUpgradeCharacter {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SwitchOn;

};
static void _ConvertPbToFCSReqSetAutoUpgradeCharacter(FCSReqSetAutoUpgradeCharacter &msg, const msg::CSReqSetAutoUpgradeCharacter *pb) {
	msg.SwitchOn=pb->switchon();
}


USTRUCT(BlueprintType)
struct  FCSReqReconnect {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqReconnect(FCSReqReconnect &msg, const msg::CSReqReconnect *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqManuallyUpgradeCharacter {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInBag;

};
static void _ConvertPbToFCSReqManuallyUpgradeCharacter(FCSReqManuallyUpgradeCharacter &msg, const msg::CSReqManuallyUpgradeCharacter *pb) {
	msg.BagIndex=pb->bagindex();
	msg.Tx=pb->tx();
	msg.Ty=pb->ty();
	msg.IsInBag=pb->isinbag();
}


USTRUCT(BlueprintType)
struct  FCSReqQuitBattle {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqQuitBattle(FCSReqQuitBattle &msg, const msg::CSReqQuitBattle *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSusPendGame {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool susPend;	// true 表示挂起暂停 fasle表示取消暂停

};
static void _ConvertPbToFCSReqSusPendGame(FCSReqSusPendGame &msg, const msg::CSReqSusPendGame *pb) {
	msg.susPend=pb->suspend();
}


USTRUCT(BlueprintType)
struct  FCSReqChessDB {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqChessDB(FCSReqChessDB &msg, const msg::CSReqChessDB *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqStatisticsInfo {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqStatisticsInfo(FCSReqStatisticsInfo &msg, const msg::CSReqStatisticsInfo *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPassThrough {
	GENERATED_BODY()

	std::string data;

};
static void _ConvertPbToFCSReqPassThrough(FCSReqPassThrough &msg, const msg::CSReqPassThrough *pb) {
	msg.data=pb->data();
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateBattleResult {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqUpdateBattleResult(FCSReqUpdateBattleResult &msg, const msg::CSReqUpdateBattleResult *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqVisitPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SrcPlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DestPlayerIndex;

};
static void _ConvertPbToFCSReqVisitPlayer(FCSReqVisitPlayer &msg, const msg::CSReqVisitPlayer *pb) {
	msg.SrcPlayerIndex=pb->srcplayerindex();
	msg.DestPlayerIndex=pb->destplayerindex();
}


USTRUCT(BlueprintType)
struct  FCSReqLeaveGameEarly {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqLeaveGameEarly(FCSReqLeaveGameEarly &msg, const msg::CSReqLeaveGameEarly *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqReportAbsent {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqReportAbsent(FCSReqReportAbsent &msg, const msg::CSReqReportAbsent *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspSetMessengerPos {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMessengerMoveType Type;

};
static void _ConvertPbToFCSRspSetMessengerPos(FCSRspSetMessengerPos &msg, const msg::CSRspSetMessengerPos *pb) {
	msg.Success=pb->success();
	msg.Type=(EMessengerMoveType)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSRspPvpSetReadyState {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

};
static void _ConvertPbToFCSRspPvpSetReadyState(FCSRspPvpSetReadyState &msg, const msg::CSRspPvpSetReadyState *pb) {
	msg.Success=pb->success();
}


USTRUCT(BlueprintType)
struct  FCSRspSetRefreshShopLock {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsLock;

};
static void _ConvertPbToFCSRspSetRefreshShopLock(FCSRspSetRefreshShopLock &msg, const msg::CSRspSetRefreshShopLock *pb) {
	msg.Success=pb->success();
	msg.IsLock=pb->islock();
}


USTRUCT(BlueprintType)
struct  FCSRspRetrieveChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D SrcChessPos;

};
static void _ConvertPbToFCSRspRetrieveChess(FCSRspRetrieveChess &msg, const msg::CSRspRetrieveChess *pb) {
	msg.Success=pb->success();
	msg.BagIndex=pb->bagindex();
	_ConvertPbToFPositionInt2D(msg.SrcChessPos, &pb->srcchesspos());
}


USTRUCT(BlueprintType)
struct  FCSRspBuyChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShopIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConfigId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsToBag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDrag;

};
static void _ConvertPbToFCSRspBuyChess(FCSRspBuyChess &msg, const msg::CSRspBuyChess *pb) {
	msg.Success=pb->success();
	msg.BagIndex=pb->bagindex();
	msg.ShopIndex=pb->shopindex();
	msg.ConfigId=pb->configid();
	msg.IsToBag=pb->istobag();
	msg.Tx=pb->tx();
	msg.Ty=pb->ty();
	msg.IsDrag=pb->isdrag();
}


USTRUCT(BlueprintType)
struct  FCSRspSellChessInBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LeftMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

};
static void _ConvertPbToFCSRspSellChessInBag(FCSRspSellChessInBag &msg, const msg::CSRspSellChessInBag *pb) {
	msg.Success=pb->success();
	msg.LeftMoney=pb->leftmoney();
	msg.BagIndex=pb->bagindex();
}


USTRUCT(BlueprintType)
struct  FCSRspSellChessOnBoard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LeftMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D ChessPos;

};
static void _ConvertPbToFCSRspSellChessOnBoard(FCSRspSellChessOnBoard &msg, const msg::CSRspSellChessOnBoard *pb) {
	msg.Success=pb->success();
	msg.LeftMoney=pb->leftmoney();
	_ConvertPbToFPositionInt2D(msg.ChessPos, &pb->chesspos());
}


USTRUCT(BlueprintType)
struct  FCSRspMoveChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D SrcChessPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D DestChessPos;

};
static void _ConvertPbToFCSRspMoveChess(FCSRspMoveChess &msg, const msg::CSRspMoveChess *pb) {
	msg.Success=pb->success();
	_ConvertPbToFPositionInt2D(msg.SrcChessPos, &pb->srcchesspos());
	_ConvertPbToFPositionInt2D(msg.DestChessPos, &pb->destchesspos());
}


USTRUCT(BlueprintType)
struct  FCSRspBuyExp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddedExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentExp;

};
static void _ConvertPbToFCSRspBuyExp(FCSRspBuyExp &msg, const msg::CSRspBuyExp *pb) {
	msg.Success=pb->success();
	msg.AddedExp=pb->addedexp();
	msg.CurrentExp=pb->currentexp();
}


USTRUCT(BlueprintType)
struct  FCSRspRefreshShop {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

};
static void _ConvertPbToFCSRspRefreshShop(FCSRspRefreshShop &msg, const msg::CSRspRefreshShop *pb) {
	msg.Success=pb->success();
}


USTRUCT(BlueprintType)
struct  FCSRspMoveChessInBagToMap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D DestPos;

};
static void _ConvertPbToFCSRspMoveChessInBagToMap(FCSRspMoveChessInBagToMap &msg, const msg::CSRspMoveChessInBagToMap *pb) {
	msg.Success=pb->success();
	msg.BagIdx=pb->bagidx();
	_ConvertPbToFPositionInt2D(msg.DestPos, &pb->destpos());
}


USTRUCT(BlueprintType)
struct  FCSRspMoveChessWithinBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SrcBagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DestBagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

};
static void _ConvertPbToFCSRspMoveChessWithinBag(FCSRspMoveChessWithinBag &msg, const msg::CSRspMoveChessWithinBag *pb) {
	msg.SrcBagIdx=pb->srcbagidx();
	msg.DestBagIdx=pb->destbagidx();
	msg.Success=pb->success();
}


USTRUCT(BlueprintType)
struct  FCSRspPlayerLoaded {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPlayerLoaded(FCSRspPlayerLoaded &msg, const msg::CSRspPlayerLoaded *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspPlayerRoundEnd {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPlayerRoundEnd(FCSRspPlayerRoundEnd &msg, const msg::CSRspPlayerRoundEnd *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspPickupEquipment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIdx;

};
static void _ConvertPbToFCSRspPickupEquipment(FCSRspPickupEquipment &msg, const msg::CSRspPickupEquipment *pb) {
	msg.NetId=pb->netid();
	msg.Success=pb->success();
	msg.BagIdx=pb->bagidx();
}


USTRUCT(BlueprintType)
struct  FCSRspCraftEquip {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsToChess;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Equips;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEquipmentInfo NewEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessBagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOnBattle;

};
static void _ConvertPbToFCSRspCraftEquip(FCSRspCraftEquip &msg, const msg::CSRspCraftEquip *pb) {
	msg.Success=pb->success();
	msg.IsToChess=pb->istochess();
	for (int i = 0; i < pb->equips().size(); i++) {
		auto &a = pb->equips().Get(i);
		int tmp;
		tmp=a;
		msg.Equips.Add(tmp);
	}
	_ConvertPbToFEquipmentInfo(msg.NewEquip, &pb->newequip());
	msg.ChessBagIdx=pb->chessbagidx();
	msg.IsOnBattle=pb->isonbattle();
}


USTRUCT(BlueprintType)
struct  FCSRspUseEquipment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsChessInBag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessBagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipBagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D Pos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOnBattle;

};
static void _ConvertPbToFCSRspUseEquipment(FCSRspUseEquipment &msg, const msg::CSRspUseEquipment *pb) {
	msg.NetId=pb->netid();
	msg.IsChessInBag=pb->ischessinbag();
	msg.ChessBagIndex=pb->chessbagindex();
	msg.EquipBagIndex=pb->equipbagindex();
	_ConvertPbToFPositionInt2D(msg.Pos, &pb->pos());
	msg.Success=pb->success();
	msg.IsOnBattle=pb->isonbattle();
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateAntiAddictionTime {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateAntiAddictionTime(FCSRspUpdateAntiAddictionTime &msg, const msg::CSRspUpdateAntiAddictionTime *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspCancelReconnect {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspCancelReconnect(FCSRspCancelReconnect &msg, const msg::CSRspCancelReconnect *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspSetAutoUpgradeCharacter {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SwitchOn;

};
static void _ConvertPbToFCSRspSetAutoUpgradeCharacter(FCSRspSetAutoUpgradeCharacter &msg, const msg::CSRspSetAutoUpgradeCharacter *pb) {
	msg.SwitchOn=pb->switchon();
}


USTRUCT(BlueprintType)
struct  FCSRspReconnect {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsValid;

};
static void _ConvertPbToFCSRspReconnect(FCSRspReconnect &msg, const msg::CSRspReconnect *pb) {
	msg.IsValid=pb->isvalid();
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateRank {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateRank(FCSRspUpdateRank &msg, const msg::CSRspUpdateRank *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspManuallyUpgradeCharacter {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInBag;

};
static void _ConvertPbToFCSRspManuallyUpgradeCharacter(FCSRspManuallyUpgradeCharacter &msg, const msg::CSRspManuallyUpgradeCharacter *pb) {
	msg.BagIndex=pb->bagindex();
	msg.Tx=pb->tx();
	msg.Ty=pb->ty();
	msg.Success=pb->success();
	msg.IsInBag=pb->isinbag();
}


USTRUCT(BlueprintType)
struct  FCSRspQuitBattle {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

};
static void _ConvertPbToFCSRspQuitBattle(FCSRspQuitBattle &msg, const msg::CSRspQuitBattle *pb) {
	msg.Success=pb->success();
}


USTRUCT(BlueprintType)
struct  FCSRspSusPendGame {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool susPend;	// true 表示挂起暂停 fasle表示取消暂停

};
static void _ConvertPbToFCSRspSusPendGame(FCSRspSusPendGame &msg, const msg::CSRspSusPendGame *pb) {
	msg.susPend=pb->suspend();
}


USTRUCT(BlueprintType)
struct  FCSRspChessDB {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessPiecesMapLevData> chessPiecesMapLev;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPlayerChessNumber> playerChess;

};
static void _ConvertPbToFCSRspChessDB(FCSRspChessDB &msg, const msg::CSRspChessDB *pb) {
	for (int i = 0; i < pb->chesspiecesmaplev().size(); i++) {
		auto &a = pb->chesspiecesmaplev().Get(i);
		FChessPiecesMapLevData tmp;
		_ConvertPbToFChessPiecesMapLevData(tmp, &a);
		msg.chessPiecesMapLev.Add(tmp);
	}
	for (int i = 0; i < pb->playerchess().size(); i++) {
		auto &a = pb->playerchess().Get(i);
		FPlayerChessNumber tmp;
		_ConvertPbToFPlayerChessNumber(tmp, &a);
		msg.playerChess.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspStatisticsInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int initMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPlayerStatisticsInfo> playerStatistics;

};
static void _ConvertPbToFCSRspStatisticsInfo(FCSRspStatisticsInfo &msg, const msg::CSRspStatisticsInfo *pb) {
	msg.initMoney=pb->initmoney();
	for (int i = 0; i < pb->playerstatistics().size(); i++) {
		auto &a = pb->playerstatistics().Get(i);
		FPlayerStatisticsInfo tmp;
		_ConvertPbToFPlayerStatisticsInfo(tmp, &a);
		msg.playerStatistics.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspPassThrough {
	GENERATED_BODY()

	TArray<std::string> data;

};
static void _ConvertPbToFCSRspPassThrough(FCSRspPassThrough &msg, const msg::CSRspPassThrough *pb) {
	for (int i = 0; i < pb->data().size(); i++) {
		auto &a = pb->data().Get(i);
		std::string tmp;
		tmp=a;
		msg.data.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateBattleResult {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateBattleResult(FCSRspUpdateBattleResult &msg, const msg::CSRspUpdateBattleResult *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspVisitPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SrcPlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DestPlayerIndex;

};
static void _ConvertPbToFCSRspVisitPlayer(FCSRspVisitPlayer &msg, const msg::CSRspVisitPlayer *pb) {
	msg.SrcPlayerIndex=pb->srcplayerindex();
	msg.DestPlayerIndex=pb->destplayerindex();
}


USTRUCT(BlueprintType)
struct  FCSRspLeaveGameEarly {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspLeaveGameEarly(FCSRspLeaveGameEarly &msg, const msg::CSRspLeaveGameEarly *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspReportAbsent {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspReportAbsent(FCSRspReportAbsent &msg, const msg::CSRspReportAbsent *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpChangeStage {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoundCnt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameStage Stage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCorrectFormation> Correction;

};
static void _ConvertPbToFCSNtfPvpChangeStage(FCSNtfPvpChangeStage &msg, const msg::CSNtfPvpChangeStage *pb) {
	msg.RoundCnt=pb->roundcnt();
	msg.Duration=pb->duration();
	msg.Stage=(EGameStage)pb->stage();
	for (int i = 0; i < pb->correction().size(); i++) {
		auto &a = pb->correction().Get(i);
		FCorrectFormation tmp;
		_ConvertPbToFCorrectFormation(tmp, &a);
		msg.Correction.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpUpdateMoney {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Money;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SrcTag;	// 0: by round, 1: sell chess

};
static void _ConvertPbToFCSNtfPvpUpdateMoney(FCSNtfPvpUpdateMoney &msg, const msg::CSNtfPvpUpdateMoney *pb) {
	msg.Money=pb->money();
	msg.PlayerIdx=pb->playeridx();
	msg.SrcTag=pb->srctag();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpUpdateMessengerPos {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionFloat2D Pos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMessengerMoveType Type;

};
static void _ConvertPbToFCSNtfPvpUpdateMessengerPos(FCSNtfPvpUpdateMessengerPos &msg, const msg::CSNtfPvpUpdateMessengerPos *pb) {
	msg.PlayerIndex=pb->playerindex();
	_ConvertPbToFPositionFloat2D(msg.Pos, &pb->pos());
	msg.Type=(EMessengerMoveType)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpPlayerLoggedIn {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPlayerBasicInfo PlayerInfo;

};
static void _ConvertPbToFCSNtfPvpPlayerLoggedIn(FCSNtfPvpPlayerLoggedIn &msg, const msg::CSNtfPvpPlayerLoggedIn *pb) {
	_ConvertPbToFPlayerBasicInfo(msg.PlayerInfo, &pb->playerinfo());
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpSetReadyState {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool State;

};
static void _ConvertPbToFCSNtfPvpSetReadyState(FCSNtfPvpSetReadyState &msg, const msg::CSNtfPvpSetReadyState *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.State=pb->state();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpPlayerAllReady {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfPvpPlayerAllReady(FCSNtfPvpPlayerAllReady &msg, const msg::CSNtfPvpPlayerAllReady *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpPlayerDead {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

};
static void _ConvertPbToFCSNtfPvpPlayerDead(FCSNtfPvpPlayerDead &msg, const msg::CSNtfPvpPlayerDead *pb) {
	msg.PlayerIdx=pb->playeridx();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpPlayerOffline {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

};
static void _ConvertPbToFCSNtfPvpPlayerOffline(FCSNtfPvpPlayerOffline &msg, const msg::CSNtfPvpPlayerOffline *pb) {
	msg.PlayerIdx=pb->playeridx();
}


USTRUCT(BlueprintType)
struct  FCSNtfChessOnBoardSold {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D SrcPos;

};
static void _ConvertPbToFCSNtfChessOnBoardSold(FCSNtfChessOnBoardSold &msg, const msg::CSNtfChessOnBoardSold *pb) {
	msg.PlayerIdx=pb->playeridx();
	_ConvertPbToFPositionInt2D(msg.SrcPos, &pb->srcpos());
}


USTRUCT(BlueprintType)
struct  FCSNtfChessRemovedFromBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

};
static void _ConvertPbToFCSNtfChessRemovedFromBag(FCSNtfChessRemovedFromBag &msg, const msg::CSNtfChessRemovedFromBag *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.BagIndex=pb->bagindex();
}


USTRUCT(BlueprintType)
struct  FCSNtfBuyChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessConfigId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsToBag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDrag;

};
static void _ConvertPbToFCSNtfBuyChess(FCSNtfBuyChess &msg, const msg::CSNtfBuyChess *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.ChessConfigId=pb->chessconfigid();
	msg.IsToBag=pb->istobag();
	msg.BagIndex=pb->bagindex();
	msg.Tx=pb->tx();
	msg.Ty=pb->ty();
	msg.IsDrag=pb->isdrag();
}


USTRUCT(BlueprintType)
struct  FCSNtfChessRetrievedToBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D SrcPos;

};
static void _ConvertPbToFCSNtfChessRetrievedToBag(FCSNtfChessRetrievedToBag &msg, const msg::CSNtfChessRetrievedToBag *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.BagIndex=pb->bagindex();
	_ConvertPbToFPositionInt2D(msg.SrcPos, &pb->srcpos());
}


USTRUCT(BlueprintType)
struct  FCSNtfChessMoved {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D SrcPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D DestPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

};
static void _ConvertPbToFCSNtfChessMoved(FCSNtfChessMoved &msg, const msg::CSNtfChessMoved *pb) {
	_ConvertPbToFPositionInt2D(msg.SrcPos, &pb->srcpos());
	_ConvertPbToFPositionInt2D(msg.DestPos, &pb->destpos());
	msg.PlayerIdx=pb->playeridx();
	msg.Success=pb->success();
}


USTRUCT(BlueprintType)
struct  FCSNtfChessFromBagToMap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D DestPos;

};
static void _ConvertPbToFCSNtfChessFromBagToMap(FCSNtfChessFromBagToMap &msg, const msg::CSNtfChessFromBagToMap *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.BagIdx=pb->bagidx();
	_ConvertPbToFPositionInt2D(msg.DestPos, &pb->destpos());
}


USTRUCT(BlueprintType)
struct  FCSNtfPlayerLvUpgraded {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewPlayerLv;

};
static void _ConvertPbToFCSNtfPlayerLvUpgraded(FCSNtfPlayerLvUpgraded &msg, const msg::CSNtfPlayerLvUpgraded *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.NewPlayerLv=pb->newplayerlv();
}


USTRUCT(BlueprintType)
struct  FCSNtfUpdateExp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentExp;

};
static void _ConvertPbToFCSNtfUpdateExp(FCSNtfUpdateExp &msg, const msg::CSNtfUpdateExp *pb) {
	msg.CurrentExp=pb->currentexp();
}


USTRUCT(BlueprintType)
struct  FCSNtfSetEnemy {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EnemyIdx;

};
static void _ConvertPbToFCSNtfSetEnemy(FCSNtfSetEnemy &msg, const msg::CSNtfSetEnemy *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.EnemyIdx=pb->enemyidx();
}


USTRUCT(BlueprintType)
struct  FCSNtfSetSeed {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Seed;

};
static void _ConvertPbToFCSNtfSetSeed(FCSNtfSetSeed &msg, const msg::CSNtfSetSeed *pb) {
	msg.Seed=pb->seed();
}


USTRUCT(BlueprintType)
struct  FCSNtfBattleTerminated {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfBattleTerminated(FCSNtfBattleTerminated &msg, const msg::CSNtfBattleTerminated *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfShopRefreshed {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Chesses;

};
static void _ConvertPbToFCSNtfShopRefreshed(FCSNtfShopRefreshed &msg, const msg::CSNtfShopRefreshed *pb) {
	for (int i = 0; i < pb->chesses().size(); i++) {
		auto &a = pb->chesses().Get(i);
		int tmp;
		tmp=a;
		msg.Chesses.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfChessMovedWithinBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SrcBagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DestBagIdx;

};
static void _ConvertPbToFCSNtfChessMovedWithinBag(FCSNtfChessMovedWithinBag &msg, const msg::CSNtfChessMovedWithinBag *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.SrcBagIdx=pb->srcbagidx();
	msg.DestBagIdx=pb->destbagidx();
}


USTRUCT(BlueprintType)
struct  FCSNtfCreepDied {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CreepId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipNetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D CreepPos;

};
static void _ConvertPbToFCSNtfCreepDied(FCSNtfCreepDied &msg, const msg::CSNtfCreepDied *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.CreepId=pb->creepid();
	msg.EquipNetId=pb->equipnetid();
	msg.EquipId=pb->equipid();
	_ConvertPbToFPositionInt2D(msg.CreepPos, &pb->creeppos());
}


USTRUCT(BlueprintType)
struct  FCSNtfUpdateHp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Hp;

};
static void _ConvertPbToFCSNtfUpdateHp(FCSNtfUpdateHp &msg, const msg::CSNtfUpdateHp *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.Hp=pb->hp();
}


USTRUCT(BlueprintType)
struct  FCSNtfPickupEquipment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipNetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIdx;

};
static void _ConvertPbToFCSNtfPickupEquipment(FCSNtfPickupEquipment &msg, const msg::CSNtfPickupEquipment *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.EquipNetId=pb->equipnetid();
	msg.BagIdx=pb->bagidx();
}


USTRUCT(BlueprintType)
struct  FCSNtfUseEquipment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsChessInBag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D Pos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipBagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOnBattle;

};
static void _ConvertPbToFCSNtfUseEquipment(FCSNtfUseEquipment &msg, const msg::CSNtfUseEquipment *pb) {
	msg.NetId=pb->netid();
	msg.IsChessInBag=pb->ischessinbag();
	msg.BagIndex=pb->bagindex();
	msg.PlayerIdx=pb->playeridx();
	_ConvertPbToFPositionInt2D(msg.Pos, &pb->pos());
	msg.EquipBagIndex=pb->equipbagindex();
	msg.IsOnBattle=pb->isonbattle();
}


USTRUCT(BlueprintType)
struct  FCSNtfOperateEquipInBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipmentId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRemoved;

};
static void _ConvertPbToFCSNtfOperateEquipInBag(FCSNtfOperateEquipInBag &msg, const msg::CSNtfOperateEquipInBag *pb) {
	msg.NetId=pb->netid();
	msg.EquipmentId=pb->equipmentid();
	msg.BagIdx=pb->bagidx();
	msg.PlayerIdx=pb->playeridx();
	msg.IsRemoved=pb->isremoved();
}


USTRUCT(BlueprintType)
struct  FCSNtfOperateEquipOnChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRemoved;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsChessOnBoard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessBagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPositionInt2D ChessTilePos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipmentId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessSlotIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOnBattle;

};
static void _ConvertPbToFCSNtfOperateEquipOnChess(FCSNtfOperateEquipOnChess &msg, const msg::CSNtfOperateEquipOnChess *pb) {
	msg.NetId=pb->netid();
	msg.PlayerIdx=pb->playeridx();
	msg.IsRemoved=pb->isremoved();
	msg.IsChessOnBoard=pb->ischessonboard();
	msg.ChessBagIndex=pb->chessbagindex();
	_ConvertPbToFPositionInt2D(msg.ChessTilePos, &pb->chesstilepos());
	msg.EquipmentId=pb->equipmentid();
	msg.ChessSlotIndex=pb->chessslotindex();
	msg.IsOnBattle=pb->isonbattle();
}


USTRUCT(BlueprintType)
struct  FCSNtfAntiAddictionTime {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalOnlineDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalOfflineDuration;

};
static void _ConvertPbToFCSNtfAntiAddictionTime(FCSNtfAntiAddictionTime &msg, const msg::CSNtfAntiAddictionTime *pb) {
	msg.TotalOnlineDuration=pb->totalonlineduration();
	msg.TotalOfflineDuration=pb->totalofflineduration();
}


USTRUCT(BlueprintType)
struct  FCSNtfAntiAddictionTriggered {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfAntiAddictionTriggered(FCSNtfAntiAddictionTriggered &msg, const msg::CSNtfAntiAddictionTriggered *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfAntiAddictionRemoved {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfAntiAddictionRemoved(FCSNtfAntiAddictionRemoved &msg, const msg::CSNtfAntiAddictionRemoved *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfUnsuggestedPhase {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfUnsuggestedPhase(FCSNtfUnsuggestedPhase &msg, const msg::CSNtfUnsuggestedPhase *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfGameEnd {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfGameEnd(FCSNtfGameEnd &msg, const msg::CSNtfGameEnd *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfCandyReward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CandyCnt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

};
static void _ConvertPbToFCSNtfCandyReward(FCSNtfCandyReward &msg, const msg::CSNtfCandyReward *pb) {
	msg.CandyCnt=pb->candycnt();
	msg.PlayerIdx=pb->playeridx();
}


USTRUCT(BlueprintType)
struct  FCSNtfWinStreak {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WinStreak;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

};
static void _ConvertPbToFCSNtfWinStreak(FCSNtfWinStreak &msg, const msg::CSNtfWinStreak *pb) {
	msg.WinStreak=pb->winstreak();
	msg.PlayerIdx=pb->playeridx();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpState {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GameID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpTCPAddr;

};
static void _ConvertPbToFCSNtfPvpState(FCSNtfPvpState &msg, const msg::CSNtfPvpState *pb) {
	msg.PvpID=pb->pvpid();
	msg.GameID=pb->gameid();
	msg.PvpTCPAddr=UTF8_TO_TCHAR(pb->pvptcpaddr().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfSetAutoUpgradeCharacter {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SwitchOn;

};
static void _ConvertPbToFCSNtfSetAutoUpgradeCharacter(FCSNtfSetAutoUpgradeCharacter &msg, const msg::CSNtfSetAutoUpgradeCharacter *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.SwitchOn=pb->switchon();
}


USTRUCT(BlueprintType)
struct  FCSNtfManuallyUpgradeCharacter {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BagIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInBag;

};
static void _ConvertPbToFCSNtfManuallyUpgradeCharacter(FCSNtfManuallyUpgradeCharacter &msg, const msg::CSNtfManuallyUpgradeCharacter *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.BagIndex=pb->bagindex();
	msg.Tx=pb->tx();
	msg.Ty=pb->ty();
	msg.IsInBag=pb->isinbag();
}


USTRUCT(BlueprintType)
struct  FCSNtfQuitBattle {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIndex;

};
static void _ConvertPbToFCSNtfQuitBattle(FCSNtfQuitBattle &msg, const msg::CSNtfQuitBattle *pb) {
	msg.PlayerIndex=pb->playerindex();
}


USTRUCT(BlueprintType)
struct  FCSNtfRoundResult {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWINTYPE Result;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LeftFriendCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Damage;

};
static void _ConvertPbToFCSNtfRoundResult(FCSNtfRoundResult &msg, const msg::CSNtfRoundResult *pb) {
	msg.Result=(EWINTYPE)pb->result();
	msg.LeftFriendCount=pb->leftfriendcount();
	msg.Damage=pb->damage();
}


USTRUCT(BlueprintType)
struct  FCSNtfSuspendGame {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool susPend;	// true 表示挂起暂停 fasle表示取消暂停

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString pid;	// 如果是恢复的话需要带着时间下去

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int resumeTime;

};
static void _ConvertPbToFCSNtfSuspendGame(FCSNtfSuspendGame &msg, const msg::CSNtfSuspendGame *pb) {
	msg.susPend=pb->suspend();
	msg.pid=UTF8_TO_TCHAR(pb->pid().c_str());
	msg.resumeTime=pb->resumetime();
}


USTRUCT(BlueprintType)
struct  FCSNtfPassThrough {
	GENERATED_BODY()

	std::string data;

};
static void _ConvertPbToFCSNtfPassThrough(FCSNtfPassThrough &msg, const msg::CSNtfPassThrough *pb) {
	msg.data=pb->data();
}


USTRUCT(BlueprintType)
struct  FCSNtfUpdateBattleResult {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTCampData> Camp;

};
static void _ConvertPbToFCSNtfUpdateBattleResult(FCSNtfUpdateBattleResult &msg, const msg::CSNtfUpdateBattleResult *pb) {
	for (int i = 0; i < pb->camp().size(); i++) {
		auto &a = pb->camp().Get(i);
		FCSDTCampData tmp;
		_ConvertPbToFCSDTCampData(tmp, &a);
		msg.Camp.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfAA {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAddictionState State;

	int64 TotalOnlineDuration;

	int64 TotalOfflineDuration;

};
static void _ConvertPbToFCSNtfAA(FCSNtfAA &msg, const msg::CSNtfAA *pb) {
	msg.State=(EAddictionState)pb->state();
	msg.TotalOnlineDuration=pb->totalonlineduration();
	msg.TotalOfflineDuration=pb->totalofflineduration();
}


USTRUCT(BlueprintType)
struct  FCSNtfEquipDivision {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SrcPlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDivision> Divisions;

};
static void _ConvertPbToFCSNtfEquipDivision(FCSNtfEquipDivision &msg, const msg::CSNtfEquipDivision *pb) {
	msg.SrcPlayerIndex=pb->srcplayerindex();
	for (int i = 0; i < pb->divisions().size(); i++) {
		auto &a = pb->divisions().Get(i);
		FDivision tmp;
		_ConvertPbToFDivision(tmp, &a);
		msg.Divisions.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfVisitPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SrcPlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DestPlayerIndex;

};
static void _ConvertPbToFCSNtfVisitPlayer(FCSNtfVisitPlayer &msg, const msg::CSNtfVisitPlayer *pb) {
	msg.SrcPlayerIndex=pb->srcplayerindex();
	msg.DestPlayerIndex=pb->destplayerindex();
}


USTRUCT(BlueprintType)
struct  FCSNtfLeaveGameEarly {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIndex;

};
static void _ConvertPbToFCSNtfLeaveGameEarly(FCSNtfLeaveGameEarly &msg, const msg::CSNtfLeaveGameEarly *pb) {
	msg.PlayerIndex=pb->playerindex();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpAffixTrigger {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAffixTriggerInfo> Affix;

};
static void _ConvertPbToFCSNtfPvpAffixTrigger(FCSNtfPvpAffixTrigger &msg, const msg::CSNtfPvpAffixTrigger *pb) {
	msg.PlayerIndex=pb->playerindex();
	for (int i = 0; i < pb->affix().size(); i++) {
		auto &a = pb->affix().Get(i);
		FAffixTriggerInfo tmp;
		_ConvertPbToFAffixTriggerInfo(tmp, &a);
		msg.Affix.Add(tmp);
	}
}


