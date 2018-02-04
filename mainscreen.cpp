#include "mainscreen.h"
#include "ui_mainscreen.h"


MainScreen::MainScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScreen){
    ui->setupUi(this);

    Database = new DLLDatabaseComponent;
    //Remember to change port number to right one here and in loginscreen
    Card = new DLLRFID("\\\\.\\COM4");
    Pin = new DLLOmaUIKomponentti;

    //Read cardId from RFID-reader
    cardId = Card->getId();

    //Search cards information and log data and write newest one
    infoData = Database->searchInfoFromCloud(cardId);
    logData = Database->searchLogsFromCloud(cardId);
    Database->writeToCloud(cardId);
    handleInfoData();

}

MainScreen::~MainScreen(){
    delete ui;
    delete Database;
    delete Card;
    delete Pin;
}

void MainScreen::handleInfoData(){    
    lastDatetime = searchLastLogin();

    //Get current Date and Time
    QJsonArray result = infoData ["results"].toArray();
    QDateTime currentDateTime(QDateTime::currentDateTime());
    QString datetime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

    foreach(const QJsonValue& value, result){
        const QJsonObject& object = value.toObject();
        const QString& cardnum = object["cardNum"].toString();
        const QString& idnum = object["idNum"].toString();
        const QString& firstname = object["Firstname"].toString();
        const QString& surname = object["Surname"].toString();
        const QString& job = object["Job"].toString();
        ui->label_cardId->setText(cardnum);
        ui->label_hetu->setText(idnum);
        ui->label_firstname->setText(firstname);
        ui->label_job->setText(job);
        ui->label_surname->setText(surname);
        ui->label_loginTime->setText(datetime);
        ui->label_lastLogin->setText(lastDatetime);
    }
}

void MainScreen::on_pushButton_logout_clicked(){
    MainWindow::change_screen("Login");
}

void MainScreen::on_pushButton_search_clicked(){
    //Prevent seeing logs until correct password is applied
    pinCorrect = Pin->rajapintafunktioDLLOmaUIKomponentti();
    handleLogData();
}

void MainScreen::handleLogData(){  
    if(pinCorrect){
        //Set row and column count for the tableWidget
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(1);
        //Make the rows stretch to maximun size
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        //Set a header to the table
        QTableWidgetItem *header = new QTableWidgetItem;
        header->setText("Date and Time");
        //To change the row that the header is attached change 0 to the wanted row
        ui->tableWidget->setHorizontalHeaderItem(0,header);

        QJsonArray result = logData ["results"].toArray();
        int i = -1;
        foreach(const QJsonValue& value, result){

            const QJsonObject& object = value.toObject();
            QString time = object["Time"].toString();
            lastDatetime = time;
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            QTableWidgetItem *item = new QTableWidgetItem(time);
            ui->tableWidget->setItem(i,1,item);
            i = i + 1;
        }
    }
    else{
        qDebug()<<"Password incorrect";
    }
}

QString MainScreen::searchLastLogin(){
    QJsonArray result = logData ["results"].toArray();

    foreach(const QJsonValue& value, result){
        const QJsonObject& object = value.toObject();
        QString datetime = object["Time"].toString();
        return datetime;
    }
    QString error = "Couldn't get lastLoginTime";
    return error;
}


