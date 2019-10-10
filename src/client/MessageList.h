#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <QObject>
#include <QAbstractListModel>

class MessageItem
{
public:
    MessageItem(const QString &_userID, const QString &_photo, const QString &_from, const QString &_msg, const QString &_time)
        : userID(_userID)
        , photo(_photo)
        , from(_from)
        , msg(_msg)
        , time(_time)
    {}

    QString userID;
    QString photo;
    QString from;
    QString msg;
    QString time;
};

class MessageList : public QAbstractListModel
{
    Q_OBJECT
public:
    static MessageList *instance();

    QList<MessageItem> &items();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    MessageList();

    QList<MessageItem> m_list;
};

#endif // MESSAGELIST_H
