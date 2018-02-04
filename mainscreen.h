#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QDateTime>
/*
#include <QTableView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStandardItemModel>
*/
#include "mainwindow.h"
#include "libs/cloud/dlldatabasecomponent.h"
#include "libs/cloud/cloudmotor.h"
#include "libs/pincode/dllomauikomponentti.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();

private slots:
    void on_pushButton_logout_clicked();
    void on_pushButton_search_clicked();

private:
    bool pinCorrect;
    QString cardId;
    QString lastDatetime;
    QJsonObject infoData;
    QJsonObject logData;
    Ui::MainScreen *ui;
    DLLDatabaseComponent *Database;
    DLLOmaUIKomponentti *Pin;
    DLLRFID *Card;
    void handleInfoData();
    void handleLogData();
    QString searchLastLogin();

};

#endif // MAINSCREEN_H
