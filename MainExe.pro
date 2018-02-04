#-------------------------------------------------
#
# Project created by QtCreator 2015-04-23T08:37:59
#
#-------------------------------------------------

QT       += core gui
QT +=enginio

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainExe
TEMPLATE = app


SOURCES += main.cpp\
    pilvi.cpp \
    mainscreen.cpp \
    loginscreen.cpp \
    mainwindow.cpp

HEADERS  += \
    pilvi.h \
    mainscreen.h \
    loginscreen.h \
    mainwindow.h

FORMS    += mainwindow.ui \
    mainscreen.ui \
    loginscreen.ui

CONFIG += c++11

win32:LIBS += -L$$_PRO_FILE_PWD_/libs/cloud -lDLLDatabaseComponent \
    -L$$_PRO_FILE_PWD_/libs/pincode -lDLLOmaUIKomponentti \
    -L$$_PRO_FILE_PWD_/libs/rfid -lDLLRFID

