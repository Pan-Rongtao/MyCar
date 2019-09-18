#pragma once
#include <Poco/SharedPtr.h>
#include <Poco/Data/SQLite/SQLite.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>

namespace uit {

class DB
{
public:
	//
	static DB *instance();

	//º”‘ÿ ˝æ›ø‚
	bool load(const std::string &path);
	std::string getDBPath() const;

	Poco::Data::Session &session();

private:
	std::string								m_DBpath;
	Poco::SharedPtr<Poco::Data::Session>	m_session;

};

}