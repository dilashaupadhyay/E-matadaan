#ifndef CANDIDATEINFO_H
#define CANDIDATEINFO_H

#include <QDialog>
#include "dashboard.h"

namespace Ui {
class candidateinfo;
}

class candidateinfo : public QDialog
{
    Q_OBJECT

public:
    explicit candidateinfo(QWidget *parent = nullptr);
    ~candidateinfo();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::candidateinfo *ui;
};

#endif // CANDIDATEINFO_H
