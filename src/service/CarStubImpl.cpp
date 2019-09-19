#include "CarStubImpl.h"
#include "DB.h"
#include "server/ServerDomain.h"
#include "core/Log.h"
#include "Share.h"
#include <Poco/Data/RecordSet.h>

using namespace uit;
using namespace Poco;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;

CarStubImpl::CarStubImpl(ServerDomain * p)
	: m_serverDomain(p)
{
}

void CarStubImpl::addRecord(const std::string userID)
{
	auto _id = userID;
	DB::instance()->session() << "insert into users values(?, 0.0, 0.0, 0.0, 0.0, 0.0, false, false, false, false, false, false, false, false, false, 20, "", false)", use(_id), now;
}

void CarStubImpl::setAvailableFuel(const std::string & userID, float available)
{
	auto _id = userID;
	auto _fuel = available;
	DB::instance()->session() << "update cars set AvailableFuel=? where UserID=?", use(_fuel), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] setAvailableFuel[%.2f]", userID.data(), available);
}

void CarStubImpl::setAverageFuel(const std::string & userID, float average)
{
	auto _id = userID;
	auto _fuel = average;
	DB::instance()->session() << "update cars set AverageFuel=? where UserID=?", use(_fuel), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] setAverageFuel[%.2f]", userID.data(), average);
}

void CarStubImpl::setTotalKm(const std::string & userID, float totalKm)
{
	auto _id = userID;
	auto _km = totalKm;
	DB::instance()->session() << "update cars set TotalKm=? where UserID=?", use(_km), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] setTotalKm[%.2f]", userID.data(), _km);
}

void CarStubImpl::setSubKmA(const std::string & userID, float subKmA)
{
	auto _id = userID;
	auto _km = subKmA;
	DB::instance()->session() << "update cars set SubKmA=? where UserID=?", use(_km), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] setSubKmA[%.2f]", userID.data(), _km);
}

void CarStubImpl::setSubKmB(const std::string & userID, float subKmB)
{
	auto _id = userID;
	auto _km = subKmB;
	DB::instance()->session() << "update cars set SubKmB=? where UserID=?", use(_km), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] setSubKmB[%.2f]", userID.data(), _km);
}

void CarStubImpl::switchLeftFrontDoor(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set LeftFrontDoor=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchLeftFrontDoor[%d]", userID.data(), _b);
}

void CarStubImpl::switchRightFrontDoor(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set RightFrontDoor=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchRightFrontDoor[%d]", userID.data(), _b);
}

void CarStubImpl::switchLeftRearDoor(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set LeftRearDoor=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchLeftRearDoor[%d]", userID.data(), _b);
}

void CarStubImpl::switchRightRearDoor(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set RightRearDoor=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchRightRearDoor[%d]", userID.data(), _b);
}

void CarStubImpl::switchLeftFrontWindow(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set LeftFrontWindow=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchLeftFrontWindow[%d]", userID.data(), _b);
}

void CarStubImpl::switchRightFrontWindow(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set RightFrontWindow=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchRightFrontWindow[%d]", userID.data(), _b);
}

void CarStubImpl::switchLeftRearWindow(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set LeftRearWindow=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchLeftRearWindow[%d]", userID.data(), _b);
}

void CarStubImpl::switchRightRearWindow(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set RightRearWindow=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchRightRearWindow[%d]", userID.data(), _b);
}

void CarStubImpl::switchAC(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set AC=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] switchAC[%d]", userID.data(), _b);
}

void CarStubImpl::setACTemp(const std::string & userID, int temp)
{
	auto _id = userID;
	auto _b = temp;
	DB::instance()->session() << "update cars set ACTemp=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] adjustACTemp[%d]", userID.data(), _b);
}

bool CarStubImpl::setShutdownPhoto(const std::string & userID, const std::string & photoBuffer)
{
	if (photoBuffer.size() > 3 * 1024 * 1024)
	{
		Log::info(LOG_TAG, "user[%s] setShutdownPhoto[%d] fail, too big", userID.data(), photoBuffer.size());
		return false;
	}
	else
	{
		auto path = userID + ".shutdowm";
		FILE *pf = fopen(path.data(), "wb");
		if (pf)
		{
			fwrite(photoBuffer.data(), 1, photoBuffer.size(), pf);
		}
		fclose(pf);
		auto _id = userID;
		DB::instance()->session() << "update users set Photo=? where UserID=?", use(path), use(_id), now;
		CarInfo info;
		bool b = getCarInfo(userID, info);
		m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
		Log::info(LOG_TAG, "user[%s] setShutdownPhoto[%d]", userID.data(), photoBuffer.size());
		return true;
	}
}

void CarStubImpl::setDriving(const std::string & userID, bool driving)
{
	auto _id = userID;
	auto _b = driving;
	DB::instance()->session() << "update cars set Driving=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	m_serverDomain->m_publisherCar->publish().onCarChanged(userID, info);
	Log::info(LOG_TAG, "user[%s] setDriving[%d]", userID.data(), _b);
}

bool CarStubImpl::getCarInfo(const std::string & userID, CarInfo &info)
{
	Statement select(DB::instance()->session());
	auto _id = userID;
	select << "select * from cars where UserID=?", use(_id);
	select.execute();
	RecordSet rs(select);
	if (rs.rowCount() == 0)
	{
		return false;
	}
	else 
	{
		info.availableFuel = rs[1].convert<float>();
		info.averageFuel = rs[2].convert<float>();
		info.totalKm = rs[3].convert<float>();
		info.subKmA = rs[4].convert<float>();
		info.subKmB = rs[5].convert<float>();
		info.leftFrontDoor = rs[6].convert<bool>();
		info.rightFrontDoor = rs[7].convert<bool>();
		info.leftRearDoor = rs[8].convert<bool>();
		info.rightRearDoor = rs[9].convert<bool>();
		info.leftFrontWindow = rs[10].convert<bool>();
		info.rightFrontWindow = rs[11].convert<bool>();
		info.leftRearWindow = rs[12].convert<bool>();
		info.rightRearWindow = rs[13].convert<bool>();
		info.AC = rs[14].convert<bool>();
		info.ACTemp = rs[15].convert<int>();
		info.shutdownPhoto = rs[16].convert<std::string>();
		info.driving = rs[17].convert<bool>();
		return true;
	}
}
