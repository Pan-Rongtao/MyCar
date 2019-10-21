#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "Item.h"

class Users : public QAbstractListModel
{
    Q_OBJECT
public:
    static Users *get();

    QList<UserItem> &items();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;


public slots:
    void update();

private:
    Users();

    QList<UserItem> m_list;
};

