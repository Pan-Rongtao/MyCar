#pragma once
#include <RCF/Idl.hpp>

struct CarInfo
{
	std::string userID;
	float availableFuel{100};
	float averageFuel{ 0.0 };
	float totalKm{ 0.0 };
	float subKmA{ 0.0 };
	float subKmB{ 0.0 };
	bool leftFrontDoor{false};
	bool rightFrontDoor{ false };
	bool leftRearDoor{ false };
	bool rightRearDoor{ false };
	bool leftFrontWindow{ false };
	bool rightFrontWindow{ false };
	bool leftRearWindow{ false };
	bool rightRearWindow{ false };
	bool AC{ false };
	int ACTemp{20};
	std::string shutdownPhoto;
	bool driving{ false };

	void CarInfo::serialize(SF::Archive& ar)
	{
		ar & availableFuel;
		ar & averageFuel;
		ar & totalKm;
		ar & subKmA;
		ar & subKmB;
		ar & leftFrontDoor;
		ar & rightFrontDoor;
		ar & leftRearDoor;
		ar & rightRearDoor;
		ar & leftFrontWindow;
		ar & rightFrontWindow;
		ar & leftRearWindow;
		ar & rightRearWindow;
		ar & AC;
		ar & ACTemp;
		ar & shutdownPhoto;
		ar & driving;
	}
};

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
RCF_METHOD_R2(bool, getCarInfo, const std::string &, CarInfo &);

RCF_END(CarInterface)

RCF_BEGIN(CarNotify, "CarNotify")

RCF_METHOD_V2(void, onCarChanged, const std::string &, const CarInfo &);

RCF_END(CarNotify)
