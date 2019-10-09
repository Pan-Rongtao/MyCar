#include "AccountStub.h"
#include <Poco/Data/RecordSet.h>
#include "server/Account.h"
#include "core/Log.h"
#include "DB.h"
#include "CarStub.h"

using namespace uit;
using namespace Poco;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;

#define LOG_TAG	"server"

AccountStub * AccountStub::instance()
{
	static AccountStub *p = nullptr;
	if (!p)	p = new AccountStub();
	return p;
}

bool AccountStub::regist(const std::string & userID, const std::string & password, const std::string & nickname)
{
	AccountInfo info{ userID, password, nickname, "该用户很懒，懒得签名.", "", DateTimeFormatter::format(DateTime(), Poco::DateTimeFormat::SORTABLE_FORMAT) , 0, 0, 0, 0 };
	try {
		DB::instance()->session() << "insert into users values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", use(info.userID), use(info.password), use(info.nickname), use(info.signaTure),
			use(info.photo), use(info.registTime), use(info.vehicleOnline), use(info.pcOnline), use(info.handeldOnline), use(info.padOnline), now;
		CarStub::instance()->addRecord(userID);
	}
	catch (Poco::Exception &e) {
		(void)e;
		Log::error(LOG_TAG, "regist userID[%s] is existed , password[%s], nickname[%s], ignore.", userID.data(), password.data(), nickname.data());
		return false;
	}
	Log::info(LOG_TAG, "user[%s] regist, password[%s], nickname[%s]", userID.data(), password.data(), nickname.data());
	return true;
}

bool AccountStub::isRegisted(const std::string & userID)
{
	std::vector<std::string> records;
	auto _id = userID;
	DB::instance()->session() << "select UserID from users where UserID=?", into(records), use(_id), now;
	bool bExists = !records.empty();
	return bExists;
}

void AccountStub::setPassword(const std::string &userID, const std::string & password)
{
	auto _id = userID;
	auto _pw = password;
	DB::instance()->session() << "update users set Password=? where UserID=?", use(_pw), use(_id), now;
	AccountInfo info;
	bool b = getAccountInfo(userID, info);
	AccountChanged.dispatch({userID, info });
	Log::info(LOG_TAG, "user[%s] setPassword[%s]", userID.data(), password.data());
}

void AccountStub::setNickname(const std::string &userID, const std::string & nickname)
{
	auto _id = userID;
	auto _nn = nickname;
	DB::instance()->session() << "update users set NickName=? where UserID=?", use(_nn), use(_id), now;
	AccountInfo info;
	bool b = getAccountInfo(userID, info);
	AccountChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] setNickname[%s]", userID.data(), nickname.data());
}

void AccountStub::setSignaTure(const std::string & userID, const std::string & signaTure)
{
	auto _id = userID;
	auto _st = signaTure;
	DB::instance()->session() << "update users set SignaTure=? where UserID=?", use(_st), use(_id), now;
	AccountInfo info;
	bool b = getAccountInfo(userID, info);
	AccountChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] setSignaTure[%s]", userID.data(), signaTure.data());
}

bool AccountStub::setPhoto(const std::string &userID, const std::string &photoBuffer)
{
	if (photoBuffer.size() > 256 * 1024)
	{
		Log::info(LOG_TAG, "user[%s] setPhoto[%d] fail, too big", userID.data(), photoBuffer.size());
		return false;
	}
	else
	{
		auto path = userID + ".jpg";
		FILE *pf = fopen(path.data(), "wb");
		if (pf)
		{
			fwrite(photoBuffer.data(), 1, photoBuffer.size(), pf);
		}
		fclose(pf);
		auto _id = userID;
		DB::instance()->session() << "update users set Photo=? where UserID=?", use(path), use(_id), now;
		AccountInfo info;
		bool b = getAccountInfo(userID, info);
		AccountChanged.dispatch({ userID, info });
		Log::info(LOG_TAG, "user[%s] setPhoto[%d]", userID.data(), photoBuffer.size());
		return true;
	}
}

bool AccountStub::setVehicleOnline(const std::string & userID, const std::string &password, bool online)
{
	std::vector<std::string> records;
	auto _id = userID;
	auto _pw = password;
	int _online = online;
	DB::instance()->session() << "select UserID from users where UserID=? and Password=?", into(records), use(_id), use(_pw), now;
	bool bExists = !records.empty();
	DB::instance()->session() << "update users set VehicleOnline=? where UserID = ? ", use(_online), use(_id), now;
	AccountInfo info;
	getAccountInfo(userID, info);
	AccountChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] %s for vehicle %s", userID.data(), _online ? "login" : "logout", bExists ? "success" : "fail with unmatched id|password");
	return bExists;
}

