/****************************************************************************
** Meta object code from reading C++ file 'room.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../homelogic/room.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'room.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Room_t {
    QByteArrayData data[7];
    char stringdata[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Room_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Room_t qt_meta_stringdata_Room = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 9),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 6),
QT_MOC_LITERAL(4, 23, 8),
QT_MOC_LITERAL(5, 32, 8),
QT_MOC_LITERAL(6, 41, 14)
    },
    "Room\0lightsOff\0\0roomID\0lightsOn\0"
    "doorLock\0check_location\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Room[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,
       4,    1,   37,    2, 0x05,
       5,    1,   40,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Room::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Room *_t = static_cast<Room *>(_o);
        switch (_id) {
        case 0: _t->lightsOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->lightsOn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->doorLock((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->check_location(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Room::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Room::lightsOff)) {
                *result = 0;
            }
        }
        {
            typedef void (Room::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Room::lightsOn)) {
                *result = 1;
            }
        }
        {
            typedef void (Room::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Room::doorLock)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Room::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Room.data,
      qt_meta_data_Room,  qt_static_metacall, 0, 0}
};


const QMetaObject *Room::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Room::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Room.stringdata))
        return static_cast<void*>(const_cast< Room*>(this));
    return QObject::qt_metacast(_clname);
}

int Room::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Room::lightsOff(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Room::lightsOn(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Room::doorLock(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
