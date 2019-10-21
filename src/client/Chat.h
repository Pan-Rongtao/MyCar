#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "Item.h"

class P2PChat : public QAbstractListModel
{
    Q_OBJECT
public:
    static P2PChat *get();

    Q_PROPERTY(QString friendID READ friendID WRITE setfriendID NOTIFY friendIDChanged)
    Q_PROPERTY(QString friendNickname READ friendNickname WRITE setfriendNickname NOTIFY friendNicknameChanged)

    void setfriendID(QString friendID);
    QString friendID();

    void setfriendNickname(QString friendNickname);
    QString friendNickname();

    QList<ChatItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void signalUpdate();
    void friendIDChanged();
    void friendNicknameChanged();

public slots:
    void enterFromFriendList(int index);
    void enterFromNewMessage();
    void sendMessage(const QString &msg);
    void update();

private:
    P2PChat();

    QList<ChatItem>  m_list;
    QString          m_friendID;
    QString          m_friendNickname;
    QString          m_friendPhoto;
};

class GroupChat : public QAbstractListModel
{
    Q_OBJECT
public:
    static GroupChat *get();

    Q_PROPERTY(QString groupName READ groupName WRITE setgroupName NOTIFY groupNameChanged)
    Q_PROPERTY(QString groupID READ groupName WRITE setgroupID NOTIFY groupIDChanged)

    void setgroupName(QString groupName);
    QString groupName();
    void setgroupID(QString groupID);
    QString groupID();

    QList<ChatItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void signalUpdate();
    void groupNameChanged();
    void groupIDChanged();

public slots:
    void enter(int index);
    void enterFromNewMessage();
    void sendMessage(const QString &msg);
    void update();

    void modifyGroupName(const QString &name);

private:
    GroupChat();

    QList<ChatItem> m_list;
    QString         m_groupID;
    QString         m_groupName;
};

class GroupMembers : public QAbstractListModel
{
    Q_OBJECT
public:
    static GroupMembers *get();

    QList<UserItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void addMember(const QList<int> &indexs);
    void update();

private:
    GroupMembers();

    QList<UserItem>m_list;
};

class MessageList : public QAbstractListModel
{
    Q_OBJECT
public:
    static MessageList *get();

    Q_PROPERTY(bool newMessage READ newMessage WRITE setnewMessage NOTIFY newMessageChanged)
    Q_PROPERTY(QString newMessageSenderID READ newMessageSenderID WRITE setnewMessageSenderID NOTIFY newMessageSenderIDChanged)
    Q_PROPERTY(QString newMessageSenderName READ newMessageSenderName WRITE setnewMessageSenderName NOTIFY newMessageSenderNameChanged)
    Q_PROPERTY(QString newMessageContent READ newMessageContent WRITE setnewMessageContent NOTIFY newMessageContentChanged)
    Q_PROPERTY(bool newMessageIsP2p READ newMessageIsP2p WRITE setnewMessageIsP2p NOTIFY newMessageIsP2pChanged)

    void setnewMessage(bool newMessage);
    bool newMessage();

    void setnewMessageSenderID(const QString &newMessageSenderID);
    QString newMessageSenderID();

    void setnewMessageSenderName(const QString &newMessageSenderName);
    QString newMessageSenderName();

    void setnewMessageContent(const QString &newMessageContent);
    QString newMessageContent();

    void setnewMessageIsP2p(bool newMessageIsP2p);
    bool newMessageIsP2p();


    QList<ChatItem> &items();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void signalUpdate();
    void newMessageChanged();
    void newMessageSenderIDChanged();
    void newMessageSenderNameChanged();
    void newMessageContentChanged();
    void newMessageIsP2pChanged();
    void signalUpdateNewMsg(const QString &sender, const QString &msg, bool isP2P);

public slots:
    void enterChat(int index);
    void update();
    void updateNewMsg(const QString &sender, const QString &msg, bool isP2P);

private:
    MessageList();
    static bool compareItem(const ChatItem &item0, const ChatItem &item1);

    bool    m_newMessage{false};
    QString m_newMessageSenderID;
    QString m_newMessageSenderName;
    QString m_newMessageContent;
    bool    m_newMessageIsP2P{false};
    QList<ChatItem> m_list;
};
