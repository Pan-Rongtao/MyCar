#include "Groups.h"
#include <QPixmap>
#include <QPainter>
#include <QFile>
#include "Account.h"
#include "Proxy.h"
#include "Friends.h"

Groups::Groups()
{

}

Groups *Groups::instance()
{
    static Groups *p = nullptr;
    if(!p)  p = new Groups();
    return p;
}

QList<UserItem> &Groups::items()
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
    case 0: return m_list[index.row()].id;
    case 1: return m_list[index.row()].name;
    case 2: return m_list[index.row()].photo;
    default:return QVariant();
    }
}

QHash<int, QByteArray> Groups::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "id";
    roles[1] = "name";
    roles[2] = "photo";
    return roles;
}

void Groups::create(const QList<int> &indexs)
{
    auto proxy = Proxy::instance()->accountProxy();
    QString name;
    QPixmap photo(100, 100);
    photo.fill(QColor(205, 205, 205));
    QPainter painter(&photo);
    int w = photo.width() / 3;
    int h = photo.height() / 3;
    QPixmap img;
    bool b = img.load(Account::instance()->getUserPhoto(Account::instance()->userID().toStdString()));
    painter.drawPixmap(0, 0, w, h, img);
    auto friends = Friends::instance()->items();
    for(auto i = 0; i != indexs.size(); ++i)
    {
        if(i <= 2)
            name += (friends[indexs[i]].name + ",");
        QPixmap img;
        bool b = img.load(Account::instance()->getUserPhoto(friends[indexs[i]].id.toStdString()));
        int x = (i + 1) % 3 * w;
        int y = (i + 1) / 3 * h;
        painter.drawPixmap(x, y, w, h, img);
    }
    name = name.left(name.length() - 1) + "...";
    b = photo.toImage().save("grouptemp.jpg");
    QFile f("grouptemp.jpg");
    b = f.open(QFile::ReadOnly);
    auto buffer = f.readAll();
    std::string groupID = proxy->addGroup(name.toStdString(), std::string(buffer.data(), buffer.size()));
    proxy->addGroupMember(groupID, Account::instance()->userID().toStdString());
    for(auto index : indexs)
    {
        auto addMember = friends[index];
        proxy->addGroupMember(groupID, addMember.id.toStdString());
    }
    update();
}

void Groups::remove(int index)
{
    auto proxy = Proxy::instance()->accountProxy();
    proxy->removeGroupMember(m_list[index].id.toStdString(), Account::instance()->userID().toStdString());
    update();
}

void Groups::update()
{
    auto proxy = Proxy::instance()->accountProxy();
    std::vector<std::string> groups = proxy->getBelongGroups(Account::instance()->userID().toStdString());

    beginResetModel();
    m_list.clear();
    for(auto &groupID : groups)
    {
        GroupInfo info = proxy->getGroupInfo(groupID);
        Account::instance()->saveUserPhoto(info.groupID, info.photo);
        UserItem item(QString::fromStdString(info.groupID), QString::fromStdString(info.name), Account::instance()->getUserPhoto(info.groupID));
        m_list.append(item);
    }
    endResetModel();
}
