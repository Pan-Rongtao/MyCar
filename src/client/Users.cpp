#include "Users.h"
#include "Account.h"
#include "Singleton.h"
#include <QFile>
#include <QDir>

Users::Users()
{

}

QList<UserItem> &Users::items()
{
    return m_list;
}

int Users::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant Users::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch (role) {
    case 0: return m_list[index.row()].userID;
    case 1: return m_list[index.row()].nickname;
    case 2: return m_list[index.row()].photo;
    default:return QVariant();
    }
}

QHash<int, QByteArray> Users::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "userID";
    roles[1] = "nickname";
    roles[2] = "photo";
    return roles;
}

void Users::query()
{
    beginResetModel();
    m_list.clear();
    std::vector<AccountInfo> infos;
    nb::Singleton<Account>::instance()->queryAllAccount(infos);
    QDir usersDir;
    usersDir.mkdir("users");
    for(auto &info : infos)
    {
        QString photoPath = usersDir.dirName() + "/" + "users/" + QString::fromStdString(info.userID) + ".jpg";
        QFile f(photoPath);
        if(f.open(QFile::WriteOnly))
            f.write(info.photo.data(), info.photo.size());
        UserItem item(QString::fromStdString(info.userID), QString::fromStdString(info.nickname), photoPath);
        m_list.append(item);
    }
    endResetModel();
}
