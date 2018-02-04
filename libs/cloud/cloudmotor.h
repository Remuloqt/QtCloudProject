#ifndef CLOUDMOTOR_H
#define CLOUDMOTOR_H

#include <QObject>
#include <Enginio/Enginio>
#include <QEventLoop>
#include <QDebug>
#include <QDateTime>

class CloudMotor:public QObject
{ Q_OBJECT

public:
    CloudMotor();
    ~CloudMotor();
    void writeToCloud(QString);
    QJsonObject searchCardInfo(QString);
    QJsonObject searchLogins(QString);
    //void handleData();

private:
    EnginioClient *client;
    EnginioReply *reply;
    QJsonObject data;
    bool dataReturned;
};

#endif // CLOUDMOTOR_H
