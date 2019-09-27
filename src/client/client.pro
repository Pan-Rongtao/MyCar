TEMPLATE = app

QT += qml quick
CONFIG += c++14 resources_big

HEADERS += \
    Account.h \
    Singleton.h \
    ImageProvider.h \
    Car.h \
    Contacts.h \
    Users.h

SOURCES += main.cpp \
	Account.cpp \
    ImageProvider.cpp \
    Car.cpp \
    Contacts.cpp \
    Users.cpp

RESOURCES += qml.qrc

uit_dist = ../../dist

INCLUDEPATH += \
    $$uit_dist/include

win32{
	LIBS += -L$$uit_dist/lib/debug \
	-L../../3rdparty/lib/win32/debug \
	-luit_core \
	-lPocoFoundationd \
	-lPocoJSONd \
	-lRcfLib
}

unix{
    contains(QT_ARCH, arm) {
            LIBS += -L$$uit_dist/lib \
            -L../../3rdparty/lib/linux-arm \
            -luit_core \
            -lPocoFoundation \
            -lPocoJSON \
            -lRcfLib \
            -lpthread \
            -luuid \
            -ldl
    }else{
            LIBS += -L$$uit_dist/lib \
            -L../../3rdparty/lib/linux-x11 \
            -luit_core \
            -lPocoFoundation \
            -lPocoJSON \
            -lPocoNet \
            -lPocoUtil \
            -lPocoXML \
            -lRcfLib \
            -lpthread \
            -luuid \
            -ldl
    }
}
