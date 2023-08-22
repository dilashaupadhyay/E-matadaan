#ifndef BALLOT_H
#define BALLOT_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "dashboard.h"
//#include "mainwindow.h"

namespace Ui {
class ballot;
}

class ballot : public QDialog
{
    Q_OBJECT

public:
    explicit ballot(QWidget *parent = nullptr);
    ~ballot();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ballot *ui;
    QSqlDatabase db;
};

#endif // BALLOT_H
