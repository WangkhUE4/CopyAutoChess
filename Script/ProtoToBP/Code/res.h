/*
Proto buf => BP

*/
#pragma once


#include "CoreMinimal.h"
#include "res.pb.h"
#include "common.h"
#include "common.pb.h"
#include "res.generated.h"


UENUM(BlueprintType)
enum class EEXPERIENCE_TYPE: uint8 {
	EXPERIENCE_TYPE_NULL = 0 UMETA(DisplayName="EXPERIENCE_TYPE_NULL"),
	CARD = 1 UMETA(DisplayName="CARD"),
	SKIN = 2 UMETA(DisplayName="SKIN"),
};

UENUM(BlueprintType)
enum class EEGGTYPE: uint8 {
	EGG_NULL = 0 UMETA(DisplayName="EGG_NULL"),
	EGG_COMMON = 1 UMETA(DisplayName="EGG_COMMON"),	//普通扭蛋
	EGG_ACTIVITY = 2 UMETA(DisplayName="EGG_ACTIVITY"),	//活动扭蛋
	EGG_SPECIAL = 3 UMETA(DisplayName="EGG_SPECIAL"),	//特殊扭蛋
};

UENUM(BlueprintType)
enum class EEGGPOOLTYPE: uint8 {
	POOL_NULL = 0 UMETA(DisplayName="POOL_NULL"),
	POOL_COMMON = 1 UMETA(DisplayName="POOL_COMMON"),	//普通随机池
	POOL_MIN_GUARANTEE = 2 UMETA(DisplayName="POOL_MIN_GUARANTEE"),	//保底池
};

UENUM(BlueprintType)
enum class EITEMCLASS1: uint8 {
	ITEMCLASS1_NULL = 0 UMETA(DisplayName="ITEMCLASS1_NULL"),
	ITEMCLASS1_EXP = 1 UMETA(DisplayName="ITEMCLASS1_EXP"),
	ITEMCLASS1_MONEY = 2 UMETA(DisplayName="ITEMCLASS1_MONEY"),
	ITEMCLASS1_ITEM = 3 UMETA(DisplayName="ITEMCLASS1_ITEM"),
	ITEMCLASS1_DRESS = 4 UMETA(DisplayName="ITEMCLASS1_DRESS"),
};

UENUM(BlueprintType)
enum class EITEMCLASS2: uint8 {
	ITEMCLASS2_NULL = 0 UMETA(DisplayName="ITEMCLASS2_NULL"),
	ITEMCLASS2_SKIN = 1 UMETA(DisplayName="ITEMCLASS2_SKIN"),
	ITEMCLASS2_EFFECT = 2 UMETA(DisplayName="ITEMCLASS2_EFFECT"),
	ITEMCLASS2_ACTION = 3 UMETA(DisplayName="ITEMCLASS2_ACTION"),
	ITEMCLASS2_VOICE = 4 UMETA(DisplayName="ITEMCLASS2_VOICE"),
	ITEMCLASS2_EXPRESSION = 5 UMETA(DisplayName="ITEMCLASS2_EXPRESSION"),
	ITEMCLASS2_UI_DRESS = 6 UMETA(DisplayName="ITEMCLASS2_UI_DRESS"),
};

UENUM(BlueprintType)
enum class EPURCHASETYPE: uint8 {
	PURCHASE_INLAND = 0 UMETA(DisplayName="PURCHASE_INLAND"),	//国内版本
	PURCHASE_INTERNATIONAL = 1 UMETA(DisplayName="PURCHASE_INTERNATIONAL"),	//国际版本
};

UENUM(BlueprintType)
enum class ECHARGETYPE: uint8 {
	CHARGE_NULL = 0 UMETA(DisplayName="CHARGE_NULL"),
	CHARGE_COMMON = 1 UMETA(DisplayName="CHARGE_COMMON"),	//普通充值
	CHARGE_FIRST = 2 UMETA(DisplayName="CHARGE_FIRST"),	//首充
	CHARGE_PASSPORT = 3 UMETA(DisplayName="CHARGE_PASSPORT"),	//直购通行证
	CHARGE_GROUPBUY = 4 UMETA(DisplayName="CHARGE_GROUPBUY"),	//活动团购返利
	CHARGE_GIFT = 5 UMETA(DisplayName="CHARGE_GIFT"),	//礼包活动
	CHARGE_MALL = 6 UMETA(DisplayName="CHARGE_MALL"),	//商城活动
	CHARGE_TCARD = 7 UMETA(DisplayName="CHARGE_TCARD"),	//VNG电话卡
	CHARGE_PREORDER = 8 UMETA(DisplayName="CHARGE_PREORDER"),	//预购礼包
};

UENUM(BlueprintType)
enum class EREFRESHTYPE: uint8 {
	REFRESHTYPE_NULL = 0 UMETA(DisplayName="REFRESHTYPE_NULL"),	//不刷新
	REFRESHTYPE_DAY = 1 UMETA(DisplayName="REFRESHTYPE_DAY"),	//每日刷新
	REFRESHTYPE_WEEK = 2 UMETA(DisplayName="REFRESHTYPE_WEEK"),	//每周刷新
};

UENUM(BlueprintType)
enum class EAITRIGGERTYPE: uint8 {
	TRIGGER_BEGIN_TO_PLAY = 0 UMETA(DisplayName="TRIGGER_BEGIN_TO_PLAY"),	//玩家刚开始玩
	TRIGGER_CONTINUOUS_LOSE = 1 UMETA(DisplayName="TRIGGER_CONTINUOUS_LOSE"),	//连续获得较低名次
	TRIGGER_BEFORE_LOWER_CUP = 2 UMETA(DisplayName="TRIGGER_BEFORE_LOWER_CUP"),	//掉段前
	TRIGGER_PLAYER_GO_BACK = 3 UMETA(DisplayName="TRIGGER_PLAYER_GO_BACK"),	//玩家回归
	TRIGGER_LOW_CUP = 4 UMETA(DisplayName="TRIGGER_LOW_CUP"),	//低段位保护
};

UENUM(BlueprintType)
enum class ETIMEFLAG: uint8 {
	TIME_PERMANENT = 0 UMETA(DisplayName="TIME_PERMANENT"),	//永久
	TIME_DAILY = 1 UMETA(DisplayName="TIME_DAILY"),	//每天
	TIME_WEEKLY = 2 UMETA(DisplayName="TIME_WEEKLY"),	//每周
	TIME_MONTHLY = 3 UMETA(DisplayName="TIME_MONTHLY"),	//每月
};

UENUM(BlueprintType)
enum class ECUPTYPE: uint8 {
	CUP_PAWN = 0 UMETA(DisplayName="CUP_PAWN"),	//士兵
	CUP_KNIGHT = 1 UMETA(DisplayName="CUP_KNIGHT"),	//骑士
	CUP_BISHOP = 2 UMETA(DisplayName="CUP_BISHOP"),	//主教
	CUP_ROOK = 3 UMETA(DisplayName="CUP_ROOK"),	//堡垒
	CUP_KING = 4 UMETA(DisplayName="CUP_KING"),	//国王
	CUP_QUEEN = 5 UMETA(DisplayName="CUP_QUEEN"),	//皇后
};

UENUM(BlueprintType)
enum class EDELAYTYPE: uint8 {
	UNCONFIRMED = 0 UMETA(DisplayName="UNCONFIRMED"),	//未确定
	FLUENCY = 1 UMETA(DisplayName="FLUENCY"),	//流畅
	GENERAL = 2 UMETA(DisplayName="GENERAL"),	//一般
	LAG = 3 UMETA(DisplayName="LAG"),	//卡顿
	DIFFICULTY = 4 UMETA(DisplayName="DIFFICULTY"),	//不能玩
	DELAYTYPE_MAX_NUM = 5 UMETA(DisplayName="DELAYTYPE_MAX_NUM"),
};

UENUM(BlueprintType)
enum class ETOURNAMENTTYPE: uint8 {
	TOURNAMENT_UNKNOWN = 0 UMETA(DisplayName="TOURNAMENT_UNKNOWN"),	//未知类型
	TOURNAMENT_TOURNAMENT = 1 UMETA(DisplayName="TOURNAMENT_TOURNAMENT"),	//锦标赛
	TOURNAMENT_OFFICIAL = 2 UMETA(DisplayName="TOURNAMENT_OFFICIAL"),	//官方赛
	TOURNAMENT_CUSTOM = 3 UMETA(DisplayName="TOURNAMENT_CUSTOM"),	//自建赛
};

UENUM(BlueprintType)
enum class ETournamentTimeType: uint8 {
	other = 0 UMETA(DisplayName="other"),	// 一般赛事
	Week = 1 UMETA(DisplayName="Week"),	// 周赛
	Month = 2 UMETA(DisplayName="Month"),	// 月赛
	Season = 3 UMETA(DisplayName="Season"),	// 季赛
};

UENUM(BlueprintType)
enum class EOWNERTYPE: uint8 {
	OWNER_UNKNOWN = 0 UMETA(DisplayName="OWNER_UNKNOWN"),
	OWNER_OFFICIAL = 1 UMETA(DisplayName="OWNER_OFFICIAL"),	//官方
	OWNER_PLAYER = 2 UMETA(DisplayName="OWNER_PLAYER"),	//玩家
};

UENUM(BlueprintType)
enum class EBATTLEGROUPTYPE: uint8 {
	BATTLEGROUP_NULL = 0 UMETA(DisplayName="BATTLEGROUP_NULL"),
	BATTLEGROUP_MATCH = 1 UMETA(DisplayName="BATTLEGROUP_MATCH"),	//匹配战斗组
	BATTLEGROUP_FIXED = 2 UMETA(DisplayName="BATTLEGROUP_FIXED"),	//固定战斗组
};

UENUM(BlueprintType)
enum class ETOURNAMENTAWARDTYPE: uint8 {
	TOURNAMENTAWARD_NULL = 0 UMETA(DisplayName="TOURNAMENTAWARD_NULL"),
	TOURNAMENTAWARD_RANK_RANGE = 1 UMETA(DisplayName="TOURNAMENTAWARD_RANK_RANGE"),	//积分排行奖励
	TOURNAMENTAWARD_RANK_PROGRESS = 2 UMETA(DisplayName="TOURNAMENTAWARD_RANK_PROGRESS"),	//积分进度奖励
	TOURNAMENTAWARD_BATTLE_RANGE = 3 UMETA(DisplayName="TOURNAMENTAWARD_BATTLE_RANGE"),	//战斗排行奖励
	TOURNAMENTAWARD_JOIN = 4 UMETA(DisplayName="TOURNAMENTAWARD_JOIN"),	//参与奖励
	TOURNAMENTAWARD_RISE = 5 UMETA(DisplayName="TOURNAMENTAWARD_RISE"),	//晋级奖励
	TOURNAMENTAWARD_OUT = 6 UMETA(DisplayName="TOURNAMENTAWARD_OUT"),	//淘汰奖励
};

UENUM(BlueprintType)
enum class ETOURNAMENTLAYER: uint8 {
	LAYER_NULL = 0 UMETA(DisplayName="LAYER_NULL"),	//
	LAYER_TOURNAMENT = 1 UMETA(DisplayName="LAYER_TOURNAMENT"),	//赛事层
	LAYER_LEVEL = 2 UMETA(DisplayName="LAYER_LEVEL"),	//级别层
	LAYER_ROUND = 3 UMETA(DisplayName="LAYER_ROUND"),	//轮次层
	LAYER_BATTLE_GROUP = 4 UMETA(DisplayName="LAYER_BATTLE_GROUP"),	//战斗组
};

UENUM(BlueprintType)
enum class EFallAddType: uint8 {
	FALLADDNONE = 0 UMETA(DisplayName="FALLADDNONE"),
	PROBABILITY = 1 UMETA(DisplayName="PROBABILITY"),	// 概率
	TIME = 2 UMETA(DisplayName="TIME"),	// 时间
	LEVEL = 3 UMETA(DisplayName="LEVEL"),	// 等级
};

UENUM(BlueprintType)
enum class EFalledType: uint8 {
	FALLTYPENONE = 0 UMETA(DisplayName="FALLTYPENONE"),
	BOX = 1 UMETA(DisplayName="BOX"),	// 宝箱
	FIGHT = 2 UMETA(DisplayName="FIGHT"),	// 对局
};

UENUM(BlueprintType)
enum class EAddictionType: uint8 {
	ADDICTIONNULL = 0 UMETA(DisplayName="ADDICTIONNULL"),
	LOGINALLOWTIME = 1 UMETA(DisplayName="LOGINALLOWTIME"),	//沉迷允许登录时间段
	TIPTIMED = 2 UMETA(DisplayName="TIPTIMED"),	//沉迷定时提示
};

UENUM(BlueprintType)
enum class EPassportShareType: uint8 {
	Unknown = 0 UMETA(DisplayName="Unknown"),
	COMMONAWARD = 1 UMETA(DisplayName="COMMONAWARD"),	//分享通用奖励
	PSharTaskMoney = 2 UMETA(DisplayName="PSharTaskMoney"),	//通行证金币任务分享
	PSharTaskScatter = 3 UMETA(DisplayName="PSharTaskScatter"),	//通行证星罗棋布任务分享
	PSharTaskRecruitArmy = 4 UMETA(DisplayName="PSharTaskRecruitArmy"),	//通行证招兵买马任务分享
	PSharTaskArmyTeeth = 5 UMETA(DisplayName="PSharTaskArmyTeeth"),	//通行证全副武装任务分享
};

UENUM(BlueprintType)
enum class EDEDUCTIONTYPE: uint8 {
	DEDUCTIONTYPE_PASSPORT = 0 UMETA(DisplayName="DEDUCTIONTYPE_PASSPORT"),	//通行证折扣券
	DEDUCTIONTYPE_MALL = 1 UMETA(DisplayName="DEDUCTIONTYPE_MALL"),	//商城折扣券
};

UENUM(BlueprintType)
enum class ECHESSSTATUS: uint8 {
	CHESSSTATUS_NULL = 0 UMETA(DisplayName="CHESSSTATUS_NULL"),
	REFRESH = 1 UMETA(DisplayName="REFRESH"),	//1、可刷到的棋子
	SUMMON = 2 UMETA(DisplayName="SUMMON"),	//2、棋子的召唤物
	MONSTER = 3 UMETA(DisplayName="MONSTER"),	//3、野怪
	DISPLAY = 4 UMETA(DisplayName="DISPLAY"),	//4、不显示
	RETREAT_ENVIRONMENT = 5 UMETA(DisplayName="RETREAT_ENVIRONMENT"),	//5、退环境的棋子
	BEGIN_PUT = 6 UMETA(DisplayName="BEGIN_PUT"),	//6、预投放的棋子
};

UENUM(BlueprintType)
enum class EPSCHARGETYPE: uint8 {
	CHARGE_GENERAL = 0 UMETA(DisplayName="CHARGE_GENERAL"),	//通用
	CHARGE_PS4 = 1 UMETA(DisplayName="CHARGE_PS4"),	//ps4独有
	CHARGE_PS5 = 2 UMETA(DisplayName="CHARGE_PS5"),	//ps5独有
};

UENUM(BlueprintType)
enum class ERETURN_GUID_TAG: uint8 {
	TYPE_NORMAL = 0 UMETA(DisplayName="TYPE_NORMAL"),	//无 不展示
	TYPE_NEW_MODE = 1 UMETA(DisplayName="TYPE_NEW_MODE"),	//新模式
	TYPE_NEW_CHESS = 2 UMETA(DisplayName="TYPE_NEW_CHESS"),	//新棋子
	TYPE_NEW_FUNC = 3 UMETA(DisplayName="TYPE_NEW_FUNC"),	//新功能
	TYPE_NEW_FETTER = 4 UMETA(DisplayName="TYPE_NEW_FETTER"),	//新羁绊
};

UENUM(BlueprintType)
enum class ECHESOPENTYPE: uint8 {
	OPEN_NORMAL = 0 UMETA(DisplayName="OPEN_NORMAL"),
	OPEN_CHEST = 1 UMETA(DisplayName="OPEN_CHEST"),	//宝箱开宝箱
};

UENUM(BlueprintType)
enum class EPVPDROPTYPE: uint8 {
	PVPDROP_NILL = 0 UMETA(DisplayName="PVPDROP_NILL"),
	PVPDROP_BATTLE = 1 UMETA(DisplayName="PVPDROP_BATTLE"),	//普通参赛
	PVPDROP_OB = 2 UMETA(DisplayName="PVPDROP_OB"),	//普通观战
	PVPDROP_AUTHORITY = 3 UMETA(DisplayName="PVPDROP_AUTHORITY"),	//官方自定义
	PVPDROP_END = 4 UMETA(DisplayName="PVPDROP_END"),
};

UENUM(BlueprintType)
enum class ESETNAMETYPE: uint8 {
	SETNAMETYPE_NULL = 0 UMETA(DisplayName="SETNAMETYPE_NULL"),
	SETNAMETYPE_PLAYER_NAME = 1 UMETA(DisplayName="SETNAMETYPE_PLAYER_NAME"),	//玩家名字
	SETNAMETYPE_ACUTION_NAME = 2 UMETA(DisplayName="SETNAMETYPE_ACUTION_NAME"),	//拍卖行名字
	SETNAMETYPE_ACUTION_REMARK = 3 UMETA(DisplayName="SETNAMETYPE_ACUTION_REMARK"),	//拍卖行留言
};

UENUM(BlueprintType)
enum class EModeClassType1: uint8 {
	MODECLASSTYPE1_NULL = 0 UMETA(DisplayName="MODECLASSTYPE1_NULL"),
	MODECLASSTYPE1_CLASSIC = 1 UMETA(DisplayName="MODECLASSTYPE1_CLASSIC"),	// 经典模式
	MODECLASSTYPE1_FUN = 2 UMETA(DisplayName="MODECLASSTYPE1_FUN"),	// 娱乐模式
	MODECLASSTYPE1_TEACH = 3 UMETA(DisplayName="MODECLASSTYPE1_TEACH"),	// 教学模式
	MODECLASSTYPE1_CUSTOM = 4 UMETA(DisplayName="MODECLASSTYPE1_CUSTOM"),	// 自建房
};

UENUM(BlueprintType)
enum class EModeClassType2: uint8 {
	MODECLASSTYPE2_NULL = 0 UMETA(DisplayName="MODECLASSTYPE2_NULL"),
	MODECLASSTYPE2_RANK = 1 UMETA(DisplayName="MODECLASSTYPE2_RANK"),	// 排位
	MODECLASSTYPE2_RELAX = 2 UMETA(DisplayName="MODECLASSTYPE2_RELAX"),	// 休闲
};

UENUM(BlueprintType)
enum class EPackChannel: uint8 {
	ChannelTypeNull = 0 UMETA(DisplayName="ChannelTypeNull"),
	ChanGoogle = 1 UMETA(DisplayName="ChanGoogle"),
	ChanOverseaIOS = 2 UMETA(DisplayName="ChanOverseaIOS"),
	ChanTencent = 3 UMETA(DisplayName="ChanTencent"),
	ChanOverseaPC = 4 UMETA(DisplayName="ChanOverseaPC"),	// 海外pc
	ChanInlandPC = 5 UMETA(DisplayName="ChanInlandPC"),	// 国内pc
	PS = 6 UMETA(DisplayName="PS"),
	InlandPhone = 7 UMETA(DisplayName="InlandPhone"),	// 国内手游
	ChanVNG = 8 UMETA(DisplayName="ChanVNG"),	// vng
};

enum class EFUNCID: int32 {
	FUNCID_NULL = 0,
	FUNCID_WORKSHOP = 1000,
	FUNCID_WORKSHOP_CREATE_ROOM = 1001,
	FUNCID_WORKSHOP_JOIN_ROOM = 1002,
	FUNCID_TOURNAMENT = 1100,
	FUNCID_GUILD = 1200,
	FUNCID_GUILD_JOIN = 1201,
	FUNCID_GUILD_CREATE = 1202,
	FUNCID_POP_PICTURE = 1300,
	FUNCID_ACTIVITY = 1400,
	FUNCID_ACTIVITY_NEW_PLAYER = 1401,
	FUNCID_ACTIVITY_RETURN = 1402,
	FUNCID_MALL = 1500,
	FUNCID_PASSPORT = 1600,
	FUNCID_PVPMODE = 1700,
	FUNCID_PVPMODE_AUTO_CHESS = 1701,
	FUNCID_PVPMODE_AUTO_CHESS_RANK = 1702,
	FUNCID_PVPMODE_CUSTOM = 1703,
	FUNCID_PVPMODE_NEW_PLAYER = 1704,
	FUNCID_PVPMODE_MELEE = 1705,
	FUNCID_PVPMODE_TEAM_BATTLE = 1706,
	FUNCID_PVPMODE_TEAM_BATTLE_RANK = 1707,
	FUNCID_PVPMODE_COMBAT_TRAINING = 1708,
	FUNCID_PVPMODE_NEW_PLAYER_GUIDE = 1709,
	FUNCID_PVPMODE_TEACH_BATTLE = 1711,	// 关卡教学
	FUNCID_PVPMODE_AI_TRAIN = 1712,	// 实战训练
	FUNCID_PVPMODE_BIGWINNER = 1713,	// 大赢家
	FUNCID_PVPMODE_FOURVSFOUR = 1715,	// 团队休闲
	FUNCID_PVPMODE_FOURVSFOUR_RANK = 1716,	// 团队排位
	FUNCID_VIDEO = 1800,
	FUNCID_VIDEO_POP_UP = 1801,	// 拍脸视频
	FUNCID_CARD_GROUP = 1900,	// 棋组
};

UENUM(BlueprintType)
enum class EFUNCUNLOCKTYPE: uint8 {
	FUNCUNLOCKTYPE_NULL = 0 UMETA(DisplayName="FUNCUNLOCKTYPE_NULL"),
	FUNCUNLOCKTYPE_LEVEL = 1 UMETA(DisplayName="FUNCUNLOCKTYPE_LEVEL"),
	FUNCUNLOCKTYPE_CUP = 2 UMETA(DisplayName="FUNCUNLOCKTYPE_CUP"),
};

UENUM(BlueprintType)
enum class EGUILDRIGHTTYPE: uint8 {
	GUILDRIGHTTYPE_NULL = 0 UMETA(DisplayName="GUILDRIGHTTYPE_NULL"),
	APPROVE = 1 UMETA(DisplayName="APPROVE"),	// 审批
	RECRUIT = 2 UMETA(DisplayName="RECRUIT"),	// 招募
	INVITE = 3 UMETA(DisplayName="INVITE"),	// 邀请
	MODIFY_NAME = 4 UMETA(DisplayName="MODIFY_NAME"),
	MODIFY_SIGN = 5 UMETA(DisplayName="MODIFY_SIGN"),
	MODIFY_TAGS = 6 UMETA(DisplayName="MODIFY_TAGS"),
	MODIFY_NOTICE = 7 UMETA(DisplayName="MODIFY_NOTICE"),
	MODIFY_PERMIT = 8 UMETA(DisplayName="MODIFY_PERMIT"),
	KICKOFF = 9 UMETA(DisplayName="KICKOFF"),
	APPOINT_VICE = 10 UMETA(DisplayName="APPOINT_VICE"),	// 任命副社长
	APPOINT_OFFICER = 11 UMETA(DisplayName="APPOINT_OFFICER"),	// 任命主将
	MAX = 100 UMETA(DisplayName="MAX"),
};

UENUM(BlueprintType)
enum class EMedalType: uint8 {
	MedalTypeCommon = 0 UMETA(DisplayName="MedalTypeCommon"),	// 通用
	MedalTypeCareer = 1 UMETA(DisplayName="MedalTypeCareer"),	// 生涯
	MedalTypeMATCH = 2 UMETA(DisplayName="MedalTypeMATCH"),	// 赛事
	MedalTypeActivity = 3 UMETA(DisplayName="MedalTypeActivity"),	// 活动
	MedalTypeSet = 4 UMETA(DisplayName="MedalTypeSet"),	// 套组
};

UENUM(BlueprintType)
enum class EMedalSubType: uint8 {
	MEDAL_NORMAL = 0 UMETA(DisplayName="MEDAL_NORMAL"),	//通用
	MEDAL_ACHIEVEMENT = 1 UMETA(DisplayName="MEDAL_ACHIEVEMENT"),	//成就
	MEDAL_COLLECT = 2 UMETA(DisplayName="MEDAL_COLLECT"),	//收集
	MEDAL_CUMULATE = 3 UMETA(DisplayName="MEDAL_CUMULATE"),	//累计
};

UENUM(BlueprintType)
enum class EPVE_RANK_SCORE_TYPE: uint8 {
	PVE_RANK_INIT = 0 UMETA(DisplayName="PVE_RANK_INIT"),
	PVE_RANK_HP_TIME = 1 UMETA(DisplayName="PVE_RANK_HP_TIME"),	// 血量-时间
	PVE_RANK_KERNEL_SCORE = 2 UMETA(DisplayName="PVE_RANK_KERNEL_SCORE"),	// 内核积分
};

UENUM(BlueprintType)
enum class ERANDPICKUPPOOLTYPE: uint8 {
	RANDPICKUPPOOLTYPE_NULL = 0 UMETA(DisplayName="RANDPICKUPPOOLTYPE_NULL"),
	RANDPICKUPPOOLTYPE_NORMAL = 1 UMETA(DisplayName="RANDPICKUPPOOLTYPE_NORMAL"),
	RANDPICKUPPOOLTYPE_RANGE = 2 UMETA(DisplayName="RANDPICKUPPOOLTYPE_RANGE"),
	RANDPICKUPPOOLTYPE_RANGE_DECIMAL = 3 UMETA(DisplayName="RANDPICKUPPOOLTYPE_RANGE_DECIMAL"),
};

UENUM(BlueprintType)
enum class EITEMAFFIXTYPE: uint8 {
	ITEMAFFIXTYPE_NULL = 0 UMETA(DisplayName="ITEMAFFIXTYPE_NULL"),
	ITEMAFFIXTYPE_CHESSPLAYER = 1 UMETA(DisplayName="ITEMAFFIXTYPE_CHESSPLAYER"),
	ITEMAFFIXTYPE_SCENE = 2 UMETA(DisplayName="ITEMAFFIXTYPE_SCENE"),
	ITEMAFFIXTYPE_CHESSSKIN_COMMON = 3 UMETA(DisplayName="ITEMAFFIXTYPE_CHESSSKIN_COMMON"),
	ITEMAFFIXTYPE_CHESSSKIN_EXCLUSIVE = 4 UMETA(DisplayName="ITEMAFFIXTYPE_CHESSSKIN_EXCLUSIVE"),
};

UENUM(BlueprintType)
enum class EITEMAFFIXCONDTYPE: uint8 {
	ITEMAFFIXCONDTYPE_ = 0 UMETA(DisplayName="ITEMAFFIXCONDTYPE_"),
};

UENUM(BlueprintType)
enum class EITEMAFFIXTRIGGERTYPE: uint8 {
	ITEMAFFIXTriggerType_ = 0 UMETA(DisplayName="ITEMAFFIXTriggerType_"),
	ITEMAFFIXTriggerType_ROUND = 1 UMETA(DisplayName="ITEMAFFIXTriggerType_ROUND"),	// 回合出发
	ITEMAFFIXTRIGGERTYPE_IMMEDIATE = 2 UMETA(DisplayName="ITEMAFFIXTRIGGERTYPE_IMMEDIATE"),	//即时触发
};

UENUM(BlueprintType)
enum class EITEMIDENTIFYATTR: uint8 {
	ITEMIDENTIFYATTR_AFFIXCNT = 0 UMETA(DisplayName="ITEMIDENTIFYATTR_AFFIXCNT"),	// 词缀数量
	ITEMIDENTIFYATTR_AFFIX = 1 UMETA(DisplayName="ITEMIDENTIFYATTR_AFFIX"),	// 词缀
	ITEMIDENTIFYATTR_ABRASION = 2 UMETA(DisplayName="ITEMIDENTIFYATTR_ABRASION"),	// 磨损度
	ITEMIDENTIFYATTR_NUMBER = 3 UMETA(DisplayName="ITEMIDENTIFYATTR_NUMBER"),	// 发行编号
	ITEMIDENTIFYATTR_TEXTURE = 4 UMETA(DisplayName="ITEMIDENTIFYATTR_TEXTURE"),	// 磨损贴图
};

UENUM(BlueprintType)
enum class EDestinyActionTrigger: uint8 {
	Trigger_NULL = 0 UMETA(DisplayName="Trigger_NULL"),
	Trigger_Buy = 1 UMETA(DisplayName="Trigger_Buy"),	// 购买
	Trigger_Victory = 2 UMETA(DisplayName="Trigger_Victory"),	// 胜利
};

USTRUCT(BlueprintType)
struct  FPvpBox {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//宝箱ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FallMax;	//最大掉落

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	//掉落权重

};
static void _ConvertPbToFPvpBox(FPvpBox &msg, const msg::PvpBox *pb) {
	msg.Id=pb->id();
	msg.FallMax=pb->fallmax();
	msg.Weight=pb->weight();
}


USTRUCT(BlueprintType)
struct  FRankLimit {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EPVPMODE> Modes;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rank;	//排名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IncludeAI;	//是否包含AI局

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//第几局

};
static void _ConvertPbToFRankLimit(FRankLimit &msg, const msg::RankLimit *pb) {
	for (int i = 0; i < pb->modes().size(); i++) {
		auto &a = pb->modes().Get(i);
		EPVPMODE tmp;
		tmp=(EPVPMODE)a;
		msg.Modes.Add(tmp);
	}
	msg.Rank=pb->rank();
	msg.IncludeAI=pb->includeai();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FTrophyTask {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//奖杯id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//奖杯级别

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DLC;	//是否正片

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Logo;	//是否正片

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Hide;	//是否隐藏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Link;	//图标链接

};
static void _ConvertPbToFTrophyTask(FTrophyTask &msg, const msg::TrophyTask *pb) {
	msg.ID=pb->id();
	msg.Level=pb->level();
	msg.DLC=pb->dlc();
	msg.Logo=UTF8_TO_TCHAR(pb->logo().c_str());
	msg.Hide=pb->hide();
	msg.Link=UTF8_TO_TCHAR(pb->link().c_str());
}


USTRUCT(BlueprintType)
struct  FAlphaAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFAlphaAward(FAlphaAward &msg, const msg::AlphaAward *pb) {
	msg.Count=pb->count();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChannelInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

};
static void _ConvertPbToFChannelInfo(FChannelInfo &msg, const msg::ChannelInfo *pb) {
	msg.Type=(ECHANELTYPE)pb->type();
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FGoodsName {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelName;	//渠道名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//商品名

};
static void _ConvertPbToFGoodsName(FGoodsName &msg, const msg::GoodsName *pb) {
	msg.ChannelName=UTF8_TO_TCHAR(pb->channelname().c_str());
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
}


USTRUCT(BlueprintType)
struct  FOpenData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHEST_OPEN_TYPE Type;	//开启类型(高阶密藏、普通密藏)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;	//掉落池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KeyId;	//钥匙id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KeyNum;	//钥匙

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowRate;	//展示概率

};
static void _ConvertPbToFOpenData(FOpenData &msg, const msg::OpenData *pb) {
	msg.Type=(ECHEST_OPEN_TYPE)pb->type();
	msg.PoolId=pb->poolid();
	msg.KeyId=pb->keyid();
	msg.KeyNum=pb->keynum();
	msg.ShowRate=UTF8_TO_TCHAR(pb->showrate().c_str());
}


USTRUCT(BlueprintType)
struct  FCumulativeAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Reward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Num;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cond;

};
static void _ConvertPbToFCumulativeAward(FCumulativeAward &msg, const msg::CumulativeAward *pb) {
	msg.Reward=pb->reward();
	msg.Num=pb->num();
	msg.Cond=pb->cond();
}


USTRUCT(BlueprintType)
struct  FStandbyChess {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Left;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Right;

};
static void _ConvertPbToFStandbyChess(FStandbyChess &msg, const msg::StandbyChess *pb) {
	msg.Left=UTF8_TO_TCHAR(pb->left().c_str());
	msg.Right=UTF8_TO_TCHAR(pb->right().c_str());
}


USTRUCT(BlueprintType)
struct  FEggConsume {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//连抽次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//连抽消耗

};
static void _ConvertPbToFEggConsume(FEggConsume &msg, const msg::EggConsume *pb) {
	msg.Count=pb->count();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRandLib {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//商品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//商品数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	//商品权重

};
static void _ConvertPbToFRandLib(FRandLib &msg, const msg::RandLib *pb) {
	msg.Id=pb->id();
	msg.Count=pb->count();
	msg.Weight=pb->weight();
}


USTRUCT(BlueprintType)
struct  FReduction {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//减免货币id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//减免货币数量

};
static void _ConvertPbToFReduction(FReduction &msg, const msg::Reduction *pb) {
	msg.Id=pb->id();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FGameLimit {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//游戏局数

};
static void _ConvertPbToFGameLimit(FGameLimit &msg, const msg::GameLimit *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FPunishmentTrigger {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPUNISHMENTBEHAVIOR Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OverlayCount;	//叠加次数

};
static void _ConvertPbToFPunishmentTrigger(FPunishmentTrigger &msg, const msg::PunishmentTrigger *pb) {
	msg.Type=(EPUNISHMENTBEHAVIOR)pb->type();
	msg.OverlayCount=pb->overlaycount();
}


USTRUCT(BlueprintType)
struct  FSkinInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SkinModel;	//棋子模型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Skinicon;	//皮肤icon

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SkinPic;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BookPic;

};
static void _ConvertPbToFSkinInfo(FSkinInfo &msg, const msg::SkinInfo *pb) {
	msg.SkinModel=UTF8_TO_TCHAR(pb->skinmodel().c_str());
	msg.Skinicon=UTF8_TO_TCHAR(pb->skinicon().c_str());
	msg.SkinPic=UTF8_TO_TCHAR(pb->skinpic().c_str());
	msg.BookPic=UTF8_TO_TCHAR(pb->bookpic().c_str());
}


USTRUCT(BlueprintType)
struct  FComposeMaterial {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//材料物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxUseCount;	//每次合成最大使用数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Essential;	//是否是合成必不可少的材料

};
static void _ConvertPbToFComposeMaterial(FComposeMaterial &msg, const msg::ComposeMaterial *pb) {
	msg.Id=pb->id();
	msg.MaxUseCount=pb->maxusecount();
	msg.Essential=pb->essential();
}


USTRUCT(BlueprintType)
struct  FEnrollTicket {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NeedNum;	//需求数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConsumeNum;	//消耗数量

};
static void _ConvertPbToFEnrollTicket(FEnrollTicket &msg, const msg::EnrollTicket *pb) {
	msg.Id=pb->id();
	msg.NeedNum=pb->neednum();
	msg.ConsumeNum=pb->consumenum();
}


USTRUCT(BlueprintType)
struct  FActivationTimeRange {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StartTime;	//赛事轮次开始激活时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EndTime;	//赛事轮次开始暂停时间

};
static void _ConvertPbToFActivationTimeRange(FActivationTimeRange &msg, const msg::ActivationTimeRange *pb) {
	msg.StartTime=UTF8_TO_TCHAR(pb->starttime().c_str());
	msg.EndTime=UTF8_TO_TCHAR(pb->endtime().c_str());
}


USTRUCT(BlueprintType)
struct  FRangeAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFRangeAward(FRangeAward &msg, const msg::RangeAward *pb) {
	msg.Min=pb->min();
	msg.Max=pb->max();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FABTestWeight {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Value;

};
static void _ConvertPbToFABTestWeight(FABTestWeight &msg, const msg::ABTestWeight *pb) {
	msg.Rate=pb->rate();
	msg.Value=pb->value();
}


USTRUCT(BlueprintType)
struct  FTeachInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Text;	//文本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Pic;	//图片

};
static void _ConvertPbToFTeachInfo(FTeachInfo &msg, const msg::TeachInfo *pb) {
	msg.Text=UTF8_TO_TCHAR(pb->text().c_str());
	msg.Pic=UTF8_TO_TCHAR(pb->pic().c_str());
}


USTRUCT(BlueprintType)
struct  FTeachTask {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCond Cond;	//任务条件释义类型

};
static void _ConvertPbToFTeachTask(FTeachTask &msg, const msg::TeachTask *pb) {
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	_ConvertPbToFCond(msg.Cond, &pb->cond());
}


USTRUCT(BlueprintType)
struct  FTextPool {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultText;	//默认台词池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NormalText;	//普通台词池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeniorText;	//高级台词池

};
static void _ConvertPbToFTextPool(FTextPool &msg, const msg::TextPool *pb) {
	msg.DefaultText=pb->defaulttext();
	msg.NormalText=pb->normaltext();
	msg.SeniorText=pb->seniortext();
}


USTRUCT(BlueprintType)
struct  FAwardGroup {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//奖励组id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardId;	//奖励组奖品id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Rule;	//奖励组规则

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//奖励组奖品数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLoc Loc;	//奖励组位置

};
static void _ConvertPbToFAwardGroup(FAwardGroup &msg, const msg::AwardGroup *pb) {
	msg.Id=pb->id();
	msg.AwardId=pb->awardid();
	msg.Rule=UTF8_TO_TCHAR(pb->rule().c_str());
	msg.Count=pb->count();
	_ConvertPbToFLoc(msg.Loc, &pb->loc());
}


USTRUCT(BlueprintType)
struct  FPoolItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOUTPUT_ITEM_TYPE Type;	//物品类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Limit;	//物品限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	//物品权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//物品数量

};
static void _ConvertPbToFPoolItem(FPoolItem &msg, const msg::PoolItem *pb) {
	msg.Id=pb->id();
	msg.Type=(EOUTPUT_ITEM_TYPE)pb->type();
	msg.Limit=pb->limit();
	msg.Weight=pb->weight();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FAwardToken {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

};
static void _ConvertPbToFAwardToken(FAwardToken &msg, const msg::AwardToken *pb) {
	msg.ID=pb->id();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FRankAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Level;	//排名档位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Reward;	//排名奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Num;	//奖励数量

};
static void _ConvertPbToFRankAward(FRankAward &msg, const msg::RankAward *pb) {
	msg.Level=UTF8_TO_TCHAR(pb->level().c_str());
	msg.Reward=UTF8_TO_TCHAR(pb->reward().c_str());
	msg.Num=UTF8_TO_TCHAR(pb->num().c_str());
}


USTRUCT(BlueprintType)
struct  FSmeltExcludeItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE ItemType;	//类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Quality;	//质量(>=)

};
static void _ConvertPbToFSmeltExcludeItem(FSmeltExcludeItem &msg, const msg::SmeltExcludeItem *pb) {
	msg.ItemType=(EITEMTYPE)pb->itemtype();
	msg.Quality=pb->quality();
}


USTRUCT(BlueprintType)
struct  FDestinyAction {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDestinyActionTrigger Trigger;	//触发条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Priority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Voice;

};
static void _ConvertPbToFDestinyAction(FDestinyAction &msg, const msg::DestinyAction *pb) {
	msg.Trigger=(EDestinyActionTrigger)pb->trigger();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Priority=pb->priority();
	msg.Voice=UTF8_TO_TCHAR(pb->voice().c_str());
}


USTRUCT(BlueprintType)
struct  FChessQuality {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHESS_QUALITY Id;	//棋子质量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//数量

};
static void _ConvertPbToFChessQuality(FChessQuality &msg, const msg::ChessQuality *pb) {
	msg.Id=(ECHESS_QUALITY)pb->id();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FLyAwardPool {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE Type;	//物品类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LimitPlayer;	//个人掉落物品上限

	int64 LimitTotal;	//全服掉落物品上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	//物品权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//物品掉落数量

};
static void _ConvertPbToFLyAwardPool(FLyAwardPool &msg, const msg::LyAwardPool *pb) {
	msg.Id=pb->id();
	msg.Type=(EITEMTYPE)pb->type();
	msg.LimitPlayer=pb->limitplayer();
	msg.LimitTotal=pb->limittotal();
	msg.Weight=pb->weight();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FTaskInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//任务ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETASKTYPE Type;	//任务类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;	//任务标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//任务描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Unit;	//任务条件单位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCond Cond;	//任务完成条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//任务完成奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankLimit;	//完成回合要求

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CondGroup;	//任务组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PreCondGroup;	//前置任务组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ProgressInherit;	//进度是否继承前置任务进度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> TaskCardConsumes;	//任务卡消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCharge;	//是否是付费任务  0-免费  1-付费

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDifficult;	//是否是困难任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeriesID;	//序列ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTrophyTask Trophy;	// @update ps4 成就奖杯

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Week;	//周

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Season;	//赛季+

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPassportShareType QuestShareType;	//通行证任务分享奖励类型:1,通用;2 特殊 此处未使用，仅作表格解析兼容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionStartTime;	// 任务开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionEndTime;	// 任务开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QuestLevel;	//通行证等级分享类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsActive;	//是否是主动领取奖励任务

};
static void _ConvertPbToFTaskInfo(FTaskInfo &msg, const msg::TaskInfo *pb) {
	msg.Id=pb->id();
	msg.Type=(ETASKTYPE)pb->type();
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.Unit=pb->unit();
	_ConvertPbToFCond(msg.Cond, &pb->cond());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.RankLimit=pb->ranklimit();
	msg.CondGroup=pb->condgroup();
	msg.PreCondGroup=pb->precondgroup();
	msg.ProgressInherit=pb->progressinherit();
	for (int i = 0; i < pb->taskcardconsumes().size(); i++) {
		auto &a = pb->taskcardconsumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.TaskCardConsumes.Add(tmp);
	}
	msg.IsCharge=pb->ischarge();
	msg.IsDifficult=pb->isdifficult();
	msg.SeriesID=pb->seriesid();
	_ConvertPbToFTrophyTask(msg.Trophy, &pb->trophy());
	msg.Week=pb->week();
	msg.Season=pb->season();
	msg.QuestShareType=(EPassportShareType)pb->questsharetype();
	msg.MissionStartTime=UTF8_TO_TCHAR(pb->missionstarttime().c_str());
	msg.MissionEndTime=UTF8_TO_TCHAR(pb->missionendtime().c_str());
	msg.QuestLevel=pb->questlevel();
	msg.IsActive=pb->isactive();
}


USTRUCT(BlueprintType)
struct  FMentorShipReach {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Para;	//条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORREACH Type;	//类型

};
static void _ConvertPbToFMentorShipReach(FMentorShipReach &msg, const msg::MentorShipReach *pb) {
	for (int i = 0; i < pb->para().size(); i++) {
		auto &a = pb->para().Get(i);
		int tmp;
		tmp=a;
		msg.Para.Add(tmp);
	}
	msg.Type=(EMENTORREACH)pb->type();
}


USTRUCT(BlueprintType)
struct  FExceptProData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExceptionPr;	//期望概率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddCrit;	//期望增量(真实的概率)

};
static void _ConvertPbToFExceptProData(FExceptProData &msg, const msg::ExceptProData *pb) {
	msg.ExceptionPr=pb->exceptionpr();
	msg.AddCrit=pb->addcrit();
}


USTRUCT(BlueprintType)
struct  FModeProData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Mode;	//模式ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PrMode;	//模式概率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Pr;	//排位概率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ObPro;	//观战概率

};
static void _ConvertPbToFModeProData(FModeProData &msg, const msg::ModeProData *pb) {
	msg.Mode=pb->mode();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.PrMode=pb->prmode();
	for (int i = 0; i < pb->pr().size(); i++) {
		auto &a = pb->pr().Get(i);
		int tmp;
		tmp=a;
		msg.Pr.Add(tmp);
	}
	msg.ObPro=pb->obpro();
}


