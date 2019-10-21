TEMPLATE = app

QT += qml quick
CONFIG += c++14 resources_big

HEADERS += \
    Account.h \
    Car.h \
    Users.h \
    Proxy.h \
    Groups.h \
    Item.h \
    LayerManager.h \
    Type.h \
    Chat.h

SOURCES += main.cpp \
	Account.cpp \
    Car.cpp \
    Users.cpp \
    Proxy.cpp \
    Groups.cpp \
    LayerManager.cpp \
    Chat.cpp

RESOURCES += qml.qrc

uit_dist = ../../dist

INCLUDEPATH += \
    ../../3rdparty/include \
    ../../include

win32{
CONFIG(debug, debug|release){
    LIBS += -L../../3rdparty/lib/win32/debug \
    -lRcfLib
    QMAKE_POST_LINK += copy /y debug\client.exe ..\..\dist\win32\bin\debug\app\
}else{
    LIBS += -L../../3rdparty/lib/win32/release \
    -lRcfLib
    QMAKE_POST_LINK += copy /y release\client.exe ..\..\dist\win32\bin\release\app\
}
}

unix{
    message($$QT_ARCH)
    contains(QT_ARCH, arm) {
            LIBS += -L../../3rdparty/lib/linux-arm \
            -lRCF-android \
    }else{

        contains(QT_ARCH, arm64) {
                            OBJECTS_DIR=./obj
                            MOC_DIR=./obj
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

}
