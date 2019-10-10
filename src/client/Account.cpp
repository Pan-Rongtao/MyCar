#include "Account.h"
#include "core/Log.h"
#include <QDebug>
#include <QFile>
#include <iostream>
#include "ImageProvider.h"
#include "Singleton.h"
#include "Car.h"

void Account::setconnected(bool connected)
{
    if(connected != m_connected)
    {
        m_connected = connected;
        emit connectedChanged();
    }
}

bool Account::connected()
{
    return m_connected;
}

void Account::setuserID(const QString &useID)
{
    if(m_userID != useID)
    {
        m_userID = useID;
        emit userIDChanged();
    }
}

QString Account::userID()
{
    return m_userID;
}

void Account::setpassword(const QString &password)
{
    if(m_password != password)
    {
        m_password = password;
        emit passwordChanged();
    }
}

QString Account::password()
{
    return m_password;
}

void Account::setnickname(const QString &nickname)
{
    if(m_nickname != nickname)
    {
        m_nickname = nickname;
        emit nicknameChanged();
    }
}

QString Account::nickname()
{
    return m_nickname;
}

void Account::setsignaTure(const QString &signaTure)
{
    if(m_signaTure != signaTure)
    {
        m_signaTure = signaTure;
        emit signaTureChanged();
    }
}

QString Account::signaTure()
{
    return m_signaTure;
}

void Account::setphoto(const QString &photo)
{
    if(m_photo != photo)
    {
        m_photo = photo;
        emit photoChanged();
    }
}

QString Account::photo()
{
    return m_photo;
}

void Account::setregistTime(const QString &registTime)
{
    if(m_registTime != registTime)
    {
        m_registTime = registTime;
        emit registTimeChanged();
    }
}

QString Account::registTime()
{
    return m_registTime;
}

void Account::setvehicleOnline(bool vehicleOnline)
{
    if(m_vehicleOnline != vehicleOnline)
    {
        m_vehicleOnline = vehicleOnline;
        emit vehicleOnlineChanged();
    }
}

bool Account::vehicleOnline()
{
    return m_vehicleOnline;
}

void Account::setpcOnline(bool pcOnline)
{
    if(m_pcOnline != pcOnline)
    {
        m_pcOnline = pcOnline;
        emit pcOnlineChanged();
    }
}

bool Account::pcOnline()
{
    return m_pcOnline;
}

void Account::sethandeldOnline(bool handeldOnline)
{
    if(m_handeldOnline != handeldOnline)
    {
        m_handeldOnline = handeldOnline;
        emit handeldOnlineChanged();
    }
}

bool Account::handeldOnline()
{
    return m_handeldOnline;
}

void Account::setpadOnline(bool padOnline)
{
    if(m_padOnline != padOnline)
    {
        m_padOnline = padOnline;
        emit padOnlineChanged();
    }
}

bool Account::padOnline()
{
    return m_padOnline;
}

void Account::setislogin(bool islogin)
{
    if(m_islogin != islogin)
    {
        m_islogin = islogin;
        emit isloginChanged();
    }
}

bool Account::islogin()
{
    return m_islogin;
}

Account::Account()
{
    RCF::init();
#if defined(Q_OS_WIN)
    m_t = pc;
#elif defined(Q_OS_ANDROID)
    m_t = handheld;
#elif defined(Q_OS_LINUX)
    m_t = vehicle;
#endif
}

void Account::onAccountChanged(const std::string &userID, const AccountInfo &info)
{
    if(userID == m_userID.toStdString())
    {
#if defined(Q_OS_WIN)
        setislogin(info.pcOnline);
#elif defined(Q_OS_ANDROID)
        setislogin(info.handeldOnline);
#elif defined(Q_OS_LINUX)
        setislogin(info.vehicleOnline);
#endif
        updateAccountInfo(info);
    }
}

bool Account::ping()
{
    try{
        m_client->getClientStubPtr()->ping();
        return true;
    }catch(...)
    {
        return false;
    }
}

bool Account::connectServer(const std::string &ip, int interfacePort, int publisherPort)
{
    m_client = std::make_shared<RcfClient<AccountInterface>>(RCF::TcpEndpoint(ip, interfacePort));
    m_client->getClientStub().setAutoReconnect(true);
    m_subscribServer = std::make_shared<RCF::RcfServer>(RCF::TcpEndpoint(-1));
    m_subscribServer->start();

    RCF::SubscriptionParms subParms;
    subParms.setPublisherEndpoint(RCF::TcpEndpoint(ip, publisherPort));
    m_subscription = m_subscribServer->createSubscription<AccountNotify>(*this, subParms);
    setconnected(true);
    return true;
}

