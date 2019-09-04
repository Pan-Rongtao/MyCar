#pragma once
#include "core/Event.h"
#include <RCF/RCF.hpp>

namespace uit {

class AccountStubImpl;
class UIT_API ServerDomain final
{
public:
	ServerDomain(const std::string &ip, int port);
	~ServerDomain();
	ServerDomain(const ServerDomain &other) = delete;
	void operator =(const ServerDomain &other) = delete;

	std::string ip() const;
	int port() const;

	//配置数据库路径
	bool configDBPath(const std::string &path);
	std::string getDBPath() const;

	//启动
	bool startup();
	bool stop();

	struct ClientLoginEventArgs { std::string id; };
	uit::Event<ClientLoginEventArgs>		ClientLoginEvent;

private:
	std::string							m_ip;
	int									m_port;
	std::shared_ptr<RCF::RcfServer>		m_server;
	std::shared_ptr<AccountStubImpl>	m_accountStub;
};


}