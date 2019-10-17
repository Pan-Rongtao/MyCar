/****************************************************************************
** Meta object code from reading C++ file 'Car.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Car.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Car.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Car_t {
    QByteArrayData data[51];
    char stringdata0[752];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Car_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Car_t qt_meta_stringdata_Car = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Car"
QT_MOC_LITERAL(1, 4, 20), // "availableFuelChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "averageFuelChanged"
QT_MOC_LITERAL(4, 45, 14), // "totalKmChanged"
QT_MOC_LITERAL(5, 60, 13), // "subKmAChanged"
QT_MOC_LITERAL(6, 74, 13), // "subKmBChanged"
QT_MOC_LITERAL(7, 88, 20), // "leftFrontDoorChanged"
QT_MOC_LITERAL(8, 109, 21), // "rightFrontDoorChanged"
QT_MOC_LITERAL(9, 131, 19), // "leftRearDoorChanged"
QT_MOC_LITERAL(10, 151, 20), // "rightRearDoorChanged"
QT_MOC_LITERAL(11, 172, 22), // "leftFrontWindowChanged"
QT_MOC_LITERAL(12, 195, 23), // "rightFrontWindowChanged"
QT_MOC_LITERAL(13, 219, 21), // "leftRearWindowChanged"
QT_MOC_LITERAL(14, 241, 22), // "rightRearWindowChanged"
QT_MOC_LITERAL(15, 264, 9), // "ACChanged"
QT_MOC_LITERAL(16, 274, 13), // "ACTempChanged"
QT_MOC_LITERAL(17, 288, 20), // "shutdownPhotoChanged"
QT_MOC_LITERAL(18, 309, 14), // "drivingChanged"
QT_MOC_LITERAL(19, 324, 12), // "signalUpdate"
QT_MOC_LITERAL(20, 337, 6), // "update"
QT_MOC_LITERAL(21, 344, 19), // "switchLeftFrontDoor"
QT_MOC_LITERAL(22, 364, 1), // "b"
QT_MOC_LITERAL(23, 366, 20), // "switchRightFrontDoor"
QT_MOC_LITERAL(24, 387, 18), // "switchLeftRearDoor"
QT_MOC_LITERAL(25, 406, 19), // "switchRightRearDoor"
QT_MOC_LITERAL(26, 426, 21), // "switchLeftFrontWindow"
QT_MOC_LITERAL(27, 448, 22), // "switchRightFrontWindow"
QT_MOC_LITERAL(28, 471, 20), // "switchLeftRearWindow"
QT_MOC_LITERAL(29, 492, 21), // "switchRightRearWindow"
QT_MOC_LITERAL(30, 514, 8), // "switchAC"
QT_MOC_LITERAL(31, 523, 12), // "switchACTemp"
QT_MOC_LITERAL(32, 536, 1), // "v"
QT_MOC_LITERAL(33, 538, 13), // "switchDriving"
QT_MOC_LITERAL(34, 552, 13), // "availableFuel"
QT_MOC_LITERAL(35, 566, 11), // "averageFuel"
QT_MOC_LITERAL(36, 578, 7), // "totalKm"
QT_MOC_LITERAL(37, 586, 6), // "subKmA"
QT_MOC_LITERAL(38, 593, 6), // "subKmB"
QT_MOC_LITERAL(39, 600, 13), // "leftFrontDoor"
QT_MOC_LITERAL(40, 614, 14), // "rightFrontDoor"
QT_MOC_LITERAL(41, 629, 12), // "leftRearDoor"
QT_MOC_LITERAL(42, 642, 13), // "rightRearDoor"
QT_MOC_LITERAL(43, 656, 15), // "leftFrontWindow"
QT_MOC_LITERAL(44, 672, 16), // "rightFrontWindow"
QT_MOC_LITERAL(45, 689, 14), // "leftRearWindow"
QT_MOC_LITERAL(46, 704, 15), // "rightRearWindow"
QT_MOC_LITERAL(47, 720, 2), // "AC"
QT_MOC_LITERAL(48, 723, 6), // "ACTemp"
QT_MOC_LITERAL(49, 730, 13), // "shutdownPhoto"
QT_MOC_LITERAL(50, 744, 7) // "driving"

    },
    "Car\0availableFuelChanged\0\0averageFuelChanged\0"
    "totalKmChanged\0subKmAChanged\0subKmBChanged\0"
    "leftFrontDoorChanged\0rightFrontDoorChanged\0"
    "leftRearDoorChanged\0rightRearDoorChanged\0"
    "leftFrontWindowChanged\0rightFrontWindowChanged\0"
    "leftRearWindowChanged\0rightRearWindowChanged\0"
    "ACChanged\0ACTempChanged\0shutdownPhotoChanged\0"
    "drivingChanged\0signalUpdate\0update\0"
    "switchLeftFrontDoor\0b\0switchRightFrontDoor\0"
    "switchLeftRearDoor\0switchRightRearDoor\0"
    "switchLeftFrontWindow\0switchRightFrontWindow\0"
    "switchLeftRearWindow\0switchRightRearWindow\0"
    "switchAC\0switchACTemp\0v\0switchDriving\0"
    "availableFuel\0averageFuel\0totalKm\0"
    "subKmA\0subKmB\0leftFrontDoor\0rightFrontDoor\0"
    "leftRearDoor\0rightRearDoor\0leftFrontWindow\0"
    "rightFrontWindow\0leftRearWindow\0"
    "rightRearWindow\0AC\0ACTemp\0shutdownPhoto\0"
    "driving"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Car[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
      17,  216, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  164,    2, 0x06 /* Public */,
       3,    0,  165,    2, 0x06 /* Public */,
       4,    0,  166,    2, 0x06 /* Public */,
       5,    0,  167,    2, 0x06 /* Public */,
       6,    0,  168,    2, 0x06 /* Public */,
       7,    0,  169,    2, 0x06 /* Public */,
       8,    0,  170,    2, 0x06 /* Public */,
       9,    0,  171,    2, 0x06 /* Public */,
      10,    0,  172,    2, 0x06 /* Public */,
      11,    0,  173,    2, 0x06 /* Public */,
      12,    0,  174,    2, 0x06 /* Public */,
      13,    0,  175,    2, 0x06 /* Public */,
      14,    0,  176,    2, 0x06 /* Public */,
      15,    0,  177,    2, 0x06 /* Public */,
      16,    0,  178,    2, 0x06 /* Public */,
      17,    0,  179,    2, 0x06 /* Public */,
      18,    0,  180,    2, 0x06 /* Public */,
      19,    0,  181,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,  182,    2, 0x0a /* Public */,
      21,    1,  183,    2, 0x0a /* Public */,
      23,    1,  186,    2, 0x0a /* Public */,
      24,    1,  189,    2, 0x0a /* Public */,
      25,    1,  192,    2, 0x0a /* Public */,
      26,    1,  195,    2, 0x0a /* Public */,
      27,    1,  198,    2, 0x0a /* Public */,
      28,    1,  201,    2, 0x0a /* Public */,
      29,    1,  204,    2, 0x0a /* Public */,
      30,    1,  207,    2, 0x0a /* Public */,
      31,    1,  210,    2, 0x0a /* Public */,
      33,    1,  213,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Bool,   22,

 // properties: name, type, flags
      34, QMetaType::Float, 0x00495003,
      35, QMetaType::Float, 0x00495003,
      36, QMetaType::Float, 0x00495003,
      37, QMetaType::Float, 0x00495003,
      38, QMetaType::Float, 0x00495003,
      39, QMetaType::Bool, 0x00495003,
      40, QMetaType::Bool, 0x00495003,
      41, QMetaType::Bool, 0x00495003,
      42, QMetaType::Bool, 0x00495003,
      43, QMetaType::Bool, 0x00495003,
      44, QMetaType::Bool, 0x00495003,
      45, QMetaType::Bool, 0x00495003,
      46, QMetaType::Bool, 0x00495003,
      47, QMetaType::Bool, 0x00495103,
      48, QMetaType::Int, 0x00495103,
      49, QMetaType::QString, 0x00495003,
      50, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,

       0        // eod
};

