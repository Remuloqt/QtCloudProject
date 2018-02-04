#-------------------------------------------------
#
# Project created by QtCreator 2015-04-21T23:23:43
#
#-------------------------------------------------

QT       -= gui
QT += enginio
TARGET = DLLDatabaseComponent
TEMPLATE = lib

DEFINES += DLLDATABASECOMPONENT_LIBRARY

SOURCES += dlldatabasecomponent.cpp \
    cloudmotor.cpp

HEADERS += dlldatabasecomponent.h\
        dlldatabasecomponent_global.h \
    cloudmotor.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG += c++11
