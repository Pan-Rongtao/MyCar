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
	//�������ݿ�
	bool load(const std::string &path);
	std::string getDBPath() const;

	//ע��һ���˺�
	void regist(const std::string &userID, const std::string &password, const std::string &nickname);

	//ע��һ���˺�
	void remove(const std::string &userID);

	//��¼
	bool login(const std::string &userID, const std::string &password);
	bool logout(const std::string &userID, const std::string & password);
	bool isOnline(const std::string &userID) const;

	//����
	void setPassword(const std::string &userID, const std::string &password);
	std::string getPassword(const std::string &userID) const;

	//�ǳ�
	void setNickname(const std::string &userID, const std::string &nickname);
	std::string getNickname(const std::string &userID) const;

	//ǩ��
	void setSignaTure(const std::string &userID, const std::string &signaTure);
	std::string getSignaTure(const std::string &userID);

	//ͷ��
	void setPhoto(const std::string &userID, const Poco::Buffer<char> &photo);
	Poco::Buffer<char> getPhoto(const std::string &userID) const;

private:
	std::string								m_DBpath;
	Poco::SharedPtr<Poco::Data::Session>	m_session;
};

}