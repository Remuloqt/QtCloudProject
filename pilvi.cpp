#include "pilvi.h"

Pilvi::Pilvi()
{
    QByteArray backendid("5536b4b1d45dfe202b05e2cd");
    client = new EnginioClient;
    client->setBackendId(backendid);

}

Pilvi::~Pilvi()
{

}

void Pilvi::reading(QString lue)
{
    qDebug()<<lue<<endl;

    QJsonObject object;
    object["objectType"] = QStringLiteral( "objects.cardInfo" );
    object["limit"] = 1;
    //Luodaan uusi JSonObject joka sisältää query hakuehdot ja lisätään tämä pää qeuryyn.
    QJsonObject search;
    search["cardNum"] = lue;
    object["query"] = search;
    client->query( object );

    QObject::connect(client, SIGNAL(finished(EnginioReply*)), this,
    SLOT(readOk(EnginioReply*)));
}


void Pilvi::readOk(EnginioReply* reply)
{
    qDebug() <<reply<<endl;
    QJsonArray result = reply->data( )["results"].toArray( );


    foreach ( const QJsonValue& value, result )
     {
     const QJsonObject& object = value.toObject( );
     const QString& cardNum = object["cardNum"].toString( );
     const QString& idNum = object["idNum"].toString( );
     cCardId = cardNum;
     cIdNum = idNum;
     }
    emit finished(cCardId,cIdNum);
}

void Pilvi::writeToCloud(QString KorttiId)
{
    /*time_t now;
    time(&now);
    char buf[sizeof "2011-10-08T07:07:09Z"];
    strftime(buf, sizeof buf, "%FT%TZ", gmtime(&now));*/
    QJsonObject write;
    write.insert("objectType", QString("objects.Logs"));
    QString nimi = KorttiId;
    //QString time = "Testi aika";
    write.insert("KorttiId", nimi);
    //write.insert("addCarddate", time);
    client->create(write);

}
