#pragma once
#include <Poco/Util/ServerApplication.h>
#include <RCF/RCF.hpp>
#include <iostream>
#include "AccountStub.h"
#include "CarStub.h"
#include "DB.h"
#include "server/Account.h"
#include "server/Car.h"

namespace uit{

class Service : public Poco::Util::ServerApplication
{
public:
	virtual int main(const std::vector<std::string>& args) override;
	virtual void initialize(Application& app) override;
	virtual void uninitialize() override;

private:
	std::string getLocalIp() const;

	std::shared_ptr<RCF::RcfServer>		m_interfaceServer;
	std::shared_ptr<RCF::RcfServer>		m_publisherServer;
	std::shared_ptr<RCF::Publisher<AccountNotify>>	m_publisherAccount;
	std::shared_ptr<RCF::Publisher<CarNotify>>		m_publisherCar;

};

}
//POCO_SERVER_MAIN(Service)
