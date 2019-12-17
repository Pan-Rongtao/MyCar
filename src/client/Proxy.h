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
#include "Type.h"

class Proxy : public QObject
{
    Q_OBJECT
public:
    static Proxy *get();

    Q_PROPERTY(Type::TerminalType terminalType READ terminalType WRITE setterminalType NOTIFY terminalTypeChanged)
    Q_PROPERTY(bool connected READ connected WRITE setconnected NOTIFY connectedChanged)

    void setterminalType(const Type::TerminalType &terminalType);
    Type::TerminalType terminalType();

    void setconnected(bool connected);
    bool connected();

    std::shared_ptr<RcfClient<AccountInterface>> accountProxy();
    std::shared_ptr<RcfClient<CarInterface>> carProxy();

    static std::string getLocalIp();

signals:
    void terminalTypeChanged();
    void connectedChanged();

public slots:
    bool ping();
    bool connectToServer(const QString &ip, int interfacePort, int publisherPort);

private:
    Proxy();

    std::shared_ptr<RcfClient<AccountInterface>>m_accountProxy;
    std::shared_ptr<RcfClient<CarInterface>>	m_carProxy;
    std::shared_ptr<RCF::RcfServer>             m_subscribServer;
    RCF::SubscriptionPtr                        m_accountSubscription;
    RCF::SubscriptionPtr                        m_carSubscription;
    bool                                        m_connected;
    Type::TerminalType                          m_terminalType;
};
