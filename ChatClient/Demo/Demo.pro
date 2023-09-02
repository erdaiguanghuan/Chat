QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ckernel.cpp \
    logindialog.cpp \
    main.cpp \
    demodialog.cpp \
    roomdialog.cpp \
    usershow.cpp \
    setuserdialog.cpp \
    workthread.cpp

HEADERS += \
    ckernel.h \
    demodialog.h \
    logindialog.h \
    roomdialog.h \
    usershow.h \
    setuserdialog.h \
    workthread.h

FORMS += \
    demodialog.ui \
    logindialog.ui \
    roomdialog.ui \
    usershow.ui \
    setuserdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(./netapi/netapi.pri)
include(./uiapi/uiapi.pri)
include(./md5./md5.pri)
include(./AudioApi/audioapi.pri)
include(./VideoApi/videoapi.pri)

#  -I
INCLUDEPATH += ./netapi/\
               ./uiapi/\
               ./VideoApi/\
               ./AudioApi/



RESOURCES += \
    resources.qrc


