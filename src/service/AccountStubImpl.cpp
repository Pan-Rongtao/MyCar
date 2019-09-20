#include "AccountStubImpl.h"
#include "core/Log.h"
#include "Share.h"
#include "server/Account.h"
#include "server/ServerDomain.h"
#include "DB.h"

using namespace uit;
using namespace Poco;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;

AccountStubImpl::AccountStubImpl(ServerDomain * p)
	: m_serverDomain(p)
{
}

bool AccountStubImpl::regist(const std::string & userID, const std::string & password, const std::string & nickname)
{
	Poco::Tuple<std::string, std::string, std::string, std::string, std::string, DateTime, int, int, int, int> record{ userID, password, nickname, "该用户很懒，懒得签名.", "", DateTime(), 0, 0, 0, 0 };
	try {
		DB::instance()->session() << "insert into users values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", use(record), now;
		auto _id = userID;
		CarInfo info;
		DB::instance()->session() << "insert into cars values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", use(_id), use(info.availableFuel),
			use(info.averageFuel), use(info.totalKm), use(info.subKmA), use(info.subKmB), use(info.leftFrontDoor), use(info.rightFrontDoor), use(info.leftRearDoor), use(info.rightRearDoor), use(info.leftFrontWindow), use(info.rightFrontWindow),
			use(info.leftRearWindow), use(info.rightRearWindow), use(info.AC), use(info.ACTemp), use(info.shutdownPhoto), use(info.driving), now;
	}
	catch (Poco::Exception &e) {
		(void)e;
		Log::error(LOG_TAG, "regist userID[%s] is existed , password[%s], nickname[%s], ignore.", userID.data(), password.data(), nickname.data());
		Log::error(LOG_TAG, "%s", e.what());
		return false;
	}
	Log::info(LOG_TAG, "user[%s] regist, password[%s], nickname[%s]", userID.data(), password.data(), nickname.data());
	return true;
}

void AccountStubImpl::remove(const std::string & userID, const std::string &password)
{
	logout(userID, password, vehicle, true);
	logout(userID, password, pc, true);
	logout(userID, password, handheld, true);
	logout(userID, password, pad, true);
	auto _id = userID;
	DB::instance()->session() << "delete from users where UserID=?", use(_id), now;
	Log::info(LOG_TAG, "user[%s] remove", userID.data());
}

bool AccountStubImpl::isUserIDExists(const std::string & userID)
{
	std::vector<std::string> records;
	auto _id = userID;
	DB::instance()->session() << "select UserID from users where UserID=?", into(records), use(_id), now;
	bool bExists = !records.empty();
	return bExists;
}

bool AccountStubImpl::login(const std::string & userID, const std::string & password, int terminalType)
{
	std::vector<std::string> records;
	auto _id = userID;
	auto _pw = password;
	DB::instance()->session() << "select UserID from users where UserID=? and Password=?", into(records), use(_id), use(_pw), now;
	bool bExists = !records.empty();
	if (bExists)
	{
		std::string s = "update users set " + terminalTypeToOnlineString(terminalType) + "=1 where UserID = ? ";
		DB::instance()->session() << s, use(_id), now;
		Log::info(LOG_TAG, "user[%s] longin", userID.data());
		m_serverDomain->m_publisherAccount->publish().onUserLoggingStateChanged(userID, terminalType, true, false);
	}
	else
	{
		Log::info(LOG_TAG, "user[%s] longin fail for unmatched id & password", userID.data());
	}
	return bExists;
}

bool AccountStubImpl::logout(const std::string & userID, const std::string & password, int terminalType, bool kickout)
{
	std::vector<std::string> records;
	auto _id = userID;
	auto _pw = password;
	DB::instance()->session() << "select UserID from users where UserID=? and Password=?", into(records), use(_id), use(_pw), now;
	bool bExists = !records.empty();
	if (bExists)
	{
		std::string s = "update users set " + terminalTypeToOnlineString(terminalType) + "=0 where UserID = ? ";
		DB::instance()->session() << s, use(_id), now;
		Log::info(LOG_TAG, "user[%s] logout", userID.data());
		m_serverDomain->m_publisherAccount->publish().onUserLoggingStateChanged(userID, terminalType, false, kickout);
	}
	else
	{
		Log::info(LOG_TAG, "user[%s] logout fail for unmatched id & password", userID.data());
	}
	return bExists;
}

bool AccountStubImpl::getAccountInfo(const std::string & userID, std::string & password, std::string & nickname, std::string & signaTure,
	std::string & photo, std::string & registTime, bool & vehicleOnline, bool & pcOnline, bool & handeldOnline, bool & padOnline) const
{
	typedef Poco::Tuple<std::string, std::string, std::string, std::string, std::string, DateTime, int, int, int, int> Record;
	std::vector<Record> records;
	auto _id = userID;
	DB::instance()->session() << "select * from users where UserID=?", into(records), use(_id), now;
	if (records.empty())
	{
		return false;
	}
	else
	{
		password = records.front().get<1>();
		nickname = records.front().get<2>();
		signaTure = records.front().get<3>();
		photo = loadImage(records.front().get<4>());
		registTime = Poco::DateTimeFormatter::format(records.front().get<5>(), Poco::DateTimeFormat::SORTABLE_FORMAT);
		vehicleOnline = records.front().get<6>() == 0 ? false : true;
		pcOnline = records.front().get<7>() == 0 ? false : true;
		handeldOnline = records.front().get<8>() == 0 ? false : true;
		padOnline = records.front().get<9>() == 0 ? false : true;
		return true;
	}
}

