#include "Chat.h"
#include <QFile>
#include "Proxy.h"
#include "Account.h"
#include "Groups.h"
#include "LayerManager.h"

P2PChat::P2PChat()
{
    QObject::connect(this, SIGNAL(signalUpdate()), this, SLOT(update()));
}

P2PChat *P2PChat::get()
{
    static P2PChat *p = nullptr;
    if(!p)  p = new P2PChat();
    return p;
}

void P2PChat::setfriendID(QString friendID)
{
    if(m_friendID != friendID)
    {
        m_friendID = friendID;
        emit friendIDChanged();
    }
}

QString P2PChat::friendID()
{
    return m_friendID;
}

void P2PChat::setfriendNickname(QString friendNickname)
{
    if(m_friendNickname != friendNickname)
    {
        m_friendNickname = friendNickname;
        emit friendNicknameChanged();
    }
}

QString P2PChat::friendNickname()
{
    return m_friendNickname;
}

QList<ChatItem> &P2PChat::items()
{
    return m_list;
}

int P2PChat::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant P2PChat::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> P2PChat::roleNames() const
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

void P2PChat::enterFromFriendList(int index)
{
    m_friendID = Friends::get()->items()[index].id;
    m_friendNickname = Friends::get()->items()[index].name;
}

void P2PChat::enterFromNewMessage()
{
    m_friendID = MessageList::get()->newMessageSenderID();
    m_friendNickname = MessageList::get()->newMessageSenderName();
}

void P2PChat::sendMessage(const QString &msg)
{
    auto proxy = Proxy::get()->accountProxy();
    proxy->addP2PMessage(Account::get()->userID().toStdString(), m_friendID.toStdString(), msg.toStdString());
    update();
}

void P2PChat::update()
{
    auto proxy = Proxy::get()->accountProxy();
    std::vector<ChatMessage> msgs = proxy->getP2PMessages(m_friendID.toStdString(), Account::get()->userID().toStdString());

    beginResetModel();
    m_list.clear();
    for(auto msg : msgs)
    {
        bool bIamSender = msg.senderID == Account::get()->userID().toStdString();
        auto nick = bIamSender ? Account::get()->nickname() : m_friendNickname;
        ChatItem item(QString::fromStdString(msg.senderID), nick, Account::get()->getUserPhoto(msg.senderID),
                      QString::fromStdString(msg.content), QString::fromStdString(msg.time), bIamSender, true);
        m_list.append(item);
    }
    endResetModel();
}

GroupChat::GroupChat()
{
    QObject::connect(this, SIGNAL(signalUpdate()), this, SLOT(update()));
}

GroupChat *GroupChat::get()
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
    m_groupID = Groups::get()->items()[index].id;
    m_groupName = Groups::get()->items()[index].name;
}

void GroupChat::enterFromNewMessage()
{
    m_groupID = MessageList::get()->newMessageSenderID();
    m_groupName = MessageList::get()->newMessageSenderName();
}

void GroupChat::sendMessage(const QString &msg)
{
    auto proxy = Proxy::get()->accountProxy();
    proxy->addGroupMessage(m_groupID.toStdString(), Account::get()->userID().toStdString(), msg.toStdString());
    update();
}

void GroupChat::update()
{
    auto proxy = Proxy::get()->accountProxy();
    std::vector<ChatMessage> msgs = proxy->getGroupMessages(m_groupID.toStdString());

    beginResetModel();
    m_list.clear();
    for(auto msg : msgs)
    {
        bool bIamSender = msg.senderID == Account::get()->userID().toStdString();
        UserInfo info = proxy->getUserInfo(msg.senderID);
        ChatItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), Account::get()->getUserPhoto(msg.senderID),
                      QString::fromStdString(msg.content), QString::fromStdString(msg.time), bIamSender, false);
        m_list.append(item);
    }
    endResetModel();
}

void GroupChat::modifyGroupName(const QString &name)
{
    auto proxy = Proxy::get()->accountProxy();
    proxy->setGroupName(m_groupID.toStdString(), name.toStdString());
    setgroupName(name);
}

//////////////////////
GroupMembers *GroupMembers::get()
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
    auto proxy = Proxy::get()->accountProxy();
    auto friends = Friends::get()->items();
    for(auto index : indexs)
    {
        auto addMember = friends[index];
        proxy->addGroupMember(GroupChat::get()->groupID().toStdString(), addMember.id.toStdString());
    }
    update();
}

void GroupMembers::update()
{
    auto proxy = Proxy::get()->accountProxy();
    std::vector<std::string> members = proxy->getGroupMembers(GroupChat::get()->groupID().toStdString());

    beginResetModel();
    m_list.clear();
    for(auto & userID : members)
    {
        UserInfo info = Proxy::get()->accountProxy()->getUserInfo(userID);
        Account::get()->saveUserPhoto(info.userID, info.photo);
        UserItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), Account::get()->getUserPhoto(info.userID));
        m_list.append(item);
    }
    m_list.append(UserItem("", "", "qrc:/images/addmember.png"));
    endResetModel();
}

GroupMembers::GroupMembers()
{

}

