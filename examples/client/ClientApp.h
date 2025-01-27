#pragma once
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/Util/Application.h>
#include <RCF/RCF.hpp>
#include "server/Account.h"

namespace uit {

class ClientApp : public Poco::Util::Application
{
public:
	virtual int main(const std::vector<std::string>& args) override;
	virtual void initialize(Application& app) override;
	virtual void uninitialize() override;

	void onAccountChanged(const UserInfo &info) {}
	void onMessageArrived(const ChatMessage &msg) {}
	void onShutdownPC(const std::string &userID) {}

private:
	std::string getLocalIp() const;

	std::shared_ptr<RcfClient<AccountInterface>>	m_client;
};

}
