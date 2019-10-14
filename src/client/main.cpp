#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include <QDebug>
#include "Account.h"
#include "Car.h"
#include "ImageProvider.h"
#include "Friends.h"
#include "Users.h"
#include "MessageList.h"
#include "P2PChat.h"
#include "Groups.h"
#include "GroupChat.h"
#include "LayerManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("Some Company");
    app.setOrganizationDomain("somecompany.com");
    app.setApplicationName("Amazing Application");

    qmlRegisterType<Type>("UIT.Type", 1, 0, "Type");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("LayerManager", LayerManager::instance());
    engine.rootContext()->setContextProperty("Account", Account::instance());
    engine.rootContext()->setContextProperty("Car", Car::instance());
    engine.rootContext()->setContextProperty("Friends", Friends::instance());
    engine.rootContext()->setContextProperty("Users", Users::instance());
    engine.rootContext()->setContextProperty("MessageList", MessageList::instance());
    engine.rootContext()->setContextProperty("P2PChat", P2PChat::instance());
    engine.rootContext()->setContextProperty("Groups", Groups::instance());
    engine.rootContext()->setContextProperty("GroupChat", GroupChat::instance());
    engine.rootContext()->setContextProperty("GroupMembers", GroupMembers::instance());
    engine.rootContext()->setContextProperty("ImageProvider", ImageProvider::instance());
    engine.addImageProvider("ImgProvider", ImageProvider::instance());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

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
