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

	//账号相关
	bool regist(const std::string &userID, const std::string &password, const std::string &nickname);
	bool isRegisted(const std::string &userID);
	void setPassword(const std::string &userID, const std::string &password);
	void setNickname(const std::string &userID, const std::string &nickname);
	void setSignaTure(const std::string &userID, const std::string &signaTure);
	bool setPhoto(const std::string &userID, const std::string &photoBuffer);
	bool setVehicleOnline(const std::string &userID, const std::string &password, bool online);
	bool setPCOnline(const std::string &userID, const std::string &password, bool online);
	bool setHandeldOnline(const std::string &userID, const std::string &password, bool online);
	bool setPadOnline(const std::string &userID, const std::string &password, bool online);
	bool getAccountInfo(const std::string &userID, AccountInfo &info);
	bool queryAllAccountInfo(std::vector<AccountInfo> &infos);

	//联系人
	bool addContacts(const std::string &userID, const std::string &friendID);
	bool removeContacts(const std::string &userID, const std::string &friendID);
	bool getContacts(const std::string &userID, std::vector<std::string> &friends);

	//消息
	void addP2PMessage(const std::string &fromID, const std::string &toID, const std::string &msg);
	void getP2PMessage(const std::string &user0, const std::string &user1, std::vector<std::string> &msgs);
	
	struct AccountChangedArgs { std::string userID; AccountInfo info; };
	uit::Event<AccountChangedArgs>	AccountChanged;

private:
	std::string loadImage(const std::string &path) const;

};

}