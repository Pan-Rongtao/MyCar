/****************************************************************************
** Meta object code from reading C++ file 'LayerManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LayerManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayerManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LayerManager_t {
    QByteArrayData data[14];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayerManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayerManager_t qt_meta_stringdata_LayerManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LayerManager"
QT_MOC_LITERAL(1, 13, 19), // "notLoginWarnChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "currentPageChanged"
QT_MOC_LITERAL(4, 53, 17), // "currentPopChanged"
QT_MOC_LITERAL(5, 71, 10), // "switchPage"
QT_MOC_LITERAL(6, 82, 4), // "page"
QT_MOC_LITERAL(7, 87, 9), // "switchPop"
QT_MOC_LITERAL(8, 97, 3), // "pop"
QT_MOC_LITERAL(9, 101, 12), // "notLoginWarn"
QT_MOC_LITERAL(10, 114, 11), // "currentPage"
QT_MOC_LITERAL(11, 126, 11), // "Type::PageE"
QT_MOC_LITERAL(12, 138, 10), // "currentPop"
QT_MOC_LITERAL(13, 149, 10) // "Type::PopE"

    },
    "LayerManager\0notLoginWarnChanged\0\0"
    "currentPageChanged\0currentPopChanged\0"
    "switchPage\0page\0switchPop\0pop\0"
    "notLoginWarn\0currentPage\0Type::PageE\0"
    "currentPop\0Type::PopE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayerManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // properties: name, type, flags
       9, QMetaType::Bool, 0x00495003,
      10, 0x80000000 | 11, 0x0049500b,
      12, 0x80000000 | 13, 0x0049500b,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void LayerManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayerManager *_t = static_cast<LayerManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->notLoginWarnChanged(); break;
        case 1: _t->currentPageChanged(); break;
        case 2: _t->currentPopChanged(); break;
        case 3: _t->switchPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->switchPop((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LayerManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LayerManager::notLoginWarnChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LayerManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LayerManager::currentPageChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LayerManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LayerManager::currentPopChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        LayerManager *_t = static_cast<LayerManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->notLoginWarn(); break;
        case 1: *reinterpret_cast< Type::PageE*>(_v) = _t->currentPage(); break;
        case 2: *reinterpret_cast< Type::PopE*>(_v) = _t->currentPop(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        LayerManager *_t = static_cast<LayerManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setnotLoginWarn(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setcurrentPage(*reinterpret_cast< Type::PageE*>(_v)); break;
        case 2: _t->setcurrentPop(*reinterpret_cast< Type::PopE*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

static const QMetaObject * const qt_meta_extradata_LayerManager[] = {
        &Type::staticMetaObject,
    nullptr
};

const QMetaObject LayerManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LayerManager.data,
      qt_meta_data_LayerManager,  qt_static_metacall, qt_meta_extradata_LayerManager, nullptr}
};


const QMetaObject *LayerManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LayerManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LayerManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LayerManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LayerManager::notLoginWarnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LayerManager::currentPageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LayerManager::currentPopChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
