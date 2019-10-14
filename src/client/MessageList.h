#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "Item.h"

class MessageList : public QAbstractListModel
{
    Q_OBJECT
public:
    static MessageList *instance();

    QList<ChatItem> &items();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    MessageList();

    QList<ChatItem> m_list;
};

