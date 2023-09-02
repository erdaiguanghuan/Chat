/****************************************************************************
** Meta object code from reading C++ file 'roomdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../roomdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoomDialog_t {
    QByteArrayData data[14];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoomDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoomDialog_t qt_meta_stringdata_RoomDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RoomDialog"
QT_MOC_LITERAL(1, 11, 12), // "SIG_quitRoom"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "slot_setRoomID"
QT_MOC_LITERAL(4, 40, 6), // "roomid"
QT_MOC_LITERAL(5, 47, 12), // "slot_addUser"
QT_MOC_LITERAL(6, 60, 8), // "QWidget*"
QT_MOC_LITERAL(7, 69, 4), // "user"
QT_MOC_LITERAL(8, 74, 15), // "slot_removeUser"
QT_MOC_LITERAL(9, 90, 19), // "on_pb_colse_clicked"
QT_MOC_LITERAL(10, 110, 17), // "on_pb_max_clicked"
QT_MOC_LITERAL(11, 128, 17), // "on_pb_min_clicked"
QT_MOC_LITERAL(12, 146, 18), // "on_pb_hide_clicked"
QT_MOC_LITERAL(13, 165, 18) // "on_pb_quit_clicked"

    },
    "RoomDialog\0SIG_quitRoom\0\0slot_setRoomID\0"
    "roomid\0slot_addUser\0QWidget*\0user\0"
    "slot_removeUser\0on_pb_colse_clicked\0"
    "on_pb_max_clicked\0on_pb_min_clicked\0"
    "on_pb_hide_clicked\0on_pb_quit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoomDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   60,    2, 0x0a /* Public */,
       5,    1,   63,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoomDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoomDialog *_t = static_cast<RoomDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_quitRoom(); break;
        case 1: _t->slot_setRoomID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slot_addUser((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->slot_removeUser((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->on_pb_colse_clicked(); break;
        case 5: _t->on_pb_max_clicked(); break;
        case 6: _t->on_pb_min_clicked(); break;
        case 7: _t->on_pb_hide_clicked(); break;
        case 8: _t->on_pb_quit_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_quitRoom)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RoomDialog::staticMetaObject = {
    { &CustomMoveDialog::staticMetaObject, qt_meta_stringdata_RoomDialog.data,
      qt_meta_data_RoomDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RoomDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RoomDialog.stringdata0))
        return static_cast<void*>(const_cast< RoomDialog*>(this));
    return CustomMoveDialog::qt_metacast(_clname);
}

int RoomDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomMoveDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void RoomDialog::SIG_quitRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
