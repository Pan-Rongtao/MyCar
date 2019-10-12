#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include <QAbstractListModel>
#include "Proxy.h"

class CantactItem
{
public:
    CantactItem(const QString &_userID, const QString &_nickname, const QString &_photo)
        : userID(_userID)
        , nickname(_nickname)
        , photo(_photo)
    {}

    QString userID;
    QString nickname;
    QString photo;
};

class Contacts : public QAbstractListModel
{
    Q_OBJECT
public:
    static Contacts *instance();

    QList<CantactItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:

public slots:
    void add(const QList<int> &indexs);
    void remove(int index);
    void update();

private:
    Contacts();

    QList<CantactItem> m_list;
};

#endif // CONTACTS_H
