#pragma once
#include <RCF/Idl.hpp>

RCF_BEGIN(CarInterface, "CarInterface")

RCF_METHOD_V2(void, setAvailableFuel, const std::string &, float);


RCF_END(CarInterface)