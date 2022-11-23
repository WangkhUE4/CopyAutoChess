/*
Proto buf => BP

*/
#pragma once


#include "CoreMinimal.h"
#include "csprotocol.pb.h"
#include "common.h"
#include "common.pb.h"
#include "result.h"
#include "result.pb.h"
#include "battle.h"
#include "battle.pb.h"
#include "csprotocolstruct.h"
#include "csprotocolstruct.pb.h"
#include "towerdefense.h"
#include "towerdefense.pb.h"
#include "csprotocol.generated.h"


enum class ECSMsgID: int32 {
	CS_REQ_BEGIN = 0,	//保留
	REQ_HEART = 1,	//心跳包
	REQ_LOGIN = 2,	//登陆请求
	REQ_VERSION_CHECK = 3,	//版本检查
	REQ_RESOURCE_VERSION_CHECK = 4,	//资源版本检测
	REQ_APPLY_HALL_SERVER = 5,
	REQ_GET_NUM_RANK = 6,
	REQ_WORLD_CHAT = 7,
	REQ_PLAYERS_BASE_INFO = 8,	//玩家基础信息
	REQ_PLAYER_DETAIL_INFO = 9,	//玩家详细信息
	REQ_READ_MAIL = 10,	//读邮件
	REQ_GET_MAIL_AWARD = 11,	//领取邮件奖励
	REQ_BUY_EGG = 12,	//购买扭蛋
	REQ_USERNAME_SET = 13,	//设置用户名
	REQ_USERNAME_RANDOM = 14,	//随机用户名
	REQ_HEADPIC_SET = 15,	//设置头像
	REQ_PVP = 16,	//pvp请求
	REQ_PVP_MATCH_CANCEL = 17,	//取消匹配
	REQ_DRESS_CHESS_PLAYER = 18,	//
	REQ_DRESS_SCENE = 19,	//
	REQ_PVP_LOGIN = 20,	//pvp服登陆请求
	REQ_PVP_SEQS = 21,
	REQ_PVP_PLAYER_READY = 22,
	REQ_PVP_CLIENT_READY = 23,
	REQ_REP_PVP_ACTION = 24,
	REQ_PVP_END = 25,
	REQ_PLAYER_FINISH = 26,
	REQ_PLAYER_QUIT = 27,
	REQ_SELL_ITEM = 28,	//出售物品
	REQ_GET_EVAL_AWARD = 29,
	REQ_USE_CHESS_PLAYER = 30,
	REQ_GUID_REPORT = 31,
	REQ_GET_CODE_AWARD = 32,
	REQ_ROUND_REPORT = 33,
	REQ_LOADING_PROGRESS = 34,
	REQ_PVP_CHAT = 35,
	REQ_CHESS_COMBINE = 36,	//棋子合成
	REQ_EXPOSE = 37,	// 举报
	REQ_APPLY_ORDER_ID = 38,	//申请订单Id
	REQ_REPORT_ORDER_INFO = 39,	//上报订单信息
	REQ_SET_ITEM = 40,	//配置物品
	REQ_UNSET_ITEM = 41,	//取消配置物品
	REQ_RANDOM_ITEM = 42,	//请求随机物品
	REQ_CHAT = 43,	//聊天
	REQ_SET_CHESS_PLAYER = 44,	//配置棋手相关属性
	REQ_UNSET_CHESS_PLAYER = 45,	//取消配置棋手相关属性
	REQ_GET_FANS_LIST = 46,	//获取粉丝列表
	REQ_FOLLOW_PLAYER = 47,	//关注玩家
	REQ_UNFOLLOW_PLAYER = 48,	//取消关注玩家
	REQ_PLAYERS_STATUS_INFO = 49,
	REQ_INVITE_JOIN_TEAM = 50,
	REQ_JOIN_TEAM = 51,	//请求加入队伍
	REQ_LEAVE_TEAM = 52,	//请求离开队伍
	REQ_KICKOFF_TEAM_PLAYER = 53,	//请求剔除队伍队员
	REQ_TEAM_MSG = 54,	//请求队伍聊天
	REQ_TEAM_READY = 55,	//队伍成员准备
	REQ_REJECT_JOIN_TEAM = 56,	//拒绝加入队伍
	REQ_REPORT_PAY_RESPONSE = 57,	//上报支付回执信息
	REQ_SHIELD_CHAT = 58,	//私聊屏蔽
	REQ_BUY_PASSPORT_LEVEL = 59,	//购买通行证等级
	REQ_UPGRADE_PASSPORT = 60,	//升级通行证
	REQ_GET_PASSPORT_LEVEL_AWARD = 61,	//获取通行证等级奖励
	REQ_GET_PASSPORT_TASK_AWARD = 62,	//获取通行证任务奖励
	REQ_TEL_BOOK = 63,	//通讯录
	REQ_ACTIVATE_PASSPORT = 64,	//激活通行证
	REQ_RANKSEASON_EVAL = 65,
	REQ_BIND_ACCOUNT = 66,
	REQ_INCREASE_AD_SHOW_COUNT = 67,	//增加loading广告浏览次数
	REQ_USE_BONUS_CARD = 68,	//使用加成卡
	REQ_GET_SEASON_AWARD = 69,
	REQ_GET_ALPHA_ACTIVITY_AWARD = 70,
	REQ_GET_LANGUAGE_DATA = 71,
	REQ_GET_ACTIVITY_AWARD = 72,	//获取活动奖励
	REQ_GET_ACTIVITY_DATA = 73,	//获取活动数据
	REQ_SEND_SMS = 74,	//发短信
	REQ_GET_MELEE_AWARD = 75,
	REQ_ADD_AI_TO_TEAM = 76,
	REQ_SHARE = 77,	//玩家分享通知
	REQ_SKIP_INTERFACE = 78,	//跳转界面
	REQ_TEAM_GAME = 79,
	REQ_SET_TEAM_MODE = 80,
	REQ_SET_HITORY_PVP_SHOW_PERMISSION = 81,	//设置历史战绩查看权限
	REQ_SEARCH_TEAM = 82,
	REQ_APPLY_CHAT = 83,
	REQ_CHAT_LOGIN = 84,
	REQ_PROBE_NET_DELAY = 85,
	REQ_GET_EGGS = 86,	//获取商店展示商品
	REQ_BUY_GOODS = 87,	//购买特价礼包
	REQ_EXCHANGE_PASSPORT_GOODS = 88,	//兑换通行证商品
	REQ_USE_PASSPORT_TASK_CARD = 89,	//使用任务卡
	REQ_OPEN_RAND_CHEST = 90,	//打开随机宝箱, 自选宝箱
	REQ_EGG_LOTTERY = 91,	//扭蛋抽奖
	REQ_QUERY_DIAMOND_BALANCE = 92,
	REQ_USE_ITEM = 93,	//使用道具
	REQ_USE_EXPERIENCE_CARD = 94,
	REQ_RAND_TARGET_ITEM = 95,
	REQ_ADD_BLACKLIST = 96,	//添加黑名单
	REQ_REMOVE_BLACKLIST = 97,	//删除黑名单
	REQ_REPORT_PLAYER_BIRTH = 98,	//上报玩家出生年月
	REQ_REPORT_INFO_INPUT = 99,	//上报玩家信息录入
	REQ_SEND_VERIFICATION_CODE = 100,	//发送验证码
	REQ_BIND_PHONE_NUMBER = 101,	//绑定手机号
	REQ_WORLD_INVITE = 102,	//邀约
	REQ_REMOVE_EXPIRE_ITEM = 103,
	REQ_GET_MALL_GOODS = 104,	//请求获取商品信息
	REQ_BUY_MALL_GOODS = 105,	//购买商城商品
	REQ_BIND_SHARING_CODE = 106,	//绑定分享码
	REQ_WX_BLESS_BAG = 107,
	REQ_UPDATE_FRIENDS_INGAME = 108,	//更新同玩好友人数
	REQ_SHARE_REWARD = 109,
	REQ_ALLFIGHT_INFO = 110,	//获取全民对局信息
	REQ_GET_OLD_PLAYER = 111,	//获取老账号
	REQ_BIND_OLD_PLAYER = 112,	//绑定老账号
	REQ_SEND_VERIFICATION_CODE_WITH_CHECK_REDIS = 113,	//发送验证码(获取老账号)
	REQ_REPORT_SETTING = 114,
	REQ_ANTI_DATA = 115,	//安全sdk anti通知消息
	REQ_TLOG_DATA = 116,	//tlog通知消息
	REQ_DAY_SIGN = 117,	//签到
	REQ_DAY_FIT_AVOID = 118,	//上报每日宜忌
	REQ_SHARE_COUNT_AWARD = 119,	//领取每月累计分享奖励
	REQ_ACT_ITEM_EXCH = 120,	//集道具兑换活动 兑换请求
	REQ_REALATION_STAR = 121,	//关系链幸运星邀请
	REQ_GET_REALATION_STAR_INVITE_SUCC = 122,	//获取关系链幸运星邀请成功列表
	REQ_GET_REALATION_STAR = 123,	//获取关系链幸运星邀请列表
	REQ_GET_ACT_RECORD = 124,	//获取活动记录
	REQ_JOIN_VOICE_TEAM = 125,	//加入team语音房间
	REQ_JOIN_VOICE_PVP = 126,	//加入pvp语音房间
	REQ_JOIN_VOICE_CAMP = 127,	//加入camp语音房间
	REQ_USERCOUNTRY_SET = 128,	//设置国家
	REQ_OFFLINE_INVITE_JOINTEAM = 129,	//邀请离线好友(TX QQ 微信邀请分享)
	REQ_OBSERVE = 130,	//请求观战
	REQ_GET_RECOMMEND_PVP = 131,	//获取推荐观战战局
	REQ_OBSERVE_LOGIN = 132,	//观战玩家登录
	REQ_QUIT_OBSERVE = 133,	//退出观战
	REQ_GET_OBSERVE_INFO = 134,	//获取观战信息
	REQ_FREE_FLOW = 135,	//免流查询
	REQ_SET_PUSH_TOKEN = 136,	//设置玩家消息推送token
	REQ_TLOG_EVENT = 137,	//tlog
	REQ_WXVVIP_AWARD = 138,	//大玩家领奖
	REQ_GET_RELATIONSTAR_WX = 139,	//获取微信关系链
	REQ_WX_REDPKT_SEND = 140,	//发送微信红包
	REQ_WX_REDPKT_RECV = 141,	//领取微信红包
	REQ_WX_REDPKT_LIKE = 142,	//微信大玩家点赞
	REQ_WX_REDPKT_RANK = 143,	//微信大玩家点赞排行
	REQ_OBSERVE_PRIVILEGE_SET = 144,	//观战权限设置
	REQ_PRESET_FAST_CHAT = 145,	//快捷聊天预设文本
	REQ_CHANGE_SLOT_TEAM = 146,	//改变位置
	REQ_CHANGE_SUB_MODE_TEAM = 147,	//改变子模式
	REQ_CONFIRM_CHANGE_SLOT_TEAM = 148,	//确认改变位置
	REQ_PVP_ROUND_END = 149,	//回合结束
	REQ_OBSERVE_CHAT_LOGIN = 150,	//观战玩家聊天登录
	REQ_PVP_CONFIRM = 151,	//游戏确认
	REQ_ACTIVITY_PIC_SHARE = 152,	//活动图片分享
	REQ_BIND_OLD_BUSINESS_PLAYER = 153,	//绑定老business玩家
	REQ_TRANSLATE = 154,	//翻译
	REQ_SUBMIT_QUESTIONNAIRE = 155,	//提交问卷
	REQ_CANCEL_CHANGESLOT = 156,	//取消换位
	REQ_SET_CHESS_SKIN = 157,	//棋子皮肤配置
	REQ_UNSET_CHESS_SKIN = 158,	//取消棋子皮肤配置
	REQ_COMPOSE = 159,	//合成物品
	REQ_VIDEO = 160,	//获取视频信息
	REQ_OFF_HELP_REDDOT = 161,	//熄灭知己红点
	REQ_CHANGE_LANGUAGE = 162,	//修改游戏中的语种
	REQ_REPORT_VIDEO_PLAY = 163,	//上报视频播放信息
	REQ_SET_PROVINCE = 164,	//设置省份
	REQ_LONGYUAN_VOICE = 165,	//请求龙渊语音参数
	REQ_TOURNAMENT_ENROLL = 166,	//赛事报名
	REQ_JOIN_TOURNAMENT_ROOM = 167,	//加入赛事房间
	REQ_TOURNAMENT_POINT_AWARD = 168,	//领取赛事积分奖励
	REQ_DEAL_WEB_MAIL = 169,	//处理web邮件
	REQ_GET_ENROLL_PLAYERS = 170,	//获取报名玩家名单
	REQ_CHALLENGE_AGAIN = 171,	//赛事再次挑战
	REQ_SET_FRIEND_INVISIABLE = 172,	//好友不可见
	REQ_GET_OBSERVE_TASK_AWARD = 173,	//获取观战任务奖励
	REQ_INVITE_OBSERVE = 174,	//邀请观战
	REQ_REJECT_OBSERVE = 175,	//拒绝邀请观战
	REQ_GET_TX_PLAYER = 176,	//查询腾讯玩家
	REQ_CHOOSE_TX_PLAYER = 177,	//选择腾讯玩家
	REQ_THIRD_PVP_INFO = 178,	//获取第三方战斗信息
	REQ_MARK_PLAYER_GUIDE = 179,	//标记新手引导
	REQ_MARK_CHESS_SKIN_CLICKED = 180,	// 标记棋子皮肤已点击
	REQ_RECRUIT_INVITE_PLAYER = 181,	//战友招募邀请玩家
	REQ_RECRUIT_BIND_INVITER = 182,	//输入招募者ID
	REQ_QUERY_PS4_ENTITLEMENTS = 183,	//查询PS4接口
	REQ_ACT_DAYSIGN = 184,	//每日活动签到
	REQ_HAVE_THIRD_PVP = 185,	//是否有第三方战斗进行
	REQ_ACTIVITY_MALL = 186,	//获取回流商店内容
	REQ_PSONLY = 187,	//ps only
	REQ_CHANGE_CHANNEL_TYPE = 188,	//修改渠道
	REQ_CUSTOM_CARD_OPT = 189,	//自定义组卡玩法操作 获取;保存;设置;
	REQ_STATISTICS_REPORT = 190,	//打点上报o
	REQ_CHAMPION_HISTORY = 191,	//获取锦标赛历届冠军信息
	REQ_TOURNAMENT_LAST_TOP_RANK = 192,	//获取上届锦标赛top8
	REQ_BIGWINNER_EXPANDMATCH = 193,	//大赢家扩大匹配请求
	REQ_BIGWINNER_DAILYAWARD = 194,	//领取低保
	REQ_BIGWINNER_SCOREHISITORY = 195,	//积分历史
	REQ_SMELT_ITEM = 196,	//熔炼物品
	REQ_OAUTH_APP = 200,	// 请求掌上龙渊授权
	REQ_TEAM_OP = 300,
	REQ_OB_TEAM_INFO = 301,	// 请求OB房间信息
	REQ_REPORT_HEADICONURL = 302,	// 请求上报头像url
	REQ_GET_PVP_SERVER_GROUP = 303,	// 获取PVP分组
	REQ_REPORT_PVP_INFO = 304,	// 上报选择的pvp分组及ping值
	REQ_CHOOSE_PLAYER = 305,	// 角色多选一
	REQ_PING_TEST = 306,	// 延迟测试
	REQ_REPORT_REGION_INFO = 307,	// 上报各区域的延迟信息
	REQ_RECALLEDPLAYER = 308,	// 已召回玩家
	REQ_WEB_LOGIN = 309,	// 网页登录
	REQ_INVITECODERESET = 310,	// 重置玩家黑盒邀请码
	REQ_RECALLREWARD = 311,	// 召回奖励
	REQ_SWITCHTO_COMMONMATCH = 312,	// 切换到全球匹配队列
	REQ_SWITCH_MODE_IN_TEAM = 320,	// 队伍中切换模式
	REQ_GET_TNROOM_STATE = 321,	// 获取锦标赛房间状态
	REQ_WORKSHOP_MATCH = 330,	// 发起创意工坊匹配
	REQ_BUY_WORKSHOP_TICKET = 331,	// 购买创意工坊门票
	REQ_FAVOURITE_WORKSHOP_MAP = 332,	// 收藏创意工坊地图
	REQ_SHORTCUT_MAPS_OP = 333,	// 操作创意工坊快捷入口
	REQ_PLAYERS_Tournament_INFO = 334,	// 玩家锦标赛信息
	REQ_SCORE_WORKSHOP_MAP = 335,	// 给创意工坊地图打分
	REQ_MAPS_VISITEDBY_FRIENDS = 336,	// 好友游玩记录
	REQ_VERIFY_REAL_NAME = 350,	// 请求实名认证
	REQ_FAKE_PAY = 351,	// 伪充值
	REQ_GUILD_CREATE = 360,	// 创建公会
	REQ_GUILD_APPLY = 361,	// 申请加入
	REQ_GUILD_HOME = 362,	// 公会首页
	REQ_GUILD_INFO = 364,	// 查看公会信息
	REQ_GUILD_APPROVE = 365,	// 同意申请
	REQ_GUILD_SET_ROLE = 366,	// 成员角色管理
	REQ_GUILD_MODIFY = 367,	// 修改公会信息
	REQ_GUILD_KICKOFF = 368,	// 提出公会
	REQ_GUILD_DISMISS = 369,	// 解散公会
	REQ_GUILD_EXIT = 370,	// 退出公会
	REQ_GUILD_CHAT = 371,	// 公会聊天
	REQ_GUILD_LIST = 372,	// 公会推荐列表
	REQ_GUILD_RECOMMEND_PLAYER = 373,	// 公会推荐玩家
	REQ_GUILD_RESIGN = 374,	// 辞去职位
	REQ_GUILD_INVITE = 375,	// 公会邀约
	REQ_GUILD_INVITE_LIST = 376,	// 玩家收到邀约
	REQ_GUILD_REJECT_INVITE = 377,	// 拒绝邀约
	REQ_VNG_COMMENT_AWARD = 390,	// VNG商店好评奖励
	REQ_LEVEL_UP_CHEST = 391,	// 宝箱升级
	REQ_WATCH_AD = 392,	// 开始观看广告
	REQ_QUERY_PS_TOURNAMENT_ROOM = 393,	// 查询ps赛事房间
	REQ_GET_AD_CUMULATE_AWARD = 394,	//获取广告保底奖励
	REQ_CHANNEL_CHAT = 395,	// 公共频道聊天
	REQ_APPLY_CHANNEL_CHAT = 396,	// 申请频道
	REQ_LEAVE_CHANNEL_CHAT = 397,	// 离开频道
	REQ_SET_MSGR_POS = 500,	// 同步信使位置
	REQ_CANCEL_RECONNECT = 520,
	REQ_RECONNECT = 522,
	REQ_PASS_THROUGH = 529,
	REQ_VISIT_PLAYER = 530,
	REQ_LEAVE_GAME_EARLY = 531,	// 提前离开游戏
	REQ_GDCOMMON_BIN = 532,	//游戏common配置数据请求
	REQ_GDCOMMONBIN_DATA = 533,	//请求bin文件的内容
	REQ_HISTORY_CHAT_MSG = 534,	//历史聊天消息
	REQ_BATTLE_CAMPRESULT = 535,	//获取战斗阵营数据
	REQ_AUTO_BATTLE_OP = 536,	//请求自动操作(一键占位 一键穿装备)
	REQ_RESTRICT_USER = 537,	//请求限制用户
	REQ_EQUIP_SELECT_RATE = 538,	//请求装备选取率
	REQ_REPORT_ABSENT = 539,	//上报缺席
	REQ_RECOMMEND_WEEK = 600,	// 请求推荐阵容周榜
	REQ_RECOMMEND_OFFICIAL = 601,	// 请求推荐阵容官方
	REQ_RECOMMEND_LATEST = 602,	// 请求推荐阵容最新
	REQ_RECOMMEND_HISTORY = 603,	// 请求个人历史阵容
	REQ_RECOMMEND_COLLECT = 604,	// 请求阵容收藏
	REQ_RECOMMEND_SET = 605,	// 请求阵容设置
	REQ_RECOMMEND_GETCOLLECTION = 606,	// 获取阵容收藏
	REQ_RECOMMEND_EQUIP = 607,	// 获取推荐阵容
	REQ_LOGIN_CANCEL = 608,	// 取消登录
	REQ_CONVERT_DEBRIS = 609,	// 兑换碎片
	REQ_USE_PROTECTION_CARD = 610,	// 段位保护
	REQ_USE_PASSPORT_CARD = 611,	// 使用通行证激活卡
	REQ_SET_MEDAL = 612,	// 穿戴勋章
	REQ_UNSET_MEDAL = 613,	// 穿戴勋章
	REQ_PLAYER_MEDALS = 614,	// 勋章列
	REQ_UPDATE_HOT_DOT = 616,	// 更新红点列表
	REQ_QUERY_HOT_DOT = 617,	// 查询红点列表
	REQ_SET_CACHE = 618,	// 存储信息
	REQ_GET_CACHE = 619,	// 获取信息
	REQ_BUY_CHALLENGE_COUNT = 620,	// 购买挑战记录
	REQ_GET_PVE_RANK = 621,	// 获取pve排行榜
	REQ_AUTH_ACCOUNT = 622,	// 验证，并获取用户的基础信息
	REQ_UNBIND_ACCOUNT = 623,	// 解绑ps ly 账号
	REQ_BAGTOITEM = 624,	// 转移背包物品
	REQ_IDENTIFY_ITEM = 625,	// 鉴定物品
	REQ_INSERT_ITEM_AFFIX = 626,	// 向前词缀
	REQ_UNSET_ITEM_AFFIX = 627,	// 提取词缀
	REQ_SET_DEFAULT_ATTRIBUTES = 628,	// 设置玩家默认的属性
	REQ_CHECK_CANCEL = 629,	// 检测注销条件
	REQ_CANCEL_ACCOUNT = 630,	// 注销账号
	REQ_PVE_UP_TALENT_LEVEL = 631,	// PVE-天赋升级
	REQ_PVE_LUCKY_AWARD = 632,	// PVE-抽奖
	REQ_GET_SELF_NUM_RANK_DATA = 633,	//获取个人多个排行榜排名--不支持锦标赛
	REQ_UPDATE_CARD_GROUP = 634,	//更新棋组信息    优化过后 弃用
	REQ_UPDATE_CARD_GROUP_NAME = 635,	//更新棋组 方案名  优化过后 弃用
	REQ_BUY_PVE_BUFF = 636,	//购买pve buff
	REQ_SET_CARD_GROUP = 637,	//局内设置卡组
	REQ_BUY_PVE_CHESS_TEMPLATE = 638,	// 购买棋子和技能
	REQ_PVE_UNLOCK_CHESS_TEMPLATE = 639,	// 装配/卸下棋子和技能
	REQ_PVE_SET_TEAM_DEBUFF = 640,	// 设置房间debuff
	REQ_CHOSE_CARD_GROUP = 641,	// 局内设置卡组
	REQ_REMOVE_OVERTIME_BUFF = 642,	// 删除过期时间
	REQ_UPDATE_NEW_CARD_GROUP_SIGN = 643,	// 标记 局外第一次卡组引导
	REQ_TD_GET_ONHOOK_AWARD = 644,	// 获取挂机奖励
	REQ_TD_DRAW = 645,	// 抽卡
	REQ_TD_BUY_CARD = 646,	// 购买卡券
	REQ_TD_SET_CARD_GROUP = 647,	// 设置卡组
	REQ_TD_LEVEL_UP = 648,	// 升级
	REQ_TD_EQUIP = 649,	// 更新装备
	REQ_MENTOR_UPDATE_SETTING = 650,	// 更新 设置
	REQ_MENTOR_INVITE = 651,	// 发送邀请
	REQ_MENTOR_CONFIRM_INVITE = 652,	// 确认邀请
	REQ_MENTOR_RECOMMEND_LIST = 653,	// 师傅/徒弟推荐列表
	REQ_MENTOR_GET_TASK_AWARD = 654,	// 领取任务奖励
	REQ_MENTOR_GRADUATE = 655,	// 出师
	REQ_MENTOR_RELIEVE_RELATION = 656,	// 解除关系
	REQ_GET_MENTOR_INFO = 657,	// 获取师徒信息
	REQ_MENTOR_GET_INVITE_MSG = 658,	// 获取邀请信息
	REQ_UPDATE_CARD_GROUP_BETTER = 659,	//更新卡组 优化
	REQ_UPDATE_CARD_GROUP_SETTING = 660,	//更新卡组 设置
	REQ_SET_AUCTION_NAME = 661,	//设置拍卖行的名字
	REQ_SET_AUCTION_REMARK = 662,	//设置拍卖行的留言
	REQ_GET_BALANCE = 663,	//获取余额
	REQ_RECHARGE_BALANCE = 664,	//存入余额
	REQ_WITHDRAW_BALANCE = 665,	//提现余额
	REQ_PERSONAL_RECOMMEND_MALL = 666,	//精细化投放
	REQ_GET_MEDAL_CHEST_AWARD = 667,	//获取成就勋章任务宝箱奖励
	REQ_SET_ITEM_AUTO_USE = 668,	//设置物品自动使用
	CS_RSP_BEGIN = 1000,	//保留
	RSP_HEART = 1001,
	RSP_LOGIN = 1002,	//登陆请求
	RSP_VERSION_CHECK = 1003,	//版本检查
	RSP_RESOURCE_VERSION_CHECK = 1004,	//资源版本检测
	RSP_APPLY_HALL_SERVER = 1005,
	RSP_GET_NUM_RANK = 1006,
	RSP_WORLD_CHAT = 1007,
	RSP_PLAYERS_BASE_INFO = 1008,	//玩家基础信息
	RSP_PLAYER_DETAIL_INFO = 1009,	//玩家详细信息
	RSP_READ_MAIL = 1010,	//读邮件
	RSP_GET_MAIL_AWARD = 1011,	//领取邮件奖励
	RSP_BUY_EGG = 1012,	//购买扭蛋
	RSP_USERNAME_SET = 1013,	//设置用户名
	RSP_USERNAME_RANDOM = 1014,	//随机用户名
	RSP_HEADPIC_SET = 1015,	//设置头像
	RSP_PVP = 1016,	//pvp请求
	RSP_PVP_MATCH_CANCEL = 1017,	//取消匹配
	RSP_DRESS_CHESS_PLAYER = 1018,	//
	RSP_DRESS_SCENE = 1019,	//
	RSP_PVP_LOGIN = 1020,	//pvp服登陆请求
	RSP_PVP_SEQS = 1021,
	RSP_PVP_PLAYER_READY = 1022,
	RSP_PVP_CLIENT_READY = 1023,
	RSP_REP_PVP_ACTION = 1024,
	RSP_PVP_END = 1025,
	RSP_PLAYER_FINISH = 1026,
	RSP_PLAYER_QUIT = 1027,
	RSP_SELL_ITEM = 1028,	//出售物品
	RSP_GET_EVAL_AWARD = 1029,
	RSP_USE_CHESS_PLAYER = 1030,
	RSP_GUID_REPORT = 1031,
	RSP_GET_CODE_AWARD = 1032,
	RSP_ROUND_REPORT = 1033,
	RSP_LOADING_PROGRESS = 1034,
	RSP_PVP_CHAT = 1035,
	RSP_CHESS_COMBINE = 1036,	//棋子合成
	RSP_EXPOSE = 1037,	// 举报
	RSP_APPLY_ORDER_ID = 1038,	//申请订单Id
	RSP_REPORT_ORDER_INFO = 1039,	//上报订单信息
	RSP_SET_ITEM = 1040,	//配置物品
	RSP_UNSET_ITEM = 1041,	//取消配置物品
	RSP_RANDOM_ITEM = 1042,	//请求随机物品
	RSP_CHAT = 1043,	//聊天
	RSP_SET_CHESS_PLAYER = 1044,	//配置棋手相关属性
	RSP_UNSET_CHESS_PLAYER = 1045,	//取消配置棋手相关属性
	RSP_GET_FANS_LIST = 1046,	//获取粉丝列表
	RSP_FOLLOW_PLAYER = 1047,	//关注玩家
	RSP_UNFOLLOW_PLAYER = 1048,	//取消关注玩家
	RSP_PLAYERS_STATUS_INFO = 1049,
	RSP_INVITE_JOIN_TEAM = 1050,
	RSP_JOIN_TEAM = 1051,	//请求加入队伍
	RSP_LEAVE_TEAM = 1052,	//请求离开队伍
	RSP_KICKOFF_TEAM_PLAYER = 1053,	//请求剔除队伍队员
	RSP_TEAM_MSG = 1054,	//请求队伍聊天
	RSP_TEAM_READY = 1055,	//队伍成员准备
	RSP_REJECT_JOIN_TEAM = 1056,	//拒绝加入队伍
	RSP_REPORT_PAY_RESPONSE = 1057,	//上报支付回执信息
	RSP_SHIELD_CHAT = 1058,	//私聊屏蔽
	RSP_BUY_PASSPORT_LEVEL = 1059,	//购买通行证等级
	RSP_UPGRADE_PASSPORT = 1060,	//升级通行证
	RSP_GET_PASSPORT_LEVEL_AWARD = 1061,	//获取通行证等级奖励
	RSP_GET_PASSPORT_TASK_AWARD = 1062,	//获取通行证任务奖励
	RSP_TEL_BOOK = 1063,	//通讯录
	RSP_ACTIVATE_PASSPORT = 1064,	//激活通行证
	RSP_RANKSEASON_EVAL = 1065,
	RSP_BIND_ACCOUNT = 1066,	//
	RSP_INCREASE_AD_SHOW_COUNT = 1067,	//增加loading广告浏览次数
	RSP_USE_BONUS_CARD = 1068,	//使用加成卡
	RSP_GET_SEASON_AWARD = 1069,
	RSP_GET_ALPHA_ACTIVITY_AWARD = 1070,
	RSP_GET_LANGUAGE_DATA = 1071,
	RSP_GET_ACTIVITY_AWARD = 1072,	//获取活动奖励
	RSP_GET_ACTIVITY_DATA = 1073,	//获取活动数据
	RSP_SEND_SMS = 1074,	//发短信
	RSP_GET_MELEE_AWARD = 1075,
	RSP_ADD_AI_TO_TEAM = 1076,
	RSP_SHARE = 1077,	//玩家分享通知
	RSP_SKIP_INTERFACE = 1078,	//跳转界面
	RSP_TEAM_GAME = 1079,
	RSP_SET_TEAM_MODE = 1080,
	RSP_SET_HITORY_PVP_SHOW_PERMISSION = 1081,	//设置历史战绩查看权限
	RSP_SEARCH_TEAM = 1082,
	RSP_APPLY_CHAT = 1083,
	RSP_CHAT_LOGIN = 1084,
	RSP_PROBE_NET_DELAY = 1085,
	RSP_GET_EGGS = 1086,	//获取可展示的扭蛋信息
	RSP_BUY_GOODS = 1087,	//购买特价礼包
	RSP_EXCHANGE_PASSPORT_GOODS = 1088,	//兑换通行证商品
	RSP_USE_PASSPORT_TASK_CARD = 1089,	//使用任务卡
	RSP_OPEN_RAND_CHEST = 1090,	//打开随机宝箱, 自选宝箱
	RSP_EGG_LOTTERY = 1091,	//扭蛋抽奖
	RSP_QUERY_DIAMOND_BALANCE = 1092,
	RSP_USE_ITEM = 1093,	//使用道具
	RSP_USE_EXPERIENCE_CARD = 1094,
	RSP_RAND_TARGET_ITEM = 1095,
	RSP_ADD_BLACKLIST = 1096,	//添加黑名单
	RSP_REMOVE_BLACKLIST = 1097,	//删除黑名单
	RSP_REPORT_PLAYER_BIRTH = 1098,	//上报玩家出生年月
	RSP_REPORT_INFO_INPUT = 1099,	//上报玩家信息录入
	RSP_SEND_VERIFICATION_CODE = 1100,	//发送验证码
	RSP_BIND_PHONE_NUMBER = 1101,	//绑定手机号
	RSP_WORLD_INVITE = 1102,	//邀约
	RSP_REMOVE_EXPIRE_ITEM = 1103,
	RSP_GET_MALL_GOODS = 1104,	//请求获取商品信息
	RSP_BUY_MALL_GOODS = 1105,	//购买商城商品
	RSP_BIND_SHARING_CODE = 1106,	//绑定分享码
	RSP_WX_BLESS_BAG = 1107,
	RSP_UPDATE_FRIENDS_INGAME = 1108,	//更新同玩好友人数
	RSP_SHARE_REWARD = 1109,
	RSP_ALLFIGHT_INFO = 1110,	//获取全民对局信息
	RSP_GET_OLD_PLAYER = 1111,	//获取老账号
	RSP_BIND_OLD_PLAYER = 1112,	//绑定老账号
	RSP_SEND_VERIFICATION_CODE_WITH_CHECK_REDIS = 1113,	//发送验证码(获取老账号)
	RSP_REPORT_SETTING = 1114,	//上报玩家设置
	RSP_ANTI_DATA = 1115,	//安全sdk anti通知消息
	RSP_TLOG_DATA = 1116,	//tlog通知消息
	RSP_DAY_SIGN = 1117,	//签到
	RSP_DAY_FIT_AVOID = 1118,	//玩家上报每日宜忌
	RSP_SHARE_COUNT_AWARD = 1119,	//领取每月累计分享奖励
	RSP_ACT_ITEM_EXCH = 1120,	//集道具兑换活动 兑换应答
	RSP_REALATION_STAR = 1121,	//关系链幸运星邀请
	RSP_GET_REALATION_STAR_INVITE_SUCC = 1122,	//获取关系链幸运星邀请成功列表
	RSP_GET_REALATION_STAR = 1123,	//获取关系链幸运星邀请列表
	RSP_GET_ACT_RECORD = 1124,	//获取活动记录
	RSP_JOIN_VOICE_TEAM = 1125,	//加入语音房间
	RSP_JOIN_VOICE_PVP = 1126,	//加入pvp语音房间
	RSP_JOIN_VOICE_CAMP = 1127,	//加入camp语音房间
	RSP_USERCOUNTRY_SET = 1128,	//设置国家
	RSP_OFFLINE_INVITE_JOINTEAM = 1129,	//邀请离线好友(TX QQ 微信邀请分享)
	RSP_OBSERVE = 1130,	//请求观战
	RSP_GET_RECOMMEND_PVP = 1131,	//获取推荐观战战局
	RSP_OBSERVE_LOGIN = 1132,	//观战玩家登录
	RSP_QUIT_OBSERVE = 1133,	//退出观战
	RSP_GET_OBSERVE_INFO = 1134,	//获取观战人数
	RSP_FREE_FLOW = 1135,	//免流查询
	RSP_SET_PUSH_TOKEN = 1136,	//设置玩家消息推送token
	RSP_TLOG_EVENT = 1137,	//tlog
	RSP_WXVVIP_AWARD = 1138,	//微信大玩家领奖
	RSP_GET_RELATIONSTAR_WX = 1139,	//获取微信关系链
	RSP_WX_REDPKT_SEND = 1140,	//发送微信红包
	RSP_WX_REDPKT_RECV = 1141,	//领取微信红包
	RSP_WX_REDPKT_LIKE = 1142,	//微信大玩家点赞
	RSP_WX_REDPKT_RANK = 1143,	//微信大玩家点赞排行
	RSP_OBSERVE_PRIVILEGE_SET = 1144,	//观战权限设置
	RSP_PRESET_FAST_CHAT = 1145,	//快捷聊天预设文本
	RSP_CHANGE_SLOT_TEAM = 1146,	//改变位置
	RSP_CHANGE_SUB_MODE_TEAM = 1147,	//改变子模式
	RSP_CONFIRM_CHANGE_SLOT_TEAM = 1148,	//确认改变位置
	RSP_PVP_ROUND_END = 1149,	//回合结束
	RSP_OBSERVE_CHAT_LOGIN = 1150,	//观战玩家聊天登录
	RSP_PVP_CONFIRM = 1151,
	RSP_ACTIVITY_PIC_SHARE = 1152,	//活动图片分享
	RSP_BIND_OLD_BUSINESS_PLAYER = 1153,	//绑定老business玩家
	RSP_TRANSLATE = 1154,	//翻译
	RSP_SUBMIT_QUESTIONNAIRE = 1155,	//提交问卷
	RSP_CANCEL_CHANGESLOT = 1156,	//取消换位
	RSP_SET_CHESS_SKIN = 1157,	//配置棋子皮肤
	RSP_UNSET_CHESS_SKIN = 1158,	//取消配置棋子皮肤
	RSP_COMPOSE = 1159,	//合成物品
	RSP_VIDEO = 1160,	//获取视频信息返回
	RSP_OFF_HELP_REDDOT = 1161,	//熄灭知己红点
	RSP_CHANGE_LANGUAGE = 1162,	//修改游戏中的语种
	RSP_REPORT_VIDEO_PLAY = 1163,	//上报视频播放信息回复
	RSP_SET_PROVINCE = 1164,	//设置省份
	RSP_LONGYUAN_VOICE = 1165,	//返回龙渊语音参数
	RSP_TOURNAMENT_ENROLL = 1166,	//赛事报名
	RSP_JOIN_TOURNAMENT_ROOM = 1167,	//加入赛事房间
	RSP_TOURNAMENT_POINT_AWARD = 1168,	//领取赛事积分奖励
	RSP_DEAL_WEB_MAIL = 1169,	//处理web邮件
	RSP_GET_ENROLL_PLAYERS = 1170,	//获取报名玩家列表
	RSP_CHALLENGE_AGAIN = 1171,	//赛事再次挑战
	RSP_SET_FRIEND_INVISIABLE = 1172,	//好友不可见
	RSP_GET_OBSERVE_TASK_AWARD = 1173,	//获取观战任务奖励
	RSP_INVITE_OBSERVE = 1174,	//邀请观战
	RSP_REJECT_OBSERVE = 1175,	//拒绝邀请观战
	RSP_GET_TX_PLAYER = 1176,	//查询腾讯玩家
	RSP_CHOOSE_TX_PLAYER = 1177,	//选择腾讯玩家
	RSP_THIRD_PVP_INFO = 1178,	//获取第三方战斗信息
	RSP_MARK_PLAYER_GUIDE = 1179,	//标记新手引导
	RSP_MARK_CHESS_SKIN_CLICKED = 1180,
	RSP_RECRUIT_INVITE_PLAYER = 1181,	//战友招募邀请玩家
	RSP_RECRUIT_BIND_INVITER = 1182,	//输入招募者ID
	RSP_QUERY_PS4_ENTITLEMENTS = 1183,	//查询ps4
	RSP_ACT_DAYSIGN = 1184,	//每日活动签到
	RSP_HAVE_THIRD_PVP = 1185,	//是否有第三方战斗进行
	RSP_ACTIVITY_MALL = 1186,	//回流商店内容
	RSP_PSONLY = 1187,	//ps only
	RSP_CHANGE_CHANNEL_TYPE = 1188,	//
	RSP_CUSTOM_CARD_OPT = 1189,	//自定义组卡玩法操作 获取;保存;设置;
	RSP_STATISTICS_REPORT = 1190,	//
	RSP_CHAMPION_HISTORY = 1191,	//获取锦标赛历届冠军信息
	RSP_TOURNAMENT_LAST_TOP_RANK = 1192,	//获取上届锦标赛top8
	RSP_BIGWINNER_EXPANDMATCH = 1193,	//
	RSP_BIGWINNER_DAILYAWARD = 1194,	//
	RSP_BIGWINNER_SCOREHISITORY = 1195,	//积分历史
	RSP_SMELT_ITEM = 1196,	//熔炼物品
	RSP_OAUTH_APP = 1200,	// 请求掌上龙渊授权
	RSP_TEAM_OP = 1300,	// 队伍操作应答
	RSP_OB_TEAM_INFO = 1301,	// OB队伍信息
	RSP_GET_PVP_SERVER_GROUP = 1303,	// 获取PVP分组
	RSP_REPORT_PVP_INFO = 1304,	// 上报选择的pvp分组及ping值
	RSP_CHOOSE_PLAYER = 1305,	// 角色多选一
	RSP_PING_TEST = 1306,	// 延迟测试
	RSP_REPORT_REGION_INFO = 1307,	// 上报各区域的延迟信息
	RSP_RECALLEDPLAYER = 1308,	// 已召回玩家
	RSP_WEB_LOGIN = 1309,	// 网页登录
	RSP_INVITECODERESET = 1310,	// 响应重置新的邀请码
	RSP_RECALLREWARD = 1311,	// 召回奖励
	RSP_SWITCHTO_COMMONMATCH = 1312,	// 切换到全球匹配队列
	RSP_SWITCH_MODE_IN_TEAM = 1320,	// 队伍中切换模式
	RSP_GET_TNROOM_STATE = 1321,	// 好友游玩记录
	RSP_WORKSHOP_MATCH = 1330,	// 发起创意工坊匹配
	RSP_BUY_WORKSHOP_TICKET = 1331,	// 购买创意工坊门票
	RSP_FAVOURITE_WORKSHOP_MAP = 1332,	// 收藏创意工坊地图
	RSP_SHORTCUT_MAPS_OP = 1333,	// 操作创意工坊快捷入口
	RSP_PLAYERS_Tournament_INFO = 1334,	// 玩家锦标赛信息
	RSP_SCORE_WORKSHOP_MAP = 1335,	// 给创意工坊地图打分
	RSP_MAPS_VISITEDBY_FRIENDS = 1336,	//
	RSP_VERIFY_REAL_NAME = 1350,
	RSP_FAKE_PAY = 1351,
	RSP_GUILD_CREATE = 1360,	// 创建公会
	RSP_GUILD_APPLY = 1361,	// 申请加入
	RSP_GUILD_HOME = 1362,	// 公会首页
	RSP_GUILD_APPLY_LIST = 1363,	// 公会申请列表
	RSP_GUILD_INFO = 1364,	// 查看公会信息
	RSP_GUILD_APPROVE = 1365,	// 同意申请
	RSP_GUILD_SET_ROLE = 1366,	// 成员角色管理
	RSP_GUILD_MODIFY = 1367,	// 修改公会信息
	RSP_GUILD_KICKOFF = 1368,	// 提出公会
	RSP_GUILD_DISMISS = 1369,	// 解散公会
	RSP_GUILD_EXIT = 1370,	// 退出公会
	RSP_GUILD_CHAT = 1371,	// 公会聊天
	RSP_GUILD_LIST = 1372,	// 公会推荐列表
	RSP_GUILD_RECOMMEND_PLAYER = 1373,	// 公会推荐玩家
	RSP_GUILD_RESIGN = 1374,	// 辞去职位
	RSP_GUILD_INVITE = 1375,	// 公会邀约
	RSP_GUILD_INVITE_LIST = 1376,	// 玩家收到邀约列表
	RSP_GUILD_LOG = 1377,	// 公会日志
	RSP_GUILD_REJECT_INVITE = 1378,	// 拒绝邀请
	RSP_VNG_COMMENT_AWARD = 1390,	// VNG商店好评奖励
	RSP_LEVEL_UP_CHEST = 1391,	// VNG商店好评奖励
	RSP_WATCH_AD = 1392,	// 开始观看广告
	RSP_QUERY_PS_TOURNAMENT_ROOM = 1393,	// 查询ps赛事房间
	RSP_GET_AD_CUMULATE_AWARD = 1394,	// 获取广告保底奖励
	RSP_CHANNEL_CHAT = 1395,	//公共频道聊天
	RSP_APPLY_CHANNEL_CHAT = 1396,	//
	RSP_LEAVE_CHANNEL_CHAT = 1397,
	RSP_SET_MSGR_POS = 1500,	//同步信使位置
	RSP_CANCEL_RECONNECT = 1520,
	RSP_RECONNECT = 1522,	// 重连
	RSP_PASS_THROUGH = 1529,
	RSP_VISIT_PLAYER = 1530,
	RSP_LEAVE_GAME_EARLY = 1531,	//提前离开游戏
	RSP_GDCOMMON_BIN = 1532,	//
	RSP_GDCOMMONBIN_DATA = 1533,
	RSP_HISTORY_CHAT_MSG = 1534,	// 历史聊天消息
	RSP_BATTLE_CAMPRESULT = 1535,	//获取战斗阵营数据
	RSP_AUTO_BATTLE_OP = 1536,	// 自动战斗(一键占位 一键上装备)
	RSP_RESTRICT_USER = 1537,	//限制用户
	RSP_EQUIP_SELECT_RATE = 1538,	//请求装备选取率
	RSP_REPORT_ABSENT = 1539,	//提前离开游戏
	RSP_RECOMMEND_WEEK = 1600,	// 请求推荐阵容周榜
	RSP_RECOMMEND_OFFICIAL = 1601,	// 请求推荐阵容官方
	RSP_RECOMMEND_LATEST = 1602,	// 请求推荐阵容最新
	RSP_RECOMMEND_HISTORY = 1603,	// 请求个人历史阵容
	RSP_RECOMMEND_COLLECT = 1604,	// 请求阵容收藏
	RSP_RECOMMEND_SET = 1605,	// 请求阵容设置
	RSP_RECOMMEND_GETCOLLECTION = 1606,	// 获取阵容收藏
	RSP_RECOMMEND_EQUIP = 1607,	// 获取推荐装备
	RSP_LOGIN_CANCEL = 1608,	// 取消登录
	RSP_CONVERT_DEBRIS = 1609,	// 兑换碎片
	RSP_USE_PROTECTION_CARD = 1610,	// 段位保护
	RSP_USE_PASSPORT_CARD = 1611,	// 使用通行证激活卡
	RSP_SET_MEDAL = 1612,	// 卸下勋章
	RSP_UNSET_MEDAL = 1613,	// 卸下勋章
	RSP_PLAYER_MEDALS = 1614,	// 勋章列表
	RSP_UPDATE_HOT_DOT = 1616,	//更新红点列表
	RSP_QUERY_HOT_DOT = 1617,	//查询红点列表
	RSP_SET_CACHE = 1618,
	RSP_GET_CACHE = 1619,
	RSP_BUY_CHALLENGE_COUNT = 1620,	//购买挑战记录
	RSP_GET_PVE_RANK = 1621,	//获取PVE排行榜
	RSP_AUTH_ACCOUNT = 1622,	// 验证，并获取用户的基础信息
	RSP_UNBIND_ACCOUNT = 1623,	// 解绑 ps ly 账号
	RSP_BAGTOITEM = 1624,	// 转移背包物品
	RSP_IDENTIFY_ITEM = 1625,	// 鉴定物品
	RSP_INSERT_ITEM_AFFIX = 1626,	// 向前词缀
	RSP_UNSET_ITEM_AFFIX = 1627,	// 提取词缀
	RSP_SET_DEFAULT_ATTRIBUTES = 1628,	// 设置玩家默认属性
	RSP_CHECK_CANCEL = 1629,	// 检测注销条件
	RSP_CANCEL_ACCOUNT = 1630,	// 注销账户
	RSP_PVE_UP_TALENT_LEVEL = 1631,	// PVE-天赋升级
	RSP_PVE_LUCKY_AWARD = 1632,	// PVE-抽奖
	RSP_GET_SELF_NUM_RANK_DATA = 1633,	//个人多个排行榜排名
	RSP_UPDATE_CARD_GROUP = 1634,
	RSP_UPDATE_CARD_GROUP_NAME = 1635,
	RSP_BUY_PVE_BUFF = 1636,
	RSP_SET_CARD_GROUP = 1637,
	RSP_BUY_PVE_CHESS_TEMPLATE = 1638,
	RSP_PVE_UNLOCK_CHESS_TEMPLATE = 1639,
	RSP_PVE_SET_TEAM_DEBUFF = 1640,
	RSP_CHOSE_CARD_GROUP = 1641,
	RSP_REMOVE_OVERTIME_BUFF = 1642,
	RSP_UPDATE_NEW_CARD_GROUP_SIGN = 1643,
	RSP_TD_GET_ONHOOK_AWARD = 1644,	// 获取挂机奖励
	RSP_TD_DRAW = 1645,	// 抽卡
	RSP_TD_BUY_CARD = 1646,	// 购买卡券
	RSP_TD_SET_CARD_GROUP = 1647,	// 设置卡组
	RSP_TD_LEVEL_UP = 1648,	// 升级
	RSP_TD_EQUIP = 1649,	// 更新装备
	RSP_MENTOR_UPDATE_SETTING = 1650,	//更新师徒 设置
	RSP_MENTOR_INVITE = 1651,	// 发送邀请
	RSP_MENTOR_CONFIRM_INVITE = 1652,	// 确认邀请
	RSP_MENTOR_RECOMMEND_LIST = 1653,	// 师傅/徒弟推荐列表
	RSP_MENTOR_GET_TASK_AWARD = 1654,	// 领取任务奖励
	RSP_MENTOR_GRADUATE = 1655,	// 出师
	RSP_MENTOR_RELIEVE_RELATION = 1656,	// 解除关系
	RSP_GET_MENTOR_INFO = 1657,	// 获取师徒信息
	RSP_MENTOR_GET_INVITE_MSG = 1658,	// 获取邀请信息
	RSP_UPDATE_CARD_GROUP_BETTER = 1659,	//更新卡组 优化
	RSP_UPDATE_CARD_GROUP_SETTING = 1660,	//更新卡组 设置
	RSP_SET_AUCTION_NAME = 1661,	//设置拍卖行的名字
	RSP_SET_AUCTION_REMARK = 1662,	//设置拍卖行的留言
	RSP_GET_BALANCE = 1663,	//获取余额
	RSP_RECHARGE_BALANCE = 1664,	//存入余额
	RSP_WITHDRAW_BALANCE = 1665,	//提现余额
	RSP_PERSONAL_RECOMMEND_MALL = 1666,	//精细化投放
	RSP_GET_MEDAL_CHEST_AWARD = 1667,	//成就勋章任务宝箱奖励
	RSP_SET_ITEM_AUTO_USE = 1668,	//设置物品自动使用
	CS_NTF_BEGIN = 2000,	//保留
	NTF_KICKOFF = 2001,	//踢线
	NTF_PLAYER_WAIT = 2002,
	NTF_PASS_DAY = 2003,	//跨天通知
	NTF_PASS_WEEK = 2004,
	NTF_PASS_MONTH = 2005,
	NTF_WORLD_CHAT = 2006,
	NTF_MAILS = 2007,
	NTF_HEAD_PIC = 2008,	//头像变更通告
	NTF_PVP_MATCH = 2009,
	NTF_PVP_MATCH_CANCEL = 2010,
	NTF_PVP = 2011,
	NTF_PVP_STATUS = 2012,
	NTF_PVP_PLAYER_READY = 2013,
	NTF_PVP_BEGIN = 2014,
	NTF_PVP_SEQ = 2015,
	NTF_PLAYER_FINISH = 2016,	//
	NTF_PVP_END = 2017,
	NTF_MARQUEE = 2018,	//GM跑马灯通告
	NTF_REMOVE_MARQUEE = 2019,	//删除跑马灯
	NTF_LOADING_PROGRESS = 2020,
	NTF_PVP_CHAT = 2021,
	NTF_RELOAD = 2022,
	NTF_PAY = 2023,	//支付信息通知
	NTF_CHAT = 2024,	//聊天消息下发
	NTF_FOLLOW_LIST = 2025,
	NTF_NEW_FOLLOWER = 2026,
	NTF_LOST_FOLLOWER = 2027,
	NTF_INVITE_JOIN_TEAM = 2028,
	NTF_PLAYER_JOIN_TEAM = 2029,
	NTF_KICKOFF_TEAM_PLAYER = 2030,
	NTF_TEAM_MSG = 2031,
	NTF_TEAM_READY = 2032,
	NTF_REJECT_JOIN_TEAM = 2033,
	NTF_PLAYER_LEAVE_TEAM = 2034,
	NTF_NOTICE = 2035,
	NTF_REMOVE_NOTICE = 2036,
	NTF_UPGRADE_BATTLE_STAGE = 2037,	//战阶(通行证等级)通知
	NTF_PASSPORT_TASK_PROGRESS = 2038,	//通行证任务进度通告
	NTF_RANKSEASON_EVAL = 2039,
	NTF_BIND_ACCOUNTS = 2040,
	NTF_SEASON_TASK_PROGRESS = 2041,
	NTF_ALPHA_ACTIVITY = 2042,
	NTF_OFF_SEASON_TO_NEW_SEASON = 2043,
	NTF_LANGUAGE_MD5_LIST = 2044,
	NTF_ACTIVITY_PROGRESS = 2045,
	NTF_REMOVE_ACTIVITY = 2046,
	NTF_ACTIVITY_CONFIG = 2047,
	NTF_MELEE_TASK_PROGRESS = 2048,
	NTF_SET_TEAM_MODE = 2049,
	NTF_PASSPORT_OPEN = 2050,
	NTF_PASSPORT_CLOSE = 2051,
	NTF_WEEK_INDEX = 2052,
	NTF_NEW_PVP_HISTORY = 2053,
	NTF_TEAM_PVP_END = 2054,
	NTF_PROBE_NET_DELAY = 2055,
	NTF_REFRESH_GOODS = 2056,	//商品刷新通知
	NTF_SWITCH_SYS_SET = 2058,	//开关控制标记设置_系统
	NTF_SWITCH_PLAYER_SET = 2059,	//开关控制标记设置_个人
	NTF_BLACKLIST = 2060,	//通知黑名单信息
	NTF_BIND_PHONE_NUMBER_SWITCH = 2061,	//通知手机绑定开关
	NTF_WORLD_INVITE = 2062,	//邀约
	NTF_MALL_NOTICE = 2063,	// 商城推荐页公告
	NTF_PRIVILEGE = 2064,	//通知特权信息
	NTF_AA_REMIND = 2065,
	NTF_AA_BAN = 2066,
	NTF_AA_VERIFY = 2067,
	NTF_PHONE_NUMBER = 2068,	//绑定的手机号
	NTF_ANTI_CALLBACK = 2069,	//通知安全sdk anti回调
	NTF_FORTUNEBAG_TIME = 2070,	//通知福袋时间
	NTF_UPDATE_ITEM = 2071,	//通知物品/货币更改
	NTF_CREDIT_SCORE = 2072,	//通知安全信用分
	NTF_BUFF_ACT = 2073,	//通知buff活动
	NTF_ACTIVITY_GROUP = 2074,	//通知活动组信息
	NTF_GM_SYSMESSAGE = 2075,	//idip通知GM系统信息
	NTF_CLEAR_CHAT = 2076,	//通知清空聊天内容
	NTF_FORBID_INFO = 2077,	//通知封禁内容
	NTF_MIDAS_DIAMOND = 2078,	//米大师查询得到钻石
	NTF_JOIN_VOICE_TEAM = 2079,	//加入team语音房间
	NTF_JOIN_VOICE_PVP = 2080,	//加入pvp语音房间
	NTF_JOIN_VOICE_CAMP = 2081,	//加入camp语音房间
	NTF_WX_VVIP_LEVEL = 2082,	//同步微信大玩家等级
	NTF_FREE_FLOW = 2083,	//免流查询
	NTF_OBSERVE_STATUS = 2084,	//观战状态通知
	NTF_GAME_MARQUEE = 2085,	//游戏内跑马灯
	NTF_WX_RED_PACKET = 2086,	//有新的红包
	NTF_NEW_PUNISHMENT = 2087,	//新惩罚通知
	NTF_TEAMSLOT = 2088,	//队伍位置
	NTF_TEAMSUBMODE = 2089,	//队伍子模式
	NTF_TEAMSLOTSTATUS = 2099,	//通知换位状态
	NTF_PUNISHMENT_INFO = 2100,	//惩罚提示信息
	NTF_REMOVE_PUNISHMENT = 2101,	//移除惩罚
	NTF_PVP_CONFIRM = 2102,	//游戏确认
	NTF_MATCH_SUCCESS = 2103,	//匹配成功，进入游戏确认阶段
	NTF_OLD_BUSINESS_PLAYER = 2104,	//business老玩家信息
	NTF_CHANGETEAMSLOT = 2105,	//通知换位请求
	NTF_REFUSECHANGETEAMSLOT = 2106,	// 通知拒绝换位
	NTF_CANCELCHANGESLOT = 2107,	// 取消换位
	NTF_SHOW_CHESS_SKIN = 2108,	// 当前配置的棋子皮肤
	NTF_ON_HELP_REDDOT = 2109,	// 通知点亮知己红点
	NTF_BAG_UPDATE = 2110,	// 背包变更
	NTF_REFRESH_MELEE = 2111,	// 梦境变更通知
	NTF_CURRENT_TOURNAMENTS = 2112,	// 下发正在进行的赛事
	NTF_TOURNAMENT_BEGIN = 2113,	// 赛事开始通知
	NTF_TOURNAMENT_END = 2114,	// 赛事结束通知
	NTF_ENROLL_BEGIN = 2115,	// 报名开始通知
	NTF_ENROLL_END = 2116,	// 报名结束通知
	NTF_JOIN_TOURNAMENT_ROOM = 2119,	// 有玩家加入到赛事房间（不通知本人）
	NTF_TOURNAMENT_OUT = 2120,	// 通知客户端赛事被淘汰
	NTF_ROUND_END = 2121,	// 轮次结束通知，如果是固定战斗组模式赛事，需要在轮次结束时通知客户端本轮晋级玩家以及下一轮的分组
	NTF_TEAM_STATUS = 2122,	// 队伍状态通知
	NTF_INVITE_OBSERVE = 2123,	// 邀请观战通知
	NTF_REJECT_OBSERVE = 2124,	// 拒绝观战
	NTF_CHEST_COUNT = 2125,	// 开宝箱次数
	NTF_ACTIVITYTASK_UNLOCK = 2126,	// 通知活动任务解锁
	NTF_ADD_THIRDPVPINFO = 2128,	// 通知增加第三方比赛信息
	NTF_DEL_THIRDPVPINFO = 2129,	// 通知删除第三方比赛信息
	NTF_PS4_SERVER_ONLY = 2130,	// 通知ps4serveronly
	NTF_CHESS_LIST_ERR = 2131,	// 通知房主队内玩家自定义组卡有误
	NTF_CHEST_RECORD = 2132,	// 开宝箱记录
	NTF_GOA_INFO = 2133,	// 通知客户端营销活动平台信息
	NTF_MEDAL_INFO = 2134,	// 通知勋章编号
	NTF_MEDAL_ID = 2135,	// 通知勋章ID
	NTF_PVP_RESET = 2136,	// pvp重置
	NTF_DEL_MAIL = 2137,	// 删除邮件
	NTF_ITEM_INFO = 2138,	// 更新物品信息
	NTF_BAG = 2139,	// 通知背包
	NTF_PASSPORT_NUM = 2140,	// 通知通行证卡号
	NTF_PASSPORT_YEAR_CARD_NUM = 2141,	// 通知通行证年卡剩余次数
	NTF_TEAM_OP = 2300,
	NTF_TEAM_DISMISS = 2301,	// 队伍解散
	NTF_WEB_LOGIN = 2302,	// 通知网页登录
	NTF_SINGLE_ROUND_FLOW = 2303,	// 通知小黑盒单回合结束
	NTF_LUCK_STAR_AWARD = 2304,	// 幸运星奖励
	NTF_RECRUIT_INFO = 2305,	// 招募信息
	NTF_RECRUIT_PLAYER = 2306,	// 招募玩家
	NTF_RECRUIT_PLAYER_BATTLE = 2307,	// 招募玩家的对局数
	NTF_LUCK_MALL_GOODS = 2308,	// 幸运星商店
	NTF_BIGWINNER_EXPANDMATCH = 2309,	// 通知幸运星扩大匹配
	NTF_SWITCH_MODE_IN_TEAM = 2310,	// 队伍中切换模式
	NTF_TNGAME_END = 2311,	// 锦标赛通知下一局比赛开始时间
	NTF_PLAYER_LACK_RESOURCE = 2320,	// 有玩家缺少创意工坊门票
	NTF_FAV_MAP_REMOVED = 2321,	// 移除收藏列表的地图
	NTF_WORKSHOP_MATCH_RESULT = 2322,	// 创意工坊匹配结果（通知队伍成员）
	NTF_VERIFY_REAL_NAME = 2350,	// 通知客户端，需实名认证
	NTF_PLAYER_EXP_CHANGED = 2351,	// 玩家角色经验变化通知
	NTF_GUILD_JOIN = 2400,	// 加入公会通知
	NTF_GUILD_MEMBER_CHANGE = 2401,	// 成员变化
	NTF_GUILD_KICKOFF = 2402,	// 被踢
	NTF_GUILD_ROLE_CHANGE = 2403,	// 角色变更
	NTF_GUILD_ATTR_CHANGE = 2404,	// 标志变更
	NTF_GUILD_CHAT = 2409,	// 公会聊天
	NTF_GUILD_NEW_LOG = 2410,	// 公会日志
	NTF_GUILD_APPLICANT_CHANGE = 2411,	// 申请列表变化
	NTF_GUILD_INVITEE_CHANGE = 2412,	// 邀约列表变化
	NTF_GUILD_NEW_INVITE = 2413,	// 新邀约
	NTF_GUILD_INFO = 2414,	// 登录下发公会信息
	NTF_VNG_COMMENT_AWARD_RESET = 2420,
	NTF_AD_AWARD = 2421,	// 观看广告发奖
	NTF_AD_COUNT = 2422,	// 广告统计信息
	NTF_UI_FORBID = 2423,	// 关闭客户端UI
	NTF_PVP_UPDATE_MSGR_POS = 2522,	// 同步信使位置
	NTF_PVP_PLAYER_LOGGED_IN = 2523,	// 其他玩家登录成功
	NTF_PASS_THROUGH = 2566,
	NTF_AA = 2570,
	NTF_PVP_RECONNECT = 2571,	// 战斗重连通知
	NTF_UPDATE_BATTLE_RESULT = 2572,
	NTF_VISIT_PLAYER = 2573,
	NTF_KR_IDENTITYAUTH = 2574,	// 通知韩国身份认证
	NTF_KR_ADDICTIONTIP = 2575,	// 通知韩国沉迷提示
	NTF_LEAVE_GAME_EARLY = 2576,
	NTF_KR_ADDICTIONCOUNTDOWN = 2577,	// 通知沉迷倒计时
	NTF_ADD_BANNER = 2578,	// 添加banner通知
	NTF_REMOVE_BANNER = 2579,	// 删除banner通知
	NTF_HISTOY_CHAT_MSG = 2580,	// 刷新历史消息
	NTF_SYSTEM_GM_TIME = 2581,	// 通知系统时间, 包含gm修改时间, 主要用于gm修改时间后,通知
	NTF_CHANGE_NAME = 2582,	// 修改玩家昵称通知
	NTF_FIRST_PAY = 2583,	// 玩家首充通知
	NTF_BETON_BOUNTY = 2584,	// 玩家投注通知
	NTF_TASK_PROGRESS = 2585,	// 通行证任务进度通告
	NTF_NEW_PLAYER_GUIDE_ENDED = 2586,	// 新手引导已结束
	NTF_ACHIEVEMENT_TASK_PROGRESS = 2587,	// 任务进度通告，为了前端兼容，此处新增id，而不复用 NTF_TASK_PROGRESS
	NTF_ACHIEVEMENT_TASK_INFO = 2588,	// 任务进度通告，为了前端兼容，此处新增id，而不复用 NTF_TASK_PROGRESS
	NTF_PVP_AWARDS = 2589,	// 通知获得PVP战斗奖励
	NTF_ADD_AWARD = 2590,	// 通用物品获得通知
	NTF_LIMIT_REFRESH = 2591,	// 通知上限刷新
	NTF_UPDATE_NOTICE = 2592,	// 更新公告通知
	NTF_CALC_MMR = 2593,	// 结算mmr
	NTF_PVE_CHALLENGE_COUNT = 2594,	// 更新挑战次数 和抽奖次数
	NTF_AD_DISCOUNT = 2595,	// 观看广告商城优惠
	NTF_ITEM_ATTRIBUTES = 2596,	// 通知物品属性
	NTF_PVP_AFFIX_TRIGGER = 2597,	// 局内通知词缀属性变化
	NTF_UPDATE_PVP_DATA = 2598,	// 更新PVP数据
	NTF_UPGRADE_PASSPORT = 2599,	//升级通行证
	NTF_UODATE_TEAM_DEBUFF = 2600,	//通知debuff
	NTF_PVE_EVAL = 2601,	//通知PVE结算
	NTF_UNLOCK_CARD_GROUP = 2602,	//通知解锁卡组
	NTF_CUSTOM_PVE_ACTIVITY = 2603,	//通知 选技pve 关联活动
	NTF_GM_BAN = 2604,	//gm封禁通知
	NTF_TD_PLAYER_INFO = 2605,	//通知塔防模式数据
	NTF_MENTOR_INVITE_MSG = 2606,	//通知消息到来
	NTF_BECOME_MENTOR = 2607,	//师徒 成为师傅
	NTF_MENTOR_RELATION = 2608,	//关系建立
	NTF_MENTORSHIP_TASK = 2609,	//下发徒弟任务
	NTF_MENTORSHIP_LEVEL = 2610,	//师傅等级更新  时 下发
	NTF_CUR_DRESS_UPDATE = 2611,	//穿戴中的物品更新
	NTF_CHANGE_EXCHANGE_MARK = 2612,	//改变拍卖行标记状态
	NTF_REFRESH_PASSPORT = 2613,	//通行证刷新、
	NTF_GM_REMOVE_MAIL = 2614,	//gm删除邮件
	NTF_AUTO_USE_ITEM = 2615,	//物品自动使用触发通知
};

