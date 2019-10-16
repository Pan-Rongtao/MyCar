#include "AccountStub.h"
#include <Poco/Data/RecordSet.h>
#include <Poco/File.h>
#include <Poco/Path.h>
#include "server/Account.h"
#include "core/Log.h"
#include "core/Runtime.h"
#include "DB.h"
#include "CarStub.h"

using namespace uit;
using namespace Poco;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;

#define LOG_TAG				"server"
#define USER_DEFAULT_PHOTO	uit::Runtime::getUitEtcDirectory() + "default.jpg"
#define USER_PHOTO_DIR		uit::Runtime::getUitEtcDirectory() + "photos/"

AccountStub * AccountStub::get()
{
	static AccountStub *p = nullptr;
	if (!p)	p = new AccountStub();
	return p;
}

bool AccountStub::regist(const std::string & userID, const std::string & password, const std::string & nickname)
{
	UserInfo info{ userID, password, nickname, "该用户很懒，懒得签名.", USER_DEFAULT_PHOTO, DateTimeFormatter::format(DateTime(), Poco::DateTimeFormat::SORTABLE_FORMAT) , 0, 0, 0, 0 };
	try {
		DB::get()->session() << "insert into users values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", use(info.userID), use(info.password), use(info.nickname), use(info.signaTure),
			use(info.photo), use(info.registTime), use(info.vehicleOnline), use(info.pcOnline), use(info.handeldOnline), use(info.padOnline), now;
		CarStub::get()->addRecord(userID);
	}
	catch (Poco::Exception &e) {
		Log::error(LOG_TAG, "regist userID[%s] has been registed, error=[%s].", userID.data(), e.what());
		return false;
	}
	Log::info(LOG_TAG, "user[%s] regist, password[%s], nickname[%s]", userID.data(), password.data(), nickname.data());
	return true;
}

bool AccountStub::isRegisted(const std::string & userID)
{
	std::vector<std::string> records;
	auto _id = userID;
	DB::get()->session() << "select UserID from users where UserID=?", into(records), use(_id), now;
	return !records.empty();
}

void AccountStub::setPassword(const std::string &userID, const std::string & password)
{
	auto _id = userID;
	auto _pw = password;
	DB::get()->session() << "update users set Password=? where UserID=?", use(_pw), use(_id), now;
	AccountChanged.dispatch({ getUserInfo(userID) });
	Log::info(LOG_TAG, "user[%s] setPassword[%s]", userID.data(), password.data());
}

void AccountStub::setNickname(const std::string &userID, const std::string & nickname)
{
	auto _id = userID;
	auto _nn = nickname;
	DB::get()->session() << "update users set NickName=? where UserID=?", use(_nn), use(_id), now;
	AccountChanged.dispatch({ getUserInfo(userID) });
	Log::info(LOG_TAG, "user[%s] setNickname[%s]", userID.data(), nickname.data());
}

void AccountStub::setSignaTure(const std::string & userID, const std::string & signaTure)
{
	auto _id = userID;
	auto _st = signaTure;
	DB::get()->session() << "update users set SignaTure=? where UserID=?", use(_st), use(_id), now;
	AccountChanged.dispatch({ getUserInfo(userID) });
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
		auto path = USER_PHOTO_DIR + userID + ".jpg";
		saveImage(path, photoBuffer);
		auto _id = userID;
		DB::get()->session() << "update users set Photo=? where UserID=?", use(path), use(_id), now;
		AccountChanged.dispatch({ getUserInfo(userID) });
		Log::info(LOG_TAG, "user[%s] setPhoto[%d]", userID.data(), photoBuffer.size());
		return true;
	}
}

void AccountStub::setVehicleOnline(const std::string & userID, const std::string &password, bool online)
{
	setOnline(userID, online, "VehicleOnline");
}

void AccountStub::setPCOnline(const std::string & userID, const std::string &password, bool online)
{
	setOnline(userID, online, "PCOnline");
}

void AccountStub::setHandeldOnline(const std::string & userID, const std::string &password, bool online)
{
	setOnline(userID, online, "HandeldOnline");
}

void AccountStub::setPadOnline(const std::string & userID, const std::string &password, bool online)
{
	setOnline(userID, online, "PadOnline");
}

UserInfo AccountStub::getUserInfo(const std::string & userID)
{
	Statement select(DB::get()->session());
	auto _id = userID;
	select << "select * from users where UserID=?", use(_id), now;
	RecordSet rs(select);
	UserInfo ret = rs.rowCount() == 0 ? UserInfo() : UserInfo{ 
		rs[0].convert<std::string>(), rs[1].convert<std::string>(), rs[2].convert<std::string>(), rs[3].convert<std::string>(),loadImage(rs[4].convert<std::string>()),
		rs[5].convert<std::string>(), rs[6].convert<bool>(), rs[7].convert<bool>(), rs[8].convert<bool>(), rs[9].convert<bool>() };
	return ret;
}

