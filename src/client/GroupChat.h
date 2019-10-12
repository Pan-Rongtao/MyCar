#pragma once

#include <QObject>
#include <QAbstractListModel>
#include "Proxy.h"
#include "Users.h"

class GroupChatItem
{
public:
    GroupChatItem(const QString &_nickname, const QString &_photo, const QString &_msg, const QString &_time, bool _iSend)
        : nickname(_nickname)
        , photo(_photo)
        , msg(_msg)
        , time(_time)
        , iSend(_iSend)
    {}

    QString nickname;
    QString photo;
    QString msg;
    QString time;
    bool    iSend;
};

class GroupChat : public QAbstractListModel
{
    Q_OBJECT
public:
    static GroupChat *instance();

    Q_PROPERTY(QString groupName READ groupName WRITE setgroupName NOTIFY groupNameChanged)
    Q_PROPERTY(QString groupID READ groupName WRITE setgroupID NOTIFY groupIDChanged)

    void setgroupName(QString groupName);
    QString groupName();
    void setgroupID(QString groupID);
    QString groupID();

    QList<GroupChatItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void signalUpdate();
    void groupNameChanged();
    void groupIDChanged();

public slots:
    void enter(int index);
    void sendMessage(const QString &msg);
    void update();

    void modifyGroupName(const QString &name);

private:
    GroupChat();

    QList<GroupChatItem>m_list;
    QString             m_groupID;
    QString             m_groupName;
};

class GroupMembers : public QAbstractListModel
{
    Q_OBJECT
public:
    static GroupMembers *instance();

    QList<UserItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void update();

private:
    GroupMembers();

    QList<UserItem>m_list;
};