bool Account::isRegisted(const QString &userID)
{
    return m_client->isRegisted(userID.toStdString());
}

bool Account::regist(const QString &userID, const QString &password, const QString &nickname)
{
    return m_client->regist(userID.toStdString(), password.toStdString(), nickname.toStdString());
}

bool Account::login(const QString &userID, const QString &password)
{
    bool b = false;
    try{
        switch (m_t) {
        case pc:        b = m_client->setPCOnline(userID.toStdString(), password.toStdString(), true);       break;
        case vehicle:   b = m_client->setVehicleOnline(userID.toStdString(), password.toStdString(), true);  break;
        case handheld:  b = m_client->setHandeldOnline(userID.toStdString(), password.toStdString(), true);  break;
        }
        setislogin(b);
        AccountInfo info;
        m_client->getAccountInfo(userID.toStdString(), info);
        updateAccountInfo(info);
        nb::Singleton<Car>::instance()->updateCar();
    }
    catch(RCF::Exception &e)
    {
        qDebug() << e.what();
    }

    return b;
}

bool Account::logout()
{
    if(!m_islogin)  return false;

    bool b = false;
    switch (m_t) {
    case pc:        b = m_client->setPCOnline(m_userID.toStdString(), m_password.toStdString(), false);       break;
    case vehicle:   b = m_client->setVehicleOnline(m_userID.toStdString(), m_password.toStdString(), false);  break;
    case handheld:  b = m_client->setHandeldOnline(m_userID.toStdString(), m_password.toStdString(), false);  break;
    }
    setislogin(false);
    AccountInfo info;
    m_client->getAccountInfo(m_userID.toStdString(), info);
    updateAccountInfo(info);
    nb::Singleton<Car>::instance()->updateCar();
    return b;
}

void Account::getInfo(const QString &userID, AccountInfo &info)
{
    m_client->getAccountInfo(userID.toStdString(), info);
}

bool Account::modifyPassword(const QString &password)
{
    m_client->setPassword(m_userID.toStdString(), password.toStdString());
    return true;
}

bool Account::modifyNickname(const QString &nickname)
{
    m_client->setNickname(m_userID.toStdString(), nickname.toStdString());
    return true;
}

bool Account::modifySignaTure(const QString &signaTure)
{
    m_client->setSignaTure(m_userID.toStdString(), signaTure.toStdString());
    return true;
}

bool Account::modifyPhoto(const QUrl &file)
{
    QFile f(file.toLocalFile());
    bool b = f.open(QFile::ReadOnly);
    auto buffer = f.readAll();
    std::string photoBuffer(buffer.data(), buffer.size());
    try{
        b = m_client->setPhoto(m_userID.toStdString(), photoBuffer);
    }catch(...)
    {
        f.close();
        return false;
    }
    f.close();
    return b;
}

void Account::queryAllAccount(std::vector<AccountInfo> &infos)
{
    m_client->queryAllAccountInfo(infos);
}

bool Account::addContacts(const QString &userID, const QString &friendID)
{
    return m_client->addContacts(userID.toStdString(), friendID.toStdString());
}

bool Account::removeContacts(const QString &userID, const QString &friendID)
{
    return m_client->removeContacts(userID.toStdString(), friendID.toStdString());
}

bool Account::getContacts(const QString &userID, std::vector<std::string> &friends)
{
    try{
        return m_client->getContacts(userID.toStdString(), friends);
    }catch(RCF::Exception &e)
    {
        qDebug() << e.what();
    }
}

void Account::updateAccountInfo(const AccountInfo &info)
{
    if(!m_islogin)
    {
        setuserID("");
        setpassword("");
        setnickname("");
        setsignaTure("");
        ImageProvider::current()->setImage(nullptr, 0);
        setregistTime("");
        setvehicleOnline(false);
        setpcOnline(false);
        sethandeldOnline(false);
        setpadOnline(false);
    }
    else
    {
        setuserID(QString::fromStdString(info.userID));
        setpassword(QString::fromStdString(info.password));
        setnickname(QString::fromStdString(info.nickname));
        setsignaTure(QString::fromStdString(info.signaTure));
        ImageProvider::current()->setImage((const unsigned char *)info.photo.data(), info.photo.size());
        setregistTime(QString::fromStdString(info.registTime));
        setvehicleOnline(info.vehicleOnline);
        setpcOnline(info.pcOnline);
        sethandeldOnline(info.handeldOnline);
        setpadOnline(info.padOnline);
    }
}
