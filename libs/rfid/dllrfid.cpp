#include "DLLRFID.h"

DLLRFID::DLLRFID(QString pPortName){
    portName = pPortName;
    portOpen = openCOMPort();
}

DLLRFID::~DLLRFID(){
    port->close();

    qDebug()<<"Port is closed";
    delete port;
}

void DLLRFID::mainRunner(){
    if(portOpen){
        qDebug()<<"Port is open";
        writeCharToCOMPort();
        msleep(500);
        receiveData();
        //port->close();
    }
    else{
        portOpen = false;
        qDebug() <<"Failed to open port";
    }

}

bool DLLRFID::openCOMPort(){
    qDebug()<<"Trying to open port";

    port = new QextSerialPort;
    port->setPortName(portName);
    port->setQueryMode(QextSerialPort::EventDriven);
    port->setBaudRate(BAUD9600);
    port->setFlowControl(FLOW_HARDWARE);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);

    returnValue = port->open(QIODevice::ReadWrite);
    return returnValue;
}

void DLLRFID::writeCharToCOMPort(){
    port->write("U\0",1);
}

void DLLRFID::msleep(unsigned long msecs){
    QThread::msleep(msecs);
}

void DLLRFID::receiveData(){
    QString hexNum,cardSerialNumber;
    char data[9], temp[9];
    int bytes_Read;

    bytes_Read = port->read(data, 8);
    bytesRead = bytes_Read;
    data[bytes_Read] = '\0';
    qDebug()<<"Cards tag byte amount: "<<bytes_Read;

    if(bytes_Read>1){
        for(int i=0;i<7;i++){
            sprintf(temp,"%08X", data[i]);

            hexNum = temp;

            cardSerialNumber = cardSerialNumber + hexNum.right(2);
        }

        qDebug() << "Cards number is: " << cardSerialNumber;
        cardId = cardSerialNumber;
        port->close();
    }
}

QString DLLRFID::getId(){
    mainRunner();
    return cardId;
}

bool DLLRFID::emitCardInserted(){
    for(int i = 0; i<1; i){
        if(cardId != 0)
        {
            return true;
        }
        else if (!portOpen)
        {
            return false;
        }
        else
        {
            mainRunner();
        }
    }
}

//This is used to detect when card is removed
/*
bool DLLRFID::emitCardNotInserted(){
    for(int i = 0; i<1; i){
        mainRunner();

        if(bytesRead == 0)
        {

            qDebug() << "Card removed";
            return true;
        }
        else if (bytesRead == 1)
        {
            qDebug() << "Card removed";
            return true;
        }
}
    return false;
}*/

