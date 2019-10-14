#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "Item.h"

class Friends : public QAbstractListModel
{
    Q_OBJECT
public:
    static Friends *instance();

    QList<UserItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void add(const QList<int> &indexs);
    void remove(int index);
    void update();

private:
    Friends();

    QList<UserItem> m_list;
};
