#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T12:25:29
#
#-------------------------------------------------
QT += gui widgets
TARGET = DLLOmaUIKomponentti
TEMPLATE = lib

DEFINES += DLLOMAUIKOMPONENTTI_LIBRARY

SOURCES += dllomauikomponentti.cpp \
    omauimoottoridialog.cpp

HEADERS += dllomauikomponentti.h\
        dllomauikomponentti_global.h \
    omauimoottoridialog.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    omauimoottoridialog.ui
CONFIG += c++11
