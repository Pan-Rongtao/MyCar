#include "Contacts.h"
#include <QDir>
#include <QFile>
#include <QPixmap>
#include <QPainter>
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

void Contacts::addFriend(const QList<int> &indexs)
{
    auto userID = Account::instance()->userID();
    for(auto i : indexs)
    {
        auto friendID = Users::instance()->items()[i].userID;
        if(friendID != userID)
            Proxy::instance()->accountProxy()->addContacts(userID.toStdString(), friendID.toStdString());
    }
    updateFriend();
}

void Contacts::removeFriend(int index)
{
    auto userID = Account::instance()->userID();
    auto friendID = m_list[index].userID;
    Proxy::instance()->accountProxy()->removeContacts(userID.toStdString(), friendID.toStdString());
    updateFriend();
}

void Contacts::updateFriend()
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

void Contacts::createGroup(const QList<int> &indexs)
{
    auto proxy = Proxy::instance()->accountProxy();
    QString name;
    QPixmap photo(300, 300);
    int w = photo.width() / 3;
    int h = photo.height() / 3;
    QPainter painter(&photo);
    for(auto i = 0; i != indexs.size(); ++i)
    {
        name += m_list[i].nickname;
        if(i != indexs.size() - 1)
            name += ",";
        QPixmap img;
        bool b = img.load(Account::instance()->getUserPhoto(m_list[i].userID.toStdString()));
        int x = i % 3 * w;
        int y = i / 3 * h;
        painter.drawPixmap(x, y, w, h, img);
    }
    auto p = photo.toImage().bits();
    std::string s((char *)p, 10);
    proxy->addGroup(name.toStdString(), s);
}

void Contacts::removeGroup(int index)
{

}

void Contacts::updateGroup()
{

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
