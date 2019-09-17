#include "Account.h"
#include "svcar/core/Log.h"
#include "Poco/Dynamic/Var.h"
#include <QDebug>
#include <QFile>
#include "Poco/Platform.h"
#include "ImageProvider.h"

void Account::setconnected(bool connected)
{
    if(connected != m_connected)
        m_connected = connected;
    emit connectedChanged();
}

bool Account::connected()
{
    return m_connected;
}

void Account::setuserID(const QString &useID)
{
    if(m_userID != useID)
        m_userID = useID;
    emit userIDChanged();
}

QString Account::userID()
{
    return m_userID;
}

void Account::setpassword(const QString &password)
{
    if(m_password != password)
        m_password = password;
    emit passwordChanged();
}

QString Account::password()
{
    return m_password;
}

void Account::setnickname(const QString &nickname)
{
    if(m_nickname != nickname)
        m_nickname = nickname;
    emit nicknameChanged();
}

QString Account::nickname()
{
    return m_nickname;
}

void Account::setsignaTure(const QString &signaTure)
{
    if(m_signaTure != signaTure)
        m_signaTure = signaTure;
    emit signaTureChanged();
}

QString Account::signaTure()
{
    return m_signaTure;
}

void Account::setphoto(const QString &photo)
{
    if(m_photo != photo)
        m_photo = photo;
    emit photoChanged();
}

QString Account::photo()
{
    return m_photo;
}

void Account::setregistTime(const QString &registTime)
{
    if(m_registTime != registTime)
        m_registTime = registTime;
    emit registTimeChanged();
}

QString Account::registTime()
{
    return m_registTime;
}

void Account::setvehicleOnline(bool vehicleOnline)
{
    if(m_vehicleOnline != vehicleOnline)
        m_vehicleOnline = vehicleOnline;
    emit vehicleOnlineChanged();
}

bool Account::vehicleOnline()
{
    return m_vehicleOnline;
}

void Account::setpcOnline(bool pcOnline)
{
    if(m_pcOnline != pcOnline)
        m_pcOnline = pcOnline;
    emit pcOnlineChanged();
}

bool Account::pcOnline()
{
    return m_pcOnline;
}

void Account::sethandeldOnline(bool handeldOnline)
{
    if(m_handeldOnline != handeldOnline)
        m_handeldOnline = handeldOnline;
    emit handeldOnlineChanged();
}

bool Account::handeldOnline()
{
    return m_handeldOnline;
}

void Account::setpadOnline(bool padOnline)
{
    if(m_padOnline != padOnline)
        m_padOnline = padOnline;
    emit padOnlineChanged();
}

bool Account::padOnline()
{
    return m_padOnline;
}

void Account::setislogin(bool islogin)
{
    if(m_islogin != islogin)
        m_islogin = islogin;
    emit isloginChanged();
}

bool Account::islogin()
{
    return m_islogin;
}

Account::Account()
{
    qRegisterMetaType<std::string>("std::string");
    connect(this, SIGNAL(signalPhotoChanged(std::string)), this, SLOT(slotPhotoChanged(std::string)));
    RCF::init();
#if POCO_OS == POCO_OS_WINDOWS_NT
    m_t = pc;
#elif POCO_OS == POCO_OS_ANDROID
    m_t = handheld;
#elif POCO_OS == POCO_OS_LINUX
    m_t = vehicle;
#endif
}

void Account::onPasswordChanged(const std::string &userID, const std::string &password)
{
    if(userID == m_userID.toStdString())
        setpassword(QString::fromStdString(password));
}

void Account::onUserNicknameChanged(const std::string &userID, const std::string &nickname)
{
    if(userID == m_userID.toStdString())
        setnickname(QString::fromStdString(nickname));
}

void Account::onUserSignaTureChanged(const std::string &userID, const std::string &signaTure)
{
    if(userID == m_userID.toStdString())
        setsignaTure(QString::fromStdString(signaTure));
}

void Account::onUserPhotoChanged(const std::string &userID, const std::string &photoBuffer)
{
    if(userID == m_userID.toStdString())
    {
        ImageProvider::current()->setImage((const unsigned char *)photoBuffer.data(), photoBuffer.size());
    //    updateAccountInfo(m_userID);
    //    emit signalPhotoChanged(photoBuffer);
    }
}

void Account::onUserLoggingStateChanged(const std::string &userID, int terminalType, bool bLogin, bool kickout)
{
    if(userID == m_userID.toStdString())
    {
        if(bLogin)
        {

        }
    }
}

bool Account::connectServer(const QString &ip, int port)
{
    m_client = std::make_shared<RcfClient<AccountInterface>>(RCF::TcpEndpoint(ip.toStdString(), port));
    m_client->getClientStub().setAutoReconnect(true);
    m_subscribServer = std::make_shared<RCF::RcfServer>(RCF::TcpEndpoint(-1));
    m_subscribServer->start();

    RCF::SubscriptionParms subParms;
    subParms.setPublisherEndpoint(RCF::TcpEndpoint(ip.toStdString(), 9999));
    try
    {
        m_subscription = m_subscribServer->createSubscription<AccountNofity>(*this, subParms);
    }
    catch ( const RCF::Exception & e )
    {
        std::cout << "Error: " << e.getErrorMessage() << std::endl;
    }
    try{
        m_client->getClientStub().ping();
    }catch(...)
    {
        setconnected(false);
        return false;
    }
    setconnected(true);
    return true;
}

bool Account::isUserIDExists(const QString &userID)
{
    return m_client->isUserIDExists(userID.toStdString());
}

bool Account::regist(const QString &userID, const QString &password, const QString &nickname)
{
    return m_client->regist(userID.toStdString(), password.toStdString(), nickname.toStdString());
}

bool Account::login(const QString &userID, const QString &password)
{
    bool b = m_client->login(userID.toStdString(), password.toStdString(), m_t);
    if(b)
        setislogin(true);
    updateAccountInfo(userID);
    return b;
}

bool Account::logout()
{
    if(!m_islogin)  return false;

    bool b = m_client->logout(m_userID.toStdString(), m_password.toStdString(), m_t, false);
    setislogin(false);
    updateAccountInfo(m_userID);
    return b;
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

void Account::slotPhotoChanged(std::string buffer)
{
    ImageProvider::current()->setImage((const unsigned char *)buffer.data(), buffer.size());
    //updateAccountInfo(m_userID);
    qDebug() << "photo changed, size=" << buffer.size();
}

void Account::updateAccountInfo(const QString &userID)
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
        std::string sPassword, sNickname, sSignaTure, sPhoto, sRegTime;
        bool bVehicleOnline, bPCOnline, bHandeldOnline, bPadOnline;
        try{
        m_client->getAccountInfo(userID.toStdString(), sPassword, sNickname, sSignaTure, sPhoto, sRegTime, bVehicleOnline, bPCOnline, bHandeldOnline, bPadOnline);
        }catch(RCF::Exception &e)
        {
            std::cout << "Error: " << e.getErrorMessage() << std::endl;
        }

        setuserID(QString::fromStdString(userID.toStdString()));
        setpassword(QString::fromStdString(sPassword));
        setnickname(QString::fromStdString(sNickname));
        setsignaTure(QString::fromStdString(sSignaTure));
        ImageProvider::current()->setImage((const unsigned char *)sPhoto.data(), sPhoto.size());
        setregistTime(QString::fromStdString(sRegTime));
        setvehicleOnline(bVehicleOnline);
        setpcOnline(bPCOnline);
        sethandeldOnline(bHandeldOnline);
        setpadOnline(bPadOnline);
    }
}
