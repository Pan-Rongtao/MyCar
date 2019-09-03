#include "car/ServerDomain.h"
#include "AccountServerImpl.h"

using namespace uit;

ServerDomain::ServerDomain()
	: m_running(false)
	, m_accountStub(std::make_shared<AccountStubImpl>())
{
}

bool ServerDomain::configDBPath(const std::string &path)
{
	return true;
}

std::string ServerDomain::getDBPath() const
{
	return "";
}

bool ServerDomain::startup()
{
	if (m_running)
		return true;
	return true;
}

bool ServerDomain::stop()
{
	return true;
}

bool ServerDomain::initServerStub()
{
	return false;
}
