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
    static Users *instance();

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

