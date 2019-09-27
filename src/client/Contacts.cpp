#include "Contacts.h"

Contacts::Contacts()
{

}

QList<CantactItem> &Contacts::items()
{
    return m_list;
}

int Contacts::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant Contacts::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].nickname;
    case 1: return m_list[index.row()].photo;
    default:return QVariant();
    }
}

QHash<int, QByteArray> Contacts::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "nickname";
    roles[1] = "photo";
    return roles;
}
