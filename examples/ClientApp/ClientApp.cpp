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
	m_client = std::make_shared<RcfClient<AccountInterface>>(RCF::TcpEndpoint("10.219.125.39", 8888));
	m_client->getClientStub().ping();
	uit::Log::info(LOG_TAG, "connected, cost [%d].\n", (int)(uit::getTickCount() - k));
	m_client->regist("13112657701", "Aa123456", "Pan.T");
	bool b = m_client->getClientStub().isConnected();
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
