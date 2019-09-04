#pragma once
#include "core/Def.h"
#include "RCF/RCF.hpp"
#include "car/RCFInterface.h"

namespace uit {

class UIT_API AccountClient final
{
public:
	//����һ���˺ſͻ���
	AccountClient();

	//���ӷ�����
	bool connect(const std::string &ip, int port);

	//ע���û�
	void regist(const std::string &id, const std::string &password, const std::string &nickname);

	//��¼
	void login(const std::string &id, const std::string &password);

	//�ǳ�
	void logout();

private:
	std::shared_ptr<RcfClient<AccountInterface>>	m_client;
};

}