USTRUCT(BlueprintType)
struct  FPvpChestData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TimeId;	//时间ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExceptionNum;	//周期期望个数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BeginTime;	//开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EndTime;	//结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPvpBox> Boxs;	//对局宝箱数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PramA;	//宝箱参数a

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PramB;	//宝箱参数b

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PramC;	//上限后宝箱参数c

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PramD;	//调控参数D

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPDROPTYPE DropType;	//0:参赛 1:观战 2:官方自定义

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//唯一Key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpMode;

};
static void _ConvertPbToFPvpChestData(FPvpChestData &msg, const msg::PvpChestData *pb) {
	msg.TimeId=UTF8_TO_TCHAR(pb->timeid().c_str());
	msg.ExceptionNum=pb->exceptionnum();
	msg.BeginTime=UTF8_TO_TCHAR(pb->begintime().c_str());
	msg.EndTime=UTF8_TO_TCHAR(pb->endtime().c_str());
	for (int i = 0; i < pb->boxs().size(); i++) {
		auto &a = pb->boxs().Get(i);
		FPvpBox tmp;
		_ConvertPbToFPvpBox(tmp, &a);
		msg.Boxs.Add(tmp);
	}
	msg.PramA=pb->prama();
	msg.PramB=pb->pramb();
	msg.PramC=pb->pramc();
	msg.PramD=pb->pramd();
	msg.DropType=(EPVPDROPTYPE)pb->droptype();
	msg.ID=pb->id();
	msg.PvpMode=UTF8_TO_TCHAR(pb->pvpmode().c_str());
}


USTRUCT(BlueprintType)
struct  FObserverChestData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;	//时间ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BeginTime;	//开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EndTime;	//结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPvpBox> Boxs;	//对局宝箱数据

};
static void _ConvertPbToFObserverChestData(FObserverChestData &msg, const msg::ObserverChestData *pb) {
	msg.ID=UTF8_TO_TCHAR(pb->id().c_str());
	msg.BeginTime=UTF8_TO_TCHAR(pb->begintime().c_str());
	msg.EndTime=UTF8_TO_TCHAR(pb->endtime().c_str());
	for (int i = 0; i < pb->boxs().size(); i++) {
		auto &a = pb->boxs().Get(i);
		FPvpBox tmp;
		_ConvertPbToFPvpBox(tmp, &a);
		msg.Boxs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCupData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;	//杯段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//杯段名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score;	//所需分数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BufferScore;	//缓冲分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeasonResetScore;	//赛季重置分数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//该字段客户端使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRBasicFailK;	//MMR失败基本分调整系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECUPTYPE Class;	//杯段分类

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CupUrl;	//杯段头像

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon3;

};
static void _ConvertPbToFCupData(FCupData &msg, const msg::CupData *pb) {
	msg.Cup=pb->cup();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Score=pb->score();
	msg.BufferScore=pb->bufferscore();
	msg.SeasonResetScore=pb->seasonresetscore();
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
	msg.MMRBasicFailK=pb->mmrbasicfailk();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.Icon2=UTF8_TO_TCHAR(pb->icon2().c_str());
	msg.Class=(ECUPTYPE)pb->class_();
	msg.CupUrl=UTF8_TO_TCHAR(pb->cupurl().c_str());
	msg.Icon3=UTF8_TO_TCHAR(pb->icon3().c_str());
}


USTRUCT(BlueprintType)
struct  FCupMatchPerfectData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;	//杯段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MmrGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TiredTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AiStreakFailCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FailRank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamMatchTime;	//队伍匹配时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LanguageMatchTime;	//语言匹配时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerCountUpper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RegionMatchTime;	//区域匹配时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Region;	//匹配区域

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WinningStreak;	//连胜最低要求名次

};
static void _ConvertPbToFCupMatchPerfectData(FCupMatchPerfectData &msg, const msg::CupMatchPerfectData *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.Cup=pb->cup();
	msg.WaitTime=pb->waittime();
	msg.PlayerCount=pb->playercount();
	msg.MmrGap=pb->mmrgap();
	msg.TiredTime=pb->tiredtime();
	msg.AiStreakFailCount=pb->aistreakfailcount();
	msg.FailRank=pb->failrank();
	msg.TeamMatchTime=pb->teammatchtime();
	msg.LanguageMatchTime=pb->languagematchtime();
	msg.PlayerCountUpper=pb->playercountupper();
	msg.RegionMatchTime=pb->regionmatchtime();
	msg.Region=UTF8_TO_TCHAR(pb->region().c_str());
	msg.WinningStreak=pb->winningstreak();
}


USTRUCT(BlueprintType)
struct  FCupMatchExtendData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;	//杯段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerCountCycleTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerCountEnlargeValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinPlayerCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRGapCycleTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRGapEnlargeValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMMRGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Region;

};
static void _ConvertPbToFCupMatchExtendData(FCupMatchExtendData &msg, const msg::CupMatchExtendData *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.Cup=pb->cup();
	msg.PlayerCountCycleTime=pb->playercountcycletime();
	msg.PlayerCountEnlargeValue=pb->playercountenlargevalue();
	msg.MinPlayerCount=pb->minplayercount();
	msg.MMRGapCycleTime=pb->mmrgapcycletime();
	msg.MMRGapEnlargeValue=pb->mmrgapenlargevalue();
	msg.MaxMMRGap=pb->maxmmrgap();
	msg.Region=UTF8_TO_TCHAR(pb->region().c_str());
}


USTRUCT(BlueprintType)
struct  FRankSeasonEvalData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Season;	//赛季

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;	//杯段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> EvalAwards;	//结算奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Desc;	//描述

};
static void _ConvertPbToFRankSeasonEvalData(FRankSeasonEvalData &msg, const msg::RankSeasonEvalData *pb) {
	msg.Season=pb->season();
	msg.Cup=pb->cup();
	for (int i = 0; i < pb->evalawards().size(); i++) {
		auto &a = pb->evalawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.EvalAwards.Add(tmp);
	}
	for (int i = 0; i < pb->desc().size(); i++) {
		auto &a = pb->desc().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Desc.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNickName {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NickName;	//昵称

};
static void _ConvertPbToFNickName(FNickName &msg, const msg::NickName *pb) {
	msg.NickName=UTF8_TO_TCHAR(pb->nickname().c_str());
}


USTRUCT(BlueprintType)
struct  FDirtyWord {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DirtyWord;	//脏字

};
static void _ConvertPbToFDirtyWord(FDirtyWord &msg, const msg::DirtyWord *pb) {
	msg.DirtyWord=UTF8_TO_TCHAR(pb->dirtyword().c_str());
}


USTRUCT(BlueprintType)
struct  FActiveCode {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Code;

};
static void _ConvertPbToFActiveCode(FActiveCode &msg, const msg::ActiveCode *pb) {
	msg.Code=UTF8_TO_TCHAR(pb->code().c_str());
}


USTRUCT(BlueprintType)
struct  FItemData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//物品Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE Type;	//物品类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//物品名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMQUALITY Quality;	//物品品质

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//物品ICON

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> ConvertAwards;	//物品折算价格

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//物品描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Model;	//物品模型标识

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanMultiply;	//是否可叠加

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanSell;	//是否可出售

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMCLASS1 Class1;	//一级分类

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMCLASS2 Class2;	//二级分类

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SellLimit;	//售卖保留数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMSHAREBG ShareBg;	//分享背景

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShareCheckerboard;	//棋手分享对应文本字段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChannelInfo> Channels;	//客户端展示用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ComposeValue;	//合成值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Visible;	//仓库内是否可见

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Belong;	//道具的归属棋手

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BackpackDisplay;	//未拥有是否展示  1-展示  0-不展示

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SaleConfirm;	//物品出售是否二次确认,1-确认，0-不确认

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VideoResources;	//展示视频资源

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChestBlong;	//所属宝箱id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EffectBeginTime;	//物品生效时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EffectEndTime;	//物品失效时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool JumpSwitch;	//获取途径引导开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AchieveExplain;	//获取途径说明

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Indate;	//物品有效期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ExpireAutoRemove;	//物品失效自动删除

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VideoResourcesPC;	//展示视频资源(pc用)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanExchange;	//是否能交易

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SmeltValue;	//熔炼值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlatformLimitType;	//物品独占平台

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlatformLimitOnlyID;	//独占资源显示

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Serial;	//编号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Order;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanIdentify;	// 能否鉴定

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OriginId;	// 来源Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SmeltLevel;	// 汰换等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IdentifiedID;	// 鉴定后id, 用于可叠加物品鉴定后变为不可叠加物品，不可交易物品鉴定后转为可交易物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayBeginTime;	//展示开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayEndTime;	//展示结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OriginText;	//来源多语言

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TradeBoxShow;	//控制宝箱道具是否在列表中展示

};
static void _ConvertPbToFItemData(FItemData &msg, const msg::ItemData *pb) {
	msg.Id=pb->id();
	msg.Type=(EITEMTYPE)pb->type();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Quality=(EITEMQUALITY)pb->quality();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	for (int i = 0; i < pb->convertawards().size(); i++) {
		auto &a = pb->convertawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.ConvertAwards.Add(tmp);
	}
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.Model=UTF8_TO_TCHAR(pb->model().c_str());
	msg.CanMultiply=pb->canmultiply();
	msg.CanSell=pb->cansell();
	msg.Class1=(EITEMCLASS1)pb->class1();
	msg.Class2=(EITEMCLASS2)pb->class2();
	msg.SellLimit=pb->selllimit();
	msg.ShareBg=(EITEMSHAREBG)pb->sharebg();
	msg.ShareCheckerboard=UTF8_TO_TCHAR(pb->sharecheckerboard().c_str());
	for (int i = 0; i < pb->channels().size(); i++) {
		auto &a = pb->channels().Get(i);
		FChannelInfo tmp;
		_ConvertPbToFChannelInfo(tmp, &a);
		msg.Channels.Add(tmp);
	}
	msg.ComposeValue=pb->composevalue();
	msg.Visible=pb->visible();
	msg.Belong=UTF8_TO_TCHAR(pb->belong().c_str());
	msg.BackpackDisplay=pb->backpackdisplay();
	msg.SaleConfirm=pb->saleconfirm();
	msg.VideoResources=UTF8_TO_TCHAR(pb->videoresources().c_str());
	msg.ChestBlong=UTF8_TO_TCHAR(pb->chestblong().c_str());
	msg.EffectBeginTime=UTF8_TO_TCHAR(pb->effectbegintime().c_str());
	msg.EffectEndTime=UTF8_TO_TCHAR(pb->effectendtime().c_str());
	msg.JumpSwitch=pb->jumpswitch();
	msg.AchieveExplain=UTF8_TO_TCHAR(pb->achieveexplain().c_str());
	msg.Indate=pb->indate();
	msg.ExpireAutoRemove=pb->expireautoremove();
	msg.VideoResourcesPC=UTF8_TO_TCHAR(pb->videoresourcespc().c_str());
	msg.CanExchange=pb->canexchange();
	msg.SmeltValue=pb->smeltvalue();
	msg.PlatformLimitType=UTF8_TO_TCHAR(pb->platformlimittype().c_str());
	msg.PlatformLimitOnlyID=pb->platformlimitonlyid();
	msg.Serial=UTF8_TO_TCHAR(pb->serial().c_str());
	msg.Order=pb->order();
	msg.CanIdentify=pb->canidentify();
	msg.OriginId=pb->originid();
	msg.SmeltLevel=pb->smeltlevel();
	msg.IdentifiedID=pb->identifiedid();
	msg.DisplayBeginTime=UTF8_TO_TCHAR(pb->displaybegintime().c_str());
	msg.DisplayEndTime=UTF8_TO_TCHAR(pb->displayendtime().c_str());
	msg.OriginText=UTF8_TO_TCHAR(pb->origintext().c_str());
	msg.TradeBoxShow=UTF8_TO_TCHAR(pb->tradeboxshow().c_str());
}


USTRUCT(BlueprintType)
struct  FEggAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//奖励序列号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAward AwardItem;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	//权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EggId;	//所属扭蛋ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEGGPOOLTYPE PoolType;	//随机池类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDisplay;	//是否展示

};
static void _ConvertPbToFEggAward(FEggAward &msg, const msg::EggAward *pb) {
	msg.Id=pb->id();
	_ConvertPbToFAward(msg.AwardItem, &pb->awarditem());
	msg.Weight=pb->weight();
	msg.EggId=pb->eggid();
	msg.PoolType=(EEGGPOOLTYPE)pb->pooltype();
	msg.IsDisplay=pb->isdisplay();
}


USTRUCT(BlueprintType)
struct  FSetNameData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESETNAMETYPE Type;	//类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//消耗列表

};
static void _ConvertPbToFSetNameData(FSetNameData &msg, const msg::SetNameData *pb) {
	msg.Count=pb->count();
	msg.Type=(ESETNAMETYPE)pb->type();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRandomNameData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SingleName;	//单名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CombinedName1;	//组合名1

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CombinedName2;	//组合名2

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CombinedName3;	//组合名3

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CombinedName4;	//组合名4

};
static void _ConvertPbToFRandomNameData(FRandomNameData &msg, const msg::RandomNameData *pb) {
	msg.SingleName=UTF8_TO_TCHAR(pb->singlename().c_str());
	msg.CombinedName1=UTF8_TO_TCHAR(pb->combinedname1().c_str());
	msg.CombinedName2=UTF8_TO_TCHAR(pb->combinedname2().c_str());
	msg.CombinedName3=UTF8_TO_TCHAR(pb->combinedname3().c_str());
	msg.CombinedName4=UTF8_TO_TCHAR(pb->combinedname4().c_str());
}


USTRUCT(BlueprintType)
struct  FEvalData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleStar;

};
static void _ConvertPbToFEvalData(FEvalData &msg, const msg::EvalData *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.Rank=pb->rank();
	msg.MaxMoney=pb->maxmoney();
	msg.MinMoney=pb->minmoney();
	msg.BattleStar=pb->battlestar();
}


USTRUCT(BlueprintType)
struct  FMmrChangeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DecCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddLimit;

};
static void _ConvertPbToFMmrChangeData(FMmrChangeData &msg, const msg::MmrChangeData *pb) {
	msg.Cup=pb->cup();
	msg.AddCoefficient=pb->addcoefficient();
	msg.DecCoefficient=pb->deccoefficient();
	msg.AddLimit=pb->addlimit();
}


USTRUCT(BlueprintType)
struct  FMmrRankCoefficientData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rank;

	double Coefficient;

};
static void _ConvertPbToFMmrRankCoefficientData(FMmrRankCoefficientData &msg, const msg::MmrRankCoefficientData *pb) {
	msg.Cup=pb->cup();
	msg.Rank=pb->rank();
	msg.Coefficient=pb->coefficient();
}


USTRUCT(BlueprintType)
struct  FMmrWinFailCoefficientData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rank;

	double Coefficient;

};
static void _ConvertPbToFMmrWinFailCoefficientData(FMmrWinFailCoefficientData &msg, const msg::MmrWinFailCoefficientData *pb) {
	msg.Cup=pb->cup();
	msg.Rank=pb->rank();
	msg.Coefficient=pb->coefficient();
}


USTRUCT(BlueprintType)
struct  FChessPlayerData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Skins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Costume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Mount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ScaleX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ScaleY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShowTheBase;	//是否显示底座

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MedalOffsetPhoneX;	// 勋章偏移量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MedalOffsetPhoneY;	// 勋章偏移量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MedalOffsetPCX;	// 勋章偏移量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MedalOffsetPCY;	// 勋章偏移量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SkinPic;	// 立绘

};
static void _ConvertPbToFChessPlayerData(FChessPlayerData &msg, const msg::ChessPlayerData *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	for (int i = 0; i < pb->skins().size(); i++) {
		auto &a = pb->skins().Get(i);
		int tmp;
		tmp=a;
		msg.Skins.Add(tmp);
	}
	msg.Costume=UTF8_TO_TCHAR(pb->costume().c_str());
	msg.Weapon=UTF8_TO_TCHAR(pb->weapon().c_str());
	msg.Mount=UTF8_TO_TCHAR(pb->mount().c_str());
	msg.X=UTF8_TO_TCHAR(pb->x().c_str());
	msg.Y=UTF8_TO_TCHAR(pb->y().c_str());
	msg.ScaleX=UTF8_TO_TCHAR(pb->scalex().c_str());
	msg.ScaleY=UTF8_TO_TCHAR(pb->scaley().c_str());
	msg.ShowTheBase=pb->showthebase();
	msg.MedalOffsetPhoneX=UTF8_TO_TCHAR(pb->medaloffsetphonex().c_str());
	msg.MedalOffsetPhoneY=UTF8_TO_TCHAR(pb->medaloffsetphoney().c_str());
	msg.MedalOffsetPCX=UTF8_TO_TCHAR(pb->medaloffsetpcx().c_str());
	msg.MedalOffsetPCY=UTF8_TO_TCHAR(pb->medaloffsetpcy().c_str());
	msg.SkinPic=UTF8_TO_TCHAR(pb->skinpic().c_str());
}


USTRUCT(BlueprintType)
struct  FGuideData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SequenceId;

};
static void _ConvertPbToFGuideData(FGuideData &msg, const msg::GuideData *pb) {
	msg.Key=UTF8_TO_TCHAR(pb->key().c_str());
	msg.SequenceId=UTF8_TO_TCHAR(pb->sequenceid().c_str());
}


USTRUCT(BlueprintType)
struct  FDirectLoginPlayerData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;	//龙渊uid

};
static void _ConvertPbToFDirectLoginPlayerData(FDirectLoginPlayerData &msg, const msg::DirectLoginPlayerData *pb) {
	msg.Id=UTF8_TO_TCHAR(pb->id().c_str());
}


USTRUCT(BlueprintType)
struct  FRegionData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Region;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString IdPrefix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMatchMmr;

};
static void _ConvertPbToFRegionData(FRegionData &msg, const msg::RegionData *pb) {
	msg.Region=UTF8_TO_TCHAR(pb->region().c_str());
	msg.IdPrefix=UTF8_TO_TCHAR(pb->idprefix().c_str());
	msg.MaxMatchMmr=pb->maxmatchmmr();
}


USTRUCT(BlueprintType)
struct  FPhoneTypeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DeviceName;	//手机型号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//

};
static void _ConvertPbToFPhoneTypeData(FPhoneTypeData &msg, const msg::PhoneTypeData *pb) {
	msg.DeviceName=UTF8_TO_TCHAR(pb->devicename().c_str());
	msg.Level=pb->level();
}


USTRUCT(BlueprintType)
struct  FChargeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//充值ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHANELTYPE ChannelType;	//渠道类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHARGETYPE Type;	//充值类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Price;	//价格

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diamond;	//获得钻石

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExtraDiamond;	//额外获得钻石

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//充值档图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChannelInfo;	//渠道信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECURRENCYTYPE Unit;	//价格单位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//充值奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PrivatePara;	//辅助参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGoodsName> GoodsNames;	//商品名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Add;	//充值额外赠送diamond

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Show;	//虚拟道具信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Currency;	//货币类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> AwardsValue;	//商品价值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SubIcon;	//pc客户端使用icon

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPSCHARGETYPE PsType;	//ps充值类型

};
static void _ConvertPbToFChargeData(FChargeData &msg, const msg::ChargeData *pb) {
	msg.Id=pb->id();
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.ChannelType=(ECHANELTYPE)pb->channeltype();
	msg.Type=(ECHARGETYPE)pb->type();
	msg.Price=pb->price();
	msg.Diamond=pb->diamond();
	msg.ExtraDiamond=pb->extradiamond();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.ChannelInfo=UTF8_TO_TCHAR(pb->channelinfo().c_str());
	msg.Unit=(ECURRENCYTYPE)pb->unit();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.PrivatePara=pb->privatepara();
	for (int i = 0; i < pb->goodsnames().size(); i++) {
		auto &a = pb->goodsnames().Get(i);
		FGoodsName tmp;
		_ConvertPbToFGoodsName(tmp, &a);
		msg.GoodsNames.Add(tmp);
	}
	msg.Add=pb->add();
	msg.Show=UTF8_TO_TCHAR(pb->show().c_str());
	msg.Currency=UTF8_TO_TCHAR(pb->currency().c_str());
	for (int i = 0; i < pb->awardsvalue().size(); i++) {
		auto &a = pb->awardsvalue().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.AwardsValue.Add(tmp);
	}
	msg.SubIcon=UTF8_TO_TCHAR(pb->subicon().c_str());
	msg.PsType=(EPSCHARGETYPE)pb->pstype();
}


USTRUCT(BlueprintType)
struct  FMultiConfigData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE Type;	//物品类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Random;	//多配置下是否随机

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinSetCount;	//最小配置数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxSetCount;	//最大配置数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//描述

};
static void _ConvertPbToFMultiConfigData(FMultiConfigData &msg, const msg::MultiConfigData *pb) {
	msg.Type=(EITEMTYPE)pb->type();
	msg.Random=pb->random();
	msg.MinSetCount=pb->minsetcount();
	msg.MaxSetCount=pb->maxsetcount();
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
}


USTRUCT(BlueprintType)
struct  FModeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lvl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamPlayerNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ChangeMmr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ChangeExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AiCompetitionCnt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AiCup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FirstWinRank;	// 首胜触发名次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CommentSwitch;	// 评论引导开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CommentRank;	// 评论引导触发名次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ChangeBattleStar;	// 是否可获得战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CampPlayerCount;	// 每个阵营玩家数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Class;	// 所属分类

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActItemExch;	// 集道具活动是否开启

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecommendRatio;	// 推荐比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RecommendFlag;	// 推荐标识

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool FollowObserveFlag;	// 好友观战标识

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ApplyAI;	// 是否适用AI局规则判断

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanForbidden;	// 是否受惩罚影响

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanShowAudienceChat;	// 是否允许对局玩家查看观众聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HidePlayerInfo;	// 游戏确认阶段是否隐藏玩家信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ApplyCustomMode;	// 自定义房间是否可以使用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModeEffects;	// 模式特效

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AudienceNumLimit;	// 观众上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int JudgmentNumLimit;	// 裁判上限

	int64 TimeOutCd;	// 暂停冷却时间

	int64 TimeOutMaxTime;	// 最大暂停时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanUnlockPicbook;	// 是否可解锁图鉴

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyModSwitch;	// 赏金功能开关(官方模式)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyModsys;	// 赏金系统分成(官方模式)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> MoneyModProportion;	// 赏金分成比例(官方模式)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IsMobileMode;	// 为1时，端游不显示相关信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool WatchTransactionCase;	// 观战是否掉落宝箱

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EModeClassType1 ModeClassType1;	// ModeClassType1

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EModeClassType2 ModeClassType2;	// ModeClassType2

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Sort;	// 排序

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QueenRankLimit;	// 皇后段位展示排名限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ChessGroupSwitch;	//  棋组方案开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessGroupInjectionRound;	//棋组注入回合

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TaskModeBeginTime;	// 任务模式开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TaskModeEndTime;	// 任务模式关闭时间

};
static void _ConvertPbToFModeData(FModeData &msg, const msg::ModeData *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Lvl=pb->lvl();
	msg.PlayerNum=pb->playernum();
	msg.TeamPlayerNum=pb->teamplayernum();
	msg.ChangeMmr=pb->changemmr();
	msg.ChangeExp=pb->changeexp();
	msg.AiCompetitionCnt=pb->aicompetitioncnt();
	msg.AiCup=pb->aicup();
	msg.FirstWinRank=pb->firstwinrank();
	msg.CommentSwitch=pb->commentswitch();
	msg.CommentRank=pb->commentrank();
	msg.ChangeBattleStar=pb->changebattlestar();
	msg.CampPlayerCount=pb->campplayercount();
	msg.Class=pb->class_();
	msg.ActItemExch=pb->actitemexch();
	msg.RecommendRatio=pb->recommendratio();
	msg.RecommendFlag=pb->recommendflag();
	msg.FollowObserveFlag=pb->followobserveflag();
	msg.ApplyAI=pb->applyai();
	msg.CanForbidden=pb->canforbidden();
	msg.CanShowAudienceChat=pb->canshowaudiencechat();
	msg.HidePlayerInfo=pb->hideplayerinfo();
	msg.ApplyCustomMode=pb->applycustommode();
	msg.ModeEffects=UTF8_TO_TCHAR(pb->modeeffects().c_str());
	msg.AudienceNumLimit=pb->audiencenumlimit();
	msg.JudgmentNumLimit=pb->judgmentnumlimit();
	msg.TimeOutCd=pb->timeoutcd();
	msg.TimeOutMaxTime=pb->timeoutmaxtime();
	msg.CanUnlockPicbook=pb->canunlockpicbook();
	msg.MoneyModSwitch=pb->moneymodswitch();
	msg.MoneyModsys=pb->moneymodsys();
	for (int i = 0; i < pb->moneymodproportion().size(); i++) {
		auto &a = pb->moneymodproportion().Get(i);
		int tmp;
		tmp=a;
		msg.MoneyModProportion.Add(tmp);
	}
	msg.IsMobileMode=pb->ismobilemode();
	msg.WatchTransactionCase=pb->watchtransactioncase();
	msg.ModeClassType1=(EModeClassType1)pb->modeclasstype1();
	msg.ModeClassType2=(EModeClassType2)pb->modeclasstype2();
	msg.Sort=pb->sort();
	msg.QueenRankLimit=pb->queenranklimit();
	msg.ChessGroupSwitch=pb->chessgroupswitch();
	msg.ChessGroupInjectionRound=pb->chessgroupinjectionround();
	msg.TaskModeBeginTime=UTF8_TO_TCHAR(pb->taskmodebegintime().c_str());
	msg.TaskModeEndTime=UTF8_TO_TCHAR(pb->taskmodeendtime().c_str());
}


USTRUCT(BlueprintType)
struct  FModeSortData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ModeId;	// 模式ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;	// 排序

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PageIndex;	// 页签排序

};
static void _ConvertPbToFModeSortData(FModeSortData &msg, const msg::ModeSortData *pb) {
	msg.ModeId=pb->modeid();
	msg.Index=pb->index();
	msg.PageIndex=pb->pageindex();
}


USTRUCT(BlueprintType)
struct  FPassportLevelData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Level;	//等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleStar;	//升级所需战星

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareType;	//等级分享类型,客户端用

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Loop;	//循环(配合Level计算真实level = level+Loop*Spacing)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Spacing;	//间隔(配合Level计算真实level = level+Loop*Spacing)

};
static void _ConvertPbToFPassportLevelData(FPassportLevelData &msg, const msg::PassportLevelData *pb) {
	msg.Level=UTF8_TO_TCHAR(pb->level().c_str());
	msg.BattleStar=pb->battlestar();
	msg.ShareType=pb->sharetype();
	msg.Loop=pb->loop();
	msg.Spacing=pb->spacing();
}


USTRUCT(BlueprintType)
struct  FPassportLevelAwardData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//奖励ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Season;	//赛季

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//免费奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> ChargeAwards;	//付费奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Value;	//奖励价值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Level;	//等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Enhanced;	//是否显示增强

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SpecialTip;	//特殊提示框

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Loop;	//循环(配合Level计算真实level = level+Loop*Spacing)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Spacing;	//间隔(配合Level计算真实level = level+Loop*Spacing)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPainting;	//是否为立绘

};
static void _ConvertPbToFPassportLevelAwardData(FPassportLevelAwardData &msg, const msg::PassportLevelAwardData *pb) {
	msg.Id=pb->id();
	msg.Season=pb->season();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	for (int i = 0; i < pb->chargeawards().size(); i++) {
		auto &a = pb->chargeawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.ChargeAwards.Add(tmp);
	}
	msg.Value=pb->value();
	msg.Level=UTF8_TO_TCHAR(pb->level().c_str());
	msg.Enhanced=pb->enhanced();
	msg.SpecialTip=UTF8_TO_TCHAR(pb->specialtip().c_str());
	msg.Loop=pb->loop();
	msg.Spacing=pb->spacing();
	msg.IsPainting=pb->ispainting();
}


USTRUCT(BlueprintType)
struct  FPassportData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//通行证ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPASSPORTTYPE Type;	//通行证类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TypeId;	//通行证类型ID(对应通行证类型表)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//购买此通行证消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OnSaleBeginTime;	//打折开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OnSaleEndTime;	//打折结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//购买附加奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPURCHASETYPE PurchaseType;	//购买类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShowUpLevel;	//直升等级提示

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SpecialNameShowType;	//专属昵称展示方案

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ShowAwards;	//展示奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Coefficient;	//积分加成系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Period;	//通行证赛季

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Segment;	//当前段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PreCondTypeId;	//分段购买前置条件TypeID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ConflictTypeId;	//分段购买冲突条件TypeID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SpecialNameShowWeight;	//昵称展示权值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ContinuousSeasons;	//年卡持续赛季数

};
static void _ConvertPbToFPassportData(FPassportData &msg, const msg::PassportData *pb) {
	msg.Id=pb->id();
	msg.Type=(EPASSPORTTYPE)pb->type();
	msg.TypeId=pb->typeid_();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.OnSaleBeginTime=UTF8_TO_TCHAR(pb->onsalebegintime().c_str());
	msg.OnSaleEndTime=UTF8_TO_TCHAR(pb->onsaleendtime().c_str());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.PurchaseType=(EPURCHASETYPE)pb->purchasetype();
	msg.ShowUpLevel=pb->showuplevel();
	msg.SpecialNameShowType=pb->specialnameshowtype();
	for (int i = 0; i < pb->showawards().size(); i++) {
		auto &a = pb->showawards().Get(i);
		int tmp;
		tmp=a;
		msg.ShowAwards.Add(tmp);
	}
	msg.Coefficient=pb->coefficient();
	msg.Period=pb->period();
	msg.Segment=pb->segment();
	msg.PreCondTypeId=UTF8_TO_TCHAR(pb->precondtypeid().c_str());
	msg.ConflictTypeId=UTF8_TO_TCHAR(pb->conflicttypeid().c_str());
	msg.SpecialNameShowWeight=pb->specialnameshowweight();
	msg.ContinuousSeasons=pb->continuousseasons();
}


USTRUCT(BlueprintType)
struct  FPassportTaskData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//任务ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Season;	//赛季 已废弃

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPASSPORTTASKTYPE Type;	//任务类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;	//任务标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//任务描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Unit;	//任务条件单位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCond Cond;	//任务完成条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//任务完成奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankLimit;	//完成回合要求

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CondGroup;	//任务组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PreCondGroup;	//前置任务组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ProgressInherit;	//进度是否继承前置任务进度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> TaskCardConsumes;	//任务卡消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCharge;	//是否是付费任务  0-免费  1-付费

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDifficult;	//是否是困难任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeriesID;	//序列ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QuestLevel;	//通行证等级分享类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPassportShareType QuestShareType;	//通行证任务分享奖励类型:1,通用;2 特殊

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionStartTime;	// 任务开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionENdTime;	// 任务开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;	//所属任务池id

};
static void _ConvertPbToFPassportTaskData(FPassportTaskData &msg, const msg::PassportTaskData *pb) {
	msg.Id=pb->id();
	msg.Season=pb->season();
	msg.Type=(EPASSPORTTASKTYPE)pb->type();
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.Unit=pb->unit();
	_ConvertPbToFCond(msg.Cond, &pb->cond());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.RankLimit=pb->ranklimit();
	msg.CondGroup=pb->condgroup();
	msg.PreCondGroup=pb->precondgroup();
	msg.ProgressInherit=pb->progressinherit();
	for (int i = 0; i < pb->taskcardconsumes().size(); i++) {
		auto &a = pb->taskcardconsumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.TaskCardConsumes.Add(tmp);
	}
	msg.IsCharge=pb->ischarge();
	msg.IsDifficult=pb->isdifficult();
	msg.SeriesID=pb->seriesid();
	msg.QuestLevel=pb->questlevel();
	msg.QuestShareType=(EPassportShareType)pb->questsharetype();
	msg.MissionStartTime=UTF8_TO_TCHAR(pb->missionstarttime().c_str());
	msg.MissionENdTime=UTF8_TO_TCHAR(pb->missionendtime().c_str());
	msg.PoolId=pb->poolid();
}


