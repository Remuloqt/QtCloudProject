#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pilvi.h"
#include "C:\Project\MainExe\headeritDLLCOM\dllcomcomponent.h"
#include "C:\data\TESTIEXE\dllomauikomponentti.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void asetaArvot(QString, QString);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Pilvi *olioPilvi;
    QString asetettuKorttiId;
    QString asetettuHetu;
    DLLCOMComponent *olioDLLCOMComponent;
};

#endif // MAINWINDOW_H
