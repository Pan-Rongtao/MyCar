#ifndef P2PChat_H
#define P2PChat_H

#include <QObject>
#include <QAbstractListModel>
#include "Proxy.h"

class P2PChatItem
{
public:
    P2PChatItem(const QString &_nickname, const QString &_photo, const QString &_msg, const QString &_time, bool _iSend)
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

class P2PChat : public QAbstractListModel
{
    Q_OBJECT
public:
    static P2PChat *instance();

    Q_PROPERTY(QString friendNickname READ friendNickname WRITE setfriendNickname NOTIFY friendNicknameChanged)

    void setfriendNickname(QString friendNickname);
    QString friendNickname();

    QList<P2PChatItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void signalUpdate();
    void friendNicknameChanged();

public slots:
    void enter(int friendRowIndex);
    void sendMessage(const QString &msg);
    void update();

private:
    P2PChat();

    QList<P2PChatItem>  m_list;
    QString             m_friendID;
    QString             m_friendNickname;
    QString             m_friendPhoto;
};

#endif // P2PChat_H
