#include "MessageList.h"
#include "Account.h"
#include "LayerManager.h"
#include "P2PChat.h"
#include "GroupChat.h"

MessageList::MessageList()
{
    QObject::connect(this, SIGNAL(signalUpdate()), this, SLOT(update()));
}

MessageList *MessageList::instance()
{
    static MessageList *p = nullptr;
    if(!p)  p = new MessageList();
    return p;
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

void MessageList::enterChat(int index)
{
    auto item = m_list[index];
    if(item.p2p)
    {
        P2PChat::instance()->setfriendID(item.id);
        P2PChat::instance()->setfriendNickname(item.name);
        LayerManager::instance()->switchPage(Type::Page_P2PChat);
    }
    else
    {
        GroupChat::instance()->setgroupID(item.id);
        GroupChat::instance()->setgroupName(item.name);
        LayerManager::instance()->switchPage(Type::Page_GroupChat);
    }
}

void MessageList::update()
{
    beginResetModel();
    m_list.clear();
    auto proxy = Proxy::instance()->accountProxy();
    std::vector<std::string> groups;
    proxy->getBelongGroups(Account::instance()->userID().toStdString(), groups);
    for(auto &groupID : groups)
    {
        GroupInfo info;
        proxy->getGroupInfo(groupID, info);
        std::vector<GroupMessage> msgs;
        proxy->getGroupMessage(groupID, msgs);
        if(!msgs.empty())
        {
            auto lastMsg = msgs.back();
            bool bIamSender = lastMsg.fromID == Account::instance()->userID().toStdString();
            AccountInfo fromInfo;
            proxy->getAccountInfo(lastMsg.fromID, fromInfo);
            ChatItem item(QString::fromStdString(info.ID), QString::fromStdString(info.name), Account::instance()->getUserPhoto(groupID),
                          QString::fromStdString(fromInfo.nickname + ":" + lastMsg.msg), QString::fromStdString(lastMsg.time), bIamSender, false);
            m_list.append(item);
        }
    }

    std::vector<std::string> friends;
    proxy->getFriends(Account::instance()->userID().toStdString(), friends);
    for(auto &frd : friends)
    {
        std::vector<P2PMessage> msgs;
        proxy->getP2PMessage(frd, Account::instance()->userID().toStdString(), msgs);
        if(!msgs.empty())
        {
            auto lastMsg = msgs.back();
            bool bIamSender = lastMsg.fromID == Account::instance()->userID().toStdString();
            auto id = bIamSender ? lastMsg.toID : lastMsg.fromID;
            AccountInfo fromInfo;
            proxy->getAccountInfo(id, fromInfo);
            ChatItem item(QString::fromStdString(id), QString::fromStdString(fromInfo.nickname), Account::instance()->getUserPhoto(frd),
                          QString::fromStdString(lastMsg.msg), QString::fromStdString(lastMsg.time), bIamSender, true);
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