/////////////
MessageList::MessageList()
{
    QObject::connect(this, SIGNAL(signalUpdateNewMsg(const QString &, const QString &, bool)), this, SLOT(updateNewMsg(const QString &, const QString &, bool)));
    QObject::connect(this, SIGNAL(signalUpdate()), this, SLOT(update()));
}

MessageList *MessageList::get()
{
    static MessageList *p = nullptr;
    if(!p)  p = new MessageList();
    return p;
}

void MessageList::setnewMessage(bool newMessage)
{
    m_newMessage = newMessage;
    emit newMessageChanged();
}

bool MessageList::newMessage()
{
    return m_newMessage;
}

void MessageList::setnewMessageSenderID(const QString &newMessageSenderID)
{
    if(m_newMessageSenderID != newMessageSenderID)
    {
        m_newMessageSenderID = newMessageSenderID;
        emit newMessageSenderIDChanged();
    }
}

QString MessageList::newMessageSenderID()
{
    return m_newMessageSenderID;
}

void MessageList::setnewMessageSenderName(const QString &newMessageSenderName)
{
    if(m_newMessageSenderName != newMessageSenderName)
    {
        m_newMessageSenderName = newMessageSenderName;
        emit newMessageSenderNameChanged();
    }
}

QString MessageList::newMessageSenderName()
{
    return m_newMessageSenderName;
}

void MessageList::setnewMessageContent(const QString &newMessageContent)
{
    if(m_newMessageContent != newMessageContent)
    {
        m_newMessageContent = newMessageContent;
        emit newMessageContentChanged();
    }
}

QString MessageList::newMessageContent()
{
    return m_newMessageContent;
}

void MessageList::setnewMessageIsP2p(bool newMessageIsP2p)
{
    if(m_newMessageIsP2P != newMessageIsP2p)
    {
        m_newMessageIsP2P = newMessageIsP2p;
        emit newMessageIsP2pChanged();
    }
}

bool MessageList::newMessageIsP2p()
{
    return m_newMessageIsP2P;
}

QList<ChatItem> &MessageList::items()
{
    return m_list;
}

int MessageList::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant MessageList::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> MessageList::roleNames() const
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

void MessageList ::updateNewMsg(const QString &sender, const QString &msg, bool isP2P)
{
    auto proxy = Proxy::get()->accountProxy();
    UserInfo info = proxy->getUserInfo(sender.toStdString());
    setnewMessage(true);
    setnewMessageSenderID(QString::fromStdString(info.userID));
    setnewMessageSenderName(QString::fromStdString(info.nickname));
    setnewMessageContent(msg);
    setnewMessageIsP2p(isP2P);
}

void MessageList::enterChat(int index)
{
    auto item = m_list[index];
    if(item.p2p)
    {
        P2PChat::get()->setfriendID(item.id);
        P2PChat::get()->setfriendNickname(item.name);
        LayerManager::get()->switchPage(Type::Page_P2PChat);
    }
    else
    {
        GroupChat::get()->setgroupID(item.id);
        GroupChat::get()->setgroupName(item.name);
        LayerManager::get()->switchPage(Type::Page_GroupChat);
    }
}

void MessageList::update()
{
    auto proxy = Proxy::get()->accountProxy();
    std::vector<std::string> groups = proxy->getBelongGroups(Account::get()->userID().toStdString());

    beginResetModel();
    m_list.clear();
    for(auto &groupID : groups)
    {
        GroupInfo info = proxy->getGroupInfo(groupID);
        std::vector<ChatMessage> msgs = proxy->getGroupMessages(groupID);
        if(!msgs.empty())
        {
            auto lastMsg = msgs.back();
            bool bIamSender = lastMsg.senderID == Account::get()->userID().toStdString();
            UserInfo senderInfo = proxy->getUserInfo(lastMsg.senderID);
            ChatItem item(QString::fromStdString(info.groupID), QString::fromStdString(info.name), Account::get()->getUserPhoto(info.groupID),
                          QString::fromStdString(senderInfo.nickname + ":" + lastMsg.content), QString::fromStdString(lastMsg.time), bIamSender, false);
            m_list.append(item);
        }
    }

    std::vector<std::string> friends = proxy->getFriends(Account::get()->userID().toStdString());
    for(auto &frd : friends)
    {
        std::vector<ChatMessage> msgs = proxy->getP2PMessages(frd, Account::get()->userID().toStdString());
        if(!msgs.empty())
        {
            auto lastMsg = msgs.back();
            bool bIamSender = lastMsg.senderID == Account::get()->userID().toStdString();
            auto id = bIamSender ? lastMsg.receiverID : lastMsg.senderID;
            UserInfo fromInfo = proxy->getUserInfo(id);
            ChatItem item(QString::fromStdString(id), QString::fromStdString(fromInfo.nickname), Account::get()->getUserPhoto(frd),
                          QString::fromStdString(lastMsg.content), QString::fromStdString(lastMsg.time), bIamSender, true);
            m_list.append(item);
        }
    }
    qSort (m_list.begin(), m_list.end(), MessageList::compareItem);
    endResetModel();
}

bool MessageList::compareItem(const ChatItem &item0, const ChatItem &item1)
{
    return item0.time > item1.time;
}
