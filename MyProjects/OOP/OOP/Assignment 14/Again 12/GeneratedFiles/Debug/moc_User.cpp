/****************************************************************************
** Meta object code from reading C++ file 'User.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../User.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'User.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_User_t {
    QByteArrayData data[11];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_User_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_User_t qt_meta_stringdata_User = {
    {
QT_MOC_LITERAL(0, 0, 4), // "User"
QT_MOC_LITERAL(1, 5, 12), // "filterMovies"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "addMovie"
QT_MOC_LITERAL(4, 28, 8), // "delMovie"
QT_MOC_LITERAL(5, 37, 9), // "likeMovie"
QT_MOC_LITERAL(6, 47, 7), // "showCSV"
QT_MOC_LITERAL(7, 55, 8), // "showHTML"
QT_MOC_LITERAL(8, 64, 9), // "nextMovie"
QT_MOC_LITERAL(9, 74, 7), // "undoFct"
QT_MOC_LITERAL(10, 82, 7) // "redoFct"

    },
    "User\0filterMovies\0\0addMovie\0delMovie\0"
    "likeMovie\0showCSV\0showHTML\0nextMovie\0"
    "undoFct\0redoFct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_User[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void User::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        User *_t = static_cast<User *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterMovies(); break;
        case 1: _t->addMovie(); break;
        case 2: _t->delMovie(); break;
        case 3: _t->likeMovie(); break;
        case 4: _t->showCSV(); break;
        case 5: _t->showHTML(); break;
        case 6: _t->nextMovie(); break;
        case 7: _t->undoFct(); break;
        case 8: _t->redoFct(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject User::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_User.data,
      qt_meta_data_User,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *User::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *User::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_User.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int User::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
