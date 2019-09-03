#pragma once
#include "core/Event.h"
#include <RCF/RCF.hpp>

namespace uit {

class AccountServerImpl;
class UIT_API ServerDomain final
{
public:
	ServerDomain();
	~ServerDomain() = default;
	ServerDomain(const ServerDomain &other) = delete;
	void operator =(const ServerDomain &other) = delete;

	//�������ݿ�·��
	bool configDBPath(const std::string &path);
	std::string getDBPath() const;

	//����
	bool startup();
	bool stop();

	struct ClientLoginEventArgs { std::string id; };
	uit::Event<ClientLoginEventArgs>		ClientLoginEvent;

private:
	bool initServerStub();

	bool								m_running;
	RCF::RcfServer						m_server;
	std::shared_ptr<AccountServerImpl>	m_accountStub;
};


}