USTRUCT(BlueprintType)
struct  FCSHead {
	GENERATED_BODY()

	ECSMsgID MsgId;	//消息Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BodyLen;	//Body长度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Compress;	//是否压缩

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ServerId;	//服务器id

};
static void _ConvertPbToFCSHead(FCSHead &msg, const msg::CSHead *pb) {
	msg.MsgId=(ECSMsgID)pb->msgid();
	msg.BodyLen=pb->bodylen();
	msg.Compress=pb->compress();
	msg.ServerId=pb->serverid();
}


USTRUCT(BlueprintType)
struct  FCSReqBody {
	GENERATED_BODY()

	uint64 Seq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqHeart Heart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqLogin Login;	//登陆

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqVersionCheck VersionCheck;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqResourceVersionCheck ResourceVersionCheck;	//资源版本检测

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqApplyHallServer ApplyHallServer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetNumRank GetNumRank;	//获取排行榜数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWorldChat WorldChat;	//世界聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPlayersBaseInfo PlayersBaseInfo;	//玩家基础信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPlayerDetailInfo PlayerDetailInfo;	//玩家详细信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReadMail ReadMail;	//读邮件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetMailAward GetMailAward;	//领取邮件奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBuyEgg BuyEgg;	//购买扭蛋

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUserNameSet UserNameSet;	//用户名设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUserNameRandom UserNameRandom;	//随机用户名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqHeadPicSet HeadPicSet;	//设置头像

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPvp Pvp;	//pvp

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqDressChessPlayer DressChessPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqDressScene DressScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPvpLogin PvpLogin;	//pvp服登陆

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPvpEnd PvpEnd;	//pvp结束请求

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPlayerFinish PlayerFinish;	//大逃杀死亡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPlayerQuit PlayerQuit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSellItem SellItem;	//出售物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetEvalAward GetEvalAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUseChessPlayer UseChessPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuidReport GuidReport;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetCodeAward GetCodeAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRoundReport RoundReport;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqLoadingProgress LoadingProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPvpChat PvpChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChessCombine ChessCombine;	//棋子合成上报

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqExpose Expose;	//举报

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqApplyOrderId ApplyOrderId;	//申请订单Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportOrderInfo ReportOrderInfo;	//上报订单信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetItem SetItem;	//配置物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUnsetItem UnsetItem;	//取消配置物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRandomItem RandomItem;	//随机展示物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChat Chat;	//聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetChessPlayer SetChessPlayer;	//配置棋手相关属性

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUnsetChessPlayer UnsetChessPlayer;	//取消配置棋手相关属性

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetFansList GetFansList;	//获取粉丝列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqFollowPlayer FollowPlayer;	//关注玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUnfollowPlayer UnfollowPlayer;	//取消关注玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPlayersStatusInfo PlayersStatusInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqInviteJoinTeam InviteJoinTeam;	//请求邀请加入组队游戏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqJoinTeam JoinTeam;	//请求加入组队游戏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqKickOffTeamPlayer KickOffTeamPlayer;	//请求剔除队伍玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTeamMsg TeamMsg;	//队伍聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTeamReady TeamReady;	//组队成员准备

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportPayResponse ReportPayResponse;	//上报支付回执

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRejectJoinTeam RejectJoinTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqShieldChat ShieldChat;	//私聊屏蔽

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBuyPassportLevel BuyPassportLevel;	//购买通行证等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUpgradePassport UpgradePassport;	//购买通行证

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetPassportLevelAward GetPassportLevelAward;	//获取通行证等级奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetPassportTaskAward GetPassportTaskAward;	//获取通行证任务奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTelBook TelBook;	//通讯录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqActivatePassport ActivatePassport;	//激活通行证

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRankSeasonEval RankSeasonEval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBindAccount BindAccount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqIncAdShowCount IncAdsShowCount;	//增加广告浏览次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUseBonusCard UseBonusCard;	//使用加成卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetSeasonAward GetSeasonAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetAlphaActivityAward GetAlphaActivityAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetLanguageData GetLanguageData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetActivityAward GetActivityAward;	//获取活动奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetActivityData GetActivityData;	//获取活动数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSendSms SendSms;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetMeleeAward GetMeleeAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqAddAiToTeam AddAiToTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqShare Share;	//分享

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSkipInterface SkipInterface;	//跳转界面

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTeamGame TeamGame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetTeamMode SetTeamMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetHistoryPvpShowPermission HistoryPvpShowPermission;	//设置历史战绩查看权限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSearchTeam SearchTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqApplyChat ApplyChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChatLogin ChatLogin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqProbeNetDelay ProbeNetDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetEggs GetEggs;	//获取当前可展示的商品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBuyGoods BuyGoods;	//购买特价礼包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqExchangePassportGoods ExchangePassportGoods;	//通行证兑换商店购买

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUsePassportTaskCard UsePassportTaskCard;	//使用通行证任务卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqOpenRandChest OpenRandChest;	//打开随机宝箱, 自选宝箱

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqEggLottery EggLottery;	//扭蛋抽奖

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqQueryDiamondBalance QueryDiamondBalance;	//向渠道查询钻石充值信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUseItem UseItem;	//使用道具

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUseExperienceCard UseExperienceCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRandTargetItem RandTargetItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqAddBlacklist AddBlacklist;	//添加黑名单

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRemoveBlacklist RemoveBlacklist;	//删除黑名单

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportPlayerBirth ReportPlayerBirth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportInfoInput ReportInfoInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSendVerificationCode SendVerificationCode;	//发送验证码

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBindPhoneNumber BindPhoneNumber;	//绑定手机号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWorldInvite WorldInvite;	//邀约

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRemoveExpireItem RemoveExpireItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetMallGoods GetMallGoods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBuyMallGoods BuyMallGoods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBindSharingCode BindSharingCode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWXBlessBag WXBlessBag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUpdateFriendsInGame UpdateFriendsInGame;	//更新同玩好友数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqShareReward ShareReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqAllFightInfo AllFightInfo;	//获取全民对局信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetOldPlayer GetOldPlayer;	//获取老账号信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBindOldPlayer BindOldPlayer;	//绑定老账号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSendVerificationCodeWithCheckRedis SendVerificationCodeWithCheckRedis;	//发送验证码（获取老账号）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportSetting ReportSetting;	//上报玩家设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqAntiData AntiData;	//发送Anti数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTlogData TlogData;	//发送Tlog数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqDaySign DaySign;	//每日签到

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqDayFitAvoid DayFitAvoid;	//上报每日宜忌

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqShareCountAward ShareCountAward;	//领取累计分享奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqActItemExch ActItemExch;	//活动集道具兑换

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRealationStar RealationStar;	//关系链幸运星邀请

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetRealationStarInviteSucc GetRealationStarInviteSucc;	//获取关系链幸运星邀请成功玩家列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetRealationStar GetRealationStar;	//获取关系链幸运星邀请玩家列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetActRecord ReqActRecord;	//获取活动记录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqJoinVoiceTeam JoinVoiceTeam;	//加入Team语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqJoinVoicePvp JoinVoicePvp;	//加入Pvp语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqJoinVoiceCamp JoinVoiceCamp;	//加入Camp语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUserCountrySet UserCountrySet;	//用户国家设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqOfflineInviteJoinTeam OfflineInviteJoinTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqObserve Observe;	//观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetRecommendPvp GetRecommendPvp;	//获取推荐观战战局

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqObserveLogin ObserveLogin;	//观战玩家登录PVP服

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqQuitObserve QuitObserve;	//退出观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetObserveInfo GetObserveInfo;	//获取观战人数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqFreeFlow FreeFlow;	//免流查询

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetPushToken SetPushToken;	//设置玩家消息推送token

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTlogEvent TlogEvent;	//客户端请求TLOG事件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWxVVipAward WxVVipAward;	//获取微信大玩家奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetRelationStarWX RelationStarWX;	//获取微信关系链

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSendWxRedPacket SendWxRedPacket;	//发送微信红包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecvWxRedPacket RecvWxRedPacket;	//领取微信红包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWxRedPktLike WxRedPktLike;	//微信大玩家点赞

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWxRedPktRank WxRedPktRank;	//微信大玩家点赞排行

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqObservePrivilege SetObservePrivilege;	//观战权限设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPresetFastChat PresetFastChat;	//预设快捷聊天文本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChangeSlotTeam ChangeSlotTeam;	//切换位置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChangeSubModeTeam ChangeSubModeTeam;	//切换子模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqConfirmChangeSlotTeam ConfirmChangeSlotTeam;	//确认切换位置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPvpRoundEnd PvpRoundEnd;	//回合结束

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqObserveChatLogin ObserveChatLogin;	//观战聊天登录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPvpConfirm PvpConfirm;	//游戏确认

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqActivityPicShare ActivityPicShare;	//大图分享

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBindOldBusinessPlayer BindOldBusinessPlayer;	//绑定老business玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTranslate Translate;	// 翻译

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSubmitQuestionnaire SubmitQuestionnaire;	//提交问卷答案

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqCancelChangeSlot CancelChangeSlot;	// 取消换位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetChessSkin SetChessSkin;	//棋子皮肤配置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUnsetChessSkin UnsetChessSkin;	//棋子皮肤取消配置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqCompose Compose;	//合成

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqOffHelpReddot OffHelpReddot;	//熄灭知己红点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqVideo Video;	//获取视频信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChangeLanguage ChangeLanguage;	//修改游戏语种

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportVideoPlay VideoPlay;	//上报视频信息播放

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetProvince SetProvince;	//设置省份

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqLongyuanVoice LongyuanVoice;	//龙渊语音参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqEnrollTournament EnrollTournament;	//报名赛事

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqJoinTournamentRoom JoinTournamentRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTournamentPointAward TournamentPointAward;	//请求赛事积分进度奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqDealWebMail DealWebMail;	//处理开放平台邮件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetEnrollPlayers GetEnrollPlayers;	//获取报名玩家列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChallengeAgain ChallengeAgain;	//再次挑战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqHistoryChatMsg HistoryChat;	//历史聊天消息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetFriendInvisible SetFriendInvisible;	//好友不可见

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetObserveAward GetObserveAward;	//获取观战任务奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqInviteObserve InviteObserve;	//邀请观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRejectObserve RejectObserve;	//拒绝观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetTxPlayer GetTxPlayer;	//请求Tx玩家信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChooseTxPlayer ChooseTxPlayer;	//选择绑定Tx玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetThirdPvpInfo GetThirdPvpInfo;	//获取第三方战斗信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMarkPlayerGuide MarkPlayerGuide;	//标记玩家新手引导

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMarkChessSkinClicked MarkChessSkinClicked;	// 标记皮肤点击

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecruitInvitePlayer RecruitInvitePlayer;	//请求邀请玩家ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecruitBindInviter RecruitBindInviter;	//绑定邀请者

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqQueryPs4Entitlements QueryPs4Entitlements;	//ps4 查询

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqActDaySign ActDaySign;	//每日签到活动

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqHaveThirdPvp HaveThirdPvpInfo;	//是否第三方战斗进行

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqActivityMall ActivityMall;	//获取回流商店内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPsOnly PsOnly;	//设置玩家级的ps only

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChangeChannelType ChangeChannelType;	//设置渠道

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqCustomCardOpt CustomCardOpt;	//自定义组卡玩法操作 获取;保存;设置;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqStaticsReport StaticsReport;	//上报打点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChampionHistory ChampionHistory;	//历届冠军信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTournamentLastTopRank TournamentLastTopRank;	//上届锦标赛top8

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBigWinnerExpandMatch BigWinnerExpandMatch;	//扩大匹配

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBigWinnerDailyAward BigWinnerDailyAward;	//领取低保

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBigWinnerScoreHistory BigWinnerScoreHistory;	//积分历史

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSmeltItem SmeltItem;	//熔炼

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPVEUpTalentLevel PVEUpTalentLevel;	//PVE升级天赋

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPVELuckyAward LuckyAward;	//PVE抽奖

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqApplyChannel ApplyChannel;	//申请渠道聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTeamOP TeamOP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqOBTeamInfo OBTeamInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportHeadIconUrl HeadIconUrl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetPvpServerGroup GetPvpServerGroup;	//获取PVP分组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportPvpInfo ReportPvpInfo;	//上报选择的pvp分组及ping值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChoosePlayer ChoosePlayer;	//角色多选一

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPingTest PingTest;	//延迟测试

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportRegionInfo ReportRegionInfo;	//上报各区域的延迟信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecalledPlayer RecalledPlaeyr;	//获取已经召回玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWebLogin WebLogin;	//网页登录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqInviteCodeReset InviteCodeReset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecallReward RecallReward;	//获取召回奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSwitchToCommonMatch SwitchToCommonMatch;	//切换到全球匹配队列

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSwitchModeInTeam SwitchModeInTeam;	// 队伍中切换模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetTNRoomState GetTNRoomState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWorkshopMatch WorkshopMatch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBuyWorkshopTicket BuyWorkshopTicket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqFavouriteWorkshopMap FavouriteWorkshopMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqShortcutMapsOP ShortcutMapsOP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPlayersTournamentInfo PlayersTournamentInfo;	//玩家锦标赛信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqScoreWorkshopMap ScoreWorkshopMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMapsVisitedByFriends MapsVisitedByFriends;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqVerifyRealName VerifyRealName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqFakePay FakePay;	// 伪充值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildCreate GuildCreate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildApply GuildApply;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildHome GuildHome;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildInfo GuildInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildApprove GuildApprove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildSetRole GuildRole;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildModify GuildModify;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildKickoff GuildKickoff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildDismiss GuildDismiss;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildExit GuildExit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildChat GuildChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildList GuildList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildRecommendPlayers GuildRecommendPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildInviteList GuildInviteList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildInvite GuildInvite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildResign GuildResign;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGuildRejectInvite GuildRejectInvite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetVngCommentAward GetVngCommentAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqLevelupChest LevelupChest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWatchAd WatchAd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqQueryPsTournamentRoom PsTournamentRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetAdCumulateAward GetAdCumulateAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetMessengerPos SetMessengerPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUpdateAntiAddictionTime UpdateAntiAddictionTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqCancelReconnect CancelReconnect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReconnect Reconnect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPassThrough PassThrough;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqVisitPlayer VisitPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqLeaveGameEarly LeaveGameEarly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGDCommonBin GDCommonBin;	// common游戏数据配置请求

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGDCommonBinData GDBinData;	// common bin data

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqAutoBattleOP AutoBattleOP;	// 自动战斗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRestrictUser RestrictUser;	// 限制用户

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqEquipSelectRate EquipSelectRate;	// 装备选取率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqReportAbsent ReportAbsent;	// 上报缺席

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecommendWeek RecommendWeek;	// 请求推荐阵容周榜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecommendOfficial RecommendOfficial;	// 请求推荐阵容官方

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecommendLatest RecommendLatest;	// 请求推荐阵容最新

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecommendHistory RecommendHistory;	// 请求个人历史阵容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecommendCollect RecommendCollect;	// 请求阵容收藏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecommendSet RecommendSet;	// 请求阵容推荐设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecommendGetCollection RecommendGetCollection;	// 获取阵容收藏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRecommendEquip RecommendEquip;	// 获取推荐装备

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqLoginCancel LoginCancel;	// 取消登录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqConvertDebris ConvertDebris;	// 兑换碎片

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUseProtectionCard ProtectionCard;	// 段位保护

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUsePassportCard UsePassportCard;	// 使用通行证激活卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetMedal SetMedal;	// 佩戴勋章

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUnSetMedal UnSetMedal;	// 取下勋章

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPlayerMedals PlayerMedals;	// 勋章列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUpdateHotDot UpdateHotDot;	//红点信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqQueryHotDot QueryHotDot;	//查询红点信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetCache SetCache;	//查询红点信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetCache GetCache;	//查询红点信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBuyChallengeCount BuyChallengeCount;	//购买挑战记录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetPveRank GetPveRank;	//获取pve排行榜记录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqLogin AuthAccount;	//验证并返回用户基础信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUnbindAccount UnbindAccount;	//解绑账号，目前只支持 ps->ly

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBagToItem BagToItem;	//转移背包物品到玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqIdentifyItem IdentifyItem;	// 鉴定物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqInsetItemAffix InsetItemAffix;	// 装备词缀

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUnsetItemAffix UnsetItemAffix;	// 卸载词缀数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetDefaultAttributes SetDefaultAttributes;	// 设置玩家默认的属性

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqCheckCancel CheckCancel;	// 检测注销条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqCancelAccount CancelAccount;	// 注销账户

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqOAuthApp OAuthApp;	// 掌上龙渊授权

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetSelfNumRankData GetSelfNumRankData;	// 获取个人多个排行榜数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUpdateCardGroup UpdateCardGroup;	// 更新卡组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUpdateCardGroupName UpdateCardGroupName;	// 更新卡组名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBuyPveBuff BuyPveBuff;	// 购买pve特权或者buff

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetCardGroup SetCardGroup;	// 局内设置卡组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqBuyPveChessTemplate BuyPveChessTemplate;	// 购买棋子和技能

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPveUnlockChessTemplate PveUnlockChessTemplate;	// 解锁棋子和技能

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPveSetTeamDeBuff PveSetTeamDeBuff;	// 房间内修改词缀难度

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqChoseCardGroup ChoseCardGroup;	// 局内选择卡组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRemoveOvertimeBuff RemoveOvertimeBuff;	// 删除过期buff

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateNewCardGroupSign UpdateNewCardGroupSign;	// 局外卡组新手标记去校

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTDGetOnHookAward TDGetOnHookAward;	// 获取挂机奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCsReqTDDraw TDDraw;	// 抽卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCsReqTDBuyCard TDBuyCard;	// 购买卡券

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTDSetCardGroup TDSetCardGroup;	// 设置卡组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTDLevelUp TDLevelUp;	// 升级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqTDEquip TDEquip;	// 装备和卸下

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMentorUpdateSetting MentorUpdateSetting;	// 师徒 修改设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMentorInvite MentorInvite;	// 师徒邀请信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMentorConfirmInvite MentorConfirmInvite;	// 确认师徒邀请信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMentorRecommendList MentorRecommendList;	// 师傅徒弟推荐列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMentorGetTaskAward MentorGetTaskAward;	// 任务获取奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMentorGraduate MentorGraduate;	// 出师

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMentorRelieveRelation MentorRelieveRelation;	// 解除关系

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetMentorInfo GetMentorInfo;	// 获取师傅信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqMentorGetInviteMsg MentorGetInviteMsg;	// 获取邀请信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUpdateCardGroupBetter UpdateCardGroupBetter;	// 设置卡组优化

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqUpdateCardGroupSetting UpdateCardGroupSetting;	// 卡组设置更新

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetContent SetContent;	// 设置文字数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetBalance GetBalance;	// 获取余额

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqRechargeBalance RechargeBalance;	// 充值余额

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqWithdrawBalance WithdrawBalance;	// 提现余额

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqPersonalRecommendMall PersonalRecommendMall;	// 精细化投放

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqGetMedalChestAward GetMedalChestAward;	// 成就勋章任务宝箱奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSReqSetItemAutoUse SetItemAutoUse;	// 设置物品自动使用

};
static void _ConvertPbToFCSReqBody(FCSReqBody &msg, const msg::CSReqBody *pb) {
	msg.Seq=pb->seq();
	_ConvertPbToFCSReqHeart(msg.Heart, &pb->heart());
	_ConvertPbToFCSReqLogin(msg.Login, &pb->login());
	_ConvertPbToFCSReqVersionCheck(msg.VersionCheck, &pb->versioncheck());
	_ConvertPbToFCSReqResourceVersionCheck(msg.ResourceVersionCheck, &pb->resourceversioncheck());
	_ConvertPbToFCSReqApplyHallServer(msg.ApplyHallServer, &pb->applyhallserver());
	_ConvertPbToFCSReqGetNumRank(msg.GetNumRank, &pb->getnumrank());
	_ConvertPbToFCSReqWorldChat(msg.WorldChat, &pb->worldchat());
	_ConvertPbToFCSReqPlayersBaseInfo(msg.PlayersBaseInfo, &pb->playersbaseinfo());
	_ConvertPbToFCSReqPlayerDetailInfo(msg.PlayerDetailInfo, &pb->playerdetailinfo());
	_ConvertPbToFCSReqReadMail(msg.ReadMail, &pb->readmail());
	_ConvertPbToFCSReqGetMailAward(msg.GetMailAward, &pb->getmailaward());
	_ConvertPbToFCSReqBuyEgg(msg.BuyEgg, &pb->buyegg());
	_ConvertPbToFCSReqUserNameSet(msg.UserNameSet, &pb->usernameset());
	_ConvertPbToFCSReqUserNameRandom(msg.UserNameRandom, &pb->usernamerandom());
	_ConvertPbToFCSReqHeadPicSet(msg.HeadPicSet, &pb->headpicset());
	_ConvertPbToFCSReqPvp(msg.Pvp, &pb->pvp());
	_ConvertPbToFCSReqDressChessPlayer(msg.DressChessPlayer, &pb->dresschessplayer());
	_ConvertPbToFCSReqDressScene(msg.DressScene, &pb->dressscene());
	_ConvertPbToFCSReqPvpLogin(msg.PvpLogin, &pb->pvplogin());
	_ConvertPbToFCSReqPvpEnd(msg.PvpEnd, &pb->pvpend());
	_ConvertPbToFCSReqPlayerFinish(msg.PlayerFinish, &pb->playerfinish());
	_ConvertPbToFCSReqPlayerQuit(msg.PlayerQuit, &pb->playerquit());
	_ConvertPbToFCSReqSellItem(msg.SellItem, &pb->sellitem());
	_ConvertPbToFCSReqGetEvalAward(msg.GetEvalAward, &pb->getevalaward());
	_ConvertPbToFCSReqUseChessPlayer(msg.UseChessPlayer, &pb->usechessplayer());
	_ConvertPbToFCSReqGuidReport(msg.GuidReport, &pb->guidreport());
	_ConvertPbToFCSReqGetCodeAward(msg.GetCodeAward, &pb->getcodeaward());
	_ConvertPbToFCSReqRoundReport(msg.RoundReport, &pb->roundreport());
	_ConvertPbToFCSReqLoadingProgress(msg.LoadingProgress, &pb->loadingprogress());
	_ConvertPbToFCSReqPvpChat(msg.PvpChat, &pb->pvpchat());
	_ConvertPbToFCSReqChessCombine(msg.ChessCombine, &pb->chesscombine());
	_ConvertPbToFCSReqExpose(msg.Expose, &pb->expose());
	_ConvertPbToFCSReqApplyOrderId(msg.ApplyOrderId, &pb->applyorderid());
	_ConvertPbToFCSReqReportOrderInfo(msg.ReportOrderInfo, &pb->reportorderinfo());
	_ConvertPbToFCSReqSetItem(msg.SetItem, &pb->setitem());
	_ConvertPbToFCSReqUnsetItem(msg.UnsetItem, &pb->unsetitem());
	_ConvertPbToFCSReqRandomItem(msg.RandomItem, &pb->randomitem());
	_ConvertPbToFCSReqChat(msg.Chat, &pb->chat());
	_ConvertPbToFCSReqSetChessPlayer(msg.SetChessPlayer, &pb->setchessplayer());
	_ConvertPbToFCSReqUnsetChessPlayer(msg.UnsetChessPlayer, &pb->unsetchessplayer());
	_ConvertPbToFCSReqGetFansList(msg.GetFansList, &pb->getfanslist());
	_ConvertPbToFCSReqFollowPlayer(msg.FollowPlayer, &pb->followplayer());
	_ConvertPbToFCSReqUnfollowPlayer(msg.UnfollowPlayer, &pb->unfollowplayer());
	_ConvertPbToFCSReqPlayersStatusInfo(msg.PlayersStatusInfo, &pb->playersstatusinfo());
	_ConvertPbToFCSReqInviteJoinTeam(msg.InviteJoinTeam, &pb->invitejointeam());
	_ConvertPbToFCSReqJoinTeam(msg.JoinTeam, &pb->jointeam());
	_ConvertPbToFCSReqKickOffTeamPlayer(msg.KickOffTeamPlayer, &pb->kickoffteamplayer());
	_ConvertPbToFCSReqTeamMsg(msg.TeamMsg, &pb->teammsg());
	_ConvertPbToFCSReqTeamReady(msg.TeamReady, &pb->teamready());
	_ConvertPbToFCSReqReportPayResponse(msg.ReportPayResponse, &pb->reportpayresponse());
	_ConvertPbToFCSReqRejectJoinTeam(msg.RejectJoinTeam, &pb->rejectjointeam());
	_ConvertPbToFCSReqShieldChat(msg.ShieldChat, &pb->shieldchat());
	_ConvertPbToFCSReqBuyPassportLevel(msg.BuyPassportLevel, &pb->buypassportlevel());
	_ConvertPbToFCSReqUpgradePassport(msg.UpgradePassport, &pb->upgradepassport());
	_ConvertPbToFCSReqGetPassportLevelAward(msg.GetPassportLevelAward, &pb->getpassportlevelaward());
	_ConvertPbToFCSReqGetPassportTaskAward(msg.GetPassportTaskAward, &pb->getpassporttaskaward());
	_ConvertPbToFCSReqTelBook(msg.TelBook, &pb->telbook());
	_ConvertPbToFCSReqActivatePassport(msg.ActivatePassport, &pb->activatepassport());
	_ConvertPbToFCSReqRankSeasonEval(msg.RankSeasonEval, &pb->rankseasoneval());
	_ConvertPbToFCSReqBindAccount(msg.BindAccount, &pb->bindaccount());
	_ConvertPbToFCSReqIncAdShowCount(msg.IncAdsShowCount, &pb->incadsshowcount());
	_ConvertPbToFCSReqUseBonusCard(msg.UseBonusCard, &pb->usebonuscard());
	_ConvertPbToFCSReqGetSeasonAward(msg.GetSeasonAward, &pb->getseasonaward());
	_ConvertPbToFCSReqGetAlphaActivityAward(msg.GetAlphaActivityAward, &pb->getalphaactivityaward());
	_ConvertPbToFCSReqGetLanguageData(msg.GetLanguageData, &pb->getlanguagedata());
	_ConvertPbToFCSReqGetActivityAward(msg.GetActivityAward, &pb->getactivityaward());
	_ConvertPbToFCSReqGetActivityData(msg.GetActivityData, &pb->getactivitydata());
	_ConvertPbToFCSReqSendSms(msg.SendSms, &pb->sendsms());
	_ConvertPbToFCSReqGetMeleeAward(msg.GetMeleeAward, &pb->getmeleeaward());
	_ConvertPbToFCSReqAddAiToTeam(msg.AddAiToTeam, &pb->addaitoteam());
	_ConvertPbToFCSReqShare(msg.Share, &pb->share());
	_ConvertPbToFCSReqSkipInterface(msg.SkipInterface, &pb->skipinterface());
	_ConvertPbToFCSReqTeamGame(msg.TeamGame, &pb->teamgame());
	_ConvertPbToFCSReqSetTeamMode(msg.SetTeamMode, &pb->setteammode());
	_ConvertPbToFCSReqSetHistoryPvpShowPermission(msg.HistoryPvpShowPermission, &pb->historypvpshowpermission());
	_ConvertPbToFCSReqSearchTeam(msg.SearchTeam, &pb->searchteam());
	_ConvertPbToFCSReqApplyChat(msg.ApplyChat, &pb->applychat());
	_ConvertPbToFCSReqChatLogin(msg.ChatLogin, &pb->chatlogin());
	_ConvertPbToFCSReqProbeNetDelay(msg.ProbeNetDelay, &pb->probenetdelay());
	_ConvertPbToFCSReqGetEggs(msg.GetEggs, &pb->geteggs());
	_ConvertPbToFCSReqBuyGoods(msg.BuyGoods, &pb->buygoods());
	_ConvertPbToFCSReqExchangePassportGoods(msg.ExchangePassportGoods, &pb->exchangepassportgoods());
	_ConvertPbToFCSReqUsePassportTaskCard(msg.UsePassportTaskCard, &pb->usepassporttaskcard());
	_ConvertPbToFCSReqOpenRandChest(msg.OpenRandChest, &pb->openrandchest());
	_ConvertPbToFCSReqEggLottery(msg.EggLottery, &pb->egglottery());
	_ConvertPbToFCSReqQueryDiamondBalance(msg.QueryDiamondBalance, &pb->querydiamondbalance());
	_ConvertPbToFCSReqUseItem(msg.UseItem, &pb->useitem());
	_ConvertPbToFCSReqUseExperienceCard(msg.UseExperienceCard, &pb->useexperiencecard());
	_ConvertPbToFCSReqRandTargetItem(msg.RandTargetItem, &pb->randtargetitem());
	_ConvertPbToFCSReqAddBlacklist(msg.AddBlacklist, &pb->addblacklist());
	_ConvertPbToFCSReqRemoveBlacklist(msg.RemoveBlacklist, &pb->removeblacklist());
	_ConvertPbToFCSReqReportPlayerBirth(msg.ReportPlayerBirth, &pb->reportplayerbirth());
	_ConvertPbToFCSReqReportInfoInput(msg.ReportInfoInput, &pb->reportinfoinput());
	_ConvertPbToFCSReqSendVerificationCode(msg.SendVerificationCode, &pb->sendverificationcode());
	_ConvertPbToFCSReqBindPhoneNumber(msg.BindPhoneNumber, &pb->bindphonenumber());
	_ConvertPbToFCSReqWorldInvite(msg.WorldInvite, &pb->worldinvite());
	_ConvertPbToFCSReqRemoveExpireItem(msg.RemoveExpireItem, &pb->removeexpireitem());
	_ConvertPbToFCSReqGetMallGoods(msg.GetMallGoods, &pb->getmallgoods());
	_ConvertPbToFCSReqBuyMallGoods(msg.BuyMallGoods, &pb->buymallgoods());
	_ConvertPbToFCSReqBindSharingCode(msg.BindSharingCode, &pb->bindsharingcode());
	_ConvertPbToFCSReqWXBlessBag(msg.WXBlessBag, &pb->wxblessbag());
	_ConvertPbToFCSReqUpdateFriendsInGame(msg.UpdateFriendsInGame, &pb->updatefriendsingame());
	_ConvertPbToFCSReqShareReward(msg.ShareReward, &pb->sharereward());
	_ConvertPbToFCSReqAllFightInfo(msg.AllFightInfo, &pb->allfightinfo());
	_ConvertPbToFCSReqGetOldPlayer(msg.GetOldPlayer, &pb->getoldplayer());
	_ConvertPbToFCSReqBindOldPlayer(msg.BindOldPlayer, &pb->bindoldplayer());
	_ConvertPbToFCSReqSendVerificationCodeWithCheckRedis(msg.SendVerificationCodeWithCheckRedis, &pb->sendverificationcodewithcheckredis());
	_ConvertPbToFCSReqReportSetting(msg.ReportSetting, &pb->reportsetting());
	_ConvertPbToFCSReqAntiData(msg.AntiData, &pb->antidata());
	_ConvertPbToFCSReqTlogData(msg.TlogData, &pb->tlogdata());
	_ConvertPbToFCSReqDaySign(msg.DaySign, &pb->daysign());
	_ConvertPbToFCSReqDayFitAvoid(msg.DayFitAvoid, &pb->dayfitavoid());
	_ConvertPbToFCSReqShareCountAward(msg.ShareCountAward, &pb->sharecountaward());
	_ConvertPbToFCSReqActItemExch(msg.ActItemExch, &pb->actitemexch());
	_ConvertPbToFCSReqRealationStar(msg.RealationStar, &pb->realationstar());
	_ConvertPbToFCSReqGetRealationStarInviteSucc(msg.GetRealationStarInviteSucc, &pb->getrealationstarinvitesucc());
	_ConvertPbToFCSReqGetRealationStar(msg.GetRealationStar, &pb->getrealationstar());
	_ConvertPbToFCSReqGetActRecord(msg.ReqActRecord, &pb->reqactrecord());
	_ConvertPbToFCSReqJoinVoiceTeam(msg.JoinVoiceTeam, &pb->joinvoiceteam());
	_ConvertPbToFCSReqJoinVoicePvp(msg.JoinVoicePvp, &pb->joinvoicepvp());
	_ConvertPbToFCSReqJoinVoiceCamp(msg.JoinVoiceCamp, &pb->joinvoicecamp());
	_ConvertPbToFCSReqUserCountrySet(msg.UserCountrySet, &pb->usercountryset());
	_ConvertPbToFCSReqOfflineInviteJoinTeam(msg.OfflineInviteJoinTeam, &pb->offlineinvitejointeam());
	_ConvertPbToFCSReqObserve(msg.Observe, &pb->observe());
	_ConvertPbToFCSReqGetRecommendPvp(msg.GetRecommendPvp, &pb->getrecommendpvp());
	_ConvertPbToFCSReqObserveLogin(msg.ObserveLogin, &pb->observelogin());
	_ConvertPbToFCSReqQuitObserve(msg.QuitObserve, &pb->quitobserve());
	_ConvertPbToFCSReqGetObserveInfo(msg.GetObserveInfo, &pb->getobserveinfo());
	_ConvertPbToFCSReqFreeFlow(msg.FreeFlow, &pb->freeflow());
	_ConvertPbToFCSReqSetPushToken(msg.SetPushToken, &pb->setpushtoken());
	_ConvertPbToFCSReqTlogEvent(msg.TlogEvent, &pb->tlogevent());
	_ConvertPbToFCSReqWxVVipAward(msg.WxVVipAward, &pb->wxvvipaward());
	_ConvertPbToFCSReqGetRelationStarWX(msg.RelationStarWX, &pb->relationstarwx());
	_ConvertPbToFCSReqSendWxRedPacket(msg.SendWxRedPacket, &pb->sendwxredpacket());
	_ConvertPbToFCSReqRecvWxRedPacket(msg.RecvWxRedPacket, &pb->recvwxredpacket());
	_ConvertPbToFCSReqWxRedPktLike(msg.WxRedPktLike, &pb->wxredpktlike());
	_ConvertPbToFCSReqWxRedPktRank(msg.WxRedPktRank, &pb->wxredpktrank());
	_ConvertPbToFCSReqObservePrivilege(msg.SetObservePrivilege, &pb->setobserveprivilege());
	_ConvertPbToFCSReqPresetFastChat(msg.PresetFastChat, &pb->presetfastchat());
	_ConvertPbToFCSReqChangeSlotTeam(msg.ChangeSlotTeam, &pb->changeslotteam());
	_ConvertPbToFCSReqChangeSubModeTeam(msg.ChangeSubModeTeam, &pb->changesubmodeteam());
	_ConvertPbToFCSReqConfirmChangeSlotTeam(msg.ConfirmChangeSlotTeam, &pb->confirmchangeslotteam());
	_ConvertPbToFCSReqPvpRoundEnd(msg.PvpRoundEnd, &pb->pvproundend());
	_ConvertPbToFCSReqObserveChatLogin(msg.ObserveChatLogin, &pb->observechatlogin());
	_ConvertPbToFCSReqPvpConfirm(msg.PvpConfirm, &pb->pvpconfirm());
	_ConvertPbToFCSReqActivityPicShare(msg.ActivityPicShare, &pb->activitypicshare());
	_ConvertPbToFCSReqBindOldBusinessPlayer(msg.BindOldBusinessPlayer, &pb->bindoldbusinessplayer());
	_ConvertPbToFCSReqTranslate(msg.Translate, &pb->translate());
	_ConvertPbToFCSReqSubmitQuestionnaire(msg.SubmitQuestionnaire, &pb->submitquestionnaire());
	_ConvertPbToFCSReqCancelChangeSlot(msg.CancelChangeSlot, &pb->cancelchangeslot());
	_ConvertPbToFCSReqSetChessSkin(msg.SetChessSkin, &pb->setchessskin());
	_ConvertPbToFCSReqUnsetChessSkin(msg.UnsetChessSkin, &pb->unsetchessskin());
	_ConvertPbToFCSReqCompose(msg.Compose, &pb->compose());
	_ConvertPbToFCSReqOffHelpReddot(msg.OffHelpReddot, &pb->offhelpreddot());
	_ConvertPbToFCSReqVideo(msg.Video, &pb->video());
	_ConvertPbToFCSReqChangeLanguage(msg.ChangeLanguage, &pb->changelanguage());
	_ConvertPbToFCSReqReportVideoPlay(msg.VideoPlay, &pb->videoplay());
	_ConvertPbToFCSReqSetProvince(msg.SetProvince, &pb->setprovince());
	_ConvertPbToFCSReqLongyuanVoice(msg.LongyuanVoice, &pb->longyuanvoice());
	_ConvertPbToFCSReqEnrollTournament(msg.EnrollTournament, &pb->enrolltournament());
	_ConvertPbToFCSReqJoinTournamentRoom(msg.JoinTournamentRoom, &pb->jointournamentroom());
	_ConvertPbToFCSReqTournamentPointAward(msg.TournamentPointAward, &pb->tournamentpointaward());
	_ConvertPbToFCSReqDealWebMail(msg.DealWebMail, &pb->dealwebmail());
	_ConvertPbToFCSReqGetEnrollPlayers(msg.GetEnrollPlayers, &pb->getenrollplayers());
	_ConvertPbToFCSReqChallengeAgain(msg.ChallengeAgain, &pb->challengeagain());
	_ConvertPbToFCSReqHistoryChatMsg(msg.HistoryChat, &pb->historychat());
	_ConvertPbToFCSReqSetFriendInvisible(msg.SetFriendInvisible, &pb->setfriendinvisible());
	_ConvertPbToFCSReqGetObserveAward(msg.GetObserveAward, &pb->getobserveaward());
	_ConvertPbToFCSReqInviteObserve(msg.InviteObserve, &pb->inviteobserve());
	_ConvertPbToFCSReqRejectObserve(msg.RejectObserve, &pb->rejectobserve());
	_ConvertPbToFCSReqGetTxPlayer(msg.GetTxPlayer, &pb->gettxplayer());
	_ConvertPbToFCSReqChooseTxPlayer(msg.ChooseTxPlayer, &pb->choosetxplayer());
	_ConvertPbToFCSReqGetThirdPvpInfo(msg.GetThirdPvpInfo, &pb->getthirdpvpinfo());
	_ConvertPbToFCSReqMarkPlayerGuide(msg.MarkPlayerGuide, &pb->markplayerguide());
	_ConvertPbToFCSReqMarkChessSkinClicked(msg.MarkChessSkinClicked, &pb->markchessskinclicked());
	_ConvertPbToFCSReqRecruitInvitePlayer(msg.RecruitInvitePlayer, &pb->recruitinviteplayer());
	_ConvertPbToFCSReqRecruitBindInviter(msg.RecruitBindInviter, &pb->recruitbindinviter());
	_ConvertPbToFCSReqQueryPs4Entitlements(msg.QueryPs4Entitlements, &pb->queryps4entitlements());
	_ConvertPbToFCSReqActDaySign(msg.ActDaySign, &pb->actdaysign());
	_ConvertPbToFCSReqHaveThirdPvp(msg.HaveThirdPvpInfo, &pb->havethirdpvpinfo());
	_ConvertPbToFCSReqActivityMall(msg.ActivityMall, &pb->activitymall());
	_ConvertPbToFCSReqPsOnly(msg.PsOnly, &pb->psonly());
	_ConvertPbToFCSReqChangeChannelType(msg.ChangeChannelType, &pb->changechanneltype());
	_ConvertPbToFCSReqCustomCardOpt(msg.CustomCardOpt, &pb->customcardopt());
	_ConvertPbToFCSReqStaticsReport(msg.StaticsReport, &pb->staticsreport());
	_ConvertPbToFCSReqChampionHistory(msg.ChampionHistory, &pb->championhistory());
	_ConvertPbToFCSReqTournamentLastTopRank(msg.TournamentLastTopRank, &pb->tournamentlasttoprank());
	_ConvertPbToFCSReqBigWinnerExpandMatch(msg.BigWinnerExpandMatch, &pb->bigwinnerexpandmatch());
	_ConvertPbToFCSReqBigWinnerDailyAward(msg.BigWinnerDailyAward, &pb->bigwinnerdailyaward());
	_ConvertPbToFCSReqBigWinnerScoreHistory(msg.BigWinnerScoreHistory, &pb->bigwinnerscorehistory());
	_ConvertPbToFCSReqSmeltItem(msg.SmeltItem, &pb->smeltitem());
	_ConvertPbToFCSReqPVEUpTalentLevel(msg.PVEUpTalentLevel, &pb->pveuptalentlevel());
	_ConvertPbToFCSReqPVELuckyAward(msg.LuckyAward, &pb->luckyaward());
	_ConvertPbToFCSReqApplyChannel(msg.ApplyChannel, &pb->applychannel());
	_ConvertPbToFCSReqTeamOP(msg.TeamOP, &pb->teamop());
	_ConvertPbToFCSReqOBTeamInfo(msg.OBTeamInfo, &pb->obteaminfo());
	_ConvertPbToFCSReqReportHeadIconUrl(msg.HeadIconUrl, &pb->headiconurl());
	_ConvertPbToFCSReqGetPvpServerGroup(msg.GetPvpServerGroup, &pb->getpvpservergroup());
	_ConvertPbToFCSReqReportPvpInfo(msg.ReportPvpInfo, &pb->reportpvpinfo());
	_ConvertPbToFCSReqChoosePlayer(msg.ChoosePlayer, &pb->chooseplayer());
	_ConvertPbToFCSReqPingTest(msg.PingTest, &pb->pingtest());
	_ConvertPbToFCSReqReportRegionInfo(msg.ReportRegionInfo, &pb->reportregioninfo());
	_ConvertPbToFCSReqRecalledPlayer(msg.RecalledPlaeyr, &pb->recalledplaeyr());
	_ConvertPbToFCSReqWebLogin(msg.WebLogin, &pb->weblogin());
	_ConvertPbToFCSReqInviteCodeReset(msg.InviteCodeReset, &pb->invitecodereset());
	_ConvertPbToFCSReqRecallReward(msg.RecallReward, &pb->recallreward());
	_ConvertPbToFCSReqSwitchToCommonMatch(msg.SwitchToCommonMatch, &pb->switchtocommonmatch());
	_ConvertPbToFCSReqSwitchModeInTeam(msg.SwitchModeInTeam, &pb->switchmodeinteam());
	_ConvertPbToFCSReqGetTNRoomState(msg.GetTNRoomState, &pb->gettnroomstate());
	_ConvertPbToFCSReqWorkshopMatch(msg.WorkshopMatch, &pb->workshopmatch());
	_ConvertPbToFCSReqBuyWorkshopTicket(msg.BuyWorkshopTicket, &pb->buyworkshopticket());
	_ConvertPbToFCSReqFavouriteWorkshopMap(msg.FavouriteWorkshopMap, &pb->favouriteworkshopmap());
	_ConvertPbToFCSReqShortcutMapsOP(msg.ShortcutMapsOP, &pb->shortcutmapsop());
	_ConvertPbToFCSReqPlayersTournamentInfo(msg.PlayersTournamentInfo, &pb->playerstournamentinfo());
	_ConvertPbToFCSReqScoreWorkshopMap(msg.ScoreWorkshopMap, &pb->scoreworkshopmap());
	_ConvertPbToFCSReqMapsVisitedByFriends(msg.MapsVisitedByFriends, &pb->mapsvisitedbyfriends());
	_ConvertPbToFCSReqVerifyRealName(msg.VerifyRealName, &pb->verifyrealname());
	_ConvertPbToFCSReqFakePay(msg.FakePay, &pb->fakepay());
	_ConvertPbToFCSReqGuildCreate(msg.GuildCreate, &pb->guildcreate());
	_ConvertPbToFCSReqGuildApply(msg.GuildApply, &pb->guildapply());
	_ConvertPbToFCSReqGuildHome(msg.GuildHome, &pb->guildhome());
	_ConvertPbToFCSReqGuildInfo(msg.GuildInfo, &pb->guildinfo());
	_ConvertPbToFCSReqGuildApprove(msg.GuildApprove, &pb->guildapprove());
	_ConvertPbToFCSReqGuildSetRole(msg.GuildRole, &pb->guildrole());
	_ConvertPbToFCSReqGuildModify(msg.GuildModify, &pb->guildmodify());
	_ConvertPbToFCSReqGuildKickoff(msg.GuildKickoff, &pb->guildkickoff());
	_ConvertPbToFCSReqGuildDismiss(msg.GuildDismiss, &pb->guilddismiss());
	_ConvertPbToFCSReqGuildExit(msg.GuildExit, &pb->guildexit());
	_ConvertPbToFCSReqGuildChat(msg.GuildChat, &pb->guildchat());
	_ConvertPbToFCSReqGuildList(msg.GuildList, &pb->guildlist());
	_ConvertPbToFCSReqGuildRecommendPlayers(msg.GuildRecommendPlayers, &pb->guildrecommendplayers());
	_ConvertPbToFCSReqGuildInviteList(msg.GuildInviteList, &pb->guildinvitelist());
	_ConvertPbToFCSReqGuildInvite(msg.GuildInvite, &pb->guildinvite());
	_ConvertPbToFCSReqGuildResign(msg.GuildResign, &pb->guildresign());
	_ConvertPbToFCSReqGuildRejectInvite(msg.GuildRejectInvite, &pb->guildrejectinvite());
	_ConvertPbToFCSReqGetVngCommentAward(msg.GetVngCommentAward, &pb->getvngcommentaward());
	_ConvertPbToFCSReqLevelupChest(msg.LevelupChest, &pb->levelupchest());
	_ConvertPbToFCSReqWatchAd(msg.WatchAd, &pb->watchad());
	_ConvertPbToFCSReqQueryPsTournamentRoom(msg.PsTournamentRoom, &pb->pstournamentroom());
	_ConvertPbToFCSReqGetAdCumulateAward(msg.GetAdCumulateAward, &pb->getadcumulateaward());
	_ConvertPbToFCSReqSetMessengerPos(msg.SetMessengerPos, &pb->setmessengerpos());
	_ConvertPbToFCSReqUpdateAntiAddictionTime(msg.UpdateAntiAddictionTime, &pb->updateantiaddictiontime());
	_ConvertPbToFCSReqCancelReconnect(msg.CancelReconnect, &pb->cancelreconnect());
	_ConvertPbToFCSReqReconnect(msg.Reconnect, &pb->reconnect());
	_ConvertPbToFCSReqPassThrough(msg.PassThrough, &pb->passthrough());
	_ConvertPbToFCSReqVisitPlayer(msg.VisitPlayer, &pb->visitplayer());
	_ConvertPbToFCSReqLeaveGameEarly(msg.LeaveGameEarly, &pb->leavegameearly());
	_ConvertPbToFCSReqGDCommonBin(msg.GDCommonBin, &pb->gdcommonbin());
	_ConvertPbToFCSReqGDCommonBinData(msg.GDBinData, &pb->gdbindata());
	_ConvertPbToFCSReqAutoBattleOP(msg.AutoBattleOP, &pb->autobattleop());
	_ConvertPbToFCSReqRestrictUser(msg.RestrictUser, &pb->restrictuser());
	_ConvertPbToFCSReqEquipSelectRate(msg.EquipSelectRate, &pb->equipselectrate());
	_ConvertPbToFCSReqReportAbsent(msg.ReportAbsent, &pb->reportabsent());
	_ConvertPbToFCSReqRecommendWeek(msg.RecommendWeek, &pb->recommendweek());
	_ConvertPbToFCSReqRecommendOfficial(msg.RecommendOfficial, &pb->recommendofficial());
	_ConvertPbToFCSReqRecommendLatest(msg.RecommendLatest, &pb->recommendlatest());
	_ConvertPbToFCSReqRecommendHistory(msg.RecommendHistory, &pb->recommendhistory());
	_ConvertPbToFCSReqRecommendCollect(msg.RecommendCollect, &pb->recommendcollect());
	_ConvertPbToFCSReqRecommendSet(msg.RecommendSet, &pb->recommendset());
	_ConvertPbToFCSReqRecommendGetCollection(msg.RecommendGetCollection, &pb->recommendgetcollection());
	_ConvertPbToFCSReqRecommendEquip(msg.RecommendEquip, &pb->recommendequip());
	_ConvertPbToFCSReqLoginCancel(msg.LoginCancel, &pb->logincancel());
	_ConvertPbToFCSReqConvertDebris(msg.ConvertDebris, &pb->convertdebris());
	_ConvertPbToFCSReqUseProtectionCard(msg.ProtectionCard, &pb->protectioncard());
	_ConvertPbToFCSReqUsePassportCard(msg.UsePassportCard, &pb->usepassportcard());
	_ConvertPbToFCSReqSetMedal(msg.SetMedal, &pb->setmedal());
	_ConvertPbToFCSReqUnSetMedal(msg.UnSetMedal, &pb->unsetmedal());
	_ConvertPbToFCSReqPlayerMedals(msg.PlayerMedals, &pb->playermedals());
	_ConvertPbToFCSReqUpdateHotDot(msg.UpdateHotDot, &pb->updatehotdot());
	_ConvertPbToFCSReqQueryHotDot(msg.QueryHotDot, &pb->queryhotdot());
	_ConvertPbToFCSReqSetCache(msg.SetCache, &pb->setcache());
	_ConvertPbToFCSReqGetCache(msg.GetCache, &pb->getcache());
	_ConvertPbToFCSReqBuyChallengeCount(msg.BuyChallengeCount, &pb->buychallengecount());
	_ConvertPbToFCSReqGetPveRank(msg.GetPveRank, &pb->getpverank());
	_ConvertPbToFCSReqLogin(msg.AuthAccount, &pb->authaccount());
	_ConvertPbToFCSReqUnbindAccount(msg.UnbindAccount, &pb->unbindaccount());
	_ConvertPbToFCSReqBagToItem(msg.BagToItem, &pb->bagtoitem());
	_ConvertPbToFCSReqIdentifyItem(msg.IdentifyItem, &pb->identifyitem());
	_ConvertPbToFCSReqInsetItemAffix(msg.InsetItemAffix, &pb->insetitemaffix());
	_ConvertPbToFCSReqUnsetItemAffix(msg.UnsetItemAffix, &pb->unsetitemaffix());
	_ConvertPbToFCSReqSetDefaultAttributes(msg.SetDefaultAttributes, &pb->setdefaultattributes());
	_ConvertPbToFCSReqCheckCancel(msg.CheckCancel, &pb->checkcancel());
	_ConvertPbToFCSReqCancelAccount(msg.CancelAccount, &pb->cancelaccount());
	_ConvertPbToFCSReqOAuthApp(msg.OAuthApp, &pb->oauthapp());
	_ConvertPbToFCSReqGetSelfNumRankData(msg.GetSelfNumRankData, &pb->getselfnumrankdata());
	_ConvertPbToFCSReqUpdateCardGroup(msg.UpdateCardGroup, &pb->updatecardgroup());
	_ConvertPbToFCSReqUpdateCardGroupName(msg.UpdateCardGroupName, &pb->updatecardgroupname());
	_ConvertPbToFCSReqBuyPveBuff(msg.BuyPveBuff, &pb->buypvebuff());
	_ConvertPbToFCSReqSetCardGroup(msg.SetCardGroup, &pb->setcardgroup());
	_ConvertPbToFCSReqBuyPveChessTemplate(msg.BuyPveChessTemplate, &pb->buypvechesstemplate());
	_ConvertPbToFCSReqPveUnlockChessTemplate(msg.PveUnlockChessTemplate, &pb->pveunlockchesstemplate());
	_ConvertPbToFCSReqPveSetTeamDeBuff(msg.PveSetTeamDeBuff, &pb->pvesetteamdebuff());
	_ConvertPbToFCSReqChoseCardGroup(msg.ChoseCardGroup, &pb->chosecardgroup());
	_ConvertPbToFCSReqRemoveOvertimeBuff(msg.RemoveOvertimeBuff, &pb->removeovertimebuff());
	_ConvertPbToFCSRspUpdateNewCardGroupSign(msg.UpdateNewCardGroupSign, &pb->updatenewcardgroupsign());
	_ConvertPbToFCSReqTDGetOnHookAward(msg.TDGetOnHookAward, &pb->tdgetonhookaward());
	_ConvertPbToFCsReqTDDraw(msg.TDDraw, &pb->tddraw());
	_ConvertPbToFCsReqTDBuyCard(msg.TDBuyCard, &pb->tdbuycard());
	_ConvertPbToFCSReqTDSetCardGroup(msg.TDSetCardGroup, &pb->tdsetcardgroup());
	_ConvertPbToFCSReqTDLevelUp(msg.TDLevelUp, &pb->tdlevelup());
	_ConvertPbToFCSReqTDEquip(msg.TDEquip, &pb->tdequip());
	_ConvertPbToFCSReqMentorUpdateSetting(msg.MentorUpdateSetting, &pb->mentorupdatesetting());
	_ConvertPbToFCSReqMentorInvite(msg.MentorInvite, &pb->mentorinvite());
	_ConvertPbToFCSReqMentorConfirmInvite(msg.MentorConfirmInvite, &pb->mentorconfirminvite());
	_ConvertPbToFCSReqMentorRecommendList(msg.MentorRecommendList, &pb->mentorrecommendlist());
	_ConvertPbToFCSReqMentorGetTaskAward(msg.MentorGetTaskAward, &pb->mentorgettaskaward());
	_ConvertPbToFCSReqMentorGraduate(msg.MentorGraduate, &pb->mentorgraduate());
	_ConvertPbToFCSReqMentorRelieveRelation(msg.MentorRelieveRelation, &pb->mentorrelieverelation());
	_ConvertPbToFCSReqGetMentorInfo(msg.GetMentorInfo, &pb->getmentorinfo());
	_ConvertPbToFCSReqMentorGetInviteMsg(msg.MentorGetInviteMsg, &pb->mentorgetinvitemsg());
	_ConvertPbToFCSReqUpdateCardGroupBetter(msg.UpdateCardGroupBetter, &pb->updatecardgroupbetter());
	_ConvertPbToFCSReqUpdateCardGroupSetting(msg.UpdateCardGroupSetting, &pb->updatecardgroupsetting());
	_ConvertPbToFCSReqSetContent(msg.SetContent, &pb->setcontent());
	_ConvertPbToFCSReqGetBalance(msg.GetBalance, &pb->getbalance());
	_ConvertPbToFCSReqRechargeBalance(msg.RechargeBalance, &pb->rechargebalance());
	_ConvertPbToFCSReqWithdrawBalance(msg.WithdrawBalance, &pb->withdrawbalance());
	_ConvertPbToFCSReqPersonalRecommendMall(msg.PersonalRecommendMall, &pb->personalrecommendmall());
	_ConvertPbToFCSReqGetMedalChestAward(msg.GetMedalChestAward, &pb->getmedalchestaward());
	_ConvertPbToFCSReqSetItemAutoUse(msg.SetItemAutoUse, &pb->setitemautouse());
}


