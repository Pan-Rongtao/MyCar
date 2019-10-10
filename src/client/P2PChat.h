#ifndef P2PChat_H
#define P2PChat_H

#include <QObject>
#include <QAbstractListModel>

class P2PChatItem
{
public:
    P2PChatItem(const QString &_nickname, const QString &_photo, const QString &_msg, const QString &_time, bool _iSend)
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

class P2PChat : public QAbstractListModel
{
    Q_OBJECT
public:
    P2PChat();

    Q_PROPERTY(QString who READ who WRITE setwho NOTIFY whoChanged)
    void setwho(QString who);
    QString who();

    QList<P2PChatItem> &items();
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void whoChanged();

public slots:
    void sendMessage(const QString &msg);

private:
    QList<P2PChatItem> m_list;
    QString         m_who;
};

#endif // P2PChat_H
