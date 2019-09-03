#include "CarServiceApp.h"
#include "core/Log.h"

int CarServiceApp::main(const std::vector<std::string>& args)
{
	waitForTerminationRequest();
	return ServerApplication::EXIT_OK;
}

void CarServiceApp::initialize(Application & app)
{
	ServerApplication::initialize(app);
}

void CarServiceApp::uninitialize()
{
	ServerApplication::uninitialize();
	uit::Log::info("SVCar", "car service shutdown.");
}

void CarServiceApp::defineOptions(Poco::Util::OptionSet & options)
{
}
