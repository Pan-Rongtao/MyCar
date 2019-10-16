#include "GroupChat.h"
#include <QFile>
#include "Proxy.h"
#include "Account.h"
#include "Friends.h"
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

void GroupChat::setgroupID(QString groupID)
{
    if(m_groupID != groupID)
    {
        m_groupID = groupID;
        emit groupIDChanged();
    }
}

QString GroupChat::groupID()
{
    return m_groupID;
}

QList<ChatItem> &GroupChat::items()
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
    case 0: return m_list[index.row()].id;
    case 1: return m_list[index.row()].name;
    case 2: return m_list[index.row()].photo;
    case 3: return m_list[index.row()].msg;
    case 4: return m_list[index.row()].time;
    case 5: return m_list[index.row()].iSend;
    default:return QVariant();
    }
}

QHash<int, QByteArray> GroupChat::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "id";
    roles[1] = "name";
    roles[2] = "photo";
    roles[3] = "msg";
    roles[4] = "time";
    roles[5] = "iSend";
    return roles;
}

void GroupChat::enter(int index)
{
    m_groupID = Groups::instance()->items()[index].id;
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
    std::vector<ChatMessage> msgs = proxy->getGroupMessages(m_groupID.toStdString());

    beginResetModel();
    m_list.clear();
    for(auto msg : msgs)
    {
        bool bIamSender = msg.senderID == Account::instance()->userID().toStdString();
        UserInfo info = proxy->getUserInfo(msg.senderID);
        ChatItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), Account::instance()->getUserPhoto(msg.senderID),
                      QString::fromStdString(msg.content), QString::fromStdString(msg.time), bIamSender, false);
        m_list.append(item);
    }
    endResetModel();
}

void GroupChat::modifyGroupName(const QString &name)
{
    auto proxy = Proxy::instance()->accountProxy();
    proxy->setGroupName(m_groupID.toStdString(), name.toStdString());
    setgroupName(name);
}

//////////////////////
GroupMembers *GroupMembers::instance()
{
    static GroupMembers *p = nullptr;
    if(!p)  p = new GroupMembers();
    return p;
}

QList<UserItem> &GroupMembers::items()
{
    return m_list;
}

int GroupMembers::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant GroupMembers::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> GroupMembers::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "id";
    roles[1] = "name";
    roles[2] = "photo";
    return roles;
}

void GroupMembers::addMember(const QList<int> &indexs)
{
    auto proxy = Proxy::instance()->accountProxy();
    auto friends = Friends::instance()->items();
    for(auto index : indexs)
    {
        auto addMember = friends[index];
        proxy->addGroupMember(GroupChat::instance()->groupID().toStdString(), addMember.id.toStdString());
    }
    update();
}

void GroupMembers::update()
{
    auto proxy = Proxy::instance()->accountProxy();
    std::vector<std::string> members = proxy->getGroupMembers(GroupChat::instance()->groupID().toStdString());

    beginResetModel();
    m_list.clear();
    for(auto & userID : members)
    {
        UserInfo info = Proxy::instance()->accountProxy()->getUserInfo(userID);
        Account::instance()->saveUserPhoto(info.userID, info.photo);
        UserItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), Account::instance()->getUserPhoto(info.userID));
        m_list.append(item);
    }
    m_list.append(UserItem("", "", "qrc:/images/addmember.png"));
    endResetModel();
}

GroupMembers::GroupMembers()
{

}