USTRUCT(BlueprintType)
struct  FPassportTypeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TypeId;	//类型ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LogId;	//日志统计ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UnlockLevel;	//分段通行证等级奖励限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LanguageKey;	//语言key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LastBuyConsumes;	//消费推荐方案

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Recommend;	//投放推荐方案

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShowAwardLevelLimit;	//奖励展示限制等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PlayerInfoBackground;	//局内玩家信息底版开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPASSPORTCARDTYPE CardType;	//卡号类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CoverLevel;	//通行证类型覆盖顺序

};
static void _ConvertPbToFPassportTypeData(FPassportTypeData &msg, const msg::PassportTypeData *pb) {
	msg.TypeId=pb->typeid_();
	msg.LogId=pb->logid();
	msg.UnlockLevel=UTF8_TO_TCHAR(pb->unlocklevel().c_str());
	msg.LanguageKey=UTF8_TO_TCHAR(pb->languagekey().c_str());
	msg.LastBuyConsumes=UTF8_TO_TCHAR(pb->lastbuyconsumes().c_str());
	msg.Recommend=pb->recommend();
	msg.ShowAwardLevelLimit=pb->showawardlevellimit();
	msg.PlayerInfoBackground=pb->playerinfobackground();
	msg.CardType=(EPASSPORTCARDTYPE)pb->cardtype();
	msg.CoverLevel=pb->coverlevel();
}


USTRUCT(BlueprintType)
struct  FSeasonData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BeginDate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EndDate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CondDesc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCond Cond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportBeginDate;	//通行证开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportEndDate;	//通行证结束时间

};
static void _ConvertPbToFSeasonData(FSeasonData &msg, const msg::SeasonData *pb) {
	msg.Id=pb->id();
	msg.BeginDate=UTF8_TO_TCHAR(pb->begindate().c_str());
	msg.EndDate=UTF8_TO_TCHAR(pb->enddate().c_str());
	msg.Cup=pb->cup();
	msg.CondDesc=UTF8_TO_TCHAR(pb->conddesc().c_str());
	_ConvertPbToFCond(msg.Cond, &pb->cond());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.PassportBeginDate=UTF8_TO_TCHAR(pb->passportbegindate().c_str());
	msg.PassportEndDate=UTF8_TO_TCHAR(pb->passportenddate().c_str());
}


USTRUCT(BlueprintType)
struct  FLevelData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	// 等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NeedExp;	// 到下一级需要的经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	// 奖励

};
static void _ConvertPbToFLevelData(FLevelData &msg, const msg::LevelData *pb) {
	msg.Level=pb->level();
	msg.NeedExp=pb->needexp();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FResChessData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//棋子详细ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Races;	//种族

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Professions;	//职业

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Quality;	//品质

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Star;	//星级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessId;	//棋子ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShowTheBase;	//原始棋子是否显示底座

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHESSSTATUS RetreatEnvironment;	//是否退环境

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShowTheBaseTransformation;	//棋子变身是否显示底座

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShowTheBaseSummon;	//棋子召唤物是否显示底座

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KernelChessId;	//棋子内核id

};
static void _ConvertPbToFResChessData(FResChessData &msg, const msg::ChessData *pb) {
	msg.Id=pb->id();
	for (int i = 0; i < pb->races().size(); i++) {
		auto &a = pb->races().Get(i);
		int tmp;
		tmp=a;
		msg.Races.Add(tmp);
	}
	for (int i = 0; i < pb->professions().size(); i++) {
		auto &a = pb->professions().Get(i);
		int tmp;
		tmp=a;
		msg.Professions.Add(tmp);
	}
	msg.Quality=pb->quality();
	msg.Star=pb->star();
	msg.ChessId=pb->chessid();
	msg.ShowTheBase=pb->showthebase();
	msg.RetreatEnvironment=(ECHESSSTATUS)pb->retreatenvironment();
	msg.ShowTheBaseTransformation=pb->showthebasetransformation();
	msg.ShowTheBaseSummon=pb->showthebasesummon();
	msg.KernelChessId=pb->kernelchessid();
}


USTRUCT(BlueprintType)
struct  FPropData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//道具ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE Type;	//物品类型

	int64 Indate;	//道具本身有效期

	int64 EffectIndate;	//道具效果持续时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Coefficient;	//加成系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> UseAwards;	//道具使用奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;	//掉落池Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RandCount;	//随机宝箱单次掉落数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanPutBack;	//随机宝箱是否放回抽取

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExperienceTargetId;	//体验卡目标对象

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityGroupType;	//道具归属活动组id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowDropRate;	//掉落概率展示

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FallId;	//掉落id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KeyId;	//钥匙id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KeyNum;	//钥匙数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDEDUCTIONTYPE DeductionType;	//抵扣券类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PurchaseId;	//购买方案id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DeductionId;	//抵扣货币id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DeductionRate;	//抵扣货币比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DeductionNum;	//抵扣货币数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BoxOpenType;	//宝箱打开方式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassportTypeId;	//通行证分段ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PurchaseType;	// ITEMTYPE 商城抵扣可用的物品类型,多类型用英文逗号隔开

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PurchaseItemId;	//商城抵扣购买物品id,多个id 用 `,` 分隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEXPERIENCE_TYPE ExperienceType;	//体验卡类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CumulativeRewardId;	//宝箱保底奖励表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Reductionswitch;	// 是否减价礼包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ExtraPoolId;	// 额外掉落池Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ExtraRandCount;	// 额外随机宝箱单次掉落数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<bool> ExtraCanPutBack;	// 额外随机宝箱是否放回抽取

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ExtraShowDropRate;	// 额外掉落概率展示

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ChoiceBoxSwitch;	// 是否自选礼包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivateSeasonId;	// 能激活的赛季ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivateTypeId;	// 能激活的通行证类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TransformSwitch;	// 重复激活卡转化物品开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TransformItemId;	// 重复激活卡转化物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TransformItemNum;	// 转化物品数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UnrepeatBoxSwitch;	// 去重礼包标记

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivateItemId;	// 多选一激活卡付费项货币

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivatePrice;	// 多选一激活卡付费项货币

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FOpenData> OpenChest;	// 开启方式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SkipKeyAnimation;	// 跳过钥匙动画

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHESOPENTYPE ChestOpenType;	// 宝箱开启类型(服务器专用)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChestOpenTime;	// 宝箱可开启时间

};
static void _ConvertPbToFPropData(FPropData &msg, const msg::PropData *pb) {
	msg.Id=pb->id();
	msg.Type=(EITEMTYPE)pb->type();
	msg.Indate=pb->indate();
	msg.EffectIndate=pb->effectindate();
	msg.Coefficient=pb->coefficient();
	for (int i = 0; i < pb->useawards().size(); i++) {
		auto &a = pb->useawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.UseAwards.Add(tmp);
	}
	msg.PoolId=pb->poolid();
	msg.RandCount=pb->randcount();
	msg.CanPutBack=pb->canputback();
	msg.ExperienceTargetId=pb->experiencetargetid();
	msg.ActivityGroupType=UTF8_TO_TCHAR(pb->activitygrouptype().c_str());
	msg.ShowDropRate=UTF8_TO_TCHAR(pb->showdroprate().c_str());
	msg.FallId=pb->fallid();
	msg.KeyId=pb->keyid();
	msg.KeyNum=pb->keynum();
	msg.DeductionType=(EDEDUCTIONTYPE)pb->deductiontype();
	msg.PurchaseId=UTF8_TO_TCHAR(pb->purchaseid().c_str());
	msg.DeductionId=pb->deductionid();
	msg.DeductionRate=pb->deductionrate();
	msg.DeductionNum=pb->deductionnum();
	msg.BoxOpenType=UTF8_TO_TCHAR(pb->boxopentype().c_str());
	msg.PassportTypeId=pb->passporttypeid();
	msg.PurchaseType=UTF8_TO_TCHAR(pb->purchasetype().c_str());
	msg.PurchaseItemId=UTF8_TO_TCHAR(pb->purchaseitemid().c_str());
	msg.ExperienceType=(EEXPERIENCE_TYPE)pb->experiencetype();
	msg.CumulativeRewardId=pb->cumulativerewardid();
	msg.Reductionswitch=pb->reductionswitch();
	for (int i = 0; i < pb->extrapoolid().size(); i++) {
		auto &a = pb->extrapoolid().Get(i);
		int tmp;
		tmp=a;
		msg.ExtraPoolId.Add(tmp);
	}
	for (int i = 0; i < pb->extrarandcount().size(); i++) {
		auto &a = pb->extrarandcount().Get(i);
		int tmp;
		tmp=a;
		msg.ExtraRandCount.Add(tmp);
	}
	for (int i = 0; i < pb->extracanputback().size(); i++) {
		auto &a = pb->extracanputback().Get(i);
		bool tmp;
		tmp=a;
		msg.ExtraCanPutBack.Add(tmp);
	}
	for (int i = 0; i < pb->extrashowdroprate().size(); i++) {
		auto &a = pb->extrashowdroprate().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ExtraShowDropRate.Add(tmp);
	}
	msg.ChoiceBoxSwitch=pb->choiceboxswitch();
	msg.ActivateSeasonId=UTF8_TO_TCHAR(pb->activateseasonid().c_str());
	msg.ActivateTypeId=UTF8_TO_TCHAR(pb->activatetypeid().c_str());
	msg.TransformSwitch=pb->transformswitch();
	msg.TransformItemId=pb->transformitemid();
	msg.TransformItemNum=pb->transformitemnum();
	msg.UnrepeatBoxSwitch=pb->unrepeatboxswitch();
	msg.ActivateItemId=UTF8_TO_TCHAR(pb->activateitemid().c_str());
	msg.ActivatePrice=UTF8_TO_TCHAR(pb->activateprice().c_str());
	for (int i = 0; i < pb->openchest().size(); i++) {
		auto &a = pb->openchest().Get(i);
		FOpenData tmp;
		_ConvertPbToFOpenData(tmp, &a);
		msg.OpenChest.Add(tmp);
	}
	msg.SkipKeyAnimation=pb->skipkeyanimation();
	msg.ChestOpenType=(ECHESOPENTYPE)pb->chestopentype();
	msg.ChestOpenTime=UTF8_TO_TCHAR(pb->chestopentime().c_str());
}


USTRUCT(BlueprintType)
struct  FCumulativeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// 保底ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RewardReset;	// 重置标记

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCumulativeAward> Cumulative;	// 保底奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Rewardpicture;

};
static void _ConvertPbToFCumulativeData(FCumulativeData &msg, const msg::CumulativeData *pb) {
	msg.Id=pb->id();
	msg.RewardReset=pb->rewardreset();
	for (int i = 0; i < pb->cumulative().size(); i++) {
		auto &a = pb->cumulative().Get(i);
		FCumulativeAward tmp;
		_ConvertPbToFCumulativeAward(tmp, &a);
		msg.Cumulative.Add(tmp);
	}
	for (int i = 0; i < pb->rewardpicture().size(); i++) {
		auto &a = pb->rewardpicture().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Rewardpicture.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCondParaphraseData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cond;	//条件类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Para;	//参数

};
static void _ConvertPbToFCondParaphraseData(FCondParaphraseData &msg, const msg::CondParaphraseData *pb) {
	msg.Cond=pb->cond();
	for (int i = 0; i < pb->para().size(); i++) {
		auto &a = pb->para().Get(i);
		int tmp;
		tmp=a;
		msg.Para.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMeleeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Week;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCond Cond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CondDesc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CampPlayerCount;	//每个阵营玩家数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ApplyAI;	//是否适用AI局规则判断

};
static void _ConvertPbToFMeleeData(FMeleeData &msg, const msg::MeleeData *pb) {
	msg.Week=pb->week();
	msg.Rule=pb->rule();
	_ConvertPbToFCond(msg.Cond, &pb->cond());
	msg.CondDesc=UTF8_TO_TCHAR(pb->conddesc().c_str());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.CampPlayerCount=pb->campplayercount();
	msg.ApplyAI=pb->applyai();
}


USTRUCT(BlueprintType)
struct  FPsActivity {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ModeId;	//模式id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityId;	// PS5活动

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lvl;	// 等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CampPlayerCount;	// 阵营玩家数量

};
static void _ConvertPbToFPsActivity(FPsActivity &msg, const msg::PsActivity *pb) {
	msg.ModeId=pb->modeid();
	msg.ActivityId=UTF8_TO_TCHAR(pb->activityid().c_str());
	msg.Lvl=pb->lvl();
	msg.CampPlayerCount=pb->campplayercount();
}


USTRUCT(BlueprintType)
struct  FLineUpData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RaceId;	//种族ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	//权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Modes;	//模式

};
static void _ConvertPbToFLineUpData(FLineUpData &msg, const msg::LineUpData *pb) {
	msg.RaceId=pb->raceid();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.Weight=pb->weight();
	for (int i = 0; i < pb->modes().size(); i++) {
		auto &a = pb->modes().Get(i);
		int tmp;
		tmp=a;
		msg.Modes.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGenreData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RaceId;	//种族ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//流派ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//流派名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Difficulty;	//上手难度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChessList;	//棋子列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AdvantageList;	//阵容优势

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WeaknessList;	//阵容劣势

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PriorChessList;	//优先三星的棋子列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FStandbyChess> StandbyChessList;	//备选棋子列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShareName;	//吃鸡分享阵容文本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShareTex;	//吃鸡分享阵容描述文本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Modes;	//模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VideoId;	//视频id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CoreChess;	// 核心棋子

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChessLevel;	// 棋子星级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Display;	// 是否展示

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChessTeamPlan;	// 卡组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TypeId;	// 卡组所属方typeId

};
static void _ConvertPbToFGenreData(FGenreData &msg, const msg::GenreData *pb) {
	msg.RaceId=pb->raceid();
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.Difficulty=pb->difficulty();
	msg.ChessList=UTF8_TO_TCHAR(pb->chesslist().c_str());
	msg.AdvantageList=UTF8_TO_TCHAR(pb->advantagelist().c_str());
	msg.WeaknessList=UTF8_TO_TCHAR(pb->weaknesslist().c_str());
	msg.PriorChessList=UTF8_TO_TCHAR(pb->priorchesslist().c_str());
	for (int i = 0; i < pb->standbychesslist().size(); i++) {
		auto &a = pb->standbychesslist().Get(i);
		FStandbyChess tmp;
		_ConvertPbToFStandbyChess(tmp, &a);
		msg.StandbyChessList.Add(tmp);
	}
	msg.ShareName=UTF8_TO_TCHAR(pb->sharename().c_str());
	msg.ShareTex=UTF8_TO_TCHAR(pb->sharetex().c_str());
	for (int i = 0; i < pb->modes().size(); i++) {
		auto &a = pb->modes().Get(i);
		int tmp;
		tmp=a;
		msg.Modes.Add(tmp);
	}
	msg.VideoId=pb->videoid();
	msg.CoreChess=UTF8_TO_TCHAR(pb->corechess().c_str());
	msg.ChessLevel=UTF8_TO_TCHAR(pb->chesslevel().c_str());
	msg.Display=pb->display();
	msg.ChessTeamPlan=UTF8_TO_TCHAR(pb->chessteamplan().c_str());
	msg.TypeId=UTF8_TO_TCHAR(pb->typeid_().c_str());
}


USTRUCT(BlueprintType)
struct  FEggData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//扭蛋ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEGGTYPE Type;	//扭蛋类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//扭蛋名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BeginShowTime;	//展示开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EndShowTime;	//展示结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BeginTime;	//开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EndTime;	//结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Order;	//展示优先级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//扭蛋描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxCount;	//扭蛋最大抽取次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEggConsume> BuyHeadPicConsume;	//扭蛋头像购买消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GuaranteeCount;	//扭蛋保底次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> OriginalPrice;	//扭蛋头像单次购买原价

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool FirstGuarantee;	//该扭蛋是否支持首抽保底功能

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//扭蛋图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> EggLotteryConsumes;	//扭蛋抽奖消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> BuyHeadPicAwards;	//购买扭蛋头像奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> BuyHeadPicGiveAwards;	//购买扭蛋头像赠送奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SubName;	//副标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowDropRate;	//概率展示

};
static void _ConvertPbToFEggData(FEggData &msg, const msg::EggData *pb) {
	msg.Id=pb->id();
	msg.Type=(EEGGTYPE)pb->type();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.BeginShowTime=UTF8_TO_TCHAR(pb->beginshowtime().c_str());
	msg.EndShowTime=UTF8_TO_TCHAR(pb->endshowtime().c_str());
	msg.BeginTime=UTF8_TO_TCHAR(pb->begintime().c_str());
	msg.EndTime=UTF8_TO_TCHAR(pb->endtime().c_str());
	msg.Order=pb->order();
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.MaxCount=pb->maxcount();
	for (int i = 0; i < pb->buyheadpicconsume().size(); i++) {
		auto &a = pb->buyheadpicconsume().Get(i);
		FEggConsume tmp;
		_ConvertPbToFEggConsume(tmp, &a);
		msg.BuyHeadPicConsume.Add(tmp);
	}
	msg.GuaranteeCount=pb->guaranteecount();
	for (int i = 0; i < pb->originalprice().size(); i++) {
		auto &a = pb->originalprice().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.OriginalPrice.Add(tmp);
	}
	msg.FirstGuarantee=pb->firstguarantee();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	for (int i = 0; i < pb->egglotteryconsumes().size(); i++) {
		auto &a = pb->egglotteryconsumes().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.EggLotteryConsumes.Add(tmp);
	}
	for (int i = 0; i < pb->buyheadpicawards().size(); i++) {
		auto &a = pb->buyheadpicawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.BuyHeadPicAwards.Add(tmp);
	}
	for (int i = 0; i < pb->buyheadpicgiveawards().size(); i++) {
		auto &a = pb->buyheadpicgiveawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.BuyHeadPicGiveAwards.Add(tmp);
	}
	msg.SubName=UTF8_TO_TCHAR(pb->subname().c_str());
	msg.ShowDropRate=UTF8_TO_TCHAR(pb->showdroprate().c_str());
}


USTRUCT(BlueprintType)
struct  FGoodsDetail {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//商品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//商品名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//商品描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//商品内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//商品价格

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//商品图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Background;	//商品背景

};
static void _ConvertPbToFGoodsDetail(FGoodsDetail &msg, const msg::GoodsDetail *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
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
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.Background=UTF8_TO_TCHAR(pb->background().c_str());
}


USTRUCT(BlueprintType)
struct  FGoodsRandData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESHOPTYPE Type;	//商店类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Forbid;	//格子时候失效

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRandLib> RandLibs;	//商品库

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Uid;	//唯一ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DropCount;	//掉落数量

};
static void _ConvertPbToFGoodsRandData(FGoodsRandData &msg, const msg::GoodsRandData *pb) {
	msg.Type=(ESHOPTYPE)pb->type();
	msg.Forbid=pb->forbid();
	for (int i = 0; i < pb->randlibs().size(); i++) {
		auto &a = pb->randlibs().Get(i);
		FRandLib tmp;
		_ConvertPbToFRandLib(tmp, &a);
		msg.RandLibs.Add(tmp);
	}
	msg.Uid=pb->uid();
	msg.DropCount=pb->dropcount();
}


USTRUCT(BlueprintType)
struct  FPassportShopData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//商品内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Consumes;	//商品价格

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassportLevel;	//通行证登记限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuyLimit;	//购买限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EREFRESHTYPE RefreshType;	//刷新方式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SortId;	//排序Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeasonId;	//赛季

};
static void _ConvertPbToFPassportShopData(FPassportShopData &msg, const msg::PassportShopData *pb) {
	msg.Id=pb->id();
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
	msg.PassportLevel=pb->passportlevel();
	msg.BuyLimit=pb->buylimit();
	msg.RefreshType=(EREFRESHTYPE)pb->refreshtype();
	msg.SortId=pb->sortid();
	msg.SeasonId=pb->seasonid();
}


USTRUCT(BlueprintType)
struct  FRandChestAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//奖励序列号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;	//掉落池池Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAward AwardItem;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	//权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShowWeight;	//展示权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsHide;	//是否隐藏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Isrepeat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FReduction> Reduction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRarePool;	// 珍稀掉落 每个奖励独立抽取 权重为万分率

};
static void _ConvertPbToFRandChestAward(FRandChestAward &msg, const msg::RandChestAward *pb) {
	msg.Id=pb->id();
	msg.PoolId=pb->poolid();
	_ConvertPbToFAward(msg.AwardItem, &pb->awarditem());
	msg.Weight=pb->weight();
	msg.ShowWeight=pb->showweight();
	msg.IsHide=pb->ishide();
	msg.Isrepeat=pb->isrepeat();
	for (int i = 0; i < pb->reduction().size(); i++) {
		auto &a = pb->reduction().Get(i);
		FReduction tmp;
		_ConvertPbToFReduction(tmp, &a);
		msg.Reduction.Add(tmp);
	}
	msg.IsRarePool=pb->israrepool();
}


USTRUCT(BlueprintType)
struct  FAITriggerData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TriggerId;	//ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAITRIGGERTYPE TriggerType;	//触发条件类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EPVPMODE> Modes;	//触发模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxCount;	//最大游戏场次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinMMR;	////MMR范围

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMMR;	//MMR范围

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ScoreRange;	//离当前段位分数范围

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NoLoginDays;	//连续未登录天数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGameLimit> GameLimits;	//游戏场次限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRankLimit> RankLimits;	//排名限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxTeamAvgMMR;	//最大队伍平均值MMR

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinTeamAvgMMR;	//最小队伍平均值MMR

};
static void _ConvertPbToFAITriggerData(FAITriggerData &msg, const msg::AITriggerData *pb) {
	msg.TriggerId=pb->triggerid();
	msg.TriggerType=(EAITRIGGERTYPE)pb->triggertype();
	for (int i = 0; i < pb->modes().size(); i++) {
		auto &a = pb->modes().Get(i);
		EPVPMODE tmp;
		tmp=(EPVPMODE)a;
		msg.Modes.Add(tmp);
	}
	msg.MaxCount=pb->maxcount();
	msg.MinMMR=pb->minmmr();
	msg.MaxMMR=pb->maxmmr();
	msg.ScoreRange=pb->scorerange();
	msg.NoLoginDays=pb->nologindays();
	for (int i = 0; i < pb->gamelimits().size(); i++) {
		auto &a = pb->gamelimits().Get(i);
		FGameLimit tmp;
		_ConvertPbToFGameLimit(tmp, &a);
		msg.GameLimits.Add(tmp);
	}
	for (int i = 0; i < pb->ranklimits().size(); i++) {
		auto &a = pb->ranklimits().Get(i);
		FRankLimit tmp;
		_ConvertPbToFRankLimit(tmp, &a);
		msg.RankLimits.Add(tmp);
	}
	msg.MaxTeamAvgMMR=pb->maxteamavgmmr();
	msg.MinTeamAvgMMR=pb->minteamavgmmr();
}


USTRUCT(BlueprintType)
struct  FAIAssistantData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//效果ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TriggerId;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EPVPMODE> Modes;	//辅助模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayCount;	//第几局

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMMR;	//MMR限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRankLimit> RankLimits;	//排名限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AiEvalMMr;	//ai结算的mmr

};
static void _ConvertPbToFAIAssistantData(FAIAssistantData &msg, const msg::AIAssistantData *pb) {
	msg.Id=pb->id();
	msg.TriggerId=pb->triggerid();
	for (int i = 0; i < pb->modes().size(); i++) {
		auto &a = pb->modes().Get(i);
		EPVPMODE tmp;
		tmp=(EPVPMODE)a;
		msg.Modes.Add(tmp);
	}
	msg.PlayCount=pb->playcount();
	msg.MaxMMR=pb->maxmmr();
	for (int i = 0; i < pb->ranklimits().size(); i++) {
		auto &a = pb->ranklimits().Get(i);
		FRankLimit tmp;
		_ConvertPbToFRankLimit(tmp, &a);
		msg.RankLimits.Add(tmp);
	}
	msg.AiEvalMMr=pb->aievalmmr();
}


USTRUCT(BlueprintType)
struct  FDaySignAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Day;	// 第几天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsSpecial;	// 是否是特殊奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	// 奖励内容

};
static void _ConvertPbToFDaySignAward(FDaySignAward &msg, const msg::DaySignAward *pb) {
	msg.Day=pb->day();
	msg.IsSpecial=pb->isspecial();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActDaySignAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActivityGroupId;	// 活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Day;	// 第几天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsSpecial;	// 第几天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	// 奖励内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SignDay;	// 大奖配置规则

};
static void _ConvertPbToFActDaySignAward(FActDaySignAward &msg, const msg::ActDaySignAward *pb) {
	msg.ActivityGroupId=pb->activitygroupid();
	msg.Day=pb->day();
	msg.IsSpecial=pb->isspecial();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.SignDay=pb->signday();
}


USTRUCT(BlueprintType)
struct  FActReSignConsume {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActivityGroupId;	// 活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ReSiginTimes;	// 重签次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Conds;	// 商品价格

};
static void _ConvertPbToFActReSignConsume(FActReSignConsume &msg, const msg::ActReSignConsume *pb) {
	msg.ActivityGroupId=pb->activitygroupid();
	msg.ReSiginTimes=pb->resigintimes();
	for (int i = 0; i < pb->conds().size(); i++) {
		auto &a = pb->conds().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Conds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FDynamicTips {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TipsDes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Cond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Param;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int JumpID;

};
static void _ConvertPbToFDynamicTips(FDynamicTips &msg, const msg::DynamicTips *pb) {
	msg.ID=pb->id();
	msg.TipsDes=UTF8_TO_TCHAR(pb->tipsdes().c_str());
	for (int i = 0; i < pb->cond().size(); i++) {
		auto &a = pb->cond().Get(i);
		int tmp;
		tmp=a;
		msg.Cond.Add(tmp);
	}
	for (int i = 0; i < pb->param().size(); i++) {
		auto &a = pb->param().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Param.Add(tmp);
	}
	msg.JumpID=pb->jumpid();
}


USTRUCT(BlueprintType)
struct  FMonthShareAward {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	// 月累计分享次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	// 奖励

};
static void _ConvertPbToFMonthShareAward(FMonthShareAward &msg, const msg::MonthShareAward *pb) {
	msg.Count=pb->count();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessShareData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString X;	//对应界面预制该节点的X坐标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Y;	//对应界面预制该节点的Y坐标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ScaleX;	//对应界面预制该节点的X坐标缩放值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ScaleY;	//对应界面预制该节点的Y坐标缩放值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterDec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Type;

};
static void _ConvertPbToFChessShareData(FChessShareData &msg, const msg::ChessShareData *pb) {
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.X=UTF8_TO_TCHAR(pb->x().c_str());
	msg.Y=UTF8_TO_TCHAR(pb->y().c_str());
	msg.ScaleX=UTF8_TO_TCHAR(pb->scalex().c_str());
	msg.ScaleY=UTF8_TO_TCHAR(pb->scaley().c_str());
	msg.CharacterTex=UTF8_TO_TCHAR(pb->charactertex().c_str());
	msg.CharacterDec=UTF8_TO_TCHAR(pb->characterdec().c_str());
	msg.Type=pb->type();
}


USTRUCT(BlueprintType)
struct  FCountryData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;	//国家名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Continent;	//洲

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CountryLog;	//国旗图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Sort;	//大洲排序权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Area;	//地理分区

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Zone;	//分区

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityJumpLink;	//端游需要字段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DivisionId;	//赛区分组ID

};
static void _ConvertPbToFCountryData(FCountryData &msg, const msg::CountryData *pb) {
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.Continent=UTF8_TO_TCHAR(pb->continent().c_str());
	msg.CountryLog=UTF8_TO_TCHAR(pb->countrylog().c_str());
	msg.Sort=pb->sort();
	msg.Area=UTF8_TO_TCHAR(pb->area().c_str());
	msg.Zone=pb->zone();
	msg.ActivityJumpLink=UTF8_TO_TCHAR(pb->activityjumplink().c_str());
	msg.DivisionId=pb->divisionid();
}


USTRUCT(BlueprintType)
struct  FProvinceData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ProvinceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SDKKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Province;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ProvinceShorthand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Region;

};
static void _ConvertPbToFProvinceData(FProvinceData &msg, const msg::ProvinceData *pb) {
	msg.ProvinceId=pb->provinceid();
	msg.SDKKey=UTF8_TO_TCHAR(pb->sdkkey().c_str());
	msg.Province=UTF8_TO_TCHAR(pb->province().c_str());
	msg.ProvinceShorthand=UTF8_TO_TCHAR(pb->provinceshorthand().c_str());
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.Region=pb->region();
}


USTRUCT(BlueprintType)
struct  FItemOutputItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoundRank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModeList;	//模式列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

};
static void _ConvertPbToFItemOutputItem(FItemOutputItem &msg, const msg::ItemOutputItem *pb) {
	msg.Id=pb->id();
	msg.RoundRank=pb->roundrank();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.ModeList=UTF8_TO_TCHAR(pb->modelist().c_str());
	msg.GroupId=pb->groupid();
}


USTRUCT(BlueprintType)
struct  FItemExchangeItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemDesc;	//描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LimitedCount;	//兑换次数限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Conds;	//被兑换道具

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//兑换得到道具

};
static void _ConvertPbToFItemExchangeItem(FItemExchangeItem &msg, const msg::ItemExchangeItem *pb) {
	msg.Id=pb->id();
	msg.GroupId=pb->groupid();
	msg.ItemDesc=UTF8_TO_TCHAR(pb->itemdesc().c_str());
	msg.LimitedCount=pb->limitedcount();
	for (int i = 0; i < pb->conds().size(); i++) {
		auto &a = pb->conds().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Conds.Add(tmp);
	}
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPassportPeriodData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//赛季

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportBeginDate;	//通行证开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportEndDate;	//通行证结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Name;	//通行证名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> PopupADS;	//弹窗广告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ImageADS;	//图像广告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BuyPassportADS;	//购买通行证广告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ShowAwards;	//展示奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DiamondRebate;	//甜甜圈购买是否返利

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CashRebate;	//现金购买是否返利

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxLevel;	//每赛季最大等级限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StartRemindLastDays;	//赛季未剩余提示天数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StartRemindLevel;	//开始提示等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StartRemindLockLevel;	//开始提示未解锁等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StartRemindType;	//推荐分阶段等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TaskPoolId;	//任务池id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayFreeTaskCount;	//天免费任务数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayFreeDifficultTaskCount;	//天免费困难任务数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayChargeTaskCount;	//天付费任务数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayChargeDifficultTaskCount;	//天付费困难任务数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekFreeTaskCount;	//周免费任务数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekFreeDifficultTaskCount;	//周免费困难任务数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekChargeTaskCount;	//周付费任务数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekChargeDifficultTaskCount;	//周付费困难任务数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayMaxPoint;	//每天获取战星上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekMaxPoint;	//周获取战星上限

};
static void _ConvertPbToFPassportPeriodData(FPassportPeriodData &msg, const msg::PassportPeriodData *pb) {
	msg.Id=pb->id();
	msg.PassportBeginDate=UTF8_TO_TCHAR(pb->passportbegindate().c_str());
	msg.PassportEndDate=UTF8_TO_TCHAR(pb->passportenddate().c_str());
	for (int i = 0; i < pb->name().size(); i++) {
		auto &a = pb->name().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Name.Add(tmp);
	}
	for (int i = 0; i < pb->popupads().size(); i++) {
		auto &a = pb->popupads().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.PopupADS.Add(tmp);
	}
	msg.ImageADS=UTF8_TO_TCHAR(pb->imageads().c_str());
	msg.BuyPassportADS=UTF8_TO_TCHAR(pb->buypassportads().c_str());
	for (int i = 0; i < pb->showawards().size(); i++) {
		auto &a = pb->showawards().Get(i);
		int tmp;
		tmp=a;
		msg.ShowAwards.Add(tmp);
	}
	msg.DiamondRebate=pb->diamondrebate();
	msg.CashRebate=pb->cashrebate();
	msg.MaxLevel=pb->maxlevel();
	msg.StartRemindLastDays=pb->startremindlastdays();
	msg.StartRemindLevel=pb->startremindlevel();
	msg.StartRemindLockLevel=pb->startremindlocklevel();
	msg.StartRemindType=pb->startremindtype();
	msg.TaskPoolId=pb->taskpoolid();
	msg.DayFreeTaskCount=pb->dayfreetaskcount();
	msg.DayFreeDifficultTaskCount=pb->dayfreedifficulttaskcount();
	msg.DayChargeTaskCount=pb->daychargetaskcount();
	msg.DayChargeDifficultTaskCount=pb->daychargedifficulttaskcount();
	msg.WeekFreeTaskCount=pb->weekfreetaskcount();
	msg.WeekFreeDifficultTaskCount=pb->weekfreedifficulttaskcount();
	msg.WeekChargeTaskCount=pb->weekchargetaskcount();
	msg.WeekChargeDifficultTaskCount=pb->weekchargedifficulttaskcount();
	msg.DayMaxPoint=pb->daymaxpoint();
	msg.WeekMaxPoint=pb->weekmaxpoint();
}


USTRUCT(BlueprintType)
struct  FGroupPayItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Type;	//充值档位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Limits;	//购买次数限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PayNum1;	//第1档购买人次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards1;	//第1档达成奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PayNum2;	//第2档购买人次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards2;	//第2档达成奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PayNum3;	//第3档购买人次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards3;	//第3档达成奖励

};
static void _ConvertPbToFGroupPayItem(FGroupPayItem &msg, const msg::GroupPayItem *pb) {
	msg.Id=pb->id();
	msg.Type=pb->type();
	msg.Limits=pb->limits();
	msg.PayNum1=pb->paynum1();
	for (int i = 0; i < pb->awards1().size(); i++) {
		auto &a = pb->awards1().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards1.Add(tmp);
	}
	msg.PayNum2=pb->paynum2();
	for (int i = 0; i < pb->awards2().size(); i++) {
		auto &a = pb->awards2().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards2.Add(tmp);
	}
	msg.PayNum3=pb->paynum3();
	for (int i = 0; i < pb->awards3().size(); i++) {
		auto &a = pb->awards3().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards3.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FFitAvoidItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;	// 宜忌池子类型id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LanguageId;	// 宜忌文字id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	// 权重

};
static void _ConvertPbToFFitAvoidItem(FFitAvoidItem &msg, const msg::FitAvoidItem *pb) {
	msg.Id=pb->id();
	msg.PoolId=pb->poolid();
	msg.LanguageId=UTF8_TO_TCHAR(pb->languageid().c_str());
	msg.Weight=pb->weight();
}


USTRUCT(BlueprintType)
struct  FVNGCcyItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Currency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECURRENCYTYPE Unit;

};
static void _ConvertPbToFVNGCcyItem(FVNGCcyItem &msg, const msg::VNGCcyItem *pb) {
	msg.Id=pb->id();
	msg.Currency=UTF8_TO_TCHAR(pb->currency().c_str());
	msg.Unit=(ECURRENCYTYPE)pb->unit();
}


USTRUCT(BlueprintType)
struct  FVNGExchangeItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Currency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Purchase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diamond;

};
static void _ConvertPbToFVNGExchangeItem(FVNGExchangeItem &msg, const msg::VNGExchangeItem *pb) {
	msg.Id=pb->id();
	msg.Currency=UTF8_TO_TCHAR(pb->currency().c_str());
	msg.Purchase=pb->purchase();
	msg.Diamond=pb->diamond();
}


USTRUCT(BlueprintType)
struct  FVNGFirstPayItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExtraDiamond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FirstRechargeGroup;

};
static void _ConvertPbToFVNGFirstPayItem(FVNGFirstPayItem &msg, const msg::VNGFirstPayItem *pb) {
	msg.Id=pb->id();
	msg.ExtraDiamond=pb->extradiamond();
	msg.FirstRechargeGroup=pb->firstrechargegroup();
}


USTRUCT(BlueprintType)
struct  FActReturnRewardItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OfflineDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Day;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	// 活动组表 组id

};
static void _ConvertPbToFActReturnRewardItem(FActReturnRewardItem &msg, const msg::ActReturnRewardItem *pb) {
	msg.Id=pb->id();
	msg.OfflineDay=pb->offlineday();
	msg.Day=pb->day();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.GroupId=pb->groupid();
}


USTRUCT(BlueprintType)
struct  FObserveLevelData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxObserveCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;

};
static void _ConvertPbToFObserveLevelData(FObserveLevelData &msg, const msg::ObserveLevelData *pb) {
	msg.Id=pb->id();
	msg.MaxObserveCount=pb->maxobservecount();
	msg.Mode=(EPVPMODE)pb->mode();
}


USTRUCT(BlueprintType)
struct  FWxVVipRightItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LvPlayer;	//大玩家等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CondType;	//特权类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Param1;	//特权类型参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GiftId;	//礼包码id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextMailTitle;	//邮件title

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextMailcontent;	//邮件content

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Announce;	//公告

};
static void _ConvertPbToFWxVVipRightItem(FWxVVipRightItem &msg, const msg::WxVVipRightItem *pb) {
	msg.Id=pb->id();
	msg.LvPlayer=pb->lvplayer();
	msg.CondType=pb->condtype();
	msg.Param1=pb->param1();
	msg.GiftId=pb->giftid();
	msg.TextMailTitle=UTF8_TO_TCHAR(pb->textmailtitle().c_str());
	msg.TextMailcontent=UTF8_TO_TCHAR(pb->textmailcontent().c_str());
	msg.Announce=pb->announce();
}


USTRUCT(BlueprintType)
struct  FGiftItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFGiftItem(FGiftItem &msg, const msg::GiftItem *pb) {
	msg.Id=pb->id();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMarqueeItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//跑马灯id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Announce;	//跑马灯key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AnnouncePriority;	//跑马灯优先级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AnnounceRO;	//跑马灯生命周期

};
static void _ConvertPbToFMarqueeItem(FMarqueeItem &msg, const msg::MarqueeItem *pb) {
	msg.Id=pb->id();
	msg.Announce=UTF8_TO_TCHAR(pb->announce().c_str());
	msg.AnnouncePriority=pb->announcepriority();
	msg.AnnounceRO=pb->announcero();
}


USTRUCT(BlueprintType)
struct  FRedPacketItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//红包id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> Conds;	//消耗道具

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ClaimCount;	//领取人数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;	//领取道具id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemCount;	//领取道具数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PacketRankNum;	//红包领取数量显示

};
static void _ConvertPbToFRedPacketItem(FRedPacketItem &msg, const msg::RedPacketItem *pb) {
	msg.Id=pb->id();
	for (int i = 0; i < pb->conds().size(); i++) {
		auto &a = pb->conds().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.Conds.Add(tmp);
	}
	msg.ClaimCount=pb->claimcount();
	msg.ItemId=pb->itemid();
	msg.ItemCount=pb->itemcount();
	msg.PacketRankNum=pb->packetranknum();
}


