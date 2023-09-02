/****************************************************************************
** Meta object code from reading C++ file 'demodialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../demodialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'demodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DemoDialog_t {
    QByteArrayData data[17];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DemoDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DemoDialog_t qt_meta_stringdata_DemoDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DemoDialog"
QT_MOC_LITERAL(1, 11, 9), // "SIG_close"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "SIG_joinRoom"
QT_MOC_LITERAL(4, 35, 14), // "SIG_createRoom"
QT_MOC_LITERAL(5, 50, 11), // "SIG_setUser"
QT_MOC_LITERAL(6, 62, 12), // "slot_setInfo"
QT_MOC_LITERAL(7, 75, 4), // "name"
QT_MOC_LITERAL(8, 80, 6), // "iconid"
QT_MOC_LITERAL(9, 87, 17), // "on_pb_min_clicked"
QT_MOC_LITERAL(10, 105, 19), // "on_pb_close_clicked"
QT_MOC_LITERAL(11, 125, 18), // "on_pb_join_clicked"
QT_MOC_LITERAL(12, 144, 20), // "on_pb_create_clicked"
QT_MOC_LITERAL(13, 165, 18), // "on_pb_icon_clicked"
QT_MOC_LITERAL(14, 184, 19), // "on_pb_setup_clicked"
QT_MOC_LITERAL(15, 204, 25), // "slot_setPushButton_enable"
QT_MOC_LITERAL(16, 230, 4) // "flag"

    },
    "DemoDialog\0SIG_close\0\0SIG_joinRoom\0"
    "SIG_createRoom\0SIG_setUser\0slot_setInfo\0"
    "name\0iconid\0on_pb_min_clicked\0"
    "on_pb_close_clicked\0on_pb_join_clicked\0"
    "on_pb_create_clicked\0on_pb_icon_clicked\0"
    "on_pb_setup_clicked\0slot_setPushButton_enable\0"
    "flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DemoDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   78,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    0,   86,    2, 0x0a /* Public */,
      13,    0,   87,    2, 0x0a /* Public */,
      14,    0,   88,    2, 0x0a /* Public */,
      15,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,

       0        // eod
};

void DemoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DemoDialog *_t = static_cast<DemoDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_close(); break;
        case 1: _t->SIG_joinRoom(); break;
        case 2: _t->SIG_createRoom(); break;
        case 3: _t->SIG_setUser(); break;
        case 4: _t->slot_setInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_pb_min_clicked(); break;
        case 6: _t->on_pb_close_clicked(); break;
        case 7: _t->on_pb_join_clicked(); break;
        case 8: _t->on_pb_create_clicked(); break;
        case 9: _t->on_pb_icon_clicked(); break;
        case 10: _t->on_pb_setup_clicked(); break;
        case 11: _t->slot_setPushButton_enable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DemoDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DemoDialog::SIG_close)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DemoDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DemoDialog::SIG_joinRoom)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DemoDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DemoDialog::SIG_createRoom)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DemoDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DemoDialog::SIG_setUser)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject DemoDialog::staticMetaObject = {
    { &CustomMoveDialog::staticMetaObject, qt_meta_stringdata_DemoDialog.data,
      qt_meta_data_DemoDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DemoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DemoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DemoDialog.stringdata0))
        return static_cast<void*>(const_cast< DemoDialog*>(this));
    return CustomMoveDialog::qt_metacast(_clname);
}

int DemoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomMoveDialog::qt_metacall(_c, _id, _a);
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
void DemoDialog::SIG_close()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DemoDialog::SIG_joinRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void DemoDialog::SIG_createRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DemoDialog::SIG_setUser()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
