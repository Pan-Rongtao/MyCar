#pragma once

class UserItem
{
public:
    UserItem(const QString &_userID, const QString &_nickname, const QString &_photo)
        : id(_userID)
        , name(_nickname)
        , photo(_photo)
    {}

    QString id;
    QString name;
    QString photo;
};

class ChatItem
{
public:
    ChatItem(const QString &_nickname, const QString &_photo, const QString &_msg, const QString &_time, bool _iSend)
        : nickname(_nickname)
        , photo(_photo)
        , msg(_msg)
        , time(_time)
        , iSend(_iSend)
    {}

    QString nickname;
    QString photo;
    QString msg;
    QString time;
    bool    iSend;
};
