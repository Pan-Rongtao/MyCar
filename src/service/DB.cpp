#include "DB.h"
#include "Poco/File.h"

using namespace uit;

DB * DB::get()
{
	static DB *p = nullptr;
	if (!p)
		p = new DB();
	return p;
}

bool DB::load(const std::string & path)
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

std::string DB::getDBPath() const
{
	return m_DBpath;
}

Poco::Data::Session & uit::DB::session()
{
	return *m_session;
}
