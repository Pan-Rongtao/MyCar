#include "Account.h"
#include <QDebug>
#include <QFile>
#include <iostream>
#include "ImageProvider.h"
#include "Car.h"

Account *Account::instance()
{
    static Account *p = nullptr;
    if(!p)  p = new Account();
    return p;
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

bool Account::islogin()
{
#if defined(Q_OS_WIN)
        return pcOnline();
#elif defined(Q_OS_ANDROID)
        return handeldOnline();
#elif defined(Q_OS_LINUX)
        return vehicleOnline();
#endif
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
        setpcOnline(info.pcOnline);
        sethandeldOnline(info.handeldOnline);
        setvehicleOnline(info.vehicleOnline);
        setpadOnline(info.padOnline);
        updateAccountInfo(info);
    }
}

bool Account::isRegisted(const QString &userID)
{
    return Proxy::instance()->accountProxy()->isRegisted(userID.toStdString());
}

bool Account::regist(const QString &userID, const QString &password, const QString &nickname)
{
    return Proxy::instance()->accountProxy()->regist(userID.toStdString(), password.toStdString(), nickname.toStdString());
}

bool Account::login(const QString &userID, const QString &password)
{
    bool b = false;
    setuserID(userID);
    auto proxy = Proxy::instance()->accountProxy();
    try{
        switch (m_t) {
        case pc:        b = proxy->setPCOnline(userID.toStdString(), password.toStdString(), true);       break;
        case vehicle:   b = proxy->setVehicleOnline(userID.toStdString(), password.toStdString(), true);  break;
        case handheld:  b = proxy->setHandeldOnline(userID.toStdString(), password.toStdString(), true);  break;
        }
    }
    catch(RCF::Exception &e)
    {
        qDebug() << e.what();
    }

    return b;
}

bool Account::logout()
{
    if(!islogin())  return false;

    bool b = false;
    auto proxy = Proxy::instance()->accountProxy();
    switch (m_t) {
    case pc:        b = proxy->setPCOnline(m_userID.toStdString(), m_password.toStdString(), false);       break;
    case vehicle:   b = proxy->setVehicleOnline(m_userID.toStdString(), m_password.toStdString(), false);  break;
    case handheld:  b = proxy->setHandeldOnline(m_userID.toStdString(), m_password.toStdString(), false);  break;
    }
    return b;
}

bool Account::modifyPassword(const QString &password)
{
    Proxy::instance()->accountProxy()->setPassword(m_userID.toStdString(), password.toStdString());
    return true;
}

bool Account::modifyNickname(const QString &nickname)
{
    Proxy::instance()->accountProxy()->setNickname(m_userID.toStdString(), nickname.toStdString());
    return true;
}

bool Account::modifySignaTure(const QString &signaTure)
{
    Proxy::instance()->accountProxy()->setSignaTure(m_userID.toStdString(), signaTure.toStdString());
    return true;
}

bool Account::modifyPhoto(const QUrl &file)
{
    QFile f(file.toLocalFile());
    bool b = f.open(QFile::ReadOnly);
    auto buffer = f.readAll();
    std::string photoBuffer(buffer.data(), buffer.size());
    try{
        b = Proxy::instance()->accountProxy()->setPhoto(m_userID.toStdString(), photoBuffer);
    }catch(...)
    {
        f.close();
        return false;
    }
    f.close();
    return b;
}

void Account::updateAccountInfo(const AccountInfo &info)
{
    if(!islogin())
    {
        setuserID("");
        setpassword("");
        setnickname("");
        setsignaTure("");
        ImageProvider::instance()->setImage(nullptr, 0);
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
        ImageProvider::instance()->setImage((const unsigned char *)info.photo.data(), info.photo.size());
        setregistTime(QString::fromStdString(info.registTime));
        setvehicleOnline(info.vehicleOnline);
        setpcOnline(info.pcOnline);
        sethandeldOnline(info.handeldOnline);
        setpadOnline(info.padOnline);
    }
}
