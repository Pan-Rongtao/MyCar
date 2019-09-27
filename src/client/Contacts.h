#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include <QAbstractListModel>

class CantactItem
{
public:
    CantactItem(const QString &_nickname, const QString &_photo)
        : nickname(_nickname)
        , photo(_photo)
    {}

    QString nickname;
    QString photo;
};

class Contacts : public QAbstractListModel
{
    Q_OBJECT
public:
    Contacts();

    QList<CantactItem> &items();
    void addFromUserList();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:

public slots:


private:
    QList<CantactItem> m_list;
};

#endif // CONTACTS_H
