#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_clicked()
{
    if(ui->adminUsername->text() == "admin" and ui->adminPassword->text() == "admin"){
        this->hide();
        adminMainWindow amw;
        amw.setModal(true);
        amw.exec();
    }
}
