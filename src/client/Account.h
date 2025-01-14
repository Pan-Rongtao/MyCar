#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "Proxy.h"
#include "Item.h"

class Account : public QObject
{
    Q_OBJECT
public:
    static Account *get();

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

    void onAccountChanged(const UserInfo &info);
    void onMessageArrived(const ChatMessage &msg);
    void onShutdownPC(const std::string &userID);
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
    void shutdownPC();

private:
    Account();

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
};

class Friends : public QAbstractListModel
{
    Q_OBJECT
public:
    static Friends *get();

    QList<UserItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void add(const QList<int> &indexs);
    void remove(int index);
    void update();

private:
    Friends();

    QList<UserItem> m_list;
};

