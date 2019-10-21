#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "Item.h"

class Groups : public QAbstractListModel
{
    Q_OBJECT
public:
    static Groups *get();

    QList<UserItem> &items();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;


public slots:
    void update();
    void create(const QList<int> &indexs);
    void remove(int index);


private:
    Groups();

    QList<UserItem> m_list;
};
