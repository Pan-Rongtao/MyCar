#pragma once
#define WIN32_WINNT 0x60
#define WIN32_LEAN_AND_MEAN

#include <RCF/RCF.hpp>
#include <QObject>
#include "server/Account.h"
#include "server/Car.h"
#ifdef WIN32
    #include <WinSock2.h>
#else
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <sys/ioctl.h>
    #include <net/if.h>
    #include <stdlib.h>
#endif

class Proxy : public QObject
{
    Q_OBJECT
public:
    static Proxy *instance();

    Q_PROPERTY(bool connected READ connected WRITE setconnected NOTIFY connectedChanged)

    void setconnected(bool connected);
    bool connected();

    bool connectToServer(const std::string &ip, int interfacePort, int publisherPort);
    std::shared_ptr<RcfClient<AccountInterface>> accountProxy();
    std::shared_ptr<RcfClient<CarInterface>> carProxy();

    static std::string getLocalIp();

signals:
    void connectedChanged();

public slots:
    bool ping();

private:
    Proxy();

    std::shared_ptr<RcfClient<AccountInterface>>m_accountProxy;
    std::shared_ptr<RcfClient<CarInterface>>	m_carProxy;
    std::shared_ptr<RCF::RcfServer>             m_subscribServer;
    RCF::SubscriptionPtr                        m_accountSubscription;
    RCF::SubscriptionPtr                        m_carSubscription;
    bool                                        m_connected;
};
