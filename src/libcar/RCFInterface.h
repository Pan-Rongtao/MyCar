#pragma once
#include <RCF/Idl.hpp>

RCF_BEGIN(AccountInterface, "AccountInterface")

RCF_METHOD_V1(void, registerAccount, const std::string &, const std::string &, const std::string &);

RCF_END()
