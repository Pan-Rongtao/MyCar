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
	virtual void defineOptions(Poco::Util::OptionSet& options) override;

	void onPasswordChanged(const std::string &userID, const std::string &password);
	void onUserNicknameChanged(const std::string &userID, const std::string &nickname);
	void onUserSignaTureChanged(const std::string &userID, const std::string &signaTure);
	void onUserPhotoChanged(const std::string &userID, const std::string &photoBuffer);
	void onUserLoggingStateChanged(const std::string &userID, int terminalType, bool login, bool kickout);

private:

	std::shared_ptr<RcfClient<AccountInterface>>	m_client;
};

}
