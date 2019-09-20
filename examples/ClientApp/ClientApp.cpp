#include "ClientApp.h"
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/StringTokenizer.h>
#include "core/Log.h"
#include "core/Runtime.h"
#include <cassert>
#include <thread>

using namespace uit;
using namespace Poco;
using namespace Poco::Util;

#define LOG_TAG	"clientapp"
#define DEFAULT_DATA_EVENT_DIR			uit::Runtime::getUitEtcDirectory() + "data-event"

int main(int argc, char **argv)
{
	try {
		ClientApp app;
		app.run();
	}
	catch (RCF::Exception &e)
	{
		uit::Log::error(LOG_TAG, "a RCF::Exception occur: %s", e.what());
	}
	catch (Poco::Exception &e)
	{
		uit::Log::error(LOG_TAG, "a Poco::Exception occur: %s", e.what());
	}
	catch (std::exception &e)
	{
		uit::Log::error(LOG_TAG, "a std::exception occur: %s", e.what());
	}
	catch (...)
	{
		uit::Log::error(LOG_TAG, "unknown exception");
	}
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
#ifdef WIN32
	std::string ip = "192.168.160.133";
	int port = 8888;
#else
	std::string ip = "10.219.125.172";
	int port = 8888;
#endif
	m_client = std::make_shared<RcfClient<AccountInterface>>(RCF::TcpEndpoint(ip, port));
	m_client->getClientStub().setAutoReconnect(true);
	m_client->getClientStub().ping();
	uit::Log::info(LOG_TAG, "connected, cost [%d].\n", (int)(uit::getTickCount() - k));
	m_client->regist("13112657701", "Aa123456", "Pan.T");
	bool b = m_client->getClientStub().isConnected();

	RCF::RcfServer subServer(RCF::TcpEndpoint(-1));
	subServer.start();
	//PrintService printService;
	RCF::SubscriptionParms subParms;
	subParms.setPublisherEndpoint(RCF::TcpEndpoint(ip, 9999));
	RCF::SubscriptionPtr subscriptionPtr = subServer.createSubscription<AccountNotify>(
		*this,
		subParms);
}

void ClientApp::uninitialize()
{
	Application::uninitialize();
}

void ClientApp::defineOptions(OptionSet & options)
{
	Application::defineOptions(options);
	//shortName有很多限制，比如必须是fullName的开头，不能有多个Option shortName相似等。不设置了

	
}

void uit::ClientApp::onPasswordChanged(const std::string & userID, const std::string & password)
{
}

void uit::ClientApp::onUserNicknameChanged(const std::string & userID, const std::string & nickname)
{
}

void uit::ClientApp::onUserSignaTureChanged(const std::string & userID, const std::string & signaTure)
{
}

void uit::ClientApp::onUserPhotoChanged(const std::string & userID, const std::string & photoBuffer)
{
}

void uit::ClientApp::onUserLoggingStateChanged(const std::string & userID, int terminalType, bool login, bool kickout)
{
}
