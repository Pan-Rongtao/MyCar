#pragma once
#include <RCF/Idl.hpp>

struct AccountInfo
{
	std::string userID;
	std::string password;
	std::string	nickname;
	std::string	signaTure;
	std::string	photo;
	std::string	registTime;
	bool		vehicleOnline;
	bool		pcOnline;
	bool		handeldOnline;
	bool		padOnline;

	void serialize(SF::Archive& ar)
	{
		ar & userID; ar & password; ar & nickname; ar & signaTure; ar & photo; ar & registTime; ar & vehicleOnline; ar & pcOnline; ar & handeldOnline; ar & padOnline;
	}
};

RCF_BEGIN(AccountInterface, "AccountInterface")
RCF_METHOD_R3(bool, regist, const std::string &, const std::string &, const std::string &);
RCF_METHOD_R1(bool, isRegisted, const std::string &);
RCF_METHOD_V2(void, setPassword, const std::string &, const std::string &);
RCF_METHOD_V2(void, setNickname, const std::string &, const std::string &);
RCF_METHOD_V2(void, setSignaTure, const std::string &, const std::string &);
RCF_METHOD_R2(bool, setPhoto, const std::string &, const std::string &);
RCF_METHOD_R3(bool, setVehicleOnline, const std::string &, const std::string &, bool);
RCF_METHOD_R3(bool, setPCOnline, const std::string &, const std::string &, bool);
RCF_METHOD_R3(bool, setHandeldOnline, const std::string &, const std::string &, bool);
RCF_METHOD_R3(bool, setPadOnline, const std::string &, const std::string &, bool);
RCF_METHOD_R2(bool, getAccountInfo, const std::string &, AccountInfo &);
RCF_END(AccountInterface)

RCF_BEGIN(AccountNotify, "AccountNotify")
RCF_METHOD_V2(void, onAccountChanged, const std::string &, const AccountInfo &);
RCF_END(AccountNotify)

