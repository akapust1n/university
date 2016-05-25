/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "floor_button_pushed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "lift_button_pushed"
QT_MOC_LITERAL(4, 51, 7), // "hide_el"
QT_MOC_LITERAL(5, 59, 7), // "show_el"
QT_MOC_LITERAL(6, 67, 13), // "floor_changed"
QT_MOC_LITERAL(7, 81, 14), // "change_lift_st"
QT_MOC_LITERAL(8, 96, 10), // "state_lift"
QT_MOC_LITERAL(9, 107, 20), // "on_floor1BTN_clicked"
QT_MOC_LITERAL(10, 128, 20), // "on_floor2BTN_clicked"
QT_MOC_LITERAL(11, 149, 20), // "on_floor3BTN_clicked"
QT_MOC_LITERAL(12, 170, 20), // "on_floor4BTN_clicked"
QT_MOC_LITERAL(13, 191, 20), // "on_floor5BTN_clicked"
QT_MOC_LITERAL(14, 212, 20), // "on_floor6BTN_clicked"
QT_MOC_LITERAL(15, 233, 20) // "on_floor7BTN_clicked"

    },
    "MainWindow\0floor_button_pushed\0\0"
    "lift_button_pushed\0hide_el\0show_el\0"
    "floor_changed\0change_lift_st\0state_lift\0"
    "on_floor1BTN_clicked\0on_floor2BTN_clicked\0"
    "on_floor3BTN_clicked\0on_floor4BTN_clicked\0"
    "on_floor5BTN_clicked\0on_floor6BTN_clicked\0"
    "on_floor7BTN_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   85,    2, 0x0a /* Public */,
       5,    0,   86,    2, 0x0a /* Public */,
       6,    1,   87,    2, 0x0a /* Public */,
       7,    1,   90,    2, 0x0a /* Public */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->floor_button_pushed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->lift_button_pushed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->hide_el(); break;
        case 3: _t->show_el(); break;
        case 4: _t->floor_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->change_lift_st((*reinterpret_cast< state_lift(*)>(_a[1]))); break;
        case 6: _t->on_floor1BTN_clicked(); break;
        case 7: _t->on_floor2BTN_clicked(); break;
        case 8: _t->on_floor3BTN_clicked(); break;
        case 9: _t->on_floor4BTN_clicked(); break;
        case 10: _t->on_floor5BTN_clicked(); break;
        case 11: _t->on_floor6BTN_clicked(); break;
        case 12: _t->on_floor7BTN_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::floor_button_pushed)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::lift_button_pushed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::floor_button_pushed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::lift_button_pushed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
