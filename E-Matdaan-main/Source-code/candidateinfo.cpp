#include "candidateinfo.h"
#include "ui_candidateinfo.h"

candidateinfo::candidateinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::candidateinfo)
{
    ui->setupUi(this);
}

candidateinfo::~candidateinfo()
{
    delete ui;
}

void candidateinfo::on_pushButton_2_clicked()
{
    this->hide();
    dashboard c;
    c.setModal(true);
    c.exec();
}
