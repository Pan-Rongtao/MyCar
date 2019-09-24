#include "CarStub.h"
#include "DB.h"
#include "core/Log.h"
#include <Poco/Data/RecordSet.h>

using namespace uit;
using namespace Poco;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;

#define LOG_TAG	"server"

CarStub * CarStub::instance()
{
	static CarStub *p = nullptr;
	if (!p)	p = new CarStub();
	return p;
}

void CarStub::addRecord(const std::string userID)
{
	auto _id = userID;
	CarInfo info;
	DB::instance()->session() << "insert into cars values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", use(_id), use(info.availableFuel),
		use(info.averageFuel), use(info.totalKm), use(info.subKmA), use(info.subKmB), use(info.leftFrontDoor), use(info.rightFrontDoor), use(info.leftRearDoor), use(info.rightRearDoor), use(info.leftFrontWindow), use(info.rightFrontWindow),
		use(info.leftRearWindow), use(info.rightRearWindow), use(info.AC), use(info.ACTemp), use(info.shutdownPhoto), use(info.driving), now;
}

void CarStub::setAvailableFuel(const std::string & userID, float available)
{
	auto _id = userID;
	auto _fuel = available;
	DB::instance()->session() << "update cars set AvailableFuel=? where UserID=?", use(_fuel), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] setAvailableFuel[%.2f]", userID.data(), available);
}

void CarStub::setAverageFuel(const std::string & userID, float average)
{
	auto _id = userID;
	auto _fuel = average;
	DB::instance()->session() << "update cars set AverageFuel=? where UserID=?", use(_fuel), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] setAverageFuel[%.2f]", userID.data(), average);
}

void CarStub::setTotalKm(const std::string & userID, float totalKm)
{
	auto _id = userID;
	auto _km = totalKm;
	DB::instance()->session() << "update cars set TotalKm=? where UserID=?", use(_km), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] setTotalKm[%.2f]", userID.data(), _km);
}

void CarStub::setSubKmA(const std::string & userID, float subKmA)
{
	auto _id = userID;
	auto _km = subKmA;
	DB::instance()->session() << "update cars set SubKmA=? where UserID=?", use(_km), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] setSubKmA[%.2f]", userID.data(), _km);
}

void CarStub::setSubKmB(const std::string & userID, float subKmB)
{
	auto _id = userID;
	auto _km = subKmB;
	DB::instance()->session() << "update cars set SubKmB=? where UserID=?", use(_km), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] setSubKmB[%.2f]", userID.data(), _km);
}

void CarStub::switchLeftFrontDoor(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set LeftFrontDoor=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchLeftFrontDoor[%d]", userID.data(), _b);
}

void CarStub::switchRightFrontDoor(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set RightFrontDoor=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchRightFrontDoor[%d]", userID.data(), _b);
}

void CarStub::switchLeftRearDoor(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set LeftRearDoor=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchLeftRearDoor[%d]", userID.data(), _b);
}

void CarStub::switchRightRearDoor(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set RightRearDoor=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchRightRearDoor[%d]", userID.data(), _b);
}

void CarStub::switchLeftFrontWindow(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set LeftFrontWindow=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchLeftFrontWindow[%d]", userID.data(), _b);
}

void CarStub::switchRightFrontWindow(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set RightFrontWindow=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchRightFrontWindow[%d]", userID.data(), _b);
}

void CarStub::switchLeftRearWindow(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set LeftRearWindow=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchLeftRearWindow[%d]", userID.data(), _b);
}

void CarStub::switchRightRearWindow(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set RightRearWindow=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchRightRearWindow[%d]", userID.data(), _b);
}

void CarStub::switchAC(const std::string & userID, bool open)
{
	auto _id = userID;
	auto _b = open;
	DB::instance()->session() << "update cars set AC=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] switchAC[%d]", userID.data(), _b);
}

void CarStub::setACTemp(const std::string & userID, int temp)
{
	auto _id = userID;
	auto _b = temp;
	DB::instance()->session() << "update cars set ACTemp=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] adjustACTemp[%d]", userID.data(), _b);
}

bool CarStub::setShutdownPhoto(const std::string & userID, const std::string & photoBuffer)
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
		CarChanged.dispatch({ userID, info });
		Log::info(LOG_TAG, "user[%s] setShutdownPhoto[%d]", userID.data(), photoBuffer.size());
		return true;
	}
}

void CarStub::setDriving(const std::string & userID, bool driving)
{
	auto _id = userID;
	auto _b = driving;
	DB::instance()->session() << "update cars set Driving=? where UserID=?", use(_b), use(_id), now;
	CarInfo info;
	bool b = getCarInfo(userID, info);
	CarChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] setDriving[%d]", userID.data(), _b);
}

bool CarStub::getCarInfo(const std::string & userID, CarInfo &info)
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
		info.userID = rs[0].convert<std::string>();
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