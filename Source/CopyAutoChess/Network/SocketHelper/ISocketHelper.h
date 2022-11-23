#pragma once

namespace msg
{
	enum CSMsgID : int;
	class CSReqBody;
	class CSRspBody;
	class CSNtfBody;
}

using RspCall = std::function<void(const msg::CSRspBody& message)>;

class ISocketHelper
{
public:
	virtual ~ISocketHelper() {}
	virtual void testPrint() = 0;

	virtual void connect(const FString ip, int32 port) = 0;
	virtual void disconnect() = 0;
	virtual void send(msg::CSMsgID reqMsgId, const msg::CSReqBody& msgBody, msg::CSMsgID rspMsgId, const RspCall& rspCall) = 0;
};
