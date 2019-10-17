/****************************************************************************
** Meta object code from reading C++ file 'Type.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Type.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Type.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Type_t {
    QByteArrayData data[18];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Type_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Type_t qt_meta_stringdata_Type = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Type"
QT_MOC_LITERAL(1, 5, 5), // "PageE"
QT_MOC_LITERAL(2, 11, 12), // "Page_Account"
QT_MOC_LITERAL(3, 24, 11), // "Page_Regist"
QT_MOC_LITERAL(4, 36, 10), // "Page_Login"
QT_MOC_LITERAL(5, 47, 8), // "Page_Car"
QT_MOC_LITERAL(6, 56, 7), // "Page_PC"
QT_MOC_LITERAL(7, 64, 14), // "Page_Cellphone"
QT_MOC_LITERAL(8, 79, 12), // "Page_Message"
QT_MOC_LITERAL(9, 92, 13), // "Page_Contacts"
QT_MOC_LITERAL(10, 106, 12), // "Page_P2PChat"
QT_MOC_LITERAL(11, 119, 14), // "Page_GroupChat"
QT_MOC_LITERAL(12, 134, 4), // "PopE"
QT_MOC_LITERAL(13, 139, 8), // "Pop_None"
QT_MOC_LITERAL(14, 148, 13), // "Pop_AddFriend"
QT_MOC_LITERAL(15, 162, 15), // "Pop_CreateGroup"
QT_MOC_LITERAL(16, 178, 13), // "Pop_GroupInfo"
QT_MOC_LITERAL(17, 192, 18) // "Pop_AddGroupMember"

    },
    "Type\0PageE\0Page_Account\0Page_Regist\0"
    "Page_Login\0Page_Car\0Page_PC\0Page_Cellphone\0"
    "Page_Message\0Page_Contacts\0Page_P2PChat\0"
    "Page_GroupChat\0PopE\0Pop_None\0Pop_AddFriend\0"
    "Pop_CreateGroup\0Pop_GroupInfo\0"
    "Pop_AddGroupMember"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Type[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,   10,   22,
      12, 0x0,    5,   42,

 // enum data: key, value
       2, uint(Type::Page_Account),
       3, uint(Type::Page_Regist),
       4, uint(Type::Page_Login),
       5, uint(Type::Page_Car),
       6, uint(Type::Page_PC),
       7, uint(Type::Page_Cellphone),
       8, uint(Type::Page_Message),
       9, uint(Type::Page_Contacts),
      10, uint(Type::Page_P2PChat),
      11, uint(Type::Page_GroupChat),
      13, uint(Type::Pop_None),
      14, uint(Type::Pop_AddFriend),
      15, uint(Type::Pop_CreateGroup),
      16, uint(Type::Pop_GroupInfo),
      17, uint(Type::Pop_AddGroupMember),

       0        // eod
};

void Type::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Type::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Type.data,
      qt_meta_data_Type,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Type::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Type::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Type.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Type::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