bool AccountStub::setPCOnline(const std::string & userID, const std::string &password, bool online)
{
	std::vector<std::string> records;
	auto _id = userID;
	auto _pw = password;
	int _online = online;
	DB::instance()->session() << "select UserID from users where UserID=? and Password=?", into(records), use(_id), use(_pw), now;
	bool bExists = !records.empty();
	DB::instance()->session() << "update users set PCOnline=? where UserID = ? ", use(_online), use(_id), now;
	AccountInfo info;
	getAccountInfo(userID, info);
	AccountChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] %s for pc %s", userID.data(), _online ? "login" : "logout", bExists ? "success" : "fail with unmatched id|password");
	return bExists;
}

bool AccountStub::setHandeldOnline(const std::string & userID, const std::string &password, bool online)
{
	std::vector<std::string> records;
	auto _id = userID;
	auto _pw = password;
	int _online = online;
	DB::instance()->session() << "select UserID from users where UserID=? and Password=?", into(records), use(_id), use(_pw), now;
	bool bExists = !records.empty();
	DB::instance()->session() << "update users set HandeldOnline=? where UserID = ? ", use(_online), use(_id), now;
	AccountInfo info;
	getAccountInfo(userID, info);
	AccountChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] %s for handeld %s", userID.data(), _online ? "login" : "logout", bExists ? "success" : "fail with unmatched id|password");
	return bExists;
}

bool AccountStub::setPadOnline(const std::string & userID, const std::string &password, bool online)
{
	std::vector<std::string> records;
	auto _id = userID;
	auto _pw = password;
	int _online = online;
	DB::instance()->session() << "select UserID from users where UserID=? and Password=?", into(records), use(_id), use(_pw), now;
	bool bExists = !records.empty();
	DB::instance()->session() << "update users set PadOnline=? where UserID = ? ", use(_online), use(_id), now;
	AccountInfo info;
	getAccountInfo(userID, info);
	AccountChanged.dispatch({ userID, info });
	Log::info(LOG_TAG, "user[%s] %s for pad %s", userID.data(), _online ? "login" : "logout", bExists ? "success" : "fail with unmatched id|password");
	return bExists;
}

bool AccountStub::getAccountInfo(const std::string & userID, AccountInfo &info)
{
	Statement select(DB::instance()->session());
	auto _id = userID;
	select << "select * from users where UserID=?", use(_id), now;
	RecordSet rs(select);
	if (rs.rowCount() == 0)
	{
		return false;
	}
	else
	{
		info.userID = rs[0].convert<std::string>();
		info.password = rs[1].convert<std::string>();
		info.nickname = rs[2].convert<std::string>();
		info.signaTure = rs[3].convert<std::string>();
		info.photo = loadImage(rs[4].convert<std::string>());
		info.registTime = rs[5].convert<std::string>();
		info.vehicleOnline = rs[6].convert<bool>();
		info.pcOnline = rs[7].convert<bool>();
		info.handeldOnline = rs[8].convert<bool>();
		info.padOnline = rs[9].convert<bool>();
		return true;
	}
}

bool AccountStub::queryAllAccountInfo(std::vector<AccountInfo>& infos)
{
	Statement select(DB::instance()->session());
	select << "select * from users", now;
	RecordSet rs(select);
	bool more = rs.moveFirst();
	while (more)
	{
		AccountInfo info;
		info.userID = rs[0].convert<std::string>();
		info.password = rs[1].convert<std::string>();
		info.nickname = rs[2].convert<std::string>();
		info.signaTure = rs[3].convert<std::string>();
		info.photo = loadImage(rs[4].convert<std::string>());
		info.registTime = rs[5].convert<std::string>();
		info.vehicleOnline = rs[6].convert<bool>();
		info.pcOnline = rs[7].convert<bool>();
		info.handeldOnline = rs[8].convert<bool>();
		info.padOnline = rs[9].convert<bool>();
		infos.push_back(info);
		more = rs.moveNext();
	}
	return true;
}

bool AccountStub::addContacts(const std::string & userID, const std::string & friendID)
{
	std::string _userID = userID;
	std::string _friendID = friendID;
	std::string _remark = friendID;
	try {
		DB::instance()->session() << "insert into friends values(?, ?, ?)", use(_userID), use(_friendID), use(_remark), now;
		Log::info(LOG_TAG, "user[%s] addContacts[%s]", userID.data(), friendID.data());
		return true;
	}
	catch (Poco::Exception &e) {
		(void)e;
		Log::error(LOG_TAG, "user[%s] already has contacts[%s], ignore.", userID.data(), friendID.data());
		return false;
	}
}

bool AccountStub::removeContacts(const std::string & userID, const std::string & friendID)
{
	std::string _userID = userID;
	std::string _friendID = friendID;
	DB::instance()->session() << "delete from friends where UserID=? and FriendID=?", use(_userID), use(_friendID), now;
	Log::info(LOG_TAG, "user[%s] removeContacts[%s]", userID.data(), friendID.data());
	return true;
}

bool AccountStub::getContacts(const std::string & userID, std::vector<std::string>& friends)
{
	auto _id = userID;
	DB::instance()->session() << "select FriendID from friends where UserID=?", into(friends), use(_id), now;
	return true;
}

std::string AccountStub::loadImage(const std::string &path) const
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