std::vector<UserInfo> AccountStub::queryUsers()
{
	std::vector<UserInfo> ret;
	Statement select(DB::get()->session());
	select << "select * from users", now;
	RecordSet rs(select);
	bool more = rs.moveFirst();
	while (more)
	{
		UserInfo info{ rs[0].convert<std::string>(), rs[1].convert<std::string>(), rs[2].convert<std::string>(), rs[3].convert<std::string>(),
			loadImage(rs[4].convert<std::string>()), rs[5].convert<std::string>(), rs[6].convert<bool>(), rs[7].convert<bool>(), rs[8].convert<bool>(), rs[9].convert<bool>() };
		ret.push_back(info);
		more = rs.moveNext();
	}
	return ret;
}

bool AccountStub::addFriend(const std::string & userID, const std::string & friendID)
{
	std::string _userID = userID;
	std::string _friendID = friendID;
	std::string _remark = friendID;
	try {
		DB::get()->session() << "insert into friends values(?, ?, ?)", use(_userID), use(_friendID), use(_remark), now;
		Log::info(LOG_TAG, "user[%s] addFriend[%s]", userID.data(), friendID.data());
		return true;
	}
	catch (Poco::Exception &e) {
		Log::error(LOG_TAG, "user[%s] already has friend[%s], error[%s].", userID.data(), friendID.data(), e.what());
		return false;
	}
}

void AccountStub::removeFriend(const std::string & userID, const std::string & friendID)
{
	std::string _userID = userID;
	std::string _friendID = friendID;
	DB::get()->session() << "delete from friends where UserID=? and FriendID=?", use(_userID), use(_friendID), now;
	Log::info(LOG_TAG, "user[%s] removeFriend[%s]", userID.data(), friendID.data());
}

std::vector<ChatMessage> AccountStub::getP2PMessages(const std::string & user0, const std::string & user1)
{
	std::vector<ChatMessage> ret;
	auto _id0 = user0;
	auto _id1 = user1;
	Statement select(DB::get()->session());
	select << "select * from p2p_messages where (FromID=? and ToID=?) or (FromID=? and ToID=?)", use(_id0), use(_id1), use(_id1), use(_id0), now;
	RecordSet rs(select);
	bool more = rs.moveFirst();
	while (more)
	{
		ChatMessage record{ rs[0].convert<std::string>(), rs[1].convert<std::string>(), rs[2].convert<std::string>(), rs[3].convert<std::string>() };
		ret.push_back(record);
		more = rs.moveNext();
	}
	return ret;
}

std::string AccountStub::addGroup(const std::string & name, const std::string & photoBuffer)
{
	std::vector<std::string> records;
	DB::get()->session() << "select GroupID from groups", into(records), now;
	std::string _groupID = "group_";
	if (records.empty())
	{
		_groupID += "0";
	}
	else
	{
		auto last = records.back();
		auto num = std::to_string(std::stoi(last.substr(last.find('_') + 1)) + 1);
		_groupID += num;
	}
	auto _name = name;
	auto _brief = "welcome!";
	auto _path = USER_PHOTO_DIR + _groupID + ".jpg";
	try {
		DB::get()->session() << "insert into groups values(?, ?, ?, ?)", use(_groupID), use(_name), use(_path), use(_brief), now;
		Log::info(LOG_TAG, "addGroup[%s]", _groupID.data());
		saveImage(_path, photoBuffer);
		return _groupID;
	}
	catch (Poco::Exception &e) {
		Log::error(LOG_TAG, "group[%s] already exists, ignore. error[%s]", _groupID.data(), e.what());
		return "";
	}
}

void AccountStub::removeGroup(const std::string & groupID)
{
	std::string _groupID = groupID;
	DB::get()->session() << "delete from groups where GroupID=?", use(_groupID), now;
	Log::info(LOG_TAG, "removeGroup[%s]", _groupID.data());
}

GroupInfo AccountStub::getGroupInfo(const std::string & grouID)
{
	auto _id = grouID;
	Statement select(DB::get()->session());
	select << "select * from groups where GroupID=?", use(_id), now;
	RecordSet rs(select);
	return rs.rowCount() == 0 ? GroupInfo() : GroupInfo{ rs[0].convert<std::string>(), rs[1].convert<std::string>(), loadImage(rs[2].convert<std::string>()), rs[3].convert<std::string>() };
}

std::vector<std::string> AccountStub::getBelongGroups(const std::string &userID)
{
	std::vector<std::string> ret;
	auto _userID = userID;
	DB::get()->session() << "select GroupID from groupmembers where UserID=?", into(ret), use(_userID), now;
	return ret;
}

void AccountStub::setGroupName(const std::string & groupID, const std::string & name)
{
	auto _id = groupID;
	auto _nn = name;
	DB::get()->session() << "update groups set Name=? where GroupID=?", use(_nn), use(_id), now;
	Log::info(LOG_TAG, "user[%s] setNickname[%s]", _id.data(), _nn.data());
}

