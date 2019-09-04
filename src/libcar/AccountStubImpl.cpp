#include "AccountStubImpl.h"
#include "Poco/File.h"
#include "core/Log.h"
#include "Share.h"

using namespace uit;
using namespace Poco;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;

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
	Poco::Tuple<std::string, std::string, std::string, std::string, std::string, int, DateTime> record{ userID, password, nickname, "", "", 0, DateTime() };
	*m_session << "insert into users values(?, ?, ?, ?, ?, ?, ?)", use(record), now;
	Log::info(LOG_TAG, "user[%s] regist, password[%s], nickname[%s]", userID.data(), password.data(), nickname.data());
}

void AccountStubImpl::remove(const std::string & userID)
{
	auto _id = userID;
	*m_session << "delete from users where UserID=?", use(_id), now;
	Log::info(LOG_TAG, "user[%s] remove", userID.data());
}

bool AccountStubImpl::login(const std::string & userID, const std::string & password)
{
	std::vector<std::string> recoreds;
	auto _id = userID;
	auto _pw = password;
	*m_session << "select UserID from users where UserID=? and Password=?", into(recoreds), use(_id), use(_pw), now;
	bool bExists = recoreds.empty();
	if (bExists)
	{
		*m_session << "update users set Online=1 where UserID=?", use(_id), now;
		Log::info(LOG_TAG, "user[%s] longin", userID.data());
	}
	else
	{
		Log::info(LOG_TAG, "user[%s] longin fail for unmatched id & password", userID.data());
	}
	return bExists;
}

bool AccountStubImpl::logout(const std::string & userID, const std::string & password)
{
	std::vector<std::string> recoreds;
	auto _id = userID;
	auto _pw = password;
	*m_session << "select UserID from users where UserID=? and Password=?", into(recoreds), use(_id), use(_pw), now;
	bool bExists = recoreds.empty();
	if (bExists)
	{
		*m_session << "update users set Online=1 where UserID=?", use(_id), now;
		Log::info(LOG_TAG, "user[%s] logout", userID.data());
	}
	else
	{
		Log::info(LOG_TAG, "user[%s] logout fail for unmatched id & password", userID.data());
	}
	return bExists;
}

bool AccountStubImpl::isOnline(const std::string & userID) const
{
	std::vector<int> recoreds;
	auto _id = userID;
	auto ss = *m_session;
	ss << "select Online from users where UserID=?", into(recoreds), use(_id), now;
	return recoreds.empty() ? false : recoreds.front();
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
	std::vector<std::string> recoreds;
	auto _id = userID;
	auto ss = *m_session;
	ss << "select Password from users where UserID=?", into(recoreds), use(_id), now;
	auto ret = recoreds.empty() ? "" : recoreds.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

void AccountStubImpl::setNickname(const std::string &userID, const std::string & nickname)
{
	auto _id = userID;
	auto _nn = nickname;
	*m_session << "update users set NickName=? where UserID=?", use(_nn), use(_id), now;
	Log::info(LOG_TAG, "user[%s] setNickname[%s]", userID.data(), nickname.data());
}

std::string AccountStubImpl::getNickname(const std::string &userID) const
{
	auto _id = userID;
	std::vector<std::string> recoreds;
	auto ss = *m_session;
	ss << "select NickName from users where UserID=?", into(recoreds), use(_id), now;
	auto ret = recoreds.empty() ? "" : recoreds.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

void AccountStubImpl::setSignaTure(const std::string & userID, const std::string & signaTure)
{
	auto _id = userID;
	auto _st = signaTure;
	*m_session << "update users set SignaTure=? where UserID=?", use(_st), use(_id), now;
	Log::info(LOG_TAG, "user[%s] setSignaTure[%s]", userID.data(), signaTure.data());
}

std::string AccountStubImpl::getSignaTure(const std::string & userID)
{
	auto _id = userID;
	std::vector<std::string> recoreds;
	auto ss = *m_session;
	ss << "select SignaTure from users where UserID=?", into(recoreds), use(_id), now;
	auto ret = recoreds.empty() ? "" : recoreds.front();
	Log::info(LOG_TAG, "user[%s] getPassword[%s]", userID.data(), ret.data());
	return ret;
}

void AccountStubImpl::setPhoto(const std::string &userID, const Poco::Buffer<char>& photo)
{
	auto path = "photo/" + userID;
	FILE *pFile = fopen(path.data(), "rw");
	if (pFile == nullptr)
	{
		Log::error(LOG_TAG, "can't create photo.");
	}
	else
	{
		fwrite(photo.begin(), 1, photo.size(), pFile);
	}
	fclose(pFile);
	Log::info(LOG_TAG, "user[%s] setPhoto[%s]", userID.data(), path.data());
}

Poco::Buffer<char> AccountStubImpl::getPhoto(const std::string &userID) const
{
	Poco::Buffer<char> ret(0);
	auto path = "photo/" + userID;
	FILE *pFile = fopen(path.data(), "rb");
	if (pFile)
	{
		fseek(pFile, 0, SEEK_END);
		int nLength = ftell(pFile);
		unsigned char *pData = new unsigned char[nLength];
		fseek(pFile, 0, SEEK_SET);
		Poco::Buffer<char> ret(nLength);
		fread(ret.begin(), nLength, 1, pFile);
	}
	fclose(pFile);
	Log::info(LOG_TAG, "user[%s] getPhoto[%s]", userID.data(), path.data());
	return ret;
}
