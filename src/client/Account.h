#pragma once

#include <QObject>
#include "Proxy.h"

class Account : public QObject
{
    Q_OBJECT
public:
    static Account *instance();

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

    void onAccountChanged(const std::string &userID, const AccountInfo &info);
    void onP2PMessageArrived(const std::string &fromID, const P2PMessage &msg);
    void onGroupMessageArrived(const std::string &groupID, const GroupMessage &msg);
    void saveUserPhoto(const std::string &userID, const std::string &photoBuffer);
    QString getUserPhoto(const std::string &userID);

signals:
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

public slots:
    bool isRegisted(const QString &userID);
    bool regist(const QString &userID, const QString &password, const QString &nickname);
    bool login(const QString &userID, const QString &password);
    bool logout();
    bool islogin();
    bool modifyPassword(const QString &password);
    bool modifyNickname(const QString &nickname);
    bool modifySignaTure(const QString &signaTure);
    bool modifyPhoto(const QUrl &file);

private:
    Account();

    enum TerminalType
    {
        pc,
        vehicle,
        handheld,
        pad,
    };

    void updateAccountInfo(const AccountInfo &info);

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

    TerminalType    m_t{pc};
};

