TEMPLATE = app

QT += qml quick
CONFIG += resources_big
QT_IM_MODULE=qtvirtualkeyboard

SOURCES += *.cpp \
    Account.cpp \
    ImageProvider.cpp \
    Car.cpp

RESOURCES += qml.qrc


uit_dist = E:\GitHub\MyCar\dist

INCLUDEPATH += \
    $$uit_dist/include

LIBS += -L$$uit_dist/lib/debug \
-L../../3rdparty/lib/win32/debug \
-luit_core \
-lPocoFoundationd \
-lPocoJSONd \
-lRcfLib

HEADERS += \
    Account.h \
    Singleton.h \
    ImageProvider.h \
    Car.h
