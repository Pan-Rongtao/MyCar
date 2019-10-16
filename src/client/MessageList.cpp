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
    auto proxy = Proxy::instance()->accountProxy();
    std::vector<std::string> groups = proxy->getBelongGroups(Account::instance()->userID().toStdString());

    beginResetModel();
    m_list.clear();
    for(auto &groupID : groups)
    {
        GroupInfo info = proxy->getGroupInfo(groupID);
        std::vector<ChatMessage> msgs = proxy->getGroupMessages(groupID);
        if(!msgs.empty())
        {
            auto lastMsg = msgs.back();
            bool bIamSender = lastMsg.senderID == Account::instance()->userID().toStdString();
            UserInfo senderInfo = proxy->getUserInfo(lastMsg.senderID);
            ChatItem item(QString::fromStdString(info.groupID), QString::fromStdString(info.name), Account::instance()->getUserPhoto(info.groupID),
                          QString::fromStdString(senderInfo.nickname + ":" + lastMsg.content), QString::fromStdString(lastMsg.time), bIamSender, false);
            m_list.append(item);
        }
    }

    std::vector<std::string> friends = proxy->getFriends(Account::instance()->userID().toStdString());
    for(auto &frd : friends)
    {
        std::vector<ChatMessage> msgs = proxy->getP2PMessages(frd, Account::instance()->userID().toStdString());
        if(!msgs.empty())
        {
            auto lastMsg = msgs.back();
            bool bIamSender = lastMsg.senderID == Account::instance()->userID().toStdString();
            auto id = bIamSender ? lastMsg.receiverID : lastMsg.senderID;
            UserInfo fromInfo = proxy->getUserInfo(id);
            ChatItem item(QString::fromStdString(id), QString::fromStdString(fromInfo.nickname), Account::instance()->getUserPhoto(frd),
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
