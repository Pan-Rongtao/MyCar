#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include <QDebug>
#include "Share.h"
#include "Account.h"
#include "Car.h"
#include "Singleton.h"
#include "ImageProvider.h"
#include "Contacts.h"
#include "Users.h"
#include "MessageList.h"
#include "Chat.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("Some Company");
    app.setOrganizationDomain("somecompany.com");
    app.setApplicationName("Amazing Application");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Account", nb::Singleton<Account>::instance());
    engine.rootContext()->setContextProperty("Car", nb::Singleton<Car>::instance());
    engine.rootContext()->setContextProperty("Contacts", nb::Singleton<Contacts>::instance());
    engine.rootContext()->setContextProperty("Users", nb::Singleton<Users>::instance());
    engine.rootContext()->setContextProperty("MessageList", nb::Singleton<MessageList>::instance());
    engine.rootContext()->setContextProperty("Chat", nb::Singleton<Chat>::instance());
    engine.rootContext()->setContextProperty("ImageProvider", ImageProvider::current());
    engine.addImageProvider("ImgProvider", ImageProvider::current());
/*
    nb::Singleton<Contacts>::instance()->items().append(CantactItem("1", "e:/5.jpg"));
    nb::Singleton<Contacts>::instance()->items().append(CantactItem("2", "b"));
    nb::Singleton<Contacts>::instance()->items().append(CantactItem("3", "c"));
    nb::Singleton<Contacts>::instance()->items().append(CantactItem("4", "d"));
*/
    nb::Singleton<MessageList>::instance()->items().append(MessageItem("uidp3575", "e:/5.jpg", "Pan", "hello!", QTime::currentTime().toString()));
    nb::Singleton<MessageList>::instance()->items().append(MessageItem("uidp3575", "e:/5.jpg", "Pan", "hello!", QTime::currentTime().toString()));
    nb::Singleton<MessageList>::instance()->items().append(MessageItem("uidp3575", "e:/5.jpg", "Pan", "hello!", QTime::currentTime().toString()));
    nb::Singleton<MessageList>::instance()->items().append(MessageItem("uidp3575", "e:/5.jpg", "Pan", "hello!", QTime::currentTime().toString()));

    nb::Singleton<Chat>::instance()->items().append(ChatItem("Pan", "e:/5.jpg", "000000", QTime::currentTime().toString(), false));
    nb::Singleton<Chat>::instance()->items().append(ChatItem("Pan", "e:/5.jpg", "111", QTime::currentTime().toString(), false));
    nb::Singleton<Chat>::instance()->items().append(ChatItem("Pan", "e:/5.jpg", "222", QTime::currentTime().toString(), false));
    nb::Singleton<Chat>::instance()->items().append(ChatItem("Pan", "e:/5.jpg", "hello1472347329eua4urq983ruq89y3tq98eur9q83y9rq8y39rqy9weyrq9wyr9qy39y34q9yr9", QTime::currentTime().toString(), true));


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    std::string ip = nb::Singleton<Share>::instance()->getLocalIp();
    auto interfacePort = 8888;
    auto publisherPort = 9999;
    try{
        nb::Singleton<Account>::instance()->connectServer(ip, interfacePort, publisherPort);
        nb::Singleton<Car>::instance()->connectServer(ip, interfacePort, publisherPort);
        qDebug() << "connected to [" << QString::fromStdString(ip) << ":" << interfacePort << "," << publisherPort << "]";
    }
    catch (RCF::Exception &e)	{ qDebug() << "a RCF::Exception occur:" << e.what(); }

    return app.exec();

//    catch (RCF::Exception &e)	{ qDebug() << "a RCF::Exception occur:" << e.what(); }
//    catch (std::exception &e)	{ qDebug() << "a std::exception occur:" << e.what(); }
//    catch (...)					{ qDebug() << "unknown exception\n"; }
}
