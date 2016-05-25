/****************************************************************************
** Meta object code from reading C++ file 'doors.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "doors.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doors.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_doors_t {
    QByteArrayData data[9];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_doors_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_doors_t qt_meta_stringdata_doors = {
    {
QT_MOC_LITERAL(0, 0, 5), // "doors"
QT_MOC_LITERAL(1, 6, 9), // "change_st"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "state"
QT_MOC_LITERAL(4, 23, 6), // "opened"
QT_MOC_LITERAL(5, 30, 6), // "closed"
QT_MOC_LITERAL(6, 37, 4), // "open"
QT_MOC_LITERAL(7, 42, 5), // "close"
QT_MOC_LITERAL(8, 48, 6) // "set_st"

    },
    "doors\0change_st\0\0state\0opened\0closed\0"
    "open\0close\0set_st"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_doors[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void doors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        doors *_t = static_cast<doors *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change_st((*reinterpret_cast< state(*)>(_a[1]))); break;
        case 1: _t->opened(); break;
        case 2: _t->closed(); break;
        case 3: _t->open(); break;
        case 4: _t->close(); break;
        case 5: _t->set_st((*reinterpret_cast< state(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (doors::*_t)(state );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&doors::change_st)) {
                *result = 0;
            }
        }
        {
            typedef void (doors::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&doors::opened)) {
                *result = 1;
            }
        }
        {
            typedef void (doors::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&doors::closed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject doors::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_doors.data,
      qt_meta_data_doors,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *doors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *doors::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_doors.stringdata0))
        return static_cast<void*>(const_cast< doors*>(this));
    return QObject::qt_metacast(_clname);
}

int doors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void doors::change_st(state _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void doors::opened()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void doors::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
