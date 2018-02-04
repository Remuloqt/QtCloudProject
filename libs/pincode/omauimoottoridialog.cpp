#include "omauimoottoridialog.h"
#include "ui_omauimoottoridialog.h"
#include <iostream>
#include <QString>


OmaUIMoottoriDialog::OmaUIMoottoriDialog(QWidget *parent) :
    QDialog(parent),


    ui(new Ui::OmaUIMoottoriDialog)
{
    ui->setupUi(this);
    status = false;
}


OmaUIMoottoriDialog::~OmaUIMoottoriDialog()
{
    delete ui;
}

void OmaUIMoottoriDialog::on_pushButtonSulje_clicked()
{
    this->close();
}

void OmaUIMoottoriDialog::on_pushButtonClear_clicked()
{
    ui->lineEdit->clear();
}

void OmaUIMoottoriDialog::on_pushButton1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"1");
}

void OmaUIMoottoriDialog::on_pushButton2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"2");
}

void OmaUIMoottoriDialog::on_pushButton3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"3");
}

void OmaUIMoottoriDialog::on_pushButton4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"4");
}

void OmaUIMoottoriDialog::on_pushButton5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"5");
}

void OmaUIMoottoriDialog::on_pushButton6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"6");
}

void OmaUIMoottoriDialog::on_pushButton7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"7");
}

void OmaUIMoottoriDialog::on_pushButton8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"8");
}

void OmaUIMoottoriDialog::on_pushButton9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"9");
}

void OmaUIMoottoriDialog::on_pushButtonEnter_clicked()
{
    QString password;
    password=ui->lineEdit->text();

    // insert password inside ""
    if (password == "1337"){
        count = 0;  //these are for testing
        ui->label->clear();
        ui->lineEdit->clear();
        ui->label->setText("Salasana oikein");
        status = true;
        this->close();
    }

    else{
        ++count;
        ui->lineEdit->clear();
        ui->label->setText("Salasana väärin. 2 yritystä jäljellä");

    }

    if (count ==2)
    {
        ui->lineEdit->clear();
        ui->label->setText("Salasana väärin. 1 yritys jäljellä");
    }

    if (count >=3)
    {
        ui->lineEdit->clear();
        ui->label->setText("HÄLYTYS");
        status = false;
        this->close();
    }
}

bool OmaUIMoottoriDialog::returnStatus(){
    return status;
}