USTRUCT(BlueprintType)
struct  FWxVVipRankRwdItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextMailTitle;	//邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextMailcontent;	//邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextRank;	//奖励排行区间（纯前端字段）

};
static void _ConvertPbToFWxVVipRankRwdItem(FWxVVipRankRwdItem &msg, const msg::WxVVipRankRwdItem *pb) {
	msg.Id=pb->id();
	msg.Rank=pb->rank();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.TextMailTitle=UTF8_TO_TCHAR(pb->textmailtitle().c_str());
	msg.TextMailcontent=UTF8_TO_TCHAR(pb->textmailcontent().c_str());
	msg.TextRank=UTF8_TO_TCHAR(pb->textrank().c_str());
}


USTRUCT(BlueprintType)
struct  FPunishmentData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	//叠加次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EPUNISHMENTTYPE> Types;	//惩罚方式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExecuteTime;	//执行期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WatchTime;	//监视期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPunishmentTrigger> Triggers;	//触发行为

};
static void _ConvertPbToFPunishmentData(FPunishmentData &msg, const msg::PunishmentData *pb) {
	msg.Id=pb->id();
	msg.Count=pb->count();
	for (int i = 0; i < pb->types().size(); i++) {
		auto &a = pb->types().Get(i);
		EPUNISHMENTTYPE tmp;
		tmp=(EPUNISHMENTTYPE)a;
		msg.Types.Add(tmp);
	}
	msg.ExecuteTime=pb->executetime();
	msg.WatchTime=pb->watchtime();
	for (int i = 0; i < pb->triggers().size(); i++) {
		auto &a = pb->triggers().Get(i);
		FPunishmentTrigger tmp;
		_ConvertPbToFPunishmentTrigger(tmp, &a);
		msg.Triggers.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FQuickChatData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Group;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;

};
static void _ConvertPbToFQuickChatData(FQuickChatData &msg, const msg::QuickChatData *pb) {
	msg.Id=pb->id();
	msg.Group=pb->group();
	msg.Key=UTF8_TO_TCHAR(pb->key().c_str());
}


USTRUCT(BlueprintType)
struct  FLoadingRankData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LanguageId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UnlockLevel;

};
static void _ConvertPbToFLoadingRankData(FLoadingRankData &msg, const msg::LoadingRankData *pb) {
	msg.Id=pb->id();
	msg.PoolId=pb->poolid();
	msg.LanguageId=UTF8_TO_TCHAR(pb->languageid().c_str());
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.UnlockLevel=pb->unlocklevel();
}


USTRUCT(BlueprintType)
struct  FQuestionnaireData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	// 问卷ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	// 问卷名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupID;	// 问卷对应的活动组id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	// 奖励

};
static void _ConvertPbToFQuestionnaireData(FQuestionnaireData &msg, const msg::QuestionnaireData *pb) {
	msg.ID=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.GroupID=pb->groupid();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FQuestionnairePlayerList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	// 问卷id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerID;	// 玩家id

};
static void _ConvertPbToFQuestionnairePlayerList(FQuestionnairePlayerList &msg, const msg::QuestionnairePlayerList *pb) {
	msg.ID=pb->id();
	msg.PlayerID=UTF8_TO_TCHAR(pb->playerid().c_str());
}


USTRUCT(BlueprintType)
struct  FQuestionnaireContent {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// 问卷id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QuestionId;	// 题目序号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OptionId;	// 选项ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OptionType;	// 内容类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QuestionType;	// 题目类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Compulsive;	// 是否必答

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QuestionJump;	// 题目跳转

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	// 选项内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MultipleLimit;	// 多选题选项限制

};
static void _ConvertPbToFQuestionnaireContent(FQuestionnaireContent &msg, const msg::QuestionnaireContent *pb) {
	msg.Id=pb->id();
	msg.QuestionId=pb->questionid();
	msg.OptionId=pb->optionid();
	msg.OptionType=pb->optiontype();
	msg.QuestionType=pb->questiontype();
	msg.Compulsive=pb->compulsive();
	msg.QuestionJump=pb->questionjump();
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.MultipleLimit=pb->multiplelimit();
}


USTRUCT(BlueprintType)
struct  FResSkillInfoItem {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int id;	// id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LanguageKey;	// 语言key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString KeyInfo;	// 信息数组

};
static void _ConvertPbToFResSkillInfoItem(FResSkillInfoItem &msg, const msg::SkillInfoItem *pb) {
	msg.id=pb->id();
	msg.LanguageKey=UTF8_TO_TCHAR(pb->languagekey().c_str());
	msg.KeyInfo=UTF8_TO_TCHAR(pb->keyinfo().c_str());
}


USTRUCT(BlueprintType)
struct  FAILevelData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinAIRankMMR;	//MMR下限 -1表示无下限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxAIRankMMR;	//MMR上限 -1表示无上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//AI难度等级

};
static void _ConvertPbToFAILevelData(FAILevelData &msg, const msg::AILevelData *pb) {
	msg.MinAIRankMMR=pb->minairankmmr();
	msg.MaxAIRankMMR=pb->maxairankmmr();
	msg.Id=pb->id();
}


USTRUCT(BlueprintType)
struct  FChessSkinSeriesData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//系列ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChessSkinName;	//皮肤名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMQUALITY ChessSkinStage;	//皮肤品质

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> SkinIds;	//各星级的皮肤

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessId;	//所属棋子ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SkipInterface;	//获取功能跳转界面

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkipTab;	//获取功能跳转切页

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowBeginTime;	//显示开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowEndTime;	//显示结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lv1ExchangeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lv1ExchangeNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lv2ExchangeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lv2ExchangeNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lv3ExchangeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lv3ExchangeNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkinSetId;	//皮肤套装ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSkinInfo> SkinInfos;	//皮肤数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HandBookShow;

};
static void _ConvertPbToFChessSkinSeriesData(FChessSkinSeriesData &msg, const msg::ChessSkinSeriesData *pb) {
	msg.Id=pb->id();
	msg.ChessSkinName=UTF8_TO_TCHAR(pb->chessskinname().c_str());
	msg.ChessSkinStage=(EITEMQUALITY)pb->chessskinstage();
	for (int i = 0; i < pb->skinids().size(); i++) {
		auto &a = pb->skinids().Get(i);
		int tmp;
		tmp=a;
		msg.SkinIds.Add(tmp);
	}
	msg.ChessId=pb->chessid();
	msg.SkipInterface=UTF8_TO_TCHAR(pb->skipinterface().c_str());
	msg.SkipTab=pb->skiptab();
	msg.ShowBeginTime=UTF8_TO_TCHAR(pb->showbegintime().c_str());
	msg.ShowEndTime=UTF8_TO_TCHAR(pb->showendtime().c_str());
	msg.Lv1ExchangeType=pb->lv1exchangetype();
	msg.Lv1ExchangeNum=pb->lv1exchangenum();
	msg.Lv2ExchangeType=pb->lv2exchangetype();
	msg.Lv2ExchangeNum=pb->lv2exchangenum();
	msg.Lv3ExchangeType=pb->lv3exchangetype();
	msg.Lv3ExchangeNum=pb->lv3exchangenum();
	msg.SkinSetId=pb->skinsetid();
	for (int i = 0; i < pb->skininfos().size(); i++) {
		auto &a = pb->skininfos().Get(i);
		FSkinInfo tmp;
		_ConvertPbToFSkinInfo(tmp, &a);
		msg.SkinInfos.Add(tmp);
	}
	msg.HandBookShow=pb->handbookshow();
}


USTRUCT(BlueprintType)
struct  FComposeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ComposeId;	//合成ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//合成的物品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FComposeMaterial> Material;	//合成材料

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalComposeValue;	//合成总共所需合成值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCond> ComposeLimit;	//合成前置条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RepeatCompose;	//是否可以重复合成，即如果玩家拥有了该物品，是否允许合成

};
static void _ConvertPbToFComposeData(FComposeData &msg, const msg::ComposeData *pb) {
	msg.ComposeId=pb->composeid();
	msg.Id=pb->id();
	for (int i = 0; i < pb->material().size(); i++) {
		auto &a = pb->material().Get(i);
		FComposeMaterial tmp;
		_ConvertPbToFComposeMaterial(tmp, &a);
		msg.Material.Add(tmp);
	}
	msg.TotalComposeValue=pb->totalcomposevalue();
	for (int i = 0; i < pb->composelimit().size(); i++) {
		auto &a = pb->composelimit().Get(i);
		FCond tmp;
		_ConvertPbToFCond(tmp, &a);
		msg.ComposeLimit.Add(tmp);
	}
	msg.RepeatCompose=pb->repeatcompose();
}


USTRUCT(BlueprintType)
struct  FMoreStrongerData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//短描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UIId;	//跳转的界面ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubUIId;	//跳转的子界面ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Level;	//对应等级的权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//icon

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PcJumpUrl;	// pc跳转url

};
static void _ConvertPbToFMoreStrongerData(FMoreStrongerData &msg, const msg::MoreStrongerData *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.UIId=UTF8_TO_TCHAR(pb->uiid().c_str());
	msg.SubUIId=pb->subuiid();
	for (int i = 0; i < pb->level().size(); i++) {
		auto &a = pb->level().Get(i);
		int tmp;
		tmp=a;
		msg.Level.Add(tmp);
	}
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.PcJumpUrl=UTF8_TO_TCHAR(pb->pcjumpurl().c_str());
}


USTRUCT(BlueprintType)
struct  FAddictionData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAddictionType Type;	//类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;	//国家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NotAllowStartTime;	//不允许时间段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NotAllowEndTime;	//不允许时间段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AgeMin;	//年龄段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AgeMax;	//年龄段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Interval;	//时间间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SigninDesc;	//登录弹窗文本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString HallDesc;	//游戏内弹窗文本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PhoneOpen;	//手机端开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PCOpen;	// PC端开关

};
static void _ConvertPbToFAddictionData(FAddictionData &msg, const msg::AddictionData *pb) {
	msg.ID=pb->id();
	msg.Type=(EAddictionType)pb->type();
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.NotAllowStartTime=UTF8_TO_TCHAR(pb->notallowstarttime().c_str());
	msg.NotAllowEndTime=UTF8_TO_TCHAR(pb->notallowendtime().c_str());
	msg.AgeMin=pb->agemin();
	msg.AgeMax=pb->agemax();
	msg.Interval=pb->interval();
	msg.SigninDesc=UTF8_TO_TCHAR(pb->signindesc().c_str());
	msg.HallDesc=UTF8_TO_TCHAR(pb->halldesc().c_str());
	msg.PhoneOpen=pb->phoneopen();
	msg.PCOpen=pb->pcopen();
}


USTRUCT(BlueprintType)
struct  FAmazonGiftData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailDesc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

};
static void _ConvertPbToFAmazonGiftData(FAmazonGiftData &msg, const msg::AmazonGiftData *pb) {
	msg.Id=pb->id();
	msg.MailTitle=UTF8_TO_TCHAR(pb->mailtitle().c_str());
	msg.MailDesc=UTF8_TO_TCHAR(pb->maildesc().c_str());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FFallData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFalledType FallType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CommonFallPoolId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CritFallPoolId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HopeCrit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PopAddGroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TimeAddGroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LevelAddGroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanPutBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExtractNum;

};
static void _ConvertPbToFFallData(FFallData &msg, const msg::FallData *pb) {
	msg.ID=pb->id();
	msg.FallType=(EFalledType)pb->falltype();
	msg.CommonFallPoolId=pb->commonfallpoolid();
	msg.CritFallPoolId=pb->critfallpoolid();
	msg.HopeCrit=pb->hopecrit();
	msg.PopAddGroupId=pb->popaddgroupid();
	msg.TimeAddGroupId=pb->timeaddgroupid();
	msg.LevelAddGroupId=pb->leveladdgroupid();
	msg.CanPutBack=pb->canputback();
	msg.ExtractNum=pb->extractnum();
}


USTRUCT(BlueprintType)
struct  FCritAddData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFallAddType AddType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddY;

};
static void _ConvertPbToFCritAddData(FCritAddData &msg, const msg::CritAddData *pb) {
	msg.ID=pb->id();
	msg.GroupId=pb->groupid();
	msg.AddType=(EFallAddType)pb->addtype();
	msg.AddX=pb->addx();
	msg.AddY=pb->addy();
}


USTRUCT(BlueprintType)
struct  FNetDelayData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDELAYTYPE Type;	//延迟类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxPing;	//当前类型最高延迟

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PriorityTime;	//优先匹配当前类型的最大匹配时间

};
static void _ConvertPbToFNetDelayData(FNetDelayData &msg, const msg::NetDelayData *pb) {
	msg.Type=(EDELAYTYPE)pb->type();
	msg.MaxPing=pb->maxping();
	msg.PriorityTime=pb->prioritytime();
}


USTRUCT(BlueprintType)
struct  FRegionMatchData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Region;	//区域

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Open;	//是否开启区域匹配

};
static void _ConvertPbToFRegionMatchData(FRegionMatchData &msg, const msg::RegionMatchData *pb) {
	msg.Region=UTF8_TO_TCHAR(pb->region().c_str());
	msg.Open=pb->open();
}


USTRUCT(BlueprintType)
struct  FTournamentData {
	GENERATED_BODY()

	uint64 TournamentId;	//赛事ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentName;	//赛事名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> TournamentDes;	//赛事描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOWNERTYPE Owner;	//所有者

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETOURNAMENTTYPE TournamentType;	//赛事类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TournamentZoneId;	//允许参与国籍组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAdvertising;	//是否展示广告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AdImagePath;	//广告图路径

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AttendTimeLimit;	//允许重复参与次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ResettingPointsIds;	//重置积分类型（积分ID）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentStartTime;	//赛事开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EnrollStartTime;	//报名开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EnrollEndTime;	//报名结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentEndTime;	//赛事结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE TournamentMode;	//赛事游戏模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBATTLEGROUPTYPE BattleGroupDistribution;	//战斗组分配方式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanSkipRoundMatching;	//是否允许跨轮匹配

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkipRoundMatchingTimeLimit;	//跨轮匹配时间阈值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TournamentAwardIds;	//赛事奖励

	TArray<uint64> TournamentClassIds;	//赛事包含的级别

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> TournamentLabel;	//赛事标签

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> TournamentLabelDes;	//赛事标签说明

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecommendProportion;	//推荐占比

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecommendRanking;	//推荐权重

	TArray<uint64> ResettingPointsTournaments;	//重置积分的对象是哪些赛事的报名人员

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETournamentTimeType ChampionshipType;	//赛事类型 区分周、月、季赛

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChampionshipGroup;	//表明哪些赛事是同一组

};
static void _ConvertPbToFTournamentData(FTournamentData &msg, const msg::TournamentData *pb) {
	msg.TournamentId=pb->tournamentid();
	msg.TournamentName=UTF8_TO_TCHAR(pb->tournamentname().c_str());
	for (int i = 0; i < pb->tournamentdes().size(); i++) {
		auto &a = pb->tournamentdes().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.TournamentDes.Add(tmp);
	}
	msg.Owner=(EOWNERTYPE)pb->owner();
	msg.TournamentType=(ETOURNAMENTTYPE)pb->tournamenttype();
	msg.TournamentZoneId=pb->tournamentzoneid();
	msg.IsAdvertising=pb->isadvertising();
	msg.AdImagePath=UTF8_TO_TCHAR(pb->adimagepath().c_str());
	msg.AttendTimeLimit=pb->attendtimelimit();
	for (int i = 0; i < pb->resettingpointsids().size(); i++) {
		auto &a = pb->resettingpointsids().Get(i);
		int tmp;
		tmp=a;
		msg.ResettingPointsIds.Add(tmp);
	}
	msg.TournamentStartTime=UTF8_TO_TCHAR(pb->tournamentstarttime().c_str());
	msg.EnrollStartTime=UTF8_TO_TCHAR(pb->enrollstarttime().c_str());
	msg.EnrollEndTime=UTF8_TO_TCHAR(pb->enrollendtime().c_str());
	msg.TournamentEndTime=UTF8_TO_TCHAR(pb->tournamentendtime().c_str());
	msg.TournamentMode=(EPVPMODE)pb->tournamentmode();
	msg.BattleGroupDistribution=(EBATTLEGROUPTYPE)pb->battlegroupdistribution();
	msg.CanSkipRoundMatching=pb->canskiproundmatching();
	msg.SkipRoundMatchingTimeLimit=pb->skiproundmatchingtimelimit();
	for (int i = 0; i < pb->tournamentawardids().size(); i++) {
		auto &a = pb->tournamentawardids().Get(i);
		int tmp;
		tmp=a;
		msg.TournamentAwardIds.Add(tmp);
	}
	for (int i = 0; i < pb->tournamentclassids().size(); i++) {
		auto &a = pb->tournamentclassids().Get(i);
		uint64 tmp;
		tmp=a;
		msg.TournamentClassIds.Add(tmp);
	}
	for (int i = 0; i < pb->tournamentlabel().size(); i++) {
		auto &a = pb->tournamentlabel().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.TournamentLabel.Add(tmp);
	}
	for (int i = 0; i < pb->tournamentlabeldes().size(); i++) {
		auto &a = pb->tournamentlabeldes().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.TournamentLabelDes.Add(tmp);
	}
	msg.RecommendProportion=pb->recommendproportion();
	msg.RecommendRanking=pb->recommendranking();
	for (int i = 0; i < pb->resettingpointstournaments().size(); i++) {
		auto &a = pb->resettingpointstournaments().Get(i);
		uint64 tmp;
		tmp=a;
		msg.ResettingPointsTournaments.Add(tmp);
	}
	msg.ChampionshipType=(ETournamentTimeType)pb->championshiptype();
	msg.ChampionshipGroup=pb->championshipgroup();
}


USTRUCT(BlueprintType)
struct  FTournamentClassData {
	GENERATED_BODY()

	uint64 TournamentClassId;	//赛事级别ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentClassName;	//赛事级别名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerMaxLimit;	//参与玩家上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerMinLimit;	//参与玩家下限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMaxLimit;	//最高段位限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMinLimit;	//最低段位限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> RankValidSeasons;	//段位有效赛季

	TArray<uint64> TournamentRoundIds;	//包含的轮次ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEnrollTicket> EnrollTickets;	//所需物品信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TournamentClassAwardIds;	//赛事级别奖励

};
static void _ConvertPbToFTournamentClassData(FTournamentClassData &msg, const msg::TournamentClassData *pb) {
	msg.TournamentClassId=pb->tournamentclassid();
	msg.TournamentClassName=UTF8_TO_TCHAR(pb->tournamentclassname().c_str());
	msg.PlayerMaxLimit=pb->playermaxlimit();
	msg.PlayerMinLimit=pb->playerminlimit();
	msg.RankMaxLimit=pb->rankmaxlimit();
	msg.RankMinLimit=pb->rankminlimit();
	for (int i = 0; i < pb->rankvalidseasons().size(); i++) {
		auto &a = pb->rankvalidseasons().Get(i);
		int tmp;
		tmp=a;
		msg.RankValidSeasons.Add(tmp);
	}
	for (int i = 0; i < pb->tournamentroundids().size(); i++) {
		auto &a = pb->tournamentroundids().Get(i);
		uint64 tmp;
		tmp=a;
		msg.TournamentRoundIds.Add(tmp);
	}
	for (int i = 0; i < pb->enrolltickets().size(); i++) {
		auto &a = pb->enrolltickets().Get(i);
		FEnrollTicket tmp;
		_ConvertPbToFEnrollTicket(tmp, &a);
		msg.EnrollTickets.Add(tmp);
	}
	for (int i = 0; i < pb->tournamentclassawardids().size(); i++) {
		auto &a = pb->tournamentclassawardids().Get(i);
		int tmp;
		tmp=a;
		msg.TournamentClassAwardIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTournamentRoundData {
	GENERATED_BODY()

	uint64 TournamentRoundId;	//赛事轮次ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentRoundName;	//赛事轮次名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanCheckPointsRanking;	//是否允许查看积分排名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RoundStartTime;	//轮次开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RoundEndTime;	//轮次结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActivationTimeRange> ActivationTimeRanges;	//轮次激活时间范围

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAllRise;	//是否全部晋级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CheckPointId;	//检查积分ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RisePointLimit;	//晋级积分类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RiseMinRanking;	//积分排名晋级限制名次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankingLimits;	//排名范围

	TArray<uint64> TournamentGamesIds;	//所含对局信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TournamentRoundAwardIds;	//赛事轮次奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Observeicon;	//观战推荐页图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Observebg;	//观战推荐页背景

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsNotice;	//是否预告轮次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NoticeTitle;	//预告副标题

};
static void _ConvertPbToFTournamentRoundData(FTournamentRoundData &msg, const msg::TournamentRoundData *pb) {
	msg.TournamentRoundId=pb->tournamentroundid();
	msg.TournamentRoundName=UTF8_TO_TCHAR(pb->tournamentroundname().c_str());
	msg.CanCheckPointsRanking=pb->cancheckpointsranking();
	msg.RoundStartTime=UTF8_TO_TCHAR(pb->roundstarttime().c_str());
	msg.RoundEndTime=UTF8_TO_TCHAR(pb->roundendtime().c_str());
	for (int i = 0; i < pb->activationtimeranges().size(); i++) {
		auto &a = pb->activationtimeranges().Get(i);
		FActivationTimeRange tmp;
		_ConvertPbToFActivationTimeRange(tmp, &a);
		msg.ActivationTimeRanges.Add(tmp);
	}
	msg.IsAllRise=pb->isallrise();
	msg.CheckPointId=pb->checkpointid();
	msg.RisePointLimit=pb->risepointlimit();
	msg.RiseMinRanking=pb->riseminranking();
	msg.RankingLimits=pb->rankinglimits();
	for (int i = 0; i < pb->tournamentgamesids().size(); i++) {
		auto &a = pb->tournamentgamesids().Get(i);
		uint64 tmp;
		tmp=a;
		msg.TournamentGamesIds.Add(tmp);
	}
	for (int i = 0; i < pb->tournamentroundawardids().size(); i++) {
		auto &a = pb->tournamentroundawardids().Get(i);
		int tmp;
		tmp=a;
		msg.TournamentRoundAwardIds.Add(tmp);
	}
	msg.Observeicon=UTF8_TO_TCHAR(pb->observeicon().c_str());
	msg.Observebg=UTF8_TO_TCHAR(pb->observebg().c_str());
	msg.IsNotice=pb->isnotice();
	msg.NoticeTitle=UTF8_TO_TCHAR(pb->noticetitle().c_str());
}


USTRUCT(BlueprintType)
struct  FTournamentGamesData {
	GENERATED_BODY()

	uint64 TournamentGamesId;	//赛事对局ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentGamesName;	//赛事对局名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRemind;	//对局开始提醒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GameStartTime;	//对局开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GameFixedEndTime;	//对局固定截止时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GameIntervalEndTime;	//对局截止间隔时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GameEndTime;	//对局结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GameStartCountDown;	//战斗开始倒计时

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> TournamentGameAwardIds;	//赛事对局奖励

};
static void _ConvertPbToFTournamentGamesData(FTournamentGamesData &msg, const msg::TournamentGamesData *pb) {
	msg.TournamentGamesId=pb->tournamentgamesid();
	msg.TournamentGamesName=UTF8_TO_TCHAR(pb->tournamentgamesname().c_str());
	msg.IsRemind=pb->isremind();
	msg.GameStartTime=UTF8_TO_TCHAR(pb->gamestarttime().c_str());
	msg.GameFixedEndTime=UTF8_TO_TCHAR(pb->gamefixedendtime().c_str());
	msg.GameIntervalEndTime=pb->gameintervalendtime();
	msg.GameEndTime=UTF8_TO_TCHAR(pb->gameendtime().c_str());
	msg.GameStartCountDown=pb->gamestartcountdown();
	for (int i = 0; i < pb->tournamentgameawardids().size(); i++) {
		auto &a = pb->tournamentgameawardids().Get(i);
		int tmp;
		tmp=a;
		msg.TournamentGameAwardIds.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTournamentAwardsData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TournamentAwardId;	//赛事奖励ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETOURNAMENTAWARDTYPE TournamentAwardType;	//奖励类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> FixedAwards;	//固定奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TournamentPointId;	//检索积分类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETOURNAMENTLAYER AwardRankLimit;	//积分排行范围

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRangeAward> RangeAwards;	//范围奖励

};
static void _ConvertPbToFTournamentAwardsData(FTournamentAwardsData &msg, const msg::TournamentAwardsData *pb) {
	msg.TournamentAwardId=pb->tournamentawardid();
	msg.TournamentAwardType=(ETOURNAMENTAWARDTYPE)pb->tournamentawardtype();
	for (int i = 0; i < pb->fixedawards().size(); i++) {
		auto &a = pb->fixedawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.FixedAwards.Add(tmp);
	}
	msg.TournamentPointId=pb->tournamentpointid();
	msg.AwardRankLimit=(ETOURNAMENTLAYER)pb->awardranklimit();
	for (int i = 0; i < pb->rangeawards().size(); i++) {
		auto &a = pb->rangeawards().Get(i);
		FRangeAward tmp;
		_ConvertPbToFRangeAward(tmp, &a);
		msg.RangeAwards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FVideoCGData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cgtype;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Cgname;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CgStarttime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CgEndtime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkipGoods;	//跳转的商品id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkipType;	//跳转的类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CgFirstPlayTime;	//每次打开游戏首次登陆背景动画播放节点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCgSubTitle;	//是否有字幕

};
static void _ConvertPbToFVideoCGData(FVideoCGData &msg, const msg::VideoCGData *pb) {
	msg.Id=pb->id();
	msg.Cgtype=pb->cgtype();
	msg.Cgname=UTF8_TO_TCHAR(pb->cgname().c_str());
	msg.CgStarttime=UTF8_TO_TCHAR(pb->cgstarttime().c_str());
	msg.CgEndtime=UTF8_TO_TCHAR(pb->cgendtime().c_str());
	msg.SkipGoods=pb->skipgoods();
	msg.SkipType=pb->skiptype();
	msg.CgFirstPlayTime=pb->cgfirstplaytime();
	msg.IsCgSubTitle=pb->iscgsubtitle();
}


USTRUCT(BlueprintType)
struct  FEntranceNoticeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PicName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Country;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Zone;	// uint32为兼容老协议的Zone类型

};
static void _ConvertPbToFEntranceNoticeData(FEntranceNoticeData &msg, const msg::EntranceNoticeData *pb) {
	msg.Id=pb->id();
	msg.PicName=UTF8_TO_TCHAR(pb->picname().c_str());
	msg.Country=UTF8_TO_TCHAR(pb->country().c_str());
	msg.Zone=pb->zone();
}


USTRUCT(BlueprintType)
struct  FChatHistoryMessageData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECHATTYPE ID;

	int64 SaveDateLimit;	// 频道服务器消息缓存时间; 0 是无限大

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SaveTime;	// 频道消息客户端缓存时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SaveClientLimit;	// 历史增加客户端缓存时间

};
static void _ConvertPbToFChatHistoryMessageData(FChatHistoryMessageData &msg, const msg::ChatHistoryMessageData *pb) {
	msg.ID=(ECHATTYPE)pb->id();
	msg.SaveDateLimit=pb->savedatelimit();
	msg.SaveTime=UTF8_TO_TCHAR(pb->savetime().c_str());
	msg.SaveClientLimit=pb->saveclientlimit();
}


USTRUCT(BlueprintType)
struct  FABTestData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EABTESTTYPE Type;	//AB测试类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FABTestWeight> Weight;	//购买此通行证消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EffectBeginTime;	//生效开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EffectEndTime;	//生效结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EffectCountry;	//开放国家(空代表全开放)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Open;	//开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EffectPlatform;	//开放平台(空代表全开放)

};
static void _ConvertPbToFABTestData(FABTestData &msg, const msg::ABTestData *pb) {
	msg.Id=pb->id();
	msg.Type=(EABTESTTYPE)pb->type();
	for (int i = 0; i < pb->weight().size(); i++) {
		auto &a = pb->weight().Get(i);
		FABTestWeight tmp;
		_ConvertPbToFABTestWeight(tmp, &a);
		msg.Weight.Add(tmp);
	}
	msg.EffectBeginTime=UTF8_TO_TCHAR(pb->effectbegintime().c_str());
	msg.EffectEndTime=UTF8_TO_TCHAR(pb->effectendtime().c_str());
	msg.EffectCountry=UTF8_TO_TCHAR(pb->effectcountry().c_str());
	msg.Open=pb->open();
	msg.EffectPlatform=UTF8_TO_TCHAR(pb->effectplatform().c_str());
}


USTRUCT(BlueprintType)
struct  FObserveScoreData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVPMODE Mode;	//战斗模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRCoefficient;	//MMR系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Top1Coefficient;	//吃鸡率系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Top2Coefficient;	//前二率系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Top3Coefficient;	//前三率系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AveragePvpCoefficient;	//每周每日平均场次系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AttendanceCoefficient;	//观众人数系数

};
static void _ConvertPbToFObserveScoreData(FObserveScoreData &msg, const msg::ObserveScoreData *pb) {
	msg.Mode=(EPVPMODE)pb->mode();
	msg.MMRCoefficient=pb->mmrcoefficient();
	msg.Top1Coefficient=pb->top1coefficient();
	msg.Top2Coefficient=pb->top2coefficient();
	msg.Top3Coefficient=pb->top3coefficient();
	msg.AveragePvpCoefficient=pb->averagepvpcoefficient();
	msg.AttendanceCoefficient=pb->attendancecoefficient();
}


USTRUCT(BlueprintType)
struct  FObserveTaskData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//任务ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETIMEFLAG RefreshType;	//刷新类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;	//任务标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//任务描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCond Cond;	//条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RandomDropPoolIds;	//随机掉落池ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ResetDuration;	//重置周期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RandCount;	//随机宝箱单次掉落数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanPutBack;	//随机宝箱是否放回抽取

};
static void _ConvertPbToFObserveTaskData(FObserveTaskData &msg, const msg::ObserveTaskData *pb) {
	msg.Id=pb->id();
	msg.RefreshType=(ETIMEFLAG)pb->refreshtype();
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	_ConvertPbToFCond(msg.Cond, &pb->cond());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.RandomDropPoolIds=pb->randomdroppoolids();
	msg.ResetDuration=pb->resetduration();
	msg.RandCount=pb->randcount();
	msg.CanPutBack=pb->canputback();
}


USTRUCT(BlueprintType)
struct  FCommunityRedirectionData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPackChannel ChannelType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TitleDesc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AppLink;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Language;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OpenID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Scheme;

};
static void _ConvertPbToFCommunityRedirectionData(FCommunityRedirectionData &msg, const msg::CommunityRedirectionData *pb) {
	msg.ID=pb->id();
	msg.ChannelType=(EPackChannel)pb->channeltype();
	msg.TitleDesc=UTF8_TO_TCHAR(pb->titledesc().c_str());
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.Url=UTF8_TO_TCHAR(pb->url().c_str());
	msg.AppLink=UTF8_TO_TCHAR(pb->applink().c_str());
	msg.Language=UTF8_TO_TCHAR(pb->language().c_str());
	msg.OpenID=pb->openid();
	msg.Scheme=UTF8_TO_TCHAR(pb->scheme().c_str());
}


USTRUCT(BlueprintType)
struct  FSteamRoportData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Reporttype;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Reporttypekey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Reporttypetext;

};
static void _ConvertPbToFSteamRoportData(FSteamRoportData &msg, const msg::SteamRoportData *pb) {
	msg.Reporttype=pb->reporttype();
	msg.Reporttypekey=UTF8_TO_TCHAR(pb->reporttypekey().c_str());
	msg.Reporttypetext=UTF8_TO_TCHAR(pb->reporttypetext().c_str());
}


USTRUCT(BlueprintType)
struct  FSteamMapLanguageData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MapKey;

};
static void _ConvertPbToFSteamMapLanguageData(FSteamMapLanguageData &msg, const msg::SteamMapLanguageData *pb) {
	msg.Id=pb->id();
	msg.MapKey=UTF8_TO_TCHAR(pb->mapkey().c_str());
}


USTRUCT(BlueprintType)
struct  FChestLevelupData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OrderID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UnlockScoreID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UnlockScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChestsName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

};
static void _ConvertPbToFChestLevelupData(FChestLevelupData &msg, const msg::ChestLevelupData *pb) {
	msg.GroupId=pb->groupid();
	msg.OrderID=pb->orderid();
	msg.UnlockScoreID=pb->unlockscoreid();
	msg.UnlockScore=pb->unlockscore();
	msg.ChestsName=UTF8_TO_TCHAR(pb->chestsname().c_str());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
}


USTRUCT(BlueprintType)
struct  FFunctionUnlockData {
	GENERATED_BODY()

	EFUNCID MainID;

	EFUNCID SubfunctionID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Open;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFUNCUNLOCKTYPE UnlockType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UnlockParameter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PopupOpen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UIStylePhone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UIStylePC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EntranceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UnlockTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UnlockDesc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UnlockPic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UIStylePhoneID;

};
static void _ConvertPbToFFunctionUnlockData(FFunctionUnlockData &msg, const msg::FunctionUnlockData *pb) {
	msg.MainID=(EFUNCID)pb->mainid();
	msg.SubfunctionID=(EFUNCID)pb->subfunctionid();
	msg.Open=pb->open();
	msg.UnlockType=(EFUNCUNLOCKTYPE)pb->unlocktype();
	msg.UnlockParameter=pb->unlockparameter();
	msg.PopupOpen=pb->popupopen();
	msg.UIStylePhone=UTF8_TO_TCHAR(pb->uistylephone().c_str());
	msg.UIStylePC=UTF8_TO_TCHAR(pb->uistylepc().c_str());
	msg.EntranceType=pb->entrancetype();
	msg.UnlockTitle=UTF8_TO_TCHAR(pb->unlocktitle().c_str());
	msg.UnlockDesc=UTF8_TO_TCHAR(pb->unlockdesc().c_str());
	msg.UnlockPic=UTF8_TO_TCHAR(pb->unlockpic().c_str());
	msg.UIStylePhoneID=pb->uistylephoneid();
}


USTRUCT(BlueprintType)
struct  FAdvertiseData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdvertPage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdvertAwardPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdvertAwardRandCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AdvertAwardCanPutBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CumulativeRewardId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AdvertStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AdvertEndTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdvertEffectiveCD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdvertEffectiveCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdvertCountRefreshSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AdvertCountRefreshDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AdvertChannel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AdvertChannelIOS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AdvertChannelAndroid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AdvertAPPid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SdkType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SdkWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Group;	// 统计分组

};
static void _ConvertPbToFAdvertiseData(FAdvertiseData &msg, const msg::AdvertiseData *pb) {
	msg.Id=pb->id();
	msg.AdvertPage=pb->advertpage();
	msg.AdvertAwardPool=pb->advertawardpool();
	msg.AdvertAwardRandCount=pb->advertawardrandcount();
	msg.AdvertAwardCanPutBack=pb->advertawardcanputback();
	msg.CumulativeRewardId=pb->cumulativerewardid();
	msg.AdvertStartTime=UTF8_TO_TCHAR(pb->advertstarttime().c_str());
	msg.AdvertEndTime=UTF8_TO_TCHAR(pb->advertendtime().c_str());
	msg.AdvertEffectiveCD=pb->adverteffectivecd();
	msg.AdvertEffectiveCount=pb->adverteffectivecount();
	msg.AdvertCountRefreshSecond=pb->advertcountrefreshsecond();
	msg.AdvertCountRefreshDay=pb->advertcountrefreshday();
	msg.AdvertChannel=UTF8_TO_TCHAR(pb->advertchannel().c_str());
	msg.AdvertChannelIOS=UTF8_TO_TCHAR(pb->advertchannelios().c_str());
	msg.AdvertChannelAndroid=UTF8_TO_TCHAR(pb->advertchannelandroid().c_str());
	msg.AdvertAPPid=UTF8_TO_TCHAR(pb->advertappid().c_str());
	msg.SdkType=UTF8_TO_TCHAR(pb->sdktype().c_str());
	msg.SdkWeight=pb->sdkweight();
	msg.Group=pb->group();
}


USTRUCT(BlueprintType)
struct  FGuildLevelData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GuildLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GuildExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMember;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxViceAtevent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxManager;

};
static void _ConvertPbToFGuildLevelData(FGuildLevelData &msg, const msg::GuildLevelData *pb) {
	msg.GuildLevel=pb->guildlevel();
	msg.GuildExp=pb->guildexp();
	msg.MaxMember=pb->maxmember();
	msg.MaxViceAtevent=pb->maxviceatevent();
	msg.MaxManager=pb->maxmanager();
}


