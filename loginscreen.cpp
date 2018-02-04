#include "loginscreen.h"
#include "ui_loginscreen.h"
bool LoginScreen::cardinserted =false;

//Tämän methodin pitää olla ennen constructoria
void card_thread()
 {
    //Remember to change port number to right one here and in mainscreen
     DLLRFID *card = new DLLRFID("\\\\.\\COM4");
     if (card->emitCardInserted())
     {
         qDebug() << "Kortti löytynyt";
         LoginScreen::cardinserted = true;
     }
     else
     {
         qDebug() << "Korttia ei ole";
         LoginScreen::cardinserted = false;
     }
     delete card;
 }

LoginScreen::LoginScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    // Set new QThread running to monitor if card is inserted to card reader
    future = new QFuture<void>;
    watcher = new QFutureWatcher<void>;
    *future = QtConcurrent::run(card_thread);
    watcher->setFuture(*future);
    connect(watcher, SIGNAL(finished()),this, SLOT(change_screen()));
}

LoginScreen::~LoginScreen()
{
    delete ui;
    cardinserted = false;
}

 void LoginScreen::change_screen()
 {
     if (cardinserted)
     {
        MainWindow::change_screen("Main");
    }
}
