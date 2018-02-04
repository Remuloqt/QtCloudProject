#ifndef DLLRFID_H
#define DLLRFID_H

#include "dllrfid_global.h"
#include "../../libs/rfid/3rdparty/qextserialport-1.2rc/src/qextserialport.h"
#include <QString>
#include <QDebug>
#include <QThread>

class DLLRFID
{
private:
    QString portName;
    QextSerialPort *port;
    bool returnValue;
    QString cardId;
    bool portOpen;
    bool cardInserted;
    int bytesRead;

    void mainRunner();
    bool openCOMPort();
    void writeCharToCOMPort();
    static void msleep(unsigned long msecs);
    void receiveData();

public:
    DLLRFID(QString pPortName);
    ~DLLRFID();

    QString getId();
    bool emitCardInserted();
    //This is used to detect when card is removed
    //bool emitCardNotInserted();
};

#endif // DLLRFID_H