USTRUCT(BlueprintType)
struct  FGuildTagData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PatternType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UnlockCondition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ConditionValue;

};
static void _ConvertPbToFGuildTagData(FGuildTagData &msg, const msg::GuildTagData *pb) {
	msg.Id=pb->id();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.PatternType=pb->patterntype();
	msg.UnlockCondition=pb->unlockcondition();
	for (int i = 0; i < pb->conditionvalue().size(); i++) {
		auto &a = pb->conditionvalue().Get(i);
		int tmp;
		tmp=a;
		msg.ConditionValue.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRepriceRandChestData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BoxId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Reward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Num;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Sortweight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Reductiontype;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Reduction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Isrepeat;

};
static void _ConvertPbToFRepriceRandChestData(FRepriceRandChestData &msg, const msg::RepriceRandChestData *pb) {
	msg.Id=pb->id();
	msg.BoxId=pb->boxid();
	msg.Reward=pb->reward();
	msg.Num=pb->num();
	msg.Sortweight=pb->sortweight();
	msg.Reductiontype=pb->reductiontype();
	msg.Reduction=pb->reduction();
	msg.Isrepeat=pb->isrepeat();
}


USTRUCT(BlueprintType)
struct  FTeachPassData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//关卡id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChapterId;	//章节id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassName;	//关卡名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassPic;	//关卡图片

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTeachInfo> Teachs;	//教学文本/图片信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTeachTask> Task;	//任务描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;	//解锁等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PrePassId;	//解锁前置关卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//关卡奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapId;	//地图ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Exp;	//经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerNum;	//玩家人数

};
static void _ConvertPbToFTeachPassData(FTeachPassData &msg, const msg::TeachPassData *pb) {
	msg.Id=pb->id();
	msg.ChapterId=pb->chapterid();
	msg.PassName=UTF8_TO_TCHAR(pb->passname().c_str());
	msg.PassPic=UTF8_TO_TCHAR(pb->passpic().c_str());
	for (int i = 0; i < pb->teachs().size(); i++) {
		auto &a = pb->teachs().Get(i);
		FTeachInfo tmp;
		_ConvertPbToFTeachInfo(tmp, &a);
		msg.Teachs.Add(tmp);
	}
	for (int i = 0; i < pb->task().size(); i++) {
		auto &a = pb->task().Get(i);
		FTeachTask tmp;
		_ConvertPbToFTeachTask(tmp, &a);
		msg.Task.Add(tmp);
	}
	msg.Level=pb->level();
	msg.PrePassId=pb->prepassid();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.MapId=pb->mapid();
	msg.Exp=pb->exp();
	msg.PlayerNum=pb->playernum();
}


USTRUCT(BlueprintType)
struct  FTeachCapterData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

};
static void _ConvertPbToFTeachCapterData(FTeachCapterData &msg, const msg::TeachCapterData *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
}


USTRUCT(BlueprintType)
struct  FBigWinnerSeasonData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//赛季Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SeasonBeginDate;	//赛季开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SeasonEndDate;	//赛季结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BackConsume;	//返还消耗

};
static void _ConvertPbToFBigWinnerSeasonData(FBigWinnerSeasonData &msg, const msg::BigWinnerSeasonData *pb) {
	msg.Id=pb->id();
	msg.SeasonBeginDate=UTF8_TO_TCHAR(pb->seasonbegindate().c_str());
	msg.SeasonEndDate=UTF8_TO_TCHAR(pb->seasonenddate().c_str());
	msg.BackConsume=pb->backconsume();
}


USTRUCT(BlueprintType)
struct  FBigWinnerData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//场次id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	//场次名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//场次图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString IconBg;	//图标背景

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	//场次简介

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	//场次描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinScore;	//最低积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxScore;	//最高积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TicketScore;	//门票积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecommendScore;	//推荐积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LimitScore;	//限制积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExpandMatchTime;	//大玩家扩大匹配时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RefreshCost;	//刷新消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Open;	//是否开放

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MapId;	//内核模式Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SysPercent;	//系统抽成

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> RankRewardList;	//分配比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ConfigName;	//大赢家内核配置文件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WaitTime;	// 等待加入AI时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerCountCycleTime;	// 人数需求减少周期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerCountEnlargeValue;	// 人数需求减少单位值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinPlayerCount;	// 人数需求减少极限值

};
static void _ConvertPbToFBigWinnerData(FBigWinnerData &msg, const msg::BigWinnerData *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.IconBg=UTF8_TO_TCHAR(pb->iconbg().c_str());
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.MinScore=pb->minscore();
	msg.MaxScore=pb->maxscore();
	msg.TicketScore=pb->ticketscore();
	msg.RecommendScore=pb->recommendscore();
	msg.LimitScore=pb->limitscore();
	msg.ExpandMatchTime=pb->expandmatchtime();
	msg.RefreshCost=pb->refreshcost();
	msg.Open=pb->open();
	msg.MapId=pb->mapid();
	msg.SysPercent=pb->syspercent();
	for (int i = 0; i < pb->rankrewardlist().size(); i++) {
		auto &a = pb->rankrewardlist().Get(i);
		int tmp;
		tmp=a;
		msg.RankRewardList.Add(tmp);
	}
	msg.ConfigName=UTF8_TO_TCHAR(pb->configname().c_str());
	msg.WaitTime=pb->waittime();
	msg.PlayerCountCycleTime=pb->playercountcycletime();
	msg.PlayerCountEnlargeValue=pb->playercountenlargevalue();
	msg.MinPlayerCount=pb->minplayercount();
}


USTRUCT(BlueprintType)
struct  FMultiMailFile {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerID;	//玩家ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;	//邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SurviveTime;	//有效时间(天)(0:30天过期)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

};
static void _ConvertPbToFMultiMailFile(FMultiMailFile &msg, const msg::MultiMailFile *pb) {
	msg.PlayerID=UTF8_TO_TCHAR(pb->playerid().c_str());
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.SurviveTime=pb->survivetime();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMultiMailData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;	//邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	//邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SurviveTime;	//有效时间(秒)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	//奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRedis;	//是否是redis邮件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> PlayerID;	//玩家IDList

};
static void _ConvertPbToFMultiMailData(FMultiMailData &msg, const msg::MultiMailData *pb) {
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.SurviveTime=pb->survivetime();
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.IsRedis=pb->isredis();
	for (int i = 0; i < pb->playerid().size(); i++) {
		auto &a = pb->playerid().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.PlayerID.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPCPhoneUIContrast {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UIStylePhone;	// 跳转手游UI大界面

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UIStylePhoneID;	// 跳转手游UI大界面ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UIStylePhoneTABID;	// 跳转手游手游UI分页ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UIStylePC;	// 跳转PC UI类型

};
static void _ConvertPbToFPCPhoneUIContrast(FPCPhoneUIContrast &msg, const msg::PCPhoneUIContrast *pb) {
	msg.UIStylePhone=UTF8_TO_TCHAR(pb->uistylephone().c_str());
	msg.UIStylePhoneID=pb->uistylephoneid();
	msg.UIStylePhoneTABID=pb->uistylephonetabid();
	msg.UIStylePC=UTF8_TO_TCHAR(pb->uistylepc().c_str());
}


USTRUCT(BlueprintType)
struct  FChessStoryData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TextParagraphID;	// 文本段ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessID;	// 所属棋子ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextParagraphKey;	// 文本key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextIcon;	// 图片资源名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ISTitle;	// 是否为标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AlignmentType;	// 对齐方式

};
static void _ConvertPbToFChessStoryData(FChessStoryData &msg, const msg::ChessStoryData *pb) {
	msg.TextParagraphID=pb->textparagraphid();
	msg.ChessID=pb->chessid();
	msg.TextParagraphKey=UTF8_TO_TCHAR(pb->textparagraphkey().c_str());
	msg.TextIcon=UTF8_TO_TCHAR(pb->texticon().c_str());
	msg.ISTitle=pb->istitle();
	msg.AlignmentType=pb->alignmenttype();
}


USTRUCT(BlueprintType)
struct  FMedal {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMedalType MedalType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalSeriesId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalSetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalSetSort;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalMissionId;	// 成就任务

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOncecolumn;	// 是否占用一个勋章栏位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalRealNum;	// 真实编号数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalNumspace;	// 递增步长

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool MedalrepeatGet;	// 能否重复获得

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsMedalHide;	// 未获取是否隐藏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsMedalNum;	// 是否拥有勋章编号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MedalTextColor;	//勋章文本颜色

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IsMedalData;	// 勋章积分类型 1、大赢家勋章积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MedalSetType;	// 勋章套组排版类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMedalSubType MedalSubType;	//子类型

};
static void _ConvertPbToFMedal(FMedal &msg, const msg::Medal *pb) {
	msg.MedalId=pb->medalid();
	msg.MedalType=(EMedalType)pb->medaltype();
	msg.MedalSeriesId=pb->medalseriesid();
	msg.MedalSetId=pb->medalsetid();
	msg.MedalSetSort=pb->medalsetsort();
	msg.MedalMissionId=pb->medalmissionid();
	msg.IsOncecolumn=pb->isoncecolumn();
	msg.MedalRealNum=pb->medalrealnum();
	msg.MedalNumspace=pb->medalnumspace();
	msg.MedalrepeatGet=pb->medalrepeatget();
	msg.IsMedalHide=pb->ismedalhide();
	msg.IsMedalNum=pb->ismedalnum();
	msg.MedalTextColor=UTF8_TO_TCHAR(pb->medaltextcolor().c_str());
	msg.IsMedalData=pb->ismedaldata();
	msg.MedalSetType=pb->medalsettype();
	msg.MedalSubType=(EMedalSubType)pb->medalsubtype();
}


USTRUCT(BlueprintType)
struct  FPuzzleActivity {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//活动ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InitBoardRow;	//初始化拼盘行

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InitBoardColumn;	//初始化拼盘列

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OutPutPool;	//概率产出池Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;	//掉落池池Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanPutBack;	//是否可放回

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UltimateAwardID;	//大奖id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTextPool TextPool;	//台词池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAwardGroup> AwardGroup;	//奖励组

};
static void _ConvertPbToFPuzzleActivity(FPuzzleActivity &msg, const msg::PuzzleActivity *pb) {
	msg.GroupId=pb->groupid();
	msg.Id=pb->id();
	msg.InitBoardRow=pb->initboardrow();
	msg.InitBoardColumn=pb->initboardcolumn();
	msg.OutPutPool=pb->outputpool();
	msg.PoolId=pb->poolid();
	msg.CanPutBack=pb->canputback();
	msg.UltimateAwardID=pb->ultimateawardid();
	_ConvertPbToFTextPool(msg.TextPool, &pb->textpool());
	for (int i = 0; i < pb->awardgroup().size(); i++) {
		auto &a = pb->awardgroup().Get(i);
		FAwardGroup tmp;
		_ConvertPbToFAwardGroup(tmp, &a);
		msg.AwardGroup.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNormalOutPut {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModeList;	//模式列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExpectedProb;	//期望概率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Refresh;	//刷新周期 1、日 2、周 3、月

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPoolItem> Item;	//拼图道具

};
static void _ConvertPbToFNormalOutPut(FNormalOutPut &msg, const msg::NormalOutPut *pb) {
	msg.Id=pb->id();
	msg.ModeList=UTF8_TO_TCHAR(pb->modelist().c_str());
	msg.ExpectedProb=pb->expectedprob();
	msg.Refresh=pb->refresh();
	for (int i = 0; i < pb->item().size(); i++) {
		auto &a = pb->item().Get(i);
		FPoolItem tmp;
		_ConvertPbToFPoolItem(tmp, &a);
		msg.Item.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNormalText {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;	//池子Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LanguageId;	//文本id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	//权重

};
static void _ConvertPbToFNormalText(FNormalText &msg, const msg::NormalText *pb) {
	msg.Id=pb->id();
	msg.PoolId=pb->poolid();
	msg.LanguageId=UTF8_TO_TCHAR(pb->languageid().c_str());
	msg.Weight=pb->weight();
}


USTRUCT(BlueprintType)
struct  FNewPlayerModeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// 玩法ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ABTestValue;	// 对应ABTest值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ConfigName;	// 内核配置文件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerNum;	// 玩家人数

};
static void _ConvertPbToFNewPlayerModeData(FNewPlayerModeData &msg, const msg::NewPlayerModeData *pb) {
	msg.Id=pb->id();
	msg.ABTestValue=pb->abtestvalue();
	msg.ConfigName=UTF8_TO_TCHAR(pb->configname().c_str());
	msg.PlayerNum=pb->playernum();
}


USTRUCT(BlueprintType)
struct  FTeachModeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// 玩法ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;	// 玩法名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	// 玩法图标

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString IconBg;	// 图标背景

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;	// 玩法简介

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;	// 玩法描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ConfigName;	// 内核配置文件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RecommendId;	// 阵容ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info2;	// 玩法简介2

};
static void _ConvertPbToFTeachModeData(FTeachModeData &msg, const msg::TeachModeData *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.IconBg=UTF8_TO_TCHAR(pb->iconbg().c_str());
	msg.Info=UTF8_TO_TCHAR(pb->info().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.ConfigName=UTF8_TO_TCHAR(pb->configname().c_str());
	msg.RecommendId=UTF8_TO_TCHAR(pb->recommendid().c_str());
	msg.Info2=UTF8_TO_TCHAR(pb->info2().c_str());
}


USTRUCT(BlueprintType)
struct  FPveChallengeData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//活动ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FreeCount;	//免费有效次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PayCount;	//购买有效次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyType;	//购买货币

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Price;	//购买价格

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolId;	//抽奖奖池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SubModel;	//子模式id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MapKey;	//平台关联地图唯一key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CostCount;	//消耗挑战次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DailySocreLimit;	//每日积分上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardCount;	//奖励抽奖次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVE_RANK_SCORE_TYPE ScoreType;	//奖励排名类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAwardToken> AwardToken;	//奖励代币count

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalRankID;	//总排行榜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DailyRankID;	//每日排行榜奖励

};
static void _ConvertPbToFPveChallengeData(FPveChallengeData &msg, const msg::PveChallengeData *pb) {
	msg.GroupId=pb->groupid();
	msg.Id=pb->id();
	msg.FreeCount=pb->freecount();
	msg.PayCount=pb->paycount();
	msg.MoneyType=pb->moneytype();
	msg.Price=pb->price();
	msg.PoolId=pb->poolid();
	msg.SubModel=pb->submodel();
	msg.MapKey=UTF8_TO_TCHAR(pb->mapkey().c_str());
	msg.CostCount=pb->costcount();
	msg.DailySocreLimit=pb->dailysocrelimit();
	msg.AwardCount=pb->awardcount();
	msg.ScoreType=(EPVE_RANK_SCORE_TYPE)pb->scoretype();
	for (int i = 0; i < pb->awardtoken().size(); i++) {
		auto &a = pb->awardtoken().Get(i);
		FAwardToken tmp;
		_ConvertPbToFAwardToken(tmp, &a);
		msg.AwardToken.Add(tmp);
	}
	msg.TotalRankID=pb->totalrankid();
	msg.DailyRankID=pb->dailyrankid();
}


USTRUCT(BlueprintType)
struct  FPVERankData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//排行榜ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EmailTitle;	//标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EmailContent;	//内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PVERankPageLimit;	//pveRank每页限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PVERankNum;	//pveRank阈值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankFlash;	//pveRank刷新

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRankAward> RankAward;	//排位奖励

};
static void _ConvertPbToFPVERankData(FPVERankData &msg, const msg::PVERankData *pb) {
	msg.Id=pb->id();
	msg.EmailTitle=UTF8_TO_TCHAR(pb->emailtitle().c_str());
	msg.EmailContent=UTF8_TO_TCHAR(pb->emailcontent().c_str());
	msg.PVERankPageLimit=pb->pverankpagelimit();
	msg.PVERankNum=pb->pveranknum();
	msg.RankFlash=pb->rankflash();
	for (int i = 0; i < pb->rankaward().size(); i++) {
		auto &a = pb->rankaward().Get(i);
		FRankAward tmp;
		_ConvertPbToFRankAward(tmp, &a);
		msg.RankAward.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPVETalentData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//天赋ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActivityGroupId;	//关联活动组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeriesId;	//天赋系列

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankFlash;	//pveRank刷新

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Consume;	//排位奖励

};
static void _ConvertPbToFPVETalentData(FPVETalentData &msg, const msg::PVETalentData *pb) {
	msg.Id=pb->id();
	msg.ActivityGroupId=pb->activitygroupid();
	msg.SeriesId=pb->seriesid();
	msg.RankFlash=pb->rankflash();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Desc=UTF8_TO_TCHAR(pb->desc().c_str());
	msg.Value=UTF8_TO_TCHAR(pb->value().c_str());
	msg.Level=pb->level();
	msg.Consume=pb->consume();
}


USTRUCT(BlueprintType)
struct  FRandDiscoutDatum {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	// 奖励序列号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolID;	// 池Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rate;	// 概率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	// 权重

	int64 Duration;	// 持续时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Times;	// 可用次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemID;	// 可以折扣的物品id

};
static void _ConvertPbToFRandDiscoutDatum(FRandDiscoutDatum &msg, const msg::RandDiscoutDatum *pb) {
	msg.ID=pb->id();
	msg.PoolID=pb->poolid();
	msg.Rate=pb->rate();
	msg.Weight=pb->weight();
	msg.Duration=pb->duration();
	msg.Times=pb->times();
	msg.ItemID=pb->itemid();
}


USTRUCT(BlueprintType)
struct  FReturnGuid {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERETURN_GUID_TAG Tag;	// tag枚举

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Content;	// 内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;	// 标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkipTab;	// 跳转手游id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString IconName;	// 图片名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IconSite;	// 图片位置 1居左 2居右

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VersionUpdateTime;	// 任务开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SkipInterface;	// 跳转大界面得名称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ContentDeviation;	//内容文本偏移量

};
static void _ConvertPbToFReturnGuid(FReturnGuid &msg, const msg::ReturnGuid *pb) {
	msg.Id=pb->id();
	msg.Tag=(ERETURN_GUID_TAG)pb->tag();
	msg.Content=UTF8_TO_TCHAR(pb->content().c_str());
	msg.Title=UTF8_TO_TCHAR(pb->title().c_str());
	msg.SkipTab=pb->skiptab();
	msg.IconName=UTF8_TO_TCHAR(pb->iconname().c_str());
	msg.IconSite=pb->iconsite();
	msg.VersionUpdateTime=UTF8_TO_TCHAR(pb->versionupdatetime().c_str());
	msg.SkipInterface=UTF8_TO_TCHAR(pb->skipinterface().c_str());
	msg.ContentDeviation=pb->contentdeviation();
}


USTRUCT(BlueprintType)
struct  FItemComment {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemType;	// 物品分类

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CommentRank;	// 引导评论最低品质

};
static void _ConvertPbToFItemComment(FItemComment &msg, const msg::ItemComment *pb) {
	msg.ID=pb->id();
	msg.ItemType=pb->itemtype();
	msg.CommentRank=pb->commentrank();
}


USTRUCT(BlueprintType)
struct  FSmeltAwardData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StartTime;	//开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EndTime;	//结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Condition;	//条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardPool;	//奖励池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSmeltExcludeItem> Exclude;	//排除类型

};
static void _ConvertPbToFSmeltAwardData(FSmeltAwardData &msg, const msg::SmeltAwardData *pb) {
	msg.Id=pb->id();
	msg.StartTime=UTF8_TO_TCHAR(pb->starttime().c_str());
	msg.EndTime=UTF8_TO_TCHAR(pb->endtime().c_str());
	msg.Condition=pb->condition();
	msg.AwardPool=pb->awardpool();
	for (int i = 0; i < pb->exclude().size(); i++) {
		auto &a = pb->exclude().Get(i);
		FSmeltExcludeItem tmp;
		_ConvertPbToFSmeltExcludeItem(tmp, &a);
		msg.Exclude.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessSkinRelationData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//皮肤ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessId;	//所属棋子ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowBeginTime;	//显示开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowEndTime;	//显示结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkinOrder;	//排序

};
static void _ConvertPbToFChessSkinRelationData(FChessSkinRelationData &msg, const msg::ChessSkinRelationData *pb) {
	msg.Id=pb->id();
	msg.ChessId=pb->chessid();
	msg.ShowBeginTime=UTF8_TO_TCHAR(pb->showbegintime().c_str());
	msg.ShowEndTime=UTF8_TO_TCHAR(pb->showendtime().c_str());
	msg.SkinOrder=pb->skinorder();
}


USTRUCT(BlueprintType)
struct  FRandPickUpPoolData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PoolID;	// 池id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Val;	// 值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int weight;	// 权重

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERANDPICKUPPOOLTYPE Type;	// 池类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString extra;	// 扩展信息

};
static void _ConvertPbToFRandPickUpPoolData(FRandPickUpPoolData &msg, const msg::RandPickUpPoolData *pb) {
	msg.Id=pb->id();
	msg.PoolID=pb->poolid();
	for (int i = 0; i < pb->val().size(); i++) {
		auto &a = pb->val().Get(i);
		int tmp;
		tmp=a;
		msg.Val.Add(tmp);
	}
	msg.weight=pb->weight();
	msg.Type=(ERANDPICKUPPOOLTYPE)pb->type();
	msg.extra=UTF8_TO_TCHAR(pb->extra().c_str());
}


USTRUCT(BlueprintType)
struct  FItemAffixData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMAFFIXTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMAFFIXCONDTYPE CondType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AffixDesc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NodeNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMAFFIXTRIGGERTYPE TriggerType;

};
static void _ConvertPbToFItemAffixData(FItemAffixData &msg, const msg::ItemAffixData *pb) {
	msg.Id=pb->id();
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
	msg.Type=(EITEMAFFIXTYPE)pb->type();
	msg.CondType=(EITEMAFFIXCONDTYPE)pb->condtype();
	msg.AffixDesc=UTF8_TO_TCHAR(pb->affixdesc().c_str());
	msg.ItemID=pb->itemid();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.NodeNumber=UTF8_TO_TCHAR(pb->nodenumber().c_str());
	msg.Mode=UTF8_TO_TCHAR(pb->mode().c_str());
	for (int i = 0; i < pb->effect().size(); i++) {
		auto &a = pb->effect().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Effect.Add(tmp);
	}
	msg.TriggerType=(EITEMAFFIXTRIGGERTYPE)pb->triggertype();
}


USTRUCT(BlueprintType)
struct  FIdentifyItemTypeAttrPair {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Attrs;

};
static void _ConvertPbToFIdentifyItemTypeAttrPair(FIdentifyItemTypeAttrPair &msg, const msg::IdentifyItemTypeAttrPair *pb) {
	msg.Type=(EITEMTYPE)pb->type();
	msg.Attrs=UTF8_TO_TCHAR(pb->attrs().c_str());
}


USTRUCT(BlueprintType)
struct  FItemIdentifyQuality {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Val;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

};
static void _ConvertPbToFItemIdentifyQuality(FItemIdentifyQuality &msg, const msg::ItemIdentifyQuality *pb) {
	for (int i = 0; i < pb->val().size(); i++) {
		auto &a = pb->val().Get(i);
		int tmp;
		tmp=a;
		msg.Val.Add(tmp);
	}
	msg.Name=UTF8_TO_TCHAR(pb->name().c_str());
}


USTRUCT(BlueprintType)
struct  FItemIdentifyRandPoolRelationData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMTYPE ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IdentifyProp;	// 消耗道具id, 可以是消耗品物品id，或者给消耗方式定义的编号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AffixCntPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AffixPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> QualityPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AffixExclusivePool;	// 专属词缀池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IdentifyPropCnt;	// 消耗道具id数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESOURCE Source;	// 鉴定方式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SmeltLevel;	// 汰换等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanIdentify;	// 是否能鉴定

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TexturePool;	// 贴图池

};
static void _ConvertPbToFItemIdentifyRandPoolRelationData(FItemIdentifyRandPoolRelationData &msg, const msg::ItemIdentifyRandPoolRelationData *pb) {
	msg.ID=pb->id();
	msg.ItemID=pb->itemid();
	msg.ItemType=(EITEMTYPE)pb->itemtype();
	msg.IdentifyProp=pb->identifyprop();
	msg.AffixCntPool=pb->affixcntpool();
	msg.AffixPool=UTF8_TO_TCHAR(pb->affixpool().c_str());
	for (int i = 0; i < pb->qualitypool().size(); i++) {
		auto &a = pb->qualitypool().Get(i);
		int tmp;
		tmp=a;
		msg.QualityPool.Add(tmp);
	}
	msg.AffixExclusivePool=pb->affixexclusivepool();
	msg.IdentifyPropCnt=pb->identifypropcnt();
	msg.Source=(ESOURCE)pb->source();
	msg.SmeltLevel=pb->smeltlevel();
	msg.CanIdentify=pb->canidentify();
	msg.TexturePool=pb->texturepool();
}


USTRUCT(BlueprintType)
struct  FItemPublishNumberData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Prefix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InitialDigit;	// 数字位数

};
static void _ConvertPbToFItemPublishNumberData(FItemPublishNumberData &msg, const msg::ItemPublishNumberData *pb) {
	msg.Id=pb->id();
	msg.ItemId=pb->itemid();
	msg.Prefix=UTF8_TO_TCHAR(pb->prefix().c_str());
	msg.InitialDigit=pb->initialdigit();
}


USTRUCT(BlueprintType)
struct  FNoviceAnswerData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Question;	//问题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Options;	// 选项

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CorrectOption;	// 答案

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weight;	// 权重

};
static void _ConvertPbToFNoviceAnswerData(FNoviceAnswerData &msg, const msg::NoviceAnswerData *pb) {
	msg.ID=pb->id();
	msg.Question=UTF8_TO_TCHAR(pb->question().c_str());
	for (int i = 0; i < pb->options().size(); i++) {
		auto &a = pb->options().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Options.Add(tmp);
	}
	msg.CorrectOption=pb->correctoption();
	msg.Weight=pb->weight();
}


USTRUCT(BlueprintType)
struct  FChessDestinyData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> A;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> B;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDestinyAction> Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Effects;

};
static void _ConvertPbToFChessDestinyData(FChessDestinyData &msg, const msg::ChessDestinyData *pb) {
	msg.ID=pb->id();
	for (int i = 0; i < pb->a().size(); i++) {
		auto &a = pb->a().Get(i);
		int tmp;
		tmp=a;
		msg.A.Add(tmp);
	}
	for (int i = 0; i < pb->b().size(); i++) {
		auto &a = pb->b().Get(i);
		int tmp;
		tmp=a;
		msg.B.Add(tmp);
	}
	for (int i = 0; i < pb->action().size(); i++) {
		auto &a = pb->action().Get(i);
		FDestinyAction tmp;
		_ConvertPbToFDestinyAction(tmp, &a);
		msg.Action.Add(tmp);
	}
	msg.Effects=UTF8_TO_TCHAR(pb->effects().c_str());
}


USTRUCT(BlueprintType)
struct  FDynamicResourceData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//对应物品表id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Resources;	// 上层资源名

};
static void _ConvertPbToFDynamicResourceData(FDynamicResourceData &msg, const msg::DynamicResourceData *pb) {
	msg.ID=pb->id();
	msg.Resources=UTF8_TO_TCHAR(pb->resources().c_str());
}


USTRUCT(BlueprintType)
struct  FDynamicHeadData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//对应物品表id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Resources;	// 资源名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Frames;	//手游播放帧数

};
static void _ConvertPbToFDynamicHeadData(FDynamicHeadData &msg, const msg::DynamicHeadData *pb) {
	msg.ID=pb->id();
	msg.Resources=UTF8_TO_TCHAR(pb->resources().c_str());
	msg.Frames=pb->frames();
}


USTRUCT(BlueprintType)
struct  FAuctionData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemID;	// (tag.json)="code,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SellPrice;	// (tag.json)="sellPrice,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BuyPrice;	// (tag.json)="buyPrice,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SellMoney;	// (tag.json)="priceOfCash,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BuyMoney;	// (tag.json)="inquiryPriceOfCash,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InquiryCount;	// (tag.json)="inquiryCount,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyRequiredCount;	// (tag.json)="inquiryCountOfCash,omitempty"

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RequiredCount;	// (tag.json)="requiredCount,omitempty"

};
static void _ConvertPbToFAuctionData(FAuctionData &msg, const msg::AuctionData *pb) {
	msg.ItemID=pb->itemid();
	msg.SellPrice=pb->sellprice();
	msg.BuyPrice=pb->buyprice();
	msg.SellMoney=pb->sellmoney();
	msg.BuyMoney=pb->buymoney();
	msg.InquiryCount=pb->inquirycount();
	msg.MoneyRequiredCount=pb->moneyrequiredcount();
	msg.RequiredCount=pb->requiredcount();
}


USTRUCT(BlueprintType)
struct  FPveData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MapKey;	//地图key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessLimit;	//棋子上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkillLimit;	//技能上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankPageLimit;	//单页显示上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankNum;	//总上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankFlash;	//刷新间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkillPassMinLimit;	//被动技能最少装配

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkillInitiativeMinLimit;	//主动技能最少装配

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IsQuickEntry;	//是否为快捷入口

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActiveId;	//附属活动id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DayActivityLimit;	//附属活动每日积分限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxScore;	//玩家最多积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ClassicMode;	//子地图经典模式key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NightmareMode;	//子地图噩梦模式key

};
static void _ConvertPbToFPveData(FPveData &msg, const msg::PveData *pb) {
	msg.ID=pb->id();
	msg.MapKey=UTF8_TO_TCHAR(pb->mapkey().c_str());
	msg.ChessLimit=pb->chesslimit();
	msg.SkillLimit=pb->skilllimit();
	msg.RankPageLimit=pb->rankpagelimit();
	msg.RankNum=pb->ranknum();
	msg.RankFlash=pb->rankflash();
	msg.SkillPassMinLimit=pb->skillpassminlimit();
	msg.SkillInitiativeMinLimit=pb->skillinitiativeminlimit();
	msg.IsQuickEntry=pb->isquickentry();
	msg.ActiveId=pb->activeid();
	msg.DayActivityLimit=pb->dayactivitylimit();
	msg.MaxScore=pb->maxscore();
	msg.ClassicMode=UTF8_TO_TCHAR(pb->classicmode().c_str());
	msg.NightmareMode=UTF8_TO_TCHAR(pb->nightmaremode().c_str());
}


USTRUCT(BlueprintType)
struct  FPveChessData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessId;	//棋子id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPveConsume> Consumes;	//消耗列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInit;	//是否初始化

};
static void _ConvertPbToFPveChessData(FPveChessData &msg, const msg::PveChessData *pb) {
	msg.PveId=pb->pveid();
	msg.ChessId=pb->chessid();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FPveConsume tmp;
		_ConvertPbToFPveConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.IsInit=pb->isinit();
}


USTRUCT(BlueprintType)
struct  FPveSkillData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SkillId;	//技能id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPveConsume> Consumes;	//消耗列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInit;	//是否初始化

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVESKILLTYPE SkillType;	//技能类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SpecialSkill;	//是否为特俗技能描述

};
static void _ConvertPbToFPveSkillData(FPveSkillData &msg, const msg::PveSkillData *pb) {
	msg.PveId=pb->pveid();
	msg.SkillId=pb->skillid();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FPveConsume tmp;
		_ConvertPbToFPveConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.IsInit=pb->isinit();
	msg.SkillType=(EPVESKILLTYPE)pb->skilltype();
	msg.SpecialSkill=pb->specialskill();
}


USTRUCT(BlueprintType)
struct  FPveBuffData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPVE_BUFF_TYPE BuffType;	//buff 类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeriesId;	//传给内核对应的id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPveConsume> Consumes;	//消耗列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TitleKey;	//多语言title key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContentKey;	//多语言content key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PropAwards;	//道具buff 奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PropLimit;	//道具buff 上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VipSurviveTime;	//vip buff 激活持续时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VipActivateIds;	//vip 激活buff

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int IntegralBonus;	//debuff 激活加成

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	//icon

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContentKeyValue;	//多语言key 中的 替换内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuffLock;	//debuf 同一种只能有一个

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SeriesLevel;	//buff等级

};
static void _ConvertPbToFPveBuffData(FPveBuffData &msg, const msg::PveBuffData *pb) {
	msg.ID=pb->id();
	msg.PveId=pb->pveid();
	msg.BuffType=(EPVE_BUFF_TYPE)pb->bufftype();
	msg.SeriesId=pb->seriesid();
	for (int i = 0; i < pb->consumes().size(); i++) {
		auto &a = pb->consumes().Get(i);
		FPveConsume tmp;
		_ConvertPbToFPveConsume(tmp, &a);
		msg.Consumes.Add(tmp);
	}
	msg.TitleKey=UTF8_TO_TCHAR(pb->titlekey().c_str());
	msg.ContentKey=UTF8_TO_TCHAR(pb->contentkey().c_str());
	for (int i = 0; i < pb->propawards().size(); i++) {
		auto &a = pb->propawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PropAwards.Add(tmp);
	}
	msg.PropLimit=pb->proplimit();
	msg.VipSurviveTime=pb->vipsurvivetime();
	msg.VipActivateIds=UTF8_TO_TCHAR(pb->vipactivateids().c_str());
	msg.IntegralBonus=pb->integralbonus();
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.ContentKeyValue=UTF8_TO_TCHAR(pb->contentkeyvalue().c_str());
	msg.BuffLock=pb->bufflock();
	msg.SeriesLevel=pb->serieslevel();
}


USTRUCT(BlueprintType)
struct  FPvpTaskData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MissionId;	//任务id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MissionType;	//任务类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionTitleKey;	//任务标题key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionDesKey;	//任务条件key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionRewardKey;	//任务奖励key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionRequirement;	//多语言title key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MissionReward;	//多语言content key

};
static void _ConvertPbToFPvpTaskData(FPvpTaskData &msg, const msg::PvpTaskData *pb) {
	msg.Id=pb->id();
	msg.MissionId=pb->missionid();
	msg.MissionType=pb->missiontype();
	msg.MissionTitleKey=UTF8_TO_TCHAR(pb->missiontitlekey().c_str());
	msg.MissionDesKey=UTF8_TO_TCHAR(pb->missiondeskey().c_str());
	msg.MissionRewardKey=UTF8_TO_TCHAR(pb->missionrewardkey().c_str());
	msg.MissionRequirement=UTF8_TO_TCHAR(pb->missionrequirement().c_str());
	msg.MissionReward=UTF8_TO_TCHAR(pb->missionreward().c_str());
}


USTRUCT(BlueprintType)
struct  FChessSetSlotData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TypeId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Mode;	//对应的模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessQuality> Quality;	//棋子槽位数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString JsonName;	//对应内核的json名字

};
static void _ConvertPbToFChessSetSlotData(FChessSetSlotData &msg, const msg::ChessSetSlotData *pb) {
	msg.TypeId=pb->typeid_();
	msg.Mode=UTF8_TO_TCHAR(pb->mode().c_str());
	for (int i = 0; i < pb->quality().size(); i++) {
		auto &a = pb->quality().Get(i);
		FChessQuality tmp;
		_ConvertPbToFChessQuality(tmp, &a);
		msg.Quality.Add(tmp);
	}
	msg.JsonName=UTF8_TO_TCHAR(pb->jsonname().c_str());
}


USTRUCT(BlueprintType)
struct  FChessInitDeckData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TypeId;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TitleKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitChessIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SuitAllChessId;	//初始化99 的卡槽

};
static void _ConvertPbToFChessInitDeckData(FChessInitDeckData &msg, const msg::ChessInitDeckData *pb) {
	msg.ID=pb->id();
	msg.TypeId=pb->typeid_();
	msg.TitleKey=UTF8_TO_TCHAR(pb->titlekey().c_str());
	msg.InitChessIds=UTF8_TO_TCHAR(pb->initchessids().c_str());
	msg.SuitAllChessId=UTF8_TO_TCHAR(pb->suitallchessid().c_str());
}


USTRUCT(BlueprintType)
struct  FChessFetterLimitData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//羁绊

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LimitNum;	//棋子羁绊限制数量

};
static void _ConvertPbToFChessFetterLimitData(FChessFetterLimitData &msg, const msg::ChessFetterLimitData *pb) {
	msg.ID=pb->id();
	msg.LimitNum=pb->limitnum();
}


USTRUCT(BlueprintType)
struct  FMentorPunish {
	GENERATED_BODY()

	int64 Time;	//惩罚时间 s

	int64 Cond;	//被解除的玩家 活跃天数 是否达到这个值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORSHIP Type;	//惩罚的类型

};
static void _ConvertPbToFMentorPunish(FMentorPunish &msg, const msg::MentorPunish *pb) {
	msg.Time=pb->time();
	msg.Cond=pb->cond();
	msg.Type=(EMENTORSHIP)pb->type();
}


USTRUCT(BlueprintType)
struct  FMentorLevel {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORLEVEL Id;	//等级id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;	//多语言key

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;	// 徒弟数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NextLevelCond;	//下一等级的数量

};
static void _ConvertPbToFMentorLevel(FMentorLevel &msg, const msg::MentorLevel *pb) {
	msg.Id=(EMENTORLEVEL)pb->id();
	msg.Key=UTF8_TO_TCHAR(pb->key().c_str());
	msg.Count=pb->count();
	msg.NextLevelCond=pb->nextlevelcond();
}


USTRUCT(BlueprintType)
struct  FMentorShipTag {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//等级id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;	//多语言key

};
static void _ConvertPbToFMentorShipTag(FMentorShipTag &msg, const msg::MentorShipTag *pb) {
	msg.Id=pb->id();
	msg.Key=UTF8_TO_TCHAR(pb->key().c_str());
}


USTRUCT(BlueprintType)
struct  FMentorShipTaskData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	// 任务i

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCond Cond;	// 任务条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> Awards;	// 奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;	// 奖励的icon

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORSHIPTASK Type;	// 任务所属类型

};
static void _ConvertPbToFMentorShipTaskData(FMentorShipTaskData &msg, const msg::MentorShipTaskData *pb) {
	msg.Id=pb->id();
	_ConvertPbToFCond(msg.Cond, &pb->cond());
	for (int i = 0; i < pb->awards().size(); i++) {
		auto &a = pb->awards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.Awards.Add(tmp);
	}
	msg.Icon=UTF8_TO_TCHAR(pb->icon().c_str());
	msg.Type=(EMENTORSHIPTASK)pb->type();
}


USTRUCT(BlueprintType)
struct  FMentorAddn {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORADDN Type;	//加成类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Coe;	//加成系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMENTORSHIP TargetType;	//加成对象

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Mode;	//模式列表

};
static void _ConvertPbToFMentorAddn(FMentorAddn &msg, const msg::MentorAddn *pb) {
	msg.Type=(EMENTORADDN)pb->type();
	msg.Coe=pb->coe();
	msg.TargetType=(EMENTORSHIP)pb->targettype();
	msg.Mode=UTF8_TO_TCHAR(pb->mode().c_str());
}


USTRUCT(BlueprintType)
struct  FRuleData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TypeId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Picture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Rule;

};
static void _ConvertPbToFRuleData(FRuleData &msg, const msg::RuleData *pb) {
	msg.Id=pb->id();
	msg.TypeId=pb->typeid_();
	msg.Picture=UTF8_TO_TCHAR(pb->picture().c_str());
	msg.Rule=UTF8_TO_TCHAR(pb->rule().c_str());
}


