/****************************************************************************
** Meta object code from reading C++ file 'bluetooth.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bluetooth.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetooth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Bluetooth_t {
    QByteArrayData data[10];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Bluetooth_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Bluetooth_t qt_meta_stringdata_Bluetooth = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 10),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 9),
QT_MOC_LITERAL(4, 32, 12),
QT_MOC_LITERAL(5, 45, 15),
QT_MOC_LITERAL(6, 61, 8),
QT_MOC_LITERAL(7, 70, 9),
QT_MOC_LITERAL(8, 80, 13),
QT_MOC_LITERAL(9, 94, 7)
    },
    "Bluetooth\0DeviceScan\0\0read_macs\0"
    "dev_Response\0ui_notification\0rcvd_mac\0"
    "rcvd_name\0welcome_sound\0snd_mac\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bluetooth[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a,
       3,    0,   40,    2, 0x0a,
       4,    0,   41,    2, 0x0a,
       5,    2,   42,    2, 0x0a,
       8,    1,   47,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void Bluetooth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Bluetooth *_t = static_cast<Bluetooth *>(_o);
        switch (_id) {
        case 0: _t->DeviceScan(); break;
        case 1: _t->read_macs(); break;
        case 2: _t->dev_Response(); break;
        case 3: _t->ui_notification((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->welcome_sound((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Bluetooth::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Bluetooth.data,
      qt_meta_data_Bluetooth,  qt_static_metacall, 0, 0}
};


const QMetaObject *Bluetooth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bluetooth::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bluetooth.stringdata))
        return static_cast<void*>(const_cast< Bluetooth*>(this));
    return QDialog::qt_metacast(_clname);
}

int Bluetooth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
