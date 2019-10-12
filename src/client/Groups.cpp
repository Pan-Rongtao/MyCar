#include "Groups.h"
#include <QPixmap>
#include <QPainter>
#include <QFile>
#include "Account.h"
#include "Proxy.h"
#include "Contacts.h"

Groups::Groups()
{

}

Groups *Groups::instance()
{
    static Groups *p = nullptr;
    if(!p)  p = new Groups();
    return p;
}

QList<GroupItem> &Groups::items()
{
    return m_list;
}

int Groups::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    return m_list.size();
}

QVariant Groups::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].groupID;
    case 1: return m_list[index.row()].name;
    case 2: return m_list[index.row()].photo;
    default:return QVariant();
    }
}

QHash<int, QByteArray> Groups::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "groupID";
    roles[1] = "name";
    roles[2] = "photo";
    return roles;
}

void Groups::create(const QList<int> &indexs)
{
    auto proxy = Proxy::instance()->accountProxy();
    QString name;
    QPixmap photo(100, 100);
    QPainter painter(&photo);
    int w = photo.width() / 3;
    int h = photo.height() / 3;
    QPixmap img;
    bool b = img.load(Account::instance()->getUserPhoto(Account::instance()->userID().toStdString()));
    painter.drawPixmap(0, 0, w, h, img);
    auto friends = Contacts::instance()->items();
    for(auto i = 0; i != indexs.size(); ++i)
    {
        if(i <= 2)
        {
            name += friends[indexs[i]].nickname;
            name += ",";
        }
        QPixmap img;
        bool b = img.load(Account::instance()->getUserPhoto(friends[indexs[i]].userID.toStdString()));
        int x = (i + 1) % 3 * w;
        int y = (i + 1) / 3 * h;
        painter.drawPixmap(x, y, w, h, img);
    }
    name += "...";
    b = photo.toImage().save("grouptemp.jpg");
    QFile f("grouptemp.jpg");
    b = f.open(QFile::ReadOnly);
    auto buffer = f.readAll();
    std::string groupID = proxy->addGroup(name.toStdString(), std::string(buffer.data(), buffer.size()));
    proxy->addGroupMember(groupID, Account::instance()->userID().toStdString());
    for(auto index : indexs)
    {
        auto addMember = friends[index];
        proxy->addGroupMember(groupID, addMember.userID.toStdString());
    }
    update();
}

void Groups::remove(int index)
{
    auto proxy = Proxy::instance()->accountProxy();
    proxy->removeGroupMember(m_list[index].groupID.toStdString(), Account::instance()->userID().toStdString());
    update();
}

void Groups::update()
{
    auto proxy = Proxy::instance()->accountProxy();
    beginResetModel();
    m_list.clear();
    std::vector<std::string> groups;
    proxy->getBelongGroups(Account::instance()->userID().toStdString(), groups);
    for(auto &groupID : groups)
    {
        GroupInfo info;
        proxy->getGroupInfo(groupID, info);
        Account::instance()->saveUserPhoto(info.ID, info.photo);
        GroupItem item(QString::fromStdString(info.ID), QString::fromStdString(info.name), Account::instance()->getUserPhoto(info.ID));
        m_list.append(item);
    }
    endResetModel();
}
