#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "candidatesinformationinput.h"
#include <QString>
#include "dashboard.h"
#include "mainwindow.h"
#include <iostream>

extern QString winnerCS;
extern QString winnerCE;


namespace Ui {
class adminMainWindow;
}

class adminMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminMainWindow(QWidget *parent = nullptr);
    ~adminMainWindow();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::adminMainWindow *ui;
    QSqlDatabase  db;
};

#endif // ADMINMAINWINDOW_H
