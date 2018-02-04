#include "dlldatabasecomponent.h"
#include <QDebug>


QJsonObject DLLDatabaseComponent::searchInfoFromCloud(QString cardId){
    objectCloudMotor = new CloudMotor();
    QJsonObject data = objectCloudMotor->searchCardInfo(cardId);
    return data;

    delete objectCloudMotor;
}

void DLLDatabaseComponent::writeToCloud(QString cardId){
    objectCloudMotor = new CloudMotor();
    objectCloudMotor->writeToCloud(cardId);

    delete objectCloudMotor;
}

QJsonObject DLLDatabaseComponent::searchLogsFromCloud(QString cardId){
    objectCloudMotor = new CloudMotor();
    QJsonObject data = objectCloudMotor->searchLogins(cardId);
    return data;

    delete objectCloudMotor;
}
