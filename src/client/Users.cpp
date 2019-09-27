#include "Users.h"

Users::Users()
{

}

QList<UserItem> &Users::items()
{
    return m_list;
}

int Users::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant Users::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].userID;
    case 1: return m_list[index.row()].nickname;
    default:return QVariant();
    }
}

QHash<int, QByteArray> Users::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "userID";
    roles[1] = "nickname";
    return roles;
}
