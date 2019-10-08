#include "Share.h"

Share::Share()
{

}

std::string Share::getLocalIp()
{
#ifdef Q_OS_WIN32
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
#if defined(__arm__) || defined(__ARM__)
    return eth.empty() ? getDeviceIp("mlan0") : eth;
#else
    return getDeviceIp("ens160");
#endif
#endif
}
