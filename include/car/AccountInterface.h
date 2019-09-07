#pragma once
#include <RCF/Idl.hpp>
#include <SF/vector.hpp>

enum TerminalType
{
	vehicle,
	pc,
	handheld,
	pad,
};

RCF_BEGIN(AccountInterface, "AccountInterface")

RCF_METHOD_V3(void, regist, const std::string &, const std::string &, const std::string &);
RCF_METHOD_V1(void, remove, const std::string &);
RCF_METHOD_R1(bool, isUserIDExists, const std::string &);
RCF_METHOD_V3(void, login, const std::string &, const std::string &, int);
RCF_METHOD_V3(void, logout, const std::string &, const std::string &, int);
RCF_METHOD_R10(bool, getAccountInfo, const std::string &, std::string &, std::string &, std::string &,
	std::string &, std::string &, bool &, bool &, bool &, bool &);
RCF_METHOD_V2(void, setPassword, const std::string &, const std::string &);
RCF_METHOD_V2(void, setNickname, const std::string &, const std::string &);
RCF_METHOD_V2(void, setSignaTure, const std::string &, const std::string &);
RCF_METHOD_V2(void, setPhoto, const std::string &, const std::string &);

RCF_END(AccountInterface)
