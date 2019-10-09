#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include <QAbstractListModel>

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
    Contacts();

    QList<CantactItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:

public slots:
    void addFromUserList(const QList<int> &indexs);
    void remove(int index);
    void update();


private:
    QList<CantactItem> m_list;
};

#endif // CONTACTS_H
