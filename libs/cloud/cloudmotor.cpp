#include "cloudmotor.h"

CloudMotor::CloudMotor(){
    dataReturned = false;

    QByteArray backendid ("5536b4b1d45dfe202b05e2cd");
    client = new EnginioClient;
    client->setBackendId(backendid);
    qDebug()<<"Connected to cloud"<<endl;
}

CloudMotor::~CloudMotor(){
}

QJsonObject CloudMotor::searchCardInfo(QString cardId){
    qDebug()<<"Starting read for cardInfo from cloud"<<cardId<<endl;

    QJsonObject object;
    object["objectType"] = QStringLiteral( "objects.Info" );
    object["limit"] = 1;

    //Insert search parameters to query
    QJsonObject search;
    search["cardNum"] = cardId;
    object["query"] = search;

    EnginioReply *infoQuery = client->query(object);

    //Create a loop that will be repeated untill signal is emitted
    QEventLoop loop;
    if(dataReturned == false){
        connect(infoQuery, &EnginioReply::finished, [this,&loop] (EnginioReply *reply){
            if (reply->isError())
                qDebug() << "Ooops! Something went wrong!" << reply->data();
            else
                qDebug() << "The object was queried" << reply->data();
                data = reply->data();
                if(reply){
                    dataReturned = true;
                }
            loop.exit(0);
        });
    }
    loop.exec();
    return data;
}
QJsonObject CloudMotor::searchLogins(QString cardId){
    qDebug()<<"Starting search for logins from cloud"<<cardId<<endl;

    QJsonObject object;
    object["objectType"] = QString("objects.Logs");

    //Create new object that holds the search parameters
    QJsonObject search;
    search["cardNum"] = cardId;

    //Insert search parameters to query
    object["query"] = search;

    //Create new object that holds the sorting options
    QJsonObject sorting;
    sorting["sortBy"] = QString("createdAt");
    //Choose asc or desc as direction
    sorting["direction"] = QString("desc");

    QJsonArray sortArray;
    sortArray.append(sorting);

    //Insert sorting to query
    object["sort"] = sortArray;

    //Set max limit to query
    object["limit"] = 999;

    EnginioReply *query = client->query(object);

    //Create a loop that will be repeated untill signal is emitted
    QEventLoop loop;
    if(dataReturned == false){
        connect(query, &EnginioReply::finished, [this,&loop] (EnginioReply *reply){
            if (reply->isError())
                qDebug() << "Ooops! Something went wrong!" << reply->data();
            else
                qDebug() << "The logs were queried";
                data = reply->data();
                if(reply){
                    dataReturned = true;
                }
            loop.exit(0);
        });
    }
    loop.exec();
    return data;
}

void CloudMotor::writeToCloud(QString korttiID){
    qDebug() <<"Writing cardId to cloud"<<korttiID<<endl;

    QDateTime currentDateTime(QDateTime::currentDateTime());
    QString datetime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

    QJsonObject write;
    write.insert("objectType", QString("objects.Logs"));

    QString nimi = korttiID;
    QString time = datetime;

    write.insert("cardNum",QString(nimi));
    write.insert("Time",QString(time));

    client->create(write);
}

//Käytä tätä jos tahdotaan käsitellä dataa moottorissa
/*
void CloudMotor::handleData(){
    qDebug() <<"KASITELLAAN"<<endl;
    QJsonArray result = data ["results"].toArray();

    foreach(const QJsonValue& value, result){
        const QJsonObject& object = value.toObject();
        const QString& fetchdcardnum = object["cardNum"].toString();
        const QString& fetchdidnum = object["idNum"].toString();
        cardNum = fetchdcardnum;
        idNum = fetchdidnum;
        qDebug() <<cardNum<<endl;
    }
}*/


