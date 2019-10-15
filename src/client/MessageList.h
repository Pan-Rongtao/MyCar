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

signals:
    void signalUpdate();

public slots:
    void enterChat(int index);
    void update();

private:
    MessageList();
    static bool compareItem(const ChatItem &item0, const ChatItem &item1);

    QList<ChatItem> m_list;
};

