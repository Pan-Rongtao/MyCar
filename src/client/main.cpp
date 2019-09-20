#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Account.h"
#include "Car.h"
#include "Poco/SingletonHolder.h"
#include "Singleton.h"
#include "ImageProvider.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
	printf("!!!!!!!!!!111\n");
    QGuiApplication app(argc, argv);
    //3s.dkys.org:25380
    //http://prt.ngrok2.xiaomiqiu.cn
    //https://prt.ngrok2.xiaomiqiu.cn
    nb::Singleton<Account>::instance()->connectServer("192.168.0.22", 8888);
    nb::Singleton<Car>::instance()->connectServer("192.168.0.22", 8888);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Account", nb::Singleton<Account>::instance());
    engine.rootContext()->setContextProperty("Car", nb::Singleton<Car>::instance());
    engine.rootContext()->setContextProperty("ImageProvider", ImageProvider::current());
    engine.addImageProvider("ImgProvider", ImageProvider::current());

    app.setOrganizationName("Some Company"); //1
    app.setOrganizationDomain("somecompany.com"); //2
    app.setApplicationName("Amazing Application"); //3

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
