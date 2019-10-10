#include "P2PChat.h"

P2PChat::P2PChat()
{

}

void P2PChat::setwho(QString who)
{
    if(m_who != who)
    {
        m_who = who;
        emit whoChanged();
    }
}

QString P2PChat::who()
{
    return m_who;
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

}
