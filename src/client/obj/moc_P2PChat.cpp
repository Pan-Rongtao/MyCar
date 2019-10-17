/****************************************************************************
** Meta object code from reading C++ file 'P2PChat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../P2PChat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'P2PChat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_P2PChat_t {
    QByteArrayData data[12];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_P2PChat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_P2PChat_t qt_meta_stringdata_P2PChat = {
    {
QT_MOC_LITERAL(0, 0, 7), // "P2PChat"
QT_MOC_LITERAL(1, 8, 12), // "signalUpdate"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "friendIDChanged"
QT_MOC_LITERAL(4, 38, 21), // "friendNicknameChanged"
QT_MOC_LITERAL(5, 60, 19), // "enterFromFriendList"
QT_MOC_LITERAL(6, 80, 5), // "index"
QT_MOC_LITERAL(7, 86, 11), // "sendMessage"
QT_MOC_LITERAL(8, 98, 3), // "msg"
QT_MOC_LITERAL(9, 102, 6), // "update"
QT_MOC_LITERAL(10, 109, 8), // "friendID"
QT_MOC_LITERAL(11, 118, 14) // "friendNickname"

    },
    "P2PChat\0signalUpdate\0\0friendIDChanged\0"
    "friendNicknameChanged\0enterFromFriendList\0"
    "index\0sendMessage\0msg\0update\0friendID\0"
    "friendNickname"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_P2PChat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00495003,
      11, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       1,
       2,

       0        // eod
};

void P2PChat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        P2PChat *_t = static_cast<P2PChat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUpdate(); break;
        case 1: _t->friendIDChanged(); break;
        case 2: _t->friendNicknameChanged(); break;
        case 3: _t->enterFromFriendList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (P2PChat::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&P2PChat::signalUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (P2PChat::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&P2PChat::friendIDChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (P2PChat::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&P2PChat::friendNicknameChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        P2PChat *_t = static_cast<P2PChat *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->friendID(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->friendNickname(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        P2PChat *_t = static_cast<P2PChat *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setfriendID(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setfriendNickname(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject P2PChat::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_P2PChat.data,
      qt_meta_data_P2PChat,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *P2PChat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *P2PChat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_P2PChat.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int P2PChat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void P2PChat::signalUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void P2PChat::friendIDChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void P2PChat::friendNicknameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
