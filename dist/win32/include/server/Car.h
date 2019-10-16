#pragma once
#include <RCF/Idl.hpp>
#include "Types.h"

static void serialize(SF::Archive& ar, CarInfo &info)
{
	ar & info.userID & info.availableFuel & info.averageFuel & info.totalKm & info.subKmA & info.subKmB & info.leftFrontDoor & info.rightFrontDoor & info.leftRearDoor & info.rightRearDoor
	& info.leftFrontWindow & info.rightFrontWindow & info.leftRearWindow & info.rightRearWindow & info.AC & info.ACTemp & info.shutdownPhoto & info.driving;
}

RCF_BEGIN(CarInterface, "CarInterface")
RCF_METHOD_V2(void, setAvailableFuel, const std::string &, float);
RCF_METHOD_V2(void, setAverageFuel, const std::string &, float);
RCF_METHOD_V2(void, setTotalKm, const std::string &, float);
RCF_METHOD_V2(void, setSubKmA, const std::string &, float);
RCF_METHOD_V2(void, setSubKmB, const std::string &, float);
RCF_METHOD_V2(void, switchLeftFrontDoor, const std::string &, bool);
RCF_METHOD_V2(void, switchRightFrontDoor, const std::string &, bool);
RCF_METHOD_V2(void, switchLeftRearDoor, const std::string &, bool);
RCF_METHOD_V2(void, switchRightRearDoor, const std::string &, bool);
RCF_METHOD_V2(void, switchLeftFrontWindow, const std::string &, bool);
RCF_METHOD_V2(void, switchRightFrontWindow, const std::string &, bool);
RCF_METHOD_V2(void, switchLeftRearWindow, const std::string &, bool);
RCF_METHOD_V2(void, switchRightRearWindow, const std::string &, bool);
RCF_METHOD_V2(void, switchAC, const std::string &, bool);
RCF_METHOD_V2(void, setACTemp, const std::string &, int);
RCF_METHOD_R2(bool, setShutdownPhoto, const std::string &, const std::string &);
RCF_METHOD_V2(void, setDriving, const std::string &, bool);
RCF_METHOD_R1(CarInfo, getCarInfo, const std::string &);
RCF_END(CarInterface)

RCF_BEGIN(CarNotify, "CarNotify")
RCF_METHOD_V1(void, onCarChanged, const CarInfo &);
RCF_END(CarNotify)
