#pragma once
#include <Poco/Util/ServerApplication.h>
#include "car/ServerDomain.h"

class CarServiceApp : public Poco::Util::ServerApplication
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

POCO_SERVER_MAIN(CarServiceApp)