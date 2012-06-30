#-------------------------------------------------
#
# Project created by QtCreator 2012-06-27T13:46:13
#
#-------------------------------------------------

QT       += core gui xml

TARGET = MouseClick2000
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clickthread.cpp \
    controlthread.cpp \
    click.cpp \
    recordthread.cpp

HEADERS  += mainwindow.h \
    clickthread.h \
    controlthread.h \
    click.h \
    recordthread.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

CONFIG += staticlib





















