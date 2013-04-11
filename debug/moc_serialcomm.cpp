/****************************************************************************
** Meta object code from reading C++ file 'serialcomm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serialcomm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialcomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialComm_t {
    QByteArrayData data[10];
    char stringdata[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SerialComm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SerialComm_t qt_meta_stringdata_SerialComm = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 17),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 3),
QT_MOC_LITERAL(4, 34, 18),
QT_MOC_LITERAL(5, 53, 12),
QT_MOC_LITERAL(6, 66, 6),
QT_MOC_LITERAL(7, 73, 14),
QT_MOC_LITERAL(8, 88, 14),
QT_MOC_LITERAL(9, 103, 11)
    },
    "SerialComm\0devstatusResponse\0\0msg\0"
    "tempStatusResponse\0statusUpdate\0update\0"
    "processTimeout\0handleResponse\0writeSerial\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialComm[] = {

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
       1,    1,   44,    2, 0x05,
       4,    1,   47,    2, 0x05,
       5,    1,   50,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    0,   53,    2, 0x0a,
       8,    0,   54,    2, 0x0a,
       9,    1,   55,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void SerialComm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialComm *_t = static_cast<SerialComm *>(_o);
        switch (_id) {
        case 0: _t->devstatusResponse((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->tempStatusResponse((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->statusUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->processTimeout(); break;
        case 4: _t->handleResponse(); break;
        case 5: _t->writeSerial((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialComm::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialComm::devstatusResponse)) {
                *result = 0;
            }
        }
        {
            typedef void (SerialComm::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialComm::tempStatusResponse)) {
                *result = 1;
            }
        }
        {
            typedef void (SerialComm::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialComm::statusUpdate)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject SerialComm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialComm.data,
      qt_meta_data_SerialComm,  qt_static_metacall, 0, 0}
};


const QMetaObject *SerialComm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialComm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialComm.stringdata))
        return static_cast<void*>(const_cast< SerialComm*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialComm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SerialComm::devstatusResponse(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialComm::tempStatusResponse(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialComm::statusUpdate(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
