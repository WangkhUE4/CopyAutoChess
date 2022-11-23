@echo off

powershell -Command "(gc res.h) -replace 'FChessData',          'FResChessData'         | Out-File -encoding default res.h"
powershell -Command "(gc res.h) -replace 'FChessPlayerInfo',    'FResChessPlayerInfo'   | Out-File -encoding default res.h"
powershell -Command "(gc res.h) -replace 'FChessInfo',          'FResChessInfo'         | Out-File -encoding default res.h"
powershell -Command "(gc res.h) -replace 'FSkillInfo',          'FResSkillInfo'         | Out-File -encoding default res.h"
powershell -Command "(gc res.h) -replace 'FRegionInfo',         'FResRegionInfo'        | Out-File -encoding default res.h"

powershell -Command "(gc common.pb.h) -replace 'enum CHANELTYPE {',       'enum CHANELTYPE : int {'        | Out-File -encoding default common.pb.h"
powershell -Command "(gc common.pb.h) -replace 'enum RANKTYPE {',         'enum RANKTYPE : int {'          | Out-File -encoding default common.pb.h"

powershell -Command "(gc csprotocol.pb.h) -replace 'enum CSMsgID {',      'enum CSMsgID : int {'  | Out-File -encoding default csprotocol.pb.h"

powershell -Command "(gc result.h) -replace 'enum class ERESULT: int32 {',      'UENUM() enum class ERESULT: int32 {'  | Out-File -encoding default result.h"
