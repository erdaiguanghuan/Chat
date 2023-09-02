/****************************************************************************
** Meta object code from reading C++ file 'desk_read.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VideoApi/desk_read.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desk_read.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeskReadThread_t {
    QByteArrayData data[3];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeskReadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeskReadThread_t qt_meta_stringdata_DeskReadThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DeskReadThread"
QT_MOC_LITERAL(1, 15, 19), // "slot_threadReadMore"
QT_MOC_LITERAL(2, 35, 0) // ""

    },
    "DeskReadThread\0slot_threadReadMore\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeskReadThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DeskReadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeskReadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_threadReadMore(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DeskReadThread::staticMetaObject = { {
    &WorkThread::staticMetaObject,
    qt_meta_stringdata_DeskReadThread.data,
    qt_meta_data_DeskReadThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeskReadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeskReadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeskReadThread.stringdata0))
        return static_cast<void*>(this);
    return WorkThread::qt_metacast(_clname);
}

int DeskReadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WorkThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Desk_Read_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Desk_Read_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Desk_Read_t qt_meta_stringdata_Desk_Read = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Desk_Read"
QT_MOC_LITERAL(1, 10, 15), // "SIG_screenFrame"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "img"
QT_MOC_LITERAL(4, 31, 19), // "SIG_screenFrameData"
QT_MOC_LITERAL(5, 51, 2), // "ba"
QT_MOC_LITERAL(6, 54, 5), // "start"
QT_MOC_LITERAL(7, 60, 5), // "pause"
QT_MOC_LITERAL(8, 66, 20) // "slot_getScreeenFrame"

    },
    "Desk_Read\0SIG_screenFrame\0\0img\0"
    "SIG_screenFrameData\0ba\0start\0pause\0"
    "slot_getScreeenFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Desk_Read[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Desk_Read::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Desk_Read *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_screenFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->SIG_screenFrameData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->start(); break;
        case 3: _t->pause(); break;
        case 4: _t->slot_getScreeenFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Desk_Read::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Desk_Read::SIG_screenFrame)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Desk_Read::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Desk_Read::SIG_screenFrameData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Desk_Read::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Desk_Read.data,
    qt_meta_data_Desk_Read,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Desk_Read::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Desk_Read::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Desk_Read.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Desk_Read::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Desk_Read::SIG_screenFrame(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Desk_Read::SIG_screenFrameData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
