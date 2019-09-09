#include "car/ServerDomain.h"
#include "AccountStubImpl.h"

using namespace uit;

ServerDomain::ServerDomain(const std::string &ip, int port)
	: m_ip(ip)
	, m_port(port)
	, m_accountStub(std::make_shared<AccountStubImpl>(this))
{
	RCF::init();
	m_interfaceServer = std::make_shared<RCF::RcfServer>(RCF::TcpEndpoint(ip, port));
	m_publisherServer = std::make_shared<RCF::RcfServer>(RCF::TcpEndpoint(ip, port));
	m_publisher = m_publisherServer->createPublisher<AccountNofity>();
}

ServerDomain::~ServerDomain()
{
	stop();
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
	if (m_interfaceServer->isStarted())
		return true;

	m_interfaceServer->bind<AccountInterface>(*m_accountStub);
	m_interfaceServer->start();
	return true;
}

bool ServerDomain::stop()
{
	m_publisher->close();
	m_interfaceServer->stop();
	m_publisherServer->stop();
	return true;
}
