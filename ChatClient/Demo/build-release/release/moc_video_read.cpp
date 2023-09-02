/****************************************************************************
** Meta object code from reading C++ file 'video_read.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VideoApi/video_read.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_read.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_video_read_t {
    QByteArrayData data[9];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_video_read_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_video_read_t qt_meta_stringdata_video_read = {
    {
QT_MOC_LITERAL(0, 0, 10), // "video_read"
QT_MOC_LITERAL(1, 11, 14), // "SIG_videoFrame"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "image"
QT_MOC_LITERAL(4, 33, 18), // "SIG_videoFrameData"
QT_MOC_LITERAL(5, 52, 2), // "bt"
QT_MOC_LITERAL(6, 55, 5), // "start"
QT_MOC_LITERAL(7, 61, 5), // "pause"
QT_MOC_LITERAL(8, 67, 13) // "slot_readMore"

    },
    "video_read\0SIG_videoFrame\0\0image\0"
    "SIG_videoFrameData\0bt\0start\0pause\0"
    "slot_readMore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_video_read[] = {

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

void video_read::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<video_read *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_videoFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->SIG_videoFrameData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->start(); break;
        case 3: _t->pause(); break;
        case 4: _t->slot_readMore(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (video_read::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_read::SIG_videoFrame)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (video_read::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&video_read::SIG_videoFrameData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject video_read::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_video_read.data,
    qt_meta_data_video_read,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *video_read::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *video_read::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_video_read.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int video_read::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void video_read::SIG_videoFrame(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void video_read::SIG_videoFrameData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
