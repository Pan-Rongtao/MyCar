#pragma once
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/Util/Application.h>
#include "car/AccountClient.h"

namespace uit {

class ClientApp : public Poco::Util::Application
{
public:
	virtual int main(const std::vector<std::string>& args) override;
	virtual void initialize(Application& app) override;
	virtual void uninitialize() override;
	virtual void defineOptions(Poco::Util::OptionSet& options) override;

private:
	AccountClient	m_client;
};

}
