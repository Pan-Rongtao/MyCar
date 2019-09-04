#pragma once
#include "core/Def.h"
#include "RCF/RCF.hpp"
#include "car/RCFInterface.h"

namespace uit {

class UIT_API AccountClient final
{
public:
	//构建一个账号客户端
	AccountClient();

	//连接服务器
	bool connect(const std::string &ip, int port);

	//注册用户
	void regist(const std::string &id, const std::string &password, const std::string &nickname);

	//登录
	void login(const std::string &id, const std::string &password);

	//登出
	void logout();

private:
	std::shared_ptr<RcfClient<AccountInterface>>	m_client;
};

}