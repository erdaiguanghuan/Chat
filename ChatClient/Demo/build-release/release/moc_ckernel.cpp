/****************************************************************************
** Meta object code from reading C++ file 'ckernel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ckernel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ckernel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SendThread_t {
    QByteArrayData data[7];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SendThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SendThread_t qt_meta_stringdata_SendThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SendThread"
QT_MOC_LITERAL(1, 11, 19), // "slot_threadSendData"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "socket"
QT_MOC_LITERAL(4, 39, 5), // "char*"
QT_MOC_LITERAL(5, 45, 3), // "buf"
QT_MOC_LITERAL(6, 49, 4) // "nlen"

    },
    "SendThread\0slot_threadSendData\0\0socket\0"
    "char*\0buf\0nlen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SendThread[] = {

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
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,

       0        // eod
};

void SendThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SendThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_threadSendData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SendThread::staticMetaObject = { {
    &WorkThread::staticMetaObject,
    qt_meta_stringdata_SendThread.data,
    qt_meta_data_SendThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SendThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SendThread.stringdata0))
        return static_cast<void*>(this);
    return WorkThread::qt_metacast(_clname);
}

int SendThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_CKernel_t {
    QByteArrayData data[55];
    char stringdata0[777];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CKernel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CKernel_t qt_meta_stringdata_CKernel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CKernel"
QT_MOC_LITERAL(1, 8, 18), // "SIG_sendVideoFrame"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "socket"
QT_MOC_LITERAL(4, 35, 5), // "char*"
QT_MOC_LITERAL(5, 41, 3), // "buf"
QT_MOC_LITERAL(6, 45, 4), // "nlen"
QT_MOC_LITERAL(7, 50, 9), // "setNetMap"
QT_MOC_LITERAL(8, 60, 9), // "setConfig"
QT_MOC_LITERAL(9, 70, 12), // "slot_destroy"
QT_MOC_LITERAL(10, 83, 13), // "slot_dealData"
QT_MOC_LITERAL(11, 97, 16), // "slot_dealLoginRs"
QT_MOC_LITERAL(12, 114, 19), // "slot_dealRegisterRs"
QT_MOC_LITERAL(13, 134, 21), // "slot_dealCreateRoomRs"
QT_MOC_LITERAL(14, 156, 19), // "slot_dealJoinRoomRs"
QT_MOC_LITERAL(15, 176, 21), // "slot_dealRoomMemberRq"
QT_MOC_LITERAL(16, 198, 19), // "slot_dealUserInfoRq"
QT_MOC_LITERAL(17, 218, 20), // "slot_dealLeaveRoomRq"
QT_MOC_LITERAL(18, 239, 19), // "slot_dealAudioFrame"
QT_MOC_LITERAL(19, 259, 19), // "slot_dealVideoFrame"
QT_MOC_LITERAL(20, 279, 19), // "slot_clientSendData"
QT_MOC_LITERAL(21, 299, 24), // "slot_clientVideoSendData"
QT_MOC_LITERAL(22, 324, 24), // "slot_clientAudioSendData"
QT_MOC_LITERAL(23, 349, 20), // "slot_destroyInstance"
QT_MOC_LITERAL(24, 370, 19), // "slot_registerCommit"
QT_MOC_LITERAL(25, 390, 3), // "tel"
QT_MOC_LITERAL(26, 394, 6), // "passwd"
QT_MOC_LITERAL(27, 401, 16), // "slot_loginCommit"
QT_MOC_LITERAL(28, 418, 13), // "slot_joinRoom"
QT_MOC_LITERAL(29, 432, 15), // "slot_createRoom"
QT_MOC_LITERAL(30, 448, 18), // "slot_setJoinedRoom"
QT_MOC_LITERAL(31, 467, 6), // "roomid"
QT_MOC_LITERAL(32, 474, 12), // "slot_setUser"
QT_MOC_LITERAL(33, 487, 18), // "slot_userSetCommit"
QT_MOC_LITERAL(34, 506, 6), // "iconid"
QT_MOC_LITERAL(35, 513, 4), // "name"
QT_MOC_LITERAL(36, 518, 7), // "feeling"
QT_MOC_LITERAL(37, 526, 13), // "slot_quitRoom"
QT_MOC_LITERAL(38, 540, 14), // "slot_audioOpen"
QT_MOC_LITERAL(39, 555, 15), // "slot_audioClose"
QT_MOC_LITERAL(40, 571, 16), // "slot_captureOpen"
QT_MOC_LITERAL(41, 588, 17), // "slot_captureClose"
QT_MOC_LITERAL(42, 606, 13), // "slot_deskOpen"
QT_MOC_LITERAL(43, 620, 14), // "slot_deskClose"
QT_MOC_LITERAL(44, 635, 19), // "slot_sendAudioFrame"
QT_MOC_LITERAL(45, 655, 11), // "QByteArray&"
QT_MOC_LITERAL(46, 667, 2), // "ba"
QT_MOC_LITERAL(47, 670, 22), // "slot_refreshVideoImage"
QT_MOC_LITERAL(48, 693, 3), // "img"
QT_MOC_LITERAL(49, 697, 23), // "slot_sendVideoFrameData"
QT_MOC_LITERAL(50, 721, 21), // "slot_refreshUserImage"
QT_MOC_LITERAL(51, 743, 2), // "id"
QT_MOC_LITERAL(52, 746, 7), // "QImage&"
QT_MOC_LITERAL(53, 754, 16), // "slot_setFunnyPic"
QT_MOC_LITERAL(54, 771, 5) // "picid"

    },
    "CKernel\0SIG_sendVideoFrame\0\0socket\0"
    "char*\0buf\0nlen\0setNetMap\0setConfig\0"
    "slot_destroy\0slot_dealData\0slot_dealLoginRs\0"
    "slot_dealRegisterRs\0slot_dealCreateRoomRs\0"
    "slot_dealJoinRoomRs\0slot_dealRoomMemberRq\0"
    "slot_dealUserInfoRq\0slot_dealLeaveRoomRq\0"
    "slot_dealAudioFrame\0slot_dealVideoFrame\0"
    "slot_clientSendData\0slot_clientVideoSendData\0"
    "slot_clientAudioSendData\0slot_destroyInstance\0"
    "slot_registerCommit\0tel\0passwd\0"
    "slot_loginCommit\0slot_joinRoom\0"
    "slot_createRoom\0slot_setJoinedRoom\0"
    "roomid\0slot_setUser\0slot_userSetCommit\0"
    "iconid\0name\0feeling\0slot_quitRoom\0"
    "slot_audioOpen\0slot_audioClose\0"
    "slot_captureOpen\0slot_captureClose\0"
    "slot_deskOpen\0slot_deskClose\0"
    "slot_sendAudioFrame\0QByteArray&\0ba\0"
    "slot_refreshVideoImage\0img\0"
    "slot_sendVideoFrameData\0slot_refreshUserImage\0"
    "id\0QImage&\0slot_setFunnyPic\0picid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CKernel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  199,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  206,    2, 0x0a /* Public */,
       8,    0,  207,    2, 0x0a /* Public */,
       9,    0,  208,    2, 0x0a /* Public */,
      10,    3,  209,    2, 0x0a /* Public */,
      11,    3,  216,    2, 0x0a /* Public */,
      12,    3,  223,    2, 0x0a /* Public */,
      13,    3,  230,    2, 0x0a /* Public */,
      14,    3,  237,    2, 0x0a /* Public */,
      15,    3,  244,    2, 0x0a /* Public */,
      16,    3,  251,    2, 0x0a /* Public */,
      17,    3,  258,    2, 0x0a /* Public */,
      18,    3,  265,    2, 0x0a /* Public */,
      19,    3,  272,    2, 0x0a /* Public */,
      20,    3,  279,    2, 0x0a /* Public */,
      21,    3,  286,    2, 0x0a /* Public */,
      22,    3,  293,    2, 0x0a /* Public */,
      23,    0,  300,    2, 0x0a /* Public */,
      24,    2,  301,    2, 0x0a /* Public */,
      27,    2,  306,    2, 0x0a /* Public */,
      28,    0,  311,    2, 0x0a /* Public */,
      29,    0,  312,    2, 0x0a /* Public */,
      30,    1,  313,    2, 0x0a /* Public */,
      32,    0,  316,    2, 0x0a /* Public */,
      33,    3,  317,    2, 0x0a /* Public */,
      37,    0,  324,    2, 0x0a /* Public */,
      38,    0,  325,    2, 0x0a /* Public */,
      39,    0,  326,    2, 0x0a /* Public */,
      40,    0,  327,    2, 0x0a /* Public */,
      41,    0,  328,    2, 0x0a /* Public */,
      42,    0,  329,    2, 0x0a /* Public */,
      43,    0,  330,    2, 0x0a /* Public */,
      44,    1,  331,    2, 0x0a /* Public */,
      47,    1,  334,    2, 0x0a /* Public */,
      49,    1,  337,    2, 0x0a /* Public */,
      50,    2,  340,    2, 0x0a /* Public */,
      53,    1,  345,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   34,   35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 45,   46,
    QMetaType::Void, QMetaType::QImage,   48,
    QMetaType::Void, QMetaType::QByteArray,   46,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 52,   51,   48,
    QMetaType::Void, QMetaType::Int,   54,

       0        // eod
};

void CKernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CKernel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_sendVideoFrame((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->setNetMap(); break;
        case 2: _t->setConfig(); break;
        case 3: _t->slot_destroy(); break;
        case 4: _t->slot_dealData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->slot_dealLoginRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->slot_dealRegisterRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->slot_dealCreateRoomRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->slot_dealJoinRoomRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->slot_dealRoomMemberRq((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->slot_dealUserInfoRq((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->slot_dealLeaveRoomRq((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->slot_dealAudioFrame((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->slot_dealVideoFrame((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->slot_clientSendData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->slot_clientVideoSendData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 16: _t->slot_clientAudioSendData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 17: _t->slot_destroyInstance(); break;
        case 18: _t->slot_registerCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 19: _t->slot_loginCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 20: _t->slot_joinRoom(); break;
        case 21: _t->slot_createRoom(); break;
        case 22: _t->slot_setJoinedRoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->slot_setUser(); break;
        case 24: _t->slot_userSetCommit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 25: _t->slot_quitRoom(); break;
        case 26: _t->slot_audioOpen(); break;
        case 27: _t->slot_audioClose(); break;
        case 28: _t->slot_captureOpen(); break;
        case 29: _t->slot_captureClose(); break;
        case 30: _t->slot_deskOpen(); break;
        case 31: _t->slot_deskClose(); break;
        case 32: _t->slot_sendAudioFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 33: _t->slot_refreshVideoImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 34: _t->slot_sendVideoFrameData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 35: _t->slot_refreshUserImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 36: _t->slot_setFunnyPic((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CKernel::*)(uint , char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CKernel::SIG_sendVideoFrame)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CKernel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CKernel.data,
    qt_meta_data_CKernel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CKernel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CKernel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CKernel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CKernel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void CKernel::SIG_sendVideoFrame(uint _t1, char * _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