USTRUCT(BlueprintType)
struct  FLyActivityLimit {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;	//活动ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GroupId;	//活动组ID

	int64 RefreshPlayer;	//玩家上限重置时间，单位是分钟，开始时间为活动开启时间

	int64 RefreshTotal;	//全服上限重置时间，单位是分钟，开始时间为活动开启时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PvpMode;	//可掉落模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Probability;	//对应掉落模式概率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLyAwardPool> Pool;	//掉落池

};
static void _ConvertPbToFLyActivityLimit(FLyActivityLimit &msg, const msg::LyActivityLimit *pb) {
	msg.Id=pb->id();
	msg.GroupId=pb->groupid();
	msg.RefreshPlayer=pb->refreshplayer();
	msg.RefreshTotal=pb->refreshtotal();
	msg.PvpMode=UTF8_TO_TCHAR(pb->pvpmode().c_str());
	msg.Probability=UTF8_TO_TCHAR(pb->probability().c_str());
	for (int i = 0; i < pb->pool().size(); i++) {
		auto &a = pb->pool().Get(i);
		FLyAwardPool tmp;
		_ConvertPbToFLyAwardPool(tmp, &a);
		msg.Pool.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FWebUrlData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CN;	//国内网址

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Overseas;	//海外网址

};
static void _ConvertPbToFWebUrlData(FWebUrlData &msg, const msg::WebUrlData *pb) {
	msg.ID=pb->id();
	msg.CN=UTF8_TO_TCHAR(pb->cn().c_str());
	msg.Overseas=UTF8_TO_TCHAR(pb->overseas().c_str());
}


USTRUCT(BlueprintType)
struct  FBoardExclusiveSoundData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;	//对应棋盘ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OutsideName;	//局外BGM名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OutsideResources;	//资源名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InsideName;	//局内BGM名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InsideResources;	//资源名

};
static void _ConvertPbToFBoardExclusiveSoundData(FBoardExclusiveSoundData &msg, const msg::BoardExclusiveSoundData *pb) {
	msg.ID=pb->id();
	msg.OutsideName=UTF8_TO_TCHAR(pb->outsidename().c_str());
	msg.OutsideResources=UTF8_TO_TCHAR(pb->outsideresources().c_str());
	msg.InsideName=UTF8_TO_TCHAR(pb->insidename().c_str());
	msg.InsideResources=UTF8_TO_TCHAR(pb->insideresources().c_str());
}


USTRUCT(BlueprintType)
struct  FCommonInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpMatchMaxPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EscapeMatchMaxPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChatMsgMaxLen;	// 聊天最大长度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UserNameMaxLen;	// 玩家名字最大长度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DefaultHeadPics;	// 默认头像列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMQUALITY EggMinimumQuality;	// 保底品质

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FollowMaxNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoRemoveInviteInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InviteListMaxCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NotReceiveInviteInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamMaxCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GetBatchFansCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleStarPriceId;	// 战星价格

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleStarPriceCount;	// 战星价格

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LevelMax;	// 最大等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoundExpUpperLimit;	// 每局最大经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoundExpLowerLimit;	// 每局最小经验

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeekExpLimit;	// 每周经验限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SpecialGiftRefreshTime;	// 特价礼包刷新时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SpecialGiftRefreshInterval;	// 特价礼包刷新间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TimedExchangeRefreshTime;	// 限时兑换刷新时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TimedExchangeRefreshInterval;	// 限时兑换刷新间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleStarWeekBaseLimit;	// 周基础战星上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BattleStarWeekReviseLimit;	// 周战星上限增幅值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QQVipLevelExpBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QQSvipLevelExpBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int QQGameCenterLevelExpBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatGameCenterLevelExpBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BlacklistMaxNum;	// 黑名单最大人数

	int64 VerificationCodeExpiredTime;	// 验证码过期时间

	int64 BindPhoneNumberCoolingTime;	// 手机绑定冷却时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InviteMsgMaxLen;	// 黑名单最大人数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VerificationCodeDailyLimit;	// 验证码每日发送限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> BindPhoneNumberAwards;	// 首次绑定手机号奖励

	int64 SendCodeCoolingTime;	// 验证码发送冷却时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardUserInfoId;	// 个人信息分享奖励id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardUserInfoCount;	// 个人信息分享奖励数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardFriendRankId;	// 好友排行榜分享奖励id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardFriendRankCount;	// 好友排行榜分享奖励数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardPVPCountId;	// 对局数分享奖励id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardPVPCountCount;	// 对局数分享奖励数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardChessId;	// 棋子图鉴分享奖励id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardChessCount;	// 棋子图鉴分享奖励数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardCalendarId;	// 黄历分享奖励id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShareRewardCalendarCount;	// 黄历分享奖励数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> FirstChargeActivateChargeType;	// 首充活动充值类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FirstChargeActivateDonutsNum;	// 首充活动充值门限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FollowDailyLimit;	// 每日关注的最大人数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecallCooldownTime;	// 召回发送的CD

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecallTime;	// 离线多久可以召回

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerGiftsId;	// 大玩家首礼包码id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WeChatBigPlayerMailId;	// 大玩家首礼包邮件id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WeChatBigPlayerMailCtt;	// 大玩家首礼包邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerGachaColor;	// 大玩家扭蛋抽取道具品质

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerLikesDaily;	// 每日玩家可对大玩家点赞榜点赞赞次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerRedPacketClaim;	// 每日玩家可领取红包次数上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerRedPacketRank;	// 红包内领取排行榜展示人数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerLikesRank;	// 大玩家点赞榜展示人数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerRedPacketDailyReward;	// 每日玩家红包活动可领取礼包id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerLikesReward;	// 大玩家红包活动玩家点赞点赞表奖励礼包id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> WeChatBigPlayerRedLimits;	// 大玩家红包发送限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WeChatBigPlayerNormalRedStores;	// 普通玩家囤积红包数量上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> InviteRegisterAwards;	// 关系链邀请注册奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BlackTeamSwitchQQ;	// QQ开黑组队开关（0-关，1-开）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BlackTeamSwitchWeChat;	// 微信开黑组队开关（0-关，1-开）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeadIconIDIPResetTime;	// 头像IDIP重置时间 不允许拉取平台头像天数（天）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PresetFastChatLimit;	// 快捷聊天文本预设数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpConfirmMaxTime;	// 玩家确认阶段最大时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityPageShowTypeList;	// 活动派别切页

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FreeChangeCountryNumber;	// 免费修改国家的次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AvatarAllowToRemoveAll;	// 允许全部脱下的装扮类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NoAdvertiseLevel;	// Loading页无视广告的等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> RecallRewards;	// 好友召回奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FreeChangeProvinceTimes;	// 可以立即免费修改省份的次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> TeamPvpAward;	// 每日首次组队开黑奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddictionCountdown1;	// 沉迷倒计时1

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AddictionCountdown2;	// 沉迷倒计时2

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MatchAddictionCountdown;	// 匹配沉迷倒计时

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool KRAddictionPCOpen;	// 韩国防沉迷PC开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool KRAddictionPhoneOpen;	// 韩国防沉迷手游开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> FriendInviteReaward;	// 同玩好友每日首次邀请奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> RankUpShareReward;	// 段位升级每日首次分享奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> WinShareReward;	// top3 吃鸡分享奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PassLevelShareReaward;	// 通行证等级分享奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PassCommonQuestShareReaward;	// 通行证任务分享通用奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PassSpecialQuestShareReaward;	// 通行证任务分享特殊奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RefreshProvinceTime;	// 可以免费修改省份的时间间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassBuyingTips;	// 通行证倒计时提示开始天数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassAwardPreviewNum;	// 通行证领取奖励预览等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemSortGrogram1;	// 物品类型排序方案1

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MessageTimeDisplays;	// 历史消息时间显示间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PopupPlayerLeverLimit;	// 拍脸图玩家等级限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PopupPlayerRegisterTimeLimit;	// 拍脸图玩家注册时间限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PopupPlayerReturnTimeLimit;	// 拍脸图玩家回流时间限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PopupGlobalLimit;	// 拍脸图最大展示数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GlobalMatchAskCoolDown;	// 全球匹配弹窗间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GlobalMatchAskWhenReduce;	// 全球匹配弹窗开始减少的次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GlobalMatchAskReducedTime;	// 全球匹配弹窗间隔每次减少的值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GlobalMatchAskMinCoolDown;	// 全球匹配弹窗间隔最小值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewPlayerGuideLeaveTime;	// 新手引导跳过等待时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecommendedPlanOfLineup;	// 一键站位推荐方案数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ticketconversion1000;	// 糖果门票折算比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ticketconversion1001;	// 甜甜圈门票折算比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ReportIntervalTime;	// 举报间隔时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BattleWinningStreakBroadcast;	// 局内连胜播报判定次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BattleChessEvenKill;	// 局内棋子连杀播报

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WorkShopCollectionMaximum;	// 创意工坊收藏栏上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BountyType;	// 赏金房间投注货币类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerMoneyModSwitch;	// 自定义赏金总开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PreparationConditionsCandy;	// 创意工坊进入房间默认准备条件-小于配置数量糖果门票

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PreparationConditionsPayCandy;	// 创意工坊进入房间默认准备条件-小于配置数量甜甜圈门票

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PicBookEquipRecommend;	// 图鉴角色装备推荐个数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamEquipRecommend;	// 阵容详情装备推荐个数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChessEquipRecommend;	// 棋子详情装备推荐个数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EquipRecommendQuantity;	// 局内装备推荐对应棋子个数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExchangeChipScale1136;	// 棋子皮肤通用碎片兑换棋子皮肤退环境碎片蓝比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExchangeChipScale1137;	// 棋子皮肤通用碎片兑换棋子皮肤退环境碎片紫比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExchangeChipScale1138;	// 棋子皮肤通用碎片兑换棋子皮肤退环境碎片橙比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExchangeChipScale1139;	// 棋子皮肤通用碎片兑换棋子皮肤退环境碎片红比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RankCardRange;	// 段位保护卡可用等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TutorialReadingCoolingTime;	// 多多训练营教学卡阅读冷却

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ReportChatNum;	// 举报上传的聊天对话数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DelayMatchTimeLimit;	// 延迟匹配时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ReturnSignInPicLanguage;	// 签到识别是否显示凶吉图片的对应语言

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewEquipRecommendQuantity;	// 局内装备推荐对应棋子个数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ReturnSignInLocalPic;	// 签到显示本地化图片

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DelayInfoCount;	// 客户端上报延迟信息数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DelayPeekNum;	// 延迟筛选参考极值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CandidateLimit;	// 侯选阵容数量限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SmeltCondition;	// 熔炼启动值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SmeltPoolId;	// 熔炼奖池

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MailEndTimeNotify;	// 邮件过期提醒倒计时(天)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemUpLimitTitle;	// 物品上限邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemUpLimitContent;	// 物品上限邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChessModelScale;	// 物品上限邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DefaultHeadChess;	// 默认的头像和棋手

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NoviceAnswerNum;	// 新手答题数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NoviceAnswerPassNum;	// 新手答题通过所需正确数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DelayEjectTime;	// 比赛结束后结算界面延迟弹出时间(s)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WatchTime;	// 掉落交易宝箱观战时长

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MatchPlayerDropProbability;	// 官方自定义比赛参赛玩家掉落交易宝箱概率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WatchPlayerDropProbability;	// 官方自定义比赛观战玩家掉落交易宝箱概率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ExchangeCoverItemId;	// 交易服允许兑换的物品id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CanUpgradePassportItemType;	//支持升级通行证得道具类型

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceLengthLimit;	//语音消息长度限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CardGroupKernelJson;	// 卡组用的内核json文件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CardGroupAutoAddTimes;	// 卡组自动注入的回合

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AcutionNameMaxLen;	// 拍卖行名字最大长度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AcutionRemarkMaxLen;	// 拍卖行留言最大长度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WalletServiceCharge;	// 零钱包服务费（万分比*10000）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WalletServiceChargeMinNum;	// 零钱包服务费下限（固定值、整数）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BalanceCountCond;	// 成交量达成条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SaleCountCond;	// 上架达成条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerShopShareCD;	// 店铺分享CD

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InsuranceCardDayLimit;	//保险卡日使用次数限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InsuranceCardTipsTime;	//保险卡提示时间间隔(小时)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InsuranceCardStartLevel;	//使用段位起始值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InsuranceCardEndLevel;	//使用段位终止值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString QueenMmrStar;	//皇后段位&勋章的mmr分值及对应星级

	int64 BagMailInterval;	//发送邮件间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool TradeShowRMB;	//是否显示人民币价格

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InsuranceCardSeasonTip;	//保险卡赛季提示开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> InsuranceCardAutoConsume;	//保险卡自动购买消耗货币

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTradeShow;	//交易市场是否可见

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TradeAllMaxNum;	//交易市场全选上限数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShowBatchSell;	//批量出售按钮是否可见

};
static void _ConvertPbToFCommonInfo(FCommonInfo &msg, const msg::CommonInfo *pb) {
	msg.PvpMatchMaxPlayers=pb->pvpmatchmaxplayers();
	msg.EscapeMatchMaxPlayers=pb->escapematchmaxplayers();
	msg.ChatMsgMaxLen=pb->chatmsgmaxlen();
	msg.UserNameMaxLen=pb->usernamemaxlen();
	msg.DefaultHeadPics=UTF8_TO_TCHAR(pb->defaultheadpics().c_str());
	msg.EggMinimumQuality=(EITEMQUALITY)pb->eggminimumquality();
	msg.FollowMaxNum=pb->followmaxnum();
	msg.AutoRemoveInviteInterval=pb->autoremoveinviteinterval();
	msg.InviteListMaxCount=pb->invitelistmaxcount();
	msg.NotReceiveInviteInterval=pb->notreceiveinviteinterval();
	msg.TeamMaxCount=pb->teammaxcount();
	msg.GetBatchFansCount=pb->getbatchfanscount();
	msg.BattleStarPriceId=pb->battlestarpriceid();
	msg.BattleStarPriceCount=pb->battlestarpricecount();
	msg.LevelMax=pb->levelmax();
	msg.RoundExpUpperLimit=pb->roundexpupperlimit();
	msg.RoundExpLowerLimit=pb->roundexplowerlimit();
	msg.WeekExpLimit=pb->weekexplimit();
	msg.SpecialGiftRefreshTime=UTF8_TO_TCHAR(pb->specialgiftrefreshtime().c_str());
	msg.SpecialGiftRefreshInterval=pb->specialgiftrefreshinterval();
	msg.TimedExchangeRefreshTime=UTF8_TO_TCHAR(pb->timedexchangerefreshtime().c_str());
	msg.TimedExchangeRefreshInterval=pb->timedexchangerefreshinterval();
	msg.BattleStarWeekBaseLimit=pb->battlestarweekbaselimit();
	msg.BattleStarWeekReviseLimit=pb->battlestarweekreviselimit();
	msg.QQVipLevelExpBonus=pb->qqviplevelexpbonus();
	msg.QQSvipLevelExpBonus=pb->qqsviplevelexpbonus();
	msg.QQGameCenterLevelExpBonus=pb->qqgamecenterlevelexpbonus();
	msg.WeChatGameCenterLevelExpBonus=pb->wechatgamecenterlevelexpbonus();
	msg.BlacklistMaxNum=pb->blacklistmaxnum();
	msg.VerificationCodeExpiredTime=pb->verificationcodeexpiredtime();
	msg.BindPhoneNumberCoolingTime=pb->bindphonenumbercoolingtime();
	msg.InviteMsgMaxLen=pb->invitemsgmaxlen();
	msg.VerificationCodeDailyLimit=pb->verificationcodedailylimit();
	for (int i = 0; i < pb->bindphonenumberawards().size(); i++) {
		auto &a = pb->bindphonenumberawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.BindPhoneNumberAwards.Add(tmp);
	}
	msg.SendCodeCoolingTime=pb->sendcodecoolingtime();
	msg.ShareRewardUserInfoId=pb->sharerewarduserinfoid();
	msg.ShareRewardUserInfoCount=pb->sharerewarduserinfocount();
	msg.ShareRewardFriendRankId=pb->sharerewardfriendrankid();
	msg.ShareRewardFriendRankCount=pb->sharerewardfriendrankcount();
	msg.ShareRewardPVPCountId=pb->sharerewardpvpcountid();
	msg.ShareRewardPVPCountCount=pb->sharerewardpvpcountcount();
	msg.ShareRewardChessId=pb->sharerewardchessid();
	msg.ShareRewardChessCount=pb->sharerewardchesscount();
	msg.ShareRewardCalendarId=pb->sharerewardcalendarid();
	msg.ShareRewardCalendarCount=pb->sharerewardcalendarcount();
	for (int i = 0; i < pb->firstchargeactivatechargetype().size(); i++) {
		auto &a = pb->firstchargeactivatechargetype().Get(i);
		int tmp;
		tmp=a;
		msg.FirstChargeActivateChargeType.Add(tmp);
	}
	msg.FirstChargeActivateDonutsNum=pb->firstchargeactivatedonutsnum();
	msg.FollowDailyLimit=pb->followdailylimit();
	msg.RecallCooldownTime=pb->recallcooldowntime();
	msg.RecallTime=pb->recalltime();
	msg.WeChatBigPlayerGiftsId=pb->wechatbigplayergiftsid();
	msg.WeChatBigPlayerMailId=UTF8_TO_TCHAR(pb->wechatbigplayermailid().c_str());
	msg.WeChatBigPlayerMailCtt=UTF8_TO_TCHAR(pb->wechatbigplayermailctt().c_str());
	msg.WeChatBigPlayerGachaColor=pb->wechatbigplayergachacolor();
	msg.WeChatBigPlayerLikesDaily=pb->wechatbigplayerlikesdaily();
	msg.WeChatBigPlayerRedPacketClaim=pb->wechatbigplayerredpacketclaim();
	msg.WeChatBigPlayerRedPacketRank=pb->wechatbigplayerredpacketrank();
	msg.WeChatBigPlayerLikesRank=pb->wechatbigplayerlikesrank();
	msg.WeChatBigPlayerRedPacketDailyReward=pb->wechatbigplayerredpacketdailyreward();
	msg.WeChatBigPlayerLikesReward=pb->wechatbigplayerlikesreward();
	for (int i = 0; i < pb->wechatbigplayerredlimits().size(); i++) {
		auto &a = pb->wechatbigplayerredlimits().Get(i);
		int tmp;
		tmp=a;
		msg.WeChatBigPlayerRedLimits.Add(tmp);
	}
	msg.WeChatBigPlayerNormalRedStores=pb->wechatbigplayernormalredstores();
	for (int i = 0; i < pb->inviteregisterawards().size(); i++) {
		auto &a = pb->inviteregisterawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.InviteRegisterAwards.Add(tmp);
	}
	msg.BlackTeamSwitchQQ=pb->blackteamswitchqq();
	msg.BlackTeamSwitchWeChat=pb->blackteamswitchwechat();
	msg.HeadIconIDIPResetTime=pb->headiconidipresettime();
	msg.PresetFastChatLimit=pb->presetfastchatlimit();
	msg.PvpConfirmMaxTime=pb->pvpconfirmmaxtime();
	msg.ActivityPageShowTypeList=UTF8_TO_TCHAR(pb->activitypageshowtypelist().c_str());
	msg.FreeChangeCountryNumber=pb->freechangecountrynumber();
	msg.AvatarAllowToRemoveAll=UTF8_TO_TCHAR(pb->avatarallowtoremoveall().c_str());
	msg.NoAdvertiseLevel=pb->noadvertiselevel();
	for (int i = 0; i < pb->recallrewards().size(); i++) {
		auto &a = pb->recallrewards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.RecallRewards.Add(tmp);
	}
	msg.FreeChangeProvinceTimes=pb->freechangeprovincetimes();
	for (int i = 0; i < pb->teampvpaward().size(); i++) {
		auto &a = pb->teampvpaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.TeamPvpAward.Add(tmp);
	}
	msg.AddictionCountdown1=pb->addictioncountdown1();
	msg.AddictionCountdown2=pb->addictioncountdown2();
	msg.MatchAddictionCountdown=pb->matchaddictioncountdown();
	msg.KRAddictionPCOpen=pb->kraddictionpcopen();
	msg.KRAddictionPhoneOpen=pb->kraddictionphoneopen();
	for (int i = 0; i < pb->friendinvitereaward().size(); i++) {
		auto &a = pb->friendinvitereaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.FriendInviteReaward.Add(tmp);
	}
	for (int i = 0; i < pb->rankupsharereward().size(); i++) {
		auto &a = pb->rankupsharereward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.RankUpShareReward.Add(tmp);
	}
	for (int i = 0; i < pb->winsharereward().size(); i++) {
		auto &a = pb->winsharereward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.WinShareReward.Add(tmp);
	}
	for (int i = 0; i < pb->passlevelsharereaward().size(); i++) {
		auto &a = pb->passlevelsharereaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PassLevelShareReaward.Add(tmp);
	}
	for (int i = 0; i < pb->passcommonquestsharereaward().size(); i++) {
		auto &a = pb->passcommonquestsharereaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PassCommonQuestShareReaward.Add(tmp);
	}
	for (int i = 0; i < pb->passspecialquestsharereaward().size(); i++) {
		auto &a = pb->passspecialquestsharereaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PassSpecialQuestShareReaward.Add(tmp);
	}
	msg.RefreshProvinceTime=pb->refreshprovincetime();
	msg.PassBuyingTips=pb->passbuyingtips();
	msg.PassAwardPreviewNum=pb->passawardpreviewnum();
	msg.ItemSortGrogram1=UTF8_TO_TCHAR(pb->itemsortgrogram1().c_str());
	msg.MessageTimeDisplays=pb->messagetimedisplays();
	msg.PopupPlayerLeverLimit=pb->popupplayerleverlimit();
	msg.PopupPlayerRegisterTimeLimit=pb->popupplayerregistertimelimit();
	msg.PopupPlayerReturnTimeLimit=pb->popupplayerreturntimelimit();
	msg.PopupGlobalLimit=pb->popupgloballimit();
	msg.GlobalMatchAskCoolDown=pb->globalmatchaskcooldown();
	msg.GlobalMatchAskWhenReduce=pb->globalmatchaskwhenreduce();
	msg.GlobalMatchAskReducedTime=pb->globalmatchaskreducedtime();
	msg.GlobalMatchAskMinCoolDown=pb->globalmatchaskmincooldown();
	msg.NewPlayerGuideLeaveTime=pb->newplayerguideleavetime();
	msg.RecommendedPlanOfLineup=pb->recommendedplanoflineup();
	msg.Ticketconversion1000=pb->ticketconversion1000();
	msg.Ticketconversion1001=pb->ticketconversion1001();
	msg.ReportIntervalTime=pb->reportintervaltime();
	msg.BattleWinningStreakBroadcast=UTF8_TO_TCHAR(pb->battlewinningstreakbroadcast().c_str());
	msg.BattleChessEvenKill=UTF8_TO_TCHAR(pb->battlechessevenkill().c_str());
	msg.WorkShopCollectionMaximum=pb->workshopcollectionmaximum();
	msg.BountyType=UTF8_TO_TCHAR(pb->bountytype().c_str());
	msg.PlayerMoneyModSwitch=pb->playermoneymodswitch();
	msg.PreparationConditionsCandy=pb->preparationconditionscandy();
	msg.PreparationConditionsPayCandy=pb->preparationconditionspaycandy();
	msg.PicBookEquipRecommend=pb->picbookequiprecommend();
	msg.TeamEquipRecommend=pb->teamequiprecommend();
	msg.ChessEquipRecommend=pb->chessequiprecommend();
	msg.EquipRecommendQuantity=pb->equiprecommendquantity();
	msg.ExchangeChipScale1136=pb->exchangechipscale1136();
	msg.ExchangeChipScale1137=pb->exchangechipscale1137();
	msg.ExchangeChipScale1138=pb->exchangechipscale1138();
	msg.ExchangeChipScale1139=pb->exchangechipscale1139();
	msg.RankCardRange=UTF8_TO_TCHAR(pb->rankcardrange().c_str());
	msg.TutorialReadingCoolingTime=pb->tutorialreadingcoolingtime();
	msg.ReportChatNum=pb->reportchatnum();
	msg.DelayMatchTimeLimit=pb->delaymatchtimelimit();
	msg.ReturnSignInPicLanguage=UTF8_TO_TCHAR(pb->returnsigninpiclanguage().c_str());
	msg.NewEquipRecommendQuantity=pb->newequiprecommendquantity();
	msg.ReturnSignInLocalPic=UTF8_TO_TCHAR(pb->returnsigninlocalpic().c_str());
	msg.DelayInfoCount=pb->delayinfocount();
	msg.DelayPeekNum=pb->delaypeeknum();
	msg.CandidateLimit=pb->candidatelimit();
	msg.SmeltCondition=pb->smeltcondition();
	msg.SmeltPoolId=pb->smeltpoolid();
	msg.MailEndTimeNotify=pb->mailendtimenotify();
	msg.ItemUpLimitTitle=UTF8_TO_TCHAR(pb->itemuplimittitle().c_str());
	msg.ItemUpLimitContent=UTF8_TO_TCHAR(pb->itemuplimitcontent().c_str());
	msg.ChessModelScale=UTF8_TO_TCHAR(pb->chessmodelscale().c_str());
	msg.DefaultHeadChess=UTF8_TO_TCHAR(pb->defaultheadchess().c_str());
	msg.NoviceAnswerNum=pb->noviceanswernum();
	msg.NoviceAnswerPassNum=pb->noviceanswerpassnum();
	msg.DelayEjectTime=pb->delayejecttime();
	msg.WatchTime=pb->watchtime();
	msg.MatchPlayerDropProbability=UTF8_TO_TCHAR(pb->matchplayerdropprobability().c_str());
	msg.WatchPlayerDropProbability=UTF8_TO_TCHAR(pb->watchplayerdropprobability().c_str());
	msg.ExchangeCoverItemId=UTF8_TO_TCHAR(pb->exchangecoveritemid().c_str());
	msg.CanUpgradePassportItemType=UTF8_TO_TCHAR(pb->canupgradepassportitemtype().c_str());
	msg.VoiceLengthLimit=pb->voicelengthlimit();
	msg.CardGroupKernelJson=UTF8_TO_TCHAR(pb->cardgroupkerneljson().c_str());
	msg.CardGroupAutoAddTimes=UTF8_TO_TCHAR(pb->cardgroupautoaddtimes().c_str());
	msg.AcutionNameMaxLen=pb->acutionnamemaxlen();
	msg.AcutionRemarkMaxLen=pb->acutionremarkmaxlen();
	msg.WalletServiceCharge=pb->walletservicecharge();
	msg.WalletServiceChargeMinNum=pb->walletservicechargeminnum();
	msg.BalanceCountCond=pb->balancecountcond();
	msg.SaleCountCond=pb->salecountcond();
	msg.PlayerShopShareCD=pb->playershopsharecd();
	msg.InsuranceCardDayLimit=pb->insurancecarddaylimit();
	msg.InsuranceCardTipsTime=pb->insurancecardtipstime();
	msg.InsuranceCardStartLevel=pb->insurancecardstartlevel();
	msg.InsuranceCardEndLevel=pb->insurancecardendlevel();
	msg.QueenMmrStar=UTF8_TO_TCHAR(pb->queenmmrstar().c_str());
	msg.BagMailInterval=pb->bagmailinterval();
	msg.TradeShowRMB=pb->tradeshowrmb();
	msg.InsuranceCardSeasonTip=pb->insurancecardseasontip();
	for (int i = 0; i < pb->insurancecardautoconsume().size(); i++) {
		auto &a = pb->insurancecardautoconsume().Get(i);
		int tmp;
		tmp=a;
		msg.InsuranceCardAutoConsume.Add(tmp);
	}
	msg.IsTradeShow=pb->istradeshow();
	msg.TradeAllMaxNum=pb->tradeallmaxnum();
	msg.ShowBatchSell=pb->showbatchsell();
}


