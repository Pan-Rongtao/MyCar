#pragma once
#include <Poco/Util/ServerApplication.h>
#include <iostream>
#include "server/ServerDomain.h"

class Service : public Poco::Util::ServerApplication
{
public:
	virtual int main(const std::vector<std::string>& args) override;
	virtual void initialize(Application& app) override;
	virtual void uninitialize() override;
	virtual void defineOptions(Poco::Util::OptionSet& options) override;

private:
	std::string getLocalIp() const;
	std::shared_ptr<uit::ServerDomain>	m_server;
};

//POCO_SERVER_MAIN(Service)