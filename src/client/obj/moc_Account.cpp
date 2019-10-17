/****************************************************************************
** Meta object code from reading C++ file 'Account.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Account.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Account.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Account_t {
    QByteArrayData data[32];
    char stringdata0[379];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Account_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Account_t qt_meta_stringdata_Account = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Account"
QT_MOC_LITERAL(1, 8, 13), // "userIDChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "passwordChanged"
QT_MOC_LITERAL(4, 39, 15), // "nicknameChanged"
QT_MOC_LITERAL(5, 55, 16), // "signaTureChanged"
QT_MOC_LITERAL(6, 72, 12), // "photoChanged"
QT_MOC_LITERAL(7, 85, 17), // "registTimeChanged"
QT_MOC_LITERAL(8, 103, 20), // "vehicleOnlineChanged"
QT_MOC_LITERAL(9, 124, 15), // "pcOnlineChanged"
QT_MOC_LITERAL(10, 140, 20), // "handeldOnlineChanged"
QT_MOC_LITERAL(11, 161, 16), // "padOnlineChanged"
QT_MOC_LITERAL(12, 178, 10), // "isRegisted"
QT_MOC_LITERAL(13, 189, 6), // "userID"
QT_MOC_LITERAL(14, 196, 6), // "regist"
QT_MOC_LITERAL(15, 203, 8), // "password"
QT_MOC_LITERAL(16, 212, 8), // "nickname"
QT_MOC_LITERAL(17, 221, 5), // "login"
QT_MOC_LITERAL(18, 227, 6), // "logout"
QT_MOC_LITERAL(19, 234, 7), // "islogin"
QT_MOC_LITERAL(20, 242, 14), // "modifyPassword"
QT_MOC_LITERAL(21, 257, 14), // "modifyNickname"
QT_MOC_LITERAL(22, 272, 15), // "modifySignaTure"
QT_MOC_LITERAL(23, 288, 9), // "signaTure"
QT_MOC_LITERAL(24, 298, 11), // "modifyPhoto"
QT_MOC_LITERAL(25, 310, 4), // "file"
QT_MOC_LITERAL(26, 315, 5), // "photo"
QT_MOC_LITERAL(27, 321, 10), // "registTime"
QT_MOC_LITERAL(28, 332, 13), // "vehicleOnline"
QT_MOC_LITERAL(29, 346, 8), // "pcOnline"
QT_MOC_LITERAL(30, 355, 13), // "handeldOnline"
QT_MOC_LITERAL(31, 369, 9) // "padOnline"

    },
    "Account\0userIDChanged\0\0passwordChanged\0"
    "nicknameChanged\0signaTureChanged\0"
    "photoChanged\0registTimeChanged\0"
    "vehicleOnlineChanged\0pcOnlineChanged\0"
    "handeldOnlineChanged\0padOnlineChanged\0"
    "isRegisted\0userID\0regist\0password\0"
    "nickname\0login\0logout\0islogin\0"
    "modifyPassword\0modifyNickname\0"
    "modifySignaTure\0signaTure\0modifyPhoto\0"
    "file\0photo\0registTime\0vehicleOnline\0"
    "pcOnline\0handeldOnline\0padOnline"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Account[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
      10,  148, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    0,  110,    2, 0x06 /* Public */,
       4,    0,  111,    2, 0x06 /* Public */,
       5,    0,  112,    2, 0x06 /* Public */,
       6,    0,  113,    2, 0x06 /* Public */,
       7,    0,  114,    2, 0x06 /* Public */,
       8,    0,  115,    2, 0x06 /* Public */,
       9,    0,  116,    2, 0x06 /* Public */,
      10,    0,  117,    2, 0x06 /* Public */,
      11,    0,  118,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  119,    2, 0x0a /* Public */,
      14,    3,  122,    2, 0x0a /* Public */,
      17,    2,  129,    2, 0x0a /* Public */,
      18,    0,  134,    2, 0x0a /* Public */,
      19,    0,  135,    2, 0x0a /* Public */,
      20,    1,  136,    2, 0x0a /* Public */,
      21,    1,  139,    2, 0x0a /* Public */,
      22,    1,  142,    2, 0x0a /* Public */,
      24,    1,  145,    2, 0x0a /* Public */,

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

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,   13,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   15,   16,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   13,   15,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,   15,
    QMetaType::Bool, QMetaType::QString,   16,
    QMetaType::Bool, QMetaType::QString,   23,
    QMetaType::Bool, QMetaType::QUrl,   25,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00495003,
      15, QMetaType::QString, 0x00495003,
      16, QMetaType::QString, 0x00495003,
      23, QMetaType::QString, 0x00495003,
      26, QMetaType::QString, 0x00495003,
      27, QMetaType::QString, 0x00495003,
      28, QMetaType::Bool, 0x00495003,
      29, QMetaType::Bool, 0x00495003,
      30, QMetaType::Bool, 0x00495003,
      31, QMetaType::Bool, 0x00495003,

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

       0        // eod
};

void Account::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Account *_t = static_cast<Account *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userIDChanged(); break;
        case 1: _t->passwordChanged(); break;
        case 2: _t->nicknameChanged(); break;
        case 3: _t->signaTureChanged(); break;
        case 4: _t->photoChanged(); break;
        case 5: _t->registTimeChanged(); break;
        case 6: _t->vehicleOnlineChanged(); break;
        case 7: _t->pcOnlineChanged(); break;
        case 8: _t->handeldOnlineChanged(); break;
        case 9: _t->padOnlineChanged(); break;
        case 10: { bool _r = _t->isRegisted((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->regist((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->login((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->logout();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->islogin();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->modifyPassword((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->modifyNickname((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->modifySignaTure((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->modifyPhoto((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::userIDChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::passwordChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::nicknameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::signaTureChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::photoChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::registTimeChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::vehicleOnlineChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::pcOnlineChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::handeldOnlineChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account::padOnlineChanged)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Account *_t = static_cast<Account *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->userID(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->password(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->nickname(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->signaTure(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->photo(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->registTime(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->vehicleOnline(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->pcOnline(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->handeldOnline(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->padOnline(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Account *_t = static_cast<Account *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setuserID(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setpassword(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setnickname(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setsignaTure(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setphoto(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setregistTime(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setvehicleOnline(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setpcOnline(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->sethandeldOnline(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setpadOnline(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Account::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Account.data,
      qt_meta_data_Account,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Account::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Account::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Account.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Account::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Account::userIDChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Account::passwordChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Account::nicknameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Account::signaTureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Account::photoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Account::registTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Account::vehicleOnlineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Account::pcOnlineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Account::handeldOnlineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Account::padOnlineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
