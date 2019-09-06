#pragma once
#include <RCF/Idl.hpp>
#include <SF/vector.hpp>

RCF_BEGIN(AccountInterface, "AccountInterface")

RCF_METHOD_V3(void, regist, const std::string &, const std::string &, const std::string &);
RCF_METHOD_R1(bool, isUserIDExists, const std::string &);

RCF_END(AccountInterface)