USTRUCT(BlueprintType)
struct  FCSRspBody {
	GENERATED_BODY()

	uint64 Seq;

	ERESULT ErrCode;	//错误码  0: 成功  非0：失败

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ErrMsg;	//错误提示  ErrCode非0时有意义

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspHeart Heart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspLogin Login;	//登陆

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspVersionCheck VersionCheck;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspResourceVersionCheck ResourceVersionCheck;	//资源版本检测

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspApplyHallServer ApplyHallServer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetNumRank GetNumRank;	//获取排行榜数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWorldChat WorldChat;	//世界聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPlayersBaseInfo PlayersBaseInfo;	//玩家基础信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPlayerDetailInfo PlayerDetailInfo;	//玩家详细信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReadMail ReadMail;	//读邮件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetMailAward GetMailAward;	//领取邮件奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBuyEgg BuyEgg;	//购买扭蛋

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUserNameSet UserNameSet;	//用户名设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUserNameRandom UserNameRandom;	//随机用户名

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspHeadPicSet HeadPicSet;	//设置头像

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspDressChessPlayer DressChessPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspDressScene DressScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPvpLogin PvpLogin;	//pvp服登陆

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPvpEnd PvpEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPlayerFinish PlayerFinish;	//大逃杀死亡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPlayerQuit PlayerQuit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSellItem SellItem;	//出售物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetEvalAward GetEvalAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUseChessPlayer UseChessPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuidReport GuidReport;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetCodeAward GetCodeAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRoundReport RoundReport;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspLoadingProgress LoadingProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPvpChat PvpChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChessCombine ChessCombine;	//棋子合成上报

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspExpose Expose;	//举报

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspApplyOrderId ApplyOrderId;	//申请订单Id

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReportOrderInfo ReportOrderInfo;	//上报订单信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetItem SetItem;	//配置物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUnsetItem UnsetItem;	//取消配置物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRandomItem RandomItem;	//随机展示物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChat Chat;	//聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetChessPlayer SetChessPlayer;	//配置棋手相关属性

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUnsetChessPlayer UnsetChessPlayer;	//取消配置棋手相关属性

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetFansList GetFansList;	//获取好友列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspFollowPlayer FollowPlayer;	//关注玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUnfollowPlayer UnfollowPlayer;	//取消关注玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPlayersStatusInfo PlayersStatusInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspInviteJoinTeam InviteJoinTeam;	//请求邀请加入组队游戏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspJoinTeam JoinTeam;	//请求加入组队游戏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReportPayResponse ReportPayResponse;	//上报支付回执

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRejectJoinTeam RejectJoinTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspShieldChat ShieldChat;	//私聊屏蔽

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBuyPassportLevel BuyPassportLevel;	//购买通行证等级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpgradePassport UpgradePassport;	//购买通行证

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetPassportLevelAward GetPassportLevelAward;	//获取通行证等级奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetPassportTaskAward GetPassportTaskAward;	//获取通行证任务奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTelBook TelBook;	//通讯录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspActivatePassport ActivatePassport;	//激活通行证

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRankSeasonEval RankSeasonEval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBindAccount BindAccount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspIncAdShowCount IncAdsShowCount;	//增加广告浏览次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUseBonusCard UseBonusCard;	//使用加成卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetSeasonAward GetSeasonAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetAlphaActivityAward GetAlphaActivityAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetLanguageData GetLanguageData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetActivityAward GetActivityAward;	//获取活动奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetActivityData GetActivityData;	//获取活动数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSendSms SendSms;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetMeleeAward GetMeleeAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspAddAiToTeam AddAiToTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspShare Share;	//分享

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSkipInterface SkipInterface;	//跳转界面

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTeamGame TeamGame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetTeamMode SetTeamMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetHistoryPvpShowPermission HistoryPvpShowPermission;	//设置历史战绩查看权限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSearchTeam SearchTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspApplyChat ApplyChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChatLogin ChatLogin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspProbeNetDelay ProbeNetDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetEggs GetEggs;	//获取当前可展示的商品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBuyGoods BuyGoods;	//购买特价礼包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspExchangePassportGoods ExchangePassportGoods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUsePassportTaskCard UsePassportTaskCard;	//使用通行证任务卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspOpenRandChest OpenRandChest;	//打开随机宝箱, 自选宝箱

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspEggLottery EggLottery;	//扭蛋抽奖

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspQueryDiamondBalance QueryDiamondBalance;	//向渠道查询钻石充值信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUseItem UseItem;	//使用道具

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUseExperienceCard UseExperienceCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRandTargetItem RandTargetItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspAddBlacklist AddBlacklist;	//添加黑名单

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRemoveBlacklist RemoveBlacklist;	//删除黑名单

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReportPlayerBirth ReportPlayerBirth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReportInfoInput ReportInfoInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSendVerificationCode SendVerificationCode;	//发送验证码

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBindPhoneNumber BindPhoneNumber;	//绑定手机号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWorldInvite WorldInvite;	//邀约

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRemoveExpireItem RemoveExpireItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetMallGoods GetMallGoods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBuyMallGoods BuyMallGoods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBindSharingCode BindSharingCode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWXBlessBag WXBlessBag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateFriendsInGame UpdateFriendsInGame;	//更新同玩好友数量

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspShareReward ShareReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspAllFightInfo AllFightInfo;	//获取全民对局信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetOldPlayer GetOldPlayer;	//获取老账号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBindOldPlayer BindOldPlayer;	//绑定老账号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSendVerificationCodeWithCheckRedis SendVerificationCodeWithCheckRedis;	//发送验证码（获取老账号）

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReportSetting ReportSetting;	//上报玩家设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspAntiData AntiData;	//发送Anti数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTlogData TlogData;	//发送Tlog数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspDaySign DaySign;	//每日签到

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspDayFitAvoid DayFitAvoid;	//上报每日宜忌

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspShareCountAward ShareCountAward;	//领取累计分享奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRealationStar RealationStar;	//关系链幸运星邀请

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetRealationStarInviteSucc GetRealationStarInviteSucc;	//获取关系链幸运星邀请成功玩家列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetRealationStar GetRealationStar;	//获取关系链幸运星邀请玩家列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetActRecord RspActRecord;	//获取活动记录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspJoinVoiceTeam JoinVoiceTeam;	//加入语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspJoinVoicePvp JoinVoicePvp;	//加入Pvp语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspJoinVoiceCamp JoinVoiceCamp;	//加入Camp语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUserCountrySet UserCountrySet;	//用户国家设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspObserve Observe;	//观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetRecommendPvp GetRecommendPvp;	//获取推荐战局

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspObserveLogin ObserveLogin;	//观战服登录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspQuitObserve QuitObserve;	//退出观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetObserveInfo GetObserveInfo;	//获取观战人数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspFreeFlow FreeFlow;	//免流查询

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetPushToken SetPushToken;	//设置玩家消息推送token

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTlogEvent TlogEvent;	//服务器TLOG事件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWxVVipAward WxVVipAward;	//微信大玩家奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetRelationStarWX RelationStarWX;	//获取微信关系链

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSendWxRedPacket SendWxRedPacket;	//发送微信红包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecvWxRedPacket RecvWxRedPacket;	//领取微信红包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWxRedPktLike WxRedPktLike;	//微信大玩家点赞

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWxRedPktRank WxRedPktRank;	//微信大玩家点赞排行

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspObservePrivilege SetObservePrivilege;	//观战权限设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPresetFastChat PresetFastChat;	//预设快捷聊天文本

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChangeSlotTeam ChangeSlotTeam;	//切换位置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChangeSubModeTeam ChangeSubModeTeam;	//切换子模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspConfirmChangeSlotTeam ConfirmChangeSlotTeam;	//确认切换位置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPvpRoundEnd PvpRoundEnd;	//回合结束

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPvp Pvp;	//请求pvp

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTeamReady TeamReady;	//队伍准备

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBindOldBusinessPlayer BindOldBusinessPlayer;	//绑定老business玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTranslate Translate;	//翻译

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSubmitQuestionnaire SubmitQuestionnaire;	//提交问卷答案

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspCancelChangeSlot CancelChangeSlot;	// 取消换位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetChessSkin SetChessSkin;	//棋子皮肤配置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUnsetChessSkin UnsetChessSkin;	//棋子皮肤取消配置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspCompose Compose;	//合成

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspVideo Video;	//获取视频信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspOffHelpReddot OffHelpReddot;	//熄灭知己红点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChangeLanguage ChangeLanguage;	//修改游戏语种

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetProvince SetProvince;	//设置省份

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspLongyuanVoice LongyuanVoice;	//龙渊语音参数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspEnrollTournament EnrollTournament;	//报名赛事

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspJoinTournamentRoom JoinTournamentRoom;	//加入赛事房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTournamentPointAward TournamentPointAward;	//赛事积分进度奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetEnrollPlayers GetEnrollPlayers;	//获取报名玩家列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspDealWebMail DealWebMail;	//处理开放平台邮件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChallengeAgain ChallengeAgain;	//再次挑战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspHistoryChatMsg HistoryChat;	//历史聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetFriendInvisible SetFriendInvisible;	//好友不可见

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetObserveAward GetObserveAward;	//获取观战任务奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspInviteObserve InviteObserve;	//邀请观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRejectObserve RejectObserve;	//拒绝观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetTxPlayer GetTxPlayer;	//返回玩家数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetThirdPvpInfo GetThirdPvpInfo;	//获得第三方观战信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMarkPlayerGuide MarkPlayerGuide;	//标记玩家新手引导

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMarkChessSkinClicked ChessSkinClicked;	//皮肤点击

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRsqQueryPs4Entitlements QueryPs4Entitlements;	//ps4 查询

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspActDaySign ActDaySign;	//每日签到活动

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspHaveThirdPvp HaveThirdPvpInfo;	//是否第三方战斗进行

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspActivityMall ActivityMall;	//回流商店内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPsOnly PsOnly;	//返回玩家级ps only

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChangeChannelType ChangeChannelType;	//设置渠道

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspCustomCardOpt CustomCardOpt;	//自定义组卡玩法操作 获取;保存;设置;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChampionHistory ChampionHistory;	//历届冠军信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTournamentLastTopRank TournamentLastTopRank;	//上届锦标赛top8

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBigWinnerDailyAward BigWinnerDailyAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBigWinnerScoreHistory BigWinnerScoreHistory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSmeltItem SmeltItem;	//熔炼物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPVEUpTalentLevel PVEUpTalentLevel;	//PVE升级天赋

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPVELuckyAward LuckyAward;	//PVE抽奖

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspApplyChannel ApplyChannel;	//申请渠道聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspOBTeamInfo OBTeamInfo;	//OB请求应答

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetPvpServerGroup GetPvpServerGroup;	//请求获取PVP分组ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReportPvpInfo ReportPvpInfo;	//上报选择的pvp分组及ping值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChoosePlayer ChoosePlayer;	//角色多选一

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPingTest PingTest;	//延迟测试

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReportRegionInfo ReportRegionInfo;	//上报各区域的延迟信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecalledPlayer RecalledPlaeyr;	//获取已经召回玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWebLogin WebLogin;	//网页登录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspInviteCodeReset InviteCodeReset;	// 重置邀请码

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecallReward RecallReward;	//获取召回奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSwitchToCommonMatch SwitchToCommonMatch;	//切换到全球匹配队列

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSwitchModeInTeam SwitchModeInTeam;	// 队伍中切换模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetTNRoomState GetTNRoomState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWorkshopMatch WorkshopMatch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBuyWorkshopTicket BuyWorkshopTicket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspFavouriteWorkshopMap FavouriteWorkshopMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspShortcutMapsOP ShortcutMapsOP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPlayersTournamentInfo PlayersTournamentInfo;	//玩家锦标赛相关信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspScoreWorkshopMap ScoreWorkshopMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMapsVisitedByFriends MapsVisitedByFriends;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspVerifyRealName VerifyRealName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspFakePay FakePay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildCreate GuildCreate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildApply GuildApply;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildHome GuildHome;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildInfo GuildInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildApprove GuildApprove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildSetRole GuildRole;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildModify GuildModify;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildKickoff GuildKickoff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildDismiss GuildDismiss;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildExit GuildExit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildChat GuildChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildList GuildList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildRecommendPlayers GuildRecommendPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildInviteList GuildInviteList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildInvite GuildInvite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGuildRejectInvite GuildRejectInvite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetVngCommentAward GetVngCommentAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspLevelupChest LevelupChest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWatchAd WatchAd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspQueryPsTournamentRoom PsTournamentRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetAdCumulateAward GetAdCumulateAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetMessengerPos SetMessengerPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateAntiAddictionTime AntiAddictionTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspCancelReconnect CancelReconnect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReconnect Reconnect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPassThrough PassThrough;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspVisitPlayer VisitPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspLeaveGameEarly LeaveGameEarly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGDCommonBin GDCommonBin;	// 返回数据文件列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGDCommonBinData GDBinData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBattleCampResult BattleCampResult;	// 当前局内的阵营数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspAutoBattleOP AutoBattleOP;	// 自动战斗

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRestrictUser RestrictUser;	// 受限用户

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspEquipSelectRate EquipSelectRate;	// 装备选取率

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspReportAbsent ReportAbsent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecommendWeek RecommendWeek;	// 请求推荐阵容周榜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecommendOfficial RecommendOfficial;	// 请求推荐阵容官方

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecommendLatest RecommendLatest;	// 请求推荐阵容最新

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecommendHistory RecommendHistory;	// 请求个人历史阵容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecommendCollect RecommendCollect;	// 请求阵容收藏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecommendSet RecommendSet;	// 请求阵容推荐

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecommendGetCollection RecommendGetCollection;	// 获取阵容收藏

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRecommendEquip RecommendEquip;	// 获取推荐装备

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspLoginCancel LoginCancel;	// 取消登录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspConvertDebris ConvertDebris;	// 兑换碎片

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUseProtectionCard ProtectionCard;	// 段位保护

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUsePassportCard UsePassportCard;	// 使用通行证激活卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetMedal SetMedal;	// 佩戴勋章

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUnSetMedal UnSetMedal;	// 取下勋章

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPlayerMedals PlayerMedals;	// 勋章列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateHotDot UpdateHotDot;	//红点信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspQueryHotDot QueryHotDot;	//红点信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetCache SetCache;	//查询红点信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetCache GetCache;	//查询红点信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBuyChallengeCount BuyChallengeCount;	//购买挑战记录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetPveRank GetPveRank;	//获取pve排行榜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspAuthAccount AuthAccount;	//验证并获取用户信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUnbindAccount UnbindAccount;	//解绑账号，目前只支持 ps->ly

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBagToItem BagToItem;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspIdentifyItem IdentifyItem;	// 鉴定物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspInsetItemAffix InsetItemAffix;	// 装备词缀

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUnsetItemAffix UnsetItemAffix;	// 卸载词缀数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetDefaultAttributes SetDefaultAttributes;	// 设置玩家默认属性

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspCheckCancel CheckCancel;	// 检测注销条件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspCancelAccount CancelAccount;	// 注销账户

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspOAuthApp OAuthApp;	// 掌上龙渊授权

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetSelfNumRankData SelfNumRankData;	// 个人多个排行榜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateCardGroup UpdateCardGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateCardGroupName UpdateCardGroupName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBuyPveBuff BuyPveBuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetCardGroup SetCardGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspBuyPveChessTemplate BuyPveChessTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPveUnlockChessTemplate PveUnlockChessTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPveSetTeamDeBuff PveSetTeamDeBuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChoseCardGroup ChoseCardGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRemoveOvertimeBuff RemoveOvertimeBuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateNewCardGroupSign UpdateNewCardGroupSign;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTDGetOnHookAward TDGetOnHookAward;	// 获取挂机奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCsRspTDDraw TDDraw;	// 抽卡

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCsRspTDBuyCard TDBuyCard;	// 购买卡券

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTDSetCardGroup TDSetCardGroup;	// 设置卡组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTDLevelUp TDLevelUp;	// 升级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTDEquip TDEquip;	// 装备和卸下

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMentorUpdateSetting MentorUpdateSetting;	// 师徒 修改设置// 师徒更新设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMentorInvite MentorInvite;	// 师徒邀请信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMentorConfirmInvite MentorConfirmInvite;	// 确认师徒邀请信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMentorRecommendList MentorRecommendList;	// 师傅徒弟推荐列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMentorGetTaskAward MentorGetTaskAward;	// 任务获取奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMentorGraduate MentorGraduate;	// 出师

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMentorRelieveRelation MentorRelieveRelation;	// 解除关系

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetMentorInfo GetMentorInfo;	// 获取师傅信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspMentorGetInviteMsg MentorGetInviteMsg;	// 获取邀请信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspTeamMsg TeamMsg;	// 组队消息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChatMsg ChatMsg;	// 私聊消息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspChannelChat ChannelChat;	// 公共频道聊天

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateCardGroupBetter UpdateCardGroupBetter;	// 卡组更新优化

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspUpdateCardGroupSetting UpdateCardGroupSetting;	// 卡组更新设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetAuctionName SetAuctionName;	// 设置拍卖行的名字

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetAuctionRemark SetAuctionRemark;	// 设置拍卖行的留言

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetBalance GetBalance;	// 获取余额

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspRechargeBalance RechargeBalance;	// 充值余额

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspWithdrawBalance WithdrawBalance;	// 提现余额

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspPersonalRecommendMall PersonalRecommendMall;	// 精细化投放

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspGetMedalChestAward GetMedalChestAward;	//成就勋章宝箱奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSRspSetItemAutoUse SetItemAutoUse;	// 设置物品自动使用

};
static void _ConvertPbToFCSRspBody(FCSRspBody &msg, const msg::CSRspBody *pb) {
	msg.Seq=pb->seq();
	msg.ErrCode=(ERESULT)pb->errcode();
	msg.ErrMsg=UTF8_TO_TCHAR(pb->errmsg().c_str());
	_ConvertPbToFCSRspHeart(msg.Heart, &pb->heart());
	_ConvertPbToFCSRspLogin(msg.Login, &pb->login());
	_ConvertPbToFCSRspVersionCheck(msg.VersionCheck, &pb->versioncheck());
	_ConvertPbToFCSRspResourceVersionCheck(msg.ResourceVersionCheck, &pb->resourceversioncheck());
	_ConvertPbToFCSRspApplyHallServer(msg.ApplyHallServer, &pb->applyhallserver());
	_ConvertPbToFCSRspGetNumRank(msg.GetNumRank, &pb->getnumrank());
	_ConvertPbToFCSRspWorldChat(msg.WorldChat, &pb->worldchat());
	_ConvertPbToFCSRspPlayersBaseInfo(msg.PlayersBaseInfo, &pb->playersbaseinfo());
	_ConvertPbToFCSRspPlayerDetailInfo(msg.PlayerDetailInfo, &pb->playerdetailinfo());
	_ConvertPbToFCSRspReadMail(msg.ReadMail, &pb->readmail());
	_ConvertPbToFCSRspGetMailAward(msg.GetMailAward, &pb->getmailaward());
	_ConvertPbToFCSRspBuyEgg(msg.BuyEgg, &pb->buyegg());
	_ConvertPbToFCSRspUserNameSet(msg.UserNameSet, &pb->usernameset());
	_ConvertPbToFCSRspUserNameRandom(msg.UserNameRandom, &pb->usernamerandom());
	_ConvertPbToFCSRspHeadPicSet(msg.HeadPicSet, &pb->headpicset());
	_ConvertPbToFCSRspDressChessPlayer(msg.DressChessPlayer, &pb->dresschessplayer());
	_ConvertPbToFCSRspDressScene(msg.DressScene, &pb->dressscene());
	_ConvertPbToFCSRspPvpLogin(msg.PvpLogin, &pb->pvplogin());
	_ConvertPbToFCSRspPvpEnd(msg.PvpEnd, &pb->pvpend());
	_ConvertPbToFCSRspPlayerFinish(msg.PlayerFinish, &pb->playerfinish());
	_ConvertPbToFCSRspPlayerQuit(msg.PlayerQuit, &pb->playerquit());
	_ConvertPbToFCSRspSellItem(msg.SellItem, &pb->sellitem());
	_ConvertPbToFCSRspGetEvalAward(msg.GetEvalAward, &pb->getevalaward());
	_ConvertPbToFCSRspUseChessPlayer(msg.UseChessPlayer, &pb->usechessplayer());
	_ConvertPbToFCSRspGuidReport(msg.GuidReport, &pb->guidreport());
	_ConvertPbToFCSRspGetCodeAward(msg.GetCodeAward, &pb->getcodeaward());
	_ConvertPbToFCSRspRoundReport(msg.RoundReport, &pb->roundreport());
	_ConvertPbToFCSRspLoadingProgress(msg.LoadingProgress, &pb->loadingprogress());
	_ConvertPbToFCSRspPvpChat(msg.PvpChat, &pb->pvpchat());
	_ConvertPbToFCSRspChessCombine(msg.ChessCombine, &pb->chesscombine());
	_ConvertPbToFCSRspExpose(msg.Expose, &pb->expose());
	_ConvertPbToFCSRspApplyOrderId(msg.ApplyOrderId, &pb->applyorderid());
	_ConvertPbToFCSRspReportOrderInfo(msg.ReportOrderInfo, &pb->reportorderinfo());
	_ConvertPbToFCSRspSetItem(msg.SetItem, &pb->setitem());
	_ConvertPbToFCSRspUnsetItem(msg.UnsetItem, &pb->unsetitem());
	_ConvertPbToFCSRspRandomItem(msg.RandomItem, &pb->randomitem());
	_ConvertPbToFCSRspChat(msg.Chat, &pb->chat());
	_ConvertPbToFCSRspSetChessPlayer(msg.SetChessPlayer, &pb->setchessplayer());
	_ConvertPbToFCSRspUnsetChessPlayer(msg.UnsetChessPlayer, &pb->unsetchessplayer());
	_ConvertPbToFCSRspGetFansList(msg.GetFansList, &pb->getfanslist());
	_ConvertPbToFCSRspFollowPlayer(msg.FollowPlayer, &pb->followplayer());
	_ConvertPbToFCSRspUnfollowPlayer(msg.UnfollowPlayer, &pb->unfollowplayer());
	_ConvertPbToFCSRspPlayersStatusInfo(msg.PlayersStatusInfo, &pb->playersstatusinfo());
	_ConvertPbToFCSRspInviteJoinTeam(msg.InviteJoinTeam, &pb->invitejointeam());
	_ConvertPbToFCSRspJoinTeam(msg.JoinTeam, &pb->jointeam());
	_ConvertPbToFCSRspReportPayResponse(msg.ReportPayResponse, &pb->reportpayresponse());
	_ConvertPbToFCSRspRejectJoinTeam(msg.RejectJoinTeam, &pb->rejectjointeam());
	_ConvertPbToFCSRspShieldChat(msg.ShieldChat, &pb->shieldchat());
	_ConvertPbToFCSRspBuyPassportLevel(msg.BuyPassportLevel, &pb->buypassportlevel());
	_ConvertPbToFCSRspUpgradePassport(msg.UpgradePassport, &pb->upgradepassport());
	_ConvertPbToFCSRspGetPassportLevelAward(msg.GetPassportLevelAward, &pb->getpassportlevelaward());
	_ConvertPbToFCSRspGetPassportTaskAward(msg.GetPassportTaskAward, &pb->getpassporttaskaward());
	_ConvertPbToFCSRspTelBook(msg.TelBook, &pb->telbook());
	_ConvertPbToFCSRspActivatePassport(msg.ActivatePassport, &pb->activatepassport());
	_ConvertPbToFCSRspRankSeasonEval(msg.RankSeasonEval, &pb->rankseasoneval());
	_ConvertPbToFCSRspBindAccount(msg.BindAccount, &pb->bindaccount());
	_ConvertPbToFCSRspIncAdShowCount(msg.IncAdsShowCount, &pb->incadsshowcount());
	_ConvertPbToFCSRspUseBonusCard(msg.UseBonusCard, &pb->usebonuscard());
	_ConvertPbToFCSRspGetSeasonAward(msg.GetSeasonAward, &pb->getseasonaward());
	_ConvertPbToFCSRspGetAlphaActivityAward(msg.GetAlphaActivityAward, &pb->getalphaactivityaward());
	_ConvertPbToFCSRspGetLanguageData(msg.GetLanguageData, &pb->getlanguagedata());
	_ConvertPbToFCSRspGetActivityAward(msg.GetActivityAward, &pb->getactivityaward());
	_ConvertPbToFCSRspGetActivityData(msg.GetActivityData, &pb->getactivitydata());
	_ConvertPbToFCSRspSendSms(msg.SendSms, &pb->sendsms());
	_ConvertPbToFCSRspGetMeleeAward(msg.GetMeleeAward, &pb->getmeleeaward());
	_ConvertPbToFCSRspAddAiToTeam(msg.AddAiToTeam, &pb->addaitoteam());
	_ConvertPbToFCSRspShare(msg.Share, &pb->share());
	_ConvertPbToFCSRspSkipInterface(msg.SkipInterface, &pb->skipinterface());
	_ConvertPbToFCSRspTeamGame(msg.TeamGame, &pb->teamgame());
	_ConvertPbToFCSRspSetTeamMode(msg.SetTeamMode, &pb->setteammode());
	_ConvertPbToFCSRspSetHistoryPvpShowPermission(msg.HistoryPvpShowPermission, &pb->historypvpshowpermission());
	_ConvertPbToFCSRspSearchTeam(msg.SearchTeam, &pb->searchteam());
	_ConvertPbToFCSRspApplyChat(msg.ApplyChat, &pb->applychat());
	_ConvertPbToFCSRspChatLogin(msg.ChatLogin, &pb->chatlogin());
	_ConvertPbToFCSRspProbeNetDelay(msg.ProbeNetDelay, &pb->probenetdelay());
	_ConvertPbToFCSRspGetEggs(msg.GetEggs, &pb->geteggs());
	_ConvertPbToFCSRspBuyGoods(msg.BuyGoods, &pb->buygoods());
	_ConvertPbToFCSRspExchangePassportGoods(msg.ExchangePassportGoods, &pb->exchangepassportgoods());
	_ConvertPbToFCSRspUsePassportTaskCard(msg.UsePassportTaskCard, &pb->usepassporttaskcard());
	_ConvertPbToFCSRspOpenRandChest(msg.OpenRandChest, &pb->openrandchest());
	_ConvertPbToFCSRspEggLottery(msg.EggLottery, &pb->egglottery());
	_ConvertPbToFCSRspQueryDiamondBalance(msg.QueryDiamondBalance, &pb->querydiamondbalance());
	_ConvertPbToFCSRspUseItem(msg.UseItem, &pb->useitem());
	_ConvertPbToFCSRspUseExperienceCard(msg.UseExperienceCard, &pb->useexperiencecard());
	_ConvertPbToFCSRspRandTargetItem(msg.RandTargetItem, &pb->randtargetitem());
	_ConvertPbToFCSRspAddBlacklist(msg.AddBlacklist, &pb->addblacklist());
	_ConvertPbToFCSRspRemoveBlacklist(msg.RemoveBlacklist, &pb->removeblacklist());
	_ConvertPbToFCSRspReportPlayerBirth(msg.ReportPlayerBirth, &pb->reportplayerbirth());
	_ConvertPbToFCSRspReportInfoInput(msg.ReportInfoInput, &pb->reportinfoinput());
	_ConvertPbToFCSRspSendVerificationCode(msg.SendVerificationCode, &pb->sendverificationcode());
	_ConvertPbToFCSRspBindPhoneNumber(msg.BindPhoneNumber, &pb->bindphonenumber());
	_ConvertPbToFCSRspWorldInvite(msg.WorldInvite, &pb->worldinvite());
	_ConvertPbToFCSRspRemoveExpireItem(msg.RemoveExpireItem, &pb->removeexpireitem());
	_ConvertPbToFCSRspGetMallGoods(msg.GetMallGoods, &pb->getmallgoods());
	_ConvertPbToFCSRspBuyMallGoods(msg.BuyMallGoods, &pb->buymallgoods());
	_ConvertPbToFCSRspBindSharingCode(msg.BindSharingCode, &pb->bindsharingcode());
	_ConvertPbToFCSRspWXBlessBag(msg.WXBlessBag, &pb->wxblessbag());
	_ConvertPbToFCSRspUpdateFriendsInGame(msg.UpdateFriendsInGame, &pb->updatefriendsingame());
	_ConvertPbToFCSRspShareReward(msg.ShareReward, &pb->sharereward());
	_ConvertPbToFCSRspAllFightInfo(msg.AllFightInfo, &pb->allfightinfo());
	_ConvertPbToFCSRspGetOldPlayer(msg.GetOldPlayer, &pb->getoldplayer());
	_ConvertPbToFCSRspBindOldPlayer(msg.BindOldPlayer, &pb->bindoldplayer());
	_ConvertPbToFCSRspSendVerificationCodeWithCheckRedis(msg.SendVerificationCodeWithCheckRedis, &pb->sendverificationcodewithcheckredis());
	_ConvertPbToFCSRspReportSetting(msg.ReportSetting, &pb->reportsetting());
	_ConvertPbToFCSRspAntiData(msg.AntiData, &pb->antidata());
	_ConvertPbToFCSRspTlogData(msg.TlogData, &pb->tlogdata());
	_ConvertPbToFCSRspDaySign(msg.DaySign, &pb->daysign());
	_ConvertPbToFCSRspDayFitAvoid(msg.DayFitAvoid, &pb->dayfitavoid());
	_ConvertPbToFCSRspShareCountAward(msg.ShareCountAward, &pb->sharecountaward());
	_ConvertPbToFCSRspRealationStar(msg.RealationStar, &pb->realationstar());
	_ConvertPbToFCSRspGetRealationStarInviteSucc(msg.GetRealationStarInviteSucc, &pb->getrealationstarinvitesucc());
	_ConvertPbToFCSRspGetRealationStar(msg.GetRealationStar, &pb->getrealationstar());
	_ConvertPbToFCSRspGetActRecord(msg.RspActRecord, &pb->rspactrecord());
	_ConvertPbToFCSRspJoinVoiceTeam(msg.JoinVoiceTeam, &pb->joinvoiceteam());
	_ConvertPbToFCSRspJoinVoicePvp(msg.JoinVoicePvp, &pb->joinvoicepvp());
	_ConvertPbToFCSRspJoinVoiceCamp(msg.JoinVoiceCamp, &pb->joinvoicecamp());
	_ConvertPbToFCSRspUserCountrySet(msg.UserCountrySet, &pb->usercountryset());
	_ConvertPbToFCSRspObserve(msg.Observe, &pb->observe());
	_ConvertPbToFCSRspGetRecommendPvp(msg.GetRecommendPvp, &pb->getrecommendpvp());
	_ConvertPbToFCSRspObserveLogin(msg.ObserveLogin, &pb->observelogin());
	_ConvertPbToFCSRspQuitObserve(msg.QuitObserve, &pb->quitobserve());
	_ConvertPbToFCSRspGetObserveInfo(msg.GetObserveInfo, &pb->getobserveinfo());
	_ConvertPbToFCSRspFreeFlow(msg.FreeFlow, &pb->freeflow());
	_ConvertPbToFCSRspSetPushToken(msg.SetPushToken, &pb->setpushtoken());
	_ConvertPbToFCSRspTlogEvent(msg.TlogEvent, &pb->tlogevent());
	_ConvertPbToFCSRspWxVVipAward(msg.WxVVipAward, &pb->wxvvipaward());
	_ConvertPbToFCSRspGetRelationStarWX(msg.RelationStarWX, &pb->relationstarwx());
	_ConvertPbToFCSRspSendWxRedPacket(msg.SendWxRedPacket, &pb->sendwxredpacket());
	_ConvertPbToFCSRspRecvWxRedPacket(msg.RecvWxRedPacket, &pb->recvwxredpacket());
	_ConvertPbToFCSRspWxRedPktLike(msg.WxRedPktLike, &pb->wxredpktlike());
	_ConvertPbToFCSRspWxRedPktRank(msg.WxRedPktRank, &pb->wxredpktrank());
	_ConvertPbToFCSRspObservePrivilege(msg.SetObservePrivilege, &pb->setobserveprivilege());
	_ConvertPbToFCSRspPresetFastChat(msg.PresetFastChat, &pb->presetfastchat());
	_ConvertPbToFCSRspChangeSlotTeam(msg.ChangeSlotTeam, &pb->changeslotteam());
	_ConvertPbToFCSRspChangeSubModeTeam(msg.ChangeSubModeTeam, &pb->changesubmodeteam());
	_ConvertPbToFCSRspConfirmChangeSlotTeam(msg.ConfirmChangeSlotTeam, &pb->confirmchangeslotteam());
	_ConvertPbToFCSRspPvpRoundEnd(msg.PvpRoundEnd, &pb->pvproundend());
	_ConvertPbToFCSRspPvp(msg.Pvp, &pb->pvp());
	_ConvertPbToFCSRspTeamReady(msg.TeamReady, &pb->teamready());
	_ConvertPbToFCSRspBindOldBusinessPlayer(msg.BindOldBusinessPlayer, &pb->bindoldbusinessplayer());
	_ConvertPbToFCSRspTranslate(msg.Translate, &pb->translate());
	_ConvertPbToFCSRspSubmitQuestionnaire(msg.SubmitQuestionnaire, &pb->submitquestionnaire());
	_ConvertPbToFCSRspCancelChangeSlot(msg.CancelChangeSlot, &pb->cancelchangeslot());
	_ConvertPbToFCSRspSetChessSkin(msg.SetChessSkin, &pb->setchessskin());
	_ConvertPbToFCSRspUnsetChessSkin(msg.UnsetChessSkin, &pb->unsetchessskin());
	_ConvertPbToFCSRspCompose(msg.Compose, &pb->compose());
	_ConvertPbToFCSRspVideo(msg.Video, &pb->video());
	_ConvertPbToFCSRspOffHelpReddot(msg.OffHelpReddot, &pb->offhelpreddot());
	_ConvertPbToFCSRspChangeLanguage(msg.ChangeLanguage, &pb->changelanguage());
	_ConvertPbToFCSRspSetProvince(msg.SetProvince, &pb->setprovince());
	_ConvertPbToFCSRspLongyuanVoice(msg.LongyuanVoice, &pb->longyuanvoice());
	_ConvertPbToFCSRspEnrollTournament(msg.EnrollTournament, &pb->enrolltournament());
	_ConvertPbToFCSRspJoinTournamentRoom(msg.JoinTournamentRoom, &pb->jointournamentroom());
	_ConvertPbToFCSRspTournamentPointAward(msg.TournamentPointAward, &pb->tournamentpointaward());
	_ConvertPbToFCSRspGetEnrollPlayers(msg.GetEnrollPlayers, &pb->getenrollplayers());
	_ConvertPbToFCSRspDealWebMail(msg.DealWebMail, &pb->dealwebmail());
	_ConvertPbToFCSRspChallengeAgain(msg.ChallengeAgain, &pb->challengeagain());
	_ConvertPbToFCSRspHistoryChatMsg(msg.HistoryChat, &pb->historychat());
	_ConvertPbToFCSRspSetFriendInvisible(msg.SetFriendInvisible, &pb->setfriendinvisible());
	_ConvertPbToFCSRspGetObserveAward(msg.GetObserveAward, &pb->getobserveaward());
	_ConvertPbToFCSRspInviteObserve(msg.InviteObserve, &pb->inviteobserve());
	_ConvertPbToFCSRspRejectObserve(msg.RejectObserve, &pb->rejectobserve());
	_ConvertPbToFCSRspGetTxPlayer(msg.GetTxPlayer, &pb->gettxplayer());
	_ConvertPbToFCSRspGetThirdPvpInfo(msg.GetThirdPvpInfo, &pb->getthirdpvpinfo());
	_ConvertPbToFCSRspMarkPlayerGuide(msg.MarkPlayerGuide, &pb->markplayerguide());
	_ConvertPbToFCSRspMarkChessSkinClicked(msg.ChessSkinClicked, &pb->chessskinclicked());
	_ConvertPbToFCSRsqQueryPs4Entitlements(msg.QueryPs4Entitlements, &pb->queryps4entitlements());
	_ConvertPbToFCSRspActDaySign(msg.ActDaySign, &pb->actdaysign());
	_ConvertPbToFCSRspHaveThirdPvp(msg.HaveThirdPvpInfo, &pb->havethirdpvpinfo());
	_ConvertPbToFCSRspActivityMall(msg.ActivityMall, &pb->activitymall());
	_ConvertPbToFCSRspPsOnly(msg.PsOnly, &pb->psonly());
	_ConvertPbToFCSRspChangeChannelType(msg.ChangeChannelType, &pb->changechanneltype());
	_ConvertPbToFCSRspCustomCardOpt(msg.CustomCardOpt, &pb->customcardopt());
	_ConvertPbToFCSRspChampionHistory(msg.ChampionHistory, &pb->championhistory());
	_ConvertPbToFCSRspTournamentLastTopRank(msg.TournamentLastTopRank, &pb->tournamentlasttoprank());
	_ConvertPbToFCSRspBigWinnerDailyAward(msg.BigWinnerDailyAward, &pb->bigwinnerdailyaward());
	_ConvertPbToFCSRspBigWinnerScoreHistory(msg.BigWinnerScoreHistory, &pb->bigwinnerscorehistory());
	_ConvertPbToFCSRspSmeltItem(msg.SmeltItem, &pb->smeltitem());
	_ConvertPbToFCSRspPVEUpTalentLevel(msg.PVEUpTalentLevel, &pb->pveuptalentlevel());
	_ConvertPbToFCSRspPVELuckyAward(msg.LuckyAward, &pb->luckyaward());
	_ConvertPbToFCSRspApplyChannel(msg.ApplyChannel, &pb->applychannel());
	_ConvertPbToFCSRspOBTeamInfo(msg.OBTeamInfo, &pb->obteaminfo());
	_ConvertPbToFCSRspGetPvpServerGroup(msg.GetPvpServerGroup, &pb->getpvpservergroup());
	_ConvertPbToFCSRspReportPvpInfo(msg.ReportPvpInfo, &pb->reportpvpinfo());
	_ConvertPbToFCSRspChoosePlayer(msg.ChoosePlayer, &pb->chooseplayer());
	_ConvertPbToFCSRspPingTest(msg.PingTest, &pb->pingtest());
	_ConvertPbToFCSRspReportRegionInfo(msg.ReportRegionInfo, &pb->reportregioninfo());
	_ConvertPbToFCSRspRecalledPlayer(msg.RecalledPlaeyr, &pb->recalledplaeyr());
	_ConvertPbToFCSRspWebLogin(msg.WebLogin, &pb->weblogin());
	_ConvertPbToFCSRspInviteCodeReset(msg.InviteCodeReset, &pb->invitecodereset());
	_ConvertPbToFCSRspRecallReward(msg.RecallReward, &pb->recallreward());
	_ConvertPbToFCSRspSwitchToCommonMatch(msg.SwitchToCommonMatch, &pb->switchtocommonmatch());
	_ConvertPbToFCSRspSwitchModeInTeam(msg.SwitchModeInTeam, &pb->switchmodeinteam());
	_ConvertPbToFCSRspGetTNRoomState(msg.GetTNRoomState, &pb->gettnroomstate());
	_ConvertPbToFCSRspWorkshopMatch(msg.WorkshopMatch, &pb->workshopmatch());
	_ConvertPbToFCSRspBuyWorkshopTicket(msg.BuyWorkshopTicket, &pb->buyworkshopticket());
	_ConvertPbToFCSRspFavouriteWorkshopMap(msg.FavouriteWorkshopMap, &pb->favouriteworkshopmap());
	_ConvertPbToFCSRspShortcutMapsOP(msg.ShortcutMapsOP, &pb->shortcutmapsop());
	_ConvertPbToFCSRspPlayersTournamentInfo(msg.PlayersTournamentInfo, &pb->playerstournamentinfo());
	_ConvertPbToFCSRspScoreWorkshopMap(msg.ScoreWorkshopMap, &pb->scoreworkshopmap());
	_ConvertPbToFCSRspMapsVisitedByFriends(msg.MapsVisitedByFriends, &pb->mapsvisitedbyfriends());
	_ConvertPbToFCSRspVerifyRealName(msg.VerifyRealName, &pb->verifyrealname());
	_ConvertPbToFCSRspFakePay(msg.FakePay, &pb->fakepay());
	_ConvertPbToFCSRspGuildCreate(msg.GuildCreate, &pb->guildcreate());
	_ConvertPbToFCSRspGuildApply(msg.GuildApply, &pb->guildapply());
	_ConvertPbToFCSRspGuildHome(msg.GuildHome, &pb->guildhome());
	_ConvertPbToFCSRspGuildInfo(msg.GuildInfo, &pb->guildinfo());
	_ConvertPbToFCSRspGuildApprove(msg.GuildApprove, &pb->guildapprove());
	_ConvertPbToFCSRspGuildSetRole(msg.GuildRole, &pb->guildrole());
	_ConvertPbToFCSRspGuildModify(msg.GuildModify, &pb->guildmodify());
	_ConvertPbToFCSRspGuildKickoff(msg.GuildKickoff, &pb->guildkickoff());
	_ConvertPbToFCSRspGuildDismiss(msg.GuildDismiss, &pb->guilddismiss());
	_ConvertPbToFCSRspGuildExit(msg.GuildExit, &pb->guildexit());
	_ConvertPbToFCSRspGuildChat(msg.GuildChat, &pb->guildchat());
	_ConvertPbToFCSRspGuildList(msg.GuildList, &pb->guildlist());
	_ConvertPbToFCSRspGuildRecommendPlayers(msg.GuildRecommendPlayers, &pb->guildrecommendplayers());
	_ConvertPbToFCSRspGuildInviteList(msg.GuildInviteList, &pb->guildinvitelist());
	_ConvertPbToFCSRspGuildInvite(msg.GuildInvite, &pb->guildinvite());
	_ConvertPbToFCSRspGuildRejectInvite(msg.GuildRejectInvite, &pb->guildrejectinvite());
	_ConvertPbToFCSRspGetVngCommentAward(msg.GetVngCommentAward, &pb->getvngcommentaward());
	_ConvertPbToFCSRspLevelupChest(msg.LevelupChest, &pb->levelupchest());
	_ConvertPbToFCSRspWatchAd(msg.WatchAd, &pb->watchad());
	_ConvertPbToFCSRspQueryPsTournamentRoom(msg.PsTournamentRoom, &pb->pstournamentroom());
	_ConvertPbToFCSRspGetAdCumulateAward(msg.GetAdCumulateAward, &pb->getadcumulateaward());
	_ConvertPbToFCSRspSetMessengerPos(msg.SetMessengerPos, &pb->setmessengerpos());
	_ConvertPbToFCSRspUpdateAntiAddictionTime(msg.AntiAddictionTime, &pb->antiaddictiontime());
	_ConvertPbToFCSRspCancelReconnect(msg.CancelReconnect, &pb->cancelreconnect());
	_ConvertPbToFCSRspReconnect(msg.Reconnect, &pb->reconnect());
	_ConvertPbToFCSRspPassThrough(msg.PassThrough, &pb->passthrough());
	_ConvertPbToFCSRspVisitPlayer(msg.VisitPlayer, &pb->visitplayer());
	_ConvertPbToFCSRspLeaveGameEarly(msg.LeaveGameEarly, &pb->leavegameearly());
	_ConvertPbToFCSRspGDCommonBin(msg.GDCommonBin, &pb->gdcommonbin());
	_ConvertPbToFCSRspGDCommonBinData(msg.GDBinData, &pb->gdbindata());
	_ConvertPbToFCSRspBattleCampResult(msg.BattleCampResult, &pb->battlecampresult());
	_ConvertPbToFCSRspAutoBattleOP(msg.AutoBattleOP, &pb->autobattleop());
	_ConvertPbToFCSRspRestrictUser(msg.RestrictUser, &pb->restrictuser());
	_ConvertPbToFCSRspEquipSelectRate(msg.EquipSelectRate, &pb->equipselectrate());
	_ConvertPbToFCSRspReportAbsent(msg.ReportAbsent, &pb->reportabsent());
	_ConvertPbToFCSRspRecommendWeek(msg.RecommendWeek, &pb->recommendweek());
	_ConvertPbToFCSRspRecommendOfficial(msg.RecommendOfficial, &pb->recommendofficial());
	_ConvertPbToFCSRspRecommendLatest(msg.RecommendLatest, &pb->recommendlatest());
	_ConvertPbToFCSRspRecommendHistory(msg.RecommendHistory, &pb->recommendhistory());
	_ConvertPbToFCSRspRecommendCollect(msg.RecommendCollect, &pb->recommendcollect());
	_ConvertPbToFCSRspRecommendSet(msg.RecommendSet, &pb->recommendset());
	_ConvertPbToFCSRspRecommendGetCollection(msg.RecommendGetCollection, &pb->recommendgetcollection());
	_ConvertPbToFCSRspRecommendEquip(msg.RecommendEquip, &pb->recommendequip());
	_ConvertPbToFCSRspLoginCancel(msg.LoginCancel, &pb->logincancel());
	_ConvertPbToFCSRspConvertDebris(msg.ConvertDebris, &pb->convertdebris());
	_ConvertPbToFCSRspUseProtectionCard(msg.ProtectionCard, &pb->protectioncard());
	_ConvertPbToFCSRspUsePassportCard(msg.UsePassportCard, &pb->usepassportcard());
	_ConvertPbToFCSRspSetMedal(msg.SetMedal, &pb->setmedal());
	_ConvertPbToFCSRspUnSetMedal(msg.UnSetMedal, &pb->unsetmedal());
	_ConvertPbToFCSRspPlayerMedals(msg.PlayerMedals, &pb->playermedals());
	_ConvertPbToFCSRspUpdateHotDot(msg.UpdateHotDot, &pb->updatehotdot());
	_ConvertPbToFCSRspQueryHotDot(msg.QueryHotDot, &pb->queryhotdot());
	_ConvertPbToFCSRspSetCache(msg.SetCache, &pb->setcache());
	_ConvertPbToFCSRspGetCache(msg.GetCache, &pb->getcache());
	_ConvertPbToFCSRspBuyChallengeCount(msg.BuyChallengeCount, &pb->buychallengecount());
	_ConvertPbToFCSRspGetPveRank(msg.GetPveRank, &pb->getpverank());
	_ConvertPbToFCSRspAuthAccount(msg.AuthAccount, &pb->authaccount());
	_ConvertPbToFCSRspUnbindAccount(msg.UnbindAccount, &pb->unbindaccount());
	_ConvertPbToFCSRspBagToItem(msg.BagToItem, &pb->bagtoitem());
	_ConvertPbToFCSRspIdentifyItem(msg.IdentifyItem, &pb->identifyitem());
	_ConvertPbToFCSRspInsetItemAffix(msg.InsetItemAffix, &pb->insetitemaffix());
	_ConvertPbToFCSRspUnsetItemAffix(msg.UnsetItemAffix, &pb->unsetitemaffix());
	_ConvertPbToFCSRspSetDefaultAttributes(msg.SetDefaultAttributes, &pb->setdefaultattributes());
	_ConvertPbToFCSRspCheckCancel(msg.CheckCancel, &pb->checkcancel());
	_ConvertPbToFCSRspCancelAccount(msg.CancelAccount, &pb->cancelaccount());
	_ConvertPbToFCSRspOAuthApp(msg.OAuthApp, &pb->oauthapp());
	_ConvertPbToFCSRspGetSelfNumRankData(msg.SelfNumRankData, &pb->selfnumrankdata());
	_ConvertPbToFCSRspUpdateCardGroup(msg.UpdateCardGroup, &pb->updatecardgroup());
	_ConvertPbToFCSRspUpdateCardGroupName(msg.UpdateCardGroupName, &pb->updatecardgroupname());
	_ConvertPbToFCSRspBuyPveBuff(msg.BuyPveBuff, &pb->buypvebuff());
	_ConvertPbToFCSRspSetCardGroup(msg.SetCardGroup, &pb->setcardgroup());
	_ConvertPbToFCSRspBuyPveChessTemplate(msg.BuyPveChessTemplate, &pb->buypvechesstemplate());
	_ConvertPbToFCSRspPveUnlockChessTemplate(msg.PveUnlockChessTemplate, &pb->pveunlockchesstemplate());
	_ConvertPbToFCSRspPveSetTeamDeBuff(msg.PveSetTeamDeBuff, &pb->pvesetteamdebuff());
	_ConvertPbToFCSRspChoseCardGroup(msg.ChoseCardGroup, &pb->chosecardgroup());
	_ConvertPbToFCSRspRemoveOvertimeBuff(msg.RemoveOvertimeBuff, &pb->removeovertimebuff());
	_ConvertPbToFCSRspUpdateNewCardGroupSign(msg.UpdateNewCardGroupSign, &pb->updatenewcardgroupsign());
	_ConvertPbToFCSRspTDGetOnHookAward(msg.TDGetOnHookAward, &pb->tdgetonhookaward());
	_ConvertPbToFCsRspTDDraw(msg.TDDraw, &pb->tddraw());
	_ConvertPbToFCsRspTDBuyCard(msg.TDBuyCard, &pb->tdbuycard());
	_ConvertPbToFCSRspTDSetCardGroup(msg.TDSetCardGroup, &pb->tdsetcardgroup());
	_ConvertPbToFCSRspTDLevelUp(msg.TDLevelUp, &pb->tdlevelup());
	_ConvertPbToFCSRspTDEquip(msg.TDEquip, &pb->tdequip());
	_ConvertPbToFCSRspMentorUpdateSetting(msg.MentorUpdateSetting, &pb->mentorupdatesetting());
	_ConvertPbToFCSRspMentorInvite(msg.MentorInvite, &pb->mentorinvite());
	_ConvertPbToFCSRspMentorConfirmInvite(msg.MentorConfirmInvite, &pb->mentorconfirminvite());
	_ConvertPbToFCSRspMentorRecommendList(msg.MentorRecommendList, &pb->mentorrecommendlist());
	_ConvertPbToFCSRspMentorGetTaskAward(msg.MentorGetTaskAward, &pb->mentorgettaskaward());
	_ConvertPbToFCSRspMentorGraduate(msg.MentorGraduate, &pb->mentorgraduate());
	_ConvertPbToFCSRspMentorRelieveRelation(msg.MentorRelieveRelation, &pb->mentorrelieverelation());
	_ConvertPbToFCSRspGetMentorInfo(msg.GetMentorInfo, &pb->getmentorinfo());
	_ConvertPbToFCSRspMentorGetInviteMsg(msg.MentorGetInviteMsg, &pb->mentorgetinvitemsg());
	_ConvertPbToFCSRspTeamMsg(msg.TeamMsg, &pb->teammsg());
	_ConvertPbToFCSRspChatMsg(msg.ChatMsg, &pb->chatmsg());
	_ConvertPbToFCSRspChannelChat(msg.ChannelChat, &pb->channelchat());
	_ConvertPbToFCSRspUpdateCardGroupBetter(msg.UpdateCardGroupBetter, &pb->updatecardgroupbetter());
	_ConvertPbToFCSRspUpdateCardGroupSetting(msg.UpdateCardGroupSetting, &pb->updatecardgroupsetting());
	_ConvertPbToFCSRspSetAuctionName(msg.SetAuctionName, &pb->setauctionname());
	_ConvertPbToFCSRspSetAuctionRemark(msg.SetAuctionRemark, &pb->setauctionremark());
	_ConvertPbToFCSRspGetBalance(msg.GetBalance, &pb->getbalance());
	_ConvertPbToFCSRspRechargeBalance(msg.RechargeBalance, &pb->rechargebalance());
	_ConvertPbToFCSRspWithdrawBalance(msg.WithdrawBalance, &pb->withdrawbalance());
	_ConvertPbToFCSRspPersonalRecommendMall(msg.PersonalRecommendMall, &pb->personalrecommendmall());
	_ConvertPbToFCSRspGetMedalChestAward(msg.GetMedalChestAward, &pb->getmedalchestaward());
	_ConvertPbToFCSRspSetItemAutoUse(msg.SetItemAutoUse, &pb->setitemautouse());
}


