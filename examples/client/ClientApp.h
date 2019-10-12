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

	void onAccountChanged(const std::string &userID, const AccountInfo &info);
	void onP2PMessageArrived(const std::string &fromID, const P2PMessage &msg);
	void onGroupMessageArrived(const std::string &groupID, const GroupMessage &msg);

private:
	std::string getLocalIp() const;

	std::shared_ptr<RcfClient<AccountInterface>>	m_client;
};

}
