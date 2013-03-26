/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 35),
QT_MOC_LITERAL(2, 47, 0),
QT_MOC_LITERAL(3, 48, 5),
QT_MOC_LITERAL(4, 54, 20),
QT_MOC_LITERAL(5, 75, 29),
QT_MOC_LITERAL(6, 105, 27),
QT_MOC_LITERAL(7, 133, 33),
QT_MOC_LITERAL(8, 167, 19),
QT_MOC_LITERAL(9, 187, 21),
QT_MOC_LITERAL(10, 209, 24),
QT_MOC_LITERAL(11, 234, 20),
QT_MOC_LITERAL(12, 255, 20),
QT_MOC_LITERAL(13, 276, 25),
QT_MOC_LITERAL(14, 302, 20),
QT_MOC_LITERAL(15, 323, 6)
    },
    "MainWindow\0on_deviceSelect_currentIndexChanged\0"
    "\0index\0on_newDevice_clicked\0"
    "on_deviceRemoveButton_clicked\0"
    "on_deviceSaveButton_clicked\0"
    "on_roomSelect_currentIndexChanged\0"
    "on_saveRoom_clicked\0on_removeRoom_clicked\0"
    "on_newRoomButton_clicked\0device_timer_timeout\0"
    "check_status_timeout\0check_temperature_timeout\0"
    "update_StatusMonitor\0update\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08,
       4,    0,   77,    2, 0x08,
       5,    0,   78,    2, 0x08,
       6,    0,   79,    2, 0x08,
       7,    0,   80,    2, 0x08,
       8,    0,   81,    2, 0x08,
       9,    0,   82,    2, 0x08,
      10,    0,   83,    2, 0x08,
      11,    0,   84,    2, 0x08,
      12,    0,   85,    2, 0x08,
      13,    0,   86,    2, 0x08,
      14,    1,   87,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
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
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_deviceSelect_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_newDevice_clicked(); break;
        case 2: _t->on_deviceRemoveButton_clicked(); break;
        case 3: _t->on_deviceSaveButton_clicked(); break;
        case 4: _t->on_roomSelect_currentIndexChanged(); break;
        case 5: _t->on_saveRoom_clicked(); break;
        case 6: _t->on_removeRoom_clicked(); break;
        case 7: _t->on_newRoomButton_clicked(); break;
        case 8: _t->device_timer_timeout(); break;
        case 9: _t->check_status_timeout(); break;
        case 10: _t->check_temperature_timeout(); break;
        case 11: _t->update_StatusMonitor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
