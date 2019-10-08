#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include <QAbstractListModel>

class ChatItem
{
public:
    ChatItem(const QString &_nickname, const QString &_photo, const QString &_msg, const QString &_time, bool _iSend)
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

class Chat : public QAbstractListModel
{
    Q_OBJECT
public:
    Chat();

    QList<ChatItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<ChatItem> m_list;
};

#endif // CHAT_H
