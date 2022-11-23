/*
Proto buf => BP

*/
#pragma once


#include "CoreMinimal.h"
#include "csprotocolstruct.pb.h"
#include "result.h"
#include "result.pb.h"
#include "common.h"
#include "common.pb.h"
#include "csprotocolstruct.generated.h"


UENUM(BlueprintType)
enum class ETLOGTYPE: uint8 {
	TLOGTYPE_NONE = 0 UMETA(DisplayName="TLOGTYPE_NONE"),
	TLOGTYPE_BATTLE_FORMATION = 1 UMETA(DisplayName="TLOGTYPE_BATTLE_FORMATION"),	// 查看阵容
	TLOGTYPE_SHARE = 2 UMETA(DisplayName="TLOGTYPE_SHARE"),	// 分享
	TLOGTYPE_AUTO_BATTLE = 3 UMETA(DisplayName="TLOGTYPE_AUTO_BATTLE"),	// 托管
	TLOGTYPE_SEC_SOCIAL = 4 UMETA(DisplayName="TLOGTYPE_SEC_SOCIAL"),	// 社交（腾讯安全）
	TLOGTYPE_CHARGE = 5 UMETA(DisplayName="TLOGTYPE_CHARGE"),	// 甜甜圈购买
	TLOGTYPE_SINGLEROUNDFLOW = 6 UMETA(DisplayName="TLOGTYPE_SINGLEROUNDFLOW"),	// 回合日志
	TLOGTYPE_GVOICE = 7 UMETA(DisplayName="TLOGTYPE_GVOICE"),	// 语音
	TLOGTYPE_PAILIANTU = 8 UMETA(DisplayName="TLOGTYPE_PAILIANTU"),	// 拍脸图
	TLOGTYPE_SKIP_CG_GUIDE = 9 UMETA(DisplayName="TLOGTYPE_SKIP_CG_GUIDE"),	// 跳过引导CG
	TLOGTYPE_FORCE_BATTLE_GUIDE = 10 UMETA(DisplayName="TLOGTYPE_FORCE_BATTLE_GUIDE"),	// 强制战斗引导
	TLOGTYPE_CLICK_STRONGER = 11 UMETA(DisplayName="TLOGTYPE_CLICK_STRONGER"),	// 点击我要变强
	TLOGTYPE_CLICK_STRONGER_OPTION = 12 UMETA(DisplayName="TLOGTYPE_CLICK_STRONGER_OPTION"),	// 点击我要变强选项
	TLOGTYPE_TOURNAMENT_SIGNUP = 13 UMETA(DisplayName="TLOGTYPE_TOURNAMENT_SIGNUP"),	// 锦标赛报名
	TLOGTYPE_COMMON_INVTITE = 14 UMETA(DisplayName="TLOGTYPE_COMMON_INVTITE"),	// 公共邀约
};

UENUM(BlueprintType)
enum class EVERSIONUPGRADETYPE: uint8 {
	VERSIONUPGRADETYPE_NULL = 0 UMETA(DisplayName="VERSIONUPGRADETYPE_NULL"),	//无需升级
	VERSIONUPGRADETYPE_FORCE = 1 UMETA(DisplayName="VERSIONUPGRADETYPE_FORCE"),	//强制升级
	VERSIONUPGRADETYPE_OPTIONAL = 2 UMETA(DisplayName="VERSIONUPGRADETYPE_OPTIONAL"),	//可选升级
};

UENUM(BlueprintType)
enum class EPASSPORTLEVALAWARD: uint8 {
	LEVELAWARD_ALL = 0 UMETA(DisplayName="LEVELAWARD_ALL"),	//全部领取
	LEVELAWARD_FREE = 1 UMETA(DisplayName="LEVELAWARD_FREE"),	//免费部分
	LEVELAWARD_CHARGE = 2 UMETA(DisplayName="LEVELAWARD_CHARGE"),	//付费部分
};

UENUM(BlueprintType)
enum class EALPHA_ACTIVITY_STATE: uint8 {
	ALPHA_ACTIVITY_STATE_NOT_PARTICIPATE = 0 UMETA(DisplayName="ALPHA_ACTIVITY_STATE_NOT_PARTICIPATE"),
	ALPHA_ACTIVITY_STATE_CAN_GET = 1 UMETA(DisplayName="ALPHA_ACTIVITY_STATE_CAN_GET"),
	ALPHA_ACTIVITY_STATE_AWARDED = 2 UMETA(DisplayName="ALPHA_ACTIVITY_STATE_AWARDED"),
};

UENUM(BlueprintType)
enum class EBINDSWITCHTYPE: uint8 {
	BINDSWITCHTYPE_NULL = 0 UMETA(DisplayName="BINDSWITCHTYPE_NULL"),	// 不绑定
	BINDSWITCHTYPE_CAN = 1 UMETA(DisplayName="BINDSWITCHTYPE_CAN"),	// 可以绑定
	BINDSWITCHTYPE_TIPS = 2 UMETA(DisplayName="BINDSWITCHTYPE_TIPS"),	// 弹窗绑定
	BINDSWITCHTYPE_MUST = 3 UMETA(DisplayName="BINDSWITCHTYPE_MUST"),	// 必须绑定
};

UENUM(BlueprintType)
enum class EDailyShareType: uint8 {
	UserInfo = 0 UMETA(DisplayName="UserInfo"),	// 个人信息分享
	FriendRank = 1 UMETA(DisplayName="FriendRank"),	// 好友排行榜
	PVPCount = 2 UMETA(DisplayName="PVPCount"),	// 对局数分享
	Chess = 3 UMETA(DisplayName="Chess"),	// 棋子图鉴分享
	Calendar = 4 UMETA(DisplayName="Calendar"),	// 老黄历分享
	RankUpgrade = 5 UMETA(DisplayName="RankUpgrade"),	// 段位升级分享
	PVPTop3 = 6 UMETA(DisplayName="PVPTop3"),	// pvp第一名第二名第三名分享
	FriendInvite = 7 UMETA(DisplayName="FriendInvite"),	// 同玩好友邀请奖励
	PassLevelShar = 8 UMETA(DisplayName="PassLevelShar"),	// 通行证每日等级分享
	PassTaskCommon = 9 UMETA(DisplayName="PassTaskCommon"),	// 通行证通用任务分享
	PTaskMoney = 10 UMETA(DisplayName="PTaskMoney"),	//通行证金币任务分享
	PTaskScatter = 11 UMETA(DisplayName="PTaskScatter"),	//通行证星罗棋布任务分享
	PTaskRecruitArmy = 12 UMETA(DisplayName="PTaskRecruitArmy"),	//通行证招兵买马任务分享
	PTaskArmyTeeth = 13 UMETA(DisplayName="PTaskArmyTeeth"),	//通行证全副武装任务分享
	Max_NUM = 14 UMETA(DisplayName="Max_NUM"),	// 最大
};

UENUM(BlueprintType)
enum class EVERIFICATIONCODETYPE: uint8 {
	BIND_PHONE = 0 UMETA(DisplayName="BIND_PHONE"),	//绑定手机号
	GET_OLD_PLAYER = 1 UMETA(DisplayName="GET_OLD_PLAYER"),	//获取老账号
};

UENUM(BlueprintType)
enum class EWxVVipAwardTYPE: uint8 {
	DAILY_RWD = 0 UMETA(DisplayName="DAILY_RWD"),	//普通日奖励
	DAILY_V_RWD = 1 UMETA(DisplayName="DAILY_V_RWD"),	//VIP日奖励
	WEEKLY_V_RWD = 2 UMETA(DisplayName="WEEKLY_V_RWD"),	//VIP周奖励
};

UENUM(BlueprintType)
enum class EPriChatType: uint8 {
	NormalMsg = 0 UMETA(DisplayName="NormalMsg"),	//正常消息
	FollowNtf = 1 UMETA(DisplayName="FollowNtf"),	//好友关注通知
};

UENUM(BlueprintType)
enum class EPUZZLE_AWARD_TYPE: uint8 {
	AWARD_NORMAL = 0 UMETA(DisplayName="AWARD_NORMAL"),	//正常
	FLIP_CARDS = 1 UMETA(DisplayName="FLIP_CARDS"),	//翻牌
	GROUP_AWARD = 2 UMETA(DisplayName="GROUP_AWARD"),	//组奖励
	BIG_AWARD = 3 UMETA(DisplayName="BIG_AWARD"),	//大奖
};

UENUM(BlueprintType)
enum class EPLAYER_BIND_STATUS: uint8 {
	PLAYER_NOT_BIND = 0 UMETA(DisplayName="PLAYER_NOT_BIND"),	// 暂未绑定
	PLAYER_UN_BIND = 1 UMETA(DisplayName="PLAYER_UN_BIND"),	// 已经解绑
	PLAYER_PS_ALREADY_BIND = 2 UMETA(DisplayName="PLAYER_PS_ALREADY_BIND"),	// 已经绑定
};

UENUM(BlueprintType)
enum class ESEQTYPE: uint8 {
	SEQTYPE_GAMETIME_MAX = 0 UMETA(DisplayName="SEQTYPE_GAMETIME_MAX"),	//游戏最大时长
	SEQTYPE_OFFLINE = 1 UMETA(DisplayName="SEQTYPE_OFFLINE"),	//掉线
	SEQTYPE_MOVE_CHESSMAN = 2 UMETA(DisplayName="SEQTYPE_MOVE_CHESSMAN"),
	SEQTYPE_LOCK_SHOP = 3 UMETA(DisplayName="SEQTYPE_LOCK_SHOP"),
	SEQTYPE_REFRESH_SHOP = 4 UMETA(DisplayName="SEQTYPE_REFRESH_SHOP"),
	SEQTYPE_ADD_PLAYER_EXP = 5 UMETA(DisplayName="SEQTYPE_ADD_PLAYER_EXP"),
	SEQTYPE_COMPOSE_EQUIPMENT = 6 UMETA(DisplayName="SEQTYPE_COMPOSE_EQUIPMENT"),
	SEQTYPE_EQUIP_CHESSMAN = 7 UMETA(DisplayName="SEQTYPE_EQUIP_CHESSMAN"),
	SEQTYPE_PICK_EQUIPMENT = 8 UMETA(DisplayName="SEQTYPE_PICK_EQUIPMENT"),
	SEQTYPE_ROUND_READY = 9 UMETA(DisplayName="SEQTYPE_ROUND_READY"),
	SEQTYPE_ON_LINE = 10 UMETA(DisplayName="SEQTYPE_ON_LINE"),
	SEQTYPE_MOVE_CHESS_PLAYER = 11 UMETA(DisplayName="SEQTYPE_MOVE_CHESS_PLAYER"),
	SEQTYPE_GIVE_UP = 12 UMETA(DisplayName="SEQTYPE_GIVE_UP"),
	SEQTYPE_CHANGE_BATTLE_SETTING = 13 UMETA(DisplayName="SEQTYPE_CHANGE_BATTLE_SETTING"),
	SEQTYPE_SELECT_EQUIPMENT = 14 UMETA(DisplayName="SEQTYPE_SELECT_EQUIPMENT"),	//装备选择
};

UENUM(BlueprintType)
enum class ECustomCardOptType: uint8 {
	REQUEST = 0 UMETA(DisplayName="REQUEST"),	// 获取
	SAVE = 1 UMETA(DisplayName="SAVE"),	// 保存
	SET = 2 UMETA(DisplayName="SET"),	// 设置使用地图卡组
};

USTRUCT(BlueprintType)
struct  FCSDTPassportTask {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//任务ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Progress;	//任务进度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool GetAward;	//是否领奖

};
static void _ConvertPbToFCSDTPassportTask(FCSDTPassportTask &msg, const msg::CSDTPassportTask *pb) {
	msg.Id=pb->id();
	msg.Progress=pb->progress();
	msg.GetAward=pb->getaward();
}


USTRUCT(BlueprintType)
struct  FCSDTExchangePassportGoodsData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

};
static void _ConvertPbToFCSDTExchangePassportGoodsData(FCSDTExchangePassportGoodsData &msg, const msg::CSDTExchangePassportGoodsData *pb) {
	msg.Id=pb->id();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSDTBuyPassportActivity {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EACTIVITYTYPE Type;

	int64 BeginTime;

	int64 EndTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Open;

};
static void _ConvertPbToFCSDTBuyPassportActivity(FCSDTBuyPassportActivity &msg, const msg::CSDTBuyPassportActivity *pb) {
	msg.GroupId=pb->groupid();
	msg.Type=(EACTIVITYTYPE)pb->type();
	msg.BeginTime=pb->begintime();
	msg.EndTime=pb->endtime();
	msg.Open=pb->open();
}


USTRUCT(BlueprintType)
struct  FCSDTPassport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Star;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPASSPORTTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> LevelAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> LevelChargeAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPassportTask> WeeklyFreeTasks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPassportTask> WeeklyChargeTasks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPassportTask> SeasonTasks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekIndex;	//当前赛季第几周

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Period;	//周期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTExchangePassportGoodsData> BuyData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPassportTask> DailyRefreshTasks;	//每日刷新任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPassportTask> WeeklyRefreshTasks;	//每周刷新任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekBattleStar;	//每周战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTBuyPassportActivity> BuyPassportActivity;	//通行证直购活动

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Coefficient;	//积分加成

	int64 BeginTime;	//当前赛季通行证开始时间

	int64 EndTime;	//当前赛季通行证结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TypeIds;	//通行证类型IDList

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LastBuyConsumes;	//上次购买通行证花费

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRecommend;	//是否被投放(显示更优推荐方案)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPassportTask> DayFreeTasks;	// 日免费任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPassportTask> DayChargeTasks;	// 日付费任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekTaskBattleStar;	//周任务战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayTaskBattleStar;	//周任务战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> PassportCardNum;	//通行证卡号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FCSDTPassportCard> AdvancePassport;	//预购通行证 客户端自己 计算还剩多少次数

};
static void _ConvertPbToFCSDTPassport(FCSDTPassport &msg, const msg::CSDTPassport *pb) {
	msg.Level=pb->level();
	msg.Star=pb->star();
	msg.Type=(EPASSPORTTYPE)pb->type();
	for (int i = 0; i < pb->levelawards().size(); i++) {
		auto &a = pb->levelawards().Get(i);
		int tmp;
		tmp=a;
		msg.LevelAwards.Add(tmp);
	}
	for (int i = 0; i < pb->levelchargeawards().size(); i++) {
		auto &a = pb->levelchargeawards().Get(i);
		int tmp;
		tmp=a;
		msg.LevelChargeAwards.Add(tmp);
	}
	for (int i = 0; i < pb->weeklyfreetasks().size(); i++) {
		auto &a = pb->weeklyfreetasks().Get(i);
		FCSDTPassportTask tmp;
		_ConvertPbToFCSDTPassportTask(tmp, &a);
		msg.WeeklyFreeTasks.Add(tmp);
	}
	for (int i = 0; i < pb->weeklychargetasks().size(); i++) {
		auto &a = pb->weeklychargetasks().Get(i);
		FCSDTPassportTask tmp;
		_ConvertPbToFCSDTPassportTask(tmp, &a);
		msg.WeeklyChargeTasks.Add(tmp);
	}
	for (int i = 0; i < pb->seasontasks().size(); i++) {
		auto &a = pb->seasontasks().Get(i);
		FCSDTPassportTask tmp;
		_ConvertPbToFCSDTPassportTask(tmp, &a);
		msg.SeasonTasks.Add(tmp);
	}
	msg.WeekIndex=pb->weekindex();
	msg.Period=pb->period();
	for (int i = 0; i < pb->buydata().size(); i++) {
		auto &a = pb->buydata().Get(i);
		FCSDTExchangePassportGoodsData tmp;
		_ConvertPbToFCSDTExchangePassportGoodsData(tmp, &a);
		msg.BuyData.Add(tmp);
	}
	for (int i = 0; i < pb->dailyrefreshtasks().size(); i++) {
		auto &a = pb->dailyrefreshtasks().Get(i);
		FCSDTPassportTask tmp;
		_ConvertPbToFCSDTPassportTask(tmp, &a);
		msg.DailyRefreshTasks.Add(tmp);
	}
	for (int i = 0; i < pb->weeklyrefreshtasks().size(); i++) {
		auto &a = pb->weeklyrefreshtasks().Get(i);
		FCSDTPassportTask tmp;
		_ConvertPbToFCSDTPassportTask(tmp, &a);
		msg.WeeklyRefreshTasks.Add(tmp);
	}
	msg.WeekBattleStar=pb->weekbattlestar();
	for (int i = 0; i < pb->buypassportactivity().size(); i++) {
		auto &a = pb->buypassportactivity().Get(i);
		FCSDTBuyPassportActivity tmp;
		_ConvertPbToFCSDTBuyPassportActivity(tmp, &a);
		msg.BuyPassportActivity.Add(tmp);
	}
	msg.Coefficient=pb->coefficient();
	msg.BeginTime=pb->begintime();
	msg.EndTime=pb->endtime();
	for (int i = 0; i < pb->typeids().size(); i++) {
		auto &a = pb->typeids().Get(i);
		int tmp;
		tmp=a;
		msg.TypeIds.Add(tmp);
	}
	msg.LastBuyConsumes=pb->lastbuyconsumes();
	msg.IsRecommend=pb->isrecommend();
	for (int i = 0; i < pb->dayfreetasks().size(); i++) {
		auto &a = pb->dayfreetasks().Get(i);
		FCSDTPassportTask tmp;
		_ConvertPbToFCSDTPassportTask(tmp, &a);
		msg.DayFreeTasks.Add(tmp);
	}
	for (int i = 0; i < pb->daychargetasks().size(); i++) {
		auto &a = pb->daychargetasks().Get(i);
		FCSDTPassportTask tmp;
		_ConvertPbToFCSDTPassportTask(tmp, &a);
		msg.DayChargeTasks.Add(tmp);
	}
	msg.WeekTaskBattleStar=pb->weektaskbattlestar();
	msg.DayTaskBattleStar=pb->daytaskbattlestar();

    for (auto it = pb->passportcardnum().begin(); it != pb->passportcardnum().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.PassportCardNum.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->advancepassport().begin(); it != pb->advancepassport().end(); it++) {
        FCSDTPassportCard tmp_value;
        _ConvertPbToFCSDTPassportCard(tmp_value, &it->second);
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.AdvancePassport.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSDTEvalAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFCSDTEvalAward(FCSDTEvalAward &msg, const msg::CSDTEvalAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSDTTeachPass {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Win;	//是否通关

};
static void _ConvertPbToFCSDTTeachPass(FCSDTTeachPass &msg, const msg::CSDTTeachPass *pb) {
	msg.Win=pb->win();
}


USTRUCT(BlueprintType)
struct  FActivityDataWrap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FActivityData Data;	//活动项数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Progress;	//进度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Md5Sum;	//md5码

};
static void _ConvertPbToFActivityDataWrap(FActivityDataWrap &msg, const msg::ActivityDataWrap *pb) {
	_ConvertPbToFActivityData(msg.Data, &pb->data());
	msg.Progress=pb->progress();
	msg.Md5Sum=UTF8_TO_TCHAR(pb->md5sum().c_str());
}


USTRUCT(BlueprintType)
struct  FVisitMapPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerID;

	int64 VisitTime;

};
static void _ConvertPbToFVisitMapPlayer(FVisitMapPlayer &msg, const msg::VisitMapPlayer *pb) {
	msg.PlayerID=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.VisitTime=pb->visittime();
}


USTRUCT(BlueprintType)
struct  FOutPutRecord {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> ItemMap;	//周期内产出的<道具id:数量>

	int64 ResetTime;	// 重置时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int failOutPutCount;	//连续失败次数

};
static void _ConvertPbToFOutPutRecord(FOutPutRecord &msg, const msg::OutPutRecord *pb) {

    for (auto it = pb->itemmap().begin(); it != pb->itemmap().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.ItemMap.Add(tmp_key, tmp_value);
    }
	msg.ResetTime=pb->resettime();
	msg.failOutPutCount=pb->failoutputcount();
}


USTRUCT(BlueprintType)
struct  FRandDiscount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	// 奖励ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Times;	// 可用次数

	int64 AvailableTime;	// 有效时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rate;	// 折扣率

};
static void _ConvertPbToFRandDiscount(FRandDiscount &msg, const msg::RandDiscount *pb) {
	msg.ID=pb->id();
	msg.Times=pb->times();
	msg.AvailableTime=pb->availabletime();
	msg.Rate=pb->rate();
}


USTRUCT(BlueprintType)
struct  FCSDTBigWinnerData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDailyAward;	//是否领取低保

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeasonId;	//赛季ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeasonScore;	//赛季积分

};
static void _ConvertPbToFCSDTBigWinnerData(FCSDTBigWinnerData &msg, const msg::CSDTBigWinnerData *pb) {
	msg.IsDailyAward=pb->isdailyaward();
	msg.SeasonId=pb->seasonid();
	msg.SeasonScore=pb->seasonscore();
}


USTRUCT(BlueprintType)
struct  FPVEEvalData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score;	//本次积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddScore;	//增加积分

};
static void _ConvertPbToFPVEEvalData(FPVEEvalData &msg, const msg::PVEEvalData *pb) {
	msg.Score=pb->score();
	msg.AddScore=pb->addscore();
}


USTRUCT(BlueprintType)
struct  FCSDTPveRecord {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, bool> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Round;

};
static void _ConvertPbToFCSDTPveRecord(FCSDTPveRecord &msg, const msg::CSDTPveRecord *pb) {

    for (auto it = pb->awards().begin(); it != pb->awards().end(); it++) {
        bool tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Awards.Add(tmp_key, tmp_value);
    }
	msg.Round=pb->round();
}


USTRUCT(BlueprintType)
struct  FChessIdList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ids;

};
static void _ConvertPbToFChessIdList(FChessIdList &msg, const msg::ChessIdList *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		int tmp;
		tmp=a;
		msg.ids.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SenderId;	//发送者ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EmotionId;	//表情ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//发送内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NeedLocalize;	//是否需要本地化

	int64 Timestamp;	// 时间戳

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RecverId;	// 消息接收者id, 主要客户端用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	// ps4 Only 额外信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelUsrId;	// ps4 Only 额外信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PS4Only;	// ps4 Only 开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	// 聊天来源类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItemMedal MedalInfo;	// 皇后勋章信息

};
static void _ConvertPbToFCSNtfChat(FCSNtfChat &msg, const msg::CSNtfChat *pb) {
	msg.SenderId=UTF8_TO_TCHAR(pb->senderid().c_str());
	msg.EmotionId=pb->emotionid();
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.NeedLocalize=pb->needlocalize();
	msg.Timestamp=pb->timestamp();
	msg.RecverId=UTF8_TO_TCHAR(pb->recverid().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.ChannelUsrId=UTF8_TO_TCHAR(pb->channelusrid().c_str());
	msg.PS4Only=pb->ps4only();
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
	_ConvertPbToFCSDTItemMedal(msg.MedalInfo, &pb->medalinfo());
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamMsg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Msg;	//消息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Emotion;

	int64 Timestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	// ps4 Only 发消息的玩家的渠道类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelUsrId;	// ps4 Only 发消息的玩家的渠道ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PS4Only;	// ps4 Only 开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	// 聊天来源类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItemMedal MedalInfo;	//皇后勋章信息

};
static void _ConvertPbToFCSNtfTeamMsg(FCSNtfTeamMsg &msg, const msg::CSNtfTeamMsg *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Msg=UTF8_TO_TCHAR(pb->msg().c_str());
	msg.Emotion=pb->emotion();
	msg.Timestamp=pb->timestamp();
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.ChannelUsrId=UTF8_TO_TCHAR(pb->channelusrid().c_str());
	msg.PS4Only=pb->ps4only();
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
	_ConvertPbToFCSDTItemMedal(msg.MedalInfo, &pb->medalinfo());
}


USTRUCT(BlueprintType)
struct  FCSNtfWorldInvite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTWorldChat WorldInvite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EINVITETYPE Type;	//邀约类型

};
static void _ConvertPbToFCSNtfWorldInvite(FCSNtfWorldInvite &msg, const msg::CSNtfWorldInvite *pb) {
	_ConvertPbToFCSDTWorldChat(msg.WorldInvite, &pb->worldinvite());
	msg.Type=(EINVITETYPE)pb->type();
}


USTRUCT(BlueprintType)
struct  FHotDotInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> info;

};
static void _ConvertPbToFHotDotInfo(FHotDotInfo &msg, const msg::HotDotInfo *pb) {

    for (auto it = pb->info().begin(); it != pb->info().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.info.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FTxPlayerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//昵称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadPic;	//头像

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadPicFrame;	//头像框

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMR;	//杯段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diamond;	//甜甜圈数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Money;	//糖果数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassportLevel;	//通行证等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTxPlayer;	//是否是腾讯玩家

};
static void _ConvertPbToFTxPlayerInfo(FTxPlayerInfo &msg, const msg::TxPlayerInfo *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.HeadPic=pb->headpic();
	msg.HeadPicFrame=pb->headpicframe();
	msg.Level=pb->level();
	msg.MMR=pb->mmr();
	msg.Diamond=pb->diamond();
	msg.Money=pb->money();
	msg.PassportLevel=pb->passportlevel();
	msg.IsTxPlayer=pb->istxplayer();
}


USTRUCT(BlueprintType)
struct  FCSDTBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadPic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DamageEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChatBubble;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Exp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> CurShowItems;

	int64 Birthday;	//出生日期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLATFORMTYPE LastPlatFormType;	//玩家上次登录平台

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;

	int64 RefreshCountryTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NativeCountry;	// 祖籍国家

	int64 ResetHeadPicTime;	// idip重置头像时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChangeCountryNumber;	// 修改国家的次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Province;	// 省份

	int64 NextSetProvinceTime;	// 下次可以设置省份的时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChangeProvinceTimes;	// 修改省份次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItem Medal;	// 佩戴的勋章

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FCSDTCurShowItem> CurShowItem;	// 装扮{key,ITEM_TYPE}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChessPlayerUId;	// 棋手的ChessPlayer的instanceid

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPlayerMentorShipInfo MentorShipInfo;	// 师徒信息

	int64 TotalDuration;	// 新得总时长

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEXCHANGESTATE ExchangeState;	//拍卖行状态

};
static void _ConvertPbToFCSDTBase(FCSDTBase &msg, const msg::CSDTBase *pb) {
	msg.HeadPic=pb->headpic();
	msg.Scene=pb->scene();
	msg.ChessPlayer=pb->chessplayer();
	msg.DamageEffect=pb->damageeffect();
	msg.ChatBubble=pb->chatbubble();
	msg.Level=pb->level();
	msg.Exp=pb->exp();

    for (auto it = pb->curshowitems().begin(); it != pb->curshowitems().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.CurShowItems.Add(tmp_key, tmp_value);
    }
	msg.Birthday=pb->birthday();
	msg.LastPlatFormType=(EPLATFORMTYPE)pb->lastplatformtype();
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.RefreshCountryTime=pb->refreshcountrytime();
	msg.NativeCountry=UTF8_TO_TCHAR(pb->nativecountry().c_str());
	msg.ResetHeadPicTime=pb->resetheadpictime();
	msg.ChangeCountryNumber=pb->changecountrynumber();
	msg.Province=pb->province();
	msg.NextSetProvinceTime=pb->nextsetprovincetime();
	msg.ChangeProvinceTimes=pb->changeprovincetimes();
	_ConvertPbToFCSDTItem(msg.Medal, &pb->medal());

    for (auto it = pb->curshowitem().begin(); it != pb->curshowitem().end(); it++) {
        FCSDTCurShowItem tmp_value;
        _ConvertPbToFCSDTCurShowItem(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.CurShowItem.Add(tmp_key, tmp_value);
    }
	msg.ChessPlayerUId=UTF8_TO_TCHAR(pb->chessplayeruid().c_str());
	_ConvertPbToFPlayerMentorShipInfo(msg.MentorShipInfo, &pb->mentorshipinfo());
	msg.TotalDuration=pb->totalduration();
	msg.ExchangeState=(EEXCHANGESTATE)pb->exchangestate();
}


USTRUCT(BlueprintType)
struct  FCSDTPermission {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EHISTORYPVPSHOWPERMISSION ShowPvpHistory;	//查看历史战绩权限

};
static void _ConvertPbToFCSDTPermission(FCSDTPermission &msg, const msg::CSDTPermission *pb) {
	msg.ShowPvpHistory=(EHISTORYPVPSHOWPERMISSION)pb->showpvphistory();
}


USTRUCT(BlueprintType)
struct  FCSDTExtra {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SetNameCount;	//修改名字的次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Guids;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EvalWeekMoney;	//战斗获得的糖果奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EvalWeekMoneyLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DailyFirstWin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ChatShielding;	//私聊屏蔽标识

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekExp;

	TMap<int, int64> ExpBonus;	//经验加成

	TMap<int, int64> CandyBonus;	//糖果加成

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool FirstBuyEgg;	//是否是首次购买扭蛋

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EnableNewPlayerMode;

	TMap<uint64, FString> HistoryPvp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HistoryPvpShowLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LotteryCount;	//抽奖次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> EggCount;	//扭蛋抽取次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekBattleStar;	//每周战星上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> EggLowQualityCounts;	//玩家连续未抽中高质量物品次数{eggid:count}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CompleteInfoInput;

	int64 BindPhoneNumberTime;	//绑定时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BlackboxInviteCode;	//黑盒邀请码

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SharingCode;	//分享码

	int64 SharingBeginTime;	//分享活动开始时间

	int64 SharingEndTime;	//分享活动结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FString> ShareReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BindOldPlayerCount;	//绑定老账号次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MidasZoneId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOBSERVEPRIVILEGE ObservePrivilege;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool TencentTest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Questionnaires;	//玩家已经答过的问卷

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ENotices;	// 入口公告图片路径，默认取第一个元素ENotices[0]

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFRIENDINVISIBLE FriendInvisible;	//好友不可见

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BindTxPlayerId;	// 绑定腾讯角色ID(空则没有绑定过)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NtfBindTxPlayer;	// 提示绑定腾讯账号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewPlayerGuideFlag;	// 新手引导(PC用)

	int64 NewPlayerGuideTime;	// 新手引导时间(PC用)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PsOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PsServerOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> ABTestData;	// ABTestData数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCancel;	//是否取消注销

};
static void _ConvertPbToFCSDTExtra(FCSDTExtra &msg, const msg::CSDTExtra *pb) {
	msg.SetNameCount=pb->setnamecount();
	for (int i = 0; i < pb->guids().size(); i++) {
		auto &a = pb->guids().Get(i);
		int tmp;
		tmp=a;
		msg.Guids.Add(tmp);
	}
	msg.EvalWeekMoney=pb->evalweekmoney();
	msg.EvalWeekMoneyLimit=pb->evalweekmoneylimit();
	msg.DailyFirstWin=pb->dailyfirstwin();
	msg.ChatShielding=pb->chatshielding();
	msg.WeekExp=pb->weekexp();

    for (auto it = pb->expbonus().begin(); it != pb->expbonus().end(); it++) {
        int64 tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.ExpBonus.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->candybonus().begin(); it != pb->candybonus().end(); it++) {
        int64 tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.CandyBonus.Add(tmp_key, tmp_value);
    }
	msg.FirstBuyEgg=pb->firstbuyegg();
	msg.WeekIndex=pb->weekindex();
	msg.EnableNewPlayerMode=pb->enablenewplayermode();

    for (auto it = pb->historypvp().begin(); it != pb->historypvp().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        uint64 tmp_key;
        tmp_key=it->first;
        msg.HistoryPvp.Add(tmp_key, tmp_value);
    }
	msg.HistoryPvpShowLimit=pb->historypvpshowlimit();
	msg.LotteryCount=pb->lotterycount();

    for (auto it = pb->eggcount().begin(); it != pb->eggcount().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.EggCount.Add(tmp_key, tmp_value);
    }
	msg.WeekBattleStar=pb->weekbattlestar();

    for (auto it = pb->egglowqualitycounts().begin(); it != pb->egglowqualitycounts().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.EggLowQualityCounts.Add(tmp_key, tmp_value);
    }
	msg.CompleteInfoInput=pb->completeinfoinput();
	msg.BindPhoneNumberTime=pb->bindphonenumbertime();
	msg.BlackboxInviteCode=UTF8_TO_TCHAR(pb->blackboxinvitecode().c_str());
	msg.SharingCode=UTF8_TO_TCHAR(pb->sharingcode().c_str());
	msg.SharingBeginTime=pb->sharingbegintime();
	msg.SharingEndTime=pb->sharingendtime();

    for (auto it = pb->sharereward().begin(); it != pb->sharereward().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        int tmp_key;
        tmp_key=it->first;
        msg.ShareReward.Add(tmp_key, tmp_value);
    }
	msg.BindOldPlayerCount=pb->bindoldplayercount();
	msg.MidasZoneId=pb->midaszoneid();
	msg.ObservePrivilege=(EOBSERVEPRIVILEGE)pb->observeprivilege();
	msg.TencentTest=pb->tencenttest();
	for (int i = 0; i < pb->questionnaires().size(); i++) {
		auto &a = pb->questionnaires().Get(i);
		int tmp;
		tmp=a;
		msg.Questionnaires.Add(tmp);
	}
	for (int i = 0; i < pb->enotices().size(); i++) {
		auto &a = pb->enotices().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ENotices.Add(tmp);
	}
	msg.FriendInvisible=(EFRIENDINVISIBLE)pb->friendinvisible();
	msg.BindTxPlayerId=UTF8_TO_TCHAR(pb->bindtxplayerid().c_str());
	msg.NtfBindTxPlayer=pb->ntfbindtxplayer();
	msg.NewPlayerGuideFlag=pb->newplayerguideflag();
	msg.NewPlayerGuideTime=pb->newplayerguidetime();
	msg.PsOnly=pb->psonly();
	msg.PsServerOnly=pb->psserveronly();

    for (auto it = pb->abtestdata().begin(); it != pb->abtestdata().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.ABTestData.Add(tmp_key, tmp_value);
    }
	msg.IsCancel=pb->iscancel();
}


USTRUCT(BlueprintType)
struct  FCSDTTeachData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FCSDTTeachPass> Pass;	//关卡数据

};
static void _ConvertPbToFCSDTTeachData(FCSDTTeachData &msg, const msg::CSDTTeachData *pb) {

    for (auto it = pb->pass().begin(); it != pb->pass().end(); it++) {
        FCSDTTeachPass tmp_value;
        _ConvertPbToFCSDTTeachPass(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Pass.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSDTGetSelfNumRank {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERANKTYPE RankType;	//排行榜类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rank;	//玩家的排名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;	//国家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	//渠道类型

};
static void _ConvertPbToFCSDTGetSelfNumRank(FCSDTGetSelfNumRank &msg, const msg::CSDTGetSelfNumRank *pb) {
	msg.RankType=(ERANKTYPE)pb->ranktype();
	msg.Rank=pb->rank();
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
}


USTRUCT(BlueprintType)
struct  FChargeLevelSegment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinLevel;	//区间最小等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxLevel;	//区间最大等级

};
static void _ConvertPbToFChargeLevelSegment(FChargeLevelSegment &msg, const msg::ChargeLevelSegment *pb) {
	msg.MinLevel=pb->minlevel();
	msg.MaxLevel=pb->maxlevel();
}


USTRUCT(BlueprintType)
struct  FCSDTActGrpBuyAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardType;	// 领奖类型：0 - 充值奖励； others - 礼包奖励（青铜礼包、白银礼包、黄金礼包...活动配表id）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardId;	// AwardType = 0 对应充值id; others 累计档位 base-0

};
static void _ConvertPbToFCSDTActGrpBuyAward(FCSDTActGrpBuyAward &msg, const msg::CSDTActGrpBuyAward *pb) {
	msg.AwardType=pb->awardtype();
	msg.AwardId=pb->awardid();
}


USTRUCT(BlueprintType)
struct  FCSDTActPuzzle {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int mapId;	//高级道具翻牌id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GrpAwardId;	//组奖励id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPUZZLE_AWARD_TYPE AwardTyp;	//奖励类型:1、翻牌 2、组奖励 3、大奖

};
static void _ConvertPbToFCSDTActPuzzle(FCSDTActPuzzle &msg, const msg::CSDTActPuzzle *pb) {
	msg.mapId=pb->mapid();
	msg.GrpAwardId=pb->grpawardid();
	msg.AwardTyp=(EPUZZLE_AWARD_TYPE)pb->awardtyp();
}


USTRUCT(BlueprintType)
struct  FCSDTPuzzleRecord {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOUTPUT_ITEM_TYPE ItemTyp;	//使用道具的类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int mapId;	//翻牌id

};
static void _ConvertPbToFCSDTPuzzleRecord(FCSDTPuzzleRecord &msg, const msg::CSDTPuzzleRecord *pb) {
	msg.ItemTyp=(EOUTPUT_ITEM_TYPE)pb->itemtyp();
	msg.mapId=pb->mapid();
}


USTRUCT(BlueprintType)
struct  FCSDTSignRecord {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanGetSpecialAward;	//是否能领取大奖

};
static void _ConvertPbToFCSDTSignRecord(FCSDTSignRecord &msg, const msg::CSDTSignRecord *pb) {
	msg.CanGetSpecialAward=pb->cangetspecialaward();
}


USTRUCT(BlueprintType)
struct  FActivityIdList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Ids;	//活动id列表

};
static void _ConvertPbToFActivityIdList(FActivityIdList &msg, const msg::ActivityIdList *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		int tmp;
		tmp=a;
		msg.Ids.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActivityDataList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActivityDataWrap> Datas;	//活动列表数据

};
static void _ConvertPbToFActivityDataList(FActivityDataList &msg, const msg::ActivityDataList *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FActivityDataWrap tmp;
		_ConvertPbToFActivityDataWrap(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActivityGroupDataWrap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FActivityGroupData Data;	//组数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Md5Sum;	//md5码

};
static void _ConvertPbToFActivityGroupDataWrap(FActivityGroupDataWrap &msg, const msg::ActivityGroupDataWrap *pb) {
	_ConvertPbToFActivityGroupData(msg.Data, &pb->data());
	msg.Md5Sum=UTF8_TO_TCHAR(pb->md5sum().c_str());
}


USTRUCT(BlueprintType)
struct  FVisitMapPlayers {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVisitMapPlayer> Players;

};
static void _ConvertPbToFVisitMapPlayers(FVisitMapPlayers &msg, const msg::VisitMapPlayers *pb) {
	for (int i = 0; i < pb->players().size(); i++) {
		auto &a = pb->players().Get(i);
		FVisitMapPlayer tmp;
		_ConvertPbToFVisitMapPlayer(tmp, &a);
		msg.Players.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSDTReportRegionInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> Groups;	//ping值延迟信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> TCPGroups;	//tcp延迟信息

};
static void _ConvertPbToFCSDTReportRegionInfo(FCSDTReportRegionInfo &msg, const msg::CSDTReportRegionInfo *pb) {

    for (auto it = pb->groups().begin(); it != pb->groups().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Groups.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->tcpgroups().begin(); it != pb->tcpgroups().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.TCPGroups.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FBigWinnerScoreHistory {
	GENERATED_BODY()

	int64 AddTime;	// 时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESOURCE Source;	// 来源

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubSource;	// 子来源

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	// 数量

};
static void _ConvertPbToFBigWinnerScoreHistory(FBigWinnerScoreHistory &msg, const msg::BigWinnerScoreHistory *pb) {
	msg.AddTime=pb->addtime();
	msg.Source=(ESOURCE)pb->source();
	msg.SubSource=pb->subsource();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FMedalInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;	//物品唯一ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItemMedal Medal;	//勋章信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalId;	//物品ID

};
static void _ConvertPbToFMedalInfo(FMedalInfo &msg, const msg::MedalInfo *pb) {
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
	_ConvertPbToFCSDTItemMedal(msg.Medal, &pb->medal());
	msg.MedalId=pb->medalid();
}


USTRUCT(BlueprintType)
struct  FCostEnterPvP {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TicketId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CostTicketNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrencyId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CostBountyNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LockCurrencyNum;

};
static void _ConvertPbToFCostEnterPvP(FCostEnterPvP &msg, const msg::CostEnterPvP *pb) {
	msg.TicketId=pb->ticketid();
	msg.CostTicketNum=pb->costticketnum();
	msg.CurrencyId=pb->currencyid();
	msg.CostBountyNum=pb->costbountynum();
	msg.LockCurrencyNum=pb->lockcurrencynum();
}


USTRUCT(BlueprintType)
struct  FTDEvalData {
	GENERATED_BODY()

	int64 OnHookTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LastStageId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTDItem> Awards;

};
static void _ConvertPbToFTDEvalData(FTDEvalData &msg, const msg::TDEvalData *pb) {
	msg.OnHookTime=pb->onhooktime();
	msg.LastStageId=pb->laststageid();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FTDItem tmp;
		_ConvertPbToFTDItem(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTaskProgress {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//任务Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrTaskProgress;	//当前任务进度次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//完成任务自动领取的奖励

};
static void _ConvertPbToFTaskProgress(FTaskProgress &msg, const msg::TaskProgress *pb) {
	msg.Id=pb->id();
	msg.CurrTaskProgress=pb->currtaskprogress();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAdCount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ViewCount;	// 已观看次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardCount;	// 领奖次数

	int64 ViewTs;	// 上次观看时间

	int64 ResetTs;	// 上次重置时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalViewCout;	// 累计观看次数

};
static void _ConvertPbToFAdCount(FAdCount &msg, const msg::AdCount *pb) {
	msg.Id=pb->id();
	msg.ViewCount=pb->viewcount();
	msg.AwardCount=pb->awardcount();
	msg.ViewTs=pb->viewts();
	msg.ResetTs=pb->resetts();
	msg.TotalViewCout=pb->totalviewcout();
}


USTRUCT(BlueprintType)
struct  FADStat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalViewCout;	// 累计观看次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CumulateCount;	// 已领取观看次数

};
static void _ConvertPbToFADStat(FADStat &msg, const msg::ADStat *pb) {
	msg.TotalViewCout=pb->totalviewcout();
	msg.CumulateCount=pb->cumulatecount();
}


USTRUCT(BlueprintType)
struct  FLimitRefresh {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GrpId;	//活动组id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//活动id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOutPutRecord Record;	//刷新结果

};
static void _ConvertPbToFLimitRefresh(FLimitRefresh &msg, const msg::LimitRefresh *pb) {
	msg.GrpId=pb->grpid();
	msg.Id=pb->id();
	_ConvertPbToFOutPutRecord(msg.Record, &pb->record());
}


USTRUCT(BlueprintType)
struct  FUnlockChessTemplate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//解锁得id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Unlock;	//true 装配 false 卸下

};
static void _ConvertPbToFUnlockChessTemplate(FUnlockChessTemplate &msg, const msg::UnlockChessTemplate *pb) {
	msg.Id=pb->id();
	msg.Unlock=pb->unlock();
}


USTRUCT(BlueprintType)
struct  FMallIDs {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> IDs;

};
static void _ConvertPbToFMallIDs(FMallIDs &msg, const msg::MallIDs *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		int tmp;
		tmp=a;
		msg.IDs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqVerifyRealName {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RealName;	// 真实姓名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString IDNumber;	// 身份证号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ClientID;

};
static void _ConvertPbToFCSReqVerifyRealName(FCSReqVerifyRealName &msg, const msg::CSReqVerifyRealName *pb) {
	msg.RealName=UTF8_TO_TCHAR(pb->realname().c_str());
	msg.IDNumber=UTF8_TO_TCHAR(pb->idnumber().c_str());
	msg.ClientID=UTF8_TO_TCHAR(pb->clientid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspVerifyRealName {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAdult;

};
static void _ConvertPbToFCSRspVerifyRealName(FCSRspVerifyRealName &msg, const msg::CSRspVerifyRealName *pb) {
	msg.Success=pb->success();
	msg.IsAdult=pb->isadult();
}


USTRUCT(BlueprintType)
struct  FCSReqFakePay {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemID;

};
static void _ConvertPbToFCSReqFakePay(FCSReqFakePay &msg, const msg::CSReqFakePay *pb) {
	msg.ItemID=pb->itemid();
}


USTRUCT(BlueprintType)
struct  FCSRspFakePay {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspFakePay(FCSRspFakePay &msg, const msg::CSRspFakePay *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfVerifyRealName {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfVerifyRealName(FCSNtfVerifyRealName &msg, const msg::CSNtfVerifyRealName *pb) {
}


USTRUCT(BlueprintType)
struct  FCSBodySeq {
	GENERATED_BODY()

	uint64 Seq;

};
static void _ConvertPbToFCSBodySeq(FCSBodySeq &msg, const msg::CSBodySeq *pb) {
	msg.Seq=pb->seq();
}


USTRUCT(BlueprintType)
struct  FCSRspLogin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//用户id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UsrName;	//用户名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SessionId;	//用于客户端游戏中重连服务器

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBase Base;	//玩家基础信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTStat Stat;	//统计信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTItem> Items;	//玩家拥有道具

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTNoticeInfo Notice;	//公告内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> MapLoginDatas;	//登录成功后获取的渠道相关数据

	int64 ServerTime;	//服务器时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ServiceAppId;	//客服 Appid

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ServiceKey;	//客服 Key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LocalDistanceToUTC;	//当地时间与UTC时间相差秒数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTExtra Extra;	//额外信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTMarquee Marquee;	//跑马灯

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTChessPlayer> ChessPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EvalWeekMoneyLimit;	//每周战斗获得糖果阈值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> Chess;	//棋子被合成过的最大星级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RefreshTimeDaily;	//每日刷新时间点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RefreshTimeWeekly;	//每周几刷新

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WorldChatLimit;	//聊天段位限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTCommonRandList> CommonRandList;	//通用物品随机队列

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTAdsInfo Ads;	//广告内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPassport Passport;	//通行证信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DiamondCoefficient;	//付费糖果转化系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> FirstCharge;	//首充信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DiamondCovertMoney;	//是否需要将甜甜圈转化为糖果

	int64 AlphaActivityBeginTime;

	int64 AlphaActivityEndTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTSeason Season;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTActivity Activity;	//活动数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTMelee Melee;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPermission Permission;

	int64 CommentBeginTime;

	int64 CommentEndTime;

	TArray<ESWITCHTYPE> SwitchSystemSet;	//开关控制标记设置_系统

	TArray<ESWITCHTYPE> SwitchPlayerSet;	//开关控制标记设置_个人

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChannelFunctionData ChannelFunction;	//渠道功能开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMallTabData> MallTabs;	//商城栏位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELAUNCHTYPE LaunchType;	//启动类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANNELVIPTYPE ChannelVipType;	//渠道vip类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BattleIncompatibleSwitch;	//战斗不互通开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> PayRecord;	//玩家充值记录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTSignData SignData;	//每日签到活动数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> Settings;	//设置相关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> SysMsgs;	//gm系统消息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMark;	//语音开关配置标记

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWxVVipData WxVVVip;	//微信大玩家

	uint64 ObservePvpId;	//观战ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UniqueId;	//添加唯一ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IdipAreaID;	//idip区域id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> FastChatList;	//快捷聊天预设文本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPunishment> Punishment;	//玩家当前受到的惩罚

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTAddictionInfo Addiction;	//沉迷信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMultiPlayer> MultiPlayers;	//玩家待选择的角色

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBannerInfo Banners;	//banner内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTaskItem> ObserveTasks;	//观战任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PandoraUrl;	//幸运星url

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OpenBindOssPlayer;	//绑定tx玩家开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> FavouriteWSMaps;	//收藏的创意工坊地图（数组元素为地图id）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ShortcutWSMaps;	//创意工坊地图的快捷入口（数组元素为地图id）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FScoredMap> ScoredWSMaps;	//已评分的地图

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTRecruitData RecruitData;	//招募数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> RecommendCollect;	//个人收藏阵容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RecommendSet;	//个人设置的推荐阵容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTTasks Tasks;	//成就奖杯任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CliReportPublishKey;	//客户端举报接口公钥

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPlayerGuildInfo GuildInfo;	//公会

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool GetVngCommentAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> ExtraPara;	//透传的各种参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTTeachData Teach;	//教学关卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ServerEnv;	//服务器环境

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBigWinnerData BigWinner;	//大赢家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelUsrId;	//玩家的CID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRandDiscount AdDiscount;	//广告折扣

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLAYER_BIND_STATUS PsBindStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPlayerPvpData PlayerPvpData;	//玩家pvp数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGmBan> GmBans;	//gm封禁信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EnableBalance;	// 是否能使用零钱包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPassportHistory> PassportHistory;	//通行证历史数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassportRefreshTimeWeekly;	//通行证周刷新时间

};
static void _ConvertPbToFCSRspLogin(FCSRspLogin &msg, const msg::CSRspLogin *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.UsrName=UTF8_TO_TCHAR(pb->usrname().c_str());
	msg.SessionId=UTF8_TO_TCHAR(pb->sessionid().c_str());
	_ConvertPbToFCSDTBase(msg.Base, &pb->base());
	_ConvertPbToFCSDTStat(msg.Stat, &pb->stat());
	for (int i = 0; i < pb->items().size(); i++) {
		auto &a = pb->items().Get(i);
		FCSDTItem tmp;
		_ConvertPbToFCSDTItem(tmp, &a);
		msg.Items.Add(tmp);
	}
	_ConvertPbToFCSDTNoticeInfo(msg.Notice, &pb->notice());

    for (auto it = pb->maplogindatas().begin(); it != pb->maplogindatas().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.MapLoginDatas.Add(tmp_key, tmp_value);
    }
	msg.ServerTime=pb->servertime();
	msg.ServiceAppId=UTF8_TO_TCHAR(pb->serviceappid().c_str());
	msg.ServiceKey=UTF8_TO_TCHAR(pb->servicekey().c_str());
	msg.LocalDistanceToUTC=pb->localdistancetoutc();
	_ConvertPbToFCSDTExtra(msg.Extra, &pb->extra());
	_ConvertPbToFCSDTMarquee(msg.Marquee, &pb->marquee());
	for (int i = 0; i < pb->chessplayers().size(); i++) {
		auto &a = pb->chessplayers().Get(i);
		FCSDTChessPlayer tmp;
		_ConvertPbToFCSDTChessPlayer(tmp, &a);
		msg.ChessPlayers.Add(tmp);
	}
	msg.EvalWeekMoneyLimit=pb->evalweekmoneylimit();

    for (auto it = pb->chess().begin(); it != pb->chess().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.Chess.Add(tmp_key, tmp_value);
    }
	msg.RefreshTimeDaily=UTF8_TO_TCHAR(pb->refreshtimedaily().c_str());
	msg.RefreshTimeWeekly=pb->refreshtimeweekly();
	msg.WorldChatLimit=pb->worldchatlimit();
	for (int i = 0; i < pb->commonrandlist().size(); i++) {
		auto &a = pb->commonrandlist().Get(i);
		FCSDTCommonRandList tmp;
		_ConvertPbToFCSDTCommonRandList(tmp, &a);
		msg.CommonRandList.Add(tmp);
	}
	_ConvertPbToFCSDTAdsInfo(msg.Ads, &pb->ads());
	_ConvertPbToFCSDTPassport(msg.Passport, &pb->passport());
	msg.DiamondCoefficient=pb->diamondcoefficient();

    for (auto it = pb->firstcharge().begin(); it != pb->firstcharge().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.FirstCharge.Add(tmp_key, tmp_value);
    }
	msg.DiamondCovertMoney=pb->diamondcovertmoney();
	msg.AlphaActivityBeginTime=pb->alphaactivitybegintime();
	msg.AlphaActivityEndTime=pb->alphaactivityendtime();
	_ConvertPbToFCSDTSeason(msg.Season, &pb->season());
	_ConvertPbToFCSDTActivity(msg.Activity, &pb->activity());
	_ConvertPbToFCSDTMelee(msg.Melee, &pb->melee());
	_ConvertPbToFCSDTPermission(msg.Permission, &pb->permission());
	msg.CommentBeginTime=pb->commentbegintime();
	msg.CommentEndTime=pb->commentendtime();
	for (int i = 0; i < pb->switchsystemset().size(); i++) {
		auto &a = pb->switchsystemset().Get(i);
		ESWITCHTYPE tmp;
		tmp=(ESWITCHTYPE)a;
		msg.SwitchSystemSet.Add(tmp);
	}
	for (int i = 0; i < pb->switchplayerset().size(); i++) {
		auto &a = pb->switchplayerset().Get(i);
		ESWITCHTYPE tmp;
		tmp=(ESWITCHTYPE)a;
		msg.SwitchPlayerSet.Add(tmp);
	}
	_ConvertPbToFChannelFunctionData(msg.ChannelFunction, &pb->channelfunction());
	for (int i = 0; i < pb->malltabs().size(); i++) {
		auto &a = pb->malltabs().Get(i);
		FMallTabData tmp;
		_ConvertPbToFMallTabData(tmp, &a);
		msg.MallTabs.Add(tmp);
	}
	msg.LaunchType=(ELAUNCHTYPE)pb->launchtype();
	msg.ChannelVipType=(ECHANNELVIPTYPE)pb->channelviptype();
	msg.BattleIncompatibleSwitch=pb->battleincompatibleswitch();

    for (auto it = pb->payrecord().begin(); it != pb->payrecord().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.PayRecord.Add(tmp_key, tmp_value);
    }
	_ConvertPbToFCSDTSignData(msg.SignData, &pb->signdata());

    for (auto it = pb->settings().begin(); it != pb->settings().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.Settings.Add(tmp_key, tmp_value);
    }
	for (int i = 0; i < pb->sysmsgs().size(); i++) {
		auto &a = pb->sysmsgs().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.SysMsgs.Add(tmp);
	}
	msg.VoiceMark=pb->voicemark();
	_ConvertPbToFWxVVipData(msg.WxVVVip, &pb->wxvvvip());
	msg.ObservePvpId=pb->observepvpid();
	msg.UniqueId=UTF8_TO_TCHAR(pb->uniqueid().c_str());
	msg.IdipAreaID=pb->idipareaid();
	for (int i = 0; i < pb->fastchatlist().size(); i++) {
		auto &a = pb->fastchatlist().Get(i);
		int tmp;
		tmp=a;
		msg.FastChatList.Add(tmp);
	}
	for (int i = 0; i < pb->punishment().size(); i++) {
		auto &a = pb->punishment().Get(i);
		FCSDTPunishment tmp;
		_ConvertPbToFCSDTPunishment(tmp, &a);
		msg.Punishment.Add(tmp);
	}
	_ConvertPbToFCSDTAddictionInfo(msg.Addiction, &pb->addiction());
	for (int i = 0; i < pb->multiplayers().size(); i++) {
		auto &a = pb->multiplayers().Get(i);
		FMultiPlayer tmp;
		_ConvertPbToFMultiPlayer(tmp, &a);
		msg.MultiPlayers.Add(tmp);
	}
	_ConvertPbToFCSDTBannerInfo(msg.Banners, &pb->banners());
	for (int i = 0; i < pb->observetasks().size(); i++) {
		auto &a = pb->observetasks().Get(i);
		FCSDTTaskItem tmp;
		_ConvertPbToFCSDTTaskItem(tmp, &a);
		msg.ObserveTasks.Add(tmp);
	}
	msg.PandoraUrl=UTF8_TO_TCHAR(pb->pandoraurl().c_str());
	msg.OpenBindOssPlayer=pb->openbindossplayer();
	for (int i = 0; i < pb->favouritewsmaps().size(); i++) {
		auto &a = pb->favouritewsmaps().Get(i);
		int tmp;
		tmp=a;
		msg.FavouriteWSMaps.Add(tmp);
	}
	for (int i = 0; i < pb->shortcutwsmaps().size(); i++) {
		auto &a = pb->shortcutwsmaps().Get(i);
		int tmp;
		tmp=a;
		msg.ShortcutWSMaps.Add(tmp);
	}
	for (int i = 0; i < pb->scoredwsmaps().size(); i++) {
		auto &a = pb->scoredwsmaps().Get(i);
		FScoredMap tmp;
		_ConvertPbToFScoredMap(tmp, &a);
		msg.ScoredWSMaps.Add(tmp);
	}
	_ConvertPbToFCSDTRecruitData(msg.RecruitData, &pb->recruitdata());
	for (int i = 0; i < pb->recommendcollect().size(); i++) {
		auto &a = pb->recommendcollect().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.RecommendCollect.Add(tmp);
	}
	msg.RecommendSet=UTF8_TO_TCHAR(pb->recommendset().c_str());
	_ConvertPbToFCSDTTasks(msg.Tasks, &pb->tasks());
	msg.CliReportPublishKey=UTF8_TO_TCHAR(pb->clireportpublishkey().c_str());
	_ConvertPbToFPlayerGuildInfo(msg.GuildInfo, &pb->guildinfo());
	msg.GetVngCommentAward=pb->getvngcommentaward();

    for (auto it = pb->extrapara().begin(); it != pb->extrapara().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.ExtraPara.Add(tmp_key, tmp_value);
    }
	_ConvertPbToFCSDTTeachData(msg.Teach, &pb->teach());
	msg.ServerEnv=UTF8_TO_TCHAR(pb->serverenv().c_str());
	_ConvertPbToFCSDTBigWinnerData(msg.BigWinner, &pb->bigwinner());
	msg.ChannelUsrId=UTF8_TO_TCHAR(pb->channelusrid().c_str());
	_ConvertPbToFRandDiscount(msg.AdDiscount, &pb->addiscount());
	msg.PsBindStatus=(EPLAYER_BIND_STATUS)pb->psbindstatus();
	_ConvertPbToFCSDTPlayerPvpData(msg.PlayerPvpData, &pb->playerpvpdata());
	for (int i = 0; i < pb->gmbans().size(); i++) {
		auto &a = pb->gmbans().Get(i);
		FGmBan tmp;
		_ConvertPbToFGmBan(tmp, &a);
		msg.GmBans.Add(tmp);
	}
	msg.EnableBalance=pb->enablebalance();
	for (int i = 0; i < pb->passporthistory().size(); i++) {
		auto &a = pb->passporthistory().Get(i);
		FCSDTPassportHistory tmp;
		_ConvertPbToFCSDTPassportHistory(tmp, &a);
		msg.PassportHistory.Add(tmp);
	}
	msg.PassportRefreshTimeWeekly=pb->passportrefreshtimeweekly();
}


USTRUCT(BlueprintType)
struct  FCSReqGetTxPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TxPlayerId;	// 腾讯玩家Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BlackboxInviteCode;	// 小黑盒邀请码

};
static void _ConvertPbToFCSReqGetTxPlayer(FCSReqGetTxPlayer &msg, const msg::CSReqGetTxPlayer *pb) {
	msg.TxPlayerId=UTF8_TO_TCHAR(pb->txplayerid().c_str());
	msg.BlackboxInviteCode=UTF8_TO_TCHAR(pb->blackboxinvitecode().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspGetTxPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTxPlayerInfo> Players;	//玩家待选择的角色

};
static void _ConvertPbToFCSRspGetTxPlayer(FCSRspGetTxPlayer &msg, const msg::CSRspGetTxPlayer *pb) {
	for (int i = 0; i < pb->players().size(); i++) {
		auto &a = pb->players().Get(i);
		FTxPlayerInfo tmp;
		_ConvertPbToFTxPlayerInfo(tmp, &a);
		msg.Players.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqChooseTxPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTxPlayer;	// 是否选择腾讯玩家

};
static void _ConvertPbToFCSReqChooseTxPlayer(FCSReqChooseTxPlayer &msg, const msg::CSReqChooseTxPlayer *pb) {
	msg.IsTxPlayer=pb->istxplayer();
}


USTRUCT(BlueprintType)
struct  FCSReqApplyHallServer {
	GENERATED_BODY()

	int64 Ts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DeviceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelId;	//渠道Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ApkVersion;	//客户端当前版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLATFORMTYPE PlatformType;	//平台类型

};
static void _ConvertPbToFCSReqApplyHallServer(FCSReqApplyHallServer &msg, const msg::CSReqApplyHallServer *pb) {
	msg.Ts=pb->ts();
	msg.DeviceId=UTF8_TO_TCHAR(pb->deviceid().c_str());
	msg.ChannelId=UTF8_TO_TCHAR(pb->channelid().c_str());
	msg.ApkVersion=UTF8_TO_TCHAR(pb->apkversion().c_str());
	msg.PlatformType=(EPLATFORMTYPE)pb->platformtype();
}


USTRUCT(BlueprintType)
struct  FCSRspApplyHallServer {
	GENERATED_BODY()

	std::string Key;	//秘钥

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ServerId;	//服务器id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTNoticeInfo Notice;	//公告内容

};
static void _ConvertPbToFCSRspApplyHallServer(FCSRspApplyHallServer &msg, const msg::CSRspApplyHallServer *pb) {
	msg.Key=pb->key();
	msg.ServerId=pb->serverid();
	_ConvertPbToFCSDTNoticeInfo(msg.Notice, &pb->notice());
}


USTRUCT(BlueprintType)
struct  FCSReqHeart {
	GENERATED_BODY()

	uint64 time;	//时间

};
static void _ConvertPbToFCSReqHeart(FCSReqHeart &msg, const msg::CSReqHeart *pb) {
	msg.time=pb->time();
}


USTRUCT(BlueprintType)
struct  FCSRspHeart {
	GENERATED_BODY()

	uint64 time;	//时间

	uint64 NowServerTime;	//服务器当前时间

};
static void _ConvertPbToFCSRspHeart(FCSRspHeart &msg, const msg::CSRspHeart *pb) {
	msg.time=pb->time();
	msg.NowServerTime=pb->nowservertime();
}


USTRUCT(BlueprintType)
struct  FCSReqVersionCheck {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLATFORMTYPE PlatformType;	//平台类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ApkVersion;	//客户端当前版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelId;	//渠道Id

	int64 GamelibVersion;	//内核版本号

};
static void _ConvertPbToFCSReqVersionCheck(FCSReqVersionCheck &msg, const msg::CSReqVersionCheck *pb) {
	msg.PlatformType=(EPLATFORMTYPE)pb->platformtype();
	msg.ApkVersion=UTF8_TO_TCHAR(pb->apkversion().c_str());
	msg.ChannelId=UTF8_TO_TCHAR(pb->channelid().c_str());
	msg.GamelibVersion=pb->gamelibversion();
}


USTRUCT(BlueprintType)
struct  FCSRspVersionCheck {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EVERSIONUPGRADETYPE UpgradeType;	//升级方式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UpgradeAddress;	//升级地址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NewApkVersion;	//最新apk版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ApkCdnUrl;	//apk cdn资源路径

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UpgradeContent;	//更新内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VerifyGateAddr;	//跳转地址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> LanMd5List;	//多语言md5码

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ZoneCdn;	//cdn地址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ZoneSlaveCdn;	//备用cdn地址

	int64 ServerGamelibVersion;	//服务器内核版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlatUrl;	//开放平台地址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlatAppId;	//开放平台id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlatAppSecret;	//开放平台秘钥

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ConsumesUrlWeb;	//拍卖行

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ConsumesUrlApp;	//拍卖行

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AssetUrl;	//资源地址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AssetVersion;	//资源版本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpResourceVersion;	//资源版本号

};
static void _ConvertPbToFCSRspVersionCheck(FCSRspVersionCheck &msg, const msg::CSRspVersionCheck *pb) {
	msg.UpgradeType=(EVERSIONUPGRADETYPE)pb->upgradetype();
	msg.UpgradeAddress=UTF8_TO_TCHAR(pb->upgradeaddress().c_str());
	msg.NewApkVersion=UTF8_TO_TCHAR(pb->newapkversion().c_str());
	msg.ApkCdnUrl=UTF8_TO_TCHAR(pb->apkcdnurl().c_str());
	msg.UpgradeContent=UTF8_TO_TCHAR(pb->upgradecontent().c_str());
	msg.VerifyGateAddr=UTF8_TO_TCHAR(pb->verifygateaddr().c_str());

    for (auto it = pb->lanmd5list().begin(); it != pb->lanmd5list().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.LanMd5List.Add(tmp_key, tmp_value);
    }
	msg.ZoneCdn=UTF8_TO_TCHAR(pb->zonecdn().c_str());
	msg.ZoneSlaveCdn=UTF8_TO_TCHAR(pb->zoneslavecdn().c_str());
	msg.ServerGamelibVersion=pb->servergamelibversion();
	msg.PlatUrl=UTF8_TO_TCHAR(pb->platurl().c_str());
	msg.PlatAppId=UTF8_TO_TCHAR(pb->platappid().c_str());
	msg.PlatAppSecret=UTF8_TO_TCHAR(pb->platappsecret().c_str());
	msg.ConsumesUrlWeb=UTF8_TO_TCHAR(pb->consumesurlweb().c_str());
	msg.ConsumesUrlApp=UTF8_TO_TCHAR(pb->consumesurlapp().c_str());
	msg.AssetUrl=UTF8_TO_TCHAR(pb->asseturl().c_str());
	msg.AssetVersion=UTF8_TO_TCHAR(pb->assetversion().c_str());
	msg.PvpResourceVersion=UTF8_TO_TCHAR(pb->pvpresourceversion().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqFreeFlow {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AppId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AccessToken;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OpenId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLATFORMTYPE PlatformType;

};
static void _ConvertPbToFCSReqFreeFlow(FCSReqFreeFlow &msg, const msg::CSReqFreeFlow *pb) {
	msg.AppId=UTF8_TO_TCHAR(pb->appid().c_str());
	msg.AccessToken=UTF8_TO_TCHAR(pb->accesstoken().c_str());
	msg.OpenId=UTF8_TO_TCHAR(pb->openid().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.PlatformType=(EPLATFORMTYPE)pb->platformtype();
}


USTRUCT(BlueprintType)
struct  FCSRspFreeFlow {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspFreeFlow(FCSRspFreeFlow &msg, const msg::CSRspFreeFlow *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqTlogEvent {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETLOGTYPE TlogType;

	TArray<int64> TlogParamList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TlogStr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTRoundItem TlogRoundItem;

};
static void _ConvertPbToFCSReqTlogEvent(FCSReqTlogEvent &msg, const msg::CSReqTlogEvent *pb) {
	msg.TlogType=(ETLOGTYPE)pb->tlogtype();
	for (int i = 0; i < pb->tlogparamlist().size(); i++) {
		auto &a = pb->tlogparamlist().Get(i);
		int64 tmp;
		tmp=a;
		msg.TlogParamList.Add(tmp);
	}
	msg.TlogStr=UTF8_TO_TCHAR(pb->tlogstr().c_str());
	_ConvertPbToFCSDTRoundItem(msg.TlogRoundItem, &pb->tlogrounditem());
}


USTRUCT(BlueprintType)
struct  FCSRspTlogEvent {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspTlogEvent(FCSRspTlogEvent &msg, const msg::CSRspTlogEvent *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqResourceVersionCheck {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ApkVersion;	//客户端当前版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLATFORMTYPE PlatFormType;	//平台类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelId;	//渠道Id

};
static void _ConvertPbToFCSReqResourceVersionCheck(FCSReqResourceVersionCheck &msg, const msg::CSReqResourceVersionCheck *pb) {
	msg.ApkVersion=UTF8_TO_TCHAR(pb->apkversion().c_str());
	msg.PlatFormType=(EPLATFORMTYPE)pb->platformtype();
	msg.ChannelId=UTF8_TO_TCHAR(pb->channelid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspResourceVersionCheck {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ApkVersion;	//Apk版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ResourceVersion;	//资源版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Cdn;	//Cdn链接地址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SlaveCdn;	//备Cdn链接地址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UpgradeContent;	//更新内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AearIdWX;	//微信区服ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AearIdQQ;	//QQ区服ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> PvpAddresses;	//pvp分组代表测速地址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> Regions;	//区域测速点

};
static void _ConvertPbToFCSRspResourceVersionCheck(FCSRspResourceVersionCheck &msg, const msg::CSRspResourceVersionCheck *pb) {
	msg.ApkVersion=UTF8_TO_TCHAR(pb->apkversion().c_str());
	msg.ResourceVersion=UTF8_TO_TCHAR(pb->resourceversion().c_str());
	msg.Cdn=UTF8_TO_TCHAR(pb->cdn().c_str());
	msg.SlaveCdn=UTF8_TO_TCHAR(pb->slavecdn().c_str());
	msg.UpgradeContent=UTF8_TO_TCHAR(pb->upgradecontent().c_str());
	msg.AearIdWX=pb->aearidwx();
	msg.AearIdQQ=pb->aearidqq();
	for (int i = 0; i < pb->pvpaddresses().size(); i++) {
		auto &a = pb->pvpaddresses().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.PvpAddresses.Add(tmp);
	}

    for (auto it = pb->regions().begin(); it != pb->regions().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Regions.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqGetNumRank {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERANKTYPE Type;	//排行榜类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;	//国家 如果是腾讯渠道 省份ID

	uint64 TournamentId;	//赛事id

	uint64 ClassId;	//级别id

	uint64 RoundId;	//轮次id 在获取轮次排行或者组内排行才填充

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SelfRank;	//只拉取自己的名次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupIndex;	//组id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	//玩家渠道类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TargetPlayer;	//指定玩家排名--SelfRank为TRUE并且这个字段不为空 则拉取指定玩家

};
static void _ConvertPbToFCSReqGetNumRank(FCSReqGetNumRank &msg, const msg::CSReqGetNumRank *pb) {
	msg.Type=(ERANKTYPE)pb->type();
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.TournamentId=pb->tournamentid();
	msg.ClassId=pb->classid();
	msg.RoundId=pb->roundid();
	msg.SelfRank=pb->selfrank();
	msg.GroupIndex=pb->groupindex();
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.TargetPlayer=UTF8_TO_TCHAR(pb->targetplayer().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqGetSelfNumRankData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ERANKTYPE> Type;	//排行榜类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;	//国家 如果是腾讯渠道 省份ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	//玩家渠道类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TargetPlayer;	//指定玩家排名

};
static void _ConvertPbToFCSReqGetSelfNumRankData(FCSReqGetSelfNumRankData &msg, const msg::CSReqGetSelfNumRankData *pb) {
	for (int i = 0; i < pb->type().size(); i++) {
		auto &a = pb->type().Get(i);
		ERANKTYPE tmp;
		tmp=(ERANKTYPE)a;
		msg.Type.Add(tmp);
	}
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.TargetPlayer=UTF8_TO_TCHAR(pb->targetplayer().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspGetNumRank {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERANKTYPE Type;	//排行榜类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rank;	//玩家的排名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTNumRankItem> items;	//前几名的玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankThreshold;	//排名阀值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankTopCount;	//前几名的数目

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;	//国家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	//渠道类型

};
static void _ConvertPbToFCSRspGetNumRank(FCSRspGetNumRank &msg, const msg::CSRspGetNumRank *pb) {
	msg.Type=(ERANKTYPE)pb->type();
	msg.Rank=pb->rank();
	for (int i = 0; i < pb->items().size(); i++) {
		auto &a = pb->items().Get(i);
		FCSDTNumRankItem tmp;
		_ConvertPbToFCSDTNumRankItem(tmp, &a);
		msg.items.Add(tmp);
	}
	msg.RankThreshold=pb->rankthreshold();
	msg.RankTopCount=pb->ranktopcount();
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
}


USTRUCT(BlueprintType)
struct  FCSRspGetSelfNumRankData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTGetSelfNumRank> data;

};
static void _ConvertPbToFCSRspGetSelfNumRankData(FCSRspGetSelfNumRankData &msg, const msg::CSRspGetSelfNumRankData *pb) {
	for (int i = 0; i < pb->data().size(); i++) {
		auto &a = pb->data().Get(i);
		FCSDTGetSelfNumRank tmp;
		_ConvertPbToFCSDTGetSelfNumRank(tmp, &a);
		msg.data.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqWorldChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//聊天内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Emotion;	//表情

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWORDCHAT WorldChatType;	//普通世界聊天 0, 创意工坊 1

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	//聊天来源类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CheckWorlds;	//需要检测的内容， Content里面有json，不能确定内容具体是什么，所以屏蔽词用这里的检测

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelID;	//频道ID

};
static void _ConvertPbToFCSReqWorldChat(FCSReqWorldChat &msg, const msg::CSReqWorldChat *pb) {
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.Emotion=pb->emotion();
	msg.WorldChatType=(EWORDCHAT)pb->worldchattype();
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
	msg.CheckWorlds=UTF8_TO_TCHAR(pb->checkworlds().c_str());
	msg.ChannelID=UTF8_TO_TCHAR(pb->channelid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspWorldChat {
	GENERATED_BODY()

	int64 NextSendTime;

	int64 SilenceTime;	// 禁言时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Reason;	// 禁言原因

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	//聊天来源类型

};
static void _ConvertPbToFCSRspWorldChat(FCSRspWorldChat &msg, const msg::CSRspWorldChat *pb) {
	msg.NextSendTime=pb->nextsendtime();
	msg.SilenceTime=pb->silencetime();
	msg.Reason=UTF8_TO_TCHAR(pb->reason().c_str());
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
}


USTRUCT(BlueprintType)
struct  FCSReqExpose {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	// 被举报的玩家id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//被举报的内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PicUrl;	//被举报的玩家头像URL

};
static void _ConvertPbToFCSReqExpose(FCSReqExpose &msg, const msg::CSReqExpose *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.PicUrl=UTF8_TO_TCHAR(pb->picurl().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspExpose {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspExpose(FCSRspExpose &msg, const msg::CSRspExpose *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPlayersBaseInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	//id列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOpenId;	//false上面是角色id,true上面是openid(渠道类型和查询者相同)

};
static void _ConvertPbToFCSReqPlayersBaseInfo(FCSReqPlayersBaseInfo &msg, const msg::CSReqPlayersBaseInfo *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
	msg.IsOpenId=pb->isopenid();
}


USTRUCT(BlueprintType)
struct  FCSRspPlayersBaseInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPlayerBaseInfo> Info;	//基础信息列表

};
static void _ConvertPbToFCSRspPlayersBaseInfo(FCSRspPlayersBaseInfo &msg, const msg::CSRspPlayersBaseInfo *pb) {
	for (int i = 0; i < pb->info().size(); i++) {
		auto &a = pb->info().Get(i);
		FCSDTPlayerBaseInfo tmp;
		_ConvertPbToFCSDTPlayerBaseInfo(tmp, &a);
		msg.Info.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqPlayerDetailInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	//id或用户名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOpenId;	//false上面是角色id,true上面是openid(渠道类型和查询者相同)

};
static void _ConvertPbToFCSReqPlayerDetailInfo(FCSReqPlayerDetailInfo &msg, const msg::CSReqPlayerDetailInfo *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
	msg.IsOpenId=pb->isopenid();
}


USTRUCT(BlueprintType)
struct  FCSRspPlayerDetailInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPlayerDetailInfo> Infos;

};
static void _ConvertPbToFCSRspPlayerDetailInfo(FCSRspPlayerDetailInfo &msg, const msg::CSRspPlayerDetailInfo *pb) {
	for (int i = 0; i < pb->infos().size(); i++) {
		auto &a = pb->infos().Get(i);
		FCSDTPlayerDetailInfo tmp;
		_ConvertPbToFCSDTPlayerDetailInfo(tmp, &a);
		msg.Infos.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqPlayersTournamentInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	// id列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOpenId;	// false上面是角色id, true上面是openid(渠道类型和查询者相同)

};
static void _ConvertPbToFCSReqPlayersTournamentInfo(FCSReqPlayersTournamentInfo &msg, const msg::CSReqPlayersTournamentInfo *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
	msg.IsOpenId=pb->isopenid();
}


USTRUCT(BlueprintType)
struct  FCSRspPlayersTournamentInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPlayerTournamentInfo> Infos;	// 锦标赛相关的信息

};
static void _ConvertPbToFCSRspPlayersTournamentInfo(FCSRspPlayersTournamentInfo &msg, const msg::CSRspPlayersTournamentInfo *pb) {
	for (int i = 0; i < pb->infos().size(); i++) {
		auto &a = pb->infos().Get(i);
		FCSDTPlayerTournamentInfo tmp;
		_ConvertPbToFCSDTPlayerTournamentInfo(tmp, &a);
		msg.Infos.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqReadMail {
	GENERATED_BODY()

	uint64 Id;

};
static void _ConvertPbToFCSReqReadMail(FCSReqReadMail &msg, const msg::CSReqReadMail *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSRspReadMail {
	GENERATED_BODY()

	uint64 Id;

};
static void _ConvertPbToFCSRspReadMail(FCSRspReadMail &msg, const msg::CSRspReadMail *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSReqGetMailAward {
	GENERATED_BODY()

	uint64 Id;

};
static void _ConvertPbToFCSReqGetMailAward(FCSReqGetMailAward &msg, const msg::CSReqGetMailAward *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSRspGetMailAward {
	GENERATED_BODY()

	TArray<uint64> Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFCSRspGetMailAward(FCSRspGetMailAward &msg, const msg::CSRspGetMailAward *pb) {
	for (int i = 0; i < pb->id().size(); i++) {
		auto &a = pb->id().Get(i);
		uint64 tmp;
		tmp=a;
		msg.Id.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqDealWebMail {
	GENERATED_BODY()

	uint64 Id;	//邮件id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWEBRESULT Result;	//处理结果

};
static void _ConvertPbToFCSReqDealWebMail(FCSReqDealWebMail &msg, const msg::CSReqDealWebMail *pb) {
	msg.Id=pb->id();
	msg.Result=(EWEBRESULT)pb->result();
}


USTRUCT(BlueprintType)
struct  FCSRspDealWebMail {
	GENERATED_BODY()

	uint64 Id;

};
static void _ConvertPbToFCSRspDealWebMail(FCSRspDealWebMail &msg, const msg::CSRspDealWebMail *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSReqBuyEgg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//购买数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EggId;	//扭蛋ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	//价格档索引

};
static void _ConvertPbToFCSReqBuyEgg(FCSReqBuyEgg &msg, const msg::CSReqBuyEgg *pb) {
	msg.Count=pb->count();
	msg.EggId=pb->eggid();
	msg.Index=pb->index();
}


USTRUCT(BlueprintType)
struct  FCSRspBuyEgg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFCSRspBuyEgg(FCSRspBuyEgg &msg, const msg::CSRspBuyEgg *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqEggLottery {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//抽取数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EggId;	//扭蛋ID

};
static void _ConvertPbToFCSReqEggLottery(FCSReqEggLottery &msg, const msg::CSReqEggLottery *pb) {
	msg.Count=pb->count();
	msg.EggId=pb->eggid();
}


USTRUCT(BlueprintType)
struct  FCSRspEggLottery {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//抽到的奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LowQualityCount;	//连续未抽中高质量物品次数

};
static void _ConvertPbToFCSRspEggLottery(FCSRspEggLottery &msg, const msg::CSRspEggLottery *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.LowQualityCount=pb->lowqualitycount();
}


USTRUCT(BlueprintType)
struct  FCSReqTeamOP {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTeamOP OP;	//操作

};
static void _ConvertPbToFCSReqTeamOP(FCSReqTeamOP &msg, const msg::CSReqTeamOP *pb) {
	_ConvertPbToFTeamOP(msg.OP, &pb->op());
}


USTRUCT(BlueprintType)
struct  FCSReqOBTeamInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapID;	// 默认值0表示请求全部类型的房间（自定义房间+创意工坊房间）

};
static void _ConvertPbToFCSReqOBTeamInfo(FCSReqOBTeamInfo &msg, const msg::CSReqOBTeamInfo *pb) {
	msg.MapID=pb->mapid();
}


USTRUCT(BlueprintType)
struct  FCSRspOBTeamInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTeamBaseInfo> BaseInfo;

};
static void _ConvertPbToFCSRspOBTeamInfo(FCSRspOBTeamInfo &msg, const msg::CSRspOBTeamInfo *pb) {
	for (int i = 0; i < pb->baseinfo().size(); i++) {
		auto &a = pb->baseinfo().Get(i);
		FTeamBaseInfo tmp;
		_ConvertPbToFTeamBaseInfo(tmp, &a);
		msg.BaseInfo.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqReportHeadIconUrl {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString IconUrl;

};
static void _ConvertPbToFCSReqReportHeadIconUrl(FCSReqReportHeadIconUrl &msg, const msg::CSReqReportHeadIconUrl *pb) {
	msg.IconUrl=UTF8_TO_TCHAR(pb->iconurl().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqUserNameSet {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UserName;	//用户名

};
static void _ConvertPbToFCSReqUserNameSet(FCSReqUserNameSet &msg, const msg::CSReqUserNameSet *pb) {
	msg.UserName=UTF8_TO_TCHAR(pb->username().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUserNameSet {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//修改名字的次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗列表

};
static void _ConvertPbToFCSRspUserNameSet(FCSRspUserNameSet &msg, const msg::CSRspUserNameSet *pb) {
	msg.Count=pb->count();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqUserNameRandom {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UserName;	//用户名

};
static void _ConvertPbToFCSReqUserNameRandom(FCSReqUserNameRandom &msg, const msg::CSReqUserNameRandom *pb) {
	msg.UserName=UTF8_TO_TCHAR(pb->username().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUserNameRandom {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UserName;	//用户名

};
static void _ConvertPbToFCSRspUserNameRandom(FCSRspUserNameRandom &msg, const msg::CSRspUserNameRandom *pb) {
	msg.UserName=UTF8_TO_TCHAR(pb->username().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqHeadPicSet {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadPic;	//头像

};
static void _ConvertPbToFCSReqHeadPicSet(FCSReqHeadPicSet &msg, const msg::CSReqHeadPicSet *pb) {
	msg.HeadPic=pb->headpic();
}


USTRUCT(BlueprintType)
struct  FCSRspHeadPicSet {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspHeadPicSet(FCSRspHeadPicSet &msg, const msg::CSRspHeadPicSet *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPvp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//pvp模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ApkVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpResourceVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CustomSubMode;	//自定义子模式

	uint64 TournamentId;	//赛事下,赛事id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattlePassId;	//战役关卡ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BigWinnerId;	//大赢家场次id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubMode;	//子模式id,通用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActivityGroupId;	// 活动ID

};
static void _ConvertPbToFCSReqPvp(FCSReqPvp &msg, const msg::CSReqPvp *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.ApkVersion=UTF8_TO_TCHAR(pb->apkversion().c_str());
	msg.PvpResourceVersion=UTF8_TO_TCHAR(pb->pvpresourceversion().c_str());
	msg.CustomSubMode=pb->customsubmode();
	msg.TournamentId=pb->tournamentid();
	msg.BattlePassId=pb->battlepassid();
	msg.BigWinnerId=pb->bigwinnerid();
	msg.SubMode=pb->submode();
	msg.ActivityGroupId=pb->activitygroupid();
}


USTRUCT(BlueprintType)
struct  FCSRspPvp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBriefPunishment Punishment;	//惩罚信息

};
static void _ConvertPbToFCSRspPvp(FCSRspPvp &msg, const msg::CSRspPvp *pb) {
	_ConvertPbToFCSDTBriefPunishment(msg.Punishment, &pb->punishment());
}


USTRUCT(BlueprintType)
struct  FCSReqDressChessPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessPlayerId;	//棋手Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;	//道具Id

};
static void _ConvertPbToFCSReqDressChessPlayer(FCSReqDressChessPlayer &msg, const msg::CSReqDressChessPlayer *pb) {
	msg.ChessPlayerId=pb->chessplayerid();
	msg.ItemId=pb->itemid();
}


USTRUCT(BlueprintType)
struct  FCSRspDressChessPlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspDressChessPlayer(FCSRspDressChessPlayer &msg, const msg::CSRspDressChessPlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqDressScene {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//道具Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;	//道具uid

};
static void _ConvertPbToFCSReqDressScene(FCSReqDressScene &msg, const msg::CSReqDressScene *pb) {
	msg.Id=pb->id();
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspDressScene {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspDressScene(FCSRspDressScene &msg, const msg::CSRspDressScene *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPvpLogin {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//玩家id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VersionCode;	//版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ApkVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpResourceVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DeviceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GameId;

	int64 GamelibVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUserRestrictType RestrictType;	// 用户限制类型

};
static void _ConvertPbToFCSReqPvpLogin(FCSReqPvpLogin &msg, const msg::CSReqPvpLogin *pb) {
	msg.PvpId=pb->pvpid();
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.VersionCode=pb->versioncode();
	msg.ApkVersion=UTF8_TO_TCHAR(pb->apkversion().c_str());
	msg.PvpResourceVersion=UTF8_TO_TCHAR(pb->pvpresourceversion().c_str());
	msg.DeviceId=UTF8_TO_TCHAR(pb->deviceid().c_str());
	msg.GameId=pb->gameid();
	msg.GamelibVersion=pb->gamelibversion();
	msg.RestrictType=(EUserRestrictType)pb->restricttype();
}


USTRUCT(BlueprintType)
struct  FCSRspPvpLogin {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxGameSecs;	//最大游戏时间 单位：秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeqUpdate;	//服务器帧同步频率 单位：毫秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPvpPlayerData> Players;	//pvp玩家信息 包含自己，且玩家索引在单局游戏内固定

	std::string TcpKey;	//tcp秘钥

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurSeq;	//当前最新帧序号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LoadingUILeftTime;	//loadingUI剩余等待时间 单位：秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ReadyPlayers;	//loadingUI界面中已经ready玩家

	int64 CreateTime;	//pvp创建时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LocalDistanceToUTC;	//当地时间与UTC时间相差秒数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MeleeRule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpVoiceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpVoiceMemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CampVoiceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CampVoiceMemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CustomSubMode;	// 自定义子模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETEAMGROUP TeamGroup;	// 战斗中的身份

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpVoiceUserId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CampVoiceUserId;

	int64 GameStartTime;	// 本场比赛开始时间（区别于CreateTime)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CommunityLogoIcon;	// 社区logo icon

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OpenPlatAppId;	// 开放平台appid

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTournamentRoom;	// 是否是锦标赛房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBattleExtData ExtData;

	uint64 TournamentId;	// 赛事id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUserRestrictType RestrictType;	// 用户限制类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeachPassId;	// 教学关卡ID

	uint64 TournamentRoundId;	// 赛事轮次id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPvpExtData PvpExtData;	// 扩展字段

};
static void _ConvertPbToFCSRspPvpLogin(FCSRspPvpLogin &msg, const msg::CSRspPvpLogin *pb) {
	msg.PvpId=pb->pvpid();
	msg.MaxGameSecs=pb->maxgamesecs();
	msg.SeqUpdate=pb->sequpdate();
	for (int i = 0; i < pb->players().size(); i++) {
		auto &a = pb->players().Get(i);
		FPvpPlayerData tmp;
		_ConvertPbToFPvpPlayerData(tmp, &a);
		msg.Players.Add(tmp);
	}
	msg.TcpKey=pb->tcpkey();
	msg.CurSeq=pb->curseq();
	msg.LoadingUILeftTime=pb->loadinguilefttime();
	for (int i = 0; i < pb->readyplayers().size(); i++) {
		auto &a = pb->readyplayers().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ReadyPlayers.Add(tmp);
	}
	msg.CreateTime=pb->createtime();
	msg.LocalDistanceToUTC=pb->localdistancetoutc();
	msg.MeleeRule=pb->meleerule();
	msg.Mode=(EPVPMODE)pb->mode();
	msg.PvpVoiceId=UTF8_TO_TCHAR(pb->pvpvoiceid().c_str());
	msg.PvpVoiceMemId=pb->pvpvoicememid();
	msg.CampVoiceId=UTF8_TO_TCHAR(pb->campvoiceid().c_str());
	msg.CampVoiceMemId=pb->campvoicememid();
	msg.CustomSubMode=pb->customsubmode();
	msg.PlayerIndex=pb->playerindex();
	msg.TeamGroup=(ETEAMGROUP)pb->teamgroup();
	msg.PvpVoiceUserId=UTF8_TO_TCHAR(pb->pvpvoiceuserid().c_str());
	msg.CampVoiceUserId=UTF8_TO_TCHAR(pb->campvoiceuserid().c_str());
	msg.GameStartTime=pb->gamestarttime();
	msg.CommunityLogoIcon=UTF8_TO_TCHAR(pb->communitylogoicon().c_str());
	msg.OpenPlatAppId=UTF8_TO_TCHAR(pb->openplatappid().c_str());
	msg.IsTournamentRoom=pb->istournamentroom();
	_ConvertPbToFBattleExtData(msg.ExtData, &pb->extdata());
	msg.TournamentId=pb->tournamentid();
	msg.RestrictType=(EUserRestrictType)pb->restricttype();
	msg.TeachPassId=pb->teachpassid();
	msg.TournamentRoundId=pb->tournamentroundid();
	_ConvertPbToFPvpExtData(msg.PvpExtData, &pb->pvpextdata());
}


USTRUCT(BlueprintType)
struct  FCSReqPvpSeqs {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BeginSeqIndex;	//请求的帧开始序号

};
static void _ConvertPbToFCSReqPvpSeqs(FCSReqPvpSeqs &msg, const msg::CSReqPvpSeqs *pb) {
	msg.BeginSeqIndex=pb->beginseqindex();
}


USTRUCT(BlueprintType)
struct  FCSReqPvpEnd {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPvpCampResult CampResult;	//阵营数据统计

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPvpStat Stat;	//pvp统计

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	int64 PVPStartTime;	//pvp开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlatAppId;	//社区appId 对应开放平台侧

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CustomGameID;

	int64 CommunityTeamUUID;	//社区组队唯一id

};
static void _ConvertPbToFCSReqPvpEnd(FCSReqPvpEnd &msg, const msg::CSReqPvpEnd *pb) {
	msg.PvpId=pb->pvpid();
	_ConvertPbToFCSDTPvpCampResult(msg.CampResult, &pb->campresult());
	_ConvertPbToFCSDTPvpStat(msg.Stat, &pb->stat());
	msg.Mode=(EPVPMODE)pb->mode();
	msg.PVPStartTime=pb->pvpstarttime();
	msg.PlatAppId=UTF8_TO_TCHAR(pb->platappid().c_str());
	msg.CustomGameID=pb->customgameid();
	msg.CommunityTeamUUID=pb->communityteamuuid();
}


USTRUCT(BlueprintType)
struct  FCSRspPvpEnd {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPvpEnd(FCSRspPvpEnd &msg, const msg::CSRspPvpEnd *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPvpRoundEnd {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTRoundEnd> RoundItems;	//当前回合数据

};
static void _ConvertPbToFCSReqPvpRoundEnd(FCSReqPvpRoundEnd &msg, const msg::CSReqPvpRoundEnd *pb) {
	msg.PvpId=pb->pvpid();
	for (int i = 0; i < pb->rounditems().size(); i++) {
		auto &a = pb->rounditems().Get(i);
		FCSDTRoundEnd tmp;
		_ConvertPbToFCSDTRoundEnd(tmp, &a);
		msg.RoundItems.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspPvpRoundEnd {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPvpRoundEnd(FCSRspPvpRoundEnd &msg, const msg::CSRspPvpRoundEnd *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPlayerFinish {
	GENERATED_BODY()

	uint64 PvpId;	//pvp id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ReporterId;	//上报者

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPlayerFinish PlayerFinish;	//大逃杀数据

};
static void _ConvertPbToFCSReqPlayerFinish(FCSReqPlayerFinish &msg, const msg::CSReqPlayerFinish *pb) {
	msg.PvpId=pb->pvpid();
	msg.ReporterId=UTF8_TO_TCHAR(pb->reporterid().c_str());
	_ConvertPbToFCSDTPlayerFinish(msg.PlayerFinish, &pb->playerfinish());
}


USTRUCT(BlueprintType)
struct  FCSRspPlayerFinish {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPlayerFinish(FCSRspPlayerFinish &msg, const msg::CSRspPlayerFinish *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPlayerQuit {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqPlayerQuit(FCSReqPlayerQuit &msg, const msg::CSReqPlayerQuit *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspPlayerQuit {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPlayerQuit(FCSRspPlayerQuit &msg, const msg::CSRspPlayerQuit *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqObserveChatLogin {
	GENERATED_BODY()

	uint64 PvpId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpSvrId;

};
static void _ConvertPbToFCSReqObserveChatLogin(FCSReqObserveChatLogin &msg, const msg::CSReqObserveChatLogin *pb) {
	msg.PvpId=pb->pvpid();
	msg.PvpSvrId=pb->pvpsvrid();
}


USTRUCT(BlueprintType)
struct  FCSReqSellItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTItem> Items;	//出售的道具

};
static void _ConvertPbToFCSReqSellItem(FCSReqSellItem &msg, const msg::CSReqSellItem *pb) {
	for (int i = 0; i < pb->items().size(); i++) {
		auto &a = pb->items().Get(i);
		FCSDTItem tmp;
		_ConvertPbToFCSDTItem(tmp, &a);
		msg.Items.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspSellItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

};
static void _ConvertPbToFCSRspSellItem(FCSRspSellItem &msg, const msg::CSRspSellItem *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetEvalAward {
	GENERATED_BODY()

	uint64 PvpId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> RobotRankList;

};
static void _ConvertPbToFCSReqGetEvalAward(FCSReqGetEvalAward &msg, const msg::CSReqGetEvalAward *pb) {
	msg.PvpId=pb->pvpid();
	for (int i = 0; i < pb->robotranklist().size(); i++) {
		auto &a = pb->robotranklist().Get(i);
		int tmp;
		tmp=a;
		msg.RobotRankList.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspGetEvalAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FCSDTEvalAward> PlayerAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FCSDTEvalAward> RobotAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> PlayerRates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> BuffRates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FCSDTEvalAward> PvpIncomes;	// 局内收益

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTEvalAward TotalJackpot;	// 总奖金池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FPVEEvalData> PveEval;	//pve结算

};
static void _ConvertPbToFCSRspGetEvalAward(FCSRspGetEvalAward &msg, const msg::CSRspGetEvalAward *pb) {

    for (auto it = pb->playerawards().begin(); it != pb->playerawards().end(); it++) {
        FCSDTEvalAward tmp_value;
        _ConvertPbToFCSDTEvalAward(tmp_value, &it->second);
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.PlayerAwards.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->robotawards().begin(); it != pb->robotawards().end(); it++) {
        FCSDTEvalAward tmp_value;
        _ConvertPbToFCSDTEvalAward(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.RobotAwards.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->playerrates().begin(); it != pb->playerrates().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.PlayerRates.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->buffrates().begin(); it != pb->buffrates().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.BuffRates.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->pvpincomes().begin(); it != pb->pvpincomes().end(); it++) {
        FCSDTEvalAward tmp_value;
        _ConvertPbToFCSDTEvalAward(tmp_value, &it->second);
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.PvpIncomes.Add(tmp_key, tmp_value);
    }
	_ConvertPbToFCSDTEvalAward(msg.TotalJackpot, &pb->totaljackpot());

    for (auto it = pb->pveeval().begin(); it != pb->pveeval().end(); it++) {
        FPVEEvalData tmp_value;
        _ConvertPbToFPVEEvalData(tmp_value, &it->second);
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.PveEval.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqBuyPassportLevel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//购买等级

};
static void _ConvertPbToFCSReqBuyPassportLevel(FCSReqBuyPassportLevel &msg, const msg::CSReqBuyPassportLevel *pb) {
	msg.Level=pb->level();
}


USTRUCT(BlueprintType)
struct  FCSRspBuyPassportLevel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//购买等级消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewLevel;	//购买后的等级

};
static void _ConvertPbToFCSRspBuyPassportLevel(FCSRspBuyPassportLevel &msg, const msg::CSRspBuyPassportLevel *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.NewLevel=pb->newlevel();
}


USTRUCT(BlueprintType)
struct  FCSReqUpgradePassport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//升级类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DeductionId;	//代金券ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;	//代金券uid

};
static void _ConvertPbToFCSReqUpgradePassport(FCSReqUpgradePassport &msg, const msg::CSReqUpgradePassport *pb) {
	msg.Id=pb->id();
	msg.DeductionId=pb->deductionid();
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUpgradePassport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//升级消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//升级奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TypeIds;	//通行证类型IDList

};
static void _ConvertPbToFCSRspUpgradePassport(FCSRspUpgradePassport &msg, const msg::CSRspUpgradePassport *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->typeids().size(); i++) {
		auto &a = pb->typeids().Get(i);
		int tmp;
		tmp=a;
		msg.TypeIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetPassportLevelAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//战阶（通行证等级）level为0表示获取全部可领取奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPASSPORTLEVALAWARD GetType;	//领取类型

};
static void _ConvertPbToFCSReqGetPassportLevelAward(FCSReqGetPassportLevelAward &msg, const msg::CSReqGetPassportLevelAward *pb) {
	msg.Level=pb->level();
	msg.GetType=(EPASSPORTLEVALAWARD)pb->gettype();
}


USTRUCT(BlueprintType)
struct  FCSRspGetPassportLevelAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//获取的奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxLevel;	//领取的免费最大等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChargeLevelSegment> ChargeLevels;	//领取的付费等级区间

};
static void _ConvertPbToFCSRspGetPassportLevelAward(FCSRspGetPassportLevelAward &msg, const msg::CSRspGetPassportLevelAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.MaxLevel=pb->maxlevel();
	for (int i = 0; i < pb->chargelevels().size(); i++) {
		auto &a = pb->chargelevels().Get(i);
		FChargeLevelSegment tmp;
		_ConvertPbToFChargeLevelSegment(tmp, &a);
		msg.ChargeLevels.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetPassportTaskAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//任务ID

};
static void _ConvertPbToFCSReqGetPassportTaskAward(FCSReqGetPassportTaskAward &msg, const msg::CSReqGetPassportTaskAward *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSRspGetPassportTaskAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFCSRspGetPassportTaskAward(FCSRspGetPassportTaskAward &msg, const msg::CSRspGetPassportTaskAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetEggs {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetEggs(FCSReqGetEggs &msg, const msg::CSReqGetEggs *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetEggs {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Eggs;	//需要展示的商品{优先级\格子ID:商品ID}

};
static void _ConvertPbToFCSRspGetEggs(FCSRspGetEggs &msg, const msg::CSRspGetEggs *pb) {
	for (int i = 0; i < pb->eggs().size(); i++) {
		auto &a = pb->eggs().Get(i);
		int tmp;
		tmp=a;
		msg.Eggs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqUseChessPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;

};
static void _ConvertPbToFCSReqUseChessPlayer(FCSReqUseChessPlayer &msg, const msg::CSReqUseChessPlayer *pb) {
	msg.Id=pb->id();
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUseChessPlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUseChessPlayer(FCSRspUseChessPlayer &msg, const msg::CSRspUseChessPlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGuidReport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTGuide> Guides;

};
static void _ConvertPbToFCSReqGuidReport(FCSReqGuidReport &msg, const msg::CSReqGuidReport *pb) {
	for (int i = 0; i < pb->guides().size(); i++) {
		auto &a = pb->guides().Get(i);
		FCSDTGuide tmp;
		_ConvertPbToFCSDTGuide(tmp, &a);
		msg.Guides.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspGuidReport {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspGuidReport(FCSRspGuidReport &msg, const msg::CSRspGuidReport *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqStaticsReport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EventName;	//事件名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> Params;	//参数

};
static void _ConvertPbToFCSReqStaticsReport(FCSReqStaticsReport &msg, const msg::CSReqStaticsReport *pb) {
	msg.EventName=UTF8_TO_TCHAR(pb->eventname().c_str());

    for (auto it = pb->params().begin(); it != pb->params().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Params.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSRspStaticsReport {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspStaticsReport(FCSRspStaticsReport &msg, const msg::CSRspStaticsReport *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetCodeAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Code;	//兑换码

};
static void _ConvertPbToFCSReqGetCodeAward(FCSReqGetCodeAward &msg, const msg::CSReqGetCodeAward *pb) {
	msg.Code=UTF8_TO_TCHAR(pb->code().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspGetCodeAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Code;	//兑换码

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFCSRspGetCodeAward(FCSRspGetCodeAward &msg, const msg::CSRspGetCodeAward *pb) {
	msg.Code=UTF8_TO_TCHAR(pb->code().c_str());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqRoundReport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Round;

};
static void _ConvertPbToFCSReqRoundReport(FCSReqRoundReport &msg, const msg::CSReqRoundReport *pb) {
	msg.Round=pb->round();
}


USTRUCT(BlueprintType)
struct  FCSRspRoundReport {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspRoundReport(FCSRspRoundReport &msg, const msg::CSRspRoundReport *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqLoadingProgress {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Progress;

};
static void _ConvertPbToFCSReqLoadingProgress(FCSReqLoadingProgress &msg, const msg::CSReqLoadingProgress *pb) {
	msg.Progress=pb->progress();
}


USTRUCT(BlueprintType)
struct  FCSRspLoadingProgress {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspLoadingProgress(FCSRspLoadingProgress &msg, const msg::CSRspLoadingProgress *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPvpChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Emotion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATTYPE ChatType;

	uint64 PvpId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QuickChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CheckWorlds;	//需要检测的内容， Content里面有json，不能确定内容具体是什么，所以屏蔽词用这里的检测

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	//聊天来源类型

};
static void _ConvertPbToFCSReqPvpChat(FCSReqPvpChat &msg, const msg::CSReqPvpChat *pb) {
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.Emotion=pb->emotion();
	msg.ChatType=(ECHATTYPE)pb->chattype();
	msg.PvpId=pb->pvpid();
	msg.QuickChat=pb->quickchat();
	msg.CheckWorlds=UTF8_TO_TCHAR(pb->checkworlds().c_str());
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
}


USTRUCT(BlueprintType)
struct  FCSRspPvpChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NextSendTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATTYPE ChatType;

	int64 SilenceTime;	// 禁言时间

};
static void _ConvertPbToFCSRspPvpChat(FCSRspPvpChat &msg, const msg::CSRspPvpChat *pb) {
	msg.NextSendTime=pb->nextsendtime();
	msg.ChatType=(ECHATTYPE)pb->chattype();
	msg.SilenceTime=pb->silencetime();
}


USTRUCT(BlueprintType)
struct  FCSReqWXBlessBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int actId;	//活动id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int noticeId;	//活动id

};
static void _ConvertPbToFCSReqWXBlessBag(FCSReqWXBlessBag &msg, const msg::CSReqWXBlessBag *pb) {
	msg.actId=pb->actid();
	msg.noticeId=pb->noticeid();
}


USTRUCT(BlueprintType)
struct  FCSRspWXBlessBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString URL;

};
static void _ConvertPbToFCSRspWXBlessBag(FCSRspWXBlessBag &msg, const msg::CSRspWXBlessBag *pb) {
	msg.URL=UTF8_TO_TCHAR(pb->url().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqShareReward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDailyShareType Typ;

};
static void _ConvertPbToFCSReqShareReward(FCSReqShareReward &msg, const msg::CSReqShareReward *pb) {
	msg.Typ=(EDailyShareType)pb->typ();
}


USTRUCT(BlueprintType)
struct  FCSRspShareReward {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspShareReward(FCSRspShareReward &msg, const msg::CSRspShareReward *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqRecallReward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Openid;	//玩家

};
static void _ConvertPbToFCSReqRecallReward(FCSReqRecallReward &msg, const msg::CSReqRecallReward *pb) {
	msg.Openid=UTF8_TO_TCHAR(pb->openid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspRecallReward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> GetAward;

};
static void _ConvertPbToFCSRspRecallReward(FCSRspRecallReward &msg, const msg::CSRspRecallReward *pb) {
	for (int i = 0; i < pb->getaward().size(); i++) {
		auto &a = pb->getaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.GetAward.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqRecalledPlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqRecalledPlayer(FCSReqRecalledPlayer &msg, const msg::CSReqRecalledPlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspRecalledPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> OpenidList;

};
static void _ConvertPbToFCSRspRecalledPlayer(FCSRspRecalledPlayer &msg, const msg::CSRspRecalledPlayer *pb) {
	for (int i = 0; i < pb->openidlist().size(); i++) {
		auto &a = pb->openidlist().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.OpenidList.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqChessCombine {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessId;	//棋子ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Star;	//星级

};
static void _ConvertPbToFCSReqChessCombine(FCSReqChessCombine &msg, const msg::CSReqChessCombine *pb) {
	msg.ChessId=pb->chessid();
	msg.Star=pb->star();
}


USTRUCT(BlueprintType)
struct  FCSRspChessCombine {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspChessCombine(FCSRspChessCombine &msg, const msg::CSRspChessCombine *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqApplyOrderId {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GoodsId;	//商品id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Data;	//额外数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	//渠道类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> TxMBuy;	//腾讯直购参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> Attach;	//渠道购买扩展参数

};
static void _ConvertPbToFCSReqApplyOrderId(FCSReqApplyOrderId &msg, const msg::CSReqApplyOrderId *pb) {
	msg.GoodsId=pb->goodsid();
	msg.Data=UTF8_TO_TCHAR(pb->data().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();

    for (auto it = pb->txmbuy().begin(); it != pb->txmbuy().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.TxMBuy.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->attach().begin(); it != pb->attach().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Attach.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSRspApplyOrderId {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OrderId;	//订单id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GoodsId;	//商品id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PayCallBackURI;	//支付回调URI

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Data;	//额外数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> TxMBuy;	//腾讯直购参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelUsrId;	//玩家的渠道ID

};
static void _ConvertPbToFCSRspApplyOrderId(FCSRspApplyOrderId &msg, const msg::CSRspApplyOrderId *pb) {
	msg.OrderId=UTF8_TO_TCHAR(pb->orderid().c_str());
	msg.GoodsId=pb->goodsid();
	msg.PayCallBackURI=UTF8_TO_TCHAR(pb->paycallbackuri().c_str());
	msg.Data=UTF8_TO_TCHAR(pb->data().c_str());

    for (auto it = pb->txmbuy().begin(); it != pb->txmbuy().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.TxMBuy.Add(tmp_key, tmp_value);
    }
	msg.ChannelUsrId=UTF8_TO_TCHAR(pb->channelusrid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqReportOrderInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OrderId;	//订单id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//订单上报描述

};
static void _ConvertPbToFCSReqReportOrderInfo(FCSReqReportOrderInfo &msg, const msg::CSReqReportOrderInfo *pb) {
	msg.OrderId=UTF8_TO_TCHAR(pb->orderid().c_str());
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspReportOrderInfo {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspReportOrderInfo(FCSRspReportOrderInfo &msg, const msg::CSRspReportOrderInfo *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSetItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;

};
static void _ConvertPbToFCSReqSetItem(FCSReqSetItem &msg, const msg::CSReqSetItem *pb) {
	msg.ItemId=pb->itemid();
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSetItem {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetItem(FCSRspSetItem &msg, const msg::CSRspSetItem *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUnsetItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;

};
static void _ConvertPbToFCSReqUnsetItem(FCSReqUnsetItem &msg, const msg::CSReqUnsetItem *pb) {
	msg.ItemId=pb->itemid();
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUnsetItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewId;	//新展示的物品ID

};
static void _ConvertPbToFCSRspUnsetItem(FCSRspUnsetItem &msg, const msg::CSRspUnsetItem *pb) {
	msg.NewId=pb->newid();
}


USTRUCT(BlueprintType)
struct  FCSReqSetChessPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessPlayerId;	//棋手ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;	//物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChessPlayerUId;	//棋手唯一ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;	//物品唯一ID

};
static void _ConvertPbToFCSReqSetChessPlayer(FCSReqSetChessPlayer &msg, const msg::CSReqSetChessPlayer *pb) {
	msg.ChessPlayerId=pb->chessplayerid();
	msg.ItemId=pb->itemid();
	msg.ChessPlayerUId=UTF8_TO_TCHAR(pb->chessplayeruid().c_str());
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSetChessPlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetChessPlayer(FCSRspSetChessPlayer &msg, const msg::CSRspSetChessPlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUnsetChessPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessPlayerId;	//棋手ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;	//物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChessPlayerUId;	//棋手唯一ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;	//物品UId

};
static void _ConvertPbToFCSReqUnsetChessPlayer(FCSReqUnsetChessPlayer &msg, const msg::CSReqUnsetChessPlayer *pb) {
	msg.ChessPlayerId=pb->chessplayerid();
	msg.ItemId=pb->itemid();
	msg.ChessPlayerUId=UTF8_TO_TCHAR(pb->chessplayeruid().c_str());
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUnsetChessPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewId;	//新展示的物品

};
static void _ConvertPbToFCSRspUnsetChessPlayer(FCSRspUnsetChessPlayer &msg, const msg::CSRspUnsetChessPlayer *pb) {
	msg.NewId=pb->newid();
}


USTRUCT(BlueprintType)
struct  FCSReqRandomItem {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqRandomItem(FCSReqRandomItem &msg, const msg::CSReqRandomItem *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspRandomItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> Ids;

};
static void _ConvertPbToFCSRspRandomItem(FCSRspRandomItem &msg, const msg::CSRspRandomItem *pb) {

    for (auto it = pb->ids().begin(); it != pb->ids().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.Ids.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqBuyGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GiftId;	//礼包ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESHOPTYPE Type;	//商店类型

};
static void _ConvertPbToFCSReqBuyGoods(FCSReqBuyGoods &msg, const msg::CSReqBuyGoods *pb) {
	msg.GiftId=pb->giftid();
	msg.Count=pb->count();
	msg.Type=(ESHOPTYPE)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSRspBuyGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFCSRspBuyGoods(FCSRspBuyGoods &msg, const msg::CSRspBuyGoods *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetFansList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BeginIndex;	//开始位置

};
static void _ConvertPbToFCSReqGetFansList(FCSReqGetFansList &msg, const msg::CSReqGetFansList *pb) {
	msg.BeginIndex=pb->beginindex();
}


USTRUCT(BlueprintType)
struct  FCSRspGetFansList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> IdList;

};
static void _ConvertPbToFCSRspGetFansList(FCSRspGetFansList &msg, const msg::CSRspGetFansList *pb) {
	for (int i = 0; i < pb->idlist().size(); i++) {
		auto &a = pb->idlist().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.IdList.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqFollowPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//玩家ID

};
static void _ConvertPbToFCSReqFollowPlayer(FCSReqFollowPlayer &msg, const msg::CSReqFollowPlayer *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspFollowPlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspFollowPlayer(FCSRspFollowPlayer &msg, const msg::CSRspFollowPlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUnfollowPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//玩家ID

};
static void _ConvertPbToFCSReqUnfollowPlayer(FCSReqUnfollowPlayer &msg, const msg::CSReqUnfollowPlayer *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUnfollowPlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUnfollowPlayer(FCSRspUnfollowPlayer &msg, const msg::CSRspUnfollowPlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSetFriendInvisible {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFRIENDINVISIBLE Invisible;

};
static void _ConvertPbToFCSReqSetFriendInvisible(FCSReqSetFriendInvisible &msg, const msg::CSReqSetFriendInvisible *pb) {
	msg.Invisible=(EFRIENDINVISIBLE)pb->invisible();
}


USTRUCT(BlueprintType)
struct  FCSRspSetFriendInvisible {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFRIENDINVISIBLE Invisible;

};
static void _ConvertPbToFCSRspSetFriendInvisible(FCSRspSetFriendInvisible &msg, const msg::CSRspSetFriendInvisible *pb) {
	msg.Invisible=(EFRIENDINVISIBLE)pb->invisible();
}


USTRUCT(BlueprintType)
struct  FCSReqChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ReceiverId;	//接收者ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//聊天内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EmotionId;	//表情ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPriChatType PriType;	// 聊天类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	//聊天来源类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CheckWorlds;	//需要检测的内容， Content里面有json，不能确定内容具体是什么，所以屏蔽词用这里的检测

};
static void _ConvertPbToFCSReqChat(FCSReqChat &msg, const msg::CSReqChat *pb) {
	msg.ReceiverId=UTF8_TO_TCHAR(pb->receiverid().c_str());
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.EmotionId=pb->emotionid();
	msg.PriType=(EPriChatType)pb->pritype();
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
	msg.CheckWorlds=UTF8_TO_TCHAR(pb->checkworlds().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	//聊天来源类型

};
static void _ConvertPbToFCSRspChat(FCSRspChat &msg, const msg::CSRspChat *pb) {
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
}


USTRUCT(BlueprintType)
struct  FCSReqPlayersStatusInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	//id列表

};
static void _ConvertPbToFCSReqPlayersStatusInfo(FCSReqPlayersStatusInfo &msg, const msg::CSReqPlayersStatusInfo *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspPlayersStatusInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPlayerStatusInfo> Info;	//信息列表

};
static void _ConvertPbToFCSRspPlayersStatusInfo(FCSRspPlayersStatusInfo &msg, const msg::CSRspPlayersStatusInfo *pb) {
	for (int i = 0; i < pb->info().size(); i++) {
		auto &a = pb->info().Get(i);
		FCSDTPlayerStatusInfo tmp;
		_ConvertPbToFCSDTPlayerStatusInfo(tmp, &a);
		msg.Info.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqTeamGame {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	// 模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTeamOPSetting setting;	// 房间设定(自定义房间)

};
static void _ConvertPbToFCSReqTeamGame(FCSReqTeamGame &msg, const msg::CSReqTeamGame *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	_ConvertPbToFTeamOPSetting(msg.setting, &pb->setting());
}


USTRUCT(BlueprintType)
struct  FCSRspTeamGame {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//teamId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceId;	//语音房间ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTeamOPSetting Setting;

};
static void _ConvertPbToFCSRspTeamGame(FCSRspTeamGame &msg, const msg::CSRspTeamGame *pb) {
	msg.TeamId=pb->teamid();
	msg.VoiceId=UTF8_TO_TCHAR(pb->voiceid().c_str());
	_ConvertPbToFTeamOPSetting(msg.Setting, &pb->setting());
}


USTRUCT(BlueprintType)
struct  FCSReqSetTeamMode {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTeamOPSetting Setting;

};
static void _ConvertPbToFCSReqSetTeamMode(FCSReqSetTeamMode &msg, const msg::CSReqSetTeamMode *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	_ConvertPbToFTeamOPSetting(msg.Setting, &pb->setting());
}


USTRUCT(BlueprintType)
struct  FCSRspSetTeamMode {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetTeamMode(FCSRspSetTeamMode &msg, const msg::CSRspSetTeamMode *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqInviteJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWorkshopSetting Workshop;	//创意工坊

};
static void _ConvertPbToFCSReqInviteJoinTeam(FCSReqInviteJoinTeam &msg, const msg::CSReqInviteJoinTeam *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
	msg.Mode=(EPVPMODE)pb->mode();
	_ConvertPbToFWorkshopSetting(msg.Workshop, &pb->workshop());
}


USTRUCT(BlueprintType)
struct  FCSRspInviteJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//teamid

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceId;	//语音房间ID

};
static void _ConvertPbToFCSRspInviteJoinTeam(FCSRspInviteJoinTeam &msg, const msg::CSRspInviteJoinTeam *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.TeamId=pb->teamid();
	msg.VoiceId=UTF8_TO_TCHAR(pb->voiceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//teamId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EJOINTEAMTYPE JoinType;	//进队方式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFriend;	//如果有邀请者,邀请瞬间,被邀请者是否与邀请者是好友关系

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Pwd;	//需要密码

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OpenId;	//平台OpenId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Token;	//平台组队的token

	uint64 TournamentID;	//赛事ID

};
static void _ConvertPbToFCSReqJoinTeam(FCSReqJoinTeam &msg, const msg::CSReqJoinTeam *pb) {
	msg.TeamId=pb->teamid();
	msg.JoinType=(EJOINTEAMTYPE)pb->jointype();
	msg.IsFriend=pb->isfriend();
	msg.Pwd=UTF8_TO_TCHAR(pb->pwd().c_str());
	msg.OpenId=UTF8_TO_TCHAR(pb->openid().c_str());
	msg.Token=UTF8_TO_TCHAR(pb->token().c_str());
	msg.TournamentID=pb->tournamentid();
}


USTRUCT(BlueprintType)
struct  FCSRspJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	//玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Captain;	//队长

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ReadyIds;	//玩家准备状态数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SelfSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTeamSlotPlayer> SlotPlayers;	//成员所在槽号分布

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EJOINTEAMTYPE JoinType;	//回传

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFriend;	//回传

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceId;	//语音房间ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTeamOPSetting Setting;	//队伍的基础设定

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerNumber;	// 真人数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AINumber;	// AI玩家数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTournamentRoom RoomInfo;	// 锦标赛房间信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBetData BetData;	// 赏金投注信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CloseReadySwitch;	//决定客户端是否可取消准备

};
static void _ConvertPbToFCSRspJoinTeam(FCSRspJoinTeam &msg, const msg::CSRspJoinTeam *pb) {
	msg.TeamId=pb->teamid();
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
	msg.Captain=UTF8_TO_TCHAR(pb->captain().c_str());
	for (int i = 0; i < pb->readyids().size(); i++) {
		auto &a = pb->readyids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ReadyIds.Add(tmp);
	}
	msg.Mode=(EPVPMODE)pb->mode();
	msg.SelfSlot=pb->selfslot();
	for (int i = 0; i < pb->slotplayers().size(); i++) {
		auto &a = pb->slotplayers().Get(i);
		FCSDTTeamSlotPlayer tmp;
		_ConvertPbToFCSDTTeamSlotPlayer(tmp, &a);
		msg.SlotPlayers.Add(tmp);
	}
	msg.JoinType=(EJOINTEAMTYPE)pb->jointype();
	msg.IsFriend=pb->isfriend();
	msg.VoiceId=UTF8_TO_TCHAR(pb->voiceid().c_str());
	_ConvertPbToFTeamOPSetting(msg.Setting, &pb->setting());
	msg.PlayerNumber=pb->playernumber();
	msg.AINumber=pb->ainumber();
	_ConvertPbToFTournamentRoom(msg.RoomInfo, &pb->roominfo());
	_ConvertPbToFCSDTBetData(msg.BetData, &pb->betdata());
	msg.CloseReadySwitch=pb->closereadyswitch();
}


USTRUCT(BlueprintType)
struct  FCSRspLeaveTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//id

};
static void _ConvertPbToFCSRspLeaveTeam(FCSRspLeaveTeam &msg, const msg::CSRspLeaveTeam *pb) {
	msg.TeamId=pb->teamid();
}


USTRUCT(BlueprintType)
struct  FCSReqKickOffTeamPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//playerid

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAI;	//是否为自定义电脑

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Slot;	//槽号

};
static void _ConvertPbToFCSReqKickOffTeamPlayer(FCSReqKickOffTeamPlayer &msg, const msg::CSReqKickOffTeamPlayer *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.IsAI=pb->isai();
	msg.Slot=pb->slot();
}


USTRUCT(BlueprintType)
struct  FCSReqTeamMsg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Msg;	//消息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Emotion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CheckWorlds;	//需要检测的内容， Content里面有json，不能确定内容具体是什么，所以屏蔽词用这里的检测

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	//聊天来源类型

};
static void _ConvertPbToFCSReqTeamMsg(FCSReqTeamMsg &msg, const msg::CSReqTeamMsg *pb) {
	msg.Msg=UTF8_TO_TCHAR(pb->msg().c_str());
	msg.Emotion=pb->emotion();
	msg.CheckWorlds=UTF8_TO_TCHAR(pb->checkworlds().c_str());
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
}


USTRUCT(BlueprintType)
struct  FCSReqTeamReady {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//玩家id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsReady;	//准备or取消准备

};
static void _ConvertPbToFCSReqTeamReady(FCSReqTeamReady &msg, const msg::CSReqTeamReady *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.IsReady=pb->isready();
}


USTRUCT(BlueprintType)
struct  FCSRspTeamReady {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBriefPunishment Punishment;

};
static void _ConvertPbToFCSRspTeamReady(FCSRspTeamReady &msg, const msg::CSRspTeamReady *pb) {
	_ConvertPbToFCSDTBriefPunishment(msg.Punishment, &pb->punishment());
}


USTRUCT(BlueprintType)
struct  FCSReqReportPayResponse {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Signature;	//签名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Response;	//支付json回执

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	//渠道类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Env;	//环境:"Production"=正式测试,其他=沙盒测试,

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> EpicBuy;	//Epic支付相关的参数

};
static void _ConvertPbToFCSReqReportPayResponse(FCSReqReportPayResponse &msg, const msg::CSReqReportPayResponse *pb) {
	msg.Signature=UTF8_TO_TCHAR(pb->signature().c_str());
	msg.Response=UTF8_TO_TCHAR(pb->response().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.Env=UTF8_TO_TCHAR(pb->env().c_str());

    for (auto it = pb->epicbuy().begin(); it != pb->epicbuy().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.EpicBuy.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSRspReportPayResponse {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPAYRESULT Result;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;

};
static void _ConvertPbToFCSRspReportPayResponse(FCSRspReportPayResponse &msg, const msg::CSRspReportPayResponse *pb) {
	msg.Result=(EPAYRESULT)pb->result();
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqRejectJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NotReceive;

};
static void _ConvertPbToFCSReqRejectJoinTeam(FCSReqRejectJoinTeam &msg, const msg::CSReqRejectJoinTeam *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.NotReceive=pb->notreceive();
}


USTRUCT(BlueprintType)
struct  FCSRspRejectJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

};
static void _ConvertPbToFCSRspRejectJoinTeam(FCSRspRejectJoinTeam &msg, const msg::CSRspRejectJoinTeam *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqShieldChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Opening;	//是否开启

};
static void _ConvertPbToFCSReqShieldChat(FCSReqShieldChat &msg, const msg::CSReqShieldChat *pb) {
	msg.Opening=pb->opening();
}


USTRUCT(BlueprintType)
struct  FCSRspShieldChat {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspShieldChat(FCSRspShieldChat &msg, const msg::CSRspShieldChat *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqTelBook {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Tels;	//通讯录

};
static void _ConvertPbToFCSReqTelBook(FCSReqTelBook &msg, const msg::CSReqTelBook *pb) {
	for (int i = 0; i < pb->tels().size(); i++) {
		auto &a = pb->tels().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Tels.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspTelBook {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTelBook> TelBook;	//通讯录对应账号信息

};
static void _ConvertPbToFCSRspTelBook(FCSRspTelBook &msg, const msg::CSRspTelBook *pb) {
	for (int i = 0; i < pb->telbook().size(); i++) {
		auto &a = pb->telbook().Get(i);
		FCSDTTelBook tmp;
		_ConvertPbToFCSDTTelBook(tmp, &a);
		msg.TelBook.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqSendSms {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tel;	//电话号码

};
static void _ConvertPbToFCSReqSendSms(FCSReqSendSms &msg, const msg::CSReqSendSms *pb) {
	msg.Tel=UTF8_TO_TCHAR(pb->tel().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSendSms {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSendSms(FCSRspSendSms &msg, const msg::CSRspSendSms *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqActivatePassport {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqActivatePassport(FCSReqActivatePassport &msg, const msg::CSReqActivatePassport *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspActivatePassport {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspActivatePassport(FCSRspActivatePassport &msg, const msg::CSRspActivatePassport *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqRankSeasonEval {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	//赛季序号

};
static void _ConvertPbToFCSReqRankSeasonEval(FCSReqRankSeasonEval &msg, const msg::CSReqRankSeasonEval *pb) {
	msg.Index=pb->index();
}


USTRUCT(BlueprintType)
struct  FCSRspRankSeasonEval {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldIndex;	//旧赛季序号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewIndex;	//新赛季序号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewInitMMR;	//新赛季继承奖章

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldMaxMMR;	//新赛季继承段位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewInitTMMR;	//新赛季继承奖章

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldMaxTMMR;	//新赛季继承段位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldMMR;	//旧的mmr

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldTMMR;	//旧的2v2mmr

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldFFMMR;	//旧的4v4mmr

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewInitFFMMR;	//新赛季4v4继承奖章

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldMaxFFMMR;	//新赛季 4v4 继承段位

};
static void _ConvertPbToFCSRspRankSeasonEval(FCSRspRankSeasonEval &msg, const msg::CSRspRankSeasonEval *pb) {
	msg.OldIndex=pb->oldindex();
	msg.NewIndex=pb->newindex();
	msg.NewInitMMR=pb->newinitmmr();
	msg.OldMaxMMR=pb->oldmaxmmr();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.NewInitTMMR=pb->newinittmmr();
	msg.OldMaxTMMR=pb->oldmaxtmmr();
	msg.OldMMR=pb->oldmmr();
	msg.OldTMMR=pb->oldtmmr();
	msg.OldFFMMR=pb->oldffmmr();
	msg.NewInitFFMMR=pb->newinitffmmr();
	msg.OldMaxFFMMR=pb->oldmaxffmmr();
}


USTRUCT(BlueprintType)
struct  FCSReqBindAccount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	//渠道类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> AuthSDKCode;	//认证数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DeviceId;

};
static void _ConvertPbToFCSReqBindAccount(FCSReqBindAccount &msg, const msg::CSReqBindAccount *pb) {
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();

    for (auto it = pb->authsdkcode().begin(); it != pb->authsdkcode().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.AuthSDKCode.Add(tmp_key, tmp_value);
    }
	msg.DeviceId=UTF8_TO_TCHAR(pb->deviceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspBindAccount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> Datas;	//账号登陆相关数据

};
static void _ConvertPbToFCSRspBindAccount(FCSRspBindAccount &msg, const msg::CSRspBindAccount *pb) {

    for (auto it = pb->datas().begin(); it != pb->datas().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Datas.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqIncAdShowCount {
	GENERATED_BODY()

	int64 Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EADSTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

};
static void _ConvertPbToFCSReqIncAdShowCount(FCSReqIncAdShowCount &msg, const msg::CSReqIncAdShowCount *pb) {
	msg.Id=pb->id();
	msg.Type=(EADSTYPE)pb->type();
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
}


USTRUCT(BlueprintType)
struct  FCSRspIncAdShowCount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

};
static void _ConvertPbToFCSRspIncAdShowCount(FCSRspIncAdShowCount &msg, const msg::CSRspIncAdShowCount *pb) {
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSReqUseBonusCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

};
static void _ConvertPbToFCSReqUseBonusCard(FCSReqUseBonusCard &msg, const msg::CSReqUseBonusCard *pb) {
	msg.ItemId=pb->itemid();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSRspUseBonusCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE Type;	//道具类型

	int64 ExpiredTime;	//到期时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

};
static void _ConvertPbToFCSRspUseBonusCard(FCSRspUseBonusCard &msg, const msg::CSRspUseBonusCard *pb) {
	msg.Type=(EITEMTYPE)pb->type();
	msg.ExpiredTime=pb->expiredtime();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetSeasonAward {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetSeasonAward(FCSReqGetSeasonAward &msg, const msg::CSReqGetSeasonAward *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetSeasonAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFCSRspGetSeasonAward(FCSRspGetSeasonAward &msg, const msg::CSRspGetSeasonAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetVngCommentAward {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetVngCommentAward(FCSReqGetVngCommentAward &msg, const msg::CSReqGetVngCommentAward *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetVngCommentAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFCSRspGetVngCommentAward(FCSRspGetVngCommentAward &msg, const msg::CSRspGetVngCommentAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqLevelupChest {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

};
static void _ConvertPbToFCSReqLevelupChest(FCSReqLevelupChest &msg, const msg::CSReqLevelupChest *pb) {
	msg.GroupId=pb->groupid();
}


USTRUCT(BlueprintType)
struct  FCSRspLevelupChest {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSRspLevelupChest(FCSRspLevelupChest &msg, const msg::CSRspLevelupChest *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqWatchAd {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdId;	//广告id

};
static void _ConvertPbToFCSReqWatchAd(FCSReqWatchAd &msg, const msg::CSReqWatchAd *pb) {
	msg.AdId=pb->adid();
}


USTRUCT(BlueprintType)
struct  FCSRspWatchAd {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspWatchAd(FCSRspWatchAd &msg, const msg::CSRspWatchAd *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetAdCumulateAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Award;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalViewCout;	// 累计观看次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdCumulateCount;	// 已领取观看次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Group;	// 广告统计组

};
static void _ConvertPbToFCSRspGetAdCumulateAward(FCSRspGetAdCumulateAward &msg, const msg::CSRspGetAdCumulateAward *pb) {
	for (int i = 0; i < pb->award().size(); i++) {
		auto &a = pb->award().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Award.Add(tmp);
	}
	msg.TotalViewCout=pb->totalviewcout();
	msg.AdCumulateCount=pb->adcumulatecount();
	msg.Group=pb->group();
}


USTRUCT(BlueprintType)
struct  FCSReqQueryPsTournamentRoom {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EventID;	//

};
static void _ConvertPbToFCSReqQueryPsTournamentRoom(FCSReqQueryPsTournamentRoom &msg, const msg::CSReqQueryPsTournamentRoom *pb) {
	msg.EventID=UTF8_TO_TCHAR(pb->eventid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqGetAdCumulateAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Group;

};
static void _ConvertPbToFCSReqGetAdCumulateAward(FCSReqGetAdCumulateAward &msg, const msg::CSReqGetAdCumulateAward *pb) {
	msg.Group=pb->group();
}


USTRUCT(BlueprintType)
struct  FCSRspQueryPsTournamentRoom {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Room;	// 房间id

};
static void _ConvertPbToFCSRspQueryPsTournamentRoom(FCSRspQueryPsTournamentRoom &msg, const msg::CSRspQueryPsTournamentRoom *pb) {
	msg.Room=pb->room();
}


USTRUCT(BlueprintType)
struct  FCSReqGetAlphaActivityAward {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetAlphaActivityAward(FCSReqGetAlphaActivityAward &msg, const msg::CSReqGetAlphaActivityAward *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetAlphaActivityAward {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspGetAlphaActivityAward(FCSRspGetAlphaActivityAward &msg, const msg::CSRspGetAlphaActivityAward *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetLanguageData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Kyes;

};
static void _ConvertPbToFCSReqGetLanguageData(FCSReqGetLanguageData &msg, const msg::CSReqGetLanguageData *pb) {
	for (int i = 0; i < pb->kyes().size(); i++) {
		auto &a = pb->kyes().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Kyes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspGetLanguageData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FLanguageData> Datas;

};
static void _ConvertPbToFCSRspGetLanguageData(FCSRspGetLanguageData &msg, const msg::CSRspGetLanguageData *pb) {

    for (auto it = pb->datas().begin(); it != pb->datas().end(); it++) {
        FLanguageData tmp_value;
        _ConvertPbToFLanguageData(tmp_value, &it->second);
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Datas.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqGetActivityAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//活动ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTActGrpBuyAward GrpBuy;	//团购返利活动

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTActPuzzle Puzzle;	//图块活动

};
static void _ConvertPbToFCSReqGetActivityAward(FCSReqGetActivityAward &msg, const msg::CSReqGetActivityAward *pb) {
	msg.GroupId=pb->groupid();
	msg.Id=pb->id();
	_ConvertPbToFCSDTActGrpBuyAward(msg.GrpBuy, &pb->grpbuy());
	_ConvertPbToFCSDTActPuzzle(msg.Puzzle, &pb->puzzle());
}


USTRUCT(BlueprintType)
struct  FCSRspGetActivityAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPuzzleRecord Puzzle;	//图块活动

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTSignRecord DaySign;	//签到

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPveRecord Pve;	//年兽

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardPoolId;	//本次奖励在奖池的id

};
static void _ConvertPbToFCSRspGetActivityAward(FCSRspGetActivityAward &msg, const msg::CSRspGetActivityAward *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	_ConvertPbToFCSDTPuzzleRecord(msg.Puzzle, &pb->puzzle());
	_ConvertPbToFCSDTSignRecord(msg.DaySign, &pb->daysign());
	_ConvertPbToFCSDTPveRecord(msg.Pve, &pb->pve());
	msg.AwardPoolId=pb->awardpoolid();
}


USTRUCT(BlueprintType)
struct  FCSReqGetActivityData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FActivityIdList> Activities;	//活动列表(k:活动组id， v:活动id列表(如果为空，则请求该组下所有活动项数据，否则请求该id列表所指定的活动项数据))

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> GroupIdList;	//活动组id列表

};
static void _ConvertPbToFCSReqGetActivityData(FCSReqGetActivityData &msg, const msg::CSReqGetActivityData *pb) {

    for (auto it = pb->activities().begin(); it != pb->activities().end(); it++) {
        FActivityIdList tmp_value;
        _ConvertPbToFActivityIdList(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Activities.Add(tmp_key, tmp_value);
    }
	for (int i = 0; i < pb->groupidlist().size(); i++) {
		auto &a = pb->groupidlist().Get(i);
		int tmp;
		tmp=a;
		msg.GroupIdList.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspGetActivityData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FActivityDataList> Activities;	//活动列表数据(k:活动组id， v:该活动组id请求的活动项数据)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActivityGroupDataWrap> Groups;	//活动组数据

};
static void _ConvertPbToFCSRspGetActivityData(FCSRspGetActivityData &msg, const msg::CSRspGetActivityData *pb) {

    for (auto it = pb->activities().begin(); it != pb->activities().end(); it++) {
        FActivityDataList tmp_value;
        _ConvertPbToFActivityDataList(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Activities.Add(tmp_key, tmp_value);
    }
	for (int i = 0; i < pb->groups().size(); i++) {
		auto &a = pb->groups().Get(i);
		FActivityGroupDataWrap tmp;
		_ConvertPbToFActivityGroupDataWrap(tmp, &a);
		msg.Groups.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqShare {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqShare(FCSReqShare &msg, const msg::CSReqShare *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspShare {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspShare(FCSRspShare &msg, const msg::CSRspShare *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSkipInterface {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InterfaceId;	//界面ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TapId;	//切页ID

};
static void _ConvertPbToFCSReqSkipInterface(FCSReqSkipInterface &msg, const msg::CSReqSkipInterface *pb) {
	msg.InterfaceId=pb->interfaceid();
	msg.TapId=pb->tapid();
}


USTRUCT(BlueprintType)
struct  FCSRspSkipInterface {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSkipInterface(FCSRspSkipInterface &msg, const msg::CSRspSkipInterface *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetMeleeAward {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetMeleeAward(FCSReqGetMeleeAward &msg, const msg::CSReqGetMeleeAward *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetMeleeAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFCSRspGetMeleeAward(FCSRspGetMeleeAward &msg, const msg::CSRspGetMeleeAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqAddAiToTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Slot;

};
static void _ConvertPbToFCSReqAddAiToTeam(FCSReqAddAiToTeam &msg, const msg::CSReqAddAiToTeam *pb) {
	msg.Slot=pb->slot();
}


USTRUCT(BlueprintType)
struct  FCSRspAddAiToTeam {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspAddAiToTeam(FCSRspAddAiToTeam &msg, const msg::CSRspAddAiToTeam *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSetHistoryPvpShowPermission {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EHISTORYPVPSHOWPERMISSION Permission;

};
static void _ConvertPbToFCSReqSetHistoryPvpShowPermission(FCSReqSetHistoryPvpShowPermission &msg, const msg::CSReqSetHistoryPvpShowPermission *pb) {
	msg.Permission=(EHISTORYPVPSHOWPERMISSION)pb->permission();
}


USTRUCT(BlueprintType)
struct  FCSRspSetHistoryPvpShowPermission {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EHISTORYPVPSHOWPERMISSION Permission;

};
static void _ConvertPbToFCSRspSetHistoryPvpShowPermission(FCSRspSetHistoryPvpShowPermission &msg, const msg::CSRspSetHistoryPvpShowPermission *pb) {
	msg.Permission=(EHISTORYPVPSHOWPERMISSION)pb->permission();
}


USTRUCT(BlueprintType)
struct  FCSReqSearchTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE mode;	// 按模式搜索

};
static void _ConvertPbToFCSReqSearchTeam(FCSReqSearchTeam &msg, const msg::CSReqSearchTeam *pb) {
	msg.TeamId=pb->teamid();
	msg.mode=(EPVPMODE)pb->mode();
}


USTRUCT(BlueprintType)
struct  FCSRspSearchTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Captain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTeamBaseInfo baseInfo;

};
static void _ConvertPbToFCSRspSearchTeam(FCSRspSearchTeam &msg, const msg::CSRspSearchTeam *pb) {
	msg.Captain=UTF8_TO_TCHAR(pb->captain().c_str());
	msg.PlayerNum=pb->playernum();
	_ConvertPbToFTeamBaseInfo(msg.baseInfo, &pb->baseinfo());
}


USTRUCT(BlueprintType)
struct  FCSReqApplyChat {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqApplyChat(FCSReqApplyChat &msg, const msg::CSReqApplyChat *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspApplyChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChatTCPSvrAddr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SessionId;

};
static void _ConvertPbToFCSRspApplyChat(FCSRspApplyChat &msg, const msg::CSRspApplyChat *pb) {
	msg.ChatTCPSvrAddr=UTF8_TO_TCHAR(pb->chattcpsvraddr().c_str());
	msg.SessionId=UTF8_TO_TCHAR(pb->sessionid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqChatLogin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SessionId;

};
static void _ConvertPbToFCSReqChatLogin(FCSReqChatLogin &msg, const msg::CSReqChatLogin *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.SessionId=UTF8_TO_TCHAR(pb->sessionid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspChatLogin {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspChatLogin(FCSRspChatLogin &msg, const msg::CSRspChatLogin *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqApplyChannel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelID;

};
static void _ConvertPbToFCSReqApplyChannel(FCSReqApplyChannel &msg, const msg::CSReqApplyChannel *pb) {
	msg.ChannelID=UTF8_TO_TCHAR(pb->channelid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspApplyChannel {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspApplyChannel(FCSRspApplyChannel &msg, const msg::CSRspApplyChannel *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqProbeNetDelay {
	GENERATED_BODY()

	int64 Number;

};
static void _ConvertPbToFCSReqProbeNetDelay(FCSReqProbeNetDelay &msg, const msg::CSReqProbeNetDelay *pb) {
	msg.Number=pb->number();
}


USTRUCT(BlueprintType)
struct  FCSRspProbeNetDelay {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspProbeNetDelay(FCSRspProbeNetDelay &msg, const msg::CSRspProbeNetDelay *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqExchangePassportGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

};
static void _ConvertPbToFCSReqExchangePassportGoods(FCSReqExchangePassportGoods &msg, const msg::CSReqExchangePassportGoods *pb) {
	msg.Id=pb->id();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSRspExchangePassportGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTExchangePassportGoodsData> BuyData;	//通行证商店兑换的

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//通行证商店对应的商品奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗得物品

};
static void _ConvertPbToFCSRspExchangePassportGoods(FCSRspExchangePassportGoods &msg, const msg::CSRspExchangePassportGoods *pb) {
	for (int i = 0; i < pb->buydata().size(); i++) {
		auto &a = pb->buydata().Get(i);
		FCSDTExchangePassportGoodsData tmp;
		_ConvertPbToFCSDTExchangePassportGoodsData(tmp, &a);
		msg.BuyData.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqUsePassportTaskCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

};
static void _ConvertPbToFCSReqUsePassportTaskCard(FCSReqUsePassportTaskCard &msg, const msg::CSReqUsePassportTaskCard *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSRspUsePassportTaskCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//完成任务自动领取奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekTaskBattleStar;	//周任务战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayTaskBattleStar;	//日任务战星

};
static void _ConvertPbToFCSRspUsePassportTaskCard(FCSRspUsePassportTaskCard &msg, const msg::CSRspUsePassportTaskCard *pb) {
	msg.Count=pb->count();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.WeekTaskBattleStar=pb->weektaskbattlestar();
	msg.DayTaskBattleStar=pb->daytaskbattlestar();
}


USTRUCT(BlueprintType)
struct  FCSReqOpenRandChest {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//自选礼包已选择的物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHEST_OPEN_TYPE OpenType;	//开启方式(高阶密藏、低阶密藏)

};
static void _ConvertPbToFCSReqOpenRandChest(FCSReqOpenRandChest &msg, const msg::CSReqOpenRandChest *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.OpenType=(ECHEST_OPEN_TYPE)pb->opentype();
}


USTRUCT(BlueprintType)
struct  FCSRspOpenRandChest {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//抽奖奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> CumulateAwards;	// 保底奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> RareAwards;	// 珍稀奖励

};
static void _ConvertPbToFCSRspOpenRandChest(FCSRspOpenRandChest &msg, const msg::CSRspOpenRandChest *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->cumulateawards().size(); i++) {
		auto &a = pb->cumulateawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.CumulateAwards.Add(tmp);
	}
	for (int i = 0; i < pb->rareawards().size(); i++) {
		auto &a = pb->rareawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.RareAwards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqQueryDiamondBalance {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> Params;	//向渠道查询钻石充值信息参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Charge;

};
static void _ConvertPbToFCSReqQueryDiamondBalance(FCSReqQueryDiamondBalance &msg, const msg::CSReqQueryDiamondBalance *pb) {

    for (auto it = pb->params().begin(); it != pb->params().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Params.Add(tmp_key, tmp_value);
    }
	msg.Charge=pb->charge();
}


USTRUCT(BlueprintType)
struct  FCSRspQueryDiamondBalance {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> Params;	//向渠道查询钻石充值信息参数

};
static void _ConvertPbToFCSRspQueryDiamondBalance(FCSRspQueryDiamondBalance &msg, const msg::CSRspQueryDiamondBalance *pb) {

    for (auto it = pb->params().begin(); it != pb->params().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Params.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqQueryPs4Entitlements {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> Params;

};
static void _ConvertPbToFCSReqQueryPs4Entitlements(FCSReqQueryPs4Entitlements &msg, const msg::CSReqQueryPs4Entitlements *pb) {

    for (auto it = pb->params().begin(); it != pb->params().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Params.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSRsqQueryPs4Entitlements {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRsqQueryPs4Entitlements(FCSRsqQueryPs4Entitlements &msg, const msg::CSRsqQueryPs4Entitlements *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUseItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSReqUseItem(FCSReqUseItem &msg, const msg::CSReqUseItem *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspUseItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSRspUseItem(FCSRspUseItem &msg, const msg::CSRspUseItem *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqUseExperienceCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

};
static void _ConvertPbToFCSReqUseExperienceCard(FCSReqUseExperienceCard &msg, const msg::CSReqUseExperienceCard *pb) {
	msg.Id=pb->id();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSRspUseExperienceCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TargetId;

	int64 SurviveTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSRspUseExperienceCard(FCSRspUseExperienceCard &msg, const msg::CSRspUseExperienceCard *pb) {
	msg.TargetId=pb->targetid();
	msg.SurviveTime=pb->survivetime();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqRandTargetItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessPlayerId;

};
static void _ConvertPbToFCSReqRandTargetItem(FCSReqRandTargetItem &msg, const msg::CSReqRandTargetItem *pb) {
	msg.Type=(EITEMTYPE)pb->type();
	msg.ChessPlayerId=pb->chessplayerid();
}


USTRUCT(BlueprintType)
struct  FCSRspRandTargetItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewId;

};
static void _ConvertPbToFCSRspRandTargetItem(FCSRspRandTargetItem &msg, const msg::CSRspRandTargetItem *pb) {
	msg.NewId=pb->newid();
}


USTRUCT(BlueprintType)
struct  FCSReqAddBlacklist {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

};
static void _ConvertPbToFCSReqAddBlacklist(FCSReqAddBlacklist &msg, const msg::CSReqAddBlacklist *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspAddBlacklist {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

};
static void _ConvertPbToFCSRspAddBlacklist(FCSRspAddBlacklist &msg, const msg::CSRspAddBlacklist *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqRemoveBlacklist {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

};
static void _ConvertPbToFCSReqRemoveBlacklist(FCSReqRemoveBlacklist &msg, const msg::CSReqRemoveBlacklist *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspRemoveBlacklist {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

};
static void _ConvertPbToFCSRspRemoveBlacklist(FCSRspRemoveBlacklist &msg, const msg::CSRspRemoveBlacklist *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqReportPlayerBirth {
	GENERATED_BODY()

	int64 Birthday;	//年龄

};
static void _ConvertPbToFCSReqReportPlayerBirth(FCSReqReportPlayerBirth &msg, const msg::CSReqReportPlayerBirth *pb) {
	msg.Birthday=pb->birthday();
}


USTRUCT(BlueprintType)
struct  FCSRspReportPlayerBirth {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspReportPlayerBirth(FCSRspReportPlayerBirth &msg, const msg::CSRspReportPlayerBirth *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqReportInfoInput {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqReportInfoInput(FCSReqReportInfoInput &msg, const msg::CSReqReportInfoInput *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspReportInfoInput {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspReportInfoInput(FCSRspReportInfoInput &msg, const msg::CSRspReportInfoInput *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateFriendsInGame {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Num;	// 同玩好友人数

};
static void _ConvertPbToFCSReqUpdateFriendsInGame(FCSReqUpdateFriendsInGame &msg, const msg::CSReqUpdateFriendsInGame *pb) {
	msg.Num=pb->num();
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateFriendsInGame {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateFriendsInGame(FCSRspUpdateFriendsInGame &msg, const msg::CSRspUpdateFriendsInGame *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSendVerificationCode {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tel;	// 手机号

};
static void _ConvertPbToFCSReqSendVerificationCode(FCSReqSendVerificationCode &msg, const msg::CSReqSendVerificationCode *pb) {
	msg.Tel=UTF8_TO_TCHAR(pb->tel().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSendVerificationCode {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSendVerificationCode(FCSRspSendVerificationCode &msg, const msg::CSRspSendVerificationCode *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqBindPhoneNumber {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tel;	//手机号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Code;	//验证码

};
static void _ConvertPbToFCSReqBindPhoneNumber(FCSReqBindPhoneNumber &msg, const msg::CSReqBindPhoneNumber *pb) {
	msg.Tel=UTF8_TO_TCHAR(pb->tel().c_str());
	msg.Code=UTF8_TO_TCHAR(pb->code().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspBindPhoneNumber {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspBindPhoneNumber(FCSRspBindPhoneNumber &msg, const msg::CSRspBindPhoneNumber *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqWorldInvite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EINVITETYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InviteDes;	//描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WorkshopMapName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWorkshopSetting WSSetting;	// todo: 手游接入这个新字段后，删掉WorkshopMapName

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GuildID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CheckWorlds;	//需要检测的内容， Content里面有json，不能确定内容具体是什么，所以屏蔽词用这里的检测

};
static void _ConvertPbToFCSReqWorldInvite(FCSReqWorldInvite &msg, const msg::CSReqWorldInvite *pb) {
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.Mode=pb->mode();
	msg.TeamId=pb->teamid();
	msg.Type=(EINVITETYPE)pb->type();
	msg.InviteDes=UTF8_TO_TCHAR(pb->invitedes().c_str());
	msg.WorkshopMapName=UTF8_TO_TCHAR(pb->workshopmapname().c_str());
	_ConvertPbToFWorkshopSetting(msg.WSSetting, &pb->wssetting());
	msg.GuildID=UTF8_TO_TCHAR(pb->guildid().c_str());
	msg.CheckWorlds=UTF8_TO_TCHAR(pb->checkworlds().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspWorldInvite {
	GENERATED_BODY()

	int64 NextSendTime;

	int64 SilenceTime;	// 禁言时间

};
static void _ConvertPbToFCSRspWorldInvite(FCSRspWorldInvite &msg, const msg::CSRspWorldInvite *pb) {
	msg.NextSendTime=pb->nextsendtime();
	msg.SilenceTime=pb->silencetime();
}


USTRUCT(BlueprintType)
struct  FCSReqRemoveExpireItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTItemID> Ids;

};
static void _ConvertPbToFCSReqRemoveExpireItem(FCSReqRemoveExpireItem &msg, const msg::CSReqRemoveExpireItem *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FCSDTItemID tmp;
		_ConvertPbToFCSDTItemID(tmp, &a);
		msg.Ids.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspRemoveExpireItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTItemID> RemoveIds;

};
static void _ConvertPbToFCSRspRemoveExpireItem(FCSRspRemoveExpireItem &msg, const msg::CSRspRemoveExpireItem *pb) {
	for (int i = 0; i < pb->removeids().size(); i++) {
		auto &a = pb->removeids().Get(i);
		FCSDTItemID tmp;
		_ConvertPbToFCSDTItemID(tmp, &a);
		msg.RemoveIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetMallGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MallTabId;	//-1表示拉取首页推荐栏数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActivityGroupId;	//活动Groupid(根据TabId获得TabType区分活动)

};
static void _ConvertPbToFCSReqGetMallGoods(FCSReqGetMallGoods &msg, const msg::CSReqGetMallGoods *pb) {
	msg.MallTabId=pb->malltabid();
	msg.ActivityGroupId=pb->activitygroupid();
}


USTRUCT(BlueprintType)
struct  FCSRspGetMallGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FCSDTMallGoods> MallTabs;	//商城栏位的商品信息

};
static void _ConvertPbToFCSRspGetMallGoods(FCSRspGetMallGoods &msg, const msg::CSRspGetMallGoods *pb) {

    for (auto it = pb->malltabs().begin(); it != pb->malltabs().end(); it++) {
        FCSDTMallGoods tmp_value;
        _ConvertPbToFCSDTMallGoods(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.MallTabs.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqBuyMallGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GoodsId;	//商品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//购买数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> DeductionUid;	//使用抵扣券物品uId列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConsumeNum;	//使用的货币 1：货币1，2：货币2

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ADDiscount;

};
static void _ConvertPbToFCSReqBuyMallGoods(FCSReqBuyMallGoods &msg, const msg::CSReqBuyMallGoods *pb) {
	msg.GoodsId=pb->goodsid();
	msg.Count=pb->count();
	for (int i = 0; i < pb->deductionuid().size(); i++) {
		auto &a = pb->deductionuid().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.DeductionUid.Add(tmp);
	}
	msg.ConsumeNum=pb->consumenum();
	msg.ADDiscount=pb->addiscount();
}


USTRUCT(BlueprintType)
struct  FCSRspBuyMallGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuyCount;	//购买数量

	int64 LastResetTime;	//上次重置时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GoodsId;	//商品ID

};
static void _ConvertPbToFCSRspBuyMallGoods(FCSRspBuyMallGoods &msg, const msg::CSRspBuyMallGoods *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.BuyCount=pb->buycount();
	msg.LastResetTime=pb->lastresettime();
	msg.GoodsId=pb->goodsid();
}


USTRUCT(BlueprintType)
struct  FCSReqBindSharingCode {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Code;

};
static void _ConvertPbToFCSReqBindSharingCode(FCSReqBindSharingCode &msg, const msg::CSReqBindSharingCode *pb) {
	msg.Code=UTF8_TO_TCHAR(pb->code().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspBindSharingCode {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspBindSharingCode(FCSRspBindSharingCode &msg, const msg::CSRspBindSharingCode *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqAllFightInfo {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqAllFightInfo(FCSReqAllFightInfo &msg, const msg::CSReqAllFightInfo *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspAllFightInfo {
	GENERATED_BODY()

	int64 GlobalFightNum;	//全局对战局数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FightNum;	//个人对战局数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Percent;	//个人对战局数百分比

};
static void _ConvertPbToFCSRspAllFightInfo(FCSRspAllFightInfo &msg, const msg::CSRspAllFightInfo *pb) {
	msg.GlobalFightNum=pb->globalfightnum();
	msg.FightNum=pb->fightnum();
	msg.Percent=pb->percent();
}


USTRUCT(BlueprintType)
struct  FCSReqGetOldPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tel;	// 手机号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Code;	// 验证码

};
static void _ConvertPbToFCSReqGetOldPlayer(FCSReqGetOldPlayer &msg, const msg::CSReqGetOldPlayer *pb) {
	msg.Tel=UTF8_TO_TCHAR(pb->tel().c_str());
	msg.Code=UTF8_TO_TCHAR(pb->code().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspGetOldPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//昵称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadPic;	//头像

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadPicFrame;	//头像框

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMR;	//杯段

};
static void _ConvertPbToFCSRspGetOldPlayer(FCSRspGetOldPlayer &msg, const msg::CSRspGetOldPlayer *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.HeadPic=pb->headpic();
	msg.HeadPicFrame=pb->headpicframe();
	msg.Level=pb->level();
	msg.MMR=pb->mmr();
}


USTRUCT(BlueprintType)
struct  FCSReqBindOldPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tel;	// 手机号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Code;	// 验证码

};
static void _ConvertPbToFCSReqBindOldPlayer(FCSReqBindOldPlayer &msg, const msg::CSReqBindOldPlayer *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Tel=UTF8_TO_TCHAR(pb->tel().c_str());
	msg.Code=UTF8_TO_TCHAR(pb->code().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspBindOldPlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspBindOldPlayer(FCSRspBindOldPlayer &msg, const msg::CSRspBindOldPlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSendVerificationCodeWithCheckRedis {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tel;	//手机号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EVERIFICATIONCODETYPE Type;	//验证码类型

};
static void _ConvertPbToFCSReqSendVerificationCodeWithCheckRedis(FCSReqSendVerificationCodeWithCheckRedis &msg, const msg::CSReqSendVerificationCodeWithCheckRedis *pb) {
	msg.Tel=UTF8_TO_TCHAR(pb->tel().c_str());
	msg.Type=(EVERIFICATIONCODETYPE)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSRspSendVerificationCodeWithCheckRedis {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSendVerificationCodeWithCheckRedis(FCSRspSendVerificationCodeWithCheckRedis &msg, const msg::CSRspSendVerificationCodeWithCheckRedis *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqReportSetting {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> Settings;

};
static void _ConvertPbToFCSReqReportSetting(FCSReqReportSetting &msg, const msg::CSReqReportSetting *pb) {

    for (auto it = pb->settings().begin(); it != pb->settings().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.Settings.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSRspReportSetting {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspReportSetting(FCSRspReportSetting &msg, const msg::CSRspReportSetting *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqAntiData {
	GENERATED_BODY()

	std::string Data;

};
static void _ConvertPbToFCSReqAntiData(FCSReqAntiData &msg, const msg::CSReqAntiData *pb) {
	msg.Data=pb->data();
}


USTRUCT(BlueprintType)
struct  FCSRspAntiData {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspAntiData(FCSRspAntiData &msg, const msg::CSRspAntiData *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqTlogData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Data;

};
static void _ConvertPbToFCSReqTlogData(FCSReqTlogData &msg, const msg::CSReqTlogData *pb) {
	msg.Data=UTF8_TO_TCHAR(pb->data().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspTlogData {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspTlogData(FCSRspTlogData &msg, const msg::CSRspTlogData *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqDaySign {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqDaySign(FCSReqDaySign &msg, const msg::CSReqDaySign *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspDaySign {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Day;	//

};
static void _ConvertPbToFCSRspDaySign(FCSRspDaySign &msg, const msg::CSRspDaySign *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.Day=pb->day();
}


USTRUCT(BlueprintType)
struct  FCSReqActDaySign {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Day;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EActSignType Type;

};
static void _ConvertPbToFCSReqActDaySign(FCSReqActDaySign &msg, const msg::CSReqActDaySign *pb) {
	msg.GroupId=pb->groupid();
	msg.Day=pb->day();
	msg.Type=(EActSignType)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSRspActDaySign {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Day;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//补签消耗

};
static void _ConvertPbToFCSRspActDaySign(FCSRspActDaySign &msg, const msg::CSRspActDaySign *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.Day=pb->day();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqPsOnly {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PsOnly;	//

};
static void _ConvertPbToFCSReqPsOnly(FCSReqPsOnly &msg, const msg::CSReqPsOnly *pb) {
	msg.PsOnly=pb->psonly();
}


USTRUCT(BlueprintType)
struct  FCSRspPsOnly {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PsOnly;	//

};
static void _ConvertPbToFCSRspPsOnly(FCSRspPsOnly &msg, const msg::CSRspPsOnly *pb) {
	msg.PsOnly=pb->psonly();
}


USTRUCT(BlueprintType)
struct  FCSReqChangeChannelType {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

};
static void _ConvertPbToFCSReqChangeChannelType(FCSReqChangeChannelType &msg, const msg::CSReqChangeChannelType *pb) {
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
}


USTRUCT(BlueprintType)
struct  FCSRspChangeChannelType {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

};
static void _ConvertPbToFCSRspChangeChannelType(FCSRspChangeChannelType &msg, const msg::CSRspChangeChannelType *pb) {
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
}


USTRUCT(BlueprintType)
struct  FCSReqActivityMall {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	// 回流商店活动id

};
static void _ConvertPbToFCSReqActivityMall(FCSReqActivityMall &msg, const msg::CSReqActivityMall *pb) {
	msg.GroupId=pb->groupid();
}


USTRUCT(BlueprintType)
struct  FCSRspActivityMall {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FCSDTMallGoods> Goods;

};
static void _ConvertPbToFCSRspActivityMall(FCSRspActivityMall &msg, const msg::CSRspActivityMall *pb) {

    for (auto it = pb->goods().begin(); it != pb->goods().end(); it++) {
        FCSDTMallGoods tmp_value;
        _ConvertPbToFCSDTMallGoods(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Goods.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqDayFitAvoid {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Fit;	// 今日最宜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Avoid;	// 今日不宜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LuckyChess;	// 今日幸运棋子

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FortuneProverb;	// 今日棋运箴言

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FitAvoid;	// 今日幸运棋子

};
static void _ConvertPbToFCSReqDayFitAvoid(FCSReqDayFitAvoid &msg, const msg::CSReqDayFitAvoid *pb) {
	for (int i = 0; i < pb->fit().size(); i++) {
		auto &a = pb->fit().Get(i);
		int tmp;
		tmp=a;
		msg.Fit.Add(tmp);
	}
	for (int i = 0; i < pb->avoid().size(); i++) {
		auto &a = pb->avoid().Get(i);
		int tmp;
		tmp=a;
		msg.Avoid.Add(tmp);
	}
	msg.LuckyChess=pb->luckychess();
	msg.FortuneProverb=pb->fortuneproverb();
	msg.FitAvoid=pb->fitavoid();
}


USTRUCT(BlueprintType)
struct  FCSRspDayFitAvoid {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspDayFitAvoid(FCSRspDayFitAvoid &msg, const msg::CSRspDayFitAvoid *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqShareCountAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	// 累计次数

};
static void _ConvertPbToFCSReqShareCountAward(FCSReqShareCountAward &msg, const msg::CSReqShareCountAward *pb) {
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSRspShareCountAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAward AwardInfo;	//奖励

};
static void _ConvertPbToFCSRspShareCountAward(FCSRspShareCountAward &msg, const msg::CSRspShareCountAward *pb) {
	_ConvertPbToFAward(msg.AwardInfo, &pb->awardinfo());
}


USTRUCT(BlueprintType)
struct  FCSReqRealationStar {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString openid;	// openid

};
static void _ConvertPbToFCSReqRealationStar(FCSReqRealationStar &msg, const msg::CSReqRealationStar *pb) {
	msg.openid=UTF8_TO_TCHAR(pb->openid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspRealationStar {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspRealationStar(FCSRspRealationStar &msg, const msg::CSRspRealationStar *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetRealationStarInviteSucc {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetRealationStarInviteSucc(FCSReqGetRealationStarInviteSucc &msg, const msg::CSReqGetRealationStarInviteSucc *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetRealationStarInviteSucc {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> openids;	// openid

};
static void _ConvertPbToFCSRspGetRealationStarInviteSucc(FCSRspGetRealationStarInviteSucc &msg, const msg::CSRspGetRealationStarInviteSucc *pb) {
	for (int i = 0; i < pb->openids().size(); i++) {
		auto &a = pb->openids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.openids.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetRealationStar {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetRealationStar(FCSReqGetRealationStar &msg, const msg::CSReqGetRealationStar *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetRealationStar {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> openids;	// openid

};
static void _ConvertPbToFCSRspGetRealationStar(FCSRspGetRealationStar &msg, const msg::CSRspGetRealationStar *pb) {
	for (int i = 0; i < pb->openids().size(); i++) {
		auto &a = pb->openids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.openids.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetActRecord {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组id

};
static void _ConvertPbToFCSReqGetActRecord(FCSReqGetActRecord &msg, const msg::CSReqGetActRecord *pb) {
	msg.GroupId=pb->groupid();
}


USTRUCT(BlueprintType)
struct  FCSRspGetActRecord {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTActivityRecord Record;

};
static void _ConvertPbToFCSRspGetActRecord(FCSRspGetActRecord &msg, const msg::CSRspGetActRecord *pb) {
	msg.GroupId=pb->groupid();
	_ConvertPbToFCSDTActivityRecord(msg.Record, &pb->record());
}


USTRUCT(BlueprintType)
struct  FCSReqObserveLogin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;	//玩家游戏ID

	uint64 PvpId;	//pvp id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ApkVersion;	//apk版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpResourceVersion;	//资源版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//玩家等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChanelType;	//玩家渠道类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLATFORMTYPE PlatformType;	//玩家登录平台

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OpenId;	//玩家open id，国服玩家专有

	int64 GamelibVersion;	//新增内核版本号

};
static void _ConvertPbToFCSReqObserveLogin(FCSReqObserveLogin &msg, const msg::CSReqObserveLogin *pb) {
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.PvpId=pb->pvpid();
	msg.ApkVersion=UTF8_TO_TCHAR(pb->apkversion().c_str());
	msg.PvpResourceVersion=UTF8_TO_TCHAR(pb->pvpresourceversion().c_str());
	msg.Level=pb->level();
	msg.ChanelType=(ECHANELTYPE)pb->chaneltype();
	msg.PlatformType=(EPLATFORMTYPE)pb->platformtype();
	msg.OpenId=UTF8_TO_TCHAR(pb->openid().c_str());
	msg.GamelibVersion=pb->gamelibversion();
}


USTRUCT(BlueprintType)
struct  FCSRspObserveLogin {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxGameSecs;	//最大游戏时间 单位：秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeqUpdate;	//服务器帧同步频率 单位：毫秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPvpPlayerData> Players;	//pvp玩家信息 包含自己，且玩家索引在单局游戏内固定

	std::string TcpKey;	//tcp秘钥

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurSeq;	//当前最新帧序号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LoadingUILeftTime;	//loadingUI剩余等待时间 单位：秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ReadyPlayers;	//loadingUI界面中已经ready玩家

	int64 CreateTime;	//pvp创建时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LocalDistanceToUTC;	//当地时间与UTC时间相差秒数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MeleeRule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpSvrId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CustomSubMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTournamentPvp;	//是否是赛事房间

	uint64 TNClassRound;	//赛事轮次ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWorkshopSetting WSSetting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUserRestrictType RestrictType;	// 用户限制类型

	uint64 TournamentId;	//赛事id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeachPassId;	// 教学关卡ID

};
static void _ConvertPbToFCSRspObserveLogin(FCSRspObserveLogin &msg, const msg::CSRspObserveLogin *pb) {
	msg.PvpId=pb->pvpid();
	msg.MaxGameSecs=pb->maxgamesecs();
	msg.SeqUpdate=pb->sequpdate();
	for (int i = 0; i < pb->players().size(); i++) {
		auto &a = pb->players().Get(i);
		FPvpPlayerData tmp;
		_ConvertPbToFPvpPlayerData(tmp, &a);
		msg.Players.Add(tmp);
	}
	msg.TcpKey=pb->tcpkey();
	msg.CurSeq=pb->curseq();
	msg.LoadingUILeftTime=pb->loadinguilefttime();
	for (int i = 0; i < pb->readyplayers().size(); i++) {
		auto &a = pb->readyplayers().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ReadyPlayers.Add(tmp);
	}
	msg.CreateTime=pb->createtime();
	msg.LocalDistanceToUTC=pb->localdistancetoutc();
	msg.MeleeRule=pb->meleerule();
	msg.Mode=(EPVPMODE)pb->mode();
	msg.PvpSvrId=pb->pvpsvrid();
	msg.CustomSubMode=pb->customsubmode();
	msg.IsTournamentPvp=pb->istournamentpvp();
	msg.TNClassRound=pb->tnclassround();
	_ConvertPbToFWorkshopSetting(msg.WSSetting, &pb->wssetting());
	msg.RestrictType=(EUserRestrictType)pb->restricttype();
	msg.TournamentId=pb->tournamentid();
	msg.TeachPassId=pb->teachpassid();
}


USTRUCT(BlueprintType)
struct  FCSReqSetDefaultAttributes {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Head;	//默认头像

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Chess;	//默认棋手

};
static void _ConvertPbToFCSReqSetDefaultAttributes(FCSReqSetDefaultAttributes &msg, const msg::CSReqSetDefaultAttributes *pb) {
	msg.Head=pb->head();
	msg.Chess=pb->chess();
}


USTRUCT(BlueprintType)
struct  FCSRspSetDefaultAttributes {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetDefaultAttributes(FCSRspSetDefaultAttributes &msg, const msg::CSRspSetDefaultAttributes *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqChangeSlotTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Slot;

};
static void _ConvertPbToFCSReqChangeSlotTeam(FCSReqChangeSlotTeam &msg, const msg::CSReqChangeSlotTeam *pb) {
	msg.Slot=pb->slot();
}


USTRUCT(BlueprintType)
struct  FCSRspChangeSlotTeam {
	GENERATED_BODY()

	int64 NextChangeSlotTime;

};
static void _ConvertPbToFCSRspChangeSlotTeam(FCSRspChangeSlotTeam &msg, const msg::CSRspChangeSlotTeam *pb) {
	msg.NextChangeSlotTime=pb->nextchangeslottime();
}


USTRUCT(BlueprintType)
struct  FCSReqCancelChangeSlot {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DesId;

};
static void _ConvertPbToFCSReqCancelChangeSlot(FCSReqCancelChangeSlot &msg, const msg::CSReqCancelChangeSlot *pb) {
	msg.DesId=UTF8_TO_TCHAR(pb->desid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspCancelChangeSlot {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspCancelChangeSlot(FCSRspCancelChangeSlot &msg, const msg::CSRspCancelChangeSlot *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqChangeSubModeTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubMode;

};
static void _ConvertPbToFCSReqChangeSubModeTeam(FCSReqChangeSubModeTeam &msg, const msg::CSReqChangeSubModeTeam *pb) {
	msg.SubMode=pb->submode();
}


USTRUCT(BlueprintType)
struct  FCSRspChangeSubModeTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubMode;

};
static void _ConvertPbToFCSRspChangeSubModeTeam(FCSRspChangeSubModeTeam &msg, const msg::CSRspChangeSubModeTeam *pb) {
	msg.SubMode=pb->submode();
}


USTRUCT(BlueprintType)
struct  FCSReqConfirmChangeSlotTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IsAgree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SendUserId;

};
static void _ConvertPbToFCSReqConfirmChangeSlotTeam(FCSReqConfirmChangeSlotTeam &msg, const msg::CSReqConfirmChangeSlotTeam *pb) {
	msg.IsAgree=pb->isagree();
	msg.SendUserId=UTF8_TO_TCHAR(pb->senduserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspConfirmChangeSlotTeam {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspConfirmChangeSlotTeam(FCSRspConfirmChangeSlotTeam &msg, const msg::CSRspConfirmChangeSlotTeam *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqJoinVoiceTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;	// 腾讯语音使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSReqJoinVoiceTeam(FCSReqJoinVoiceTeam &msg, const msg::CSReqJoinVoiceTeam *pb) {
	msg.VoiceMemId=pb->voicememid();
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspJoinVoiceTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;	// 腾讯语音使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTeamVoicePlayer> VoicePlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSRspJoinVoiceTeam(FCSRspJoinVoiceTeam &msg, const msg::CSRspJoinVoiceTeam *pb) {
	msg.VoiceMemId=pb->voicememid();
	for (int i = 0; i < pb->voiceplayer().size(); i++) {
		auto &a = pb->voiceplayer().Get(i);
		FCSDTTeamVoicePlayer tmp;
		_ConvertPbToFCSDTTeamVoicePlayer(tmp, &a);
		msg.VoicePlayer.Add(tmp);
	}
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqJoinVoicePvp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;	// 腾讯语音使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSReqJoinVoicePvp(FCSReqJoinVoicePvp &msg, const msg::CSReqJoinVoicePvp *pb) {
	msg.VoiceMemId=pb->voicememid();
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspJoinVoicePvp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTeamVoicePlayer> VoicePlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSRspJoinVoicePvp(FCSRspJoinVoicePvp &msg, const msg::CSRspJoinVoicePvp *pb) {
	msg.VoiceMemId=pb->voicememid();
	for (int i = 0; i < pb->voiceplayer().size(); i++) {
		auto &a = pb->voiceplayer().Get(i);
		FCSDTTeamVoicePlayer tmp;
		_ConvertPbToFCSDTTeamVoicePlayer(tmp, &a);
		msg.VoicePlayer.Add(tmp);
	}
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqJoinVoiceCamp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;	// 腾讯语音使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSReqJoinVoiceCamp(FCSReqJoinVoiceCamp &msg, const msg::CSReqJoinVoiceCamp *pb) {
	msg.VoiceMemId=pb->voicememid();
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspJoinVoiceCamp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;	// 腾讯语音使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTeamVoicePlayer> VoicePlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSRspJoinVoiceCamp(FCSRspJoinVoiceCamp &msg, const msg::CSRspJoinVoiceCamp *pb) {
	msg.VoiceMemId=pb->voicememid();
	for (int i = 0; i < pb->voiceplayer().size(); i++) {
		auto &a = pb->voiceplayer().Get(i);
		FCSDTTeamVoicePlayer tmp;
		_ConvertPbToFCSDTTeamVoicePlayer(tmp, &a);
		msg.VoicePlayer.Add(tmp);
	}
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqUserCountrySet {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;

};
static void _ConvertPbToFCSReqUserCountrySet(FCSReqUserCountrySet &msg, const msg::CSReqUserCountrySet *pb) {
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqOfflineInviteJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOFFLINE_INVITE InviteType;	// 0: 微信分享邀请 1:手Q邀请(手Q拉起方式的邀请不需要发消息)

};
static void _ConvertPbToFCSReqOfflineInviteJoinTeam(FCSReqOfflineInviteJoinTeam &msg, const msg::CSReqOfflineInviteJoinTeam *pb) {
	msg.InviteType=(EOFFLINE_INVITE)pb->invitetype();
}


USTRUCT(BlueprintType)
struct  FCSRspUserCountrySet {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;

	int64 RefreshCountryTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTActivity Activity;	// 活动数据 第一次选定国家时发送

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMallTabData> MallTabs;	// 商城数据 第一次选定国家时发送

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Eggs;	// 扭蛋id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChangeCountryNumber;	// 修改国家的次数

};
static void _ConvertPbToFCSRspUserCountrySet(FCSRspUserCountrySet &msg, const msg::CSRspUserCountrySet *pb) {
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.RefreshCountryTime=pb->refreshcountrytime();
	_ConvertPbToFCSDTActivity(msg.Activity, &pb->activity());
	for (int i = 0; i < pb->malltabs().size(); i++) {
		auto &a = pb->malltabs().Get(i);
		FMallTabData tmp;
		_ConvertPbToFMallTabData(tmp, &a);
		msg.MallTabs.Add(tmp);
	}
	for (int i = 0; i < pb->eggs().size(); i++) {
		auto &a = pb->eggs().Get(i);
		int tmp;
		tmp=a;
		msg.Eggs.Add(tmp);
	}
	msg.ChangeCountryNumber=pb->changecountrynumber();
}


USTRUCT(BlueprintType)
struct  FCSReqMarkPlayerGuide {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewPlayerGuideFlag;	//

};
static void _ConvertPbToFCSReqMarkPlayerGuide(FCSReqMarkPlayerGuide &msg, const msg::CSReqMarkPlayerGuide *pb) {
	msg.NewPlayerGuideFlag=pb->newplayerguideflag();
}


USTRUCT(BlueprintType)
struct  FCSRspMarkPlayerGuide {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewPlayerGuideFlag;	// 新手引导(PC用)

	int64 NewPlayerGuideTime;	// 新手引导时间(PC用)

};
static void _ConvertPbToFCSRspMarkPlayerGuide(FCSRspMarkPlayerGuide &msg, const msg::CSRspMarkPlayerGuide *pb) {
	msg.NewPlayerGuideFlag=pb->newplayerguideflag();
	msg.NewPlayerGuideTime=pb->newplayerguidetime();
}


USTRUCT(BlueprintType)
struct  FCSReqMarkChessSkinClicked {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Skins;	//棋子皮肤ID(包括物品ID和InstanceId)

};
static void _ConvertPbToFCSReqMarkChessSkinClicked(FCSReqMarkChessSkinClicked &msg, const msg::CSReqMarkChessSkinClicked *pb) {
	for (int i = 0; i < pb->skins().size(); i++) {
		auto &a = pb->skins().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Skins.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspMarkChessSkinClicked {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Skins;	//

};
static void _ConvertPbToFCSRspMarkChessSkinClicked(FCSRspMarkChessSkinClicked &msg, const msg::CSRspMarkChessSkinClicked *pb) {
	for (int i = 0; i < pb->skins().size(); i++) {
		auto &a = pb->skins().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Skins.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqObserve {
	GENERATED_BODY()

	uint64 PvpId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Entrance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlatExtData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOBSERVELISTTYPE Type;

};
static void _ConvertPbToFCSReqObserve(FCSReqObserve &msg, const msg::CSReqObserve *pb) {
	msg.PvpId=pb->pvpid();
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.Entrance=UTF8_TO_TCHAR(pb->entrance().c_str());
	msg.Mode=(EPVPMODE)pb->mode();
	msg.PlatExtData=UTF8_TO_TCHAR(pb->platextdata().c_str());
	msg.Type=(EOBSERVELISTTYPE)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSRspObserve {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TcpAddr;

};
static void _ConvertPbToFCSRspObserve(FCSRspObserve &msg, const msg::CSRspObserve *pb) {
	msg.TcpAddr=UTF8_TO_TCHAR(pb->tcpaddr().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqGetRecommendPvp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinCup;	//推荐玩家最小段位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxCup;	//推荐玩家最大段位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Mode;	//-1表示默认模式，即按比例展示

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOBSERVELISTTYPE Type;	//观战列表类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	//如果是关注推荐，关注列表玩家ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Start;	//废弃

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> ModeIndex;	//拉取推荐观战的位置,每个mode从index开始拉去。key是mode, value是mode排序的Index

};
static void _ConvertPbToFCSReqGetRecommendPvp(FCSReqGetRecommendPvp &msg, const msg::CSReqGetRecommendPvp *pb) {
	msg.MinCup=pb->mincup();
	msg.MaxCup=pb->maxcup();
	msg.Mode=pb->mode();
	msg.Type=(EOBSERVELISTTYPE)pb->type();
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
	msg.Start=pb->start();

    for (auto it = pb->modeindex().begin(); it != pb->modeindex().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.ModeIndex.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSRspGetRecommendPvp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTRecommendPvpInfo> Recommends;	//推荐战局

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOBSERVELISTTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> ModeIndex;	//拉取推荐观战的位置。key 是mode,value是mode排序的Index

};
static void _ConvertPbToFCSRspGetRecommendPvp(FCSRspGetRecommendPvp &msg, const msg::CSRspGetRecommendPvp *pb) {
	for (int i = 0; i < pb->recommends().size(); i++) {
		auto &a = pb->recommends().Get(i);
		FCSDTRecommendPvpInfo tmp;
		_ConvertPbToFCSDTRecommendPvpInfo(tmp, &a);
		msg.Recommends.Add(tmp);
	}
	msg.Type=(EOBSERVELISTTYPE)pb->type();

    for (auto it = pb->modeindex().begin(); it != pb->modeindex().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.ModeIndex.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqQuitObserve {
	GENERATED_BODY()

	uint64 PvpId;

};
static void _ConvertPbToFCSReqQuitObserve(FCSReqQuitObserve &msg, const msg::CSReqQuitObserve *pb) {
	msg.PvpId=pb->pvpid();
}


USTRUCT(BlueprintType)
struct  FCSRspQuitObserve {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspQuitObserve(FCSRspQuitObserve &msg, const msg::CSRspQuitObserve *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetObserveInfo {
	GENERATED_BODY()

	TArray<uint64> PvpIds;

};
static void _ConvertPbToFCSReqGetObserveInfo(FCSReqGetObserveInfo &msg, const msg::CSReqGetObserveInfo *pb) {
	for (int i = 0; i < pb->pvpids().size(); i++) {
		auto &a = pb->pvpids().Get(i);
		uint64 tmp;
		tmp=a;
		msg.PvpIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspGetObserveInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTObserveInfo> Info;

};
static void _ConvertPbToFCSRspGetObserveInfo(FCSRspGetObserveInfo &msg, const msg::CSRspGetObserveInfo *pb) {
	for (int i = 0; i < pb->info().size(); i++) {
		auto &a = pb->info().Get(i);
		FCSDTObserveInfo tmp;
		_ConvertPbToFCSDTObserveInfo(tmp, &a);
		msg.Info.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetThirdPvpInfo {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetThirdPvpInfo(FCSReqGetThirdPvpInfo &msg, const msg::CSReqGetThirdPvpInfo *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetThirdPvpInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTThirdPvpInfo> Info;

};
static void _ConvertPbToFCSRspGetThirdPvpInfo(FCSRspGetThirdPvpInfo &msg, const msg::CSRspGetThirdPvpInfo *pb) {
	for (int i = 0; i < pb->info().size(); i++) {
		auto &a = pb->info().Get(i);
		FCSDTThirdPvpInfo tmp;
		_ConvertPbToFCSDTThirdPvpInfo(tmp, &a);
		msg.Info.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqHaveThirdPvp {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqHaveThirdPvp(FCSReqHaveThirdPvp &msg, const msg::CSReqHaveThirdPvp *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspHaveThirdPvp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool have;

};
static void _ConvertPbToFCSRspHaveThirdPvp(FCSRspHaveThirdPvp &msg, const msg::CSRspHaveThirdPvp *pb) {
	msg.have=pb->have();
}


USTRUCT(BlueprintType)
struct  FCSReqSetPushToken {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FCMToken;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MobToken;

};
static void _ConvertPbToFCSReqSetPushToken(FCSReqSetPushToken &msg, const msg::CSReqSetPushToken *pb) {
	msg.FCMToken=UTF8_TO_TCHAR(pb->fcmtoken().c_str());
	msg.MobToken=UTF8_TO_TCHAR(pb->mobtoken().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSetPushToken {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetPushToken(FCSRspSetPushToken &msg, const msg::CSRspSetPushToken *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqWxVVipAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWxVVipAwardTYPE AwardType;	//奖励类型

};
static void _ConvertPbToFCSReqWxVVipAward(FCSReqWxVVipAward &msg, const msg::CSReqWxVVipAward *pb) {
	msg.AwardType=(EWxVVipAwardTYPE)pb->awardtype();
}


USTRUCT(BlueprintType)
struct  FCSRspWxVVipAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWxVVipAwardTYPE AwardType;	//奖励类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//实际奖励

	int64 Tick;	//奖励领取时间戳

};
static void _ConvertPbToFCSRspWxVVipAward(FCSRspWxVVipAward &msg, const msg::CSRspWxVVipAward *pb) {
	msg.AwardType=(EWxVVipAwardTYPE)pb->awardtype();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.Tick=pb->tick();
}


USTRUCT(BlueprintType)
struct  FCSReqGetRelationStarWX {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetRelationStarWX(FCSReqGetRelationStarWX &msg, const msg::CSReqGetRelationStarWX *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetRelationStarWX {
	GENERATED_BODY()

	std::string data;	//关系链数据

};
static void _ConvertPbToFCSRspGetRelationStarWX(FCSRspGetRelationStarWX &msg, const msg::CSRspGetRelationStarWX *pb) {
	msg.data=pb->data();
}


USTRUCT(BlueprintType)
struct  FCSReqSendWxRedPacket {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RedPacketId;	//红包配表id

};
static void _ConvertPbToFCSReqSendWxRedPacket(FCSReqSendWxRedPacket &msg, const msg::CSReqSendWxRedPacket *pb) {
	msg.RedPacketId=pb->redpacketid();
}


USTRUCT(BlueprintType)
struct  FCSRspSendWxRedPacket {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SendCnt;	//当天发送红包次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

};
static void _ConvertPbToFCSRspSendWxRedPacket(FCSRspSendWxRedPacket &msg, const msg::CSRspSendWxRedPacket *pb) {
	msg.SendCnt=pb->sendcnt();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqRecvWxRedPacket {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RedPacketIdx;	//红包索引

};
static void _ConvertPbToFCSReqRecvWxRedPacket(FCSReqRecvWxRedPacket &msg, const msg::CSReqRecvWxRedPacket *pb) {
	msg.RedPacketIdx=UTF8_TO_TCHAR(pb->redpacketidx().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspRecvWxRedPacket {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RedPacketIdx;	//红包索引

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RedPacketId;	//红包ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Sender;	//发红包玩家名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Award;	//领取金额

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecvCnt;	//当天领取红包次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTRedPktData> RedPktRecord;	//红包领取排行

};
static void _ConvertPbToFCSRspRecvWxRedPacket(FCSRspRecvWxRedPacket &msg, const msg::CSRspRecvWxRedPacket *pb) {
	msg.RedPacketIdx=UTF8_TO_TCHAR(pb->redpacketidx().c_str());
	msg.RedPacketId=pb->redpacketid();
	msg.Sender=UTF8_TO_TCHAR(pb->sender().c_str());
	msg.Award=pb->award();
	msg.RecvCnt=pb->recvcnt();
	for (int i = 0; i < pb->redpktrecord().size(); i++) {
		auto &a = pb->redpktrecord().Get(i);
		FCSDTRedPktData tmp;
		_ConvertPbToFCSDTRedPktData(tmp, &a);
		msg.RedPktRecord.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqWxRedPktLike {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UId;

};
static void _ConvertPbToFCSReqWxRedPktLike(FCSReqWxRedPktLike &msg, const msg::CSReqWxRedPktLike *pb) {
	msg.UId=UTF8_TO_TCHAR(pb->uid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspWxRedPktLike {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFCSRspWxRedPktLike(FCSRspWxRedPktLike &msg, const msg::CSRspWxRedPktLike *pb) {
	msg.UId=UTF8_TO_TCHAR(pb->uid().c_str());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqWxRedPktRank {
	GENERATED_BODY()

	int64 Ver;	//版本号，初始传0

};
static void _ConvertPbToFCSReqWxRedPktRank(FCSReqWxRedPktRank &msg, const msg::CSReqWxRedPktRank *pb) {
	msg.Ver=pb->ver();
}


USTRUCT(BlueprintType)
struct  FCSRspWxRedPktRank {
	GENERATED_BODY()

	int64 Ver;	//版本号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTWxVVipRankItem> Rank;	//排行

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTWxRedPktProfile Self;	//玩家自己信息

};
static void _ConvertPbToFCSRspWxRedPktRank(FCSRspWxRedPktRank &msg, const msg::CSRspWxRedPktRank *pb) {
	msg.Ver=pb->ver();
	for (int i = 0; i < pb->rank().size(); i++) {
		auto &a = pb->rank().Get(i);
		FCSDTWxVVipRankItem tmp;
		_ConvertPbToFCSDTWxVVipRankItem(tmp, &a);
		msg.Rank.Add(tmp);
	}
	_ConvertPbToFCSDTWxRedPktProfile(msg.Self, &pb->self());
}


USTRUCT(BlueprintType)
struct  FCSReqObservePrivilege {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOBSERVEPRIVILEGE ObservePrivilege;

};
static void _ConvertPbToFCSReqObservePrivilege(FCSReqObservePrivilege &msg, const msg::CSReqObservePrivilege *pb) {
	msg.ObservePrivilege=(EOBSERVEPRIVILEGE)pb->observeprivilege();
}


USTRUCT(BlueprintType)
struct  FCSRspObservePrivilege {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspObservePrivilege(FCSRspObservePrivilege &msg, const msg::CSRspObservePrivilege *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPresetFastChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ChatIds;	//预设文本序号

};
static void _ConvertPbToFCSReqPresetFastChat(FCSReqPresetFastChat &msg, const msg::CSReqPresetFastChat *pb) {
	for (int i = 0; i < pb->chatids().size(); i++) {
		auto &a = pb->chatids().Get(i);
		int tmp;
		tmp=a;
		msg.ChatIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspPresetFastChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ChatIds;	//预设文本序号

};
static void _ConvertPbToFCSRspPresetFastChat(FCSRspPresetFastChat &msg, const msg::CSRspPresetFastChat *pb) {
	for (int i = 0; i < pb->chatids().size(); i++) {
		auto &a = pb->chatids().Get(i);
		int tmp;
		tmp=a;
		msg.ChatIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqPvpConfirm {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Confirm;	//true-确认，false-拒绝

};
static void _ConvertPbToFCSReqPvpConfirm(FCSReqPvpConfirm &msg, const msg::CSReqPvpConfirm *pb) {
	msg.Confirm=pb->confirm();
}


USTRUCT(BlueprintType)
struct  FCSReqActivityPicShare {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActivityId;

};
static void _ConvertPbToFCSReqActivityPicShare(FCSReqActivityPicShare &msg, const msg::CSReqActivityPicShare *pb) {
	msg.GroupId=pb->groupid();
	msg.ActivityId=pb->activityid();
}


USTRUCT(BlueprintType)
struct  FCSReqBindOldBusinessPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BusinessId;

};
static void _ConvertPbToFCSReqBindOldBusinessPlayer(FCSReqBindOldBusinessPlayer &msg, const msg::CSReqBindOldBusinessPlayer *pb) {
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.BusinessId=UTF8_TO_TCHAR(pb->businessid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspBindOldBusinessPlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspBindOldBusinessPlayer(FCSRspBindOldBusinessPlayer &msg, const msg::CSRspBindOldBusinessPlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqTranslate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tolangue;

};
static void _ConvertPbToFCSReqTranslate(FCSReqTranslate &msg, const msg::CSReqTranslate *pb) {
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.Tolangue=UTF8_TO_TCHAR(pb->tolangue().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspTranslate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TranslateStr;

};
static void _ConvertPbToFCSRspTranslate(FCSRspTranslate &msg, const msg::CSRspTranslate *pb) {
	msg.TranslateStr=UTF8_TO_TCHAR(pb->translatestr().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqSubmitQuestionnaire {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	// 问卷id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAnswerData> Answers;	// 问卷答案

};
static void _ConvertPbToFCSReqSubmitQuestionnaire(FCSReqSubmitQuestionnaire &msg, const msg::CSReqSubmitQuestionnaire *pb) {
	msg.ID=pb->id();
	for (int i = 0; i < pb->answers().size(); i++) {
		auto &a = pb->answers().Get(i);
		FAnswerData tmp;
		_ConvertPbToFAnswerData(tmp, &a);
		msg.Answers.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspSubmitQuestionnaire {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	// 问卷id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	// 奖励

};
static void _ConvertPbToFCSRspSubmitQuestionnaire(FCSRspSubmitQuestionnaire &msg, const msg::CSRspSubmitQuestionnaire *pb) {
	msg.ID=pb->id();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqSetChessSkin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItemID ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessId;	//棋子id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	//星级，槽位 0,1,2

};
static void _ConvertPbToFCSReqSetChessSkin(FCSReqSetChessSkin &msg, const msg::CSReqSetChessSkin *pb) {
	_ConvertPbToFCSDTItemID(msg.ItemId, &pb->itemid());
	msg.ChessId=pb->chessid();
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSetChessSkin {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetChessSkin(FCSRspSetChessSkin &msg, const msg::CSRspSetChessSkin *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUnsetChessSkin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;	//系列ID, @update.beta28 弃用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessId;	//棋子id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	//星级，槽位 0,1,2

};
static void _ConvertPbToFCSReqUnsetChessSkin(FCSReqUnsetChessSkin &msg, const msg::CSReqUnsetChessSkin *pb) {
	msg.ItemId=pb->itemid();
	msg.ChessId=pb->chessid();
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUnsetChessSkin {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUnsetChessSkin(FCSRspUnsetChessSkin &msg, const msg::CSRspUnsetChessSkin *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqCompose {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ComposeId;	//合成ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗的材料

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ComposeCount;	//合成数量

};
static void _ConvertPbToFCSReqCompose(FCSReqCompose &msg, const msg::CSReqCompose *pb) {
	msg.ComposeId=pb->composeid();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.ComposeCount=pb->composecount();
}


USTRUCT(BlueprintType)
struct  FCSRspCompose {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//合成的物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗的材料

};
static void _ConvertPbToFCSRspCompose(FCSRspCompose &msg, const msg::CSRspCompose *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqOffHelpReddot {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqOffHelpReddot(FCSReqOffHelpReddot &msg, const msg::CSReqOffHelpReddot *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspOffHelpReddot {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspOffHelpReddot(FCSRspOffHelpReddot &msg, const msg::CSRspOffHelpReddot *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqChangeLanguage {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Language;

};
static void _ConvertPbToFCSReqChangeLanguage(FCSReqChangeLanguage &msg, const msg::CSReqChangeLanguage *pb) {
	msg.Language=UTF8_TO_TCHAR(pb->language().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspChangeLanguage {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspChangeLanguage(FCSRspChangeLanguage &msg, const msg::CSRspChangeLanguage *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetPvpServerGroup {
	GENERATED_BODY()

	int64 RequestTime;	//请求时间

};
static void _ConvertPbToFCSReqGetPvpServerGroup(FCSReqGetPvpServerGroup &msg, const msg::CSReqGetPvpServerGroup *pb) {
	msg.RequestTime=pb->requesttime();
}


USTRUCT(BlueprintType)
struct  FCSRspGetPvpServerGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GroupId;	//战斗服分组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ServerId;

};
static void _ConvertPbToFCSRspGetPvpServerGroup(FCSRspGetPvpServerGroup &msg, const msg::CSRspGetPvpServerGroup *pb) {
	msg.GroupId=UTF8_TO_TCHAR(pb->groupid().c_str());
	msg.ServerId=pb->serverid();
}


USTRUCT(BlueprintType)
struct  FCSReqReportPvpInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Group;	//战斗分组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ping;

};
static void _ConvertPbToFCSReqReportPvpInfo(FCSReqReportPvpInfo &msg, const msg::CSReqReportPvpInfo *pb) {
	msg.Group=UTF8_TO_TCHAR(pb->group().c_str());
	msg.Ping=pb->ping();
}


USTRUCT(BlueprintType)
struct  FCSRspReportPvpInfo {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspReportPvpInfo(FCSRspReportPvpInfo &msg, const msg::CSRspReportPvpInfo *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqVideo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Ids;	// 请求视频的id列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	// 请求视频序号

};
static void _ConvertPbToFCSReqVideo(FCSReqVideo &msg, const msg::CSReqVideo *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		int tmp;
		tmp=a;
		msg.Ids.Add(tmp);
	}
	msg.Index=pb->index();
}


USTRUCT(BlueprintType)
struct  FCSRspVideo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVideoInfo> List;	// 视频列表

};
static void _ConvertPbToFCSRspVideo(FCSRspVideo &msg, const msg::CSRspVideo *pb) {
	for (int i = 0; i < pb->list().size(); i++) {
		auto &a = pb->list().Get(i);
		FVideoInfo tmp;
		_ConvertPbToFVideoInfo(tmp, &a);
		msg.List.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqReportVideoPlay {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// 播放的id

};
static void _ConvertPbToFCSReqReportVideoPlay(FCSReqReportVideoPlay &msg, const msg::CSReqReportVideoPlay *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSReqSetProvince {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Province;	//省份

};
static void _ConvertPbToFCSReqSetProvince(FCSReqSetProvince &msg, const msg::CSReqSetProvince *pb) {
	msg.Province=pb->province();
}


USTRUCT(BlueprintType)
struct  FCSRspSetProvince {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Province;	// 省份

	int64 NextTime;	// 下次可以免费设置省份的时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Times;	// 已经设置省份的次数

};
static void _ConvertPbToFCSRspSetProvince(FCSRspSetProvince &msg, const msg::CSRspSetProvince *pb) {
	msg.Province=pb->province();
	msg.NextTime=pb->nexttime();
	msg.Times=pb->times();
}


USTRUCT(BlueprintType)
struct  FCSReqLongyuanVoice {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqLongyuanVoice(FCSReqLongyuanVoice &msg, const msg::CSReqLongyuanVoice *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspLongyuanVoice {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AppId;	// 语音APPID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AppKey;	// 语音KEY

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Region;	// 大区

};
static void _ConvertPbToFCSRspLongyuanVoice(FCSRspLongyuanVoice &msg, const msg::CSRspLongyuanVoice *pb) {
	msg.AppId=UTF8_TO_TCHAR(pb->appid().c_str());
	msg.AppKey=UTF8_TO_TCHAR(pb->appkey().c_str());
	msg.Region=UTF8_TO_TCHAR(pb->region().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqInviteCodeReset {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqInviteCodeReset(FCSReqInviteCodeReset &msg, const msg::CSReqInviteCodeReset *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspInviteCodeReset {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BlackboxInviteCode;

	int64 ResetCD;	// 重置冷却时间 UTC unix时间戳

};
static void _ConvertPbToFCSRspInviteCodeReset(FCSRspInviteCodeReset &msg, const msg::CSRspInviteCodeReset *pb) {
	msg.BlackboxInviteCode=UTF8_TO_TCHAR(pb->blackboxinvitecode().c_str());
	msg.ResetCD=pb->resetcd();
}


USTRUCT(BlueprintType)
struct  FCSReqPingTest {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqPingTest(FCSReqPingTest &msg, const msg::CSReqPingTest *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspPingTest {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPingTest(FCSRspPingTest &msg, const msg::CSRspPingTest *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqWebLogin {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqWebLogin(FCSReqWebLogin &msg, const msg::CSReqWebLogin *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspWebLogin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Uuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Url;	//服务器回调的url

	std::string Key;	//秘钥

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WebLoginUrl;	//网页登录的地址

};
static void _ConvertPbToFCSRspWebLogin(FCSRspWebLogin &msg, const msg::CSRspWebLogin *pb) {
	msg.Uuid=UTF8_TO_TCHAR(pb->uuid().c_str());
	msg.Url=UTF8_TO_TCHAR(pb->url().c_str());
	msg.Key=pb->key();
	msg.WebLoginUrl=UTF8_TO_TCHAR(pb->webloginurl().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqSwitchModeInTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE NewMode;

};
static void _ConvertPbToFCSReqSwitchModeInTeam(FCSReqSwitchModeInTeam &msg, const msg::CSReqSwitchModeInTeam *pb) {
	msg.NewMode=(EPVPMODE)pb->newmode();
}


USTRUCT(BlueprintType)
struct  FCSRspSwitchModeInTeam {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSwitchModeInTeam(FCSRspSwitchModeInTeam &msg, const msg::CSRspSwitchModeInTeam *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetTNRoomState {
	GENERATED_BODY()

	uint64 TournamentID;

};
static void _ConvertPbToFCSReqGetTNRoomState(FCSReqGetTNRoomState &msg, const msg::CSReqGetTNRoomState *pb) {
	msg.TournamentID=pb->tournamentid();
}


USTRUCT(BlueprintType)
struct  FCSRspGetTNRoomState {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETeamState State;

};
static void _ConvertPbToFCSRspGetTNRoomState(FCSRspGetTNRoomState &msg, const msg::CSRspGetTNRoomState *pb) {
	msg.State=(ETeamState)pb->state();
}


USTRUCT(BlueprintType)
struct  FCSReqWorkshopMatch {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapId;	// 地图id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubMapId;	// 子模式id

};
static void _ConvertPbToFCSReqWorkshopMatch(FCSReqWorkshopMatch &msg, const msg::CSReqWorkshopMatch *pb) {
	msg.MapId=pb->mapid();
	msg.SubMapId=pb->submapid();
}


USTRUCT(BlueprintType)
struct  FCSRspWorkshopMatch {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamID;

};
static void _ConvertPbToFCSRspWorkshopMatch(FCSRspWorkshopMatch &msg, const msg::CSRspWorkshopMatch *pb) {
	msg.Success=pb->success();
	msg.TeamID=pb->teamid();
}


USTRUCT(BlueprintType)
struct  FCSReqBuyWorkshopTicket {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TicketType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TicketCount;

};
static void _ConvertPbToFCSReqBuyWorkshopTicket(FCSReqBuyWorkshopTicket &msg, const msg::CSReqBuyWorkshopTicket *pb) {
	msg.TicketType=pb->tickettype();
	msg.TicketCount=pb->ticketcount();
}


USTRUCT(BlueprintType)
struct  FCSRspBuyWorkshopTicket {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TicketType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurTicketCount;

};
static void _ConvertPbToFCSRspBuyWorkshopTicket(FCSRspBuyWorkshopTicket &msg, const msg::CSRspBuyWorkshopTicket *pb) {
	msg.TicketType=pb->tickettype();
	msg.CurTicketCount=pb->curticketcount();
}


USTRUCT(BlueprintType)
struct  FCSReqFavouriteWorkshopMap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFavourite;	// 收藏: true, 取消收藏: false

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapID;

};
static void _ConvertPbToFCSReqFavouriteWorkshopMap(FCSReqFavouriteWorkshopMap &msg, const msg::CSReqFavouriteWorkshopMap *pb) {
	msg.IsFavourite=pb->isfavourite();
	msg.MapID=pb->mapid();
}


USTRUCT(BlueprintType)
struct  FCSRspFavouriteWorkshopMap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

};
static void _ConvertPbToFCSRspFavouriteWorkshopMap(FCSRspFavouriteWorkshopMap &msg, const msg::CSRspFavouriteWorkshopMap *pb) {
	msg.Success=pb->success();
}


USTRUCT(BlueprintType)
struct  FCSReqShortcutMapsOP {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EShortcutMapsOP OP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> MapIDs;

};
static void _ConvertPbToFCSReqShortcutMapsOP(FCSReqShortcutMapsOP &msg, const msg::CSReqShortcutMapsOP *pb) {
	msg.OP=(EShortcutMapsOP)pb->op();
	for (int i = 0; i < pb->mapids().size(); i++) {
		auto &a = pb->mapids().Get(i);
		int tmp;
		tmp=a;
		msg.MapIDs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspShortcutMapsOP {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

};
static void _ConvertPbToFCSRspShortcutMapsOP(FCSRspShortcutMapsOP &msg, const msg::CSRspShortcutMapsOP *pb) {
	msg.Success=pb->success();
}


USTRUCT(BlueprintType)
struct  FCSReqScoreWorkshopMap {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsLike;	// true: 赞，false：踩

};
static void _ConvertPbToFCSReqScoreWorkshopMap(FCSReqScoreWorkshopMap &msg, const msg::CSReqScoreWorkshopMap *pb) {
	msg.MapID=pb->mapid();
	msg.IsLike=pb->islike();
}


USTRUCT(BlueprintType)
struct  FCSRspScoreWorkshopMap {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspScoreWorkshopMap(FCSRspScoreWorkshopMap &msg, const msg::CSRspScoreWorkshopMap *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqMapsVisitedByFriends {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> MapIDs;

};
static void _ConvertPbToFCSReqMapsVisitedByFriends(FCSReqMapsVisitedByFriends &msg, const msg::CSReqMapsVisitedByFriends *pb) {
	for (int i = 0; i < pb->mapids().size(); i++) {
		auto &a = pb->mapids().Get(i);
		int tmp;
		tmp=a;
		msg.MapIDs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspMapsVisitedByFriends {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FVisitMapPlayers> Maps;

};
static void _ConvertPbToFCSRspMapsVisitedByFriends(FCSRspMapsVisitedByFriends &msg, const msg::CSRspMapsVisitedByFriends *pb) {

    for (auto it = pb->maps().begin(); it != pb->maps().end(); it++) {
        FVisitMapPlayers tmp_value;
        _ConvertPbToFVisitMapPlayers(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Maps.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfTNGameEnd {
	GENERATED_BODY()

	int64 NextGameStartTime;	// -1表示不存在下一局

	uint64 TournamentID;

	uint64 TournamentGameID;

};
static void _ConvertPbToFCSNtfTNGameEnd(FCSNtfTNGameEnd &msg, const msg::CSNtfTNGameEnd *pb) {
	msg.NextGameStartTime=pb->nextgamestarttime();
	msg.TournamentID=pb->tournamentid();
	msg.TournamentGameID=pb->tournamentgameid();
}


USTRUCT(BlueprintType)
struct  FCSNtfPlayerLackResourceInTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> LackTicketPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> LackBountyPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> LackMoneyPlayers;

};
static void _ConvertPbToFCSNtfPlayerLackResourceInTeam(FCSNtfPlayerLackResourceInTeam &msg, const msg::CSNtfPlayerLackResourceInTeam *pb) {
	for (int i = 0; i < pb->lackticketplayers().size(); i++) {
		auto &a = pb->lackticketplayers().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.LackTicketPlayers.Add(tmp);
	}
	for (int i = 0; i < pb->lackbountyplayers().size(); i++) {
		auto &a = pb->lackbountyplayers().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.LackBountyPlayers.Add(tmp);
	}
	for (int i = 0; i < pb->lackmoneyplayers().size(); i++) {
		auto &a = pb->lackmoneyplayers().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.LackMoneyPlayers.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfFavMapRemoved {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> MapIDs;

};
static void _ConvertPbToFCSNtfFavMapRemoved(FCSNtfFavMapRemoved &msg, const msg::CSNtfFavMapRemoved *pb) {
	for (int i = 0; i < pb->mapids().size(); i++) {
		auto &a = pb->mapids().Get(i);
		int tmp;
		tmp=a;
		msg.MapIDs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfWorkshopMatchResult {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamID;

};
static void _ConvertPbToFCSNtfWorkshopMatchResult(FCSNtfWorkshopMatchResult &msg, const msg::CSNtfWorkshopMatchResult *pb) {
	msg.Success=pb->success();
	msg.TeamID=pb->teamid();
}


USTRUCT(BlueprintType)
struct  FCSReqChoosePlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;	//选择的角色

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPSBind;

};
static void _ConvertPbToFCSReqChoosePlayer(FCSReqChoosePlayer &msg, const msg::CSReqChoosePlayer *pb) {
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.IsPSBind=pb->ispsbind();
}


USTRUCT(BlueprintType)
struct  FCSRspChoosePlayer {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspChoosePlayer(FCSRspChoosePlayer &msg, const msg::CSRspChoosePlayer *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqReportRegionInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTReportRegionInfo> RegionInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> Groups;	//ping值延迟信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> TCPGroups;	//tcp延迟信息

};
static void _ConvertPbToFCSReqReportRegionInfo(FCSReqReportRegionInfo &msg, const msg::CSReqReportRegionInfo *pb) {
	for (int i = 0; i < pb->regioninfo().size(); i++) {
		auto &a = pb->regioninfo().Get(i);
		FCSDTReportRegionInfo tmp;
		_ConvertPbToFCSDTReportRegionInfo(tmp, &a);
		msg.RegionInfo.Add(tmp);
	}

    for (auto it = pb->groups().begin(); it != pb->groups().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Groups.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->tcpgroups().begin(); it != pb->tcpgroups().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.TCPGroups.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSRspReportRegionInfo {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspReportRegionInfo(FCSRspReportRegionInfo &msg, const msg::CSRspReportRegionInfo *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSwitchToCommonMatch {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqSwitchToCommonMatch(FCSReqSwitchToCommonMatch &msg, const msg::CSReqSwitchToCommonMatch *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspSwitchToCommonMatch {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExceptSecs;	//预期匹配时间 单位：秒

};
static void _ConvertPbToFCSRspSwitchToCommonMatch(FCSRspSwitchToCommonMatch &msg, const msg::CSRspSwitchToCommonMatch *pb) {
	msg.ExceptSecs=pb->exceptsecs();
}


USTRUCT(BlueprintType)
struct  FCSReqEnrollTournament {
	GENERATED_BODY()

	uint64 TournamentId;	//赛事ID

	uint64 ClassId;	//级别ID

};
static void _ConvertPbToFCSReqEnrollTournament(FCSReqEnrollTournament &msg, const msg::CSReqEnrollTournament *pb) {
	msg.TournamentId=pb->tournamentid();
	msg.ClassId=pb->classid();
}


USTRUCT(BlueprintType)
struct  FCSRspEnrollTournament {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//报名消耗的物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EnrollCount;	//报名人数

};
static void _ConvertPbToFCSRspEnrollTournament(FCSRspEnrollTournament &msg, const msg::CSRspEnrollTournament *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.EnrollCount=pb->enrollcount();
}


USTRUCT(BlueprintType)
struct  FCSReqJoinTournamentRoom {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTournamentDesc Desc;

};
static void _ConvertPbToFCSReqJoinTournamentRoom(FCSReqJoinTournamentRoom &msg, const msg::CSReqJoinTournamentRoom *pb) {
	_ConvertPbToFTournamentDesc(msg.Desc, &pb->desc());
}


USTRUCT(BlueprintType)
struct  FCSRspJoinTournamentRoom {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTournamentRoom RoomInfo;

};
static void _ConvertPbToFCSRspJoinTournamentRoom(FCSRspJoinTournamentRoom &msg, const msg::CSRspJoinTournamentRoom *pb) {
	_ConvertPbToFTournamentRoom(msg.RoomInfo, &pb->roominfo());
}


USTRUCT(BlueprintType)
struct  FCSNtfJoinTournamentRoom {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfJoinTournamentRoom(FCSNtfJoinTournamentRoom &msg, const msg::CSNtfJoinTournamentRoom *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGDCommonBin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLATFORMTYPE PlatFormType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

};
static void _ConvertPbToFCSReqGDCommonBin(FCSReqGDCommonBin &msg, const msg::CSReqGDCommonBin *pb) {
	msg.PlatFormType=(EPLATFORMTYPE)pb->platformtype();
	msg.ChannelId=UTF8_TO_TCHAR(pb->channelid().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
}


USTRUCT(BlueprintType)
struct  FCSRspGDCommonBin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTGDCommonBin> Bins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpResourceVersion;

};
static void _ConvertPbToFCSRspGDCommonBin(FCSRspGDCommonBin &msg, const msg::CSRspGDCommonBin *pb) {
	for (int i = 0; i < pb->bins().size(); i++) {
		auto &a = pb->bins().Get(i);
		FCSDTGDCommonBin tmp;
		_ConvertPbToFCSDTGDCommonBin(tmp, &a);
		msg.Bins.Add(tmp);
	}
	msg.PvpResourceVersion=UTF8_TO_TCHAR(pb->pvpresourceversion().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqGDCommonBinData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FileNames;	//请求文件列表中data数据 带后缀

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGDBinType BinTyp;	// 是否内核战斗配置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPLATFORMTYPE PlatFormType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

};
static void _ConvertPbToFCSReqGDCommonBinData(FCSReqGDCommonBinData &msg, const msg::CSReqGDCommonBinData *pb) {
	msg.FileNames=UTF8_TO_TCHAR(pb->filenames().c_str());
	msg.BinTyp=(EGDBinType)pb->bintyp();
	msg.PlatFormType=(EPLATFORMTYPE)pb->platformtype();
	msg.ChannelId=UTF8_TO_TCHAR(pb->channelid().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
}


USTRUCT(BlueprintType)
struct  FCSRspGDCommonBinData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTGDCommonBin> Bins;

};
static void _ConvertPbToFCSRspGDCommonBinData(FCSRspGDCommonBinData &msg, const msg::CSRspGDCommonBinData *pb) {
	for (int i = 0; i < pb->bins().size(); i++) {
		auto &a = pb->bins().Get(i);
		FCSDTGDCommonBin tmp;
		_ConvertPbToFCSDTGDCommonBin(tmp, &a);
		msg.Bins.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqAutoBattleOP {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString crossData;

};
static void _ConvertPbToFCSReqAutoBattleOP(FCSReqAutoBattleOP &msg, const msg::CSReqAutoBattleOP *pb) {
	msg.crossData=UTF8_TO_TCHAR(pb->crossdata().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspAutoBattleOP {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString crossData;

};
static void _ConvertPbToFCSRspAutoBattleOP(FCSRspAutoBattleOP &msg, const msg::CSRspAutoBattleOP *pb) {
	msg.crossData=UTF8_TO_TCHAR(pb->crossdata().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqEquipSelectRate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString crossData;

};
static void _ConvertPbToFCSReqEquipSelectRate(FCSReqEquipSelectRate &msg, const msg::CSReqEquipSelectRate *pb) {
	msg.crossData=UTF8_TO_TCHAR(pb->crossdata().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspEquipSelectRate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString crossData;

};
static void _ConvertPbToFCSRspEquipSelectRate(FCSRspEquipSelectRate &msg, const msg::CSRspEquipSelectRate *pb) {
	msg.crossData=UTF8_TO_TCHAR(pb->crossdata().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqHistoryChatMsg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATTYPE Ct;

};
static void _ConvertPbToFCSReqHistoryChatMsg(FCSReqHistoryChatMsg &msg, const msg::CSReqHistoryChatMsg *pb) {
	msg.Ct=(ECHATTYPE)pb->ct();
}


USTRUCT(BlueprintType)
struct  FCSRspHistoryChatMsg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTWorldChat> world;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSNtfWorldInvite> invite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSNtfTeamMsg> team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSNtfChat> personal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSNtfPvpChat> pvpChat;	// 阵营 CSNtfPvpChat.ChatType 战斗 CSNtfPvpChat.ChatType 观战 CSNtfPvpChat.ChatType

};
static void _ConvertPbToFCSRspHistoryChatMsg(FCSRspHistoryChatMsg &msg, const msg::CSRspHistoryChatMsg *pb) {
	for (int i = 0; i < pb->world().size(); i++) {
		auto &a = pb->world().Get(i);
		FCSDTWorldChat tmp;
		_ConvertPbToFCSDTWorldChat(tmp, &a);
		msg.world.Add(tmp);
	}
	for (int i = 0; i < pb->invite().size(); i++) {
		auto &a = pb->invite().Get(i);
		FCSNtfWorldInvite tmp;
		_ConvertPbToFCSNtfWorldInvite(tmp, &a);
		msg.invite.Add(tmp);
	}
	for (int i = 0; i < pb->team().size(); i++) {
		auto &a = pb->team().Get(i);
		FCSNtfTeamMsg tmp;
		_ConvertPbToFCSNtfTeamMsg(tmp, &a);
		msg.team.Add(tmp);
	}
	for (int i = 0; i < pb->personal().size(); i++) {
		auto &a = pb->personal().Get(i);
		FCSNtfChat tmp;
		_ConvertPbToFCSNtfChat(tmp, &a);
		msg.personal.Add(tmp);
	}
	for (int i = 0; i < pb->pvpchat().size(); i++) {
		auto &a = pb->pvpchat().Get(i);
		FCSNtfPvpChat tmp;
		_ConvertPbToFCSNtfPvpChat(tmp, &a);
		msg.pvpChat.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqBattleCampResult {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqBattleCampResult(FCSReqBattleCampResult &msg, const msg::CSReqBattleCampResult *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspBattleCampResult {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTCampData> CampData;	//阵营数据统计

};
static void _ConvertPbToFCSRspBattleCampResult(FCSRspBattleCampResult &msg, const msg::CSRspBattleCampResult *pb) {
	for (int i = 0; i < pb->campdata().size(); i++) {
		auto &a = pb->campdata().Get(i);
		FCSDTCampData tmp;
		_ConvertPbToFCSDTCampData(tmp, &a);
		msg.CampData.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqTournamentPointAward {
	GENERATED_BODY()

	uint64 Id;	// 赛事id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardId;	// 奖励id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Num;	// 领取的是哪一个进度

};
static void _ConvertPbToFCSReqTournamentPointAward(FCSReqTournamentPointAward &msg, const msg::CSReqTournamentPointAward *pb) {
	msg.Id=pb->id();
	msg.AwardId=pb->awardid();
	msg.Num=pb->num();
}


USTRUCT(BlueprintType)
struct  FCSRspTournamentPointAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Award;	// 奖励

};
static void _ConvertPbToFCSRspTournamentPointAward(FCSRspTournamentPointAward &msg, const msg::CSRspTournamentPointAward *pb) {
	for (int i = 0; i < pb->award().size(); i++) {
		auto &a = pb->award().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Award.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetEnrollPlayers {
	GENERATED_BODY()

	uint64 TournamentId;	//赛事ID

	uint64 ClassId;	//级别ID

};
static void _ConvertPbToFCSReqGetEnrollPlayers(FCSReqGetEnrollPlayers &msg, const msg::CSReqGetEnrollPlayers *pb) {
	msg.TournamentId=pb->tournamentid();
	msg.ClassId=pb->classid();
}


USTRUCT(BlueprintType)
struct  FCSRspGetEnrollPlayers {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> Players;	//报名玩家{玩家ID:对阵索引}

};
static void _ConvertPbToFCSRspGetEnrollPlayers(FCSRspGetEnrollPlayers &msg, const msg::CSRspGetEnrollPlayers *pb) {

    for (auto it = pb->players().begin(); it != pb->players().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Players.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqChallengeAgain {
	GENERATED_BODY()

	uint64 TournamentId;

};
static void _ConvertPbToFCSReqChallengeAgain(FCSReqChallengeAgain &msg, const msg::CSReqChallengeAgain *pb) {
	msg.TournamentId=pb->tournamentid();
}


USTRUCT(BlueprintType)
struct  FCSRspChallengeAgain {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspChallengeAgain(FCSRspChallengeAgain &msg, const msg::CSRspChallengeAgain *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfBigWinnerExpandMatch {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BigWinnerId;	//大赢家场次id

};
static void _ConvertPbToFCSNtfBigWinnerExpandMatch(FCSNtfBigWinnerExpandMatch &msg, const msg::CSNtfBigWinnerExpandMatch *pb) {
	msg.BigWinnerId=pb->bigwinnerid();
}


USTRUCT(BlueprintType)
struct  FCSReqBigWinnerExpandMatch {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqBigWinnerExpandMatch(FCSReqBigWinnerExpandMatch &msg, const msg::CSReqBigWinnerExpandMatch *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspBigWinnerExpandMatch {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspBigWinnerExpandMatch(FCSRspBigWinnerExpandMatch &msg, const msg::CSRspBigWinnerExpandMatch *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqBigWinnerDailyAward {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqBigWinnerDailyAward(FCSReqBigWinnerDailyAward &msg, const msg::CSReqBigWinnerDailyAward *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspBigWinnerDailyAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Award;	// 奖励

};
static void _ConvertPbToFCSRspBigWinnerDailyAward(FCSRspBigWinnerDailyAward &msg, const msg::CSRspBigWinnerDailyAward *pb) {
	for (int i = 0; i < pb->award().size(); i++) {
		auto &a = pb->award().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Award.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqBigWinnerScoreHistory {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqBigWinnerScoreHistory(FCSReqBigWinnerScoreHistory &msg, const msg::CSReqBigWinnerScoreHistory *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspBigWinnerScoreHistory {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBigWinnerScoreHistory> history;	// 奖励

};
static void _ConvertPbToFCSRspBigWinnerScoreHistory(FCSRspBigWinnerScoreHistory &msg, const msg::CSRspBigWinnerScoreHistory *pb) {
	for (int i = 0; i < pb->history().size(); i++) {
		auto &a = pb->history().Get(i);
		FBigWinnerScoreHistory tmp;
		_ConvertPbToFBigWinnerScoreHistory(tmp, &a);
		msg.history.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqSmeltItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTItemID> Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SmeltId;	//熔炼ID

};
static void _ConvertPbToFCSReqSmeltItem(FCSReqSmeltItem &msg, const msg::CSReqSmeltItem *pb) {
	for (int i = 0; i < pb->items().size(); i++) {
		auto &a = pb->items().Get(i);
		FCSDTItemID tmp;
		_ConvertPbToFCSDTItemID(tmp, &a);
		msg.Items.Add(tmp);
	}
	msg.SmeltId=pb->smeltid();
}


USTRUCT(BlueprintType)
struct  FCSRspSmeltItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	// 奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	// 消息

};
static void _ConvertPbToFCSRspSmeltItem(FCSRspSmeltItem &msg, const msg::CSRspSmeltItem *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqPVEUpTalentLevel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeriesIdId;	//天赋ID

};
static void _ConvertPbToFCSReqPVEUpTalentLevel(FCSReqPVEUpTalentLevel &msg, const msg::CSReqPVEUpTalentLevel *pb) {
	msg.GroupId=pb->groupid();
	msg.SeriesIdId=pb->seriesidid();
}


USTRUCT(BlueprintType)
struct  FCSRspPVEUpTalentLevel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TalentId;	//天赋ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TalentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Consume;	//消耗的Token

};
static void _ConvertPbToFCSRspPVEUpTalentLevel(FCSRspPVEUpTalentLevel &msg, const msg::CSRspPVEUpTalentLevel *pb) {
	msg.GroupId=pb->groupid();
	msg.TalentId=pb->talentid();
	msg.TalentLevel=pb->talentlevel();
	msg.Consume=pb->consume();
}


USTRUCT(BlueprintType)
struct  FCSReqPVELuckyAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

};
static void _ConvertPbToFCSReqPVELuckyAward(FCSReqPVELuckyAward &msg, const msg::CSReqPVELuckyAward *pb) {
	msg.GroupId=pb->groupid();
}


USTRUCT(BlueprintType)
struct  FCSRspPVELuckyAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPveRecord Pve;	//年兽

};
static void _ConvertPbToFCSRspPVELuckyAward(FCSRspPVELuckyAward &msg, const msg::CSRspPVELuckyAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	_ConvertPbToFCSDTPveRecord(msg.Pve, &pb->pve());
}


USTRUCT(BlueprintType)
struct  FCSReqGuildCreate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Sign;	// 标志

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Notice;	// 公告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RecruitNotice;	// 招募公告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Tags;	// 标签

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;	// 国家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Province;	// 省份

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Language;	// 语言

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RequirePermit;	// 加入限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RequireCup;	// 最低段位

};
static void _ConvertPbToFCSReqGuildCreate(FCSReqGuildCreate &msg, const msg::CSReqGuildCreate *pb) {
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Sign=pb->sign();
	msg.Notice=UTF8_TO_TCHAR(pb->notice().c_str());
	msg.RecruitNotice=UTF8_TO_TCHAR(pb->recruitnotice().c_str());
	for (int i = 0; i < pb->tags().size(); i++) {
		auto &a = pb->tags().Get(i);
		int tmp;
		tmp=a;
		msg.Tags.Add(tmp);
	}
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.Province=pb->province();
	msg.Language=UTF8_TO_TCHAR(pb->language().c_str());
	msg.RequirePermit=pb->requirepermit();
	msg.RequireCup=pb->requirecup();
}


USTRUCT(BlueprintType)
struct  FCSRspGuildCreate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuildBaseInfo Info;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSRspGuildCreate(FCSRspGuildCreate &msg, const msg::CSRspGuildCreate *pb) {
	msg.ID=UTF8_TO_TCHAR(pb->id().c_str());
	_ConvertPbToFGuildBaseInfo(msg.Info, &pb->info());
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGuildInvite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> players;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;

};
static void _ConvertPbToFCSReqGuildInvite(FCSReqGuildInvite &msg, const msg::CSReqGuildInvite *pb) {
	for (int i = 0; i < pb->players().size(); i++) {
		auto &a = pb->players().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.players.Add(tmp);
	}
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspGuildInvite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;

};
static void _ConvertPbToFCSRspGuildInvite(FCSRspGuildInvite &msg, const msg::CSRspGuildInvite *pb) {
	msg.ID=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqGuildInviteList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Province;

};
static void _ConvertPbToFCSReqGuildInviteList(FCSReqGuildInviteList &msg, const msg::CSReqGuildInviteList *pb) {
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.Province=pb->province();
}


USTRUCT(BlueprintType)
struct  FCSRspGuildInviteList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildBaseInfo> List;

};
static void _ConvertPbToFCSRspGuildInviteList(FCSRspGuildInviteList &msg, const msg::CSRspGuildInviteList *pb) {
	for (int i = 0; i < pb->list().size(); i++) {
		auto &a = pb->list().Get(i);
		FGuildBaseInfo tmp;
		_ConvertPbToFGuildBaseInfo(tmp, &a);
		msg.List.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGuildRejectInvite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GuildID;

};
static void _ConvertPbToFCSReqGuildRejectInvite(FCSReqGuildRejectInvite &msg, const msg::CSReqGuildRejectInvite *pb) {
	msg.GuildID=UTF8_TO_TCHAR(pb->guildid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspGuildRejectInvite {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspGuildRejectInvite(FCSRspGuildRejectInvite &msg, const msg::CSRspGuildRejectInvite *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGuildLog {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGuildLog(FCSReqGuildLog &msg, const msg::CSReqGuildLog *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGuildLog {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildLog> Logs;

};
static void _ConvertPbToFCSRspGuildLog(FCSRspGuildLog &msg, const msg::CSRspGuildLog *pb) {
	for (int i = 0; i < pb->logs().size(); i++) {
		auto &a = pb->logs().Get(i);
		FGuildLog tmp;
		_ConvertPbToFGuildLog(tmp, &a);
		msg.Logs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGuildApply {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInvite;	// 是否通过邀约申请

};
static void _ConvertPbToFCSReqGuildApply(FCSReqGuildApply &msg, const msg::CSReqGuildApply *pb) {
	msg.ID=UTF8_TO_TCHAR(pb->id().c_str());
	msg.IsInvite=pb->isinvite();
}


USTRUCT(BlueprintType)
struct  FCSRspGuildApply {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspGuildApply(FCSRspGuildApply &msg, const msg::CSRspGuildApply *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGuildHome {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGuildHome(FCSReqGuildHome &msg, const msg::CSReqGuildHome *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGuildHome {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuildBaseInfo Info;	// 基本信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuildExtraInfo Extra;	// 额外信息

};
static void _ConvertPbToFCSRspGuildHome(FCSRspGuildHome &msg, const msg::CSRspGuildHome *pb) {
	_ConvertPbToFGuildBaseInfo(msg.Info, &pb->info());
	_ConvertPbToFGuildExtraInfo(msg.Extra, &pb->extra());
}


USTRUCT(BlueprintType)
struct  FCSReqGuildInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> IDs;

};
static void _ConvertPbToFCSReqGuildInfo(FCSReqGuildInfo &msg, const msg::CSReqGuildInfo *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.IDs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspGuildInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildBaseInfo> info;	// 基本信息

};
static void _ConvertPbToFCSRspGuildInfo(FCSRspGuildInfo &msg, const msg::CSRspGuildInfo *pb) {
	for (int i = 0; i < pb->info().size(); i++) {
		auto &a = pb->info().Get(i);
		FGuildBaseInfo tmp;
		_ConvertPbToFGuildBaseInfo(tmp, &a);
		msg.info.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGuildApprove {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsReject;

};
static void _ConvertPbToFCSReqGuildApprove(FCSReqGuildApprove &msg, const msg::CSReqGuildApprove *pb) {
	for (int i = 0; i < pb->id().size(); i++) {
		auto &a = pb->id().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ID.Add(tmp);
	}
	msg.IsReject=pb->isreject();
}


USTRUCT(BlueprintType)
struct  FCSRspGuildApprove {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspGuildApprove(FCSRspGuildApprove &msg, const msg::CSRspGuildApprove *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGuildSetRole {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	// 对方名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGUILDROLETYPE Role;

};
static void _ConvertPbToFCSReqGuildSetRole(FCSReqGuildSetRole &msg, const msg::CSReqGuildSetRole *pb) {
	msg.ID=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Role=(EGUILDROLETYPE)pb->role();
}


USTRUCT(BlueprintType)
struct  FCSReqGuildResign {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGuildResign(FCSReqGuildResign &msg, const msg::CSReqGuildResign *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGuildSetRole {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspGuildSetRole(FCSRspGuildSetRole &msg, const msg::CSRspGuildSetRole *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGuildModify {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Sign;	// 标志

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Notice;	// 公告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RecruitNotice;	// 招募公告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Tags;	// 标签

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGUILDPERMITTYPE RequirePermit;	// 加入限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RequireCup;	// 最低段位

};
static void _ConvertPbToFCSReqGuildModify(FCSReqGuildModify &msg, const msg::CSReqGuildModify *pb) {
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Sign=pb->sign();
	msg.Notice=UTF8_TO_TCHAR(pb->notice().c_str());
	msg.RecruitNotice=UTF8_TO_TCHAR(pb->recruitnotice().c_str());
	for (int i = 0; i < pb->tags().size(); i++) {
		auto &a = pb->tags().Get(i);
		int tmp;
		tmp=a;
		msg.Tags.Add(tmp);
	}
	msg.RequirePermit=(EGUILDPERMITTYPE)pb->requirepermit();
	msg.RequireCup=pb->requirecup();
}


USTRUCT(BlueprintType)
struct  FCSRspGuildModify {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSRspGuildModify(FCSRspGuildModify &msg, const msg::CSRspGuildModify *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGuildKickoff {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ID;

};
static void _ConvertPbToFCSReqGuildKickoff(FCSReqGuildKickoff &msg, const msg::CSReqGuildKickoff *pb) {
	for (int i = 0; i < pb->id().size(); i++) {
		auto &a = pb->id().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ID.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspGuildKickoff {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspGuildKickoff(FCSRspGuildKickoff &msg, const msg::CSRspGuildKickoff *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGuildDismiss {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGuildDismiss(FCSReqGuildDismiss &msg, const msg::CSReqGuildDismiss *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGuildDismiss {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspGuildDismiss(FCSRspGuildDismiss &msg, const msg::CSRspGuildDismiss *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGuildExit {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGuildExit(FCSReqGuildExit &msg, const msg::CSReqGuildExit *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGuildExit {
	GENERATED_BODY()

	int64 Ts;	// 退出时间

};
static void _ConvertPbToFCSRspGuildExit(FCSRspGuildExit &msg, const msg::CSRspGuildExit *pb) {
	msg.Ts=pb->ts();
}


USTRUCT(BlueprintType)
struct  FCSReqGuildChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Emotion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATTYPE ChatType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QuickChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CheckWorlds;	//需要检测的内容， Content里面有json，不能确定内容具体是什么，所以屏蔽词用这里的检测

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATSOURCETYPE SourceType;	// 聊天来源类型

};
static void _ConvertPbToFCSReqGuildChat(FCSReqGuildChat &msg, const msg::CSReqGuildChat *pb) {
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.Emotion=pb->emotion();
	msg.ChatType=(ECHATTYPE)pb->chattype();
	msg.QuickChat=pb->quickchat();
	msg.CheckWorlds=UTF8_TO_TCHAR(pb->checkworlds().c_str());
	msg.SourceType=(ECHATSOURCETYPE)pb->sourcetype();
}


USTRUCT(BlueprintType)
struct  FCSRspGuildChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NextSendTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATTYPE ChatType;

	int64 SilenceTime;	// 禁言时间

};
static void _ConvertPbToFCSRspGuildChat(FCSRspGuildChat &msg, const msg::CSRspGuildChat *pb) {
	msg.NextSendTime=pb->nextsendtime();
	msg.ChatType=(ECHATTYPE)pb->chattype();
	msg.SilenceTime=pb->silencetime();
}


USTRUCT(BlueprintType)
struct  FCSReqGuildList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Province;

};
static void _ConvertPbToFCSReqGuildList(FCSReqGuildList &msg, const msg::CSReqGuildList *pb) {
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.Province=pb->province();
}


USTRUCT(BlueprintType)
struct  FCSRspGuildList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildBaseInfo> List;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ApplyList;

};
static void _ConvertPbToFCSRspGuildList(FCSRspGuildList &msg, const msg::CSRspGuildList *pb) {
	for (int i = 0; i < pb->list().size(); i++) {
		auto &a = pb->list().Get(i);
		FGuildBaseInfo tmp;
		_ConvertPbToFGuildBaseInfo(tmp, &a);
		msg.List.Add(tmp);
	}
	for (int i = 0; i < pb->applylist().size(); i++) {
		auto &a = pb->applylist().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ApplyList.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGuildRecommendPlayers {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Province;

};
static void _ConvertPbToFCSReqGuildRecommendPlayers(FCSReqGuildRecommendPlayers &msg, const msg::CSReqGuildRecommendPlayers *pb) {
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.Province=pb->province();
}


USTRUCT(BlueprintType)
struct  FCSRspGuildRecommendPlayers {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPlayerBaseInfo> List;

};
static void _ConvertPbToFCSRspGuildRecommendPlayers(FCSRspGuildRecommendPlayers &msg, const msg::CSRspGuildRecommendPlayers *pb) {
	for (int i = 0; i < pb->list().size(); i++) {
		auto &a = pb->list().Get(i);
		FCSDTPlayerBaseInfo tmp;
		_ConvertPbToFCSDTPlayerBaseInfo(tmp, &a);
		msg.List.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetObserveAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//任务ID

};
static void _ConvertPbToFCSReqGetObserveAward(FCSReqGetObserveAward &msg, const msg::CSReqGetObserveAward *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSRspGetObserveAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> BoxAwards;	//宝箱掉落奖励

};
static void _ConvertPbToFCSRspGetObserveAward(FCSRspGetObserveAward &msg, const msg::CSRspGetObserveAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->boxawards().size(); i++) {
		auto &a = pb->boxawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.BoxAwards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqInviteObserve {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	// 邀请玩家列表

	uint64 PvpId;	// 战局ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	// 游戏模式

	uint64 TNClassRound;	// 赛事轮次ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWorkshopSetting WSSetting;

};
static void _ConvertPbToFCSReqInviteObserve(FCSReqInviteObserve &msg, const msg::CSReqInviteObserve *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
	msg.PvpId=pb->pvpid();
	msg.Mode=(EPVPMODE)pb->mode();
	msg.TNClassRound=pb->tnclassround();
	_ConvertPbToFWorkshopSetting(msg.WSSetting, &pb->wssetting());
}


USTRUCT(BlueprintType)
struct  FCSRspInviteObserve {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspInviteObserve(FCSRspInviteObserve &msg, const msg::CSRspInviteObserve *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqRejectObserve {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Inviter;	//邀请者

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NotReceive;	//指定时间内是否不再接受邀请者的邀请

};
static void _ConvertPbToFCSReqRejectObserve(FCSReqRejectObserve &msg, const msg::CSReqRejectObserve *pb) {
	msg.Inviter=UTF8_TO_TCHAR(pb->inviter().c_str());
	msg.NotReceive=pb->notreceive();
}


USTRUCT(BlueprintType)
struct  FCSRspRejectObserve {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspRejectObserve(FCSRspRejectObserve &msg, const msg::CSRspRejectObserve *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqRestrictUser {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUserRestrictType Type;	// 限制类型

};
static void _ConvertPbToFCSReqRestrictUser(FCSReqRestrictUser &msg, const msg::CSReqRestrictUser *pb) {
	msg.Type=(EUserRestrictType)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSRspRestrictUser {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspRestrictUser(FCSRspRestrictUser &msg, const msg::CSRspRestrictUser *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqRecommendWeek {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqRecommendWeek(FCSReqRecommendWeek &msg, const msg::CSReqRecommendWeek *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspRecommendWeek {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//推荐阵容信息

};
static void _ConvertPbToFCSRspRecommendWeek(FCSRspRecommendWeek &msg, const msg::CSRspRecommendWeek *pb) {
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqRecommendOfficial {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqRecommendOfficial(FCSReqRecommendOfficial &msg, const msg::CSReqRecommendOfficial *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspRecommendOfficial {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//推荐官方阵容信息

};
static void _ConvertPbToFCSRspRecommendOfficial(FCSRspRecommendOfficial &msg, const msg::CSRspRecommendOfficial *pb) {
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqRecommendLatest {
	GENERATED_BODY()

	int64 Index;	//分页

	int64 Num;	//数量

};
static void _ConvertPbToFCSReqRecommendLatest(FCSReqRecommendLatest &msg, const msg::CSReqRecommendLatest *pb) {
	msg.Index=pb->index();
	msg.Num=pb->num();
}


USTRUCT(BlueprintType)
struct  FCSRspRecommendLatest {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//推荐阵容信息

};
static void _ConvertPbToFCSRspRecommendLatest(FCSRspRecommendLatest &msg, const msg::CSRspRecommendLatest *pb) {
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqRecommendHistory {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GameId;	//游戏角色ID

	int64 Size;	//拉取的条数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//上一页最后一条数据的主键ID,为空则查询第1页

};
static void _ConvertPbToFCSReqRecommendHistory(FCSReqRecommendHistory &msg, const msg::CSReqRecommendHistory *pb) {
	msg.GameId=UTF8_TO_TCHAR(pb->gameid().c_str());
	msg.Size=pb->size();
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspRecommendHistory {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//推荐阵容信息

};
static void _ConvertPbToFCSRspRecommendHistory(FCSRspRecommendHistory &msg, const msg::CSRspRecommendHistory *pb) {
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqRecommendCollect {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	// 阵容id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BSet;	// true:设置， false:取消设置

};
static void _ConvertPbToFCSReqRecommendCollect(FCSReqRecommendCollect &msg, const msg::CSReqRecommendCollect *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.BSet=pb->bset();
}


USTRUCT(BlueprintType)
struct  FCSRspRecommendCollect {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspRecommendCollect(FCSRspRecommendCollect &msg, const msg::CSRspRecommendCollect *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqRecommendSet {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	// 阵容id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BSet;	// true:设置， false:取消设置

};
static void _ConvertPbToFCSReqRecommendSet(FCSReqRecommendSet &msg, const msg::CSReqRecommendSet *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.BSet=pb->bset();
}


USTRUCT(BlueprintType)
struct  FCSRspRecommendSet {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspRecommendSet(FCSRspRecommendSet &msg, const msg::CSRspRecommendSet *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqRecommendGetCollection {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;	// 阵容ids

};
static void _ConvertPbToFCSReqRecommendGetCollection(FCSReqRecommendGetCollection &msg, const msg::CSReqRecommendGetCollection *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspRecommendGetCollection {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//推荐阵容信息

};
static void _ConvertPbToFCSRspRecommendGetCollection(FCSRspRecommendGetCollection &msg, const msg::CSRspRecommendGetCollection *pb) {
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqRecommendEquip {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString reqData;	//请求字符串

};
static void _ConvertPbToFCSReqRecommendEquip(FCSReqRecommendEquip &msg, const msg::CSReqRecommendEquip *pb) {
	msg.reqData=UTF8_TO_TCHAR(pb->reqdata().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspRecommendEquip {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//推荐装备信息

};
static void _ConvertPbToFCSRspRecommendEquip(FCSRspRecommendEquip &msg, const msg::CSRspRecommendEquip *pb) {
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqLoginCancel {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqLoginCancel(FCSReqLoginCancel &msg, const msg::CSReqLoginCancel *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspLoginCancel {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspLoginCancel(FCSRspLoginCancel &msg, const msg::CSRspLoginCancel *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqConvertDebris {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessSkinSerie;	// 棋子皮肤系列id

};
static void _ConvertPbToFCSReqConvertDebris(FCSReqConvertDebris &msg, const msg::CSReqConvertDebris *pb) {
	msg.ChessSkinSerie=pb->chessskinserie();
}


USTRUCT(BlueprintType)
struct  FCSRspConvertDebris {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Debris;	// 获得碎片

};
static void _ConvertPbToFCSRspConvertDebris(FCSRspConvertDebris &msg, const msg::CSRspConvertDebris *pb) {
	for (int i = 0; i < pb->debris().size(); i++) {
		auto &a = pb->debris().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Debris.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqUseProtectionCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	// 消耗的段位保护卡id

};
static void _ConvertPbToFCSReqUseProtectionCard(FCSReqUseProtectionCard &msg, const msg::CSReqUseProtectionCard *pb) {
	msg.ID=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSRspUseProtectionCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMR;	// 当前MMR

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;	// 当前段位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRChange;	// 单局mmr变化值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TMMR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TCup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TMMRChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FFMMR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FFCup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FFMMRChange;

};
static void _ConvertPbToFCSRspUseProtectionCard(FCSRspUseProtectionCard &msg, const msg::CSRspUseProtectionCard *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.MMR=pb->mmr();
	msg.Cup=pb->cup();
	msg.MMRChange=pb->mmrchange();
	msg.TMMR=pb->tmmr();
	msg.TCup=pb->tcup();
	msg.TMMRChange=pb->tmmrchange();
	msg.FFMMR=pb->ffmmr();
	msg.FFCup=pb->ffcup();
	msg.FFMMRChange=pb->ffmmrchange();
}


USTRUCT(BlueprintType)
struct  FCSReqCustomCardOpt {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECustomCardOptType OptType;	// 操作类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapId;	// 地图id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCommon;	// 是否是公有棋组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	// 棋组序号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessIdList IdList;	// 要保存的棋组

};
static void _ConvertPbToFCSReqCustomCardOpt(FCSReqCustomCardOpt &msg, const msg::CSReqCustomCardOpt *pb) {
	msg.OptType=(ECustomCardOptType)pb->opttype();
	msg.MapId=pb->mapid();
	msg.IsCommon=pb->iscommon();
	msg.Index=pb->index();
	_ConvertPbToFChessIdList(msg.IdList, &pb->idlist());
}


USTRUCT(BlueprintType)
struct  FCSRspCustomCardOpt {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECustomCardOptType OptType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FChessIdList> Lists;	// 所有自定义棋组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCommon;	// 当前使用的是否是公有棋组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	// 当前使用的棋组的序号

};
static void _ConvertPbToFCSRspCustomCardOpt(FCSRspCustomCardOpt &msg, const msg::CSRspCustomCardOpt *pb) {
	msg.OptType=(ECustomCardOptType)pb->opttype();

    for (auto it = pb->lists().begin(); it != pb->lists().end(); it++) {
        FChessIdList tmp_value;
        _ConvertPbToFChessIdList(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Lists.Add(tmp_key, tmp_value);
    }
	msg.IsCommon=pb->iscommon();
	msg.Index=pb->index();
}


USTRUCT(BlueprintType)
struct  FCSReqChampionHistory {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OnlyCurZone;	// 是否只拉取本赛区历届冠军

};
static void _ConvertPbToFCSReqChampionHistory(FCSReqChampionHistory &msg, const msg::CSReqChampionHistory *pb) {
	msg.OnlyCurZone=pb->onlycurzone();
}


USTRUCT(BlueprintType)
struct  FCSRspChampionHistory {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChampionInfo> ChampionList;	// 冠军信息列表

};
static void _ConvertPbToFCSRspChampionHistory(FCSRspChampionHistory &msg, const msg::CSRspChampionHistory *pb) {
	for (int i = 0; i < pb->championlist().size(); i++) {
		auto &a = pb->championlist().Get(i);
		FChampionInfo tmp;
		_ConvertPbToFChampionInfo(tmp, &a);
		msg.ChampionList.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqTournamentLastTopRank {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqTournamentLastTopRank(FCSReqTournamentLastTopRank &msg, const msg::CSReqTournamentLastTopRank *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspTournamentLastTopRank {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTopRank Rank;	//前八玩家

};
static void _ConvertPbToFCSRspTournamentLastTopRank(FCSRspTournamentLastTopRank &msg, const msg::CSRspTournamentLastTopRank *pb) {
	_ConvertPbToFTopRank(msg.Rank, &pb->rank());
}


USTRUCT(BlueprintType)
struct  FCSReqUsePassportCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//使用道具ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActivateTypeId;	//特殊通行证激活卡选择得类型

};
static void _ConvertPbToFCSReqUsePassportCard(FCSReqUsePassportCard &msg, const msg::CSReqUsePassportCard *pb) {
	msg.Id=pb->id();
	msg.ActivateTypeId=pb->activatetypeid();
}


USTRUCT(BlueprintType)
struct  FCSRspUsePassportCard {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//使用道具消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Award;	//使用道具奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TypeIds;	//通行证类型IDList

};
static void _ConvertPbToFCSRspUsePassportCard(FCSRspUsePassportCard &msg, const msg::CSRspUsePassportCard *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->award().size(); i++) {
		auto &a = pb->award().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Award.Add(tmp);
	}
	for (int i = 0; i < pb->typeids().size(); i++) {
		auto &a = pb->typeids().Get(i);
		int tmp;
		tmp=a;
		msg.TypeIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqSetMedal {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//使用道具实例ID

};
static void _ConvertPbToFCSReqSetMedal(FCSReqSetMedal &msg, const msg::CSReqSetMedal *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSetMedal {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//勋章id

};
static void _ConvertPbToFCSRspSetMedal(FCSRspSetMedal &msg, const msg::CSRspSetMedal *pb) {
	msg.ID=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSReqUnSetMedal {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqUnSetMedal(FCSReqUnSetMedal &msg, const msg::CSReqUnSetMedal *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspUnSetMedal {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUnSetMedal(FCSRspUnSetMedal &msg, const msg::CSRspUnSetMedal *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPlayerMedals {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Ids;	// 用户id

};
static void _ConvertPbToFCSReqPlayerMedals(FCSReqPlayerMedals &msg, const msg::CSReqPlayerMedals *pb) {
	msg.Ids=UTF8_TO_TCHAR(pb->ids().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqPvpChestSave {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqPvpChestSave(FCSReqPvpChestSave &msg, const msg::CSReqPvpChestSave *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspPvpChestSave {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPvpChestSave(FCSRspPvpChestSave &msg, const msg::CSRspPvpChestSave *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfMedalInfos {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMedalInfo> list;	//勋章信息

};
static void _ConvertPbToFCSNtfMedalInfos(FCSNtfMedalInfos &msg, const msg::CSNtfMedalInfos *pb) {
	for (int i = 0; i < pb->list().size(); i++) {
		auto &a = pb->list().Get(i);
		FMedalInfo tmp;
		_ConvertPbToFMedalInfo(tmp, &a);
		msg.list.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfItemInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;	//物品唯一ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Number;	//物品编号

};
static void _ConvertPbToFCSNtfItemInfo(FCSNtfItemInfo &msg, const msg::CSNtfItemInfo *pb) {
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
	msg.Id=pb->id();
	msg.Number=UTF8_TO_TCHAR(pb->number().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfPassportNum {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TypeId;	//更新的通行证类型id  客户端自己去判断是啥类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Number;	//编号

};
static void _ConvertPbToFCSNtfPassportNum(FCSNtfPassportNum &msg, const msg::CSNtfPassportNum *pb) {
	msg.TypeId=pb->typeid_();
	msg.Number=pb->number();
}


USTRUCT(BlueprintType)
struct  FCSNtfPassportYearCardNum {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FCSDTPassportCard> AdvancePassport;	//预购通行证 客户端自己 计算还剩多少次数

};
static void _ConvertPbToFCSNtfPassportYearCardNum(FCSNtfPassportYearCardNum &msg, const msg::CSNtfPassportYearCardNum *pb) {

    for (auto it = pb->advancepassport().begin(); it != pb->advancepassport().end(); it++) {
        FCSDTPassportCard tmp_value;
        _ConvertPbToFCSDTPassportCard(tmp_value, &it->second);
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.AdvancePassport.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfMedalId {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalId;	//物品ID

};
static void _ConvertPbToFCSNtfMedalId(FCSNtfMedalId &msg, const msg::CSNtfMedalId *pb) {
	msg.MedalId=pb->medalid();
}


USTRUCT(BlueprintType)
struct  FCSRspPlayerMedals {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTItem> List;

};
static void _ConvertPbToFCSRspPlayerMedals(FCSRspPlayerMedals &msg, const msg::CSRspPlayerMedals *pb) {
	for (int i = 0; i < pb->list().size(); i++) {
		auto &a = pb->list().Get(i);
		FCSDTItem tmp;
		_ConvertPbToFCSDTItem(tmp, &a);
		msg.List.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqSetCache {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Data;

};
static void _ConvertPbToFCSReqSetCache(FCSReqSetCache &msg, const msg::CSReqSetCache *pb) {
	msg.Data=UTF8_TO_TCHAR(pb->data().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSetCache {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetCache(FCSRspSetCache &msg, const msg::CSRspSetCache *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetCache {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;

};
static void _ConvertPbToFCSReqGetCache(FCSReqGetCache &msg, const msg::CSReqGetCache *pb) {
	msg.Key=UTF8_TO_TCHAR(pb->key().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspGetCache {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Val;

};
static void _ConvertPbToFCSRspGetCache(FCSRspGetCache &msg, const msg::CSRspGetCache *pb) {
	msg.Val=UTF8_TO_TCHAR(pb->val().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfKickOff {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EREASON Reason;	//踢线原因

};
static void _ConvertPbToFCSNtfKickOff(FCSNtfKickOff &msg, const msg::CSNtfKickOff *pb) {
	msg.Reason=(EREASON)pb->reason();
}


USTRUCT(BlueprintType)
struct  FCSNtfWait {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//玩家前面有多少人排队(包含自己)

};
static void _ConvertPbToFCSNtfWait(FCSNtfWait &msg, const msg::CSNtfWait *pb) {
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSNtfPassDayBody {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTActivity Activity;	//跨天之后，活动内容下发

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTSignData SignData;	//每日签到活动数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTaskItem> ObserveTasks;	//观战任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBigWinnerData BigWinner;	//大玩家数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTMallBuyCount MallBuy;	//商城购买数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPassport Passport;	//跨周之后会解锁新的通行证任务，需要下发给客户端新的通行证信息，因为有得任务有初始进度

};
static void _ConvertPbToFCSNtfPassDayBody(FCSNtfPassDayBody &msg, const msg::CSNtfPassDayBody *pb) {
	_ConvertPbToFCSDTActivity(msg.Activity, &pb->activity());
	_ConvertPbToFCSDTSignData(msg.SignData, &pb->signdata());
	for (int i = 0; i < pb->observetasks().size(); i++) {
		auto &a = pb->observetasks().Get(i);
		FCSDTTaskItem tmp;
		_ConvertPbToFCSDTTaskItem(tmp, &a);
		msg.ObserveTasks.Add(tmp);
	}
	_ConvertPbToFCSDTBigWinnerData(msg.BigWinner, &pb->bigwinner());
	_ConvertPbToFCSDTMallBuyCount(msg.MallBuy, &pb->mallbuy());
	_ConvertPbToFCSDTPassport(msg.Passport, &pb->passport());
}


USTRUCT(BlueprintType)
struct  FCSNtfPassWeekBody {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EvalWeekMoney;	//每周结算糖果

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPassport Passport;	//跨周之后会解锁新的通行证任务，需要下发给客户端新的通行证信息，因为有得任务有初始进度

};
static void _ConvertPbToFCSNtfPassWeekBody(FCSNtfPassWeekBody &msg, const msg::CSNtfPassWeekBody *pb) {
	msg.EvalWeekMoney=pb->evalweekmoney();
	msg.WeekIndex=pb->weekindex();
	_ConvertPbToFCSDTPassport(msg.Passport, &pb->passport());
}


USTRUCT(BlueprintType)
struct  FCSNtfPassMonthBody {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfPassMonthBody(FCSNtfPassMonthBody &msg, const msg::CSNtfPassMonthBody *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfWorldChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTWorldChat WorldChat;

};
static void _ConvertPbToFCSNtfWorldChat(FCSNtfWorldChat &msg, const msg::CSNtfWorldChat *pb) {
	_ConvertPbToFCSDTWorldChat(msg.WorldChat, &pb->worldchat());
}


USTRUCT(BlueprintType)
struct  FCSNtfReload {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WorldChatLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EnableNewPlayerMode;

};
static void _ConvertPbToFCSNtfReload(FCSNtfReload &msg, const msg::CSNtfReload *pb) {
	msg.WorldChatLimit=pb->worldchatlimit();
	msg.EnableNewPlayerMode=pb->enablenewplayermode();
}


USTRUCT(BlueprintType)
struct  FCSNtfHeadPic {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//头像id

};
static void _ConvertPbToFCSNtfHeadPic(FCSNtfHeadPic &msg, const msg::CSNtfHeadPic *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpMatch {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//pvp模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExceptSecs;	//预期匹配时间 单位：秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Captain;	//队长

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MatchRegion;	//非""为地区匹配.

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MatchRegionSecs;	//地区匹配时长 单位：秒

};
static void _ConvertPbToFCSNtfPvpMatch(FCSNtfPvpMatch &msg, const msg::CSNtfPvpMatch *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.ExceptSecs=pb->exceptsecs();
	msg.Captain=UTF8_TO_TCHAR(pb->captain().c_str());
	msg.MatchRegion=UTF8_TO_TCHAR(pb->matchregion().c_str());
	msg.MatchRegionSecs=pb->matchregionsecs();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpMatchCancel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//取消玩家id

};
static void _ConvertPbToFCSNtfPvpMatchCancel(FCSNtfPvpMatchCancel &msg, const msg::CSNtfPvpMatchCancel *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfPvp {
	GENERATED_BODY()

	ERESULT Result;	//pvp匹配结果

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpTCPSvrAddr;	//pvpTCP服地址  格式：（域名/IP:端口）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCostEnterPvP CostData;	//消费的信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//pvp模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattlePassId;	//关卡教学id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BigWinnerId;	//大赢家场次id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FailString;	//匹配失败的详细信息

};
static void _ConvertPbToFCSNtfPvp(FCSNtfPvp &msg, const msg::CSNtfPvp *pb) {
	msg.Result=(ERESULT)pb->result();
	msg.PvpId=pb->pvpid();
	msg.PvpTCPSvrAddr=UTF8_TO_TCHAR(pb->pvptcpsvraddr().c_str());
	_ConvertPbToFCostEnterPvP(msg.CostData, &pb->costdata());
	msg.Mode=(EPVPMODE)pb->mode();
	msg.BattlePassId=pb->battlepassid();
	msg.BigWinnerId=pb->bigwinnerid();
	msg.FailString=UTF8_TO_TCHAR(pb->failstring().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpStatus {
	GENERATED_BODY()

	uint64 PvpId;	// pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Status;	// pvp状态   0:进行中  1:结束

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpTCPSvrAddr;	// pvpTCP服地址  格式：（域名/IP:端口）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpUDPSvrAddr;	// pvpUDP服地址  格式：（域名/IP:端口）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Award;	// 奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPvpCampResult CampResult;	// 阵营结果

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTStat Stat;	// 统计信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EvalWeekMoney;	// 每周糖果产出

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EvalWeekMoneyLimit;	// 每周糖果产出上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRChangeOne;	// 单局mmr变化值，不包含升段额外加分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRCupAdd;	// 升段时额外加分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRAward;	// 奖励分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DailyFirstWin;	// 是否是每日首胜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	// 模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	// 等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChangeExp;	// 增加的经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrencyExp;	// 当前经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekExp;	// 每周经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> LevelUpAward;	// 升级获得的奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Money;	// 升级获得的糖果

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExtraExp;	// 额外经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChangeStar;	// 获得的战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExtraStar;	// 额外战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrencyStar;	// 当前战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassportLevel;	// 当前通行证等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekStar;	// 本周战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MeleeRule;	// 乱斗规则ID

	ERESULT Result;	// 结算状态

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExtraMoney;	// 额外糖果

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CustomSubMode;	// 自定义子模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool LeaveInAdvance;	// 玩家是否提前离开

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CandyExpRate;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuffExpRate;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> TeamPvpAward;	// 开黑组队吃鸡额外奖励

	uint64 TournamentId;	// 赛事id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> AwardPoint;	// 当前战斗奖励积分

	uint64 TournamentGameId;	// 赛事gameid

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> UnlockedChess;	// 本局新解锁的棋子图鉴 老id->星级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RankProtected;	// 本局是否启用了掉段位保护

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Observer;	// 是否是观众

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EarnedCurrencyId;	// 局内分成货币ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EarnedCurrencyNum;	// 局内分成所得

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUserRestrictType RestrictType;	// 用户限制类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPvpTeachResult TeachResult;	// 教学关卡解锁

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPvpExtData ExtData;	// 扩展字段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamID;	// 队伍ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPEND_REASON EndReason;	// 结束原因

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleTime;	// 战斗时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RepeatedMmr;	// 连胜奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPVEEvalData Pve;	// pve结算

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRepeatedWin;	// 是否连胜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTDEvalData TDEval;	//塔防结算

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool TriggerMmrProtect;	//触发分数保护

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldMMRChangeOne;	//原始mmr变化值,不使用分数保护

};
static void _ConvertPbToFCSNtfPvpStatus(FCSNtfPvpStatus &msg, const msg::CSNtfPvpStatus *pb) {
	msg.PvpId=pb->pvpid();
	msg.Status=pb->status();
	msg.PvpTCPSvrAddr=UTF8_TO_TCHAR(pb->pvptcpsvraddr().c_str());
	msg.PvpUDPSvrAddr=UTF8_TO_TCHAR(pb->pvpudpsvraddr().c_str());
	for (int i = 0; i < pb->award().size(); i++) {
		auto &a = pb->award().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Award.Add(tmp);
	}
	_ConvertPbToFCSDTPvpCampResult(msg.CampResult, &pb->campresult());
	_ConvertPbToFCSDTStat(msg.Stat, &pb->stat());
	msg.EvalWeekMoney=pb->evalweekmoney();
	msg.EvalWeekMoneyLimit=pb->evalweekmoneylimit();
	msg.MMRChangeOne=pb->mmrchangeone();
	msg.MMRCupAdd=pb->mmrcupadd();
	msg.MMRAward=pb->mmraward();
	msg.DailyFirstWin=pb->dailyfirstwin();
	msg.Mode=(EPVPMODE)pb->mode();
	msg.Level=pb->level();
	msg.ChangeExp=pb->changeexp();
	msg.CurrencyExp=pb->currencyexp();
	msg.WeekExp=pb->weekexp();
	for (int i = 0; i < pb->levelupaward().size(); i++) {
		auto &a = pb->levelupaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.LevelUpAward.Add(tmp);
	}
	msg.Money=pb->money();
	msg.ExtraExp=pb->extraexp();
	msg.ChangeStar=pb->changestar();
	msg.ExtraStar=pb->extrastar();
	msg.CurrencyStar=pb->currencystar();
	msg.PassportLevel=pb->passportlevel();
	msg.WeekStar=pb->weekstar();
	msg.MeleeRule=pb->meleerule();
	msg.Result=(ERESULT)pb->result();
	msg.ExtraMoney=pb->extramoney();
	msg.CustomSubMode=pb->customsubmode();
	msg.LeaveInAdvance=pb->leaveinadvance();
	msg.CandyExpRate=pb->candyexprate();
	msg.BuffExpRate=pb->buffexprate();
	for (int i = 0; i < pb->teampvpaward().size(); i++) {
		auto &a = pb->teampvpaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.TeamPvpAward.Add(tmp);
	}
	msg.TournamentId=pb->tournamentid();
	for (int i = 0; i < pb->awardpoint().size(); i++) {
		auto &a = pb->awardpoint().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.AwardPoint.Add(tmp);
	}
	msg.TournamentGameId=pb->tournamentgameid();

    for (auto it = pb->unlockedchess().begin(); it != pb->unlockedchess().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.UnlockedChess.Add(tmp_key, tmp_value);
    }
	msg.RankProtected=pb->rankprotected();
	msg.Observer=pb->observer();
	msg.EarnedCurrencyId=pb->earnedcurrencyid();
	msg.EarnedCurrencyNum=pb->earnedcurrencynum();
	msg.RestrictType=(EUserRestrictType)pb->restricttype();
	_ConvertPbToFPvpTeachResult(msg.TeachResult, &pb->teachresult());
	_ConvertPbToFPvpExtData(msg.ExtData, &pb->extdata());
	msg.TeamID=pb->teamid();
	msg.EndReason=(EPVPEND_REASON)pb->endreason();
	msg.BattleTime=pb->battletime();
	msg.RepeatedMmr=pb->repeatedmmr();
	_ConvertPbToFPVEEvalData(msg.Pve, &pb->pve());
	msg.IsRepeatedWin=pb->isrepeatedwin();
	_ConvertPbToFTDEvalData(msg.TDEval, &pb->tdeval());
	msg.TriggerMmrProtect=pb->triggermmrprotect();
	msg.OldMMRChangeOne=pb->oldmmrchangeone();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpPlayerReady {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//玩家

};
static void _ConvertPbToFCSNtfPvpPlayerReady(FCSNtfPvpPlayerReady &msg, const msg::CSNtfPvpPlayerReady *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpBegin {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

};
static void _ConvertPbToFCSNtfPvpBegin(FCSNtfPvpBegin &msg, const msg::CSNtfPvpBegin *pb) {
	msg.PvpId=pb->pvpid();
}


USTRUCT(BlueprintType)
struct  FCSNtfPlayerFinish {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPlayerFinish PlayerFinish;	//大逃杀数据

};
static void _ConvertPbToFCSNtfPlayerFinish(FCSNtfPlayerFinish &msg, const msg::CSNtfPlayerFinish *pb) {
	_ConvertPbToFCSDTPlayerFinish(msg.PlayerFinish, &pb->playerfinish());
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpEnd {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPvpCampResult CampResult;	//阵营结果

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

};
static void _ConvertPbToFCSNtfPvpEnd(FCSNtfPvpEnd &msg, const msg::CSNtfPvpEnd *pb) {
	msg.PvpId=pb->pvpid();
	_ConvertPbToFCSDTPvpCampResult(msg.CampResult, &pb->campresult());
	msg.Mode=(EPVPMODE)pb->mode();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpReset {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfPvpReset(FCSNtfPvpReset &msg, const msg::CSNtfPvpReset *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfDelMail {
	GENERATED_BODY()

	uint64 MailId;	//mailId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESOURCE Reason;	//结束原因

};
static void _ConvertPbToFCSNtfDelMail(FCSNtfDelMail &msg, const msg::CSNtfDelMail *pb) {
	msg.MailId=pb->mailid();
	msg.Reason=(ESOURCE)pb->reason();
}


USTRUCT(BlueprintType)
struct  FCSNtfMarquee {
	GENERATED_BODY()

	int64 Id;	//跑马灯id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//内容

	int64 StartTime;	//起始时间

	int64 EndTime;	//截止时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Frequency;	//滚动频率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Flag;	//0代表明文，1代表语言key

};
static void _ConvertPbToFCSNtfMarquee(FCSNtfMarquee &msg, const msg::CSNtfMarquee *pb) {
	msg.Id=pb->id();
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.StartTime=pb->starttime();
	msg.EndTime=pb->endtime();
	msg.Frequency=pb->frequency();
	msg.Flag=pb->flag();
}


USTRUCT(BlueprintType)
struct  FCSNtfGameMarquee {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MarqueeId;	//跑马灯ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> Dict;	//字典

};
static void _ConvertPbToFCSNtfGameMarquee(FCSNtfGameMarquee &msg, const msg::CSNtfGameMarquee *pb) {
	msg.MarqueeId=pb->marqueeid();

    for (auto it = pb->dict().begin(); it != pb->dict().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Dict.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfRemoveMarquee {
	GENERATED_BODY()

	int64 Id;	//跑马灯id

};
static void _ConvertPbToFCSNtfRemoveMarquee(FCSNtfRemoveMarquee &msg, const msg::CSNtfRemoveMarquee *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSNtfLoadingProgress {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Progress;

};
static void _ConvertPbToFCSNtfLoadingProgress(FCSNtfLoadingProgress &msg, const msg::CSNtfLoadingProgress *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Index=pb->index();
	msg.Progress=pb->progress();
}


USTRUCT(BlueprintType)
struct  FCSNtfPay {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OrderId;	//订单Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GoodsId;	//商品Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rmb;	//充值金额

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> DiamondAwards;	//钻石奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> GivenAwards;	//赠送奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PassportAwards;	//通行证奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> MallAwards;	//商城奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Currency;	//货币类型

};
static void _ConvertPbToFCSNtfPay(FCSNtfPay &msg, const msg::CSNtfPay *pb) {
	msg.OrderId=UTF8_TO_TCHAR(pb->orderid().c_str());
	msg.GoodsId=pb->goodsid();
	msg.Rmb=pb->rmb();
	for (int i = 0; i < pb->diamondawards().size(); i++) {
		auto &a = pb->diamondawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.DiamondAwards.Add(tmp);
	}
	for (int i = 0; i < pb->givenawards().size(); i++) {
		auto &a = pb->givenawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.GivenAwards.Add(tmp);
	}
	for (int i = 0; i < pb->passportawards().size(); i++) {
		auto &a = pb->passportawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PassportAwards.Add(tmp);
	}
	for (int i = 0; i < pb->mallawards().size(); i++) {
		auto &a = pb->mallawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.MallAwards.Add(tmp);
	}
	msg.Currency=UTF8_TO_TCHAR(pb->currency().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfUpgradeBattleStage {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//当前战阶

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleStar;	//剩余战星

};
static void _ConvertPbToFCSNtfUpgradeBattleStage(FCSNtfUpgradeBattleStage &msg, const msg::CSNtfUpgradeBattleStage *pb) {
	msg.Level=pb->level();
	msg.BattleStar=pb->battlestar();
}


USTRUCT(BlueprintType)
struct  FCSNtfPassportTaskProgress {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTaskProgress> Datas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekTaskBattleStar;	//周任务战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayTaskBattleStar;	//日任务战星

};
static void _ConvertPbToFCSNtfPassportTaskProgress(FCSNtfPassportTaskProgress &msg, const msg::CSNtfPassportTaskProgress *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTaskProgress tmp;
		_ConvertPbToFTaskProgress(tmp, &a);
		msg.Datas.Add(tmp);
	}
	msg.WeekTaskBattleStar=pb->weektaskbattlestar();
	msg.DayTaskBattleStar=pb->daytaskbattlestar();
}


USTRUCT(BlueprintType)
struct  FCSNtfRefreshGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTGoodsInfo> Goods;	//{type:goods}

};
static void _ConvertPbToFCSNtfRefreshGoods(FCSNtfRefreshGoods &msg, const msg::CSNtfRefreshGoods *pb) {
	for (int i = 0; i < pb->goods().size(); i++) {
		auto &a = pb->goods().Get(i);
		FCSDTGoodsInfo tmp;
		_ConvertPbToFCSDTGoodsInfo(tmp, &a);
		msg.Goods.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfFollowList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, bool> Follows;	//关注者列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FansCount;	//粉丝数量

};
static void _ConvertPbToFCSNtfFollowList(FCSNtfFollowList &msg, const msg::CSNtfFollowList *pb) {

    for (auto it = pb->follows().begin(); it != pb->follows().end(); it++) {
        bool tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Follows.Add(tmp_key, tmp_value);
    }
	msg.FansCount=pb->fanscount();
}


USTRUCT(BlueprintType)
struct  FCSNtfNewFollower {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Fans;	//fanID

};
static void _ConvertPbToFCSNtfNewFollower(FCSNtfNewFollower &msg, const msg::CSNtfNewFollower *pb) {
	msg.Fans=UTF8_TO_TCHAR(pb->fans().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfLostFollower {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Fans;	//fanID

};
static void _ConvertPbToFCSNtfLostFollower(FCSNtfLostFollower &msg, const msg::CSNtfLostFollower *pb) {
	msg.Fans=UTF8_TO_TCHAR(pb->fans().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfInviteJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//邀请者id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//teamId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Punished;	//是否有队友收到惩罚

	int64 PunishmentDeadline;	//惩罚截止时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWorkshopSetting Workshop;	//创意工坊

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Ps4Only;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString channelUsrId;

};
static void _ConvertPbToFCSNtfInviteJoinTeam(FCSNtfInviteJoinTeam &msg, const msg::CSNtfInviteJoinTeam *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.TeamId=pb->teamid();
	msg.Mode=(EPVPMODE)pb->mode();
	msg.Punished=pb->punished();
	msg.PunishmentDeadline=pb->punishmentdeadline();
	_ConvertPbToFWorkshopSetting(msg.Workshop, &pb->workshop());
	msg.Ps4Only=pb->ps4only();
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.channelUsrId=UTF8_TO_TCHAR(pb->channelusrid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfPlayerJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//teamId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Slot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ForbidPlayGame;	//玩家是否禁止开始游戏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETEAMGROUP GroupId;	// 属于那个组(OB新增)

};
static void _ConvertPbToFCSNtfPlayerJoinTeam(FCSNtfPlayerJoinTeam &msg, const msg::CSNtfPlayerJoinTeam *pb) {
	msg.TeamId=pb->teamid();
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.IsAI=pb->isai();
	msg.Slot=pb->slot();
	msg.VoiceId=UTF8_TO_TCHAR(pb->voiceid().c_str());
	msg.ForbidPlayGame=pb->forbidplaygame();
	msg.GroupId=(ETEAMGROUP)pb->groupid();
}


USTRUCT(BlueprintType)
struct  FCSNtfPlayerLeaveTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//teamId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Captain;	//新队长

};
static void _ConvertPbToFCSNtfPlayerLeaveTeam(FCSNtfPlayerLeaveTeam &msg, const msg::CSNtfPlayerLeaveTeam *pb) {
	msg.TeamId=pb->teamid();
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Captain=UTF8_TO_TCHAR(pb->captain().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfKickOffTeamPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	//teamid

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString KickId;	//playerid

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAI;	//AI

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Slot;

};
static void _ConvertPbToFCSNtfKickOffTeamPlayer(FCSNtfKickOffTeamPlayer &msg, const msg::CSNtfKickOffTeamPlayer *pb) {
	msg.TeamId=pb->teamid();
	msg.KickId=UTF8_TO_TCHAR(pb->kickid().c_str());
	msg.IsAI=pb->isai();
	msg.Slot=pb->slot();
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamReady {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsReady;	//准备or取消准备

};
static void _ConvertPbToFCSNtfTeamReady(FCSNtfTeamReady &msg, const msg::CSNtfTeamReady *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.IsReady=pb->isready();
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamSlot {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTSlotInfo> Slots;

};
static void _ConvertPbToFCSNtfTeamSlot(FCSNtfTeamSlot &msg, const msg::CSNtfTeamSlot *pb) {
	for (int i = 0; i < pb->slots().size(); i++) {
		auto &a = pb->slots().Get(i);
		FCSDTSlotInfo tmp;
		_ConvertPbToFCSDTSlotInfo(tmp, &a);
		msg.Slots.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamSubMode {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubMode;

};
static void _ConvertPbToFCSNtfTeamSubMode(FCSNtfTeamSubMode &msg, const msg::CSNtfTeamSubMode *pb) {
	msg.SubMode=pb->submode();
}


USTRUCT(BlueprintType)
struct  FCSNtfChangeTeamSlot {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ReqId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ReqSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DesId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DesSlot;

};
static void _ConvertPbToFCSNtfChangeTeamSlot(FCSNtfChangeTeamSlot &msg, const msg::CSNtfChangeTeamSlot *pb) {
	msg.ReqId=UTF8_TO_TCHAR(pb->reqid().c_str());
	msg.ReqSlot=pb->reqslot();
	msg.DesId=UTF8_TO_TCHAR(pb->desid().c_str());
	msg.DesSlot=pb->desslot();
}


USTRUCT(BlueprintType)
struct  FCSNtfCancelChangeSlot {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ReqId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DesId;

};
static void _ConvertPbToFCSNtfCancelChangeSlot(FCSNtfCancelChangeSlot &msg, const msg::CSNtfCancelChangeSlot *pb) {
	msg.ReqId=UTF8_TO_TCHAR(pb->reqid().c_str());
	msg.DesId=UTF8_TO_TCHAR(pb->desid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfRefuseChangeTeamSlot {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RefuseId;

};
static void _ConvertPbToFCSNtfRefuseChangeTeamSlot(FCSNtfRefuseChangeTeamSlot &msg, const msg::CSNtfRefuseChangeTeamSlot *pb) {
	msg.RefuseId=UTF8_TO_TCHAR(pb->refuseid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamSlotStatus {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Ids;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Status;

};
static void _ConvertPbToFCSNtfTeamSlotStatus(FCSNtfTeamSlotStatus &msg, const msg::CSNtfTeamSlotStatus *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Ids.Add(tmp);
	}
	msg.Status=pb->status();
}


USTRUCT(BlueprintType)
struct  FCSNtfRejectJoinTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NotReceive;

};
static void _ConvertPbToFCSNtfRejectJoinTeam(FCSNtfRejectJoinTeam &msg, const msg::CSNtfRejectJoinTeam *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.NotReceive=pb->notreceive();
}


USTRUCT(BlueprintType)
struct  FCSNtfNotice {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTNoticeInfo NoticeInfo;

};
static void _ConvertPbToFCSNtfNotice(FCSNtfNotice &msg, const msg::CSNtfNotice *pb) {
	_ConvertPbToFCSDTNoticeInfo(msg.NoticeInfo, &pb->noticeinfo());
}


USTRUCT(BlueprintType)
struct  FCSNtfRemoveNotice {
	GENERATED_BODY()

	int64 Id;	//公告ID

};
static void _ConvertPbToFCSNtfRemoveNotice(FCSNtfRemoveNotice &msg, const msg::CSNtfRemoveNotice *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSNtfRankSeasonEval {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	//赛季序号

};
static void _ConvertPbToFCSNtfRankSeasonEval(FCSNtfRankSeasonEval &msg, const msg::CSNtfRankSeasonEval *pb) {
	msg.Index=pb->index();
}


USTRUCT(BlueprintType)
struct  FCSNtfBindAccounts {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ECHANELTYPE> Channels;

};
static void _ConvertPbToFCSNtfBindAccounts(FCSNtfBindAccounts &msg, const msg::CSNtfBindAccounts *pb) {
	for (int i = 0; i < pb->channels().size(); i++) {
		auto &a = pb->channels().Get(i);
		ECHANELTYPE tmp;
		tmp=(ECHANELTYPE)a;
		msg.Channels.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfSeasonTaskProgress {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrTaskProgress;	//当前任务进度次数

};
static void _ConvertPbToFCSNtfSeasonTaskProgress(FCSNtfSeasonTaskProgress &msg, const msg::CSNtfSeasonTaskProgress *pb) {
	msg.CurrTaskProgress=pb->currtaskprogress();
}


USTRUCT(BlueprintType)
struct  FCSNtfAlphaActivity {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EALPHA_ACTIVITY_STATE State;

};
static void _ConvertPbToFCSNtfAlphaActivity(FCSNtfAlphaActivity &msg, const msg::CSNtfAlphaActivity *pb) {
	msg.State=(EALPHA_ACTIVITY_STATE)pb->state();
}


USTRUCT(BlueprintType)
struct  FCSNtfOffSeasonToNewSeason {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

};
static void _ConvertPbToFCSNtfOffSeasonToNewSeason(FCSNtfOffSeasonToNewSeason &msg, const msg::CSNtfOffSeasonToNewSeason *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSNtfLanguageMd5List {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FString> List;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString version;	// 多语言最新版本号

};
static void _ConvertPbToFCSNtfLanguageMd5List(FCSNtfLanguageMd5List &msg, const msg::CSNtfLanguageMd5List *pb) {

    for (auto it = pb->list().begin(); it != pb->list().end(); it++) {
        FString tmp_value;
        tmp_value=UTF8_TO_TCHAR(it->second.c_str());
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.List.Add(tmp_key, tmp_value);
    }
	msg.version=UTF8_TO_TCHAR(pb->version().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfActivityProgress {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Progress;

};
static void _ConvertPbToFCSNtfActivityProgress(FCSNtfActivityProgress &msg, const msg::CSNtfActivityProgress *pb) {
	msg.GroupId=pb->groupid();
	msg.Id=pb->id();
	msg.Progress=pb->progress();
}


USTRUCT(BlueprintType)
struct  FCSNtfActivityTaskUnlock {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Unlock;

};
static void _ConvertPbToFCSNtfActivityTaskUnlock(FCSNtfActivityTaskUnlock &msg, const msg::CSNtfActivityTaskUnlock *pb) {
	msg.GroupId=pb->groupid();
	msg.Id=pb->id();
	msg.Unlock=pb->unlock();
}


USTRUCT(BlueprintType)
struct  FCSNtfPsServerOnly {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PsServerOnly;

};
static void _ConvertPbToFCSNtfPsServerOnly(FCSNtfPsServerOnly &msg, const msg::CSNtfPsServerOnly *pb) {
	msg.PsServerOnly=pb->psserveronly();
}


USTRUCT(BlueprintType)
struct  FCSNtfAddThirdPvpInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTThirdPvpInfo> Info;

};
static void _ConvertPbToFCSNtfAddThirdPvpInfo(FCSNtfAddThirdPvpInfo &msg, const msg::CSNtfAddThirdPvpInfo *pb) {
	for (int i = 0; i < pb->info().size(); i++) {
		auto &a = pb->info().Get(i);
		FCSDTThirdPvpInfo tmp;
		_ConvertPbToFCSDTThirdPvpInfo(tmp, &a);
		msg.Info.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfDelThirdPvpInfo {
	GENERATED_BODY()

	uint64 ID;	//赛事ID

};
static void _ConvertPbToFCSNtfDelThirdPvpInfo(FCSNtfDelThirdPvpInfo &msg, const msg::CSNtfDelThirdPvpInfo *pb) {
	msg.ID=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSNtfRemoveActivity {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> GroupId;	//活动组ID

};
static void _ConvertPbToFCSNtfRemoveActivity(FCSNtfRemoveActivity &msg, const msg::CSNtfRemoveActivity *pb) {
	for (int i = 0; i < pb->groupid().size(); i++) {
		auto &a = pb->groupid().Get(i);
		int tmp;
		tmp=a;
		msg.GroupId.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfActivityConfig {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool All;	//是否是全部的活动组 不是的情况代表个别活动有变化

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActivityGroup> Groups;	//活动组数据

};
static void _ConvertPbToFCSNtfActivityConfig(FCSNtfActivityConfig &msg, const msg::CSNtfActivityConfig *pb) {
	msg.All=pb->all();
	for (int i = 0; i < pb->groups().size(); i++) {
		auto &a = pb->groups().Get(i);
		FActivityGroup tmp;
		_ConvertPbToFActivityGroup(tmp, &a);
		msg.Groups.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfMeleeTaskProgress {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrTaskProgress;	//当前任务进度次数

};
static void _ConvertPbToFCSNtfMeleeTaskProgress(FCSNtfMeleeTaskProgress &msg, const msg::CSNtfMeleeTaskProgress *pb) {
	msg.CurrTaskProgress=pb->currtaskprogress();
}


USTRUCT(BlueprintType)
struct  FCSNtfSetTeamMode {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTeamSlotPlayer> SlotPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTeamOPSetting setting;

};
static void _ConvertPbToFCSNtfSetTeamMode(FCSNtfSetTeamMode &msg, const msg::CSNtfSetTeamMode *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	for (int i = 0; i < pb->slotplayers().size(); i++) {
		auto &a = pb->slotplayers().Get(i);
		FCSDTTeamSlotPlayer tmp;
		_ConvertPbToFCSDTTeamSlotPlayer(tmp, &a);
		msg.SlotPlayers.Add(tmp);
	}
	_ConvertPbToFTeamOPSetting(msg.setting, &pb->setting());
}


USTRUCT(BlueprintType)
struct  FCSNtfPassportClose {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PassportLevelAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PassportTaskAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ClosePeriod;	//关闭的通行证赛季

};
static void _ConvertPbToFCSNtfPassportClose(FCSNtfPassportClose &msg, const msg::CSNtfPassportClose *pb) {
	for (int i = 0; i < pb->passportlevelawards().size(); i++) {
		auto &a = pb->passportlevelawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PassportLevelAwards.Add(tmp);
	}
	for (int i = 0; i < pb->passporttaskawards().size(); i++) {
		auto &a = pb->passporttaskawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PassportTaskAwards.Add(tmp);
	}
	msg.ClosePeriod=pb->closeperiod();
}


USTRUCT(BlueprintType)
struct  FCSNtfPassportOpen {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPassport Passport;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldPeriod;	//上一个赛季

};
static void _ConvertPbToFCSNtfPassportOpen(FCSNtfPassportOpen &msg, const msg::CSNtfPassportOpen *pb) {
	_ConvertPbToFCSDTPassport(msg.Passport, &pb->passport());
	msg.OldPeriod=pb->oldperiod();
}


USTRUCT(BlueprintType)
struct  FCSNtfWeekIndex {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekIndex;

};
static void _ConvertPbToFCSNtfWeekIndex(FCSNtfWeekIndex &msg, const msg::CSNtfWeekIndex *pb) {
	msg.WeekIndex=pb->weekindex();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpHistory {
	GENERATED_BODY()

	uint64 PvpId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Path;

};
static void _ConvertPbToFCSNtfPvpHistory(FCSNtfPvpHistory &msg, const msg::CSNtfPvpHistory *pb) {
	msg.PvpId=pb->pvpid();
	msg.Path=UTF8_TO_TCHAR(pb->path().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamPvpEnd {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfTeamPvpEnd(FCSNtfTeamPvpEnd &msg, const msg::CSNtfTeamPvpEnd *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfProbeNetDelay {
	GENERATED_BODY()

	int64 Number;

};
static void _ConvertPbToFCSNtfProbeNetDelay(FCSNtfProbeNetDelay &msg, const msg::CSNtfProbeNetDelay *pb) {
	msg.Number=pb->number();
}


USTRUCT(BlueprintType)
struct  FCSNtfRemoveEggs {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Eggs;	//扭蛋列表

};
static void _ConvertPbToFCSNtfRemoveEggs(FCSNtfRemoveEggs &msg, const msg::CSNtfRemoveEggs *pb) {
	for (int i = 0; i < pb->eggs().size(); i++) {
		auto &a = pb->eggs().Get(i);
		int tmp;
		tmp=a;
		msg.Eggs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfSwitchSet {
	GENERATED_BODY()

	TArray<ESWITCHTYPE> SwitchTypeList;

};
static void _ConvertPbToFCSNtfSwitchSet(FCSNtfSwitchSet &msg, const msg::CSNtfSwitchSet *pb) {
	for (int i = 0; i < pb->switchtypelist().size(); i++) {
		auto &a = pb->switchtypelist().Get(i);
		ESWITCHTYPE tmp;
		tmp=(ESWITCHTYPE)a;
		msg.SwitchTypeList.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfBlacklist {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> Blacklist;

};
static void _ConvertPbToFCSNtfBlacklist(FCSNtfBlacklist &msg, const msg::CSNtfBlacklist *pb) {

    for (auto it = pb->blacklist().begin(); it != pb->blacklist().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Blacklist.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfBindPhoneNumberSwitch {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBINDSWITCHTYPE BindSwitchType;

};
static void _ConvertPbToFCSNtfBindPhoneNumberSwitch(FCSNtfBindPhoneNumberSwitch &msg, const msg::CSNtfBindPhoneNumberSwitch *pb) {
	msg.BindSwitchType=(EBINDSWITCHTYPE)pb->bindswitchtype();
}


USTRUCT(BlueprintType)
struct  FCSNtfPrivilege {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANNELVIPTYPE ChannelVipType;	//渠道vip类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELAUNCHTYPE LaunchType;	//登陆类型

};
static void _ConvertPbToFCSNtfPrivilege(FCSNtfPrivilege &msg, const msg::CSNtfPrivilege *pb) {
	msg.ChannelVipType=(ECHANNELVIPTYPE)pb->channelviptype();
	msg.LaunchType=(ELAUNCHTYPE)pb->launchtype();
}


USTRUCT(BlueprintType)
struct  FCSNtfMallNotice {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMallNoticeData> Datas;

};
static void _ConvertPbToFCSNtfMallNotice(FCSNtfMallNotice &msg, const msg::CSNtfMallNotice *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMallNoticeData tmp;
		_ConvertPbToFMallNoticeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfAARemind {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AreaId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Partition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlatId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OpenId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Msg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TraceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Source;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Serial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;

};
static void _ConvertPbToFCSNtfAARemind(FCSNtfAARemind &msg, const msg::CSNtfAARemind *pb) {
	msg.AreaId=pb->areaid();
	msg.Partition=pb->partition();
	msg.PlatId=pb->platid();
	msg.OpenId=UTF8_TO_TCHAR(pb->openid().c_str());
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Msg=UTF8_TO_TCHAR(pb->msg().c_str());
	msg.TraceId=UTF8_TO_TCHAR(pb->traceid().c_str());
	msg.Source=pb->source();
	msg.Serial=UTF8_TO_TCHAR(pb->serial().c_str());
	msg.ID=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfAABan {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AreaId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Partition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlatId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OpenId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Msg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TraceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Source;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Serial;

	int64 BeginTime;

	int64 EndTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;

};
static void _ConvertPbToFCSNtfAABan(FCSNtfAABan &msg, const msg::CSNtfAABan *pb) {
	msg.AreaId=pb->areaid();
	msg.Partition=pb->partition();
	msg.PlatId=pb->platid();
	msg.OpenId=UTF8_TO_TCHAR(pb->openid().c_str());
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Msg=UTF8_TO_TCHAR(pb->msg().c_str());
	msg.TraceId=UTF8_TO_TCHAR(pb->traceid().c_str());
	msg.Source=pb->source();
	msg.Serial=UTF8_TO_TCHAR(pb->serial().c_str());
	msg.BeginTime=pb->begintime();
	msg.EndTime=pb->endtime();
	msg.ID=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfAAVerify {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AreaId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Partition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlatId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OpenId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Msg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TraceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Source;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Serial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString JsonStr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;

};
static void _ConvertPbToFCSNtfAAVerify(FCSNtfAAVerify &msg, const msg::CSNtfAAVerify *pb) {
	msg.AreaId=pb->areaid();
	msg.Partition=pb->partition();
	msg.PlatId=pb->platid();
	msg.OpenId=UTF8_TO_TCHAR(pb->openid().c_str());
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Msg=UTF8_TO_TCHAR(pb->msg().c_str());
	msg.TraceId=UTF8_TO_TCHAR(pb->traceid().c_str());
	msg.Source=pb->source();
	msg.Serial=UTF8_TO_TCHAR(pb->serial().c_str());
	msg.JsonStr=UTF8_TO_TCHAR(pb->jsonstr().c_str());
	msg.ID=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfPhoneNumber {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tel;

};
static void _ConvertPbToFCSNtfPhoneNumber(FCSNtfPhoneNumber &msg, const msg::CSNtfPhoneNumber *pb) {
	msg.Tel=UTF8_TO_TCHAR(pb->tel().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfAntiCallBack {
	GENERATED_BODY()

	std::string Data;

};
static void _ConvertPbToFCSNtfAntiCallBack(FCSNtfAntiCallBack &msg, const msg::CSNtfAntiCallBack *pb) {
	msg.Data=pb->data();
}


USTRUCT(BlueprintType)
struct  FCSNtfFortuneBagTime {
	GENERATED_BODY()

	uint64 BeginTime;

	uint64 EndTime;

};
static void _ConvertPbToFCSNtfFortuneBagTime(FCSNtfFortuneBagTime &msg, const msg::CSNtfFortuneBagTime *pb) {
	msg.BeginTime=pb->begintime();
	msg.EndTime=pb->endtime();
}


USTRUCT(BlueprintType)
struct  FCSNtfUpdateItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//减少

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//增加

};
static void _ConvertPbToFCSNtfUpdateItem(FCSNtfUpdateItem &msg, const msg::CSNtfUpdateItem *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfCreditScore {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCreditCfgItem> Config;

};
static void _ConvertPbToFCSNtfCreditScore(FCSNtfCreditScore &msg, const msg::CSNtfCreditScore *pb) {
	msg.Score=pb->score();
	for (int i = 0; i < pb->config().size(); i++) {
		auto &a = pb->config().Get(i);
		FCreditCfgItem tmp;
		_ConvertPbToFCreditCfgItem(tmp, &a);
		msg.Config.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfBuffAct {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTBuffAct> BuffActs;

};
static void _ConvertPbToFCSNtfBuffAct(FCSNtfBuffAct &msg, const msg::CSNtfBuffAct *pb) {
	for (int i = 0; i < pb->buffacts().size(); i++) {
		auto &a = pb->buffacts().Get(i);
		FCSDTBuffAct tmp;
		_ConvertPbToFCSDTBuffAct(tmp, &a);
		msg.BuffActs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfActivityGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActivityGroupData> Group;

};
static void _ConvertPbToFCSNtfActivityGroup(FCSNtfActivityGroup &msg, const msg::CSNtfActivityGroup *pb) {
	for (int i = 0; i < pb->group().size(); i++) {
		auto &a = pb->group().Get(i);
		FActivityGroupData tmp;
		_ConvertPbToFActivityGroupData(tmp, &a);
		msg.Group.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfClearChat {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfClearChat(FCSNtfClearChat &msg, const msg::CSNtfClearChat *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfJoinVoiceTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	// 玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;	// 腾讯语音使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSNtfJoinVoiceTeam(FCSNtfJoinVoiceTeam &msg, const msg::CSNtfJoinVoiceTeam *pb) {
	msg.VoiceId=UTF8_TO_TCHAR(pb->voiceid().c_str());
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.VoiceMemId=pb->voicememid();
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfJoinVoicePvp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	// 玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;	// 腾讯语音使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSNtfJoinVoicePvp(FCSNtfJoinVoicePvp &msg, const msg::CSNtfJoinVoicePvp *pb) {
	msg.VoiceId=UTF8_TO_TCHAR(pb->voiceid().c_str());
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.VoiceMemId=pb->voicememid();
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfJoinVoiceCamp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	// 玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMemId;	// 腾讯语音使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VoiceUserId;	// 龙渊语音使用

};
static void _ConvertPbToFCSNtfJoinVoiceCamp(FCSNtfJoinVoiceCamp &msg, const msg::CSNtfJoinVoiceCamp *pb) {
	msg.VoiceId=UTF8_TO_TCHAR(pb->voiceid().c_str());
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.VoiceMemId=pb->voicememid();
	msg.VoiceUserId=UTF8_TO_TCHAR(pb->voiceuserid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfWxVVip {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

};
static void _ConvertPbToFCSNtfWxVVip(FCSNtfWxVVip &msg, const msg::CSNtfWxVVip *pb) {
	msg.Level=pb->level();
}


USTRUCT(BlueprintType)
struct  FCSNtfFreeFlow {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FreeFlowUrl;

};
static void _ConvertPbToFCSNtfFreeFlow(FCSNtfFreeFlow &msg, const msg::CSNtfFreeFlow *pb) {
	msg.Body=UTF8_TO_TCHAR(pb->body().c_str());
	msg.FreeFlowUrl=UTF8_TO_TCHAR(pb->freeflowurl().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfWxRedPacket {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> RedPkts;

};
static void _ConvertPbToFCSNtfWxRedPacket(FCSNtfWxRedPacket &msg, const msg::CSNtfWxRedPacket *pb) {
	for (int i = 0; i < pb->redpkts().size(); i++) {
		auto &a = pb->redpkts().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.RedPkts.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfGmSysMsg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Contents;

};
static void _ConvertPbToFCSNtfGmSysMsg(FCSNtfGmSysMsg &msg, const msg::CSNtfGmSysMsg *pb) {
	for (int i = 0; i < pb->contents().size(); i++) {
		auto &a = pb->contents().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Contents.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfNewPunishment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTPunishment> Punishment;

};
static void _ConvertPbToFCSNtfNewPunishment(FCSNtfNewPunishment &msg, const msg::CSNtfNewPunishment *pb) {
	for (int i = 0; i < pb->punishment().size(); i++) {
		auto &a = pb->punishment().Get(i);
		FCSDTPunishment tmp;
		_ConvertPbToFCSDTPunishment(tmp, &a);
		msg.Punishment.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamOP {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTeamOP OP;	//操作

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTeamSlotPlayer> slotPlayers;

};
static void _ConvertPbToFCSNtfTeamOP(FCSNtfTeamOP &msg, const msg::CSNtfTeamOP *pb) {
	_ConvertPbToFTeamOP(msg.OP, &pb->op());
	for (int i = 0; i < pb->slotplayers().size(); i++) {
		auto &a = pb->slotplayers().Get(i);
		FCSDTTeamSlotPlayer tmp;
		_ConvertPbToFCSDTTeamSlotPlayer(tmp, &a);
		msg.slotPlayers.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfWebLogin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Uuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FirebaseToken;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LocalId;

};
static void _ConvertPbToFCSNtfWebLogin(FCSNtfWebLogin &msg, const msg::CSNtfWebLogin *pb) {
	msg.Uuid=UTF8_TO_TCHAR(pb->uuid().c_str());
	msg.FirebaseToken=UTF8_TO_TCHAR(pb->firebasetoken().c_str());
	msg.LocalId=UTF8_TO_TCHAR(pb->localid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfSingleRoundFlow {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

	int64 PVPStartTime;	//pvp开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlatAppId;	//社区appId 对应开放平台侧

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FCSDTRound> PlayerRound;	//回合数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubMode;	//子模式

	int64 CommunityTeamUUID;	// 组队唯一id

};
static void _ConvertPbToFCSNtfSingleRoundFlow(FCSNtfSingleRoundFlow &msg, const msg::CSNtfSingleRoundFlow *pb) {
	msg.PvpId=pb->pvpid();
	msg.Mode=(EPVPMODE)pb->mode();
	msg.PVPStartTime=pb->pvpstarttime();
	msg.PlatAppId=UTF8_TO_TCHAR(pb->platappid().c_str());

    for (auto it = pb->playerround().begin(); it != pb->playerround().end(); it++) {
        FCSDTRound tmp_value;
        _ConvertPbToFCSDTRound(tmp_value, &it->second);
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.PlayerRound.Add(tmp_key, tmp_value);
    }
	msg.SubMode=pb->submode();
	msg.CommunityTeamUUID=pb->communityteamuuid();
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamDismiss {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamId;	// 队伍ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETEAM_DISMISS_REASON Reason;	// 解散原因

};
static void _ConvertPbToFCSNtfTeamDismiss(FCSNtfTeamDismiss &msg, const msg::CSNtfTeamDismiss *pb) {
	msg.TeamId=pb->teamid();
	msg.Reason=(ETEAM_DISMISS_REASON)pb->reason();
}


USTRUCT(BlueprintType)
struct  FCSNtfSwitchModeInTeam {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE NewMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamID;

};
static void _ConvertPbToFCSNtfSwitchModeInTeam(FCSNtfSwitchModeInTeam &msg, const msg::CSNtfSwitchModeInTeam *pb) {
	msg.NewMode=(EPVPMODE)pb->newmode();
	msg.TeamID=pb->teamid();
}


USTRUCT(BlueprintType)
struct  FCSReqActItemExch {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExchId;	//兑换id

};
static void _ConvertPbToFCSReqActItemExch(FCSReqActItemExch &msg, const msg::CSReqActItemExch *pb) {
	msg.ExchId=pb->exchid();
}


USTRUCT(BlueprintType)
struct  FCSReqRecruitInvitePlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;	// 玩家ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	// 活动ID

};
static void _ConvertPbToFCSReqRecruitInvitePlayer(FCSReqRecruitInvitePlayer &msg, const msg::CSReqRecruitInvitePlayer *pb) {
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.GroupId=pb->groupid();
}


USTRUCT(BlueprintType)
struct  FCSReqRecruitBindInviter {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;	// 玩家ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	// 活动ID

};
static void _ConvertPbToFCSReqRecruitBindInviter(FCSReqRecruitBindInviter &msg, const msg::CSReqRecruitBindInviter *pb) {
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.GroupId=pb->groupid();
}


USTRUCT(BlueprintType)
struct  FCSNtfObserveStatus {
	GENERATED_BODY()

	uint64 PvpId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TcpAddr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;	//观战视角

};
static void _ConvertPbToFCSNtfObserveStatus(FCSNtfObserveStatus &msg, const msg::CSNtfObserveStatus *pb) {
	msg.PvpId=pb->pvpid();
	msg.TcpAddr=UTF8_TO_TCHAR(pb->tcpaddr().c_str());
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfForbidInfo {
	GENERATED_BODY()

	int64 EndTime;	// 解禁时间 0代表永久封禁

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFROZEN_TYPE FrozenType;	// 封禁类型

	ESWITCHTYPE SwitchType;	// 封禁功能类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;

};
static void _ConvertPbToFCSNtfForbidInfo(FCSNtfForbidInfo &msg, const msg::CSNtfForbidInfo *pb) {
	msg.EndTime=pb->endtime();
	msg.FrozenType=(EFROZEN_TYPE)pb->frozentype();
	msg.SwitchType=(ESWITCHTYPE)pb->switchtype();
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfMidasDiamond {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diamond;

};
static void _ConvertPbToFCSNtfMidasDiamond(FCSNtfMidasDiamond &msg, const msg::CSNtfMidasDiamond *pb) {
	msg.Diamond=pb->diamond();
}


USTRUCT(BlueprintType)
struct  FCSNtfPunishmentInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBriefPunishment Punishment;

};
static void _ConvertPbToFCSNtfPunishmentInfo(FCSNtfPunishmentInfo &msg, const msg::CSNtfPunishmentInfo *pb) {
	_ConvertPbToFCSDTBriefPunishment(msg.Punishment, &pb->punishment());
}


USTRUCT(BlueprintType)
struct  FCSNtfRemovePunishment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PunishmentId;

};
static void _ConvertPbToFCSNtfRemovePunishment(FCSNtfRemovePunishment &msg, const msg::CSNtfRemovePunishment *pb) {
	msg.PunishmentId=pb->punishmentid();
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpConfirm {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	//玩家索引

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Confirm;

};
static void _ConvertPbToFCSNtfPvpConfirm(FCSNtfPvpConfirm &msg, const msg::CSNtfPvpConfirm *pb) {
	msg.Index=pb->index();
	msg.Confirm=pb->confirm();
}


USTRUCT(BlueprintType)
struct  FCSNtfMatchSuccess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FPlayerConfirmInfo> Players;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCardGroup;

};
static void _ConvertPbToFCSNtfMatchSuccess(FCSNtfMatchSuccess &msg, const msg::CSNtfMatchSuccess *pb) {

    for (auto it = pb->players().begin(); it != pb->players().end(); it++) {
        FPlayerConfirmInfo tmp_value;
        _ConvertPbToFPlayerConfirmInfo(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Players.Add(tmp_key, tmp_value);
    }
	msg.Mode=(EPVPMODE)pb->mode();
	msg.IsCardGroup=pb->iscardgroup();
}


USTRUCT(BlueprintType)
struct  FCSNtfOldBusinessPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//昵称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadPic;	//头像

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadPicFrame;	//头像框

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMR;	//杯段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BusinessId;	//businessId

};
static void _ConvertPbToFCSNtfOldBusinessPlayer(FCSNtfOldBusinessPlayer &msg, const msg::CSNtfOldBusinessPlayer *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.HeadPic=pb->headpic();
	msg.HeadPicFrame=pb->headpicframe();
	msg.Level=pb->level();
	msg.MMR=pb->mmr();
	msg.BusinessId=UTF8_TO_TCHAR(pb->businessid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpReconnect {
	GENERATED_BODY()

	uint64 PvpId;	//pvpId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Status;	//pvp状态   0:进行中  1:结束

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpTCPSvrAddr;	//pvpTCP服地址  格式：（域名/IP:端口）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpUDPSvrAddr;	//pvpUDP服地址  格式：（域名/IP:端口）

	ERESULT Result;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GameID;

};
static void _ConvertPbToFCSNtfPvpReconnect(FCSNtfPvpReconnect &msg, const msg::CSNtfPvpReconnect *pb) {
	msg.PvpId=pb->pvpid();
	msg.Status=pb->status();
	msg.PvpTCPSvrAddr=UTF8_TO_TCHAR(pb->pvptcpsvraddr().c_str());
	msg.PvpUDPSvrAddr=UTF8_TO_TCHAR(pb->pvpudpsvraddr().c_str());
	msg.Result=(ERESULT)pb->result();
	msg.GameID=pb->gameid();
}


USTRUCT(BlueprintType)
struct  FCheseSkinData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeriesId;	//系列ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InstanceId;	//实例ID

};
static void _ConvertPbToFCheseSkinData(FCheseSkinData &msg, const msg::CheseSkinData *pb) {
	msg.SeriesId=pb->seriesid();
	msg.InstanceId=UTF8_TO_TCHAR(pb->instanceid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfShowChessSkin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FChessSkinSlotData> ChessSkins;

};
static void _ConvertPbToFCSNtfShowChessSkin(FCSNtfShowChessSkin &msg, const msg::CSNtfShowChessSkin *pb) {

    for (auto it = pb->chessskins().begin(); it != pb->chessskins().end(); it++) {
        FChessSkinSlotData tmp_value;
        _ConvertPbToFChessSkinSlotData(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.ChessSkins.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfChestCount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> ChestCount;

};
static void _ConvertPbToFCSNtfChestCount(FCSNtfChestCount &msg, const msg::CSNtfChestCount *pb) {

    for (auto it = pb->chestcount().begin(); it != pb->chestcount().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.ChestCount.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfChestRecord {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FChestRecord> ChestRecord;

};
static void _ConvertPbToFCSNtfChestRecord(FCSNtfChestRecord &msg, const msg::CSNtfChestRecord *pb) {

    for (auto it = pb->chestrecord().begin(); it != pb->chestrecord().end(); it++) {
        FChestRecord tmp_value;
        _ConvertPbToFChestRecord(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.ChestRecord.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfRecruitInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTActivityRecruit Recruit;	//招募信息

};
static void _ConvertPbToFCSNtfRecruitInfo(FCSNtfRecruitInfo &msg, const msg::CSNtfRecruitInfo *pb) {
	msg.GroupId=pb->groupid();
	_ConvertPbToFCSDTActivityRecruit(msg.Recruit, &pb->recruit());
}


USTRUCT(BlueprintType)
struct  FCSNtfRecruitPlayer {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;	//玩家ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTRecruitPlayer Info;	//玩家信息

};
static void _ConvertPbToFCSNtfRecruitPlayer(FCSNtfRecruitPlayer &msg, const msg::CSNtfRecruitPlayer *pb) {
	msg.GroupId=pb->groupid();
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
	_ConvertPbToFCSDTRecruitPlayer(msg.Info, &pb->info());
}


USTRUCT(BlueprintType)
struct  FCSNtfRecruitPlayerBattle {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;	//玩家ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleCount;	//对局数

};
static void _ConvertPbToFCSNtfRecruitPlayerBattle(FCSNtfRecruitPlayerBattle &msg, const msg::CSNtfRecruitPlayerBattle *pb) {
	msg.GroupId=pb->groupid();
	msg.PlayerId=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.BattleCount=pb->battlecount();
}


USTRUCT(BlueprintType)
struct  FCSNtfOnHelpReddot {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfOnHelpReddot(FCSNtfOnHelpReddot &msg, const msg::CSNtfOnHelpReddot *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfBagUpdate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESOURCE Source;	//来源

};
static void _ConvertPbToFCSNtfBagUpdate(FCSNtfBagUpdate &msg, const msg::CSNtfBagUpdate *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.Source=(ESOURCE)pb->source();
}


USTRUCT(BlueprintType)
struct  FCSNtfKrIdentityAuth {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Token;	// 令牌

};
static void _ConvertPbToFCSNtfKrIdentityAuth(FCSNtfKrIdentityAuth &msg, const msg::CSNtfKrIdentityAuth *pb) {
	msg.Token=UTF8_TO_TCHAR(pb->token().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfKrAddictionTip {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfKrAddictionTip(FCSNtfKrAddictionTip &msg, const msg::CSNtfKrAddictionTip *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfKrAddictionCountdown {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Countdown;	//倒计时

};
static void _ConvertPbToFCSNtfKrAddictionCountdown(FCSNtfKrAddictionCountdown &msg, const msg::CSNtfKrAddictionCountdown *pb) {
	msg.Countdown=pb->countdown();
}


USTRUCT(BlueprintType)
struct  FCSNtfRefreshMelee {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTMelee Melee;	//梦境模式信息

};
static void _ConvertPbToFCSNtfRefreshMelee(FCSNtfRefreshMelee &msg, const msg::CSNtfRefreshMelee *pb) {
	_ConvertPbToFCSDTMelee(msg.Melee, &pb->melee());
}


USTRUCT(BlueprintType)
struct  FCSNtfVngCommentAwardReset {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfVngCommentAwardReset(FCSNtfVngCommentAwardReset &msg, const msg::CSNtfVngCommentAwardReset *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfAddBanner {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBanner Banner;

};
static void _ConvertPbToFCSNtfAddBanner(FCSNtfAddBanner &msg, const msg::CSNtfAddBanner *pb) {
	_ConvertPbToFCSDTBanner(msg.Banner, &pb->banner());
}


USTRUCT(BlueprintType)
struct  FCSNtfRemoveBanner {
	GENERATED_BODY()

	int64 Id;

};
static void _ConvertPbToFCSNtfRemoveBanner(FCSNtfRemoveBanner &msg, const msg::CSNtfRemoveBanner *pb) {
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FCSNtfHistoryChatMsg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTWorldChat> world;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSNtfWorldInvite> invite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSNtfTeamMsg> team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSNtfChat> personal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSNtfPvpChat> pvpChat;	// 阵营 CSNtfPvpChat.ChatType 战斗 CSNtfPvpChat.ChatType 观战 CSNtfPvpChat.ChatType

};
static void _ConvertPbToFCSNtfHistoryChatMsg(FCSNtfHistoryChatMsg &msg, const msg::CSNtfHistoryChatMsg *pb) {
	for (int i = 0; i < pb->world().size(); i++) {
		auto &a = pb->world().Get(i);
		FCSDTWorldChat tmp;
		_ConvertPbToFCSDTWorldChat(tmp, &a);
		msg.world.Add(tmp);
	}
	for (int i = 0; i < pb->invite().size(); i++) {
		auto &a = pb->invite().Get(i);
		FCSNtfWorldInvite tmp;
		_ConvertPbToFCSNtfWorldInvite(tmp, &a);
		msg.invite.Add(tmp);
	}
	for (int i = 0; i < pb->team().size(); i++) {
		auto &a = pb->team().Get(i);
		FCSNtfTeamMsg tmp;
		_ConvertPbToFCSNtfTeamMsg(tmp, &a);
		msg.team.Add(tmp);
	}
	for (int i = 0; i < pb->personal().size(); i++) {
		auto &a = pb->personal().Get(i);
		FCSNtfChat tmp;
		_ConvertPbToFCSNtfChat(tmp, &a);
		msg.personal.Add(tmp);
	}
	for (int i = 0; i < pb->pvpchat().size(); i++) {
		auto &a = pb->pvpchat().Get(i);
		FCSNtfPvpChat tmp;
		_ConvertPbToFCSNtfPvpChat(tmp, &a);
		msg.pvpChat.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfCurrentTournament {
	GENERATED_BODY()

	TMap<uint64, FCSDTTournament> Tournaments;	//当前正在进行的赛事

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> Points;	//玩家获得的全局积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTopRank TopRank;	//赛事前八玩家,理论上应该是上一届

};
static void _ConvertPbToFCSNtfCurrentTournament(FCSNtfCurrentTournament &msg, const msg::CSNtfCurrentTournament *pb) {

    for (auto it = pb->tournaments().begin(); it != pb->tournaments().end(); it++) {
        FCSDTTournament tmp_value;
        _ConvertPbToFCSDTTournament(tmp_value, &it->second);
        uint64 tmp_key;
        tmp_key=it->first;
        msg.Tournaments.Add(tmp_key, tmp_value);
    }

    for (auto it = pb->points().begin(); it != pb->points().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.Points.Add(tmp_key, tmp_value);
    }
	_ConvertPbToFTopRank(msg.TopRank, &pb->toprank());
}


USTRUCT(BlueprintType)
struct  FCSNtfLuckStarAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFCSNtfLuckStarAward(FCSNtfLuckStarAward &msg, const msg::CSNtfLuckStarAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfTournamentBegin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTNewTournament> NewTournaments;	//新赛事

};
static void _ConvertPbToFCSNtfTournamentBegin(FCSNtfTournamentBegin &msg, const msg::CSNtfTournamentBegin *pb) {
	for (int i = 0; i < pb->newtournaments().size(); i++) {
		auto &a = pb->newtournaments().Get(i);
		FCSDTNewTournament tmp;
		_ConvertPbToFCSDTNewTournament(tmp, &a);
		msg.NewTournaments.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfTournamentOut {
	GENERATED_BODY()

	uint64 id;	// 淘汰的赛事id

	uint64 roundId;	// 淘汰的轮次id

};
static void _ConvertPbToFCSNtfTournamentOut(FCSNtfTournamentOut &msg, const msg::CSNtfTournamentOut *pb) {
	msg.id=pb->id();
	msg.roundId=pb->roundid();
}


USTRUCT(BlueprintType)
struct  FCSNtfTournamentEnrollBegin {
	GENERATED_BODY()

	TArray<uint64> Tournaments;	//允许报名的赛事

};
static void _ConvertPbToFCSNtfTournamentEnrollBegin(FCSNtfTournamentEnrollBegin &msg, const msg::CSNtfTournamentEnrollBegin *pb) {
	for (int i = 0; i < pb->tournaments().size(); i++) {
		auto &a = pb->tournaments().Get(i);
		uint64 tmp;
		tmp=a;
		msg.Tournaments.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfTournamentEnrollEnd {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTEnrollEnd> Tournaments;	//报名结束的赛事

};
static void _ConvertPbToFCSNtfTournamentEnrollEnd(FCSNtfTournamentEnrollEnd &msg, const msg::CSNtfTournamentEnrollEnd *pb) {
	for (int i = 0; i < pb->tournaments().size(); i++) {
		auto &a = pb->tournaments().Get(i);
		FCSDTEnrollEnd tmp;
		_ConvertPbToFCSDTEnrollEnd(tmp, &a);
		msg.Tournaments.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfTournamentEnd {
	GENERATED_BODY()

	uint64 TournamentId;	//赛事ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESOURCE Reason;	//结束原因

};
static void _ConvertPbToFCSNtfTournamentEnd(FCSNtfTournamentEnd &msg, const msg::CSNtfTournamentEnd *pb) {
	msg.TournamentId=pb->tournamentid();
	msg.Reason=(ESOURCE)pb->reason();
}


USTRUCT(BlueprintType)
struct  FCSNtfTournamentRoundEnd {
	GENERATED_BODY()

	uint64 TournamentId;

	uint64 ClassId;

	uint64 RoundId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FCSDTBattleGroup> Groups;	//下个轮次的战斗分组

};
static void _ConvertPbToFCSNtfTournamentRoundEnd(FCSNtfTournamentRoundEnd &msg, const msg::CSNtfTournamentRoundEnd *pb) {
	msg.TournamentId=pb->tournamentid();
	msg.ClassId=pb->classid();
	msg.RoundId=pb->roundid();

    for (auto it = pb->groups().begin(); it != pb->groups().end(); it++) {
        FCSDTBattleGroup tmp_value;
        _ConvertPbToFCSDTBattleGroup(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Groups.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfPs4ServerOnly {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ps4ServerOnly;

};
static void _ConvertPbToFCSNtfPs4ServerOnly(FCSNtfPs4ServerOnly &msg, const msg::CSNtfPs4ServerOnly *pb) {
	msg.Ps4ServerOnly=pb->ps4serveronly();
}


USTRUCT(BlueprintType)
struct  FCSNtfLuckMallGoods {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> MallGoods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Discount;	//折扣信息

};
static void _ConvertPbToFCSNtfLuckMallGoods(FCSNtfLuckMallGoods &msg, const msg::CSNtfLuckMallGoods *pb) {
	for (int i = 0; i < pb->mallgoods().size(); i++) {
		auto &a = pb->mallgoods().Get(i);
		int tmp;
		tmp=a;
		msg.MallGoods.Add(tmp);
	}
	msg.GroupId=pb->groupid();
	msg.Discount=pb->discount();
}


USTRUCT(BlueprintType)
struct  FCSNtfTeamStatus {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETeamState Status;

};
static void _ConvertPbToFCSNtfTeamStatus(FCSNtfTeamStatus &msg, const msg::CSNtfTeamStatus *pb) {
	msg.TeamID=pb->teamid();
	msg.Status=(ETeamState)pb->status();
}


USTRUCT(BlueprintType)
struct  FCSNtfPlayerExpChanged {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChangeExp;	//本次改变经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	// 变化经验后, 玩家新的等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Exp;	// 当前等级的经验值

};
static void _ConvertPbToFCSNtfPlayerExpChanged(FCSNtfPlayerExpChanged &msg, const msg::CSNtfPlayerExpChanged *pb) {
	msg.ChangeExp=pb->changeexp();
	msg.Level=pb->level();
	msg.Exp=pb->exp();
}


USTRUCT(BlueprintType)
struct  FCSNtfSystemGmTime {
	GENERATED_BODY()

	uint64 nowtime;

};
static void _ConvertPbToFCSNtfSystemGmTime(FCSNtfSystemGmTime &msg, const msg::CSNtfSystemGmTime *pb) {
	msg.nowtime=pb->nowtime();
}


USTRUCT(BlueprintType)
struct  FCSNtfChangeName {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NickName;	//修改后的昵称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SetNameCount;	//改名次数

};
static void _ConvertPbToFCSNtfChangeName(FCSNtfChangeName &msg, const msg::CSNtfChangeName *pb) {
	msg.NickName=UTF8_TO_TCHAR(pb->nickname().c_str());
	msg.SetNameCount=pb->setnamecount();
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildJoin {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GuildID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Limit;

};
static void _ConvertPbToFCSNtfGuildJoin(FCSNtfGuildJoin &msg, const msg::CSNtfGuildJoin *pb) {
	msg.GuildID=UTF8_TO_TCHAR(pb->guildid().c_str());
	msg.Limit=pb->limit();
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GuildID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGUILDROLETYPE Role;

	int64 ExitTs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildChatInfo> Chats;	// 公会聊天历史

};
static void _ConvertPbToFCSNtfGuildInfo(FCSNtfGuildInfo &msg, const msg::CSNtfGuildInfo *pb) {
	msg.GuildID=UTF8_TO_TCHAR(pb->guildid().c_str());
	msg.Role=(EGUILDROLETYPE)pb->role();
	msg.ExitTs=pb->exitts();
	for (int i = 0; i < pb->chats().size(); i++) {
		auto &a = pb->chats().Get(i);
		FGuildChatInfo tmp;
		_ConvertPbToFGuildChatInfo(tmp, &a);
		msg.Chats.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildMemberChange {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Player_PB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRemove;

};
static void _ConvertPbToFCSNtfGuildMemberChange(FCSNtfGuildMemberChange &msg, const msg::CSNtfGuildMemberChange *pb) {
	for (int i = 0; i < pb->player().size(); i++) {
		auto &a = pb->player().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Player_PB.Add(tmp);
	}
	msg.IsRemove=pb->isremove();
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildApplicantChange {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildApplicant> Applicants;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRemove;

};
static void _ConvertPbToFCSNtfGuildApplicantChange(FCSNtfGuildApplicantChange &msg, const msg::CSNtfGuildApplicantChange *pb) {
	for (int i = 0; i < pb->applicants().size(); i++) {
		auto &a = pb->applicants().Get(i);
		FGuildApplicant tmp;
		_ConvertPbToFGuildApplicant(tmp, &a);
		msg.Applicants.Add(tmp);
	}
	msg.IsRemove=pb->isremove();
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildInviteeChange {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildApplicant> Applicants;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRemove;

};
static void _ConvertPbToFCSNtfGuildInviteeChange(FCSNtfGuildInviteeChange &msg, const msg::CSNtfGuildInviteeChange *pb) {
	for (int i = 0; i < pb->applicants().size(); i++) {
		auto &a = pb->applicants().Get(i);
		FGuildApplicant tmp;
		_ConvertPbToFGuildApplicant(tmp, &a);
		msg.Applicants.Add(tmp);
	}
	msg.IsRemove=pb->isremove();
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildNewInvite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuildBaseInfo Info;

};
static void _ConvertPbToFCSNtfGuildNewInvite(FCSNtfGuildNewInvite &msg, const msg::CSNtfGuildNewInvite *pb) {
	_ConvertPbToFGuildBaseInfo(msg.Info, &pb->info());
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildKickoff {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfGuildKickoff(FCSNtfGuildKickoff &msg, const msg::CSNtfGuildKickoff *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildRoleChange {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildPlayerRole> Infos;

};
static void _ConvertPbToFCSNtfGuildRoleChange(FCSNtfGuildRoleChange &msg, const msg::CSNtfGuildRoleChange *pb) {
	for (int i = 0; i < pb->infos().size(); i++) {
		auto &a = pb->infos().Get(i);
		FGuildPlayerRole tmp;
		_ConvertPbToFGuildPlayerRole(tmp, &a);
		msg.Infos.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildAttrChange {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuildAttr Attr;

};
static void _ConvertPbToFCSNtfGuildAttrChange(FCSNtfGuildAttrChange &msg, const msg::CSNtfGuildAttrChange *pb) {
	_ConvertPbToFGuildAttr(msg.Attr, &pb->attr());
}


USTRUCT(BlueprintType)
struct  FCSNtfGuildChat {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuildChatInfo Chat;

};
static void _ConvertPbToFCSNtfGuildChat(FCSNtfGuildChat &msg, const msg::CSNtfGuildChat *pb) {
	_ConvertPbToFGuildChatInfo(msg.Chat, &pb->chat());
}


USTRUCT(BlueprintType)
struct  FCSNtfApplicantChange {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildChatInfo> Chat;

};
static void _ConvertPbToFCSNtfApplicantChange(FCSNtfApplicantChange &msg, const msg::CSNtfApplicantChange *pb) {
	for (int i = 0; i < pb->chat().size(); i++) {
		auto &a = pb->chat().Get(i);
		FGuildChatInfo tmp;
		_ConvertPbToFGuildChatInfo(tmp, &a);
		msg.Chat.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfNewGuildLog {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildLog> Logs;

};
static void _ConvertPbToFCSNtfNewGuildLog(FCSNtfNewGuildLog &msg, const msg::CSNtfNewGuildLog *pb) {
	for (int i = 0; i < pb->logs().size(); i++) {
		auto &a = pb->logs().Get(i);
		FGuildLog tmp;
		_ConvertPbToFGuildLog(tmp, &a);
		msg.Logs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfAdAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFCSNtfAdAward(FCSNtfAdAward &msg, const msg::CSNtfAdAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfAdCount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAdCount> Infos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalViewCout;	// 累计观看次数， group 0

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdCumulateCount;	// 已领取观看次数， group 0

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsReset;	// 是否重置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FADStat> Stat;	// 广告分组统计

};
static void _ConvertPbToFCSNtfAdCount(FCSNtfAdCount &msg, const msg::CSNtfAdCount *pb) {
	for (int i = 0; i < pb->infos().size(); i++) {
		auto &a = pb->infos().Get(i);
		FAdCount tmp;
		_ConvertPbToFAdCount(tmp, &a);
		msg.Infos.Add(tmp);
	}
	msg.TotalViewCout=pb->totalviewcout();
	msg.AdCumulateCount=pb->adcumulatecount();
	msg.IsReset=pb->isreset();

    for (auto it = pb->stat().begin(); it != pb->stat().end(); it++) {
        FADStat tmp_value;
        _ConvertPbToFADStat(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Stat.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfFirstPay {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfFirstPay(FCSNtfFirstPay &msg, const msg::CSNtfFirstPay *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfInviteObserve {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Inviter;	// 邀请人

	uint64 PvpId;	// 邀请观战的战局

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	// 游戏模式

	uint64 TNClassRound;	// 赛事轮次ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWorkshopSetting WSSetting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Ps4Only;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString channelUsrId;

};
static void _ConvertPbToFCSNtfInviteObserve(FCSNtfInviteObserve &msg, const msg::CSNtfInviteObserve *pb) {
	msg.Inviter=UTF8_TO_TCHAR(pb->inviter().c_str());
	msg.PvpId=pb->pvpid();
	msg.Mode=(EPVPMODE)pb->mode();
	msg.TNClassRound=pb->tnclassround();
	_ConvertPbToFWorkshopSetting(msg.WSSetting, &pb->wssetting());
	msg.Ps4Only=pb->ps4only();
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.channelUsrId=UTF8_TO_TCHAR(pb->channelusrid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfAddAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESOURCE Source;	// 来源

};
static void _ConvertPbToFCSNtfAddAward(FCSNtfAddAward &msg, const msg::CSNtfAddAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.Source=(ESOURCE)pb->source();
}


USTRUCT(BlueprintType)
struct  FCSNtfLimitRefresh {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLimitRefresh> data;	//刷新结果

};
static void _ConvertPbToFCSNtfLimitRefresh(FCSNtfLimitRefresh &msg, const msg::CSNtfLimitRefresh *pb) {
	for (int i = 0; i < pb->data().size(); i++) {
		auto &a = pb->data().Get(i);
		FLimitRefresh tmp;
		_ConvertPbToFLimitRefresh(tmp, &a);
		msg.data.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfUpdateNotice {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NoticeId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Status;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ClientEvent;

};
static void _ConvertPbToFCSNtfUpdateNotice(FCSNtfUpdateNotice &msg, const msg::CSNtfUpdateNotice *pb) {
	msg.NoticeId=UTF8_TO_TCHAR(pb->noticeid().c_str());
	msg.Tags=UTF8_TO_TCHAR(pb->tags().c_str());
	msg.Status=pb->status();
	msg.ActivityId=UTF8_TO_TCHAR(pb->activityid().c_str());
	msg.ClientEvent=UTF8_TO_TCHAR(pb->clientevent().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfUpdatePveChallengeCount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChallengeNum;	//免费挑战次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuyChallengeNum;	//今日购买奖励次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardNum;	//可抽取得奖励次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardScore;	//奖励积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Token;	//代币 {代币id,数量}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int> Talent;	//天赋等级 {代币id,数量}

};
static void _ConvertPbToFCSNtfUpdatePveChallengeCount(FCSNtfUpdatePveChallengeCount &msg, const msg::CSNtfUpdatePveChallengeCount *pb) {
	msg.GroupId=pb->groupid();
	msg.ChallengeNum=pb->challengenum();
	msg.BuyChallengeNum=pb->buychallengenum();
	msg.AwardNum=pb->awardnum();
	msg.AwardScore=pb->awardscore();
	msg.Token=pb->token();

    for (auto it = pb->talent().begin(); it != pb->talent().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Talent.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfCalcMmr {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChangeMmr;	//改变的分数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CupAdd;	//增加得杯段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RankProtected;	//是否保护

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RepeatedMmr;	//连胜奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool TriggerMmrProtect;	//是否分数保护

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OldMMRChangeOne;	//老mmr改变分数

};
static void _ConvertPbToFCSNtfCalcMmr(FCSNtfCalcMmr &msg, const msg::CSNtfCalcMmr *pb) {
	msg.ChangeMmr=pb->changemmr();
	msg.CupAdd=pb->cupadd();
	msg.RankProtected=pb->rankprotected();
	msg.Mode=(EPVPMODE)pb->mode();
	msg.RepeatedMmr=pb->repeatedmmr();
	msg.TriggerMmrProtect=pb->triggermmrprotect();
	msg.OldMMRChangeOne=pb->oldmmrchangeone();
}


USTRUCT(BlueprintType)
struct  FCSNtfBag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Page;	//页

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTBagItem> Items;	//物品

};
static void _ConvertPbToFCSNtfBag(FCSNtfBag &msg, const msg::CSNtfBag *pb) {
	msg.Page=pb->page();
	for (int i = 0; i < pb->items().size(); i++) {
		auto &a = pb->items().Get(i);
		FCSDTBagItem tmp;
		_ConvertPbToFCSDTBagItem(tmp, &a);
		msg.Items.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfRejectObserve {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Invitee;	//被邀请者

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NotReceive;	//指定时间内是否不再接受邀请者的邀请

};
static void _ConvertPbToFCSNtfRejectObserve(FCSNtfRejectObserve &msg, const msg::CSNtfRejectObserve *pb) {
	msg.Invitee=UTF8_TO_TCHAR(pb->invitee().c_str());
	msg.NotReceive=pb->notreceive();
}


USTRUCT(BlueprintType)
struct  FCSNtfBetOnBounty {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTBetData BetData;

};
static void _ConvertPbToFCSNtfBetOnBounty(FCSNtfBetOnBounty &msg, const msg::CSNtfBetOnBounty *pb) {
	_ConvertPbToFCSDTBetData(msg.BetData, &pb->betdata());
}


USTRUCT(BlueprintType)
struct  FCSNtfTaskProgress {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//任务Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrTaskProgress;	//当前任务进度次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETASKTYPE Type;	// 任务类型

};
static void _ConvertPbToFCSNtfTaskProgress(FCSNtfTaskProgress &msg, const msg::CSNtfTaskProgress *pb) {
	msg.Id=pb->id();
	msg.CurrTaskProgress=pb->currtaskprogress();
	msg.Type=(ETASKTYPE)pb->type();
}


USTRUCT(BlueprintType)
struct  FCSNtfNewPlayerGuideEnded {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfNewPlayerGuideEnded(FCSNtfNewPlayerGuideEnded &msg, const msg::CSNtfNewPlayerGuideEnded *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfChessListErr {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MemberId;	// 玩家id

};
static void _ConvertPbToFCSNtfChessListErr(FCSNtfChessListErr &msg, const msg::CSNtfChessListErr *pb) {
	msg.MemberId=UTF8_TO_TCHAR(pb->memberid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfGOAInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AppId;	// 活动平台应用标识

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Version;	// 事件版本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Env;	// 当前环境

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Url;	// 平台连接

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Authorization;	// 凭证

};
static void _ConvertPbToFCSNtfGOAInfo(FCSNtfGOAInfo &msg, const msg::CSNtfGOAInfo *pb) {
	msg.AppId=UTF8_TO_TCHAR(pb->appid().c_str());
	msg.Version=UTF8_TO_TCHAR(pb->version().c_str());
	msg.Env=UTF8_TO_TCHAR(pb->env().c_str());
	msg.Url=UTF8_TO_TCHAR(pb->url().c_str());
	msg.Authorization=UTF8_TO_TCHAR(pb->authorization().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfTasksInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTTasks Tasks;	//任务信息

};
static void _ConvertPbToFCSNtfTasksInfo(FCSNtfTasksInfo &msg, const msg::CSNtfTasksInfo *pb) {
	_ConvertPbToFCSDTTasks(msg.Tasks, &pb->tasks());
}


USTRUCT(BlueprintType)
struct  FCSNtfPvpAwardsInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFCSNtfPvpAwardsInfo(FCSNtfPvpAwardsInfo &msg, const msg::CSNtfPvpAwardsInfo *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfUIForbid {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, bool> UI;	//bool为true代表 关掉

};
static void _ConvertPbToFCSNtfUIForbid(FCSNtfUIForbid &msg, const msg::CSNtfUIForbid *pb) {

    for (auto it = pb->ui().begin(); it != pb->ui().end(); it++) {
        bool tmp_value;
        tmp_value=it->second;
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.UI.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfAdDiscount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRandDiscount RandDiscount;	//观看广告抽取商城优惠

};
static void _ConvertPbToFCSNtfAdDiscount(FCSNtfAdDiscount &msg, const msg::CSNtfAdDiscount *pb) {
	_ConvertPbToFRandDiscount(msg.RandDiscount, &pb->randdiscount());
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateHotDot {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateHotDot(FCSRspUpdateHotDot &msg, const msg::CSRspUpdateHotDot *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateHotDot {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;	//模块名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHotDotInfo Info;	//活动信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int opt;	// opt==1增加 opt ==2删除

};
static void _ConvertPbToFCSReqUpdateHotDot(FCSReqUpdateHotDot &msg, const msg::CSReqUpdateHotDot *pb) {
	msg.name=UTF8_TO_TCHAR(pb->name().c_str());
	_ConvertPbToFHotDotInfo(msg.Info, &pb->info());
	msg.opt=pb->opt();
}


USTRUCT(BlueprintType)
struct  FCSReqQueryHotDot {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//模块名字

};
static void _ConvertPbToFCSReqQueryHotDot(FCSReqQueryHotDot &msg, const msg::CSReqQueryHotDot *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspQueryHotDot {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FHotDotInfo> Info;	//活动信息

};
static void _ConvertPbToFCSRspQueryHotDot(FCSRspQueryHotDot &msg, const msg::CSRspQueryHotDot *pb) {

    for (auto it = pb->info().begin(); it != pb->info().end(); it++) {
        FHotDotInfo tmp_value;
        _ConvertPbToFHotDotInfo(tmp_value, &it->second);
        FString tmp_key;
        tmp_key=UTF8_TO_TCHAR(it->first.c_str());
        msg.Info.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSReqBuyChallengeCount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int grpId;	//活动组Id

};
static void _ConvertPbToFCSReqBuyChallengeCount(FCSReqBuyChallengeCount &msg, const msg::CSReqBuyChallengeCount *pb) {
	msg.grpId=pb->grpid();
}


USTRUCT(BlueprintType)
struct  FCSRspBuyChallengeCount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalBuyChallengeCount;	//总共购买挑战次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuyChallengeCount;	//今日购买挑战次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

};
static void _ConvertPbToFCSRspBuyChallengeCount(FCSRspBuyChallengeCount &msg, const msg::CSRspBuyChallengeCount *pb) {
	msg.TotalBuyChallengeCount=pb->totalbuychallengecount();
	msg.BuyChallengeCount=pb->buychallengecount();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqGetPveRank {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GrpId;	//活动组id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BeginIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Daily;	//当日排行榜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVERANKTYPE RankType;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;	//当为custom 是 需要填写

};
static void _ConvertPbToFCSReqGetPveRank(FCSReqGetPveRank &msg, const msg::CSReqGetPveRank *pb) {
	msg.GrpId=pb->grpid();
	msg.BeginIdx=pb->beginidx();
	msg.Daily=pb->daily();
	msg.RankType=(EPVERANKTYPE)pb->ranktype();
	msg.PveId=pb->pveid();
}


USTRUCT(BlueprintType)
struct  FCSRspGetPveRank {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTNumRankItem> items;	//排行榜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int endIdx;

	uint64 Count;	//总数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTNumRankItem Self;	//自身

};
static void _ConvertPbToFCSRspGetPveRank(FCSRspGetPveRank &msg, const msg::CSRspGetPveRank *pb) {
	for (int i = 0; i < pb->items().size(); i++) {
		auto &a = pb->items().Get(i);
		FCSDTNumRankItem tmp;
		_ConvertPbToFCSDTNumRankItem(tmp, &a);
		msg.items.Add(tmp);
	}
	msg.endIdx=pb->endidx();
	msg.Count=pb->count();
	_ConvertPbToFCSDTNumRankItem(msg.Self, &pb->self());
}


USTRUCT(BlueprintType)
struct  FCSRspAuthAccount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMultiPlayer> MultiPlayer;	// 用户信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NewPlayer;	// 是否为新用户

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannleyType;	// 解绑渠道

};
static void _ConvertPbToFCSRspAuthAccount(FCSRspAuthAccount &msg, const msg::CSRspAuthAccount *pb) {
	for (int i = 0; i < pb->multiplayer().size(); i++) {
		auto &a = pb->multiplayer().Get(i);
		FMultiPlayer tmp;
		_ConvertPbToFMultiPlayer(tmp, &a);
		msg.MultiPlayer.Add(tmp);
	}
	msg.NewPlayer=pb->newplayer();
	msg.ChannleyType=(ECHANELTYPE)pb->channleytype();
}


USTRUCT(BlueprintType)
struct  FCSReqUnbindAccount {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqUnbindAccount(FCSReqUnbindAccount &msg, const msg::CSReqUnbindAccount *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspUnbindAccount {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUnbindAccount(FCSRspUnbindAccount &msg, const msg::CSRspUnbindAccount *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqOAuthApp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Env;	// "QA", "prod"

};
static void _ConvertPbToFCSReqOAuthApp(FCSReqOAuthApp &msg, const msg::CSReqOAuthApp *pb) {
	msg.Env=UTF8_TO_TCHAR(pb->env().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspOAuthApp {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SecretToken;

};
static void _ConvertPbToFCSRspOAuthApp(FCSRspOAuthApp &msg, const msg::CSRspOAuthApp *pb) {
	msg.Token=UTF8_TO_TCHAR(pb->token().c_str());
	msg.SecretToken=UTF8_TO_TCHAR(pb->secrettoken().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqBagToItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Page;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OneKey;

};
static void _ConvertPbToFCSReqBagToItem(FCSReqBagToItem &msg, const msg::CSReqBagToItem *pb) {
	msg.Page=pb->page();
	msg.UId=UTF8_TO_TCHAR(pb->uid().c_str());
	msg.OneKey=pb->onekey();
}


USTRUCT(BlueprintType)
struct  FCSRspBagToItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Award;	//转移背包物品到玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consume;	//

};
static void _ConvertPbToFCSRspBagToItem(FCSRspBagToItem &msg, const msg::CSRspBagToItem *pb) {
	for (int i = 0; i < pb->award().size(); i++) {
		auto &a = pb->award().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Award.Add(tmp);
	}
	for (int i = 0; i < pb->consume().size(); i++) {
		auto &a = pb->consume().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consume.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqIdentifyItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItemID Item;	//鉴定的物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗的材料

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	//槽位(棋子皮肤需要)

};
static void _ConvertPbToFCSReqIdentifyItem(FCSReqIdentifyItem &msg, const msg::CSReqIdentifyItem *pb) {
	_ConvertPbToFCSDTItemID(msg.Item, &pb->item());
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspIdentifyItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//鉴定结果

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSRspIdentifyItem(FCSRspIdentifyItem &msg, const msg::CSRspIdentifyItem *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqInsetItemAffix {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItemID Item;	//物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItemID Affix;	//词缀

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	//槽位

};
static void _ConvertPbToFCSReqInsetItemAffix(FCSReqInsetItemAffix &msg, const msg::CSReqInsetItemAffix *pb) {
	_ConvertPbToFCSDTItemID(msg.Item, &pb->item());
	_ConvertPbToFCSDTItemID(msg.Affix, &pb->affix());
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspInsetItemAffix {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItem Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	//槽位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSRspInsetItemAffix(FCSRspInsetItemAffix &msg, const msg::CSRspInsetItemAffix *pb) {
	_ConvertPbToFCSDTItem(msg.Item, &pb->item());
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqUnsetItemAffix {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTItemID Item;	//物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	//槽位

};
static void _ConvertPbToFCSReqUnsetItemAffix(FCSReqUnsetItemAffix &msg, const msg::CSReqUnsetItemAffix *pb) {
	_ConvertPbToFCSDTItemID(msg.Item, &pb->item());
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUnsetItemAffix {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//提取物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Slot;	//槽位

};
static void _ConvertPbToFCSRspUnsetItemAffix(FCSRspUnsetItemAffix &msg, const msg::CSRspUnsetItemAffix *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.Slot=UTF8_TO_TCHAR(pb->slot().c_str());
}


USTRUCT(BlueprintType)
struct  FCSNtfItemAttributes {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Item;

};
static void _ConvertPbToFCSNtfItemAttributes(FCSNtfItemAttributes &msg, const msg::CSNtfItemAttributes *pb) {
	for (int i = 0; i < pb->item().size(); i++) {
		auto &a = pb->item().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Item.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfUpdatePvpData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	//玩家索引

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FUpdatePlayerData PlayerData;	//更新玩家数据

};
static void _ConvertPbToFCSNtfUpdatePvpData(FCSNtfUpdatePvpData &msg, const msg::CSNtfUpdatePvpData *pb) {
	msg.Index=pb->index();
	_ConvertPbToFUpdatePlayerData(msg.PlayerData, &pb->playerdata());
}


USTRUCT(BlueprintType)
struct  FCSNtfUpgradePassport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TypeIds;	//通行证类型IDList

};
static void _ConvertPbToFCSNtfUpgradePassport(FCSNtfUpgradePassport &msg, const msg::CSNtfUpgradePassport *pb) {
	for (int i = 0; i < pb->typeids().size(); i++) {
		auto &a = pb->typeids().Get(i);
		int tmp;
		tmp=a;
		msg.TypeIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqCheckCancel {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqCheckCancel(FCSReqCheckCancel &msg, const msg::CSReqCheckCancel *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspCheckCancel {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspCheckCancel(FCSRspCheckCancel &msg, const msg::CSRspCheckCancel *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqCancelAccount {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;

};
static void _ConvertPbToFCSReqCancelAccount(FCSReqCancelAccount &msg, const msg::CSReqCancelAccount *pb) {
	msg.ChannelId=UTF8_TO_TCHAR(pb->channelid().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
}


USTRUCT(BlueprintType)
struct  FCSRspCancelAccount {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspCancelAccount(FCSRspCancelAccount &msg, const msg::CSRspCancelAccount *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateCardGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlanId;	//方案id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TypeId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FChessIds> ChessIds;	//棋子质量：棋子ids

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//需要更新名字 就传 不需要就不管

};
static void _ConvertPbToFCSReqUpdateCardGroup(FCSReqUpdateCardGroup &msg, const msg::CSReqUpdateCardGroup *pb) {
	msg.PlanId=pb->planid();
	msg.TypeId=pb->typeid_();

    for (auto it = pb->chessids().begin(); it != pb->chessids().end(); it++) {
        FChessIds tmp_value;
        _ConvertPbToFChessIds(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.ChessIds.Add(tmp_key, tmp_value);
    }
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateCardGroup {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateCardGroup(FCSRspUpdateCardGroup &msg, const msg::CSRspUpdateCardGroup *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateCardGroupName {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlanId;	//方案id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TypeId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//方案名

};
static void _ConvertPbToFCSReqUpdateCardGroupName(FCSReqUpdateCardGroupName &msg, const msg::CSReqUpdateCardGroupName *pb) {
	msg.PlanId=pb->planid();
	msg.TypeId=pb->typeid_();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateCardGroupName {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateCardGroupName(FCSRspUpdateCardGroupName &msg, const msg::CSRspUpdateCardGroupName *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqBuyPveBuff {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuffId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVECONSUMETYPE ConsumeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConsumeId;	//如果为物品类型 则 传入消耗得id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;	//pveId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//购买次数

};
static void _ConvertPbToFCSReqBuyPveBuff(FCSReqBuyPveBuff &msg, const msg::CSReqBuyPveBuff *pb) {
	msg.BuffId=pb->buffid();
	msg.ConsumeType=(EPVECONSUMETYPE)pb->consumetype();
	msg.ConsumeId=pb->consumeid();
	msg.PveId=pb->pveid();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSRspBuyPveBuff {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPveConsume Consume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FPveBuff> Awards;	// 奖励的buff

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;	//pveid

};
static void _ConvertPbToFCSRspBuyPveBuff(FCSRspBuyPveBuff &msg, const msg::CSRspBuyPveBuff *pb) {
	_ConvertPbToFPveConsume(msg.Consume, &pb->consume());

    for (auto it = pb->awards().begin(); it != pb->awards().end(); it++) {
        FPveBuff tmp_value;
        _ConvertPbToFPveBuff(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.Awards.Add(tmp_key, tmp_value);
    }
	msg.PveId=pb->pveid();
}


USTRUCT(BlueprintType)
struct  FCSReqSetCardGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlanId;	//方案id

};
static void _ConvertPbToFCSReqSetCardGroup(FCSReqSetCardGroup &msg, const msg::CSReqSetCardGroup *pb) {
	msg.PlanId=pb->planid();
}


USTRUCT(BlueprintType)
struct  FCSRspSetCardGroup {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetCardGroup(FCSRspSetCardGroup &msg, const msg::CSRspSetCardGroup *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqBuyPveChessTemplate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;	//pveId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVECONSUMETYPE ConsumeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConsumeId;	//如果为物品类型 则 传入消耗得id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//棋子id  或者技能id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVECHESSTYPE ChessType;

};
static void _ConvertPbToFCSReqBuyPveChessTemplate(FCSReqBuyPveChessTemplate &msg, const msg::CSReqBuyPveChessTemplate *pb) {
	msg.PveId=pb->pveid();
	msg.ConsumeType=(EPVECONSUMETYPE)pb->consumetype();
	msg.ConsumeId=pb->consumeid();
	msg.Id=pb->id();
	msg.ChessType=(EPVECHESSTYPE)pb->chesstype();
}


USTRUCT(BlueprintType)
struct  FCSRspBuyPveChessTemplate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPveConsume Consume;

};
static void _ConvertPbToFCSRspBuyPveChessTemplate(FCSRspBuyPveChessTemplate &msg, const msg::CSRspBuyPveChessTemplate *pb) {
	_ConvertPbToFPveConsume(msg.Consume, &pb->consume());
}


USTRUCT(BlueprintType)
struct  FCSReqPveUnlockChessTemplate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;	//pveId

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FUnlockChessTemplate> ChessIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVECHESSTYPE ChessType;

};
static void _ConvertPbToFCSReqPveUnlockChessTemplate(FCSReqPveUnlockChessTemplate &msg, const msg::CSReqPveUnlockChessTemplate *pb) {
	msg.PveId=pb->pveid();
	for (int i = 0; i < pb->chessids().size(); i++) {
		auto &a = pb->chessids().Get(i);
		FUnlockChessTemplate tmp;
		_ConvertPbToFUnlockChessTemplate(tmp, &a);
		msg.ChessIds.Add(tmp);
	}
	msg.ChessType=(EPVECHESSTYPE)pb->chesstype();
}


USTRUCT(BlueprintType)
struct  FCSRspPveUnlockChessTemplate {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPveUnlockChessTemplate(FCSRspPveUnlockChessTemplate &msg, const msg::CSRspPveUnlockChessTemplate *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqPveSetTeamDeBuff {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> DeBuffIds;	//

};
static void _ConvertPbToFCSReqPveSetTeamDeBuff(FCSReqPveSetTeamDeBuff &msg, const msg::CSReqPveSetTeamDeBuff *pb) {
	for (int i = 0; i < pb->debuffids().size(); i++) {
		auto &a = pb->debuffids().Get(i);
		int tmp;
		tmp=a;
		msg.DeBuffIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspPveSetTeamDeBuff {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspPveSetTeamDeBuff(FCSRspPveSetTeamDeBuff &msg, const msg::CSRspPveSetTeamDeBuff *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfUpdateTeamDeBuff {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> DeBuffIds;	//

};
static void _ConvertPbToFCSNtfUpdateTeamDeBuff(FCSNtfUpdateTeamDeBuff &msg, const msg::CSNtfUpdateTeamDeBuff *pb) {
	for (int i = 0; i < pb->debuffids().size(); i++) {
		auto &a = pb->debuffids().Get(i);
		int tmp;
		tmp=a;
		msg.DeBuffIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqChoseCardGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlanId;	//

};
static void _ConvertPbToFCSReqChoseCardGroup(FCSReqChoseCardGroup &msg, const msg::CSReqChoseCardGroup *pb) {
	msg.PlanId=pb->planid();
}


USTRUCT(BlueprintType)
struct  FCSRspChoseCardGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerIdx;	//玩家索引

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlanId;	//方案id

};
static void _ConvertPbToFCSRspChoseCardGroup(FCSRspChoseCardGroup &msg, const msg::CSRspChoseCardGroup *pb) {
	msg.PlayerIdx=pb->playeridx();
	msg.PlanId=pb->planid();
}


USTRUCT(BlueprintType)
struct  FCSNtfPveEval {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score;	//实际增加的积分（内核积分+内核积分*词缀buff+内核积分*vip特权）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, int> Consume;	//消耗得次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankScore;	//加在排行版的分数/结算显示的分数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Unlock;	//是否解锁噩梦模式

};
static void _ConvertPbToFCSNtfPveEval(FCSNtfPveEval &msg, const msg::CSNtfPveEval *pb) {
	msg.PveId=pb->pveid();
	msg.Score=pb->score();

    for (auto it = pb->consume().begin(); it != pb->consume().end(); it++) {
        int tmp_value;
        tmp_value=it->second;
        int tmp_key;
        tmp_key=it->first;
        msg.Consume.Add(tmp_key, tmp_value);
    }
	msg.RankScore=pb->rankscore();
	msg.Unlock=pb->unlock();
}


USTRUCT(BlueprintType)
struct  FCSReqRemoveOvertimeBuff {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> BuffIds;	//

};
static void _ConvertPbToFCSReqRemoveOvertimeBuff(FCSReqRemoveOvertimeBuff &msg, const msg::CSReqRemoveOvertimeBuff *pb) {
	msg.PveId=pb->pveid();
	for (int i = 0; i < pb->buffids().size(); i++) {
		auto &a = pb->buffids().Get(i);
		int tmp;
		tmp=a;
		msg.BuffIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspRemoveOvertimeBuff {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> BuffIds;	//

};
static void _ConvertPbToFCSRspRemoveOvertimeBuff(FCSRspRemoveOvertimeBuff &msg, const msg::CSRspRemoveOvertimeBuff *pb) {
	msg.PveId=pb->pveid();
	for (int i = 0; i < pb->buffids().size(); i++) {
		auto &a = pb->buffids().Get(i);
		int tmp;
		tmp=a;
		msg.BuffIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfUnlockCardGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCardGroupData Data;

};
static void _ConvertPbToFCSNtfUnlockCardGroup(FCSNtfUnlockCardGroup &msg, const msg::CSNtfUnlockCardGroup *pb) {
	_ConvertPbToFCardGroupData(msg.Data, &pb->data());
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateNewCardGroupSign {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqUpdateNewCardGroupSign(FCSReqUpdateNewCardGroupSign &msg, const msg::CSReqUpdateNewCardGroupSign *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateNewCardGroupSign {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateNewCardGroupSign(FCSRspUpdateNewCardGroupSign &msg, const msg::CSRspUpdateNewCardGroupSign *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfCustomPveActivity {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GrpId;	//活动组id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score;	//增加的score

};
static void _ConvertPbToFCSNtfCustomPveActivity(FCSNtfCustomPveActivity &msg, const msg::CSNtfCustomPveActivity *pb) {
	msg.GrpId=pb->grpid();
	msg.Score=pb->score();
}


USTRUCT(BlueprintType)
struct  FCSNtfGmBan {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGmBan GmBan;

};
static void _ConvertPbToFCSNtfGmBan(FCSNtfGmBan &msg, const msg::CSNtfGmBan *pb) {
	_ConvertPbToFGmBan(msg.GmBan, &pb->gmban());
}


USTRUCT(BlueprintType)
struct  FCSReqMentorUpdateSetting {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Sign;	//拜师宣言

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tag;	//标签

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool InviteSwitch;	//拜师开关 开true 关 false

};
static void _ConvertPbToFCSReqMentorUpdateSetting(FCSReqMentorUpdateSetting &msg, const msg::CSReqMentorUpdateSetting *pb) {
	msg.Sign=UTF8_TO_TCHAR(pb->sign().c_str());
	msg.Tag=pb->tag();
	msg.InviteSwitch=pb->inviteswitch();
}


USTRUCT(BlueprintType)
struct  FCSRspMentorUpdateSetting {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspMentorUpdateSetting(FCSRspMentorUpdateSetting &msg, const msg::CSRspMentorUpdateSetting *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqMentorInvite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORSHIP Type;	//邀请类型  师傅发起 就传徒弟 代表的时候 徒弟类型的信息，徒弟发起就传师傅 代表的是 请求师傅收徒的类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//拜师/收徒 内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//邀请id

};
static void _ConvertPbToFCSReqMentorInvite(FCSReqMentorInvite &msg, const msg::CSReqMentorInvite *pb) {
	msg.Type=(EMENTORSHIP)pb->type();
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspMentorInvite {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspMentorInvite(FCSRspMentorInvite &msg, const msg::CSRspMentorInvite *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqMentorConfirmInvite {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	// 确认消息中的玩家id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAccept;	//是否接受

};
static void _ConvertPbToFCSReqMentorConfirmInvite(FCSReqMentorConfirmInvite &msg, const msg::CSReqMentorConfirmInvite *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.IsAccept=pb->isaccept();
}


USTRUCT(BlueprintType)
struct  FCSRspMentorConfirmInvite {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspMentorConfirmInvite(FCSRspMentorConfirmInvite &msg, const msg::CSRspMentorConfirmInvite *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqMentorRecommendList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORSHIP Type;	// 推荐表类型 查看类型对应的type

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StartIdx;	//分页起始页

};
static void _ConvertPbToFCSReqMentorRecommendList(FCSReqMentorRecommendList &msg, const msg::CSReqMentorRecommendList *pb) {
	msg.Type=(EMENTORSHIP)pb->type();
	msg.StartIdx=pb->startidx();
}


USTRUCT(BlueprintType)
struct  FCSRspMentorRecommendList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTMentorRecommendPlayer> Ids;	//列表返回的用户

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//总共数量

};
static void _ConvertPbToFCSRspMentorRecommendList(FCSRspMentorRecommendList &msg, const msg::CSRspMentorRecommendList *pb) {
	for (int i = 0; i < pb->ids().size(); i++) {
		auto &a = pb->ids().Get(i);
		FCSDTMentorRecommendPlayer tmp;
		_ConvertPbToFCSDTMentorRecommendPlayer(tmp, &a);
		msg.Ids.Add(tmp);
	}
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FCSReqMentorGetTaskAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TaskId;	//任务id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PupilId;	//师傅 领取徒弟任务 时 传递 徒弟id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORSHIPTASK TaskType;	//领取的任务类型 必穿

};
static void _ConvertPbToFCSReqMentorGetTaskAward(FCSReqMentorGetTaskAward &msg, const msg::CSReqMentorGetTaskAward *pb) {
	for (int i = 0; i < pb->taskid().size(); i++) {
		auto &a = pb->taskid().Get(i);
		int tmp;
		tmp=a;
		msg.TaskId.Add(tmp);
	}
	msg.PupilId=UTF8_TO_TCHAR(pb->pupilid().c_str());
	msg.TaskType=(EMENTORSHIPTASK)pb->tasktype();
}


USTRUCT(BlueprintType)
struct  FCSRspMentorGetTaskAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//任务返回的奖励

};
static void _ConvertPbToFCSRspMentorGetTaskAward(FCSRspMentorGetTaskAward &msg, const msg::CSRspMentorGetTaskAward *pb) {
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqMentorGraduate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//徒弟id 师傅id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAutoGraduate;	//是否自动毕业

};
static void _ConvertPbToFCSReqMentorGraduate(FCSReqMentorGraduate &msg, const msg::CSReqMentorGraduate *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.IsAutoGraduate=pb->isautograduate();
}


USTRUCT(BlueprintType)
struct  FCSRspMentorGraduate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPUPILSTAT Stat;	//徒弟状态

};
static void _ConvertPbToFCSRspMentorGraduate(FCSRspMentorGraduate &msg, const msg::CSRspMentorGraduate *pb) {
	msg.Stat=(EPUPILSTAT)pb->stat();
}


USTRUCT(BlueprintType)
struct  FCSReqMentorRelieveRelation {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//徒弟id 师傅id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORSHIP MsType;	// 由谁提出来的 徒弟提起就传徒弟类型 师傅提起就传师傅类型

};
static void _ConvertPbToFCSReqMentorRelieveRelation(FCSReqMentorRelieveRelation &msg, const msg::CSReqMentorRelieveRelation *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
	msg.MsType=(EMENTORSHIP)pb->mstype();
}


USTRUCT(BlueprintType)
struct  FCSRspMentorRelieveRelation {
	GENERATED_BODY()

	int64 PunishTime;	//惩罚时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPUPILSTAT Stat;	//解除关系人的状态

};
static void _ConvertPbToFCSRspMentorRelieveRelation(FCSRspMentorRelieveRelation &msg, const msg::CSRspMentorRelieveRelation *pb) {
	msg.PunishTime=pb->punishtime();
	msg.Stat=(EPUPILSTAT)pb->stat();
}


USTRUCT(BlueprintType)
struct  FCSReqGetMentorInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TargetId;	// 不传查本人 传入查询的用户id

};
static void _ConvertPbToFCSReqGetMentorInfo(FCSReqGetMentorInfo &msg, const msg::CSReqGetMentorInfo *pb) {
	msg.TargetId=UTF8_TO_TCHAR(pb->targetid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspGetMentorInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMentorInfo Info;

};
static void _ConvertPbToFCSRspGetMentorInfo(FCSRspGetMentorInfo &msg, const msg::CSRspGetMentorInfo *pb) {
	_ConvertPbToFMentorInfo(msg.Info, &pb->info());
}


USTRUCT(BlueprintType)
struct  FCSReqMentorGetInviteMsg {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqMentorGetInviteMsg(FCSReqMentorGetInviteMsg &msg, const msg::CSReqMentorGetInviteMsg *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspMentorGetInviteMsg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorInviteMsg> Info;	//邀约信息

};
static void _ConvertPbToFCSRspMentorGetInviteMsg(FCSRspMentorGetInviteMsg &msg, const msg::CSRspMentorGetInviteMsg *pb) {
	for (int i = 0; i < pb->info().size(); i++) {
		auto &a = pb->info().Get(i);
		FMentorInviteMsg tmp;
		_ConvertPbToFMentorInviteMsg(tmp, &a);
		msg.Info.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfMentorInviteMsg {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorInviteMsg> Info;	//消息

};
static void _ConvertPbToFCSNtfMentorInviteMsg(FCSNtfMentorInviteMsg &msg, const msg::CSNtfMentorInviteMsg *pb) {
	for (int i = 0; i < pb->info().size(); i++) {
		auto &a = pb->info().Get(i);
		FMentorInviteMsg tmp;
		_ConvertPbToFMentorInviteMsg(tmp, &a);
		msg.Info.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfBecomeMentor {
	GENERATED_BODY()

};
static void _ConvertPbToFCSNtfBecomeMentor(FCSNtfBecomeMentor &msg, const msg::CSNtfBecomeMentor *pb) {
}


USTRUCT(BlueprintType)
struct  FCSNtfMentorRelation {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Mentor;	//师傅id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Pupil;	//徒弟id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPUPILSTAT Stat;	//徒弟状态 更新

	int64 AddIntimacy;	//增加的亲密度

};
static void _ConvertPbToFCSNtfMentorRelation(FCSNtfMentorRelation &msg, const msg::CSNtfMentorRelation *pb) {
	msg.Mentor=UTF8_TO_TCHAR(pb->mentor().c_str());
	msg.Pupil=UTF8_TO_TCHAR(pb->pupil().c_str());
	msg.Stat=(EPUPILSTAT)pb->stat();
	msg.AddIntimacy=pb->addintimacy();
}


USTRUCT(BlueprintType)
struct  FCSNtfPupilTaskUpdate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Pupil;	//徒弟id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTTaskItem> Task;	//任务id

};
static void _ConvertPbToFCSNtfPupilTaskUpdate(FCSNtfPupilTaskUpdate &msg, const msg::CSNtfPupilTaskUpdate *pb) {
	msg.Pupil=UTF8_TO_TCHAR(pb->pupil().c_str());
	for (int i = 0; i < pb->task().size(); i++) {
		auto &a = pb->task().Get(i);
		FCSDTTaskItem tmp;
		_ConvertPbToFCSDTTaskItem(tmp, &a);
		msg.Task.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfMentorLevel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORLEVEL Level;	//是否等级更新

};
static void _ConvertPbToFCSNtfMentorLevel(FCSNtfMentorLevel &msg, const msg::CSNtfMentorLevel *pb) {
	msg.Level=(EMENTORLEVEL)pb->level();
}


USTRUCT(BlueprintType)
struct  FCSRspTeamMsg {
	GENERATED_BODY()

	int64 SilenceTime;	// 禁言时间

};
static void _ConvertPbToFCSRspTeamMsg(FCSRspTeamMsg &msg, const msg::CSRspTeamMsg *pb) {
	msg.SilenceTime=pb->silencetime();
}


USTRUCT(BlueprintType)
struct  FCSRspChatMsg {
	GENERATED_BODY()

	int64 SilenceTime;	// 禁言时间

};
static void _ConvertPbToFCSRspChatMsg(FCSRspChatMsg &msg, const msg::CSRspChatMsg *pb) {
	msg.SilenceTime=pb->silencetime();
}


USTRUCT(BlueprintType)
struct  FCSRspChannelChat {
	GENERATED_BODY()

	int64 SilenceTime;	// 禁言时间

};
static void _ConvertPbToFCSRspChannelChat(FCSRspChannelChat &msg, const msg::CSRspChannelChat *pb) {
	msg.SilenceTime=pb->silencetime();
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateCardGroupBetter {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCardGroupChess> ChessIds;	//更新棋子id  全量传

};
static void _ConvertPbToFCSReqUpdateCardGroupBetter(FCSReqUpdateCardGroupBetter &msg, const msg::CSReqUpdateCardGroupBetter *pb) {
	for (int i = 0; i < pb->chessids().size(); i++) {
		auto &a = pb->chessids().Get(i);
		FCardGroupChess tmp;
		_ConvertPbToFCardGroupChess(tmp, &a);
		msg.ChessIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateCardGroupBetter {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateCardGroupBetter(FCSRspUpdateCardGroupBetter &msg, const msg::CSRspUpdateCardGroupBetter *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqUpdateCardGroupSetting {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAutoAddCardGroupToKernel;	//是否开局自动加入局内

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoAddChessTimes;	//自动加入常用列表 0代表关

};
static void _ConvertPbToFCSReqUpdateCardGroupSetting(FCSReqUpdateCardGroupSetting &msg, const msg::CSReqUpdateCardGroupSetting *pb) {
	msg.IsAutoAddCardGroupToKernel=pb->isautoaddcardgrouptokernel();
	msg.AutoAddChessTimes=pb->autoaddchesstimes();
}


USTRUCT(BlueprintType)
struct  FCSRspUpdateCardGroupSetting {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspUpdateCardGroupSetting(FCSRspUpdateCardGroupSetting &msg, const msg::CSRspUpdateCardGroupSetting *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqSetContent {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//内容

};
static void _ConvertPbToFCSReqSetContent(FCSReqSetContent &msg, const msg::CSReqSetContent *pb) {
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
}


USTRUCT(BlueprintType)
struct  FCSRspSetAuctionName {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗

};
static void _ConvertPbToFCSRspSetAuctionName(FCSRspSetAuctionName &msg, const msg::CSRspSetAuctionName *pb) {
	msg.Count=pb->count();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspSetAuctionRemark {
	GENERATED_BODY()

};
static void _ConvertPbToFCSRspSetAuctionRemark(FCSRspSetAuctionRemark &msg, const msg::CSRspSetAuctionRemark *pb) {
}


USTRUCT(BlueprintType)
struct  FCSReqGetBalance {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqGetBalance(FCSReqGetBalance &msg, const msg::CSReqGetBalance *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspGetBalance {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diamond;	// 甜甜圈

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WalletServiceCharge;	// 零钱包服务费（万分比*10000）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WalletServiceChargeMinNum;	// 零钱包服务费下限（固定值、整数）

};
static void _ConvertPbToFCSRspGetBalance(FCSRspGetBalance &msg, const msg::CSRspGetBalance *pb) {
	msg.Diamond=pb->diamond();
	msg.WalletServiceCharge=pb->walletservicecharge();
	msg.WalletServiceChargeMinNum=pb->walletservicechargeminnum();
}


USTRUCT(BlueprintType)
struct  FCSReqRechargeBalance {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSReqRechargeBalance(FCSReqRechargeBalance &msg, const msg::CSReqRechargeBalance *pb) {
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSRspRechargeBalance {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diamond;	// 甜甜圈

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;

};
static void _ConvertPbToFCSRspRechargeBalance(FCSRspRechargeBalance &msg, const msg::CSRspRechargeBalance *pb) {
	msg.Diamond=pb->diamond();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqWithdrawBalance {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diamond;	// 甜甜圈

};
static void _ConvertPbToFCSReqWithdrawBalance(FCSReqWithdrawBalance &msg, const msg::CSReqWithdrawBalance *pb) {
	msg.Diamond=pb->diamond();
}


USTRUCT(BlueprintType)
struct  FCSRspWithdrawBalance {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diamond;	// 甜甜圈

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFCSRspWithdrawBalance(FCSRspWithdrawBalance &msg, const msg::CSRspWithdrawBalance *pb) {
	msg.Diamond=pb->diamond();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSReqPersonalRecommendMall {
	GENERATED_BODY()

};
static void _ConvertPbToFCSReqPersonalRecommendMall(FCSReqPersonalRecommendMall &msg, const msg::CSReqPersonalRecommendMall *pb) {
}


USTRUCT(BlueprintType)
struct  FCSRspPersonalRecommendMall {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, FMallIDs> MallTabs;	//商城 map<栏位, ids>

};
static void _ConvertPbToFCSRspPersonalRecommendMall(FCSRspPersonalRecommendMall &msg, const msg::CSRspPersonalRecommendMall *pb) {

    for (auto it = pb->malltabs().begin(); it != pb->malltabs().end(); it++) {
        FMallIDs tmp_value;
        _ConvertPbToFMallIDs(tmp_value, &it->second);
        int tmp_key;
        tmp_key=it->first;
        msg.MallTabs.Add(tmp_key, tmp_value);
    }
}


USTRUCT(BlueprintType)
struct  FCSNtfCurDressUpdate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAward Award;	//更新物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DressSlot;	//棋子皮肤槽位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTItemID> ChessPlayerIds;	//装扮物品的所有棋手

};
static void _ConvertPbToFCSNtfCurDressUpdate(FCSNtfCurDressUpdate &msg, const msg::CSNtfCurDressUpdate *pb) {
	_ConvertPbToFAward(msg.Award, &pb->award());
	msg.DressSlot=UTF8_TO_TCHAR(pb->dressslot().c_str());
	for (int i = 0; i < pb->chessplayerids().size(); i++) {
		auto &a = pb->chessplayerids().Get(i);
		FCSDTItemID tmp;
		_ConvertPbToFCSDTItemID(tmp, &a);
		msg.ChessPlayerIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCSNtfChangeExchangeMark {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEXCHANGESTATE ExchangeState;	//拍卖行标记状态

};
static void _ConvertPbToFCSNtfChangeExchangeMark(FCSNtfChangeExchangeMark &msg, const msg::CSNtfChangeExchangeMark *pb) {
	msg.ExchangeState=(EEXCHANGESTATE)pb->exchangestate();
}


USTRUCT(BlueprintType)
struct  FCSReqGetMedalChestAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Season;	//赛季

};
static void _ConvertPbToFCSReqGetMedalChestAward(FCSReqGetMedalChestAward &msg, const msg::CSReqGetMedalChestAward *pb) {
	msg.Season=pb->season();
}


USTRUCT(BlueprintType)
struct  FCSRspGetMedalChestAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Award;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESOURCE Source;	//来源

};
static void _ConvertPbToFCSRspGetMedalChestAward(FCSRspGetMedalChestAward &msg, const msg::CSRspGetMedalChestAward *pb) {
	for (int i = 0; i < pb->award().size(); i++) {
		auto &a = pb->award().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Award.Add(tmp);
	}
	msg.Source=(ESOURCE)pb->source();
}


USTRUCT(BlueprintType)
struct  FCSNtfRefreshPassport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPASSPORTREFRESH RefreshType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSDTPassport Passport;	//跨周之后会解锁新的通行证任务，需要下发给客户端新的通行证信息，因为有得任务有初始进度

};
static void _ConvertPbToFCSNtfRefreshPassport(FCSNtfRefreshPassport &msg, const msg::CSNtfRefreshPassport *pb) {
	msg.RefreshType=(EPASSPORTREFRESH)pb->refreshtype();
	msg.WeekIndex=pb->weekindex();
	_ConvertPbToFCSDTPassport(msg.Passport, &pb->passport());
}


USTRUCT(BlueprintType)
struct  FCSNtfGmRemoveMail {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailId;

};
static void _ConvertPbToFCSNtfGmRemoveMail(FCSNtfGmRemoveMail &msg, const msg::CSNtfGmRemoveMail *pb) {
	msg.MailId=UTF8_TO_TCHAR(pb->mailid().c_str());
}


USTRUCT(BlueprintType)
struct  FCSReqSetItemAutoUse {
	GENERATED_BODY()

	uint64 ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoFlag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoBuy;

};
static void _ConvertPbToFCSReqSetItemAutoUse(FCSReqSetItemAutoUse &msg, const msg::CSReqSetItemAutoUse *pb) {
	msg.ItemId=pb->itemid();
	msg.AutoFlag=pb->autoflag();
	msg.CurrentUse=pb->currentuse();
	msg.AutoBuy=pb->autobuy();
}


USTRUCT(BlueprintType)
struct  FCSRspSetItemAutoUse {
	GENERATED_BODY()

	uint64 ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoFlag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoBuy;

};
static void _ConvertPbToFCSRspSetItemAutoUse(FCSRspSetItemAutoUse &msg, const msg::CSRspSetItemAutoUse *pb) {
	msg.ItemId=pb->itemid();
	msg.AutoFlag=pb->autoflag();
	msg.CurrentUse=pb->currentuse();
	msg.AutoBuy=pb->autobuy();
}


USTRUCT(BlueprintType)
struct  FCSNtfAutoUseItem {
	GENERATED_BODY()

	uint64 ItemId;	//物品id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UsedCount;	//使用数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TodayUsedCount;	//今日使用数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayLimit;	//日使用限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//剩余数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoFlag;	//默认使用状态

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoBuy;

};
static void _ConvertPbToFCSNtfAutoUseItem(FCSNtfAutoUseItem &msg, const msg::CSNtfAutoUseItem *pb) {
	msg.ItemId=pb->itemid();
	msg.UsedCount=pb->usedcount();
	msg.TodayUsedCount=pb->todayusedcount();
	msg.DayLimit=pb->daylimit();
	msg.Count=pb->count();
	msg.AutoFlag=pb->autoflag();
	msg.AutoBuy=pb->autobuy();
}


