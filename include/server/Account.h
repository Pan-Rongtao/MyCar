#pragma once
#include <RCF/Idl.hpp>
#include <SF/vector.hpp>

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

struct P2PMessage
{
	std::string fromID;
	std::string toID;
	std::string	msg;
	std::string	time;
	void serialize(SF::Archive& ar)
	{
		ar & fromID; ar & toID; ar & msg; ar & time;
	}
};

struct GroupInfo 
{
	std::string ID;
	std::string	name;
	std::string photo;
	std::string info;
	void serialize(SF::Archive& ar)
	{
		ar & ID; ar & name; ar & photo; ar & info;
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
RCF_METHOD_R1(bool, queryAllAccountInfo, std::vector<AccountInfo> &);

RCF_METHOD_R2(bool, addContacts, const std::string &, const std::string &);
RCF_METHOD_R2(bool, removeContacts, const std::string &, const std::string &);
RCF_METHOD_R2(bool, getContacts, const std::string &, std::vector<std::string> &);

RCF_METHOD_V3(void, addP2PMessage, const std::string &, const std::string &, const std::string &);
RCF_METHOD_V3(void, getP2PMessage, const std::string &, const std::string &, std::vector<P2PMessage> &);

RCF_METHOD_V2(void, addGroup, const std::string &, const std::string &);
RCF_METHOD_V1(void, removeGroup, const std::string &);
RCF_METHOD_V2(void, getGroup, const std::string &, GroupInfo &);
RCF_METHOD_V2(void, setGroupName, const std::string &, const std::string &);
RCF_METHOD_V2(void, setGroupInfo, const std::string &, const std::string &);
RCF_METHOD_V2(void, addGroupMember, const std::string &, const std::string &);
RCF_METHOD_V2(void, removeGroupMember, const std::string &, const std::string &);


RCF_END(AccountInterface)

RCF_BEGIN(AccountNotify, "AccountNotify")
RCF_METHOD_V2(void, onAccountChanged, const std::string &, const AccountInfo &);
RCF_METHOD_V2(void, onP2PMessageArrived, const std::string &, const P2PMessage &);
RCF_END(AccountNotify)

