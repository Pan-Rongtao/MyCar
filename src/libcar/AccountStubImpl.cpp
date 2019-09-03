#include "AccountStubImpl.h"
#include "Poco/File.h"

using namespace uit;
using namespace Poco;
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

void AccountStubImpl::registerAccount(const std::string & id, const std::string & password, const std::string & nickname)
{
	Data::Statement sm(*m_session);
	Poco::Tuple<std::string, std::string, std::string, Poco::DateTime> record(id, password, nickname, Poco::DateTime());
	sm << "insert into account values(?, ?)", use(record), now;
}

void AccountStubImpl::deleteAccount(const std::string & id)
{
	Data::Statement sm(*m_session);
	auto _id = id;
	sm << "delete from account where id=?", use(_id), now;
}

void AccountStubImpl::setPassword(const std::string &id, const std::string & password)
{
	Data::Statement sm(*m_session);
	auto _id = id;
	auto _pw = password;
	sm << "update account set password=? where id=?", use(_pw), use(_id), now;

}

std::string AccountStubImpl::getPassword(const std::string &id) const
{
	std::vector<std::string> ret;
	auto ss = *m_session;
	Data::Statement select(ss);
	auto _id = id;
	select << "select password from account where id=?", into(ret), use(_id), now;
	return ret.empty() ? "" : ret.front();
}

void AccountStubImpl::setNickname(const std::string &id, const std::string & nickname)
{
	auto _id = id;
	auto _nn = nickname;
	Data::Statement sm(*m_session);
	sm << "update account set nickname=? where id=?", use(_nn), use(_id), now;
}

std::string AccountStubImpl::getNickname(const std::string &id) const
{
	auto _id = id;
	std::vector<std::string> ret;
	auto ss = *m_session;
	Data::Statement sm(ss);
	sm << "select nickname from account where id=?", into(ret), use(_id), now;
	return ret.empty() ? "" : ret.front();
}

void AccountStubImpl::setPhoto(const std::string &id, const Poco::Buffer<char>& photo)
{
	auto path = "photo/" + id;
	FILE *pFile = fopen(path.data(), "rw");
	if (pFile == nullptr)
	{
		printf("can't create photo.\n");
		return;
	}
	fwrite(photo.begin(), 1, photo.size(), pFile);
	fclose(pFile);
}

Poco::Buffer<char> AccountStubImpl::getPhoto(const std::string &id) const
{
	auto path = "photo/" + id;
	FILE *pFile = fopen(path.data(), "rb");
	if (pFile == nullptr)
	{
		fclose(pFile);
		return Poco::Buffer<char>(0);
	}
	else
	{
		fseek(pFile, 0, SEEK_END);
		int nLength = ftell(pFile);
		unsigned char *pData = new unsigned char[nLength];
		fseek(pFile, 0, SEEK_SET);
		Poco::Buffer<char> ret(nLength);
		fread(ret.begin(), nLength, 1, pFile);
		fclose(pFile);
		return ret;
	}
}
