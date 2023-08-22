#include "help.h"
#include "ui_help.h"
#include"systeminfo.h"
#include"technical.h"
#include"contacts.h"
#include"check.h"
#include "dashboard.h"


help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_pushButton_clicked()
{
    this->hide();
    systeminfo d;
    d.setModal(true);
    d.exec();
}


void help::on_pushButton_5_clicked()
{
    this->hide();
    technical d;
    d.setModal(true);
    d.exec();
}


void help::on_pushButton_3_clicked()
{
    this->hide();
    contacts d;
    d.setModal(true);
    d.exec();
}



void help::on_pushButton_4_clicked()
{
    this->hide();
    check d;
    d.setModal(true);
    d.exec();
}


void help::on_pushButton_6_clicked()
{
    this->hide();
    dashboard d;
    d.setModal(true);
    d.exec();
}

