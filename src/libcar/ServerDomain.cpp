#include "car/ServerDomain.h"
#include "AccountStubImpl.h"
#include "car/AccountInterface.h"

using namespace uit;

ServerDomain::ServerDomain(const std::string &ip, int port)
	: m_ip(ip)
	, m_port(port)
	, m_accountStub(std::make_shared<AccountStubImpl>())
{
	RCF::init();
	m_server = std::make_shared<RCF::RcfServer>(RCF::TcpEndpoint(ip, port));
}

ServerDomain::~ServerDomain()
{
	RCF::deinit();
}

std::string ServerDomain::ip() const
{
	return m_ip;
}

int ServerDomain::port() const
{
	return m_port;
}

bool ServerDomain::configDBPath(const std::string &path)
{
	return m_accountStub->load(path);
}

std::string ServerDomain::getDBPath() const
{
	return m_accountStub->getDBPath();
}

bool ServerDomain::startup()
{
	if (m_server->isStarted())
		return true;

	m_server->bind<AccountInterface>(*m_accountStub);
	m_server->start();
	return true;
}

bool ServerDomain::stop()
{
	m_server->stop();
	return true;
}
