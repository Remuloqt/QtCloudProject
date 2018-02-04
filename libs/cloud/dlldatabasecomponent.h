#ifndef DLLDATABASECOMPONENT_H
#define DLLDATABASECOMPONENT_H

#include <QObject>
#include "dlldatabasecomponent_global.h"
#include "cloudmotor.h"

class DLLDatabaseComponent
{

public:
   //QString DLLDATABASECOMPONENTSHARED_EXPORT searchFromCloud(QString);
   QJsonObject DLLDATABASECOMPONENTSHARED_EXPORT searchInfoFromCloud(QString);
   QJsonObject DLLDATABASECOMPONENTSHARED_EXPORT searchLogsFromCloud(QString);
   void DLLDATABASECOMPONENTSHARED_EXPORT writeToCloud(QString);

private:
   CloudMotor *objectCloudMotor;
};

#endif // DLLDATABASECOMPONENT_H
