#include "GroupChat.h"
#include <QFile>
#include "Proxy.h"
#include "Account.h"
#include "Contacts.h"
#include "Groups.h"

GroupChat::GroupChat()
{
    QObject::connect(this, SIGNAL(signalUpdate()), this, SLOT(update()));
}

GroupChat *GroupChat::instance()
{
    static GroupChat *p = nullptr;
    if(!p)  p = new GroupChat();
    return p;
}

void GroupChat::setgroupName(QString groupName)
{
    if(m_groupName != groupName)
    {
        m_groupName = groupName;
        emit groupNameChanged();
    }
}

QString GroupChat::groupName()
{
    return m_groupName;
}

QList<GroupChatItem> &GroupChat::items()
{
    return m_list;
}

int GroupChat::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant GroupChat::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].nickname;
    case 1: return m_list[index.row()].photo;
    case 2: return m_list[index.row()].msg;
    case 3: return m_list[index.row()].time;
    case 4: return m_list[index.row()].iSend;
    default:return QVariant();
    }
}

QHash<int, QByteArray> GroupChat::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "nickname";
    roles[1] = "photo";
    roles[2] = "msg";
    roles[3] = "time";
    roles[4] = "iSend";
    return roles;
}

void GroupChat::enter(int index)
{
    m_groupID = Groups::instance()->items()[index].groupID;
    m_groupName = Groups::instance()->items()[index].name;
}

void GroupChat::sendMessage(const QString &msg)
{
    auto proxy = Proxy::instance()->accountProxy();
    proxy->addGroupMessage(m_groupID.toStdString(), Account::instance()->userID().toStdString(), msg.toStdString());
    update();
}

void GroupChat::update()
{
    auto proxy = Proxy::instance()->accountProxy();
    std::vector<GroupMessage> msgs;
    proxy->getGroupMessage(m_groupID.toStdString(), msgs);
    beginResetModel();
    m_list.clear();
    for(auto msg : msgs)
    {
        bool bIamSender = msg.fromID == Account::instance()->userID().toStdString();
        AccountInfo info;
        proxy->getAccountInfo(msg.fromID, info);
        auto nick = QString::fromStdString(info.nickname);
        auto photo = Account::instance()->getUserPhoto(msg.fromID);
        GroupChatItem item(nick, photo, QString::fromStdString(msg.msg), QString::fromStdString(msg.time), bIamSender);
        m_list.append(item);
    }
    endResetModel();
}
