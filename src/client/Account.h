#pragma once

#define WIN32_WINNT 0x60
#define WIN32_LEAN_AND_MEAN

#include <QObject>
#include <RCF/RCF.hpp>
#include "server/Account.h"

class Account : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(bool connected READ connected WRITE setconnected NOTIFY connectedChanged)
    Q_PROPERTY(QString userID READ userID WRITE setuserID NOTIFY userIDChanged)
    Q_PROPERTY(QString password READ password WRITE setpassword NOTIFY passwordChanged)
    Q_PROPERTY(QString nickname READ nickname WRITE setnickname NOTIFY nicknameChanged)
    Q_PROPERTY(QString signaTure READ signaTure WRITE setsignaTure NOTIFY signaTureChanged)
    Q_PROPERTY(QString photo READ photo WRITE setphoto NOTIFY photoChanged)
    Q_PROPERTY(QString registTime READ registTime WRITE setregistTime NOTIFY registTimeChanged)
    Q_PROPERTY(bool vehicleOnline READ vehicleOnline WRITE setvehicleOnline NOTIFY vehicleOnlineChanged)
    Q_PROPERTY(bool pcOnline READ pcOnline WRITE setpcOnline NOTIFY pcOnlineChanged)
    Q_PROPERTY(bool handeldOnline READ handeldOnline WRITE sethandeldOnline NOTIFY handeldOnlineChanged)
    Q_PROPERTY(bool padOnline READ padOnline WRITE setpadOnline NOTIFY padOnlineChanged)

    Q_PROPERTY(bool islogin READ islogin WRITE setislogin NOTIFY isloginChanged)


    void setconnected(bool connected);
    bool connected();

    void setuserID(const QString &useID);
    QString userID();

    void setpassword(const QString &password);
    QString password();

    void setnickname(const QString &nickname);
    QString nickname();

    void setsignaTure(const QString &signaTure);
    QString signaTure();

    void setphoto(const QString &photo);
    QString photo();

    void setregistTime(const QString &registTime);
    QString registTime();

    void setvehicleOnline(bool vehicleOnline);
    bool vehicleOnline();

    void setpcOnline(bool pcOnline);
    bool pcOnline();

    void sethandeldOnline(bool handeldOnline);
    bool handeldOnline();

    void setpadOnline(bool padOnline);
    bool padOnline();

    void setislogin(bool islogin);
    bool islogin();

    Account();

    void onAccountChanged(const std::string &userID, const AccountInfo &info);

signals:
    void connectedChanged();
    void userIDChanged();
    void passwordChanged();
    void nicknameChanged();
    void signaTureChanged();
    void photoChanged();
    void registTimeChanged();
    void vehicleOnlineChanged();
    void pcOnlineChanged();
    void handeldOnlineChanged();
    void padOnlineChanged();
    void isloginChanged();

public slots:
    bool connectServer(const std::string &ip, int interfacePort, int publisherPort);
    bool isRegisted(const QString &userID);
    bool regist(const QString &userID, const QString &password, const QString &nickname);
    bool login(const QString &userID, const QString &password);
    bool logout();
    bool modifyPassword(const QString &password);
    bool modifyNickname(const QString &nickname);
    bool modifySignaTure(const QString &signaTure);
    bool modifyPhoto(const QUrl &file);

private:
    enum TerminalType
    {
        pc,
        vehicle,
        handheld,
        pad,
    };

    void updateAccountInfo(const AccountInfo &info);

    std::shared_ptr<RcfClient<AccountInterface>>	m_client;
    std::shared_ptr<RCF::RcfServer>                 m_subscribServer;
    RCF::SubscriptionPtr                            m_subscription;

    bool    m_connected{false};
    QString m_userID;
    QString m_password;
    QString m_nickname;
    QString m_signaTure;
    QString m_photo;
    QString m_registTime;
    bool    m_vehicleOnline{false};
    bool    m_pcOnline{false};
    bool    m_handeldOnline{false};
    bool    m_padOnline{false};
    bool    m_islogin{false};

    TerminalType    m_t{pc};
};

