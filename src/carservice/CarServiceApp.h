#pragma once
#include <Poco/Util/ServerApplication.h>


class CarServiceApp : public Poco::Util::ServerApplication
{
public:
	virtual int main(const std::vector<std::string>& args) override;
	virtual void initialize(Application& app) override;
	virtual void uninitialize() override;
	virtual void defineOptions(Poco::Util::OptionSet& options) override;

private:

};

POCO_SERVER_MAIN(CarServiceApp)