#-------------------------------------------------
#
# Project created by QtCreator 2023-08-19T17:55:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWMainWind
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        qwmainwind.cpp

HEADERS += \
        qwmainwind.h

FORMS += \
        qwmainwind.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    images/103.bmp \
    images/120.bmp \
    images/430.bmp \
    images/BLD.BMP \
    images/cut.bmp \
    images/DBLUNDR.BMP \
    images/exit.bmp \
    images/ITL.BMP \
    images/new2.bmp \
    images/open3.bmp \
    images/paste.bmp \
    images/UNDRLN.BMP \
    images/WORDUNDR.BMP \
    images/20.ico
