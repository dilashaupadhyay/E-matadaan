#ifndef CONTACTS_H
#define CONTACTS_H

#include <QDialog>

namespace Ui {
class contacts;
}

class contacts : public QDialog
{
    Q_OBJECT

public:
    explicit contacts(QWidget *parent = nullptr);
    ~contacts();

private:
    Ui::contacts *ui;
};

#endif // CONTACTS_H
