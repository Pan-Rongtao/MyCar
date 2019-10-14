#include "Users.h"
#include "Account.h"
#include "Proxy.h"

Users::Users()
{

}

Users *Users::instance()
{
    static Users *p = nullptr;
    if(!p)  p = new Users();
    return p;
}

QList<UserItem> &Users::items()
{
    return m_list;
}

int Users::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    return m_list.size();
}

QVariant Users::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> Users::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "id";
    roles[1] = "name";
    roles[2] = "photo";
    return roles;
}

void Users::update()
{
    beginResetModel();
    m_list.clear();
    std::vector<AccountInfo> infos;
    Proxy::instance()->accountProxy()->queryAllAccountInfo(infos);
    for(auto &info : infos)
    {
        Account::instance()->saveUserPhoto(info.userID, info.photo);
        UserItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), Account::instance()->getUserPhoto(info.userID));
        m_list.append(item);
    }
    endResetModel();
}
