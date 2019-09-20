#pragma once
#include <RCF/Idl.hpp>

enum TerminalType
{
	vehicle,
	pc,
	handheld,
	pad,
};

RCF_BEGIN(AccountInterface, "AccountInterface")

RCF_METHOD_R3(bool, regist, const std::string &, const std::string &, const std::string &);
RCF_METHOD_V2(void, remove, const std::string &, const std::string &);
RCF_METHOD_R1(bool, isUserIDExists, const std::string &);
RCF_METHOD_R3(bool, login, const std::string &, const std::string &, int);
RCF_METHOD_R4(bool, logout, const std::string &, const std::string &, int, bool);
RCF_METHOD_R10(bool, getAccountInfo, const std::string &, std::string &, std::string &, std::string &, std::string &, std::string &, bool &, bool &, bool &, bool &);
RCF_METHOD_V2(void, setPassword, const std::string &, const std::string &);
RCF_METHOD_V2(void, setNickname, const std::string &, const std::string &);
RCF_METHOD_V2(void, setSignaTure, const std::string &, const std::string &);
RCF_METHOD_R2(bool, setPhoto, const std::string &, const std::string &);

RCF_END(AccountInterface)

RCF_BEGIN(AccountNotify, "AccountNotify")

RCF_METHOD_V2(void, onPasswordChanged, const std::string &, const std::string &);
RCF_METHOD_V2(void, onUserNicknameChanged, const std::string &, const std::string &);
RCF_METHOD_V2(void, onUserSignaTureChanged, const std::string &, const std::string &);
RCF_METHOD_V2(void, onUserPhotoChanged, const std::string &, const std::string &);
RCF_METHOD_V4(void, onUserLoggingStateChanged, const std::string &, int, bool, bool);

RCF_END(AccountNotify)
