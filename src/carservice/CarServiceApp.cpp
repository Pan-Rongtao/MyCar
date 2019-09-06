#include "CarServiceApp.h"
#include "core/Log.h"
#include "core/Runtime.h"

#define LOG_TAG	"SVCar"
#define DEFAULT_DB_DIR		uit::Runtime::getUitEtcDirectory() + "account.db"

int CarServiceApp::main(const std::vector<std::string>& args)
{
	waitForTerminationRequest();
	return ServerApplication::EXIT_OK;
}

void CarServiceApp::initialize(Application & app)
{
	ServerApplication::initialize(app);
	auto k = uit::getTickCount();
	m_server = std::make_shared<uit::ServerDomain>(getLocalIp(), 8888);
	if (m_server->configDBPath(DEFAULT_DB_DIR))
	{
		uit::Log::info(LOG_TAG, "load [%s] success, cost [%d] ms.", m_server->getDBPath().data(), (int)(uit::getTickCount() - k));
	}
	else
	{
		uit::Log::info(LOG_TAG, "load [%s] fail.", m_server->getDBPath().data());
		terminate();
		return;
	}
	if (m_server->startup())
	{
		uit::Log::info(LOG_TAG, "server[%s] startup success, cost [%d] ms.", (m_server->ip() + ":" + std::to_string(m_server->port())).data(), (int)(uit::getTickCount() - k));
	}
	else
	{
		uit::Log::error(LOG_TAG, "server startup fail");
		terminate();
		return;
	}
}

void CarServiceApp::uninitialize()
{
	ServerApplication::uninitialize();
	uit::Log::info(LOG_TAG, "service shutdown.");
}

void CarServiceApp::defineOptions(Poco::Util::OptionSet & options)
{
}

std::string CarServiceApp::getLocalIp() const
{
	WSADATA Data;
	if (WSAStartup(MAKEWORD(1, 1), &Data) == 0)
	{
		char hostName[256] = { 0 };
		gethostname(hostName, sizeof(hostName));
		PHOSTENT hostinfo;
		hostinfo = gethostbyname(hostName);
		std::string ip = inet_ntoa(*(struct in_addr*)*hostinfo->h_addr_list);
		WSACleanup();
		return ip;
	}
	else
	{
		uit::Log::error(LOG_TAG, "can't startup winSock when get ip.");
		return "";
	}
}