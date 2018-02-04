#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include "libs/rfid/dllrfid.h"
#include <QWidget>
#include <QtConcurrent/QtConcurrentRun>
#include <QFuture>
#include <QFutureWatcher>
#include "mainwindow.h"
/*
#include <QLayout>
#include <QString>
#include <QLineEdit>
#include <QLabel>
*/


namespace Ui {
class LoginScreen;
}

class LoginScreen : public QWidget
{
    Q_OBJECT

public:
    LoginScreen(QWidget *parent = 0);
    ~LoginScreen();
    QFuture<void> *future;
    QFutureWatcher<void> *watcher;
    static bool cardinserted;

private slots:
    void change_screen();

private:
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
