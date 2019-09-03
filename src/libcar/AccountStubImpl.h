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
	void registerAccount(const std::string &id, const std::string &password, const std::string &nickname);

	//ע��һ���˺�
	void deleteAccount(const std::string &id);

	//����
	void setPassword(const std::string &id, const std::string &password);
	std::string getPassword(const std::string &id) const;

	//�ǳ�
	void setNickname(const std::string &id, const std::string &nickname);
	std::string getNickname(const std::string &id) const;

	//ͷ��
	void setPhoto(const std::string &id, const Poco::Buffer<char> &photo);
	Poco::Buffer<char> getPhoto(const std::string &id) const;

private:
	std::string								m_DBpath;
	Poco::SharedPtr<Poco::Data::Session>	m_session;
};

}