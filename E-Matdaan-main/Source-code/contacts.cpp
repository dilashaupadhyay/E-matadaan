#include "contacts.h"
#include "ui_contacts.h"

contacts::contacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contacts)
{
    ui->setupUi(this);
}

contacts::~contacts()
{
    delete ui;
}
