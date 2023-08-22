#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"


adminMainWindow::adminMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminMainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::database("qt_sql_default_connection");

}

adminMainWindow::~adminMainWindow()
{
    delete ui;
}


void adminMainWindow::on_pushButton_3_clicked()
{
    this->hide();
    CandidatesInformationInput amw;
    amw.setModal(true);
    amw.exec();
}

void adminMainWindow::on_pushButton_4_clicked()
{

    //db = QSqlDatabase::database("qt_sql_default_connection");
    QString candidate1Name, candidate2Name, candidate3Name, Department = "ComputerScience";
    int Batch;
    if (db.open()){
        QSqlQuery qry;
        qry.exec("INSERT INTO ResultStatus (ComputerScience) VALUES ('1')");
        qry.exec("SELECT sum(candidate1) AS sum1,sum(candidate2) AS sum2, sum(candidate3) AS sum3 FROM VoteCountComputerScience;");
        qry.next();
        int candidate1 = qry.value(0).toInt();
        int candidate2 = qry.value(1).toInt();
        int candidate3 = qry.value(3).toInt();

        if(!qry.exec()){
            qDebug()<<"Error in summing from votecount computer science.";
        }
        QString Winner;
        qry.exec("SELECT Name, Batch FROM candidatesInformation WHERE Department = 'ComputerScience'");
        int i= 0;
        while(qry.next() == true){
            qDebug()<<"Entered query next";
            QSqlRecord rec = qry.record();
            int nameCol = rec.indexOf("Name");// index of the field "name"
            int batchCol = rec.indexOf("Batch");
            QString name = qry.value(nameCol).toString();
            Batch = qry.value(batchCol).toInt();
            if(i == 0){
                candidate1Name = name;
            }else if(i==1){
                candidate2Name = name;
            }else{
                candidate3Name = name;
            }
            i++;
        }
        if(!qry.exec()){
            qDebug()<<"Error in fetching data from candidates information.";
        }
        if (candidate1 > candidate2 and candidate1 > candidate3){
            //QSqlQuery qry(db)
            Winner = candidate1Name;
        }
        else if (candidate2 > candidate1 and candidate2 > candidate3){
            Winner = candidate2Name;
        }
        else{
            Winner = candidate3Name;
        }
        qry.prepare("INSERT INTO Results (Department, Batch, Winner) "
                          "VALUES (:Department, :Batch, :Winner)");
            qry.bindValue(":Department", Department);
            qry.bindValue(":Batch", Batch);
            qry.bindValue(":Winner", Winner);
            qry.exec();
       // qry.exec("insert into Results (Department, Batch, Winner) values(:Department, :Batch, :Winner);");
        //qry.exec();
        if(!qry.exec()){
            qDebug()<<"Error in inserting into results."<<qry.lastError();
        }
      if(qry.exec() == true){
          QMessageBox::information(this, "Success", "Results Released!");
     } else{
         QMessageBox::information(this, "Failed", "Results Release failed!");
       }
    }
}

    void adminMainWindow::on_pushButton_2_clicked()
    {
        QString candidate1Name, candidate2Name, candidate3Name, Department = "ComputerEngineering";
        int Batch;
        if (db.open()){
            QSqlQuery qry;
            qry.exec("INSERT INTO ResultStatus (ComputerEngineering) VALUES ('1')");
            qry.exec("SELECT sum(candidate1) AS sum1,sum(candidate2) AS sum2, sum(candidate3) AS sum3 FROM VoteCountComputerEngineering;");
            qry.next();
            int candidate1 = qry.value(0).toInt();
            int candidate2 = qry.value(1).toInt();
            int candidate3 = qry.value(3).toInt();
            QString Winner;
            if(!qry.exec()){
                qDebug()<<"Error in summing from votecount computerengineering.";
            }
            qry.exec("SELECT Name, Batch FROM candidatesInformation WHERE Department = 'ComputerEngineering'");
            int i= 0;
            while(qry.next() == true){
                qDebug()<<"Entered query next";
                QSqlRecord rec = qry.record();
                int nameCol = rec.indexOf("Name");// index of the field "name"
                int batchCol = rec.indexOf("Batch");
                QString name = qry.value(nameCol).toString();
                Batch = qry.value(batchCol).toInt();
                std::cout<<"The value of batch in Batch variable: "<<Batch;
                if(i == 0){
                    candidate1Name = name;
                }else if(i==1){
                    candidate2Name = name;
                }else{
                    candidate3Name = name;
                }
                i++;
            }
            if(!qry.exec()){
                qDebug()<<"Error in fetching data from candidates information.";
            }
            if (candidate1 > candidate2 and candidate1 > candidate3){
                //QSqlQuery qry(db)
                Winner = candidate1Name;
            }
            else if (candidate2 > candidate1 and candidate2 > candidate3){
                Winner = candidate2Name;
            }
            else{
                Winner = candidate3Name;
            }

            qry.prepare("INSERT INTO Results (Department, Batch, Winner) "
                              "VALUES (:Department, :Batch, :Winner)");
                qry.bindValue(":Department", Department);
                qry.bindValue(":Batch", Batch);
                qry.bindValue(":Winner", Winner);
                qry.exec();
           // qry.exec("insert into Results (Department, Batch, Winner) values(:Department, :Batch, :Winner);");
            //qry.exec();
            if(!qry.exec()){
                qDebug()<<"Error in inserting into results.";
            }
          if(qry.exec() == true){
              QMessageBox::information(this, "Success", "Results Released!");
         } else{
             QMessageBox::information(this, "Failed", "Results Release failed!");
           }
        }

        }


void adminMainWindow::on_pushButton_clicked()
{
   // db = QSqlDatabase::database("qt_sql_default_connection");
    if(db.open()){
        QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Delete", "Do you want to delete the candidates and the results?",
                                        QMessageBox::Yes|QMessageBox::No);
          if (reply == QMessageBox::Yes) {

              // Fix this. This should all work using one line of code.
              QSqlQuery query;
              query.prepare("DELETE FROM Results");

              query.exec();

              query.prepare("DELETE FROM candidatesInformation");

              query.exec();

              query.prepare("DELETE FROM VoteCountComputerScience");

              query.exec();

              query.prepare("DELETE FROM VoteCountComputerEngineering");

              query.exec();

//              query.prepare("DELETE FROM ResultStatus");
//              query.exec();

            if(query.exec()){
                QMessageBox::information(this, "Confirmed", "Deletion successful!");
            }
            if(!query.exec()){
                qDebug()<<"Deleting records: "<<query.lastError();
                QMessageBox::information(this, "Failed!", "Your action failed!");
            }
          } else{
              QMessageBox::information(this, "cancelled", "Action cancelled.");
          }

    } else{
        qDebug()<<"Database not open.";
    }


}

void adminMainWindow::on_pushButton_6_clicked()
{
   //db = QSqlDatabase::database("qt_sql_default_connection");
    if(db.open()){
        QSqlQuery query;
        QString val = "0";
        // got stuck in a stupid stuuuuuuupid mistake. initially wrote set.. where username and password. This is an admin account. It doesnot HAVE a username and password.
        query.prepare("UPDATE BasicInformation SET VoteStatus = :val");
        query.bindValue(":val", val);
        query.exec();
        if(!query.exec()){
            qDebug()<<"Vote Status not altered from admin: "<<query.lastError();
        }
        QMessageBox::information(this, "Successful!", "Voting Allowed Successfully!");
    }else{
        QMessageBox::information(this, "Failed!", "There's some problem in the database. Contact a technical expert.");
    }
}

