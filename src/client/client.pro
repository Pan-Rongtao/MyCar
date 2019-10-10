TEMPLATE = app

QT += qml quick
CONFIG += c++14 resources_big

HEADERS += \
    Account.h \
    Singleton.h \
    ImageProvider.h \
    Car.h \
    Contacts.h \
    Users.h \
    MessageList.h \
    Share.h \
    P2PChat.h \
    Proxy.h

SOURCES += main.cpp \
	Account.cpp \
    ImageProvider.cpp \
    Car.cpp \
    Contacts.cpp \
    Users.cpp \
    MessageList.cpp \
    Share.cpp \
    P2PChat.cpp \
    Proxy.cpp

RESOURCES += qml.qrc

uit_dist = ../../dist

INCLUDEPATH += \
    $$uit_dist/include

win32{
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
