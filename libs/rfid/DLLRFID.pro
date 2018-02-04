#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T13:37:35
#
#-------------------------------------------------

QT       -= gui

TARGET = DLLRFID
TEMPLATE = lib

DEFINES += DLLRFID_LIBRARY

SOURCES += dllrfid.cpp

HEADERS += dllrfid.h\
    dllrfid_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../../libs/rfid/3rdparty/qextserialport-1.2rc/src/qextserialport.pri)
#win32:LIBS = "3rdparty/Qt5ExtSerialPort1.dll"
