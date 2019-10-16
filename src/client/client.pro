TEMPLATE = app

QT += qml quick
CONFIG += c++14 resources_big

HEADERS += \
    Account.h \
    ImageProvider.h \
    Car.h \
    Users.h \
    MessageList.h \
    P2PChat.h \
    Proxy.h \
    Groups.h \
    GroupChat.h \
    Item.h \
    Friends.h \
    LayerManager.h \
    Type.h

SOURCES += main.cpp \
	Account.cpp \
    ImageProvider.cpp \
    Car.cpp \
    Users.cpp \
    MessageList.cpp \
    P2PChat.cpp \
    Proxy.cpp \
    Groups.cpp \
    GroupChat.cpp \
    Friends.cpp \
    LayerManager.cpp

RESOURCES += qml.qrc

uit_dist = ../../dist

INCLUDEPATH += \
    ../../3rdparty/include \
    ../../include

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