USTRUCT(BlueprintType)
struct  FGlobalInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RefreshTimeDaily;	//每日刷新时间点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RefreshTimeWeekly;	//每周刷新点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InitMoney;	//初始金币

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InitMMR;	//初始MMR

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RemoveCondMatchMMRMaxGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchMMRMaxGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MatchMinWaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MatchCondLoseTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MatchMMRMaxGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MatchMMREnlargeValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MatchWinMaxGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchMinWaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchCondLoseTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchMMREnlargeValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchWinMaxGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchMMRMinGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchMMREnlargeTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchStrictMinCup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RankMatchHungerTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveMaxMatchTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PveMatchScoreGap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChatDirtyWordTip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultSkin;	//默认皮肤

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultScene;	//默认场景

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitSkinList;	//初始皮肤列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitSceneList;	//初始场景列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MMRProtectValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MmrCupAdd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MmrDiscrete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAlphaAward> AlphaOrderAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAlphaAward> AlphaCompeteAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> AlphaAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAlphaAward> AlphaChargeAwards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaOrderTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaOrderContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaCompeteTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaCompeteContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaChargeTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaChargeContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FrozenAsynCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FrozenDayAsynCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EvalWeekMoneyLimit;	//每周战斗获得糖果阈值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChatInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AiMaxCup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> AlphaTestAwards;	//内测奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaTestMailTitle;	//内测奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaTestMailContent;	//内测奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExposeCount;	// 达到禁言的举报次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SilenceTime;	// 普通禁言时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExposePeriod;	// 判断有效举报次数的时间段（s）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SilenceInterval;	// 禁言周期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SilenceSeriousTime;	// 周期内重复禁言的禁言时间（s）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> FirstWinAwards;	//首胜奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SilenceSuccessTitle;	//禁言成功邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SilenceSuccessContent;	//禁言成功邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultDamageEffect;	//默认伤害特效

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitDamageEffectList;	//赠送伤害特效列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultChatBubble;	//默认聊天气泡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitChatBubbleList;	//赠送聊天气泡列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitEmotionList;	//赠送表情列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DiamondCoefficient;	//付费糖果转化为免费糖果的系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportReturnMailTitle;	//通行证购买返利邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportReturnMailContent;	//通行证购买返利邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PassportReturnAwards;	//通行证购买返利奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AccountLevelMainParameter;	//账号等级经验公式核心参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AccountLevelReviseParameter1;	//账号等级经验公式修正参数1

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AccountLevelReviseParameter2;	//账号等级经验公式修正参数2

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SeasonAwardMailTitle;	//赛季奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SeasonAwardMailContent;	//赛季奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaActivityBeginTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AlphaActivityEndTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ResetMmrTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ResetMmrContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BaseWeekDate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityAwardMailTitle;	//活动未领取奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityAwardMailContent;	//活动未领取奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MeleeBeginWeekDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MeleeEndWeekDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HistoryPvpShowLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultHeadPicFrame;	//头像框

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitHeadPicFrameList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultChatDanmaku;	//聊天弹幕

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitChatDanmakuList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultCombineEffect;	//棋子合成特效

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitCombineEffectList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultWinTooltip;	//连胜提示框

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitWinTooltipList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultHeadPicPendant;	//头像挂件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitHeadPicPendantList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultChickenAction;	//棋手吃鸡特写动作

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitChickenActionList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DefaultRoundBeginPose;	//回合开始棋手静态POSE

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InitRoundBeginPoseList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMatchMmr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MeleeTaskAwardTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MeleeTaskAwardContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CommentBeginTime;	//评论引导功能开启时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CommentEndTime;	//评论引导功能关闭时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DailySmsLimit;	//每日短信限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DailySmsPerLimit;	//每日每哥号码短信限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportCashReturnMailTitle;	//通行证现金购买返利邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportCashReturnMailContent;	//通行证现金购买返利邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> PassportCashReturnAwards;	//通行证现金购买返利奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WeeklyRefreshTaskMailTitle;	//未领取周刷新任务标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WeeklyRefreshTaskMailContent;	//未领取周刷新任务内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DailyAwardMailTitle;	//每日奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DailyAwardMailContent;	//每日奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> DailyAwards;	//每日奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BindPhoneNumberMailTitle;	//首次绑定手机号奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BindPhoneNumberMailContent;	//首次绑定手机号奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InviteInterval;	//邀约的时间间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SharingCodeBeginTime;	//分享码活动开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SharingCodeEndTime;	//分享码活动结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SharingCodeValidityPeriod;	//分享码有效期

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpCountLimit;	//频繁对局次数限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpCountLimitPeriod;	//频繁对局次数限制周期，单位秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> QQSvipLoginAwards;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> QQSvipContinuousLoginAwards;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> QQGameCenterLoginAwards;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> WeChatGameCenterLoginAwards;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString QQCenterLaunchMailTitle;	//邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WXCenterLaunchMailTitle;	//邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString QQSvipLoginMailTitle;	//邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString QQSvipContinuousLoginMailTitle;	//邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CommonMailContent;	//通用邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> BindPhoneNumberAwards;	//首次绑定手机号奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FortuneBagBeginTime;	//福袋活动开始时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FortuneBagEndTime;	//福袋活动结束时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BindOldAccountSafetyTime;	//绑定老账号安全操作时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BindOldAccountRegisterDeadline;	//判断是否老账号的时间点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CreditScoreMin;	//安全信用分min

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CreditScoreMax;	//安全信用分max

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CreditScoreMinChatLv;	//安全信用聊天等级限制min

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CreditScoreMaxChatLv;	//安全信用聊天等级限制max

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PvpChatInterval;	//pvp聊天时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int VoiceMark;	//语音配置开关 0--所有都屏蔽 1--开启2v2阵营 2--开启战斗内所有 3--开启大厅和战斗内

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RefreshCountryTime;	//刷新国家时间 单位天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecommendPvpCount;	//每次推荐战局数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RecommendStandardScore;	//加入推荐战局标准分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NotRecommendSurviveCount;	//不加入推荐战局的最大人数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NotRecommendPlayTime;	//不加入推荐战局的最小战斗时长

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxObserveCount;	//每场战斗观战人数限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString InviteRegisterMailTitle;	//关系链邀请注册邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AIConfirmMaxTime;	//AI确认最大时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AIConfirmWaitTime;	//AI确认等待事件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TLOGRankThreshold;	//排行榜TLOG上报的最大数

	int64 AudienceChatInterval;	//观战聊天间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TLOGItemTypeCap;	//哪些道具类型下存量的TLOG

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SeasonCompenstateTitle;	//赛季补偿邮件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SeasonCompenstateContent;	//赛季补偿邮件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NextChangeSlotInterval;	//换位时间间隔 单位秒

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TLOGRankInterval;	//排行榜TLOG上报时间间隔

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MeleeRefreshWeekDay;	//梦境模式每周刷新时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassportLevelAwardLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportAwardMailTitle;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PassportAwardMailContent;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HistoryMessageFrequency;	//历史消息显示频率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PocketAutoChessShopMailTitle1;	//掌上自走棋付款提示邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PocketAutoChessShopMailContent1;	//掌上自走棋付款提示邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PocketAutoChessShopMailTitle2;	//掌上自走棋补款提示邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PocketAutoChessShopMailContent2;	//掌上自走棋补款提示邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PocketAutoChessShopMailTitle3;	//掌上自走棋退款提示邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PocketAutoChessShopMailContent3;	//掌上自走棋退款提示邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PocketAutoChessAssocciateMailTitle1;	//掌上自走棋账户关联提示标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PocketAutoChessAssocciateMailContent1;	//掌上自走棋账户关联提示内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentCancelMailTitle;	//赛事取消返还物品邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentCancelMailContent;	//赛事取消返还物品邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentPointsRewardMailTitle;	//补发赛事进度奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentPointsRewardMailContent;	//补发赛事进度奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentRankRewardMailTitle;	//赛事积分排名奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentRankRewardMailContent;	//赛事积分排名奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentRoundRankRewardMailTitle;	//轮次积分排行奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentRoundRankRewardMailContent;	//轮次积分排行奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentSeasonalMatchEliminateRewardMailTitle;	//季赛淘汰奖励邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TournamentSeasonalMatchEliminateRewardMailContent;	//季赛淘汰奖励邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DefaultNickname;	//强制改名时的默认昵称

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ForcedRenameMailTitle;	//强制改名邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ForcedRenameMailContent;	//强制改名邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> SamsungOrderMailAwards;	//samsung预约礼包奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SamsungOrderMailTitle;	//三星预约礼包邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SamsungOrderMailContent;	//三星预约礼包邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailReportSuccessTitle;	//举报成立邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailReportSuccessContent;	//举报成立邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailReportFailTitle;	//举报不成立邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailReportFailContent;	//举报不成立邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityRecruitMailTitle;	//好友召回邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActivityRecruitMailContent;	//好友召回邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> VNGCommentAward;	//vng商店评论奖励

	int64 VNGCommentAwardResetTime;	//vng商店评论时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ForcedBannedChatMailTitle;	//举报禁言邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ForcedBannedChatMailContent;	//举报禁言邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ForcedFrozenMailTitle;	//举报封号邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ForcedFrozenMailContent;	//举报封号邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> RankCardRange;	//段位保护卡适用范围

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailExchangeSellTitle;	//上架申请邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailExchangeSellContent;	//上架申请邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailExchangeGiftTitle;	//赠送邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailExchangeGiftContent;	//赠送邮件内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamMemberMmrHigh;	//组队单人匹配最高分段(用于有皇后段位的玩家则其队友必须全是国王及以上)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TeamMemberMmrLow;	//组队单人匹配最低分段

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailExchangeReceiveGiftTitle;	//接受赠送邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MailExchangeReceiveGiftContent;	//接受赠送邮件内容

	int64 LogoutCountDown;	//手游注销账号倒计时（秒）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RoomWorkshopWatchMode;	//创意工坊某些地图支持加入推荐对局(mapkey由平台页面配置)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassportRefreshTimeWeekly;	//通行证周刷新时间(day)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MedalAwardTitle;	//勋章任务奖励补发邮件标题

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MedalAwardContent;	//勋章任务奖励补发邮件内容

	int64 ObServerTime;	//观战 数据留存时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AwardInvalidActivity;	//活动结束后发放奖励代领邮件的开关

};
static void _ConvertPbToFGlobalInfo(FGlobalInfo &msg, const msg::GlobalInfo *pb) {
	msg.RefreshTimeDaily=UTF8_TO_TCHAR(pb->refreshtimedaily().c_str());
	msg.RefreshTimeWeekly=pb->refreshtimeweekly();
	msg.InitMoney=pb->initmoney();
	msg.InitMMR=pb->initmmr();
	msg.RemoveCondMatchMMRMaxGap=pb->removecondmatchmmrmaxgap();
	msg.RankMatchMMRMaxGap=pb->rankmatchmmrmaxgap();
	msg.MatchMinWaitTime=pb->matchminwaittime();
	msg.MatchCondLoseTime=pb->matchcondlosetime();
	msg.MatchMMRMaxGap=pb->matchmmrmaxgap();
	msg.MatchMMREnlargeValue=pb->matchmmrenlargevalue();
	msg.MatchWinMaxGap=pb->matchwinmaxgap();
	msg.RankMatchMinWaitTime=pb->rankmatchminwaittime();
	msg.RankMatchCondLoseTime=pb->rankmatchcondlosetime();
	msg.RankMatchMMREnlargeValue=pb->rankmatchmmrenlargevalue();
	msg.RankMatchWinMaxGap=pb->rankmatchwinmaxgap();
	msg.RankMatchMMRMinGap=pb->rankmatchmmrmingap();
	msg.RankMatchMMREnlargeTime=pb->rankmatchmmrenlargetime();
	msg.RankMatchStrictMinCup=pb->rankmatchstrictmincup();
	msg.RankMatchHungerTime=pb->rankmatchhungertime();
	msg.PveMaxMatchTime=pb->pvemaxmatchtime();
	msg.PveMatchScoreGap=pb->pvematchscoregap();
	msg.ChatDirtyWordTip=UTF8_TO_TCHAR(pb->chatdirtywordtip().c_str());
	msg.DefaultSkin=pb->defaultskin();
	msg.DefaultScene=pb->defaultscene();
	msg.InitSkinList=UTF8_TO_TCHAR(pb->initskinlist().c_str());
	msg.InitSceneList=UTF8_TO_TCHAR(pb->initscenelist().c_str());
	msg.MMRProtectValue=pb->mmrprotectvalue();
	msg.MmrCupAdd=pb->mmrcupadd();
	msg.MmrDiscrete=pb->mmrdiscrete();
	for (int i = 0; i < pb->alphaorderawards().size(); i++) {
		auto &a = pb->alphaorderawards().Get(i);
		FAlphaAward tmp;
		_ConvertPbToFAlphaAward(tmp, &a);
		msg.AlphaOrderAwards.Add(tmp);
	}
	for (int i = 0; i < pb->alphacompeteawards().size(); i++) {
		auto &a = pb->alphacompeteawards().Get(i);
		FAlphaAward tmp;
		_ConvertPbToFAlphaAward(tmp, &a);
		msg.AlphaCompeteAwards.Add(tmp);
	}
	for (int i = 0; i < pb->alphaawards().size(); i++) {
		auto &a = pb->alphaawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.AlphaAwards.Add(tmp);
	}
	for (int i = 0; i < pb->alphachargeawards().size(); i++) {
		auto &a = pb->alphachargeawards().Get(i);
		FAlphaAward tmp;
		_ConvertPbToFAlphaAward(tmp, &a);
		msg.AlphaChargeAwards.Add(tmp);
	}
	msg.AlphaOrderTitle=UTF8_TO_TCHAR(pb->alphaordertitle().c_str());
	msg.AlphaOrderContent=UTF8_TO_TCHAR(pb->alphaordercontent().c_str());
	msg.AlphaCompeteTitle=UTF8_TO_TCHAR(pb->alphacompetetitle().c_str());
	msg.AlphaCompeteContent=UTF8_TO_TCHAR(pb->alphacompetecontent().c_str());
	msg.AlphaTitle=UTF8_TO_TCHAR(pb->alphatitle().c_str());
	msg.AlphaContent=UTF8_TO_TCHAR(pb->alphacontent().c_str());
	msg.AlphaChargeTitle=UTF8_TO_TCHAR(pb->alphachargetitle().c_str());
	msg.AlphaChargeContent=UTF8_TO_TCHAR(pb->alphachargecontent().c_str());
	msg.FrozenAsynCount=pb->frozenasyncount();
	msg.FrozenDayAsynCount=pb->frozendayasyncount();
	msg.EvalWeekMoneyLimit=pb->evalweekmoneylimit();
	msg.ChatInterval=pb->chatinterval();
	msg.AiMaxCup=pb->aimaxcup();
	for (int i = 0; i < pb->alphatestawards().size(); i++) {
		auto &a = pb->alphatestawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.AlphaTestAwards.Add(tmp);
	}
	msg.AlphaTestMailTitle=UTF8_TO_TCHAR(pb->alphatestmailtitle().c_str());
	msg.AlphaTestMailContent=UTF8_TO_TCHAR(pb->alphatestmailcontent().c_str());
	msg.ExposeCount=pb->exposecount();
	msg.SilenceTime=pb->silencetime();
	msg.ExposePeriod=pb->exposeperiod();
	msg.SilenceInterval=pb->silenceinterval();
	msg.SilenceSeriousTime=pb->silenceserioustime();
	for (int i = 0; i < pb->firstwinawards().size(); i++) {
		auto &a = pb->firstwinawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.FirstWinAwards.Add(tmp);
	}
	msg.SilenceSuccessTitle=UTF8_TO_TCHAR(pb->silencesuccesstitle().c_str());
	msg.SilenceSuccessContent=UTF8_TO_TCHAR(pb->silencesuccesscontent().c_str());
	msg.DefaultDamageEffect=pb->defaultdamageeffect();
	msg.InitDamageEffectList=UTF8_TO_TCHAR(pb->initdamageeffectlist().c_str());
	msg.DefaultChatBubble=pb->defaultchatbubble();
	msg.InitChatBubbleList=UTF8_TO_TCHAR(pb->initchatbubblelist().c_str());
	msg.InitEmotionList=UTF8_TO_TCHAR(pb->initemotionlist().c_str());
	msg.DiamondCoefficient=pb->diamondcoefficient();
	msg.PassportReturnMailTitle=UTF8_TO_TCHAR(pb->passportreturnmailtitle().c_str());
	msg.PassportReturnMailContent=UTF8_TO_TCHAR(pb->passportreturnmailcontent().c_str());
	for (int i = 0; i < pb->passportreturnawards().size(); i++) {
		auto &a = pb->passportreturnawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PassportReturnAwards.Add(tmp);
	}
	msg.AccountLevelMainParameter=pb->accountlevelmainparameter();
	msg.AccountLevelReviseParameter1=pb->accountlevelreviseparameter1();
	msg.AccountLevelReviseParameter2=pb->accountlevelreviseparameter2();
	msg.SeasonAwardMailTitle=UTF8_TO_TCHAR(pb->seasonawardmailtitle().c_str());
	msg.SeasonAwardMailContent=UTF8_TO_TCHAR(pb->seasonawardmailcontent().c_str());
	msg.AlphaActivityBeginTime=UTF8_TO_TCHAR(pb->alphaactivitybegintime().c_str());
	msg.AlphaActivityEndTime=UTF8_TO_TCHAR(pb->alphaactivityendtime().c_str());
	msg.ResetMmrTitle=UTF8_TO_TCHAR(pb->resetmmrtitle().c_str());
	msg.ResetMmrContent=UTF8_TO_TCHAR(pb->resetmmrcontent().c_str());
	msg.BaseWeekDate=UTF8_TO_TCHAR(pb->baseweekdate().c_str());
	msg.ActivityAwardMailTitle=UTF8_TO_TCHAR(pb->activityawardmailtitle().c_str());
	msg.ActivityAwardMailContent=UTF8_TO_TCHAR(pb->activityawardmailcontent().c_str());
	msg.MeleeBeginWeekDay=pb->meleebeginweekday();
	msg.MeleeEndWeekDay=pb->meleeendweekday();
	msg.HistoryPvpShowLimit=pb->historypvpshowlimit();
	msg.DefaultHeadPicFrame=pb->defaultheadpicframe();
	msg.InitHeadPicFrameList=UTF8_TO_TCHAR(pb->initheadpicframelist().c_str());
	msg.DefaultChatDanmaku=pb->defaultchatdanmaku();
	msg.InitChatDanmakuList=UTF8_TO_TCHAR(pb->initchatdanmakulist().c_str());
	msg.DefaultCombineEffect=pb->defaultcombineeffect();
	msg.InitCombineEffectList=UTF8_TO_TCHAR(pb->initcombineeffectlist().c_str());
	msg.DefaultWinTooltip=pb->defaultwintooltip();
	msg.InitWinTooltipList=UTF8_TO_TCHAR(pb->initwintooltiplist().c_str());
	msg.DefaultHeadPicPendant=pb->defaultheadpicpendant();
	msg.InitHeadPicPendantList=UTF8_TO_TCHAR(pb->initheadpicpendantlist().c_str());
	msg.DefaultChickenAction=pb->defaultchickenaction();
	msg.InitChickenActionList=UTF8_TO_TCHAR(pb->initchickenactionlist().c_str());
	msg.DefaultRoundBeginPose=pb->defaultroundbeginpose();
	msg.InitRoundBeginPoseList=UTF8_TO_TCHAR(pb->initroundbeginposelist().c_str());
	msg.MaxMatchMmr=pb->maxmatchmmr();
	msg.MeleeTaskAwardTitle=UTF8_TO_TCHAR(pb->meleetaskawardtitle().c_str());
	msg.MeleeTaskAwardContent=UTF8_TO_TCHAR(pb->meleetaskawardcontent().c_str());
	msg.CommentBeginTime=UTF8_TO_TCHAR(pb->commentbegintime().c_str());
	msg.CommentEndTime=UTF8_TO_TCHAR(pb->commentendtime().c_str());
	msg.DailySmsLimit=pb->dailysmslimit();
	msg.DailySmsPerLimit=pb->dailysmsperlimit();
	msg.PassportCashReturnMailTitle=UTF8_TO_TCHAR(pb->passportcashreturnmailtitle().c_str());
	msg.PassportCashReturnMailContent=UTF8_TO_TCHAR(pb->passportcashreturnmailcontent().c_str());
	for (int i = 0; i < pb->passportcashreturnawards().size(); i++) {
		auto &a = pb->passportcashreturnawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.PassportCashReturnAwards.Add(tmp);
	}
	msg.WeeklyRefreshTaskMailTitle=UTF8_TO_TCHAR(pb->weeklyrefreshtaskmailtitle().c_str());
	msg.WeeklyRefreshTaskMailContent=UTF8_TO_TCHAR(pb->weeklyrefreshtaskmailcontent().c_str());
	msg.DailyAwardMailTitle=UTF8_TO_TCHAR(pb->dailyawardmailtitle().c_str());
	msg.DailyAwardMailContent=UTF8_TO_TCHAR(pb->dailyawardmailcontent().c_str());
	for (int i = 0; i < pb->dailyawards().size(); i++) {
		auto &a = pb->dailyawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.DailyAwards.Add(tmp);
	}
	msg.BindPhoneNumberMailTitle=UTF8_TO_TCHAR(pb->bindphonenumbermailtitle().c_str());
	msg.BindPhoneNumberMailContent=UTF8_TO_TCHAR(pb->bindphonenumbermailcontent().c_str());
	msg.InviteInterval=pb->inviteinterval();
	msg.SharingCodeBeginTime=UTF8_TO_TCHAR(pb->sharingcodebegintime().c_str());
	msg.SharingCodeEndTime=UTF8_TO_TCHAR(pb->sharingcodeendtime().c_str());
	msg.SharingCodeValidityPeriod=pb->sharingcodevalidityperiod();
	msg.PvpCountLimit=pb->pvpcountlimit();
	msg.PvpCountLimitPeriod=pb->pvpcountlimitperiod();
	for (int i = 0; i < pb->qqsviploginawards().size(); i++) {
		auto &a = pb->qqsviploginawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.QQSvipLoginAwards.Add(tmp);
	}
	for (int i = 0; i < pb->qqsvipcontinuousloginawards().size(); i++) {
		auto &a = pb->qqsvipcontinuousloginawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.QQSvipContinuousLoginAwards.Add(tmp);
	}
	for (int i = 0; i < pb->qqgamecenterloginawards().size(); i++) {
		auto &a = pb->qqgamecenterloginawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.QQGameCenterLoginAwards.Add(tmp);
	}
	for (int i = 0; i < pb->wechatgamecenterloginawards().size(); i++) {
		auto &a = pb->wechatgamecenterloginawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.WeChatGameCenterLoginAwards.Add(tmp);
	}
	msg.QQCenterLaunchMailTitle=UTF8_TO_TCHAR(pb->qqcenterlaunchmailtitle().c_str());
	msg.WXCenterLaunchMailTitle=UTF8_TO_TCHAR(pb->wxcenterlaunchmailtitle().c_str());
	msg.QQSvipLoginMailTitle=UTF8_TO_TCHAR(pb->qqsviploginmailtitle().c_str());
	msg.QQSvipContinuousLoginMailTitle=UTF8_TO_TCHAR(pb->qqsvipcontinuousloginmailtitle().c_str());
	msg.CommonMailContent=UTF8_TO_TCHAR(pb->commonmailcontent().c_str());
	for (int i = 0; i < pb->bindphonenumberawards().size(); i++) {
		auto &a = pb->bindphonenumberawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.BindPhoneNumberAwards.Add(tmp);
	}
	msg.FortuneBagBeginTime=UTF8_TO_TCHAR(pb->fortunebagbegintime().c_str());
	msg.FortuneBagEndTime=UTF8_TO_TCHAR(pb->fortunebagendtime().c_str());
	msg.BindOldAccountSafetyTime=pb->bindoldaccountsafetytime();
	msg.BindOldAccountRegisterDeadline=UTF8_TO_TCHAR(pb->bindoldaccountregisterdeadline().c_str());
	msg.CreditScoreMin=pb->creditscoremin();
	msg.CreditScoreMax=pb->creditscoremax();
	msg.CreditScoreMinChatLv=pb->creditscoreminchatlv();
	msg.CreditScoreMaxChatLv=pb->creditscoremaxchatlv();
	msg.PvpChatInterval=pb->pvpchatinterval();
	msg.VoiceMark=pb->voicemark();
	msg.RefreshCountryTime=pb->refreshcountrytime();
	msg.RecommendPvpCount=pb->recommendpvpcount();
	msg.RecommendStandardScore=pb->recommendstandardscore();
	msg.NotRecommendSurviveCount=pb->notrecommendsurvivecount();
	msg.NotRecommendPlayTime=pb->notrecommendplaytime();
	msg.MaxObserveCount=pb->maxobservecount();
	msg.InviteRegisterMailTitle=UTF8_TO_TCHAR(pb->inviteregistermailtitle().c_str());
	msg.AIConfirmMaxTime=pb->aiconfirmmaxtime();
	msg.AIConfirmWaitTime=pb->aiconfirmwaittime();
	msg.TLOGRankThreshold=pb->tlogrankthreshold();
	msg.AudienceChatInterval=pb->audiencechatinterval();
	msg.TLOGItemTypeCap=UTF8_TO_TCHAR(pb->tlogitemtypecap().c_str());
	msg.SeasonCompenstateTitle=UTF8_TO_TCHAR(pb->seasoncompenstatetitle().c_str());
	msg.SeasonCompenstateContent=UTF8_TO_TCHAR(pb->seasoncompenstatecontent().c_str());
	msg.NextChangeSlotInterval=pb->nextchangeslotinterval();
	msg.TLOGRankInterval=pb->tlogrankinterval();
	msg.MeleeRefreshWeekDay=pb->meleerefreshweekday();
	msg.PassportLevelAwardLimit=pb->passportlevelawardlimit();
	msg.PassportAwardMailTitle=UTF8_TO_TCHAR(pb->passportawardmailtitle().c_str());
	msg.PassportAwardMailContent=UTF8_TO_TCHAR(pb->passportawardmailcontent().c_str());
	msg.HistoryMessageFrequency=pb->historymessagefrequency();
	msg.PocketAutoChessShopMailTitle1=UTF8_TO_TCHAR(pb->pocketautochessshopmailtitle1().c_str());
	msg.PocketAutoChessShopMailContent1=UTF8_TO_TCHAR(pb->pocketautochessshopmailcontent1().c_str());
	msg.PocketAutoChessShopMailTitle2=UTF8_TO_TCHAR(pb->pocketautochessshopmailtitle2().c_str());
	msg.PocketAutoChessShopMailContent2=UTF8_TO_TCHAR(pb->pocketautochessshopmailcontent2().c_str());
	msg.PocketAutoChessShopMailTitle3=UTF8_TO_TCHAR(pb->pocketautochessshopmailtitle3().c_str());
	msg.PocketAutoChessShopMailContent3=UTF8_TO_TCHAR(pb->pocketautochessshopmailcontent3().c_str());
	msg.PocketAutoChessAssocciateMailTitle1=UTF8_TO_TCHAR(pb->pocketautochessassocciatemailtitle1().c_str());
	msg.PocketAutoChessAssocciateMailContent1=UTF8_TO_TCHAR(pb->pocketautochessassocciatemailcontent1().c_str());
	msg.TournamentCancelMailTitle=UTF8_TO_TCHAR(pb->tournamentcancelmailtitle().c_str());
	msg.TournamentCancelMailContent=UTF8_TO_TCHAR(pb->tournamentcancelmailcontent().c_str());
	msg.TournamentPointsRewardMailTitle=UTF8_TO_TCHAR(pb->tournamentpointsrewardmailtitle().c_str());
	msg.TournamentPointsRewardMailContent=UTF8_TO_TCHAR(pb->tournamentpointsrewardmailcontent().c_str());
	msg.TournamentRankRewardMailTitle=UTF8_TO_TCHAR(pb->tournamentrankrewardmailtitle().c_str());
	msg.TournamentRankRewardMailContent=UTF8_TO_TCHAR(pb->tournamentrankrewardmailcontent().c_str());
	msg.TournamentRoundRankRewardMailTitle=UTF8_TO_TCHAR(pb->tournamentroundrankrewardmailtitle().c_str());
	msg.TournamentRoundRankRewardMailContent=UTF8_TO_TCHAR(pb->tournamentroundrankrewardmailcontent().c_str());
	msg.TournamentSeasonalMatchEliminateRewardMailTitle=UTF8_TO_TCHAR(pb->tournamentseasonalmatcheliminaterewardmailtitle().c_str());
	msg.TournamentSeasonalMatchEliminateRewardMailContent=UTF8_TO_TCHAR(pb->tournamentseasonalmatcheliminaterewardmailcontent().c_str());
	msg.DefaultNickname=UTF8_TO_TCHAR(pb->defaultnickname().c_str());
	msg.ForcedRenameMailTitle=UTF8_TO_TCHAR(pb->forcedrenamemailtitle().c_str());
	msg.ForcedRenameMailContent=UTF8_TO_TCHAR(pb->forcedrenamemailcontent().c_str());
	for (int i = 0; i < pb->samsungordermailawards().size(); i++) {
		auto &a = pb->samsungordermailawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.SamsungOrderMailAwards.Add(tmp);
	}
	msg.SamsungOrderMailTitle=UTF8_TO_TCHAR(pb->samsungordermailtitle().c_str());
	msg.SamsungOrderMailContent=UTF8_TO_TCHAR(pb->samsungordermailcontent().c_str());
	msg.MailReportSuccessTitle=UTF8_TO_TCHAR(pb->mailreportsuccesstitle().c_str());
	msg.MailReportSuccessContent=UTF8_TO_TCHAR(pb->mailreportsuccesscontent().c_str());
	msg.MailReportFailTitle=UTF8_TO_TCHAR(pb->mailreportfailtitle().c_str());
	msg.MailReportFailContent=UTF8_TO_TCHAR(pb->mailreportfailcontent().c_str());
	msg.ActivityRecruitMailTitle=UTF8_TO_TCHAR(pb->activityrecruitmailtitle().c_str());
	msg.ActivityRecruitMailContent=UTF8_TO_TCHAR(pb->activityrecruitmailcontent().c_str());
	for (int i = 0; i < pb->vngcommentaward().size(); i++) {
		auto &a = pb->vngcommentaward().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.VNGCommentAward.Add(tmp);
	}
	msg.VNGCommentAwardResetTime=pb->vngcommentawardresettime();
	msg.ForcedBannedChatMailTitle=UTF8_TO_TCHAR(pb->forcedbannedchatmailtitle().c_str());
	msg.ForcedBannedChatMailContent=UTF8_TO_TCHAR(pb->forcedbannedchatmailcontent().c_str());
	msg.ForcedFrozenMailTitle=UTF8_TO_TCHAR(pb->forcedfrozenmailtitle().c_str());
	msg.ForcedFrozenMailContent=UTF8_TO_TCHAR(pb->forcedfrozenmailcontent().c_str());
	for (int i = 0; i < pb->rankcardrange().size(); i++) {
		auto &a = pb->rankcardrange().Get(i);
		int tmp;
		tmp=a;
		msg.RankCardRange.Add(tmp);
	}
	msg.MailExchangeSellTitle=UTF8_TO_TCHAR(pb->mailexchangeselltitle().c_str());
	msg.MailExchangeSellContent=UTF8_TO_TCHAR(pb->mailexchangesellcontent().c_str());
	msg.MailExchangeGiftTitle=UTF8_TO_TCHAR(pb->mailexchangegifttitle().c_str());
	msg.MailExchangeGiftContent=UTF8_TO_TCHAR(pb->mailexchangegiftcontent().c_str());
	msg.TeamMemberMmrHigh=pb->teammembermmrhigh();
	msg.TeamMemberMmrLow=pb->teammembermmrlow();
	msg.MailExchangeReceiveGiftTitle=UTF8_TO_TCHAR(pb->mailexchangereceivegifttitle().c_str());
	msg.MailExchangeReceiveGiftContent=UTF8_TO_TCHAR(pb->mailexchangereceivegiftcontent().c_str());
	msg.LogoutCountDown=pb->logoutcountdown();
	msg.RoomWorkshopWatchMode=UTF8_TO_TCHAR(pb->roomworkshopwatchmode().c_str());
	msg.PassportRefreshTimeWeekly=pb->passportrefreshtimeweekly();
	msg.MedalAwardTitle=UTF8_TO_TCHAR(pb->medalawardtitle().c_str());
	msg.MedalAwardContent=UTF8_TO_TCHAR(pb->medalawardcontent().c_str());
	msg.ObServerTime=pb->observertime();
	msg.AwardInvalidActivity=pb->awardinvalidactivity();
}


