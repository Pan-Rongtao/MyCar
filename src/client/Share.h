#ifndef SHARE_H
#define SHARE_H

#include <qsystemdetection.h>
#include <string>

#ifdef WIN32
    #include <WinSock2.h>
#else
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <sys/ioctl.h>
    #include <net/if.h>
    #include <stdlib.h>
#endif

class Share
{
public:
    Share();

    std::string getLocalIp();
};

#endif // SHARE_H
