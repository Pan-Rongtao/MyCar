#pragma once
#include "core/Def.h"
#include <Poco/SharedPtr.h>
#include <Poco/Data/SQLite/SQLite.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>
#include "core/Event.h"
#include "server/Account.h"

namespace uit{

class UIT_API AccountStub
{
public:
	static AccountStub *instance();

	//注册一个账号
	bool regist(const std::string &userID, const std::string &password, const std::string &nickname);
	//账号是否已经存在
	bool isRegisted(const std::string &userID);

	//登录
	bool login(const std::string &userID, const std::string &password, int terminalType);
	bool logout(const std::string &userID, const std::string & password, int terminalType, bool kickout = false);

	void setPassword(const std::string &userID, const std::string &password);
	void setNickname(const std::string &userID, const std::string &nickname);
	void setSignaTure(const std::string &userID, const std::string &signaTure);
	bool setPhoto(const std::string &userID, const std::string &photoBuffer);
	bool setVehicleOnline(const std::string &userID, const std::string &password, bool online);
	bool setPCOnline(const std::string &userID, const std::string &password, bool online);
	bool setHandeldOnline(const std::string &userID, const std::string &password, bool online);
	bool setPadOnline(const std::string &userID, const std::string &password, bool online);

	//获取账号信息
	bool getAccountInfo(const std::string &userID, AccountInfo &info);

	struct AccountChangedArgs { std::string userID; AccountInfo info; };
	uit::Event<AccountChangedArgs>	AccountChanged;

private:
	std::string loadImage(const std::string &path) const;

};

}