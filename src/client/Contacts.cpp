#include "Contacts.h"
#include "Users.h"
#include "Singleton.h"
#include "Account.h"
#include <QDir>
#include <QFile>

Contacts::Contacts()
{

}

QList<CantactItem> &Contacts::items()
{
    return m_list;
}

void Contacts::addFromUserList(const QList<int> &indexs)
{
    auto users = nb::Singleton<Users>::instance()->items();
    auto userID = nb::Singleton<Account>::instance()->userID();

    for(auto i : indexs)
    {
        auto friendID = users[i].userID;
        if(friendID != userID)
            nb::Singleton<Account>::instance()->addContacts(userID, friendID);
    }
    update();
}

void Contacts::remove(int index)
{
    auto userID = nb::Singleton<Account>::instance()->userID();
    auto friendID = m_list[index].userID;
    nb::Singleton<Account>::instance()->removeContacts(userID, friendID);
    update();
}

void Contacts::update()
{
    QDir usersDir;
    usersDir.mkdir("friend");

    beginResetModel();
    m_list.clear();
    std::vector<std::string> friends;
    nb::Singleton<Account>::instance()->getContacts(nb::Singleton<Account>::instance()->userID(), friends);
    for(auto & friendID : friends)
    {
        AccountInfo info;
        nb::Singleton<Account>::instance()->getInfo(QString::fromStdString(friendID), info);
        QString photoPath = "friend/" + QString::fromStdString(info.userID) + ".jpg";
        QFile f(photoPath);
        if(f.open(QFile::WriteOnly))
            f.write(info.photo.data(), info.photo.size());
        CantactItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), photoPath);
        m_list.append(item);
    }
    endResetModel();
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
