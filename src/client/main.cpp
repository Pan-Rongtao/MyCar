#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/Net/TCPServer.h>
#include "Account.h"
#include "Car.h"
#include "Singleton.h"
#include "ImageProvider.h"

using namespace Poco;
using namespace Poco::Util;
#define CONFIGURE_FILE_PATH		"client.conf"

std::string getLocalIp()
{
#ifdef WIN32
    WSADATA Data;
    WSAStartup(MAKEWORD(1, 1), &Data);
    char hostName[256] = { 0 };
    gethostname(hostName, sizeof(hostName));
    PHOSTENT hostinfo;
    hostinfo = gethostbyname(hostName);
    std::string ip = inet_ntoa(*(struct in_addr*)*hostinfo->h_addr_list);
    WSACleanup();
    return ip;
#else
    auto getDeviceIp = [](const std::string &sDev)->std::string {
        char ip[80] = { 0 };
        struct ifreq ifr;
        int sk = socket(AF_INET, SOCK_DGRAM, 0);
        strcpy(ifr.ifr_name, sDev.data());
        if (ioctl(sk, SIOCGIFADDR, &ifr) == 0)
            strcpy(ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
        close(sk);
        return ip;
    };
#if POCO_ARCH == ARM
    auto eth = getDeviceIp("eth1");
    if(!eth.empty())
        return eth;
    else
        return getDeviceIp("mlan0");
#else
    return getDeviceIp("ens160");
#endif
#endif
}

int main(int argc, char *argv[])
{
    try{
        QGuiApplication app(argc, argv);
        app.setOrganizationName("Some Company");
        app.setOrganizationDomain("somecompany.com");
        app.setApplicationName("Amazing Application");

        std::string ip = getLocalIp();
        auto interfacePort = 8888;
        auto publisherPort = 9999;
        try {
            Poco::AutoPtr<IniFileConfiguration> ini = new IniFileConfiguration(CONFIGURE_FILE_PATH);
            ip = ini->getString("ip");
        }
        catch (...) {}
        nb::Singleton<Account>::instance()->connectServer(getLocalIp(), interfacePort, publisherPort);
        nb::Singleton<Car>::instance()->connectServer(getLocalIp(), interfacePort, publisherPort);
        printf("connected to [%s:%d, %d].\n", ip.data(), interfacePort, publisherPort);

        QQmlApplicationEngine engine;
        engine.rootContext()->setContextProperty("Account", nb::Singleton<Account>::instance());
        engine.rootContext()->setContextProperty("Car", nb::Singleton<Car>::instance());
        engine.rootContext()->setContextProperty("ImageProvider", ImageProvider::current());
        engine.addImageProvider("ImgProvider", ImageProvider::current());

        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

        return app.exec();
    }
    catch (RCF::Exception &e)	{ printf("a RCF::Exception occur: %s\n", e.what()); }
    catch (Poco::Exception &e)	{ printf("a Poco::Exception occur: %s\n", e.what()); }
    catch (std::exception &e)	{ printf("a std::exception occur: %s\n", e.what()); }
    catch (...)					{ printf("unknown exception\n"); }
}
