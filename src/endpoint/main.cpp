#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Account.h"
#include "Poco/SingletonHolder.h"
#include "Singleton.h"
#include "ImageProvider.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QGuiApplication app(argc, argv);

    nb::Singleton<Account>::instance()->connectServer("10.219.125.39", 8888);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Account", nb::Singleton<Account>::instance());
    engine.rootContext()->setContextProperty("ImageProvider", ImageProvider::current());
    engine.addImageProvider("ImgProvider", ImageProvider::current());

    app.setOrganizationName("Some Company"); //1
    app.setOrganizationDomain("somecompany.com"); //2
    app.setApplicationName("Amazing Application"); //3

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