void Car::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Car *_t = static_cast<Car *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->availableFuelChanged(); break;
        case 1: _t->averageFuelChanged(); break;
        case 2: _t->totalKmChanged(); break;
        case 3: _t->subKmAChanged(); break;
        case 4: _t->subKmBChanged(); break;
        case 5: _t->leftFrontDoorChanged(); break;
        case 6: _t->rightFrontDoorChanged(); break;
        case 7: _t->leftRearDoorChanged(); break;
        case 8: _t->rightRearDoorChanged(); break;
        case 9: _t->leftFrontWindowChanged(); break;
        case 10: _t->rightFrontWindowChanged(); break;
        case 11: _t->leftRearWindowChanged(); break;
        case 12: _t->rightRearWindowChanged(); break;
        case 13: _t->ACChanged(); break;
        case 14: _t->ACTempChanged(); break;
        case 15: _t->shutdownPhotoChanged(); break;
        case 16: _t->drivingChanged(); break;
        case 17: _t->signalUpdate(); break;
        case 18: _t->update(); break;
        case 19: _t->switchLeftFrontDoor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->switchRightFrontDoor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->switchLeftRearDoor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->switchRightRearDoor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->switchLeftFrontWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->switchRightFrontWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->switchLeftRearWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->switchRightRearWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->switchAC((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->switchACTemp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->switchDriving((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::availableFuelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::averageFuelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::totalKmChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::subKmAChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::subKmBChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::leftFrontDoorChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::rightFrontDoorChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::leftRearDoorChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::rightRearDoorChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::leftFrontWindowChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::rightFrontWindowChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::leftRearWindowChanged)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::rightRearWindowChanged)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::ACChanged)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::ACTempChanged)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::shutdownPhotoChanged)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::drivingChanged)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (Car::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::signalUpdate)) {
                *result = 17;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Car *_t = static_cast<Car *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->availableFuel(); break;
        case 1: *reinterpret_cast< float*>(_v) = _t->averageFuel(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->totalKm(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->subKmA(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->subKmB(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->leftFrontDoor(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->rightFrontDoor(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->leftRearDoor(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->rightRearDoor(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->leftFrontWindow(); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->rightFrontWindow(); break;
        case 11: *reinterpret_cast< bool*>(_v) = _t->leftRearWindow(); break;
        case 12: *reinterpret_cast< bool*>(_v) = _t->rightRearWindow(); break;
        case 13: *reinterpret_cast< bool*>(_v) = _t->AC(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->ACTemp(); break;
        case 15: *reinterpret_cast< QString*>(_v) = _t->shutdownPhoto(); break;
        case 16: *reinterpret_cast< bool*>(_v) = _t->driving(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Car *_t = static_cast<Car *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setavailableFuel(*reinterpret_cast< float*>(_v)); break;
        case 1: _t->setaverageFuel(*reinterpret_cast< float*>(_v)); break;
        case 2: _t->settotalKm(*reinterpret_cast< float*>(_v)); break;
        case 3: _t->setsubKmA(*reinterpret_cast< float*>(_v)); break;
        case 4: _t->setsubKmB(*reinterpret_cast< float*>(_v)); break;
        case 5: _t->setleftFrontDoor(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setrightFrontDoor(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setleftRearDoor(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setrightRearDoor(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setleftFrontWindow(*reinterpret_cast< bool*>(_v)); break;
        case 10: _t->setrightFrontWindow(*reinterpret_cast< bool*>(_v)); break;
        case 11: _t->setleftRearWindow(*reinterpret_cast< bool*>(_v)); break;
        case 12: _t->setrightRearWindow(*reinterpret_cast< bool*>(_v)); break;
        case 13: _t->setAC(*reinterpret_cast< bool*>(_v)); break;
        case 14: _t->setACTemp(*reinterpret_cast< int*>(_v)); break;
        case 15: _t->setshutdownPhoto(*reinterpret_cast< QString*>(_v)); break;
        case 16: _t->setdriving(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Car::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Car.data,
      qt_meta_data_Car,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Car::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Car::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Car.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Car::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 30;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 17;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Car::availableFuelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Car::averageFuelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Car::totalKmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Car::subKmAChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Car::subKmBChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Car::leftFrontDoorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Car::rightFrontDoorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Car::leftRearDoorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Car::rightRearDoorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Car::leftFrontWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Car::rightFrontWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Car::leftRearWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Car::rightRearWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void Car::ACChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void Car::ACTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void Car::shutdownPhotoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void Car::drivingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void Car::signalUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
