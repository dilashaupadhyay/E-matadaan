#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
//#include "ballot.h"
#include "mainwindow.h"
#include "candidatesinformationinput.h"
#include "adminmainwindow.h"
namespace Ui {
class dashboard;
}

class dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

    friend class adminmainwindow;
    friend class  ballot;
    Ui::dashboard *ui;

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:

    QSqlDatabase  db;
};

#endif // DASHBOARD_H
