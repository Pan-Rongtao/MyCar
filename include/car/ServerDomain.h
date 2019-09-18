#pragma once
#include "core/Event.h"
#include <RCF/RCF.hpp>
#include "car/Account.h"
#include "car/Car.h"

namespace uit {

class AccountStubImpl;
class CarStubImpl;
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
	std::shared_ptr<RCF::RcfServer>		m_interfaceServer;
	std::shared_ptr<AccountStubImpl>	m_accountStub;
	std::shared_ptr<CarStubImpl>		m_carStub;
	std::shared_ptr<RCF::RcfServer>		m_publisherServer;
	std::shared_ptr<RCF::Publisher<AccountNofity>>	m_publisher;
	friend class AccountStubImpl;
	friend class CarStubImpl;
};


}