#pragma once

#include <QObject>
#include <QAbstractListModel>

class UserItem
{
public:
    UserItem(const QString &_userID, const QString &_nickname, const QString &_photo)
        : userID(_userID)
        , nickname(_nickname)
        , photo(_photo)
    {}

    QString userID;
    QString nickname;
    QString photo;
};

class Users : public QAbstractListModel
{
    Q_OBJECT
public:
    Users();

    QList<UserItem> &items();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;


signals:

public slots:
    void query();

private:
    QList<UserItem> m_list;
};

