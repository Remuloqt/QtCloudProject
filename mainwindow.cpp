#include "mainwindow.h"
#include "ui_mainwindow.h"
bool MainWindow::cardinserted =false;
MainWindow *MainWindow::mw;

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
   // ui(new Ui::MainWindow)
{
   // ui->setupUi(this);
    mw = this;
    newone = NULL;
    Database = new DLLDatabaseComponent;

    wrapper = new QVBoxLayout;
    wrapper->setMargin(0);
    wrapper->setSpacing(0);

    // Widgets asetukset
    setLayout(wrapper);
    setWindowTitle( "MainWindow" );
    setObjectName("mainwrapper");

    //Tällä vaihdetaan ohjelman ikkunan kokoa
    setFixedSize(600, 700);

    //Vaihda alku ikkunaa Login/Main
    screen_to("Login");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete Database;
}
/*
void MainWindow::on_pushButton_clicked()
{
    QString cardId = olioDLLCOMComponent->rajapintafunktioDLLCOMComponent("COM5");
    olioPilvi->reading(cardId);
    connect(olioPilvi, SIGNAL (finished(QString, QString)), this, SLOT(setValues(QString,QString)));
}*/

void MainWindow::getCardLogs(){

}

void MainWindow::change_screen(QString index)
{
    mw->screen_to(index);
}

void MainWindow::screen_to(QString index)
{
    if (newone)
    {
        delete newone;
        newone = NULL;
    }
    if (index == "Login")
    {
        newone = new LoginScreen;
    }

    else if (index == "Main")
    {
        newone = new MainScreen;
    }

    wrapper->addWidget(newone);
}




/*
void MainWindow::on_pushButton_2_clicked()
{
    QString korttiID = olioDLLCOMComponent->rajapintafunktioDLLCOMComponent("COM5");

    olioPilvi->writeToCloud(korttiID);
}*/
