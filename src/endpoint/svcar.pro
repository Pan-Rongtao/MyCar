TEMPLATE = app

QT += qml quick
CONFIG += c++11 resources_big
QT_IM_MODULE=qtvirtualkeyboard

SOURCES += *.cpp \
    Account.cpp \
    ImageProvider.cpp

RESOURCES += qml.qrc


uit_dist = E:\GitHub\MyCar\dist

INCLUDEPATH += \
    $$uit_dist/include

LIBS += -L$$uit_dist/lib/debug \
-luit_core \
-lPocoFoundationd \
-lPocoJSONd \
-luit_car \
-lRcfDll

HEADERS += \
    Account.h \
    Singleton.h \
    ImageProvider.h
