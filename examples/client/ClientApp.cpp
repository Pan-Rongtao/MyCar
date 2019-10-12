#include "ClientApp.h"
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/StringTokenizer.h>
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include "core/Log.h"
#include "core/Runtime.h"
#include <cassert>
#include <thread>

using namespace uit;
using namespace Poco;
using namespace Poco::Util;

#define LOG_TAG	"client"
#define DEFAULT_DATA_EVENT_DIR	uit::Runtime::getUitEtcDirectory() + "data-event"
#define CONFIGURE_FILE_PATH		uit::Runtime::getUitEtcDirectory() + "server.conf"

int main(int argc, char **argv)
{
	try {
		ClientApp app;
		app.run();
	}
	catch (RCF::Exception &e)	{ uit::Log::error(LOG_TAG, "a RCF::Exception occur: %s", e.what()); }
	catch (Poco::Exception &e)	{ uit::Log::error(LOG_TAG, "a Poco::Exception occur: %s", e.what()); }
	catch (std::exception &e)	{ uit::Log::error(LOG_TAG, "a std::exception occur: %s", e.what()); }
	catch (...)					{ uit::Log::error(LOG_TAG, "unknown exception"); }
}

int ClientApp::main(const std::vector<std::string>& args)
{
	while (1)
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return Application::EXIT_OK;
}

void ClientApp::initialize(Application & app)
{
	Application::initialize(app);
	RCF::init();
	uint64_t k = uit::getTickCount();
	auto ip = getLocalIp();
	auto interfacePort = 8888;
	auto publisherPort = 9999;
	try {
		Poco::AutoPtr<IniFileConfiguration> ini = new IniFileConfiguration(CONFIGURE_FILE_PATH);
		interfacePort = ini->getInt("InterfacePort", 8888);
		publisherPort = ini->getInt("PublisherPort", 9999);
}
	catch (...) {
		Log::warn(LOG_TAG, "get config fail, user default.");
	}

	RCF::RcfServer subscriptionServer(RCF::TcpEndpoint(-1));
	subscriptionServer.start();
	RCF::SubscriptionParms parms;
	parms.setPublisherEndpoint(RCF::TcpEndpoint(ip, publisherPort));
	RCF::SubscriptionPtr subscriptionPtr = subscriptionServer.createSubscription<AccountNotify>(*this, parms);
	m_client = std::make_shared<RcfClient<AccountInterface>>(RCF::TcpEndpoint(ip, interfacePort));
	
	uit::Log::info(LOG_TAG, "connected to [%s], cost [%d].\n", ip.data(), (int)(uit::getTickCount() - k));
	m_client->regist("13112657701", "Aa123456", "Pan.T");

}

void ClientApp::uninitialize()
{
	Application::uninitialize();
}

void ClientApp::onAccountChanged(const std::string & userID, const AccountInfo & info)
{
}

void ClientApp::onP2PMessageArrived(const std::string & fromID, const P2PMessage & msg)
{
}

void ClientApp::onGroupMessageArrived(const std::string & groupID, const GroupMessage & msg)
{
}

std::string ClientApp::getLocalIp() const
{
#ifdef WIN32
	WSADATA Data;
	auto x = WSAStartup(MAKEWORD(1, 1), &Data);
	char hostName[256] = { 0 };
	gethostname(hostName, sizeof(hostName));
	PHOSTENT hostinfo;
	hostinfo = gethostbyname(hostName);
	std::string ip = inet_ntoa(*(struct in_addr*)*hostinfo->h_addr_list);
	WSACleanup();
	return ip;
#else
	auto getDeviceIp = [](const std::string &sDev)->std::string {
		char ip[80] = { 0 };
		struct ifreq ifr;
		int sk = socket(AF_INET, SOCK_DGRAM, 0);
		strcpy(ifr.ifr_name, sDev.data());
		if (ioctl(sk, SIOCGIFADDR, &ifr) == 0)
			strcpy(ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
		close(sk);
		return ip;
	};
#if POCO_ARCH == ARM
	auto eth = getDeviceIp("eth1");
	if(!eth.empty())
		return eth;
	else
		return getDeviceIp("mlan0");
#else
	return getDeviceIp("ens160");
#endif
#endif
}
