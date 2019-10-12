#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include <QDebug>
#include "Account.h"
#include "Car.h"
#include "ImageProvider.h"
#include "Contacts.h"
#include "Users.h"
#include "MessageList.h"
#include "P2PChat.h"
#include "Groups.h"
#include "GroupChat.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("Some Company");
    app.setOrganizationDomain("somecompany.com");
    app.setApplicationName("Amazing Application");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Account", Account::instance());
    engine.rootContext()->setContextProperty("Car", Car::instance());
    engine.rootContext()->setContextProperty("Contacts", Contacts::instance());
    engine.rootContext()->setContextProperty("Users", Users::instance());
    engine.rootContext()->setContextProperty("MessageList", MessageList::instance());
    engine.rootContext()->setContextProperty("P2PChat", P2PChat::instance());
    engine.rootContext()->setContextProperty("Groups", Groups::instance());
    engine.rootContext()->setContextProperty("GroupChat", GroupChat::instance());
    engine.rootContext()->setContextProperty("ImageProvider", ImageProvider::instance());
    engine.addImageProvider("ImgProvider", ImageProvider::instance());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

/*
    MessageList::instance()->items().append(MessageItem("uidp3575", "e:/5.jpg", "Pan", "hello!", QTime::currentTime().toString()));
    MessageList::instance()->items().append(MessageItem("uidp3575", "e:/5.jpg", "Pan", "hello!", QTime::currentTime().toString()));
    MessageList::instance()->items().append(MessageItem("uidp3575", "e:/5.jpg", "Pan", "hello!", QTime::currentTime().toString()));
    MessageList::instance()->items().append(MessageItem("uidp3575", "e:/5.jpg", "Pan", "hello!", QTime::currentTime().toString()));

    P2PChat::instance()->items().append(P2PChatItem("Pan", "e:/5.jpg", "000000", QTime::currentTime().toString(), false));
    P2PChat::instance()->items().append(P2PChatItem("Pan", "e:/5.jpg", "111", QTime::currentTime().toString(), false));
    P2PChat::instance()->items().append(P2PChatItem("Pan", "e:/5.jpg", "222", QTime::currentTime().toString(), false));
    P2PChat::instance()->items().append(P2PChatItem("Pan", "e:/5.jpg", "hello1472347329eua4urq983ruq89y3tq98eur9q83y9rq8y39rqy9weyrq9wyr9qy39y34q9yr9", QTime::currentTime().toString(), true));
*/

    std::string ip = Proxy::instance()->getLocalIp();
    auto interfacePort = 8888;
    auto publisherPort = 9999;
    try{
        Proxy::instance()->connectToServer(ip, interfacePort, publisherPort);
        qDebug() << "connected to [" << QString::fromStdString(ip) << ":" << interfacePort << "," << publisherPort << "]";
    }
    catch (RCF::Exception &e)	{ qDebug() << "a RCF::Exception occur:" << e.what(); }
    return app.exec();
}
