#include "candidatesinformationinput.h"
#include "ui_candidatesinformationinput.h"

CandidatesInformationInput::CandidatesInformationInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CandidatesInformationInput)
{
    ui->setupUi(this);
}

CandidatesInformationInput::~CandidatesInformationInput()
{
    delete ui;
}

void CandidatesInformationInput::on_pushButton_clicked()
{
    db = QSqlDatabase::database("qt_sql_default_connection");
    //QString candidate1Name, candidate2Name, candidate3Name;
    int candidatesCount = 0;
    bool flag = false;
    QString candidateName[3];
    //QString candidate2Department, candidate3Department, candidate1Department;
    QString candidateDepartment[3];
    //QString candidate2RollNumber, candidate3RollNumber, candidate1RollNumber;
    QString candidateRollNumber[3];
    //QString candidate2Batch, candidate3Batch, candidate1Batch;
    QString candidateBatch[3];
    //    int candidate2Batch, candidate3Batch, candidate1Batch;
    //    int candidate2RollNumber, candidate3RollNumber, candidate1RollNumber;

    candidateName[0] = ui->Candidate1Name->text();
    candidateName[1] = ui->Candidate2Name->text();
    candidateName[2] = ui->Candidate3Name->text();

    candidateRollNumber[0] = ui->Candidate1RollNumber->text();
    candidateRollNumber[1] = ui->Candidate2RollNumber->text();
    candidateRollNumber[2] = ui->Candidate3RollNumber->text();

    candidateDepartment[0] = ui->Candidate1Department->text();
    candidateDepartment[1] = ui->Candidate2Department->text();
    candidateDepartment[2] = ui->Candidate3Department->text();

    candidateBatch[0] = ui->Candidate1Batch->text();
    candidateBatch[1] = ui->Candidate2Batch->text();
    candidateBatch[2] = ui->Candidate3Batch->text();

    for(int i=0; i<3; i++){
        QString Roll = candidateRollNumber[i];
        QString Name = candidateName[i];
        QString Department = candidateDepartment[i];
        QString Batch = candidateBatch[i];


        if(!db.open()){
            qWarning() << "ERROR in db: " << db.lastError();
            QMessageBox::information(this, "Failed!", "The database is not open.");
        }
        else{
            for(int i=0; i<2; i++){
                if(candidateRollNumber[i] == candidateRollNumber[i+1] and candidateDepartment[i] == candidateDepartment[i+1] and candidateBatch[i] == candidateBatch[i+1]){
                    QMessageBox::information(this, "Failed!", "Your data is duplicate.");
                    exit(0);
                }
            }
            QSqlQuery qry;
            if(qry.exec("select * from candidatesInformation where Department == '"+Department+"'")){
                while(qry.next() == true){
                    candidatesCount++;
                }
                if(!qry.next()){
                    qDebug()<<"Error in selecting query: "<<db.lastError();
                }
            }
            if(candidatesCount > 3){
                QMessageBox::information(this, "Failed!", "Candidates already selected for the selected department.");
                exit(0);
            } else{
                //QSqlQuery qry;
                qry.prepare("INSERT INTO candidatesInformation (Roll, Name, Department, Batch) "
                            "VALUES (:Roll, :Name, :Department, :Batch)");
                qry.bindValue(":Roll", Roll);
                qry.bindValue(":Name", Name);
                qry.bindValue(":Department", Department);
                qry.bindValue(":Batch", Batch);
                qry.exec();
                flag = true;

                if(!qry.exec()){
                    qDebug() << "ERROR in query: " << db.lastError();
                }
            }

        }
    }
    if(flag == true){
        QMessageBox::information(this, "Success!", "Candidates input successful.");
    }
}
//db.close();
// QSqlDatabase::removeDatabase("StudentInformation");


void CandidatesInformationInput::on_pushButton_3_clicked()
{
    this->hide();
    adminMainWindow c;
    c.setModal(true);
    c.exec();
}
