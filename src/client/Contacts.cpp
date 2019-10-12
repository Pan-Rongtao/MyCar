#include "Contacts.h"
#include "Users.h"
#include "Account.h"

Contacts::Contacts()
{
}

Contacts *Contacts::instance()
{
    static Contacts *p = nullptr;
    if(!p)  p = new Contacts();
    return p;
}

QList<CantactItem> &Contacts::items()
{
    return m_list;
}

void Contacts::add(const QList<int> &indexs)
{
    auto userID = Account::instance()->userID();
    for(auto i : indexs)
    {
        auto friendID = Users::instance()->items()[i].userID;
        if(friendID != userID)
            Proxy::instance()->accountProxy()->addContacts(userID.toStdString(), friendID.toStdString());
    }
    update();
}

void Contacts::remove(int index)
{
    auto userID = Account::instance()->userID();
    auto friendID = m_list[index].userID;
    Proxy::instance()->accountProxy()->removeContacts(userID.toStdString(), friendID.toStdString());
    update();
}

void Contacts::update()
{
    beginResetModel();
    m_list.clear();
    std::vector<std::string> friends;
    Proxy::instance()->accountProxy()->getContacts(Account::instance()->userID().toStdString(), friends);
    for(auto & friendID : friends)
    {
        AccountInfo info;
        Proxy::instance()->accountProxy()->getAccountInfo(friendID, info);
        Account::instance()->saveUserPhoto(info.userID, info.photo);
        CantactItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), Account::instance()->getUserPhoto(info.userID));
        m_list.append(item);
    }
    endResetModel();
}

int Contacts::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    return m_list.size();
}

QVariant Contacts::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].userID;
    case 1: return m_list[index.row()].nickname;
    case 2: return m_list[index.row()].photo;
    default:return QVariant();
    }
}

QHash<int, QByteArray> Contacts::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "userID";
    roles[1] = "nickname";
    roles[2] = "photo";
    return roles;
}
