#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtConcurrent/QtConcurrentRun>
#include <QFuture>
#include <QFutureWatcher>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include "loginscreen.h"
#include "mainscreen.h"
#include "libs/rfid/dllrfid.h"
#include "libs/cloud/cloudmotor.h"
#include "libs/cloud/dlldatabasecomponent.h"

//#include "pilvi.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QFuture<void> *future;
    QFutureWatcher<void> *watcher;
    static bool cardinserted;
    static MainWindow *mw;
    static void change_screen(QString index);
    void screen_to(QString index);
    void getCardLogs();



private:
    Ui::MainWindow *ui;
    DLLDatabaseComponent *Database;
    QString asetettuKorttiId;
    QString asetettuHetu;
    QWidget *newone;
    QVBoxLayout *wrapper;

};

#endif // MAINWINDOW_H
