#pragma once
#include "core/Def.h"
#include <Poco/SharedPtr.h>
#include <Poco/Data/SQLite/SQLite.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>
#include "core/Event.h"
#include "server/Types.h"

namespace uit{

class UIT_API AccountStub
{
public:
	static AccountStub *get();

	//账号
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
	UserInfo getUserInfo(const std::string &userID);
	std::vector<UserInfo> queryUsers();

	//联系人
	bool addFriend(const std::string &userID, const std::string &friendID);
	void removeFriend(const std::string &userID, const std::string &friendID);
	std::vector<std::string> getFriends(const std::string &userID);
	std::string addGroup(const std::string &name, const std::string &photo);
	void removeGroup(const std::string &groupID);
	GroupInfo getGroupInfo(const std::string &grouID);
	std::vector<std::string> getBelongGroups(const std::string &userID);
	void setGroupName(const std::string &groupID, const std::string &name);
	void setGroupBrief(const std::string &groupID, const std::string &brief);
	void addGroupMember(const std::string &groupID, const std::string &userID);
	void removeGroupMember(const std::string &groupID, const std::string &userID);
	std::vector<std::string> getGroupMembers(const std::string &groupID);

	//消息
	void addP2PMessage(const std::string &fromID, const std::string &toID, const std::string &msg);
	std::vector<ChatMessage> getP2PMessages(const std::string &user0, const std::string &user1);
	void addGroupMessage(const std::string &groupID, const std::string &fromID, const std::string &msg);
	std::vector<ChatMessage> getGroupMessages(const std::string &groupID);
	
	struct AccountChangedArgs { UserInfo info; };
	uit::Event<AccountChangedArgs>	AccountChanged;

	struct MessageArrivedArgs { ChatMessage msg; };
	uit::Event<MessageArrivedArgs>	MessageArrived;

private:
	bool setOnline(const std::string & userID, bool online, const std::string &field);
	void saveImage(const std::string &path, const std::string &imageBuffer);
	std::string loadImage(const std::string &path) const;

};

}