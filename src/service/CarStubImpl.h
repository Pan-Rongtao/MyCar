#pragma once
#include <string>
#include "server/Car.h"

namespace uit {

class ServerDomain;
class CarStubImpl
{
public:
	CarStubImpl(ServerDomain *p);

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

	//获取行车信息
	bool getCarInfo(const std::string &userID, CarInfo &info);

private:
	ServerDomain	*m_serverDomain;
};

}