void AccountStubImpl::setPassword(const std::string &userID, const std::string & password)
{
	auto _id = userID;
	auto _pw = password;
	DB::instance()->session() << "update users set Password=? where UserID=?", use(_pw), use(_id), now;
	m_serverDomain->m_publisherAccount->publish().onPasswordChanged(userID, password);
	m_serverDomain->m_publisherAccount->publish().onUserLoggingStateChanged(userID, vehicle, false, true);
	m_serverDomain->m_publisherAccount->publish().onUserLoggingStateChanged(userID, pc, false, true);
	m_serverDomain->m_publisherAccount->publish().onUserLoggingStateChanged(userID, handheld, false, true);
	m_serverDomain->m_publisherAccount->publish().onUserLoggingStateChanged(userID, pad, false, true);
	Log::info(LOG_TAG, "user[%s] setPassword[%s]", userID.data(), password.data());
}

std::string AccountStubImpl::getPassword(const std::string &userID) const
{
	std::vector<std::string> records;
	auto _id = userID;
	DB::instance()->session() << "select Password from users where UserID=?", into(records), use(_id), now;
	auto ret = records.empty() ? "" : records.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

void AccountStubImpl::setNickname(const std::string &userID, const std::string & nickname)
{
	auto _id = userID;
	auto _nn = nickname;
	DB::instance()->session() << "update users set NickName=? where UserID=?", use(_nn), use(_id), now;
	m_serverDomain->m_publisherAccount->publish().onUserNicknameChanged(userID, nickname);
	Log::info(LOG_TAG, "user[%s] setNickname[%s]", userID.data(), nickname.data());
}

std::string AccountStubImpl::getNickname(const std::string &userID) const
{
	auto _id = userID;
	std::vector<std::string> records;
	DB::instance()->session() << "select NickName from users where UserID=?", into(records), use(_id), now;
	auto ret = records.empty() ? "" : records.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

void AccountStubImpl::setSignaTure(const std::string & userID, const std::string & signaTure)
{
	auto _id = userID;
	auto _st = signaTure;
	DB::instance()->session() << "update users set SignaTure=? where UserID=?", use(_st), use(_id), now;
	m_serverDomain->m_publisherAccount->publish().onUserSignaTureChanged(userID, signaTure);
	Log::info(LOG_TAG, "user[%s] setSignaTure[%s]", userID.data(), signaTure.data());
}

std::string AccountStubImpl::getSignaTure(const std::string & userID)
{
	auto _id = userID;
	std::vector<std::string> records;
	DB::instance()->session() << "select SignaTure from users where UserID=?", into(records), use(_id), now;
	auto ret = records.empty() ? "" : records.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

bool AccountStubImpl::setPhoto(const std::string &userID, const std::string &photoBuffer)
{
	if (photoBuffer.size() > 256 * 1024)
	{
		Log::info(LOG_TAG, "user[%s] setPhoto[%d] fail, too big", userID.data(), photoBuffer.size());
		return false;
	}
	else
	{
		auto path = userID + ".pic";
		FILE *pf = fopen(path.data(), "wb");
		if (pf)
		{
			fwrite(photoBuffer.data(), 1, photoBuffer.size(), pf);
		}
		fclose(pf);
		auto _id = userID;
		DB::instance()->session() << "update users set Photo=? where UserID=?", use(path), use(_id), now;
		m_serverDomain->m_publisherAccount->publish().onUserPhotoChanged(userID, photoBuffer);
		Log::info(LOG_TAG, "user[%s] setPhoto[%d]", userID.data(), photoBuffer.size());
		return true;
	}
}

std::string AccountStubImpl::getPhoto(const std::string &userID) const
{
	auto _id = userID;
	std::vector<std::string> records;
	DB::instance()->session() << "select Photo from users where UserID=?", into(records), use(_id), now;
	auto path = records.empty() ? "" : records.front();
	Log::info(LOG_TAG, "user[%s] getPhoto[%d]", userID.data(), path.size());

	return loadImage(path);
}

std::string AccountStubImpl::terminalTypeToOnlineString(int terminalType) const
{
	switch (terminalType)
	{
	case vehicle:	return "VehicleOnline";
	case pc:		return "PCOnline";
	case handheld:	return "HandeldOnline";
	case pad:		return "PadOnline";
	default:		return "";
	}
}

std::string AccountStubImpl::loadImage(const std::string &path) const
{
	FILE *pFile = fopen(path.data(), "rb");
	if (pFile == nullptr)
		return std::string();

	fseek(pFile, 0, SEEK_END);
	int nLength = ftell(pFile);
	char *pData = new char[nLength];
	fseek(pFile, 0, SEEK_SET);
	fread(pData, nLength, 1, pFile);
	std::string ret(pData, nLength);
	delete[]pData;
	fclose(pFile);
	return ret;
}