TEMPLATE = app

QT += qml quick
CONFIG += c++14 resources_big

HEADERS += \
    Account.h \
    ImageProvider.h \
    Car.h \
    Contacts.h \
    Users.h \
    MessageList.h \
    P2PChat.h \
    Proxy.h \
    Groups.h \
    GroupChat.h

SOURCES += main.cpp \
	Account.cpp \
    ImageProvider.cpp \
    Car.cpp \
    Contacts.cpp \
    Users.cpp \
    MessageList.cpp \
    P2PChat.cpp \
    Proxy.cpp \
    Groups.cpp \
    GroupChat.cpp

RESOURCES += qml.qrc

uit_dist = ../../dist

INCLUDEPATH += \
    $$uit_dist/include

win32{
DEFINES +=
    LIBS += -L../../3rdparty/lib/win32/debug \
    -lRcfLib
}

unix{
    contains(QT_ARCH, arm) {
            LIBS += -L../../3rdparty/lib/linux-arm \
            -lRcfLib \
            -lpthread \
            -luuid \
            -ldl
    }else{
            LIBS += -L../../3rdparty/lib/linux-x11 \
            -lRcfLib \
            -lpthread \
            -luuid \
            -ldl
    }
}
