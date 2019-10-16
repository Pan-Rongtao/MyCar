#pragma once
#include <string>
#include "core/Event.h"
#include "server/Car.h"

namespace uit {

class CarStub
{
public:
	static CarStub *get();

	void addRecord(const std::string userID);
	//
	void setAvailableFuel(const std::string &userID, float available);
	void setAverageFuel(const std::string &userID, float average);
	void setTotalKm(const std::string &userID, float totalKm);
	void setSubKmA(const std::string &userID, float subKmA);
	void setSubKmB(const std::string &userID, float subKmB);
	void switchLeftFrontDoor(const std::string &userID, bool open);
	void switchRightFrontDoor(const std::string &userID, bool open);
	void switchLeftRearDoor(const std::string &userID, bool open);
	void switchRightRearDoor(const std::string &userID, bool open);
	void switchLeftFrontWindow(const std::string &userID, bool open);
	void switchRightFrontWindow(const std::string &userID, bool open);
	void switchLeftRearWindow(const std::string &userID, bool open);
	void switchRightRearWindow(const std::string &userID, bool open);
	void switchAC(const std::string &userID, bool open);
	void setACTemp(const std::string &userID, int temp);
	bool setShutdownPhoto(const std::string &userID, const std::string &photoBuffer);
	void setDriving(const std::string &userID, bool driving);

	CarInfo getCarInfo(const std::string &userID);

	struct CarChangedArgs { CarInfo info; };
	uit::Event<CarChangedArgs>	CarChanged;

};

}