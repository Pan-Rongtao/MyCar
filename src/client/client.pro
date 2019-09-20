TEMPLATE = app

QT += qml quick
CONFIG += resources_big
QT_IM_MODULE=qtvirtualkeyboard

HEADERS += \
    Account.h \
    Singleton.h \
    ImageProvider.h \
    Car.h

SOURCES += main.cpp \
	Account.cpp \
    ImageProvider.cpp \
    Car.cpp

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
	LIBS += -L$$uit_dist/lib \
	-L../../3rdparty/lib/linux-arm \
	-luit_core \
	-lPocoFoundation \
	-lPocoJSON \
	-lRcfLib \
	-lpthread \
	-luuid \
	-ldl
}
