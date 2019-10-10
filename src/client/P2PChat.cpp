#include "P2PChat.h"
#include "Proxy.h"
#include "Account.h"

P2PChat::P2PChat()
{

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

QList<P2PChatItem> &P2PChat::items()
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
    case 0: return m_list[index.row()].nickname;
    case 1: return m_list[index.row()].photo;
    case 2: return m_list[index.row()].msg;
    case 3: return m_list[index.row()].time;
    case 4: return m_list[index.row()].iSend;
    default:return QVariant();
    }
}

QHash<int, QByteArray> P2PChat::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "nickname";
    roles[1] = "photo";
    roles[2] = "msg";
    roles[3] = "time";
    roles[4] = "iSend";
    return roles;
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
    std::vector<P2PMessage> msgs;
    proxy->getP2PMessage(m_friendID.toStdString(), Account::instance()->userID().toStdString(), msgs);
    for(auto msg : msgs)
    {

    }
}
