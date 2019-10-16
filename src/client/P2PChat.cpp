#include "P2PChat.h"
#include <QFile>
#include <QDebug>
#include "Proxy.h"
#include "Account.h"
#include "Friends.h"
#include "MessageList.h"

P2PChat::P2PChat()
{
    QObject::connect(this, SIGNAL(signalUpdate()), this, SLOT(update()));
}

P2PChat *P2PChat::instance()
{
    static P2PChat *p = nullptr;
    if(!p)  p = new P2PChat();
    return p;
}

void P2PChat::setfriendID(QString friendID)
{
    if(m_friendID != friendID)
    {
        m_friendID = friendID;
        emit friendIDChanged();
    }
}

QString P2PChat::friendID()
{
    return m_friendID;
}

void P2PChat::setfriendNickname(QString friendNickname)
{
    if(m_friendNickname != friendNickname)
    {
        m_friendNickname = friendNickname;
        emit friendNicknameChanged();
    }
}

QString P2PChat::friendNickname()
{
    return m_friendNickname;
}

QList<ChatItem> &P2PChat::items()
{
    return m_list;
}

int P2PChat::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant P2PChat::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].id;
    case 1: return m_list[index.row()].name;
    case 2: return m_list[index.row()].photo;
    case 3: return m_list[index.row()].msg;
    case 4: return m_list[index.row()].time;
    case 5: return m_list[index.row()].iSend;
    default:return QVariant();
    }
}

QHash<int, QByteArray> P2PChat::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "id";
    roles[1] = "name";
    roles[2] = "photo";
    roles[3] = "msg";
    roles[4] = "time";
    roles[5] = "iSend";
    return roles;
}

void P2PChat::enterFromFriendList(int index)
{
    m_friendID = Friends::instance()->items()[index].id;
    m_friendNickname = Friends::instance()->items()[index].name;
}

void P2PChat::sendMessage(const QString &msg)
{
    auto proxy = Proxy::instance()->accountProxy();
    proxy->addP2PMessage(Account::instance()->userID().toStdString(), m_friendID.toStdString(), msg.toStdString());
    update();
}

void P2PChat::update()
{
    auto proxy = Proxy::instance()->accountProxy();
    std::vector<ChatMessage> msgs = proxy->getP2PMessages(m_friendID.toStdString(), Account::instance()->userID().toStdString());

    beginResetModel();
    m_list.clear();
    for(auto msg : msgs)
    {
        bool bIamSender = msg.senderID == Account::instance()->userID().toStdString();
        auto nick = bIamSender ? Account::instance()->nickname() : m_friendNickname;
        ChatItem item(QString::fromStdString(msg.senderID), nick, Account::instance()->getUserPhoto(msg.senderID),
                      QString::fromStdString(msg.content), QString::fromStdString(msg.time), bIamSender, true);
        m_list.append(item);
    }
    endResetModel();
}
