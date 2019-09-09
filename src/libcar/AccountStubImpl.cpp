#include "AccountStubImpl.h"
#include "Poco/File.h"
#include "core/Log.h"
#include "Share.h"
#include "car/Account.h"
#include "car/ServerDomain.h"

using namespace uit;
using namespace Poco;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;

AccountStubImpl::AccountStubImpl(ServerDomain * p)
	: m_serverDomain(p)
{
}

bool AccountStubImpl::load(const std::string & path)
{
	Poco::Data::SQLite::Connector::registerConnector();
	Poco::File f(path);
	if (!f.exists())
	{
		return false;
	}
	else
	{
		m_session = new Poco::Data::Session("SQLite", path, 0);
		m_DBpath = path;
		return true;
	}
}

std::string AccountStubImpl::getDBPath() const
{
	return m_DBpath;
}

void AccountStubImpl::regist(const std::string & userID, const std::string & password, const std::string & nickname)
{
	Poco::Tuple<std::string, std::string, std::string, std::string, std::string, DateTime, int, int, int, int> record{ userID, password, nickname, "", "", DateTime(), 0, 0, 0, 0 };
	*m_session << "insert into users values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", use(record), now;
	Log::info(LOG_TAG, "user[%s] regist, password[%s], nickname[%s]", userID.data(), password.data(), nickname.data());
}

void AccountStubImpl::remove(const std::string & userID)
{
	auto _id = userID;
	*m_session << "delete from users where UserID=?", use(_id), now;
	Log::info(LOG_TAG, "user[%s] remove", userID.data());
}

bool AccountStubImpl::isUserIDExists(const std::string & userID)
{
	std::vector<std::string> records;
	auto _id = userID;
	*m_session << "select UserID from users where UserID=?", into(records), use(_id), now;
	bool bExists = !records.empty();
	return bExists;
}

bool AccountStubImpl::login(const std::string & userID, const std::string & password, int terminalType)
{
	std::vector<std::string> records;
	auto _id = userID;
	auto _pw = password;
	*m_session << "select UserID from users where UserID=? and Password=?", into(records), use(_id), use(_pw), now;
	bool bExists = !records.empty();
	if (bExists)
	{
		std::string s = "update users set " + terminalTypeToOnlineString(terminalType) + "=1 where UserID = ? ";
		*m_session << s, use(_id), now;
		Log::info(LOG_TAG, "user[%s] longin", userID.data());
	}
	else
	{
		Log::info(LOG_TAG, "user[%s] longin fail for unmatched id & password", userID.data());
	}
	return bExists;
}

bool AccountStubImpl::logout(const std::string & userID, const std::string & password, int terminalType)
{
	std::vector<std::string> records;
	auto _id = userID;
	auto _pw = password;
	*m_session << "select UserID from users where UserID=? and Password=?", into(records), use(_id), use(_pw), now;
	bool bExists = !records.empty();
	if (bExists)
	{
		std::string s = "update users set " + terminalTypeToOnlineString(terminalType) + "=1 where UserID = ? ";
		*m_session << s, use(_id), now;
		Log::info(LOG_TAG, "user[%s] logout", userID.data());
	}
	else
	{
		Log::info(LOG_TAG, "user[%s] logout fail for unmatched id & password", userID.data());
	}
	m_serverDomain->m_publisher->publish().onUserLogout(userID, terminalType);
	return bExists;
}

bool AccountStubImpl::getAccountInfo(const std::string & userID, std::string & password, std::string & nickname, std::string & signaTure,
	std::string & Photo, std::string & registTime, bool & vehicleOnline, bool & pcOnline, bool & handeldOnline, bool & padOnline) const
{
	typedef Poco::Tuple<std::string, std::string, std::string, std::string, std::string, DateTime, int, int, int, int> Record;
	std::vector<Record> records;
	auto ss = *m_session;
	auto _id = userID;
	ss << "select * from users where UserID=?", into(records), use(_id), now;
	if (records.empty())
	{
		return false;
	}
	else
	{
		password = records.front().get<1>();
		nickname = records.front().get<2>();
		signaTure = records.front().get<3>();
		Photo = records.front().get<4>();
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
	*m_session << "update users set Password=? where UserID=?", use(_pw), use(_id), now;
	Log::info(LOG_TAG, "user[%s] setPassword[%s]", userID.data(), password.data());
}

std::string AccountStubImpl::getPassword(const std::string &userID) const
{
	std::vector<std::string> records;
	auto _id = userID;
	auto ss = *m_session;
	ss << "select Password from users where UserID=?", into(records), use(_id), now;
	auto ret = records.empty() ? "" : records.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

void AccountStubImpl::setNickname(const std::string &userID, const std::string & nickname)
{
	auto _id = userID;
	auto _nn = nickname;
	*m_session << "update users set NickName=? where UserID=?", use(_nn), use(_id), now;
	Log::info(LOG_TAG, "user[%s] setNickname[%s]", userID.data(), nickname.data());
	m_serverDomain->m_publisher->publish().onUserNicknameChanged(userID, nickname);
}

std::string AccountStubImpl::getNickname(const std::string &userID) const
{
	auto _id = userID;
	std::vector<std::string> records;
	auto ss = *m_session;
	ss << "select NickName from users where UserID=?", into(records), use(_id), now;
	auto ret = records.empty() ? "" : records.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

void AccountStubImpl::setSignaTure(const std::string & userID, const std::string & signaTure)
{
	auto _id = userID;
	auto _st = signaTure;
	*m_session << "update users set SignaTure=? where UserID=?", use(_st), use(_id), now;
	Log::info(LOG_TAG, "user[%s] setSignaTure[%s]", userID.data(), signaTure.data());
	m_serverDomain->m_publisher->publish().onUserSignaTureChanged(userID, signaTure);
}

std::string AccountStubImpl::getSignaTure(const std::string & userID)
{
	auto _id = userID;
	std::vector<std::string> records;
	auto ss = *m_session;
	ss << "select SignaTure from users where UserID=?", into(records), use(_id), now;
	auto ret = records.empty() ? "" : records.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

void AccountStubImpl::setPhoto(const std::string &userID, const std::string &photoBuffer)
{
	auto _id = userID;
	auto _ft = photoBuffer;
	*m_session << "update users set Photo=? where UserID=?", use(_ft), use(_id), now;
	Log::info(LOG_TAG, "user[%s] setPhoto[%d]", userID.data(), photoBuffer.size());
	m_serverDomain->m_publisher->publish().onUserPhotoChanged(userID, photoBuffer);
}

std::string AccountStubImpl::getPhoto(const std::string &userID) const
{
	auto _id = userID;
	std::vector<std::string> records;
	auto ss = *m_session;
	ss << "select Photo from users where UserID=?", into(records), use(_id), now;
	auto ret = records.empty() ? "" : records.front();
	Log::info(LOG_TAG, "user[%s] getPhoto[%d]", userID.data(), ret.size());
	return ret;
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
