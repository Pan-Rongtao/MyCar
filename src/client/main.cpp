#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "Account.h"
#include "Car.h"
#include "Users.h"
#include "Groups.h"
#include "Chat.h"
#include "LayerManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("Some Company");
    app.setOrganizationDomain("somecompany.com");
    app.setApplicationName("Amazing Application");

    qmlRegisterType<Type>("UIT.Type", 1, 0, "Type");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Proxy", Proxy::get());
    engine.rootContext()->setContextProperty("LayerManager", LayerManager::get());
    engine.rootContext()->setContextProperty("Account", Account::get());
    engine.rootContext()->setContextProperty("Car", Car::get());
    engine.rootContext()->setContextProperty("Friends", Friends::get());
    engine.rootContext()->setContextProperty("Users", Users::get());
    engine.rootContext()->setContextProperty("MessageList", MessageList::get());
    engine.rootContext()->setContextProperty("P2PChat", P2PChat::get());
    engine.rootContext()->setContextProperty("Groups", Groups::get());
    engine.rootContext()->setContextProperty("GroupChat", GroupChat::get());
    engine.rootContext()->setContextProperty("GroupMembers", GroupMembers::get());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //auto ip = QString::fromStdString(Proxy::get()->getLocalIp());
    //auto interfacePort = 8888;
    //auto publisherPort = 9999;
    //printf("getLocalIp=%s\n", ip.toStdString().data());
    QString ip = "24l0x21424.qicp.vip";
    auto interfacePort = 50074;
    auto publisherPort = 51191;
    Proxy::get()->connectToServer(ip, interfacePort, publisherPort);
    qDebug() << "connected to [" << ip << ":" << interfacePort << "," << publisherPort << "]";

    return app.exec();
}
