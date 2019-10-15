#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "Item.h"

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
    static GroupMembers *instance();

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
