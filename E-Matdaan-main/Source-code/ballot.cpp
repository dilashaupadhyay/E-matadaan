#include "ballot.h"
#include "ui_ballot.h"



int count1 = 0, count2 = 0, count3 = 0;


ballot::ballot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ballot)
{
    ui->setupUi(this);

    db = QSqlDatabase::database("qt_sql_default_connection");

    if(!db.open()){
        QMessageBox::information(this, "Connectivity", "Database not connected.");
    }

    else{
        QSqlQuery qry(db);
        qry.exec("select Name from candidatesInformation where Department = '"+depart+"';");
        int i= 0;
        while(qry.next() == true){
            QSqlRecord rec = qry.record();
            int nameCol = rec.indexOf("Name"); // index of the field "name"
            QString name = qry.value(nameCol).toString();
            if(i == 0){
                ui->candidate1->setText(name);
            }else if(i==1){
                ui->candidate2->setText(name);
            }else{
                ui->candidate3->setText(name);
            }
            i++;
            //qry.next();
        }
    }

}

ballot::~ballot()
{
    delete ui;
}


void ballot::on_pushButton_clicked()
{
    db = QSqlDatabase::database("qt_sql_default_connection");
    if(!db.open())
      qWarning() << "ERROR: " << db.lastError();

    else{

        QSqlQuery qry;
        qry.prepare("UPDATE BasicInformation SET VoteStatus = '1' WHERE  UserName == '"+username+"' and Password == '"+password+"'");
       // testQuery.bindValue(":val", val);
        qry.exec();
        if(!qry.exec()){
            qDebug()<<"Not inserted inside vote status : "<<qry.lastError();
        }

        if(ui->candidate1->isChecked()){
            count1 = 1;
            if(depart == "ComputerScience"){
                qry.prepare("INSERT INTO VoteCountComputerScience (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
                qry.bindValue(":count1", count1);
                qry.bindValue(":count2", count2);
                qry.bindValue(":count3", count3);
                count1 = 0;

                qry.exec();
            }else if(depart == "ComputerEngineering"){
                qry.prepare("INSERT INTO VoteCountComputerEngineering (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
                qry.bindValue(":count1", count1);
                qry.bindValue(":count2", count2);
                qry.bindValue(":count3", count3);
                count1 = 0;

                qry.exec();
            }else{
                qDebug()<<"Error!!";
            }


            //QMessageBox::information(this, "Success!", "If condition 1 entered.");
        } else if(ui->candidate2->isChecked()){
            count2 = 1;
            if(depart == "ComputerScience"){
                qry.prepare("INSERT INTO VoteCountComputerScience (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
                qry.bindValue(":count1", count1);
                qry.bindValue(":count2", count2);
                qry.bindValue(":count3", count3);
                count2 =0;

                qry.exec();
            }else if(depart == "ComputerEngineering"){
                qry.prepare("INSERT INTO VoteCountComputerEngineering (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
                qry.bindValue(":count1", count1);
                qry.bindValue(":count2", count2);
                qry.bindValue(":count3", count3);
                count2 = 0;
                qry.exec();
            }else{
                qDebug()<<"Error!!";
            }
            //QMessageBox::information(this, "Success!", "If condition 2 entered.");
        }else if(ui->candidate3->isChecked()){
            count3 = 1;
            if(depart == "ComputerScience"){
                qry.prepare("INSERT INTO VoteCountComputerScience (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
                qry.bindValue(":count1", count1);
                qry.bindValue(":count2", count2);
                qry.bindValue(":count3", count3);
                count3 = 0;

                qry.exec();
            }else if(depart == "ComputerEngineering"){
                qry.prepare("INSERT INTO VoteCountComputerEngineering (Candidate1, Candidate2, Candidate3) VALUES (:count1, :count2, :count3);");
                qry.bindValue(":count1", count1);
                qry.bindValue(":count2", count2);
                qry.bindValue(":count3", count3);
                count3 = 0;

                qry.exec();

            //QMessageBox::information(this, "Success!", "If condition 3 entered.");
        } }else{
            qDebug()<<"Error!!";
        }

        QMessageBox::information(this, "Success!", "Voting successful!");


    }

    //db.close();
    //QSqlDatabase::removeDatabase("StudentInformation");

    this->hide();
    dashboard d;
    d.setModal(true);
    d.exec();


}

void ballot::on_pushButton_2_clicked()
{
    this->hide();
    dashboard c;
    c.setModal(true);
    c.exec();
}
