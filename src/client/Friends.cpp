#include "Friends.h"
#include "Users.h"
#include "Account.h"

Friends::Friends()
{
}

Friends *Friends::instance()
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
    auto userID = Account::instance()->userID();
    for(auto i : indexs)
    {
        auto friendID = Users::instance()->items()[i].id;
        if(friendID != userID)
            Proxy::instance()->accountProxy()->addFriend(userID.toStdString(), friendID.toStdString());
    }
    update();
}

void Friends::remove(int index)
{
    auto userID = Account::instance()->userID();
    auto friendID = m_list[index].id;
    Proxy::instance()->accountProxy()->removeFriend(userID.toStdString(), friendID.toStdString());
    update();
}

void Friends::update()
{
    beginResetModel();
    m_list.clear();
    std::vector<std::string> friends;
    Proxy::instance()->accountProxy()->getFriends(Account::instance()->userID().toStdString(), friends);
    for(auto & friendID : friends)
    {
        AccountInfo info;
        Proxy::instance()->accountProxy()->getAccountInfo(friendID, info);
        Account::instance()->saveUserPhoto(info.userID, info.photo);
        UserItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), Account::instance()->getUserPhoto(info.userID));
        m_list.append(item);
    }
    endResetModel();
}
