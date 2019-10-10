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

    Q_PROPERTY(QString friendID READ friendID WRITE setfriendID NOTIFY friendIDChanged)

    void setfriendID(QString friendID);
    QString friendID();

    QList<P2PChatItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void friendIDChanged();
    void friendNicknameChanged();

public slots:
    void sendMessage(const QString &msg);
    void update();

private:
    P2PChat();

    QList<P2PChatItem>  m_list;
    QString             m_friendID;
};

#endif // P2PChat_H
