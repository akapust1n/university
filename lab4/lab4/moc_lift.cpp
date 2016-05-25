/****************************************************************************
** Meta object code from reading C++ file 'lift.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lift.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lift.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_lift_t {
    QByteArrayData data[17];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lift_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lift_t qt_meta_stringdata_lift = {
    {
QT_MOC_LITERAL(0, 0, 4), // "lift"
QT_MOC_LITERAL(1, 5, 13), // "floor_changed"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "open_doors"
QT_MOC_LITERAL(4, 31, 11), // "close_doors"
QT_MOC_LITERAL(5, 43, 10), // "st_changed"
QT_MOC_LITERAL(6, 54, 10), // "state_lift"
QT_MOC_LITERAL(7, 65, 7), // "arrived"
QT_MOC_LITERAL(8, 73, 9), // "show_lift"
QT_MOC_LITERAL(9, 83, 9), // "hide_lift"
QT_MOC_LITERAL(10, 93, 17), // "doors_opened_slot"
QT_MOC_LITERAL(11, 111, 17), // "doors_closed_slot"
QT_MOC_LITERAL(12, 129, 12), // "arrived_slot"
QT_MOC_LITERAL(13, 142, 9), // "floor_but"
QT_MOC_LITERAL(14, 152, 2), // "f1"
QT_MOC_LITERAL(15, 155, 8), // "lift_but"
QT_MOC_LITERAL(16, 164, 2) // "f2"

    },
    "lift\0floor_changed\0\0open_doors\0"
    "close_doors\0st_changed\0state_lift\0"
    "arrived\0show_lift\0hide_lift\0"
    "doors_opened_slot\0doors_closed_slot\0"
    "arrived_slot\0floor_but\0f1\0lift_but\0"
    "f2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lift[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,
       4,    0,   78,    2, 0x06 /* Public */,
       5,    1,   79,    2, 0x06 /* Public */,
       7,    0,   82,    2, 0x06 /* Public */,
       8,    0,   83,    2, 0x06 /* Public */,
       9,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      15,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void lift::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lift *_t = static_cast<lift *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->floor_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->open_doors(); break;
        case 2: _t->close_doors(); break;
        case 3: _t->st_changed((*reinterpret_cast< state_lift(*)>(_a[1]))); break;
        case 4: _t->arrived(); break;
        case 5: _t->show_lift(); break;
        case 6: _t->hide_lift(); break;
        case 7: _t->doors_opened_slot(); break;
        case 8: _t->doors_closed_slot(); break;
        case 9: _t->arrived_slot(); break;
        case 10: _t->floor_but((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->lift_but((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (lift::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lift::floor_changed)) {
                *result = 0;
            }
        }
        {
            typedef void (lift::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lift::open_doors)) {
                *result = 1;
            }
        }
        {
            typedef void (lift::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lift::close_doors)) {
                *result = 2;
            }
        }
        {
            typedef void (lift::*_t)(state_lift );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lift::st_changed)) {
                *result = 3;
            }
        }
        {
            typedef void (lift::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lift::arrived)) {
                *result = 4;
            }
        }
        {
            typedef void (lift::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lift::show_lift)) {
                *result = 5;
            }
        }
        {
            typedef void (lift::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lift::hide_lift)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject lift::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_lift.data,
      qt_meta_data_lift,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *lift::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lift::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_lift.stringdata0))
        return static_cast<void*>(const_cast< lift*>(this));
    return QObject::qt_metacast(_clname);
}

int lift::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void lift::floor_changed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lift::open_doors()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void lift::close_doors()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void lift::st_changed(state_lift _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void lift::arrived()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void lift::show_lift()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void lift::hide_lift()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