USTRUCT(BlueprintType)
struct  FExceptProInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FExceptProData> Datas;

};
static void _ConvertPbToFExceptProInfo(FExceptProInfo &msg, const msg::ExceptProInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FExceptProData tmp;
		_ConvertPbToFExceptProData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FModeProInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FModeProData> Datas;

};
static void _ConvertPbToFModeProInfo(FModeProInfo &msg, const msg::ModeProInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FModeProData tmp;
		_ConvertPbToFModeProData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPvpChestInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPvpChestData> Datas;

};
static void _ConvertPbToFPvpChestInfo(FPvpChestInfo &msg, const msg::PvpChestInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPvpChestData tmp;
		_ConvertPbToFPvpChestData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FObserverChestInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FObserverChestData> Datas;

};
static void _ConvertPbToFObserverChestInfo(FObserverChestInfo &msg, const msg::ObserverChestInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FObserverChestData tmp;
		_ConvertPbToFObserverChestData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCupInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCupData> Datas;

};
static void _ConvertPbToFCupInfo(FCupInfo &msg, const msg::CupInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FCupData tmp;
		_ConvertPbToFCupData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCupMatchPerfectInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCupMatchPerfectData> Datas;

};
static void _ConvertPbToFCupMatchPerfectInfo(FCupMatchPerfectInfo &msg, const msg::CupMatchPerfectInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FCupMatchPerfectData tmp;
		_ConvertPbToFCupMatchPerfectData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCupMatchExtendInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCupMatchExtendData> Datas;

};
static void _ConvertPbToFCupMatchExtendInfo(FCupMatchExtendInfo &msg, const msg::CupMatchExtendInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FCupMatchExtendData tmp;
		_ConvertPbToFCupMatchExtendData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRankSeasonEvalInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRankSeasonEvalData> Datas;

};
static void _ConvertPbToFRankSeasonEvalInfo(FRankSeasonEvalInfo &msg, const msg::RankSeasonEvalInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRankSeasonEvalData tmp;
		_ConvertPbToFRankSeasonEvalData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FLanguageInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLanguageData> Datas;

};
static void _ConvertPbToFLanguageInfo(FLanguageInfo &msg, const msg::LanguageInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FLanguageData tmp;
		_ConvertPbToFLanguageData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNickNameInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNickName> Datas;

};
static void _ConvertPbToFNickNameInfo(FNickNameInfo &msg, const msg::NickNameInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FNickName tmp;
		_ConvertPbToFNickName(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FDirtyWordInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDirtyWord> Datas;

};
static void _ConvertPbToFDirtyWordInfo(FDirtyWordInfo &msg, const msg::DirtyWordInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FDirtyWord tmp;
		_ConvertPbToFDirtyWord(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActiveCodeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActiveCode> Datas;

};
static void _ConvertPbToFActiveCodeInfo(FActiveCodeInfo &msg, const msg::ActiveCodeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FActiveCode tmp;
		_ConvertPbToFActiveCode(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemData> Datas;

};
static void _ConvertPbToFItemInfo(FItemInfo &msg, const msg::ItemInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FItemData tmp;
		_ConvertPbToFItemData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FEggAwardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEggAward> Datas;

};
static void _ConvertPbToFEggAwardInfo(FEggAwardInfo &msg, const msg::EggAwardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FEggAward tmp;
		_ConvertPbToFEggAward(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FSetNameInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSetNameData> Datas;

};
static void _ConvertPbToFSetNameInfo(FSetNameInfo &msg, const msg::SetNameInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FSetNameData tmp;
		_ConvertPbToFSetNameData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRandomNameInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRandomNameData> Datas;

};
static void _ConvertPbToFRandomNameInfo(FRandomNameInfo &msg, const msg::RandomNameInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRandomNameData tmp;
		_ConvertPbToFRandomNameData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FEvalInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEvalData> Datas;

};
static void _ConvertPbToFEvalInfo(FEvalInfo &msg, const msg::EvalInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FEvalData tmp;
		_ConvertPbToFEvalData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMmrChangeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMmrChangeData> Datas;

};
static void _ConvertPbToFMmrChangeInfo(FMmrChangeInfo &msg, const msg::MmrChangeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMmrChangeData tmp;
		_ConvertPbToFMmrChangeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMmrRankCoefficientInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMmrRankCoefficientData> Datas;

};
static void _ConvertPbToFMmrRankCoefficientInfo(FMmrRankCoefficientInfo &msg, const msg::MmrRankCoefficientInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMmrRankCoefficientData tmp;
		_ConvertPbToFMmrRankCoefficientData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMmrWinFailCoefficientInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMmrWinFailCoefficientData> Datas;

};
static void _ConvertPbToFMmrWinFailCoefficientInfo(FMmrWinFailCoefficientInfo &msg, const msg::MmrWinFailCoefficientInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMmrWinFailCoefficientData tmp;
		_ConvertPbToFMmrWinFailCoefficientData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FResChessPlayerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessPlayerData> Datas;

};
static void _ConvertPbToFResChessPlayerInfo(FResChessPlayerInfo &msg, const msg::ChessPlayerInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessPlayerData tmp;
		_ConvertPbToFChessPlayerData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGuideInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuideData> Datas;

};
static void _ConvertPbToFGuideInfo(FGuideInfo &msg, const msg::GuideInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FGuideData tmp;
		_ConvertPbToFGuideData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FStaffInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DragonNestLogo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DuoduoLogo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Staffs;

};
static void _ConvertPbToFStaffInfo(FStaffInfo &msg, const msg::StaffInfo *pb) {
	msg.DragonNestLogo=UTF8_TO_TCHAR(pb->dragonnestlogo().c_str());
	msg.DuoduoLogo=UTF8_TO_TCHAR(pb->duoduologo().c_str());
	for (int i = 0; i < pb->staffs().size(); i++) {
		auto &a = pb->staffs().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.Staffs.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FDirectLoginPlayerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDirectLoginPlayerData> Datas;

};
static void _ConvertPbToFDirectLoginPlayerInfo(FDirectLoginPlayerInfo &msg, const msg::DirectLoginPlayerInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FDirectLoginPlayerData tmp;
		_ConvertPbToFDirectLoginPlayerData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FResRegionInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRegionData> Datas;

};
static void _ConvertPbToFResRegionInfo(FResRegionInfo &msg, const msg::RegionInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRegionData tmp;
		_ConvertPbToFRegionData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPhoneTypeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPhoneTypeData> Datas;

};
static void _ConvertPbToFPhoneTypeInfo(FPhoneTypeInfo &msg, const msg::PhoneTypeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPhoneTypeData tmp;
		_ConvertPbToFPhoneTypeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChargeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChargeData> Datas;

};
static void _ConvertPbToFChargeInfo(FChargeInfo &msg, const msg::ChargeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChargeData tmp;
		_ConvertPbToFChargeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMultiConfigInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMultiConfigData> Datas;

};
static void _ConvertPbToFMultiConfigInfo(FMultiConfigInfo &msg, const msg::MultiConfigInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMultiConfigData tmp;
		_ConvertPbToFMultiConfigData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FModeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FModeData> Datas;

};
static void _ConvertPbToFModeInfo(FModeInfo &msg, const msg::ModeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FModeData tmp;
		_ConvertPbToFModeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FModeSortInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FModeSortData> Datas;

};
static void _ConvertPbToFModeSortInfo(FModeSortInfo &msg, const msg::ModeSortInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FModeSortData tmp;
		_ConvertPbToFModeSortData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPassportLevelInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPassportLevelData> Datas;

};
static void _ConvertPbToFPassportLevelInfo(FPassportLevelInfo &msg, const msg::PassportLevelInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPassportLevelData tmp;
		_ConvertPbToFPassportLevelData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPassportLevelAwardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPassportLevelAwardData> Datas;

};
static void _ConvertPbToFPassportLevelAwardInfo(FPassportLevelAwardInfo &msg, const msg::PassportLevelAwardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPassportLevelAwardData tmp;
		_ConvertPbToFPassportLevelAwardData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPassportInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPassportData> Datas;

};
static void _ConvertPbToFPassportInfo(FPassportInfo &msg, const msg::PassportInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPassportData tmp;
		_ConvertPbToFPassportData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPassportTaskInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPassportTaskData> Datas;

};
static void _ConvertPbToFPassportTaskInfo(FPassportTaskInfo &msg, const msg::PassportTaskInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPassportTaskData tmp;
		_ConvertPbToFPassportTaskData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAchieveTaskInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTaskInfo> Datas;

};
static void _ConvertPbToFAchieveTaskInfo(FAchieveTaskInfo &msg, const msg::AchieveTaskInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTaskInfo tmp;
		_ConvertPbToFTaskInfo(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPassportTypeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPassportTypeData> Datas;

};
static void _ConvertPbToFPassportTypeInfo(FPassportTypeInfo &msg, const msg::PassportTypeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPassportTypeData tmp;
		_ConvertPbToFPassportTypeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FSeasonInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSeasonData> Datas;

};
static void _ConvertPbToFSeasonInfo(FSeasonInfo &msg, const msg::SeasonInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FSeasonData tmp;
		_ConvertPbToFSeasonData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAccountLevelInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLevelData> Datas;

};
static void _ConvertPbToFAccountLevelInfo(FAccountLevelInfo &msg, const msg::AccountLevelInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FLevelData tmp;
		_ConvertPbToFLevelData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FResChessInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FResChessData> Datas;

};
static void _ConvertPbToFResChessInfo(FResChessInfo &msg, const msg::ChessInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FResChessData tmp;
		_ConvertPbToFResChessData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPropInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPropData> Datas;

};
static void _ConvertPbToFPropInfo(FPropInfo &msg, const msg::PropInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPropData tmp;
		_ConvertPbToFPropData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCumulativeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCumulativeData> Datas;

};
static void _ConvertPbToFCumulativeInfo(FCumulativeInfo &msg, const msg::CumulativeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FCumulativeData tmp;
		_ConvertPbToFCumulativeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCondParaphraseInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCondParaphraseData> Datas;

};
static void _ConvertPbToFCondParaphraseInfo(FCondParaphraseInfo &msg, const msg::CondParaphraseInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FCondParaphraseData tmp;
		_ConvertPbToFCondParaphraseData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMeleeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMeleeData> Datas;

};
static void _ConvertPbToFMeleeInfo(FMeleeInfo &msg, const msg::MeleeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMeleeData tmp;
		_ConvertPbToFMeleeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActivityGroupInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActivityGroupData> Datas;

};
static void _ConvertPbToFActivityGroupInfo(FActivityGroupInfo &msg, const msg::ActivityGroupInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FActivityGroupData tmp;
		_ConvertPbToFActivityGroupData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActivityInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActivityData> Datas;

};
static void _ConvertPbToFActivityInfo(FActivityInfo &msg, const msg::ActivityInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FActivityData tmp;
		_ConvertPbToFActivityData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActivityAttrInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActivityAttrData> Datas;

};
static void _ConvertPbToFActivityAttrInfo(FActivityAttrInfo &msg, const msg::ActivityAttrInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FActivityAttrData tmp;
		_ConvertPbToFActivityAttrData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPsActivityInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPsActivity> Datas;

};
static void _ConvertPbToFPsActivityInfo(FPsActivityInfo &msg, const msg::PsActivityInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPsActivity tmp;
		_ConvertPbToFPsActivity(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FLineUpInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLineUpData> Datas;

};
static void _ConvertPbToFLineUpInfo(FLineUpInfo &msg, const msg::LineUpInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FLineUpData tmp;
		_ConvertPbToFLineUpData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGenreInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGenreData> Datas;

};
static void _ConvertPbToFGenreInfo(FGenreInfo &msg, const msg::GenreInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FGenreData tmp;
		_ConvertPbToFGenreData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FEggInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEggData> Datas;

};
static void _ConvertPbToFEggInfo(FEggInfo &msg, const msg::EggInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FEggData tmp;
		_ConvertPbToFEggData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGoodsInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGoodsDetail> Datas;

};
static void _ConvertPbToFGoodsInfo(FGoodsInfo &msg, const msg::GoodsInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FGoodsDetail tmp;
		_ConvertPbToFGoodsDetail(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGoodsRandInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGoodsRandData> Datas;

};
static void _ConvertPbToFGoodsRandInfo(FGoodsRandInfo &msg, const msg::GoodsRandInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FGoodsRandData tmp;
		_ConvertPbToFGoodsRandData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPassportShopInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPassportShopData> Datas;

};
static void _ConvertPbToFPassportShopInfo(FPassportShopInfo &msg, const msg::PassportShopInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPassportShopData tmp;
		_ConvertPbToFPassportShopData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRandChestAwardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRandChestAward> Datas;

};
static void _ConvertPbToFRandChestAwardInfo(FRandChestAwardInfo &msg, const msg::RandChestAwardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRandChestAward tmp;
		_ConvertPbToFRandChestAward(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChannelFunctionInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChannelFunctionData> Datas;

};
static void _ConvertPbToFChannelFunctionInfo(FChannelFunctionInfo &msg, const msg::ChannelFunctionInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChannelFunctionData tmp;
		_ConvertPbToFChannelFunctionData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMallGoodsInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMallGoodsData> Datas;

};
static void _ConvertPbToFMallGoodsInfo(FMallGoodsInfo &msg, const msg::MallGoodsInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMallGoodsData tmp;
		_ConvertPbToFMallGoodsData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMallTabInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMallTabData> Datas;

};
static void _ConvertPbToFMallTabInfo(FMallTabInfo &msg, const msg::MallTabInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMallTabData tmp;
		_ConvertPbToFMallTabData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMallNoticeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMallNoticeData> Datas;

};
static void _ConvertPbToFMallNoticeInfo(FMallNoticeInfo &msg, const msg::MallNoticeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMallNoticeData tmp;
		_ConvertPbToFMallNoticeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAITriggerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAITriggerData> Datas;

};
static void _ConvertPbToFAITriggerInfo(FAITriggerInfo &msg, const msg::AITriggerInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FAITriggerData tmp;
		_ConvertPbToFAITriggerData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAIAssistantInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAIAssistantData> Datas;

};
static void _ConvertPbToFAIAssistantInfo(FAIAssistantInfo &msg, const msg::AIAssistantInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FAIAssistantData tmp;
		_ConvertPbToFAIAssistantData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FDaySignAwardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDaySignAward> Datas;

};
static void _ConvertPbToFDaySignAwardInfo(FDaySignAwardInfo &msg, const msg::DaySignAwardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FDaySignAward tmp;
		_ConvertPbToFDaySignAward(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActDaySignAwardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActDaySignAward> Datas;

};
static void _ConvertPbToFActDaySignAwardInfo(FActDaySignAwardInfo &msg, const msg::ActDaySignAwardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FActDaySignAward tmp;
		_ConvertPbToFActDaySignAward(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActReSignConsumeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActReSignConsume> Datas;

};
static void _ConvertPbToFActReSignConsumeInfo(FActReSignConsumeInfo &msg, const msg::ActReSignConsumeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FActReSignConsume tmp;
		_ConvertPbToFActReSignConsume(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FDynamicTipsInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDynamicTips> Datas;

};
static void _ConvertPbToFDynamicTipsInfo(FDynamicTipsInfo &msg, const msg::DynamicTipsInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FDynamicTips tmp;
		_ConvertPbToFDynamicTips(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMonthShareAwardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMonthShareAward> Datas;

};
static void _ConvertPbToFMonthShareAwardInfo(FMonthShareAwardInfo &msg, const msg::MonthShareAwardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMonthShareAward tmp;
		_ConvertPbToFMonthShareAward(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessShareInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessShareData> Datas;

};
static void _ConvertPbToFChessShareInfo(FChessShareInfo &msg, const msg::ChessShareInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessShareData tmp;
		_ConvertPbToFChessShareData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCountryInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCountryData> Datas;

};
static void _ConvertPbToFCountryInfo(FCountryInfo &msg, const msg::CountryInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FCountryData tmp;
		_ConvertPbToFCountryData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FProvinceInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FProvinceData> Datas;

};
static void _ConvertPbToFProvinceInfo(FProvinceInfo &msg, const msg::ProvinceInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FProvinceData tmp;
		_ConvertPbToFProvinceData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemOutputInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemOutputItem> Datas;

};
static void _ConvertPbToFItemOutputInfo(FItemOutputInfo &msg, const msg::ItemOutputInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FItemOutputItem tmp;
		_ConvertPbToFItemOutputItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemExchangeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemExchangeItem> Datas;

};
static void _ConvertPbToFItemExchangeInfo(FItemExchangeInfo &msg, const msg::ItemExchangeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FItemExchangeItem tmp;
		_ConvertPbToFItemExchangeItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPassportPeriodInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPassportPeriodData> Datas;

};
static void _ConvertPbToFPassportPeriodInfo(FPassportPeriodInfo &msg, const msg::PassportPeriodInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPassportPeriodData tmp;
		_ConvertPbToFPassportPeriodData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGroupPayInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGroupPayItem> Datas;

};
static void _ConvertPbToFGroupPayInfo(FGroupPayInfo &msg, const msg::GroupPayInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FGroupPayItem tmp;
		_ConvertPbToFGroupPayItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCalendarFitAvoidInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FFitAvoidItem> Datas;

};
static void _ConvertPbToFCalendarFitAvoidInfo(FCalendarFitAvoidInfo &msg, const msg::CalendarFitAvoidInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FFitAvoidItem tmp;
		_ConvertPbToFFitAvoidItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FVNGCcyInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVNGCcyItem> Datas;

};
static void _ConvertPbToFVNGCcyInfo(FVNGCcyInfo &msg, const msg::VNGCcyInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FVNGCcyItem tmp;
		_ConvertPbToFVNGCcyItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FVNGExchangeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVNGExchangeItem> Datas;

};
static void _ConvertPbToFVNGExchangeInfo(FVNGExchangeInfo &msg, const msg::VNGExchangeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FVNGExchangeItem tmp;
		_ConvertPbToFVNGExchangeItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FVNGFirstPayInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVNGFirstPayItem> Datas;

};
static void _ConvertPbToFVNGFirstPayInfo(FVNGFirstPayInfo &msg, const msg::VNGFirstPayInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FVNGFirstPayItem tmp;
		_ConvertPbToFVNGFirstPayItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FActReturnRewardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FActReturnRewardItem> Datas;

};
static void _ConvertPbToFActReturnRewardInfo(FActReturnRewardInfo &msg, const msg::ActReturnRewardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FActReturnRewardItem tmp;
		_ConvertPbToFActReturnRewardItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FObserveLevelInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FObserveLevelData> Datas;

};
static void _ConvertPbToFObserveLevelInfo(FObserveLevelInfo &msg, const msg::ObserveLevelInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FObserveLevelData tmp;
		_ConvertPbToFObserveLevelData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FWxVVipRightInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWxVVipRightItem> Datas;

};
static void _ConvertPbToFWxVVipRightInfo(FWxVVipRightInfo &msg, const msg::WxVVipRightInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FWxVVipRightItem tmp;
		_ConvertPbToFWxVVipRightItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGiftInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGiftItem> Datas;

};
static void _ConvertPbToFGiftInfo(FGiftInfo &msg, const msg::GiftInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FGiftItem tmp;
		_ConvertPbToFGiftItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMarqueeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMarqueeItem> Datas;

};
static void _ConvertPbToFMarqueeInfo(FMarqueeInfo &msg, const msg::MarqueeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMarqueeItem tmp;
		_ConvertPbToFMarqueeItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRedPktWeight {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rights;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Up;

};
static void _ConvertPbToFRedPktWeight(FRedPktWeight &msg, const msg::RedPktWeight *pb) {
	msg.Rights=pb->rights();
	msg.Up=pb->up();
}


USTRUCT(BlueprintType)
struct  FRedPacketInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRedPacketItem> Datas;

};
static void _ConvertPbToFRedPacketInfo(FRedPacketInfo &msg, const msg::RedPacketInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRedPacketItem tmp;
		_ConvertPbToFRedPacketItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FWxVVipRankRwdInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWxVVipRankRwdItem> Datas;

};
static void _ConvertPbToFWxVVipRankRwdInfo(FWxVVipRankRwdInfo &msg, const msg::WxVVipRankRwdInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FWxVVipRankRwdItem tmp;
		_ConvertPbToFWxVVipRankRwdItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPunishmentInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPunishmentData> Datas;

};
static void _ConvertPbToFPunishmentInfo(FPunishmentInfo &msg, const msg::PunishmentInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPunishmentData tmp;
		_ConvertPbToFPunishmentData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FQuickChatInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuickChatData> Datas;

};
static void _ConvertPbToFQuickChatInfo(FQuickChatInfo &msg, const msg::QuickChatInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FQuickChatData tmp;
		_ConvertPbToFQuickChatData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FLoadingRankInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLoadingRankData> Datas;

};
static void _ConvertPbToFLoadingRankInfo(FLoadingRankInfo &msg, const msg::LoadingRankInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FLoadingRankData tmp;
		_ConvertPbToFLoadingRankData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FQuestionnaireInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestionnaireData> Datas;

};
static void _ConvertPbToFQuestionnaireInfo(FQuestionnaireInfo &msg, const msg::QuestionnaireInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FQuestionnaireData tmp;
		_ConvertPbToFQuestionnaireData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FQuestionnairePlayerListInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestionnairePlayerList> Datas;

};
static void _ConvertPbToFQuestionnairePlayerListInfo(FQuestionnairePlayerListInfo &msg, const msg::QuestionnairePlayerListInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FQuestionnairePlayerList tmp;
		_ConvertPbToFQuestionnairePlayerList(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FQuestionnaireContentInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestionnaireContent> Datas;

};
static void _ConvertPbToFQuestionnaireContentInfo(FQuestionnaireContentInfo &msg, const msg::QuestionnaireContentInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FQuestionnaireContent tmp;
		_ConvertPbToFQuestionnaireContent(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FResSkillInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FResSkillInfoItem> Datas;

};
static void _ConvertPbToFResSkillInfo(FResSkillInfo &msg, const msg::SkillInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FResSkillInfoItem tmp;
		_ConvertPbToFResSkillInfoItem(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAILevelInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAILevelData> Datas;

};
static void _ConvertPbToFAILevelInfo(FAILevelInfo &msg, const msg::AILevelInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FAILevelData tmp;
		_ConvertPbToFAILevelData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessSkinSeriesInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessSkinSeriesData> Datas;

};
static void _ConvertPbToFChessSkinSeriesInfo(FChessSkinSeriesInfo &msg, const msg::ChessSkinSeriesInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessSkinSeriesData tmp;
		_ConvertPbToFChessSkinSeriesData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FComposeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FComposeData> Datas;

};
static void _ConvertPbToFComposeInfo(FComposeInfo &msg, const msg::ComposeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FComposeData tmp;
		_ConvertPbToFComposeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FVideoConf {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVideoInfo> Datas;

};
static void _ConvertPbToFVideoConf(FVideoConf &msg, const msg::VideoConf *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FVideoInfo tmp;
		_ConvertPbToFVideoInfo(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMoreStrongerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMoreStrongerData> Datas;

};
static void _ConvertPbToFMoreStrongerInfo(FMoreStrongerInfo &msg, const msg::MoreStrongerInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMoreStrongerData tmp;
		_ConvertPbToFMoreStrongerData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAddictionInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAddictionData> Datas;

};
static void _ConvertPbToFAddictionInfo(FAddictionInfo &msg, const msg::AddictionInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FAddictionData tmp;
		_ConvertPbToFAddictionData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAmazonGiftInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAmazonGiftData> Datas;

};
static void _ConvertPbToFAmazonGiftInfo(FAmazonGiftInfo &msg, const msg::AmazonGiftInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FAmazonGiftData tmp;
		_ConvertPbToFAmazonGiftData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FFallInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FFallData> Datas;

};
static void _ConvertPbToFFallInfo(FFallInfo &msg, const msg::FallInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FFallData tmp;
		_ConvertPbToFFallData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCritAddInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCritAddData> Datas;

};
static void _ConvertPbToFCritAddInfo(FCritAddInfo &msg, const msg::CritAddInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FCritAddData tmp;
		_ConvertPbToFCritAddData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNetDelayInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNetDelayData> Datas;

};
static void _ConvertPbToFNetDelayInfo(FNetDelayInfo &msg, const msg::NetDelayInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FNetDelayData tmp;
		_ConvertPbToFNetDelayData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRegionMatchInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRegionMatchData> Datas;

};
static void _ConvertPbToFRegionMatchInfo(FRegionMatchInfo &msg, const msg::RegionMatchInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRegionMatchData tmp;
		_ConvertPbToFRegionMatchData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTournamentInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTournamentData> Datas;

};
static void _ConvertPbToFTournamentInfo(FTournamentInfo &msg, const msg::TournamentInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTournamentData tmp;
		_ConvertPbToFTournamentData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTournamentClassInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTournamentClassData> Datas;

};
static void _ConvertPbToFTournamentClassInfo(FTournamentClassInfo &msg, const msg::TournamentClassInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTournamentClassData tmp;
		_ConvertPbToFTournamentClassData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTournamentRoundInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTournamentRoundData> Datas;

};
static void _ConvertPbToFTournamentRoundInfo(FTournamentRoundInfo &msg, const msg::TournamentRoundInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTournamentRoundData tmp;
		_ConvertPbToFTournamentRoundData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTournamentGamesInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTournamentGamesData> Datas;

};
static void _ConvertPbToFTournamentGamesInfo(FTournamentGamesInfo &msg, const msg::TournamentGamesInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTournamentGamesData tmp;
		_ConvertPbToFTournamentGamesData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTournamentAwardsInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTournamentAwardsData> Datas;

};
static void _ConvertPbToFTournamentAwardsInfo(FTournamentAwardsInfo &msg, const msg::TournamentAwardsInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTournamentAwardsData tmp;
		_ConvertPbToFTournamentAwardsData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FVideoCGInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVideoCGData> Datas;

};
static void _ConvertPbToFVideoCGInfo(FVideoCGInfo &msg, const msg::VideoCGInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FVideoCGData tmp;
		_ConvertPbToFVideoCGData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FEntranceNotice {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEntranceNoticeData> Datas;

};
static void _ConvertPbToFEntranceNotice(FEntranceNotice &msg, const msg::EntranceNotice *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FEntranceNoticeData tmp;
		_ConvertPbToFEntranceNoticeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChatHistoryMessage {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChatHistoryMessageData> Datas;

};
static void _ConvertPbToFChatHistoryMessage(FChatHistoryMessage &msg, const msg::ChatHistoryMessage *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChatHistoryMessageData tmp;
		_ConvertPbToFChatHistoryMessageData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FABTestInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FABTestData> Datas;

};
static void _ConvertPbToFABTestInfo(FABTestInfo &msg, const msg::ABTestInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FABTestData tmp;
		_ConvertPbToFABTestData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FObserveScoreInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FObserveScoreData> Datas;

};
static void _ConvertPbToFObserveScoreInfo(FObserveScoreInfo &msg, const msg::ObserveScoreInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FObserveScoreData tmp;
		_ConvertPbToFObserveScoreData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FObserveTaskInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FObserveTaskData> Datas;

};
static void _ConvertPbToFObserveTaskInfo(FObserveTaskInfo &msg, const msg::ObserveTaskInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FObserveTaskData tmp;
		_ConvertPbToFObserveTaskData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FCommunityRedirection {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCommunityRedirectionData> Datas;

};
static void _ConvertPbToFCommunityRedirection(FCommunityRedirection &msg, const msg::CommunityRedirection *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FCommunityRedirectionData tmp;
		_ConvertPbToFCommunityRedirectionData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FSteamRoport {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSteamRoportData> Datas;

};
static void _ConvertPbToFSteamRoport(FSteamRoport &msg, const msg::SteamRoport *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FSteamRoportData tmp;
		_ConvertPbToFSteamRoportData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FSteamMapLanguage {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSteamMapLanguageData> Datas;

};
static void _ConvertPbToFSteamMapLanguage(FSteamMapLanguage &msg, const msg::SteamMapLanguage *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FSteamMapLanguageData tmp;
		_ConvertPbToFSteamMapLanguageData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChestLevelupInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChestLevelupData> Datas;

};
static void _ConvertPbToFChestLevelupInfo(FChestLevelupInfo &msg, const msg::ChestLevelupInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChestLevelupData tmp;
		_ConvertPbToFChestLevelupData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FFunctionUnlockInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FFunctionUnlockData> Datas;

};
static void _ConvertPbToFFunctionUnlockInfo(FFunctionUnlockInfo &msg, const msg::FunctionUnlockInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FFunctionUnlockData tmp;
		_ConvertPbToFFunctionUnlockData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAdvertiseInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAdvertiseData> Datas;

};
static void _ConvertPbToFAdvertiseInfo(FAdvertiseInfo &msg, const msg::AdvertiseInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FAdvertiseData tmp;
		_ConvertPbToFAdvertiseData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGuildCommonInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FConsume CreateGuildConsume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FConsume GuildRenameConsume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FConsume ChangePatternConsume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GuildRenameCd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChangePatternCd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxAnnouncement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxRecruit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EITEMQUALITY ShowLowestItemQuality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RejoinCd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxApplyMessage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxApplyMessageTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxInvitationMessage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxInvitationMessageTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AteventJurisdiction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ViceAteventJurisdiction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ManagerJurisdiction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MemberJurisdiction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OncePullLog;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxLogStorage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int OncePullList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxRecommendPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AteventCriticalDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowRank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ShowSeasonPass;

};
static void _ConvertPbToFGuildCommonInfo(FGuildCommonInfo &msg, const msg::GuildCommonInfo *pb) {
	_ConvertPbToFConsume(msg.CreateGuildConsume, &pb->createguildconsume());
	_ConvertPbToFConsume(msg.GuildRenameConsume, &pb->guildrenameconsume());
	_ConvertPbToFConsume(msg.ChangePatternConsume, &pb->changepatternconsume());
	msg.GuildRenameCd=pb->guildrenamecd();
	msg.ChangePatternCd=pb->changepatterncd();
	msg.MaxAnnouncement=pb->maxannouncement();
	msg.MaxRecruit=pb->maxrecruit();
	msg.ShowLowestItemQuality=(EITEMQUALITY)pb->showlowestitemquality();
	msg.ShowItemType=UTF8_TO_TCHAR(pb->showitemtype().c_str());
	msg.RejoinCd=pb->rejoincd();
	msg.MaxApplyMessage=pb->maxapplymessage();
	msg.MaxApplyMessageTime=pb->maxapplymessagetime();
	msg.MaxInvitationMessage=pb->maxinvitationmessage();
	msg.MaxInvitationMessageTime=pb->maxinvitationmessagetime();
	msg.AteventJurisdiction=UTF8_TO_TCHAR(pb->ateventjurisdiction().c_str());
	msg.ViceAteventJurisdiction=UTF8_TO_TCHAR(pb->viceateventjurisdiction().c_str());
	msg.ManagerJurisdiction=UTF8_TO_TCHAR(pb->managerjurisdiction().c_str());
	msg.MemberJurisdiction=UTF8_TO_TCHAR(pb->memberjurisdiction().c_str());
	msg.OncePullLog=pb->oncepulllog();
	msg.MaxLogStorage=pb->maxlogstorage();
	msg.OncePullList=pb->oncepulllist();
	msg.MaxRecommendPlayer=pb->maxrecommendplayer();
	msg.AteventCriticalDay=pb->ateventcriticalday();
	msg.ShowRank=UTF8_TO_TCHAR(pb->showrank().c_str());
	msg.ShowSeasonPass=UTF8_TO_TCHAR(pb->showseasonpass().c_str());
}


USTRUCT(BlueprintType)
struct  FGuildLevelInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildLevelData> Datas;

};
static void _ConvertPbToFGuildLevelInfo(FGuildLevelInfo &msg, const msg::GuildLevelInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FGuildLevelData tmp;
		_ConvertPbToFGuildLevelData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FGuildTagInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGuildTagData> Datas;

};
static void _ConvertPbToFGuildTagInfo(FGuildTagInfo &msg, const msg::GuildTagInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FGuildTagData tmp;
		_ConvertPbToFGuildTagData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRepriceRandChest {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRepriceRandChestData> Datas;

};
static void _ConvertPbToFRepriceRandChest(FRepriceRandChest &msg, const msg::RepriceRandChest *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRepriceRandChestData tmp;
		_ConvertPbToFRepriceRandChestData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTasks {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTaskInfo> Data;

};
static void _ConvertPbToFTasks(FTasks &msg, const msg::Tasks *pb) {
	for (int i = 0; i < pb->data().size(); i++) {
		auto &a = pb->data().Get(i);
		FTaskInfo tmp;
		_ConvertPbToFTaskInfo(tmp, &a);
		msg.Data.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTeachPassInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTeachPassData> Datas;

};
static void _ConvertPbToFTeachPassInfo(FTeachPassInfo &msg, const msg::TeachPassInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTeachPassData tmp;
		_ConvertPbToFTeachPassData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTeachCapterInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTeachCapterData> Datas;

};
static void _ConvertPbToFTeachCapterInfo(FTeachCapterInfo &msg, const msg::TeachCapterInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTeachCapterData tmp;
		_ConvertPbToFTeachCapterData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FBigWinnerSeasonInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBigWinnerSeasonData> Datas;

};
static void _ConvertPbToFBigWinnerSeasonInfo(FBigWinnerSeasonInfo &msg, const msg::BigWinnerSeasonInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FBigWinnerSeasonData tmp;
		_ConvertPbToFBigWinnerSeasonData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FBigWinnerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBigWinnerData> Datas;

};
static void _ConvertPbToFBigWinnerInfo(FBigWinnerInfo &msg, const msg::BigWinnerInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FBigWinnerData tmp;
		_ConvertPbToFBigWinnerData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FBigWinnerCommonInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ScoreRule;	//积分规则

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RoundRule;	//场次规则

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DailyAward;	//低保积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DailyAwardLimit;	//低保积分限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AddSource;	//附赠来源

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyAddRate;	//糖果附赠积分比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DiamondAddRate;	//甜甜圈附赠积分比例

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoneyMallId;	//糖果商品ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DiamondMallId;	//甜甜圈商品ID

};
static void _ConvertPbToFBigWinnerCommonInfo(FBigWinnerCommonInfo &msg, const msg::BigWinnerCommonInfo *pb) {
	msg.ScoreRule=UTF8_TO_TCHAR(pb->scorerule().c_str());
	msg.RoundRule=UTF8_TO_TCHAR(pb->roundrule().c_str());
	msg.DailyAward=pb->dailyaward();
	msg.DailyAwardLimit=pb->dailyawardlimit();
	msg.AddSource=UTF8_TO_TCHAR(pb->addsource().c_str());
	msg.MoneyAddRate=pb->moneyaddrate();
	msg.DiamondAddRate=pb->diamondaddrate();
	msg.MoneyMallId=pb->moneymallid();
	msg.DiamondMallId=pb->diamondmallid();
}


USTRUCT(BlueprintType)
struct  FMultiMailFileInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMultiMailFile> Datas;

};
static void _ConvertPbToFMultiMailFileInfo(FMultiMailFileInfo &msg, const msg::MultiMailFileInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMultiMailFile tmp;
		_ConvertPbToFMultiMailFile(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMultiMailDataInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMultiMailData> Datas;

};
static void _ConvertPbToFMultiMailDataInfo(FMultiMailDataInfo &msg, const msg::MultiMailDataInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMultiMailData tmp;
		_ConvertPbToFMultiMailData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPCPhoneUIContrastInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPCPhoneUIContrast> Data;

};
static void _ConvertPbToFPCPhoneUIContrastInfo(FPCPhoneUIContrastInfo &msg, const msg::PCPhoneUIContrastInfo *pb) {
	for (int i = 0; i < pb->data().size(); i++) {
		auto &a = pb->data().Get(i);
		FPCPhoneUIContrast tmp;
		_ConvertPbToFPCPhoneUIContrast(tmp, &a);
		msg.Data.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessStoryInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessStoryData> Datas;

};
static void _ConvertPbToFChessStoryInfo(FChessStoryInfo &msg, const msg::ChessStoryInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessStoryData tmp;
		_ConvertPbToFChessStoryData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMedalList {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMedal> Datas;

};
static void _ConvertPbToFMedalList(FMedalList &msg, const msg::MedalList *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMedal tmp;
		_ConvertPbToFMedal(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPuzzleActivityInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPuzzleActivity> Datas;

};
static void _ConvertPbToFPuzzleActivityInfo(FPuzzleActivityInfo &msg, const msg::PuzzleActivityInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPuzzleActivity tmp;
		_ConvertPbToFPuzzleActivity(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNormalOutPutInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNormalOutPut> Datas;

};
static void _ConvertPbToFNormalOutPutInfo(FNormalOutPutInfo &msg, const msg::NormalOutPutInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FNormalOutPut tmp;
		_ConvertPbToFNormalOutPut(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNormalTextPool {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNormalText> Datas;

};
static void _ConvertPbToFNormalTextPool(FNormalTextPool &msg, const msg::NormalTextPool *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FNormalText tmp;
		_ConvertPbToFNormalText(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNewPlayerModeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNewPlayerModeData> Datas;

};
static void _ConvertPbToFNewPlayerModeInfo(FNewPlayerModeInfo &msg, const msg::NewPlayerModeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FNewPlayerModeData tmp;
		_ConvertPbToFNewPlayerModeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FTeachModeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTeachModeData> Datas;

};
static void _ConvertPbToFTeachModeInfo(FTeachModeInfo &msg, const msg::TeachModeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FTeachModeData tmp;
		_ConvertPbToFTeachModeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPveChallengeInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPveChallengeData> Datas;

};
static void _ConvertPbToFPveChallengeInfo(FPveChallengeInfo &msg, const msg::PveChallengeInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPveChallengeData tmp;
		_ConvertPbToFPveChallengeData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FConsumeToken {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

};
static void _ConvertPbToFConsumeToken(FConsumeToken &msg, const msg::ConsumeToken *pb) {
	msg.ID=pb->id();
	msg.Count=pb->count();
}


USTRUCT(BlueprintType)
struct  FPVERankInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPVERankData> Datas;

};
static void _ConvertPbToFPVERankInfo(FPVERankInfo &msg, const msg::PVERankInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPVERankData tmp;
		_ConvertPbToFPVERankData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPVETalentInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPVETalentData> Datas;

};
static void _ConvertPbToFPVETalentInfo(FPVETalentInfo &msg, const msg::PVETalentInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPVETalentData tmp;
		_ConvertPbToFPVETalentData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRandDiscoutData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRandDiscoutDatum> Datas;

};
static void _ConvertPbToFRandDiscoutData(FRandDiscoutData &msg, const msg::RandDiscoutData *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRandDiscoutDatum tmp;
		_ConvertPbToFRandDiscoutDatum(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FReturnGuidData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FReturnGuid> Datas;

};
static void _ConvertPbToFReturnGuidData(FReturnGuidData &msg, const msg::ReturnGuidData *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FReturnGuid tmp;
		_ConvertPbToFReturnGuid(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemCommentData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemComment> Datas;

};
static void _ConvertPbToFItemCommentData(FItemCommentData &msg, const msg::ItemCommentData *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FItemComment tmp;
		_ConvertPbToFItemComment(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FSmeltAwardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSmeltAwardData> Datas;

};
static void _ConvertPbToFSmeltAwardInfo(FSmeltAwardInfo &msg, const msg::SmeltAwardInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FSmeltAwardData tmp;
		_ConvertPbToFSmeltAwardData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessSkinRelationInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessSkinRelationData> Datas;

};
static void _ConvertPbToFChessSkinRelationInfo(FChessSkinRelationInfo &msg, const msg::ChessSkinRelationInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessSkinRelationData tmp;
		_ConvertPbToFChessSkinRelationData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRankRepeatedAwardInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CupMax;	//最高有效段位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinRound;	//最低连胜场次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StartPoint;	//起始加成分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BonusPoint;	//连胜叠加分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExtraCount;	//叠加有效场次

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModeSupport;	//支持模式

};
static void _ConvertPbToFRankRepeatedAwardInfo(FRankRepeatedAwardInfo &msg, const msg::RankRepeatedAwardInfo *pb) {
	msg.CupMax=pb->cupmax();
	msg.MinRound=pb->minround();
	msg.StartPoint=pb->startpoint();
	msg.BonusPoint=pb->bonuspoint();
	msg.ExtraCount=pb->extracount();
	msg.ModeSupport=UTF8_TO_TCHAR(pb->modesupport().c_str());
}


USTRUCT(BlueprintType)
struct  FRandPickUpPoolInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRandPickUpPoolData> Datas;

};
static void _ConvertPbToFRandPickUpPoolInfo(FRandPickUpPoolInfo &msg, const msg::RandPickUpPoolInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FRandPickUpPoolData tmp;
		_ConvertPbToFRandPickUpPoolData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemAffixInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemAffixData> Datas;

};
static void _ConvertPbToFItemAffixInfo(FItemAffixInfo &msg, const msg::ItemAffixInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FItemAffixData tmp;
		_ConvertPbToFItemAffixData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemIdentifyInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConsume> ActiveIdentify;	// 手动鉴定消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString IdentifyAttributeList;	// 鉴定属性列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FIdentifyItemTypeAttrPair> IdentifyItem;	// 物品类型属性支持列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FConsume ConsumeItemAffixSaver;	// 物品词缀封存消耗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAward ConsumeItemAffixCover;	// 物品词缀封存奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ChessSeriesSkinSuffixName;	// 棋子皮肤系列星级后缀

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemIdentifyQuality> Quality;	// 物品磨损度品质关系

};
static void _ConvertPbToFItemIdentifyInfo(FItemIdentifyInfo &msg, const msg::ItemIdentifyInfo *pb) {
	for (int i = 0; i < pb->activeidentify().size(); i++) {
		auto &a = pb->activeidentify().Get(i);
		FConsume tmp;
		_ConvertPbToFConsume(tmp, &a);
		msg.ActiveIdentify.Add(tmp);
	}
	msg.IdentifyAttributeList=UTF8_TO_TCHAR(pb->identifyattributelist().c_str());
	for (int i = 0; i < pb->identifyitem().size(); i++) {
		auto &a = pb->identifyitem().Get(i);
		FIdentifyItemTypeAttrPair tmp;
		_ConvertPbToFIdentifyItemTypeAttrPair(tmp, &a);
		msg.IdentifyItem.Add(tmp);
	}
	_ConvertPbToFConsume(msg.ConsumeItemAffixSaver, &pb->consumeitemaffixsaver());
	_ConvertPbToFAward(msg.ConsumeItemAffixCover, &pb->consumeitemaffixcover());
	for (int i = 0; i < pb->chessseriesskinsuffixname().size(); i++) {
		auto &a = pb->chessseriesskinsuffixname().Get(i);
		FString tmp;
		tmp=UTF8_TO_TCHAR(a.c_str());
		msg.ChessSeriesSkinSuffixName.Add(tmp);
	}
	for (int i = 0; i < pb->quality().size(); i++) {
		auto &a = pb->quality().Get(i);
		FItemIdentifyQuality tmp;
		_ConvertPbToFItemIdentifyQuality(tmp, &a);
		msg.Quality.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemIdentifyRandPoolRelationInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemIdentifyRandPoolRelationData> Datas;

};
static void _ConvertPbToFItemIdentifyRandPoolRelationInfo(FItemIdentifyRandPoolRelationInfo &msg, const msg::ItemIdentifyRandPoolRelationInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FItemIdentifyRandPoolRelationData tmp;
		_ConvertPbToFItemIdentifyRandPoolRelationData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FItemPublishNumberInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemPublishNumberData> Datas;

};
static void _ConvertPbToFItemPublishNumberInfo(FItemPublishNumberInfo &msg, const msg::ItemPublishNumberInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FItemPublishNumberData tmp;
		_ConvertPbToFItemPublishNumberData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FNoviceAnswerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNoviceAnswerData> Datas;

};
static void _ConvertPbToFNoviceAnswerInfo(FNoviceAnswerInfo &msg, const msg::NoviceAnswerInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FNoviceAnswerData tmp;
		_ConvertPbToFNoviceAnswerData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessDestinyInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessDestinyData> Datas;

};
static void _ConvertPbToFChessDestinyInfo(FChessDestinyInfo &msg, const msg::ChessDestinyInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessDestinyData tmp;
		_ConvertPbToFChessDestinyData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FDynamicResourceInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDynamicResourceData> Datas;

};
static void _ConvertPbToFDynamicResourceInfo(FDynamicResourceInfo &msg, const msg::DynamicResourceInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FDynamicResourceData tmp;
		_ConvertPbToFDynamicResourceData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FDynamicHeadDataInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDynamicHeadData> Datas;

};
static void _ConvertPbToFDynamicHeadDataInfo(FDynamicHeadDataInfo &msg, const msg::DynamicHeadDataInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FDynamicHeadData tmp;
		_ConvertPbToFDynamicHeadData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FAuctionInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAuctionData> Datas;

};
static void _ConvertPbToFAuctionInfo(FAuctionInfo &msg, const msg::AuctionInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FAuctionData tmp;
		_ConvertPbToFAuctionData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPveInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPveData> Datas;

};
static void _ConvertPbToFPveInfo(FPveInfo &msg, const msg::PveInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPveData tmp;
		_ConvertPbToFPveData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPveChessInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPveChessData> Datas;

};
static void _ConvertPbToFPveChessInfo(FPveChessInfo &msg, const msg::PveChessInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPveChessData tmp;
		_ConvertPbToFPveChessData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPveSkillInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPveSkillData> Datas;

};
static void _ConvertPbToFPveSkillInfo(FPveSkillInfo &msg, const msg::PveSkillInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPveSkillData tmp;
		_ConvertPbToFPveSkillData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPveBuffInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPveBuffData> Datas;

};
static void _ConvertPbToFPveBuffInfo(FPveBuffInfo &msg, const msg::PveBuffInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPveBuffData tmp;
		_ConvertPbToFPveBuffData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FPvpTaskInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPvpTaskData> Datas;

};
static void _ConvertPbToFPvpTaskInfo(FPvpTaskInfo &msg, const msg::PvpTaskInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FPvpTaskData tmp;
		_ConvertPbToFPvpTaskData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessSetSlotInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessSetSlotData> Datas;

};
static void _ConvertPbToFChessSetSlotInfo(FChessSetSlotInfo &msg, const msg::ChessSetSlotInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessSetSlotData tmp;
		_ConvertPbToFChessSetSlotData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessInitDeckInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessInitDeckData> Datas;

};
static void _ConvertPbToFChessInitDeckInfo(FChessInitDeckInfo &msg, const msg::ChessInitDeckInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessInitDeckData tmp;
		_ConvertPbToFChessInitDeckData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FChessFetterLimitInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChessFetterLimitData> Datas;

};
static void _ConvertPbToFChessFetterLimitInfo(FChessFetterLimitInfo &msg, const msg::ChessFetterLimitInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FChessFetterLimitData tmp;
		_ConvertPbToFChessFetterLimitData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FMentorShipData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorShipReach> MentorReach;	//师傅达成条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorShipReach> PupilReach;	//徒弟达成条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> GraduateAwards;	//徒弟出师获取得奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorPunish> Punish;	//解除关系惩罚

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PageLimit;	//推荐列表分页

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ListNum;	// 师傅/徒弟  推荐列表 数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ListRandNum;	// 师傅推荐列表 随机玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorLevel> MentorLevel;	// 师傅等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorShipTag> MentorShipTag;	// 玩家标签

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorAddn> MentorAddn;	//加成系数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MentorInviteLimit;	//师傅 每日 邀请 次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MentorTextMaxLen;	// 师徒所有文本长度限制

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AutoGraduateConfirmHour;	// 策划要配小时 我搞不定 自己算吧

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InviteMsgSurvive;	//邀请信息存活时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GraduateNumLimit;	//毕业人数 存储上线

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ActiveAddRecommendTime;	//上榜活跃时间 天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAward> MentorGraduateAwards;	//师傅出师获取得奖励

	int64 IntimacyUpdateFrequency;	//亲密度时间增加

	int64 IntimacyUpdateValue;	//亲密度时间比率

	int64 IntimacyLimit;	//亲密度上限

};
static void _ConvertPbToFMentorShipData(FMentorShipData &msg, const msg::MentorShipData *pb) {
	for (int i = 0; i < pb->mentorreach().size(); i++) {
		auto &a = pb->mentorreach().Get(i);
		FMentorShipReach tmp;
		_ConvertPbToFMentorShipReach(tmp, &a);
		msg.MentorReach.Add(tmp);
	}
	for (int i = 0; i < pb->pupilreach().size(); i++) {
		auto &a = pb->pupilreach().Get(i);
		FMentorShipReach tmp;
		_ConvertPbToFMentorShipReach(tmp, &a);
		msg.PupilReach.Add(tmp);
	}
	for (int i = 0; i < pb->graduateawards().size(); i++) {
		auto &a = pb->graduateawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.GraduateAwards.Add(tmp);
	}
	for (int i = 0; i < pb->punish().size(); i++) {
		auto &a = pb->punish().Get(i);
		FMentorPunish tmp;
		_ConvertPbToFMentorPunish(tmp, &a);
		msg.Punish.Add(tmp);
	}
	msg.PageLimit=pb->pagelimit();
	msg.ListNum=pb->listnum();
	msg.ListRandNum=pb->listrandnum();
	for (int i = 0; i < pb->mentorlevel().size(); i++) {
		auto &a = pb->mentorlevel().Get(i);
		FMentorLevel tmp;
		_ConvertPbToFMentorLevel(tmp, &a);
		msg.MentorLevel.Add(tmp);
	}
	for (int i = 0; i < pb->mentorshiptag().size(); i++) {
		auto &a = pb->mentorshiptag().Get(i);
		FMentorShipTag tmp;
		_ConvertPbToFMentorShipTag(tmp, &a);
		msg.MentorShipTag.Add(tmp);
	}
	for (int i = 0; i < pb->mentoraddn().size(); i++) {
		auto &a = pb->mentoraddn().Get(i);
		FMentorAddn tmp;
		_ConvertPbToFMentorAddn(tmp, &a);
		msg.MentorAddn.Add(tmp);
	}
	msg.MentorInviteLimit=pb->mentorinvitelimit();
	msg.MentorTextMaxLen=pb->mentortextmaxlen();
	msg.AutoGraduateConfirmHour=pb->autograduateconfirmhour();
	msg.InviteMsgSurvive=pb->invitemsgsurvive();
	msg.GraduateNumLimit=pb->graduatenumlimit();
	msg.ActiveAddRecommendTime=pb->activeaddrecommendtime();
	for (int i = 0; i < pb->mentorgraduateawards().size(); i++) {
		auto &a = pb->mentorgraduateawards().Get(i);
		FAward tmp;
		_ConvertPbToFAward(tmp, &a);
		msg.MentorGraduateAwards.Add(tmp);
	}
	msg.IntimacyUpdateFrequency=pb->intimacyupdatefrequency();
	msg.IntimacyUpdateValue=pb->intimacyupdatevalue();
	msg.IntimacyLimit=pb->intimacylimit();
}


USTRUCT(BlueprintType)
struct  FMentorShipTaskInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMentorShipTaskData> Datas;

};
static void _ConvertPbToFMentorShipTaskInfo(FMentorShipTaskInfo &msg, const msg::MentorShipTaskInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FMentorShipTaskData tmp;
		_ConvertPbToFMentorShipTaskData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FRuleInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRuleData> Data;

};
static void _ConvertPbToFRuleInfo(FRuleInfo &msg, const msg::RuleInfo *pb) {
	for (int i = 0; i < pb->data().size(); i++) {
		auto &a = pb->data().Get(i);
		FRuleData tmp;
		_ConvertPbToFRuleData(tmp, &a);
		msg.Data.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FLyActivityLimitInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLyActivityLimit> Datas;

};
static void _ConvertPbToFLyActivityLimitInfo(FLyActivityLimitInfo &msg, const msg::LyActivityLimitInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FLyActivityLimit tmp;
		_ConvertPbToFLyActivityLimit(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FWebUrlInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWebUrlData> Datas;

};
static void _ConvertPbToFWebUrlInfo(FWebUrlInfo &msg, const msg::WebUrlInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FWebUrlData tmp;
		_ConvertPbToFWebUrlData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


USTRUCT(BlueprintType)
struct  FBoardExclusiveSoundInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBoardExclusiveSoundData> Datas;

};
static void _ConvertPbToFBoardExclusiveSoundInfo(FBoardExclusiveSoundInfo &msg, const msg::BoardExclusiveSoundInfo *pb) {
	for (int i = 0; i < pb->datas().size(); i++) {
		auto &a = pb->datas().Get(i);
		FBoardExclusiveSoundData tmp;
		_ConvertPbToFBoardExclusiveSoundData(tmp, &a);
		msg.Datas.Add(tmp);
	}
}


