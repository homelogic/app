/****************************************************************************
** Meta object code from reading C++ file 'device.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../device.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Device_t {
    QByteArrayData data[16];
    char stringdata[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Device_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Device_t qt_meta_stringdata_Device = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 12),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 3),
QT_MOC_LITERAL(4, 25, 12),
QT_MOC_LITERAL(5, 38, 6),
QT_MOC_LITERAL(6, 45, 18),
QT_MOC_LITERAL(7, 64, 13),
QT_MOC_LITERAL(8, 78, 13),
QT_MOC_LITERAL(9, 92, 18),
QT_MOC_LITERAL(10, 111, 8),
QT_MOC_LITERAL(11, 120, 23),
QT_MOC_LITERAL(12, 144, 15),
QT_MOC_LITERAL(13, 160, 6),
QT_MOC_LITERAL(14, 167, 14),
QT_MOC_LITERAL(15, 182, 14)
    },
    "Device\0writeRequest\0\0msg\0statusUpdate\0"
    "update\0currentTemperature\0check_updated\0"
    "currentStatus\0handleDeviceStatus\0"
    "response\0handleTemperatureStatus\0"
    "room_Lights_Off\0roomID\0room_Lights_On\0"
    "room_Door_Lock\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Device[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x05,
       4,    1,   67,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   70,    2, 0x0a,
       7,    0,   71,    2, 0x0a,
       8,    0,   72,    2, 0x0a,
       9,    1,   73,    2, 0x08,
      11,    1,   76,    2, 0x08,
      12,    1,   79,    2, 0x08,
      14,    1,   82,    2, 0x08,
      15,    1,   85,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void Device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Device *_t = static_cast<Device *>(_o);
        switch (_id) {
        case 0: _t->writeRequest((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->statusUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->currentTemperature(); break;
        case 3: _t->check_updated(); break;
        case 4: _t->currentStatus(); break;
        case 5: _t->handleDeviceStatus((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->handleTemperatureStatus((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->room_Lights_Off((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->room_Lights_On((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->room_Door_Lock((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Device::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device::writeRequest)) {
                *result = 0;
            }
        }
        {
            typedef void (Device::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Device::statusUpdate)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Device::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Device.data,
      qt_meta_data_Device,  qt_static_metacall, 0, 0}
};


const QMetaObject *Device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Device::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Device.stringdata))
        return static_cast<void*>(const_cast< Device*>(this));
    return QObject::qt_metacast(_clname);
}

int Device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Device::writeRequest(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Device::statusUpdate(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
