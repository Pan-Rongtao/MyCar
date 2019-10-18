#include "Proxy.h"
#include "Account.h"
#include "Car.h"

Proxy::Proxy()
    : m_terminalType(Type::Terminal_PC)
    , m_connected(false)
{
    RCF::init();
#if defined(Q_OS_WIN)
    m_terminalType = Type::Terminal_PC;
#elif defined(Q_OS_ANDROID)
    m_terminalType = Type::Terminal_CellPhone;
#elif defined(Q_OS_LINUX)
    m_terminalType = Type::Terminal_Vehicle;
#endif
}

Proxy *Proxy::instance()
{
    static Proxy *p = nullptr;
    if(!p)  p = new Proxy();
    return p;
}

void Proxy::setterminalType(const Type::TerminalType &terminalType)
{
    if(m_terminalType != terminalType)
    {
        m_terminalType = terminalType;
        emit terminalTypeChanged();
    }
}

Type::TerminalType Proxy::terminalType()
{
    return m_terminalType;
}

void Proxy::setconnected(bool connected)
{
    if(connected != m_connected)
    {
        m_connected = connected;
        emit connectedChanged();
    }
}

bool Proxy::connected()
{
    return m_connected;
}

std::shared_ptr<RcfClient<AccountInterface> > Proxy::accountProxy()
{
    return m_accountProxy;
}

std::shared_ptr<RcfClient<CarInterface> > Proxy::carProxy()
{
    return m_carProxy;
}

bool Proxy::ping()
{
    try{
        m_accountProxy->getClientStubPtr() ->ping();
        return true;
    }catch(...) { return false; }
}

bool Proxy::connectToServer(const std::string &ip, int interfacePort, int publisherPort)
{
    m_accountProxy = std::make_shared<RcfClient<AccountInterface>>(RCF::TcpEndpoint(ip, interfacePort));
    m_accountProxy->getClientStub().setAutoReconnect(true);
    m_carProxy = std::make_shared<RcfClient<CarInterface>>(RCF::TcpEndpoint(ip, interfacePort));
    m_carProxy->getClientStub().setAutoReconnect(true);
    m_subscribServer = std::make_shared<RCF::RcfServer>(RCF::TcpEndpoint(-1));
    m_subscribServer->start();
    RCF::SubscriptionParms subParms;
    subParms.setPublisherEndpoint(RCF::TcpEndpoint(ip, publisherPort));
    m_accountSubscription = m_subscribServer->createSubscription<AccountNotify>(*Account::instance(), subParms);
    m_carSubscription = m_subscribServer->createSubscription<CarNotify>(*Car::instance(), subParms);

    bool b = ping();
    setconnected(b);
    return b;
}

std::string Proxy::getLocalIp()
{
#ifdef Q_OS_WIN32
    WSADATA Data;
    WSAStartup(MAKEWORD(1, 1), &Data);
    char hostName[256] = { 0 };
    gethostname(hostName, sizeof(hostName));
    PHOSTENT hostinfo;
    hostinfo = gethostbyname(hostName);
    std::string ip = inet_ntoa(*(struct in_addr*)*hostinfo->h_addr_list);
    WSACleanup();
    return ip;
#else
	auto getDeviceIp = [](const std::string &sDev)->std::string {
		char ip[80] = { 0 };
		struct ifreq ifr;
		int sk = socket(AF_INET, SOCK_DGRAM, 0);
		strcpy(ifr.ifr_name, sDev.data());
		if (ioctl(sk, SIOCGIFADDR, &ifr) == 0)
			strcpy(ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
		close(sk);
		return ip;
	};

	auto eth = getDeviceIp("ens160");
	if(eth.empty())
	{
		eth = getDeviceIp("eth1");
		if(eth.empty())
			eth = getDeviceIp("mlan0");
	}
	return eth;
#endif
}
