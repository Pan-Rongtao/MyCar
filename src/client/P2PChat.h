#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "Item.h"

class P2PChat : public QAbstractListModel
{
    Q_OBJECT
public:
    static P2PChat *instance();

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
    void sendMessage(const QString &msg);
    void update();

private:
    P2PChat();

    QList<ChatItem>  m_list;
    QString          m_friendID;
    QString          m_friendNickname;
    QString          m_friendPhoto;
};
