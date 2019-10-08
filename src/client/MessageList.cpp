#include "MessageList.h"

MessageList::MessageList()
{

}

QList<MessageItem> &MessageList::items()
{
    return m_list;
}

int MessageList::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant MessageList::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].userID;
    case 1: return m_list[index.row()].photo;
    case 2: return m_list[index.row()].from;
    case 3: return m_list[index.row()].msg;
    case 4: return m_list[index.row()].time;
    default:return QVariant();
    }
}

QHash<int, QByteArray> MessageList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "userID";
    roles[1] = "photo";
    roles[2] = "from";
    roles[3] = "msg";
    roles[4] = "time";
    return roles;
}
