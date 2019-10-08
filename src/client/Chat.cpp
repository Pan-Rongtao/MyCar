#include "Chat.h"

Chat::Chat()
{

}

QList<ChatItem> &Chat::items()
{
    return m_list;
}

int Chat::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant Chat::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> Chat::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "nickname";
    roles[1] = "photo";
    roles[2] = "msg";
    roles[3] = "time";
    roles[4] = "iSend";
    return roles;
}
