#pragma once

#include <QObject>
#include <QAbstractListModel>

class GroupItem
{
public:
    GroupItem(const QString &_groupID, const QString &_name, const QString &_photo)
        : groupID(_groupID)
        , name(_name)
        , photo(_photo)
    {}

    QString groupID;
    QString name;
    QString photo;
};

class Groups : public QAbstractListModel
{
    Q_OBJECT
public:
    static Groups *instance();

    QList<GroupItem> &items();

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;


public slots:
    void update();
    void create(const QList<int> &indexs);
    void remove(int index);


private:
    Groups();

    QList<GroupItem> m_list;
};