void AccountStub::setGroupBrief(const std::string & groupID, const std::string & brief)
{
	auto _id = groupID;
	auto _brief = brief;
	DB::get()->session() << "update groups set Brief=? where GroupID=?", use(_brief), use(_id), now;
	Log::info(LOG_TAG, "user[%s] setNickname[%s]", _id.data(), _brief.data());
}

void AccountStub::addGroupMember(const std::string & groupID, const std::string & userID)
{
	std::string _groupID = groupID;
	std::string _userID = userID;
	try {
		DB::get()->session() << "insert into groupmembers values(?, ?)", use(_groupID), use(_userID), now;
		Log::info(LOG_TAG, "group[%s] addGroupMember[%s]", _groupID.data(), _userID.data());
	}
	catch (Poco::Exception &e) {
		(void)e;
		Log::error(LOG_TAG, "group[%s] already has member[%s], ignore.", _groupID.data(), _userID.data());
	}
}

void AccountStub::removeGroupMember(const std::string & groupID, const std::string & userID)
{
	std::string _groupID = groupID;
	std::string _userID = userID;
	DB::get()->session() << "delete from groupmembers where GroupID=? and userID=?", use(_groupID), use(_userID), now;
	Log::info(LOG_TAG, "group[%s] removeGroup[%s]", _groupID.data(), _userID.data());
}

std::vector<std::string> AccountStub::getGroupMembers(const std::string & groupID)
{
	std::vector<std::string> ret;
	auto _groupID = groupID;
	DB::get()->session() << "select UserID from groupmembers where GroupID=?", into(ret), use(_groupID), now;
	return ret;
}

std::vector<std::string> AccountStub::getFriends(const std::string & userID)
{
	std::vector<std::string> ret;
	auto _id = userID;
	DB::get()->session() << "select FriendID from friends where UserID=?", into(ret), use(_id), now;
	return ret;
}

void AccountStub::addP2PMessage(const std::string & fromID, const std::string & toID, const std::string & msg)
{
	auto _fromID = fromID;
	auto _toID = toID;
	auto _msg = msg;
	auto _dt = DateTimeFormatter::format(DateTime(), Poco::DateTimeFormat::SORTABLE_FORMAT);
	DB::get()->session() << "insert into p2p_messages values(?, ?, ?, ?)", use(_fromID), use(_toID), use(_msg), use(_dt), now;
	MessageArrived.dispatch({ _fromID, _toID, _msg, _dt });
	Log::info(LOG_TAG, "[%s] send msg to [%s]", fromID.data(), toID.data());
}

void AccountStub::addGroupMessage(const std::string & groupID, const std::string & fromID, const std::string & msg)
{
	auto _groupID = groupID;
	auto _fromID = fromID;
	auto _msg = msg;
	auto _dt = DateTimeFormatter::format(DateTime(), Poco::DateTimeFormat::SORTABLE_FORMAT);
	DB::get()->session() << "insert into group_messages values(?, ?, ?, ?)", use(_groupID), use(_fromID), use(_msg), use(_dt), now;
	MessageArrived.dispatch({ _fromID, _groupID, _msg, _dt });
	Log::info(LOG_TAG, "[%s] send msg on [%s]", fromID.data(), groupID.data());
}

std::vector<ChatMessage> AccountStub::getGroupMessages(const std::string & groupID)
{
	std::vector<ChatMessage> ret;
	auto _groupID = groupID;
	Statement select(DB::get()->session());
	select << "select * from group_messages where GroupID=?", use(_groupID), now;
	RecordSet rs(select);
	bool more = rs.moveFirst();
	while (more)
	{
		ChatMessage record{ rs[0].convert<std::string>(), rs[1].convert<std::string>(), rs[2].convert<std::string>(), rs[3].convert<std::string>() };
		ret.push_back(record);
		more = rs.moveNext();
	}
	return ret;
}

void AccountStub::setOnline(const std::string & userID, bool online, const std::string & field)
{
	std::vector<std::string> records;
	auto _id = userID;
	int _online = online;
	DB::get()->session() << "select UserID from users where UserID=?", into(records), use(_id), now;
	std::string cmd = "update users set " + field + "=? where UserID = ?";
	DB::get()->session() << cmd, use(_online), use(_id), now;
	AccountChanged.dispatch({ getUserInfo(userID) });
	Log::info(LOG_TAG, "user[%s] set %s[%d] %s", userID.data(), field.data(), _online, records.empty() ? "fail for unknown userID" : "success");
}

void AccountStub::saveImage(const std::string & path, const std::string & imageBuffer)
{
	Poco::Path p(path);
	Poco::File f(p.parent());
	//保证文件夹的存在
	f.createDirectories();
	FILE *pf = fopen(path.data(), "wb");
	if (pf)
		fwrite(imageBuffer.data(), 1, imageBuffer.size(), pf);
	fclose(pf);
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