#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T17:23:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IOManager
#TEMPLATE = app
TEMPLATE = lib

DEFINES += IOManager_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        mainwindow.cpp \
        iomanager.cpp \
    io_ioc0640.cpp \
    DAQIOBase.cpp \
    simulationio.cpp \
    diobtn.cpp \
    test.cpp \
    diocommandtable.cpp \
    diocommandbase.cpp \
    commandsetdo.cpp

HEADERS  += mainwindow.h \
        iomanager.h \
    io_ioc0640.h \
    DAQIOBase.h \
    simulationio.h \
    diobtn.h \
    test.h \
    diocommandtable.h \
    diocommandbase.h \
    commandsetdo.h


#DAQIO SDK
INCLUDEPATH += $$PWD\\IOC0640lib

##IOLIB += $$quote(PWD)
##LIBS += -L./IOC0640lib/ -lIOC0640
LIBS += $$PWD\IOC0640lib/IOC0640.lib
##LIBS += $$IOLIB\IOC0640lib\IOC0640.lib


FORMS    += mainwindow.ui \
    test.ui

unix {
    target.path = /usr/lib
    INSTALLS += target
}
