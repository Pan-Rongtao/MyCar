#include "car/AccountClient.h"

using namespace uit;

AccountClient::AccountClient()
{
	RCF::init();
}

bool AccountClient::connect(const std::string & ip, int port)
{
	m_client = std::make_shared<RcfClient<AccountInterface>>(RCF::TcpEndpoint(ip, port));
	return true;
}

void AccountClient::regist(const std::string & id, const std::string & password, const std::string & nickname)
{
	m_client->regist(id, password, nickname);
}

void AccountClient::login(const std::string & id, const std::string & password)
{
	
}

void AccountClient::logout()
{
}
