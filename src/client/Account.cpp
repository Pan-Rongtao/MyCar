#include "Account.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QUrl>
#include <QProcess>
#include <iostream>
#include "Car.h"
#include "Chat.h"
#include "Users.h"

Account *Account::get()
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
}

void Account::onAccountChanged(const UserInfo &info)
{
    if(info.userID == m_userID.toStdString())
    {
        setpcOnline(info.pcOnline);
        sethandeldOnline(info.handeldOnline);
        setvehicleOnline(info.vehicleOnline);
        setpadOnline(info.padOnline);
        if(!islogin())
        {
            setuserID("");
            setpassword("");
            setnickname("");
            setsignaTure("");
            setphoto("");
            setregistTime("");
        }
        else
        {
            setuserID(QString::fromStdString(info.userID));
            setpassword(QString::fromStdString(info.password));
            setnickname(QString::fromStdString(info.nickname));
            setsignaTure(QString::fromStdString(info.signaTure));
            saveUserPhoto(userID().toStdString(), info.photo);
            setphoto(getUserPhoto(userID().toStdString()));
            setregistTime(QString::fromStdString(info.registTime));

        }
    }
}

void Account::onMessageArrived(const ChatMessage &msg)
{
    emit P2PChat::get()->signalUpdate();
    emit GroupChat::get()->signalUpdate();
    emit MessageList::get()->signalUpdate();
    if(msg.receiverID == m_userID.toStdString())
    {
        emit MessageList::get()->signalUpdateNewMsg(QString::fromStdString(msg.senderID), QString::fromStdString(msg.content), msg.p2p);
    }
}

void Account::onShutdownPC(const std::string &userID)
{
#ifdef WIN32
    if(m_userID.toStdString() == userID)
    {
        qDebug() << QString::fromStdString(userID) << "shutdown by remote device";
        QString program = "C:/WINDOWS/system32/shutdown.exe";
        QStringList arguments;
        arguments << "-s";
        QProcess *myProcess = new QProcess();
        myProcess->start(program, arguments);
    }
#endif
}

void Account::saveUserPhoto(const std::string &userID, const std::string &photoBuffer)
{
    QDir dir;
    dir.mkdir("photos");
    auto path = "photos/" + QString::fromStdString(userID) + ".jpg";
    QFile f(path);
    if(f.open(QFile::WriteOnly))
        f.write(photoBuffer.data(), photoBuffer.size());
}

QString Account::getUserPhoto(const std::string &userID)
{
    return "photos/" + QString::fromStdString(userID) + ".jpg";
}

bool Account::isRegisted(const QString &userID)
{
    return Proxy::get()->accountProxy()->isRegisted(userID.toStdString());
}

bool Account::regist(const QString &userID, const QString &password, const QString &nickname)
{
    return Proxy::get()->accountProxy()->regist(userID.toStdString(), password.toStdString(), nickname.toStdString());
}

bool Account::login(const QString &userID, const QString &password)
{
    bool b = false;
    setuserID(userID);
    auto proxy = Proxy::get()->accountProxy();
    try{
        switch (Proxy::get()->terminalType()) {
        case Type::Terminal_PC:        b = proxy->setPCOnline(userID.toStdString(), password.toStdString(), true);       break;
        case Type::Terminal_Vehicle:   b = proxy->setVehicleOnline(userID.toStdString(), password.toStdString(), true);  break;
        case Type::Terminal_CellPhone: b = proxy->setHandeldOnline(userID.toStdString(), password.toStdString(), true);  break;
        }
    }
    catch(RCF::Exception &e) { qDebug() << e.what(); }

    return b;
}

bool Account::logout()
{
    if(!islogin())  return true;
    bool b = false;
    auto proxy = Proxy::get()->accountProxy();
    switch (Proxy::get()->terminalType()) {
    case Type::Terminal_PC:        b = proxy->setPCOnline(m_userID.toStdString(), m_password.toStdString(), false);       break;
    case Type::Terminal_Vehicle:   b = proxy->setVehicleOnline(m_userID.toStdString(), m_password.toStdString(), false);  break;
    case Type::Terminal_CellPhone: b = proxy->setHandeldOnline(m_userID.toStdString(), m_password.toStdString(), false);  break;
    }
    return b;
}

bool Account::modifyPassword(const QString &password)
{
    Proxy::get()->accountProxy()->setPassword(m_userID.toStdString(), password.toStdString());
    return true;
}

bool Account::modifyNickname(const QString &nickname)
{
    Proxy::get()->accountProxy()->setNickname(m_userID.toStdString(), nickname.toStdString());
    return true;
}

bool Account::modifySignaTure(const QString &signaTure)
{
    Proxy::get()->accountProxy()->setSignaTure(m_userID.toStdString(), signaTure.toStdString());
    return true;
}

bool Account::modifyPhoto(const QUrl &file)
{
    QFile f(file.toLocalFile());
    f.open(QFile::ReadOnly);
    auto buffer = f.readAll();
    std::string photoBuffer(buffer.data(), buffer.size());
    f.close();
    try{
        return Proxy::get()->accountProxy()->setPhoto(m_userID.toStdString(), photoBuffer);
    }
    catch(...)
    {
        return false;
    }
}

////////friends
Friends::Friends()
{
}

Friends *Friends::get()
{
    static Friends *p = nullptr;
    if(!p)  p = new Friends();
    return p;
}

QList<UserItem> &Friends::items()
{
    return m_list;
}

int Friends::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    return m_list.size();
}

QVariant Friends::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].id;
    case 1: return m_list[index.row()].name;
    case 2: return m_list[index.row()].photo;
    default:return QVariant();
    }
}

QHash<int, QByteArray> Friends::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "id";
    roles[1] = "name";
    roles[2] = "photo";
    return roles;
}

void Friends::add(const QList<int> &indexs)
{
    auto userID = Account::get()->userID();
    for(auto i : indexs)
    {
        auto friendID = Users::get()->items()[i].id;
        if(friendID != userID)
            Proxy::get()->accountProxy()->addFriend(userID.toStdString(), friendID.toStdString());
    }
    update();
}

void Friends::remove(int index)
{
    auto userID = Account::get()->userID();
    auto friendID = m_list[index].id;
    Proxy::get()->accountProxy()->removeFriend(userID.toStdString(), friendID.toStdString());
    update();
}

void Friends::update()
{
    auto proxy = Proxy::get()->accountProxy();
    std::vector<std::string> friends = proxy->getFriends(Account::get()->userID().toStdString());
    beginResetModel();
    m_list.clear();
    for(auto & friendID : friends)
    {
        UserInfo info = proxy->getUserInfo(friendID);
        Account::get()->saveUserPhoto(info.userID, info.photo);
        UserItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), Account::get()->getUserPhoto(info.userID));
        m_list.append(item);
    }
    endResetModel();
}
