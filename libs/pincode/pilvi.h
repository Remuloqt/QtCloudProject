#ifndef PILVI_H
#define PILVI_H

#include <Enginio/Enginio>
#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <ctime>



class Pilvi:public QObject
{   Q_OBJECT
public:
    Pilvi();
    ~Pilvi();
    QString id;
    QString hetu;
    void reading(QString);
    QString palautaArvot();
    void writeToCloud(QString);

signals:
    void finished(QString, QString);

private slots:
    void readOk(EnginioReply*);


private:
    EnginioClient *client;
};

#endif // PILVI_H
