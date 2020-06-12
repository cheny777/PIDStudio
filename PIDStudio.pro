#-------------------------------------------------
#
# Project created by QtCreator 2020-06-11T10:17:53
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PIDStudio
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    pid.cpp \
    transfunc.cpp \
    CPID/ADPCONTROLmain.cpp \
    CPID/MoveObj.cpp \
    CPID/PID.cpp \
    CPID/ZPID.cpp \
    CPID/ZT.cpp \
    VPID/MoveObj.cpp \
    VPID/NST.cpp \
    VPID/PID.cpp \
    VPID/vibmain.cpp

HEADERS += \
        widget.h \
    pid.h \
    transfunc.h \
    CPID/MoveObj.h \
    CPID/PID.h \
    CPID/ZPID.h \
    CPID/ZT.h \
    VPID/MoveObj.h \
    VPID/NST.h \
    VPID/PID.h

FORMS += \
        widget.ui
