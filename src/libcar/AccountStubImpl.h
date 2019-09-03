#pragma once
#include "core/Def.h"
#include <Poco/SharedPtr.h>
#include <Poco/Data/SQLite/SQLite.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Buffer.h>

namespace uit{

class UIT_API AccountStubImpl
{
public:
	//加载数据库
	bool load(const std::string &path);
	std::string getDBPath() const;

	//注册一个账号
	void registerAccount(const std::string &id, const std::string &password, const std::string &nickname);

	//注销一个账号
	void deleteAccount(const std::string &id);

	//密码
	void setPassword(const std::string &id, const std::string &password);
	std::string getPassword(const std::string &id) const;

	//昵称
	void setNickname(const std::string &id, const std::string &nickname);
	std::string getNickname(const std::string &id) const;

	//头像
	void setPhoto(const std::string &id, const Poco::Buffer<char> &photo);
	Poco::Buffer<char> getPhoto(const std::string &id) const;

private:
	std::string								m_DBpath;
	Poco::SharedPtr<Poco::Data::Session>	m_session;
};

}