#pragma once

#include <QObject>
#include <QAbstractListModel>
#include "Proxy.h"

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

    void setgroupName(QString groupName);
    QString groupName();

    QList<GroupChatItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void signalUpdate();
    void groupNameChanged();

public slots:
    void enter(int index);
    void sendMessage(const QString &msg);
    void update();

private:
    GroupChat();

    QList<GroupChatItem>m_list;
    QString             m_groupID;
    QString             m_groupName;
};