USTRUCT(BlueprintType)
struct  FCSNtfBody {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfKickOff KickOff;	//踢线

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfWait NtfWait;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassDayBody PassDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassWeekBody PassWeek;	//跨周通告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassMonthBody PassMonth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfWorldChat WorldChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCSDTMail> Mails;	//邮件列表

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfHeadPic HeadPic;	//头像变更通告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpMatch PvpMatch;	//pvp匹配

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvp Pvp;	//pvp匹配

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpMatchCancel PvpMatchCancel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpStatus PvpStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpPlayerReady NtfPvpPlayerReady;	//PVP玩家已准备好

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpBegin PvpBegin;	//pvp开始

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPlayerFinish PlayerFinish;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpEnd PvpEnd;	//pvp结束

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMarquee Marquee;	//GM跑马灯通告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRemoveMarquee RemoveMarquee;	//删除跑马灯

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfLoadingProgress LoadingProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpChat PvpChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfReload Reload;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPay Pay;	//支付通告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfChat Chat;	//聊天消息下发

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfFollowList FollowList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfNewFollower NewFollower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfLostFollower LostFollower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfInviteJoinTeam InviteJoinTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPlayerJoinTeam PlayerJoinTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPlayerLeaveTeam PlayerLeaveTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfKickOffTeamPlayer KickOffTeamPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamMsg TeamMsg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamReady TeamReady;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRejectJoinTeam RejectJoinTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfNotice Notice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRemoveNotice RemoveNotice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUpgradeBattleStage UpgradeBattleStage;	//战阶升级通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassportTaskProgress PassportTaskProgress;	//通行证任务进度通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRankSeasonEval RankSeasonEval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBindAccounts BindAccounts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfSeasonTaskProgress SeasonTaskProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAlphaActivity AlphaActivity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfOffSeasonToNewSeason OffSeasonToNewSeason;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfLanguageMd5List LanguageMd5List;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfActivityProgress ActivityProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRemoveActivity RemoveActivity;	//删除活动

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfActivityConfig ActivityConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMeleeTaskProgress MeleeTaskProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfSetTeamMode SetTeamMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassportOpen PassportOpen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassportClose PassportClose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfWeekIndex WeekIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpHistory PvpHistory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamPvpEnd TeamPvpEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfProbeNetDelay ProbeNetDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRefreshGoods RefreshGoods;	//特价礼包刷新通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRemoveEggs RemoveEggs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfSwitchSet SwitchSet;	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBlacklist Blacklist;	//通知黑名单信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBindPhoneNumberSwitch BindPhoneNumberSwitch;	//通知手机绑定开关

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfWorldInvite WorldInvite;	//邀约

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMallNotice MallNotice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPrivilege Privilege;	//通知特权

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAARemind AARemind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAABan AABan;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAAVerify AAVerify;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPhoneNumber PhoneNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAntiCallBack AntiCallBack;	//安全sdk anti回调

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfFortuneBagTime FortuneBagTime;	//福袋时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUpdateItem UpdateItem;	//通知物品/货币更改

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfCreditScore CreditScore;	//安全信用分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBuffAct BuffAct;	//buf活动

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfActivityGroup ActivityGroup;	//活动组信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfClearChat ClearChat;	//清空聊天内容

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfForbidInfo ForbidInfo;	//封禁信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMidasDiamond MidasDiamond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfJoinVoiceTeam JoinVoiceTeam;	//加入Team语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfJoinVoicePvp JoinVoicePvp;	//加入Pvp语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfJoinVoiceCamp JoinVoiceCamp;	//加入Camp语音房间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfWxVVip WxVVip;	//同步微信大玩家信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfFreeFlow FreeFlow;	//免流查询

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfObserveStatus ObserveStatus;	//观战状态通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGameMarquee GameMarquee;	//游戏内跑马灯

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfWxRedPacket WxRedPacket;	//微信大玩家红包

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGmSysMsg GmSysMsg;	//idip通知sysMsg

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfNewPunishment NewPunishment;	//惩罚通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamSlot TeamSlot;	//队伍的成员的位置信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamSubMode TeamSubMode;	//修改子模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamSlotStatus TeamSlotStatus;	//通知换位状态

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPunishmentInfo PunishmentInfo;	//惩罚信息通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRemovePunishment RemovePunishment;	//移除惩罚通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpConfirm PvpConfirm;	//游戏确认通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMatchSuccess MatchSuccess;	//匹配成功

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfOldBusinessPlayer OldBusinessPlayer;	//business的老玩家信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfChangeTeamSlot ChangeTeamSlot;	//通知换位请求

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRefuseChangeTeamSlot RefuseChangeTeamSlot;	//通知拒绝换位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfCancelChangeSlot CancelChangeSlot;	//取消换位

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfShowChessSkin ShowChessSkin;	//当前配置的棋子皮肤通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfOnHelpReddot OnHelpReddot;	//打开知己红点

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBagUpdate BagUpdate;	//背包变更

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRefreshMelee RefreshMelee;	//梦境模式变更通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfWebLogin WebLogin;	//通知网页登录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfCurrentTournament CurrentTournament;	//当前进行的赛事通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTournamentBegin TournamentBegin;	//赛事开始通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTournamentEnrollBegin TournamentEnrollBegin;	//赛事报名开始通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTournamentEnrollEnd TournamentEnrollEnd;	//赛事报名结束通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfJoinTournamentRoom JoinTournamentRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTournamentEnd TournamentEnd;	//赛事结束通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTournamentOut TournamentOut;	//通知客户端赛事淘汰

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTournamentRoundEnd TournamentRoundEnd;	//赛事轮次结束通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfLuckStarAward LuckStarAward;	//幸运星奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfInviteObserve InviteObserve;	//邀请观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRejectObserve RejectObserve;	//拒绝观战

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfChestCount ChestCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRecruitInfo RecruitInfo;	//招募信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRecruitPlayer RecruitPlayer;	//招募到玩家

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRecruitPlayerBattle RecruitPlayerBattle;	//招募玩家的对局数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBetOnBounty BetOnBounty;	//赏金通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfActivityTaskUnlock ActivityTaskUnlock;	//活动任务解锁

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPsServerOnly PsServerOnly;	//ps server only

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAddThirdPvpInfo AddThirdPvpInfo;	//通知增加第三方比赛信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfDelThirdPvpInfo DelThirdPvpInfo;	//通知删除第三方比赛信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPs4ServerOnly Ps4ServerOnly;	//通知ps4serveronly

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfLuckMallGoods LuckMallGoods;	//幸运星商店

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfChessListErr ChessListErr;	//通知房主队内玩家自定义组卡有误

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfChestRecord ChestRecord;	// 开宝箱记录

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGOAInfo GOAInfo;	//营销活动平台

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMedalInfos MedalInfo;	//更新勋章编号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMedalId MedalId;	//通知勋章ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpReset PvpReset;	//pvp重置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfDelMail DelMail;	//删除邮件通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfItemInfo ItemInfo;	//更新物品信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassportNum PassportNum;	//通行证卡号

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassportYearCardNum PassportYearCardNum;	//通行证年卡剩余次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamOP TeamOP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamDismiss TeamDismiss;	// 队伍解散

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfSwitchModeInTeam SwitchModeInTeam;	// 队伍中切换模式

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAddBanner AddBanner;	// 添加banner通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRemoveBanner RemoveBanner;	// 删除banner通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfSingleRoundFlow SingleRoundFlow;	// 玩家单回合数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTeamStatus TeamStatus;	// 队伍状态通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTNGameEnd TNGameEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPlayerLackResourceInTeam PlayerLackResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfFavMapRemoved FavMapRemoved;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfWorkshopMatchResult WorkshopMatchResult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBigWinnerExpandMatch BigWinnerExpandMatch;	// 大赢家扩大匹配

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfVerifyRealName VerifyRealName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildJoin GuildJoin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildMemberChange MemberChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildKickoff GuildKickoff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildRoleChange GuildRoleChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildAttrChange GuildAttrChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildChat GuildChat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfNewGuildLog NewGuildLog;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildApplicantChange ApplicantChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildInviteeChange InviteeChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildNewInvite GuildNewInvite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGuildInfo GuildInfo;	// 登录下发公会信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfVngCommentAwardReset VngAwardReset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAdAward AdAward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAdCount AdCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUIForbid UIForbid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpUpdateMessengerPos PvpUpdateMessengerPos;	// 同步信使位置

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpPlayerLoggedIn PvpPlayerLoggedIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPassThrough PassThrough;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAA AA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpReconnect PvpReconnect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUpdateBattleResult UpdateBattleResult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfVisitPlayer VisitPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfKrIdentityAuth KrIdentityAuth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfKrAddictionTip KrAddictionTip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfLeaveGameEarly LeaveGameEarly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfKrAddictionCountdown KrAddictionCountdown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfHistoryChatMsg HistroyChatMsg;	// 通知历史聊天信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfSystemGmTime GMTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfChangeName ChangeName;	// 修改玩家昵称通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfFirstPay FirstPay;	// 玩家首充通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPlayerExpChanged ExpChanged;	// 玩家当前经验变化通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTaskProgress TaskProgress;	// 任务进度通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfNewPlayerGuideEnded NewPlayerGuideEnded;	// 新手引导已结束

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTasksInfo TasksInfo;	// 任务信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpAwardsInfo PvpAwardsInfo;	// Pvp宝箱数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAddAward AddAward;	// 通知奖励

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfLimitRefresh LimitRefresh;	// 刷新上限

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUpdateNotice UpdateNotice;	// 通知更新公告

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUpdatePveChallengeCount UpdatePveChallengeCount;	// 通知更新挑战次数 抽奖次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAdDiscount AdDiscount;	// 通知更新挑战次数 抽奖次数

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfCalcMmr CalcMmr;	// 结算ffmmr

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBag Bag;	// 背包物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfItemAttributes ItemAttributes;	// 背包物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPvpAffixTrigger PVPAffixTrigger;	// 背包物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUpdatePvpData UpdatePvpData;	// 更新pvp数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUpgradePassport UpgradePassport;	// 通行证升级

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUpdateTeamDeBuff UpdateTeamDeBuff;	// 房主更新设置debuuf

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPveEval PveEval;	// 通知pve结算

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfUnlockCardGroup UnlockCardGroup;	// 通知解锁的卡组

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfCustomPveActivity CustomPveActivity;	// 通知选技pve

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGmBan CSNtfGmBan;	// gm封禁信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfTDPlayerInfo TDPlayerInfo;	// 塔防数据

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMentorInviteMsg MentorInviteMsg;	// 师徒邀请信息

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfBecomeMentor BecomeMentor;	// 成为师傅

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMentorRelation MentorRelation;	// 关系建立通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfPupilTaskUpdate MentorShipTaskUpdate;	// 师徒的任务专属通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfMentorLevel MentorLevel;	// 师徒等级变化 时通知

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfCurDressUpdate CurDressUpdate;	// 当前穿戴的物品更新

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfChangeExchangeMark ChangeExchangeMark;	// 改变拍卖行标记

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfRefreshPassport RefreshPassport;	//通行证刷新

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfGmRemoveMail GmRemoveMail;	//gm移除邮件

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCSNtfAutoUseItem AutoUseItem;	//物品自动使用触发通知

};
static void _ConvertPbToFCSNtfBody(FCSNtfBody &msg, const msg::CSNtfBody *pb) {
	_ConvertPbToFCSNtfKickOff(msg.KickOff, &pb->kickoff());
	_ConvertPbToFCSNtfWait(msg.NtfWait, &pb->ntfwait());
	_ConvertPbToFCSNtfPassDayBody(msg.PassDay, &pb->passday());
	_ConvertPbToFCSNtfPassWeekBody(msg.PassWeek, &pb->passweek());
	_ConvertPbToFCSNtfPassMonthBody(msg.PassMonth, &pb->passmonth());
	_ConvertPbToFCSNtfWorldChat(msg.WorldChat, &pb->worldchat());
	for (int i = 0; i < pb->mails().size(); i++) {
		auto &a = pb->mails().Get(i);
		FCSDTMail tmp;
		_ConvertPbToFCSDTMail(tmp, &a);
		msg.Mails.Add(tmp);
	}
	_ConvertPbToFCSNtfHeadPic(msg.HeadPic, &pb->headpic());
	_ConvertPbToFCSNtfPvpMatch(msg.PvpMatch, &pb->pvpmatch());
	_ConvertPbToFCSNtfPvp(msg.Pvp, &pb->pvp());
	_ConvertPbToFCSNtfPvpMatchCancel(msg.PvpMatchCancel, &pb->pvpmatchcancel());
	_ConvertPbToFCSNtfPvpStatus(msg.PvpStatus, &pb->pvpstatus());
	_ConvertPbToFCSNtfPvpPlayerReady(msg.NtfPvpPlayerReady, &pb->ntfpvpplayerready());
	_ConvertPbToFCSNtfPvpBegin(msg.PvpBegin, &pb->pvpbegin());
	_ConvertPbToFCSNtfPlayerFinish(msg.PlayerFinish, &pb->playerfinish());
	_ConvertPbToFCSNtfPvpEnd(msg.PvpEnd, &pb->pvpend());
	_ConvertPbToFCSNtfMarquee(msg.Marquee, &pb->marquee());
	_ConvertPbToFCSNtfRemoveMarquee(msg.RemoveMarquee, &pb->removemarquee());
	_ConvertPbToFCSNtfLoadingProgress(msg.LoadingProgress, &pb->loadingprogress());
	_ConvertPbToFCSNtfPvpChat(msg.PvpChat, &pb->pvpchat());
	_ConvertPbToFCSNtfReload(msg.Reload, &pb->reload());
	_ConvertPbToFCSNtfPay(msg.Pay, &pb->pay());
	_ConvertPbToFCSNtfChat(msg.Chat, &pb->chat());
	_ConvertPbToFCSNtfFollowList(msg.FollowList, &pb->followlist());
	_ConvertPbToFCSNtfNewFollower(msg.NewFollower, &pb->newfollower());
	_ConvertPbToFCSNtfLostFollower(msg.LostFollower, &pb->lostfollower());
	_ConvertPbToFCSNtfInviteJoinTeam(msg.InviteJoinTeam, &pb->invitejointeam());
	_ConvertPbToFCSNtfPlayerJoinTeam(msg.PlayerJoinTeam, &pb->playerjointeam());
	_ConvertPbToFCSNtfPlayerLeaveTeam(msg.PlayerLeaveTeam, &pb->playerleaveteam());
	_ConvertPbToFCSNtfKickOffTeamPlayer(msg.KickOffTeamPlayer, &pb->kickoffteamplayer());
	_ConvertPbToFCSNtfTeamMsg(msg.TeamMsg, &pb->teammsg());
	_ConvertPbToFCSNtfTeamReady(msg.TeamReady, &pb->teamready());
	_ConvertPbToFCSNtfRejectJoinTeam(msg.RejectJoinTeam, &pb->rejectjointeam());
	_ConvertPbToFCSNtfNotice(msg.Notice, &pb->notice());
	_ConvertPbToFCSNtfRemoveNotice(msg.RemoveNotice, &pb->removenotice());
	_ConvertPbToFCSNtfUpgradeBattleStage(msg.UpgradeBattleStage, &pb->upgradebattlestage());
	_ConvertPbToFCSNtfPassportTaskProgress(msg.PassportTaskProgress, &pb->passporttaskprogress());
	_ConvertPbToFCSNtfRankSeasonEval(msg.RankSeasonEval, &pb->rankseasoneval());
	_ConvertPbToFCSNtfBindAccounts(msg.BindAccounts, &pb->bindaccounts());
	_ConvertPbToFCSNtfSeasonTaskProgress(msg.SeasonTaskProgress, &pb->seasontaskprogress());
	_ConvertPbToFCSNtfAlphaActivity(msg.AlphaActivity, &pb->alphaactivity());
	_ConvertPbToFCSNtfOffSeasonToNewSeason(msg.OffSeasonToNewSeason, &pb->offseasontonewseason());
	_ConvertPbToFCSNtfLanguageMd5List(msg.LanguageMd5List, &pb->languagemd5list());
	_ConvertPbToFCSNtfActivityProgress(msg.ActivityProgress, &pb->activityprogress());
	_ConvertPbToFCSNtfRemoveActivity(msg.RemoveActivity, &pb->removeactivity());
	_ConvertPbToFCSNtfActivityConfig(msg.ActivityConfig, &pb->activityconfig());
	_ConvertPbToFCSNtfMeleeTaskProgress(msg.MeleeTaskProgress, &pb->meleetaskprogress());
	_ConvertPbToFCSNtfSetTeamMode(msg.SetTeamMode, &pb->setteammode());
	_ConvertPbToFCSNtfPassportOpen(msg.PassportOpen, &pb->passportopen());
	_ConvertPbToFCSNtfPassportClose(msg.PassportClose, &pb->passportclose());
	_ConvertPbToFCSNtfWeekIndex(msg.WeekIndex, &pb->weekindex());
	_ConvertPbToFCSNtfPvpHistory(msg.PvpHistory, &pb->pvphistory());
	_ConvertPbToFCSNtfTeamPvpEnd(msg.TeamPvpEnd, &pb->teampvpend());
	_ConvertPbToFCSNtfProbeNetDelay(msg.ProbeNetDelay, &pb->probenetdelay());
	_ConvertPbToFCSNtfRefreshGoods(msg.RefreshGoods, &pb->refreshgoods());
	_ConvertPbToFCSNtfRemoveEggs(msg.RemoveEggs, &pb->removeeggs());
	_ConvertPbToFCSNtfSwitchSet(msg.SwitchSet, &pb->switchset());
	_ConvertPbToFCSNtfBlacklist(msg.Blacklist, &pb->blacklist());
	_ConvertPbToFCSNtfBindPhoneNumberSwitch(msg.BindPhoneNumberSwitch, &pb->bindphonenumberswitch());
	_ConvertPbToFCSNtfWorldInvite(msg.WorldInvite, &pb->worldinvite());
	_ConvertPbToFCSNtfMallNotice(msg.MallNotice, &pb->mallnotice());
	_ConvertPbToFCSNtfPrivilege(msg.Privilege, &pb->privilege());
	_ConvertPbToFCSNtfAARemind(msg.AARemind, &pb->aaremind());
	_ConvertPbToFCSNtfAABan(msg.AABan, &pb->aaban());
	_ConvertPbToFCSNtfAAVerify(msg.AAVerify, &pb->aaverify());
	_ConvertPbToFCSNtfPhoneNumber(msg.PhoneNumber, &pb->phonenumber());
	_ConvertPbToFCSNtfAntiCallBack(msg.AntiCallBack, &pb->anticallback());
	_ConvertPbToFCSNtfFortuneBagTime(msg.FortuneBagTime, &pb->fortunebagtime());
	_ConvertPbToFCSNtfUpdateItem(msg.UpdateItem, &pb->updateitem());
	_ConvertPbToFCSNtfCreditScore(msg.CreditScore, &pb->creditscore());
	_ConvertPbToFCSNtfBuffAct(msg.BuffAct, &pb->buffact());
	_ConvertPbToFCSNtfActivityGroup(msg.ActivityGroup, &pb->activitygroup());
	_ConvertPbToFCSNtfClearChat(msg.ClearChat, &pb->clearchat());
	_ConvertPbToFCSNtfForbidInfo(msg.ForbidInfo, &pb->forbidinfo());
	_ConvertPbToFCSNtfMidasDiamond(msg.MidasDiamond, &pb->midasdiamond());
	_ConvertPbToFCSNtfJoinVoiceTeam(msg.JoinVoiceTeam, &pb->joinvoiceteam());
	_ConvertPbToFCSNtfJoinVoicePvp(msg.JoinVoicePvp, &pb->joinvoicepvp());
	_ConvertPbToFCSNtfJoinVoiceCamp(msg.JoinVoiceCamp, &pb->joinvoicecamp());
	_ConvertPbToFCSNtfWxVVip(msg.WxVVip, &pb->wxvvip());
	_ConvertPbToFCSNtfFreeFlow(msg.FreeFlow, &pb->freeflow());
	_ConvertPbToFCSNtfObserveStatus(msg.ObserveStatus, &pb->observestatus());
	_ConvertPbToFCSNtfGameMarquee(msg.GameMarquee, &pb->gamemarquee());
	_ConvertPbToFCSNtfWxRedPacket(msg.WxRedPacket, &pb->wxredpacket());
	_ConvertPbToFCSNtfGmSysMsg(msg.GmSysMsg, &pb->gmsysmsg());
	_ConvertPbToFCSNtfNewPunishment(msg.NewPunishment, &pb->newpunishment());
	_ConvertPbToFCSNtfTeamSlot(msg.TeamSlot, &pb->teamslot());
	_ConvertPbToFCSNtfTeamSubMode(msg.TeamSubMode, &pb->teamsubmode());
	_ConvertPbToFCSNtfTeamSlotStatus(msg.TeamSlotStatus, &pb->teamslotstatus());
	_ConvertPbToFCSNtfPunishmentInfo(msg.PunishmentInfo, &pb->punishmentinfo());
	_ConvertPbToFCSNtfRemovePunishment(msg.RemovePunishment, &pb->removepunishment());
	_ConvertPbToFCSNtfPvpConfirm(msg.PvpConfirm, &pb->pvpconfirm());
	_ConvertPbToFCSNtfMatchSuccess(msg.MatchSuccess, &pb->matchsuccess());
	_ConvertPbToFCSNtfOldBusinessPlayer(msg.OldBusinessPlayer, &pb->oldbusinessplayer());
	_ConvertPbToFCSNtfChangeTeamSlot(msg.ChangeTeamSlot, &pb->changeteamslot());
	_ConvertPbToFCSNtfRefuseChangeTeamSlot(msg.RefuseChangeTeamSlot, &pb->refusechangeteamslot());
	_ConvertPbToFCSNtfCancelChangeSlot(msg.CancelChangeSlot, &pb->cancelchangeslot());
	_ConvertPbToFCSNtfShowChessSkin(msg.ShowChessSkin, &pb->showchessskin());
	_ConvertPbToFCSNtfOnHelpReddot(msg.OnHelpReddot, &pb->onhelpreddot());
	_ConvertPbToFCSNtfBagUpdate(msg.BagUpdate, &pb->bagupdate());
	_ConvertPbToFCSNtfRefreshMelee(msg.RefreshMelee, &pb->refreshmelee());
	_ConvertPbToFCSNtfWebLogin(msg.WebLogin, &pb->weblogin());
	_ConvertPbToFCSNtfCurrentTournament(msg.CurrentTournament, &pb->currenttournament());
	_ConvertPbToFCSNtfTournamentBegin(msg.TournamentBegin, &pb->tournamentbegin());
	_ConvertPbToFCSNtfTournamentEnrollBegin(msg.TournamentEnrollBegin, &pb->tournamentenrollbegin());
	_ConvertPbToFCSNtfTournamentEnrollEnd(msg.TournamentEnrollEnd, &pb->tournamentenrollend());
	_ConvertPbToFCSNtfJoinTournamentRoom(msg.JoinTournamentRoom, &pb->jointournamentroom());
	_ConvertPbToFCSNtfTournamentEnd(msg.TournamentEnd, &pb->tournamentend());
	_ConvertPbToFCSNtfTournamentOut(msg.TournamentOut, &pb->tournamentout());
	_ConvertPbToFCSNtfTournamentRoundEnd(msg.TournamentRoundEnd, &pb->tournamentroundend());
	_ConvertPbToFCSNtfLuckStarAward(msg.LuckStarAward, &pb->luckstaraward());
	_ConvertPbToFCSNtfInviteObserve(msg.InviteObserve, &pb->inviteobserve());
	_ConvertPbToFCSNtfRejectObserve(msg.RejectObserve, &pb->rejectobserve());
	_ConvertPbToFCSNtfChestCount(msg.ChestCount, &pb->chestcount());
	_ConvertPbToFCSNtfRecruitInfo(msg.RecruitInfo, &pb->recruitinfo());
	_ConvertPbToFCSNtfRecruitPlayer(msg.RecruitPlayer, &pb->recruitplayer());
	_ConvertPbToFCSNtfRecruitPlayerBattle(msg.RecruitPlayerBattle, &pb->recruitplayerbattle());
	_ConvertPbToFCSNtfBetOnBounty(msg.BetOnBounty, &pb->betonbounty());
	_ConvertPbToFCSNtfActivityTaskUnlock(msg.ActivityTaskUnlock, &pb->activitytaskunlock());
	_ConvertPbToFCSNtfPsServerOnly(msg.PsServerOnly, &pb->psserveronly());
	_ConvertPbToFCSNtfAddThirdPvpInfo(msg.AddThirdPvpInfo, &pb->addthirdpvpinfo());
	_ConvertPbToFCSNtfDelThirdPvpInfo(msg.DelThirdPvpInfo, &pb->delthirdpvpinfo());
	_ConvertPbToFCSNtfPs4ServerOnly(msg.Ps4ServerOnly, &pb->ps4serveronly());
	_ConvertPbToFCSNtfLuckMallGoods(msg.LuckMallGoods, &pb->luckmallgoods());
	_ConvertPbToFCSNtfChessListErr(msg.ChessListErr, &pb->chesslisterr());
	_ConvertPbToFCSNtfChestRecord(msg.ChestRecord, &pb->chestrecord());
	_ConvertPbToFCSNtfGOAInfo(msg.GOAInfo, &pb->goainfo());
	_ConvertPbToFCSNtfMedalInfos(msg.MedalInfo, &pb->medalinfo());
	_ConvertPbToFCSNtfMedalId(msg.MedalId, &pb->medalid());
	_ConvertPbToFCSNtfPvpReset(msg.PvpReset, &pb->pvpreset());
	_ConvertPbToFCSNtfDelMail(msg.DelMail, &pb->delmail());
	_ConvertPbToFCSNtfItemInfo(msg.ItemInfo, &pb->iteminfo());
	_ConvertPbToFCSNtfPassportNum(msg.PassportNum, &pb->passportnum());
	_ConvertPbToFCSNtfPassportYearCardNum(msg.PassportYearCardNum, &pb->passportyearcardnum());
	_ConvertPbToFCSNtfTeamOP(msg.TeamOP, &pb->teamop());
	_ConvertPbToFCSNtfTeamDismiss(msg.TeamDismiss, &pb->teamdismiss());
	_ConvertPbToFCSNtfSwitchModeInTeam(msg.SwitchModeInTeam, &pb->switchmodeinteam());
	_ConvertPbToFCSNtfAddBanner(msg.AddBanner, &pb->addbanner());
	_ConvertPbToFCSNtfRemoveBanner(msg.RemoveBanner, &pb->removebanner());
	_ConvertPbToFCSNtfSingleRoundFlow(msg.SingleRoundFlow, &pb->singleroundflow());
	_ConvertPbToFCSNtfTeamStatus(msg.TeamStatus, &pb->teamstatus());
	_ConvertPbToFCSNtfTNGameEnd(msg.TNGameEnd, &pb->tngameend());
	_ConvertPbToFCSNtfPlayerLackResourceInTeam(msg.PlayerLackResource, &pb->playerlackresource());
	_ConvertPbToFCSNtfFavMapRemoved(msg.FavMapRemoved, &pb->favmapremoved());
	_ConvertPbToFCSNtfWorkshopMatchResult(msg.WorkshopMatchResult, &pb->workshopmatchresult());
	_ConvertPbToFCSNtfBigWinnerExpandMatch(msg.BigWinnerExpandMatch, &pb->bigwinnerexpandmatch());
	_ConvertPbToFCSNtfVerifyRealName(msg.VerifyRealName, &pb->verifyrealname());
	_ConvertPbToFCSNtfGuildJoin(msg.GuildJoin, &pb->guildjoin());
	_ConvertPbToFCSNtfGuildMemberChange(msg.MemberChange, &pb->memberchange());
	_ConvertPbToFCSNtfGuildKickoff(msg.GuildKickoff, &pb->guildkickoff());
	_ConvertPbToFCSNtfGuildRoleChange(msg.GuildRoleChange, &pb->guildrolechange());
	_ConvertPbToFCSNtfGuildAttrChange(msg.GuildAttrChange, &pb->guildattrchange());
	_ConvertPbToFCSNtfGuildChat(msg.GuildChat, &pb->guildchat());
	_ConvertPbToFCSNtfNewGuildLog(msg.NewGuildLog, &pb->newguildlog());
	_ConvertPbToFCSNtfGuildApplicantChange(msg.ApplicantChange, &pb->applicantchange());
	_ConvertPbToFCSNtfGuildInviteeChange(msg.InviteeChange, &pb->inviteechange());
	_ConvertPbToFCSNtfGuildNewInvite(msg.GuildNewInvite, &pb->guildnewinvite());
	_ConvertPbToFCSNtfGuildInfo(msg.GuildInfo, &pb->guildinfo());
	_ConvertPbToFCSNtfVngCommentAwardReset(msg.VngAwardReset, &pb->vngawardreset());
	_ConvertPbToFCSNtfAdAward(msg.AdAward, &pb->adaward());
	_ConvertPbToFCSNtfAdCount(msg.AdCount, &pb->adcount());
	_ConvertPbToFCSNtfUIForbid(msg.UIForbid, &pb->uiforbid());
	_ConvertPbToFCSNtfPvpUpdateMessengerPos(msg.PvpUpdateMessengerPos, &pb->pvpupdatemessengerpos());
	_ConvertPbToFCSNtfPvpPlayerLoggedIn(msg.PvpPlayerLoggedIn, &pb->pvpplayerloggedin());
	_ConvertPbToFCSNtfPassThrough(msg.PassThrough, &pb->passthrough());
	_ConvertPbToFCSNtfAA(msg.AA, &pb->aa());
	_ConvertPbToFCSNtfPvpReconnect(msg.PvpReconnect, &pb->pvpreconnect());
	_ConvertPbToFCSNtfUpdateBattleResult(msg.UpdateBattleResult, &pb->updatebattleresult());
	_ConvertPbToFCSNtfVisitPlayer(msg.VisitPlayer, &pb->visitplayer());
	_ConvertPbToFCSNtfKrIdentityAuth(msg.KrIdentityAuth, &pb->kridentityauth());
	_ConvertPbToFCSNtfKrAddictionTip(msg.KrAddictionTip, &pb->kraddictiontip());
	_ConvertPbToFCSNtfLeaveGameEarly(msg.LeaveGameEarly, &pb->leavegameearly());
	_ConvertPbToFCSNtfKrAddictionCountdown(msg.KrAddictionCountdown, &pb->kraddictioncountdown());
	_ConvertPbToFCSNtfHistoryChatMsg(msg.HistroyChatMsg, &pb->histroychatmsg());
	_ConvertPbToFCSNtfSystemGmTime(msg.GMTime, &pb->gmtime());
	_ConvertPbToFCSNtfChangeName(msg.ChangeName, &pb->changename());
	_ConvertPbToFCSNtfFirstPay(msg.FirstPay, &pb->firstpay());
	_ConvertPbToFCSNtfPlayerExpChanged(msg.ExpChanged, &pb->expchanged());
	_ConvertPbToFCSNtfTaskProgress(msg.TaskProgress, &pb->taskprogress());
	_ConvertPbToFCSNtfNewPlayerGuideEnded(msg.NewPlayerGuideEnded, &pb->newplayerguideended());
	_ConvertPbToFCSNtfTasksInfo(msg.TasksInfo, &pb->tasksinfo());
	_ConvertPbToFCSNtfPvpAwardsInfo(msg.PvpAwardsInfo, &pb->pvpawardsinfo());
	_ConvertPbToFCSNtfAddAward(msg.AddAward, &pb->addaward());
	_ConvertPbToFCSNtfLimitRefresh(msg.LimitRefresh, &pb->limitrefresh());
	_ConvertPbToFCSNtfUpdateNotice(msg.UpdateNotice, &pb->updatenotice());
	_ConvertPbToFCSNtfUpdatePveChallengeCount(msg.UpdatePveChallengeCount, &pb->updatepvechallengecount());
	_ConvertPbToFCSNtfAdDiscount(msg.AdDiscount, &pb->addiscount());
	_ConvertPbToFCSNtfCalcMmr(msg.CalcMmr, &pb->calcmmr());
	_ConvertPbToFCSNtfBag(msg.Bag, &pb->bag());
	_ConvertPbToFCSNtfItemAttributes(msg.ItemAttributes, &pb->itemattributes());
	_ConvertPbToFCSNtfPvpAffixTrigger(msg.PVPAffixTrigger, &pb->pvpaffixtrigger());
	_ConvertPbToFCSNtfUpdatePvpData(msg.UpdatePvpData, &pb->updatepvpdata());
	_ConvertPbToFCSNtfUpgradePassport(msg.UpgradePassport, &pb->upgradepassport());
	_ConvertPbToFCSNtfUpdateTeamDeBuff(msg.UpdateTeamDeBuff, &pb->updateteamdebuff());
	_ConvertPbToFCSNtfPveEval(msg.PveEval, &pb->pveeval());
	_ConvertPbToFCSNtfUnlockCardGroup(msg.UnlockCardGroup, &pb->unlockcardgroup());
	_ConvertPbToFCSNtfCustomPveActivity(msg.CustomPveActivity, &pb->custompveactivity());
	_ConvertPbToFCSNtfGmBan(msg.CSNtfGmBan, &pb->csntfgmban());
	_ConvertPbToFCSNtfTDPlayerInfo(msg.TDPlayerInfo, &pb->tdplayerinfo());
	_ConvertPbToFCSNtfMentorInviteMsg(msg.MentorInviteMsg, &pb->mentorinvitemsg());
	_ConvertPbToFCSNtfBecomeMentor(msg.BecomeMentor, &pb->becomementor());
	_ConvertPbToFCSNtfMentorRelation(msg.MentorRelation, &pb->mentorrelation());
	_ConvertPbToFCSNtfPupilTaskUpdate(msg.MentorShipTaskUpdate, &pb->mentorshiptaskupdate());
	_ConvertPbToFCSNtfMentorLevel(msg.MentorLevel, &pb->mentorlevel());
	_ConvertPbToFCSNtfCurDressUpdate(msg.CurDressUpdate, &pb->curdressupdate());
	_ConvertPbToFCSNtfChangeExchangeMark(msg.ChangeExchangeMark, &pb->changeexchangemark());
	_ConvertPbToFCSNtfRefreshPassport(msg.RefreshPassport, &pb->refreshpassport());
	_ConvertPbToFCSNtfGmRemoveMail(msg.GmRemoveMail, &pb->gmremovemail());
	_ConvertPbToFCSNtfAutoUseItem(msg.AutoUseItem, &pb->autouseitem());
}


