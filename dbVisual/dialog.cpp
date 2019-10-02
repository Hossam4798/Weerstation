#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Online database
    dbOne = QSqlDatabase::addDatabase("QMYSQL", "first");
    dbOne.setHostName("databases.aii.avans.nl");
    dbOne.setPort(3306);
    dbOne.setUserName("qjpmdint");
    dbOne.setPassword("Ab123456");
    dbOne.setDatabaseName("qjpmdint_db");

    //Local database
    dbTwo = QSqlDatabase::addDatabase("QMYSQL", "second");
    dbTwo.setHostName("localhost");
    dbTwo.setPort(3306);
    dbTwo.setUserName("root");
    dbTwo.setPassword("");
    dbTwo.setDatabaseName("weatherstation");

    QSqlDatabase db0 = QSqlDatabase::addDatabase("QMYSQL");

    if(dbOne.open() || dbTwo.open()){
        if(dbOne.open()){

            db0 = dbOne;

        }else if(dbTwo.open()){
             QMessageBox::information(this, "Failed", "Database connection Failed. Starting local database.");
             db0 = dbTwo;
        }

        querymodel = new QSqlQueryModel();
        querymodel->setQuery("SELECT * FROM sensordata WHERE id = (SELECT max(id) FROM sensordata) ORDER BY id desc;", db0);
        ui->tableView->setModel(querymodel);

    }else{
        QMessageBox::information(this, "Failed", "Couldn't open any database. Click ok to close application");
        dbOne.close();
        dbTwo.close();
        Dialog().close();
    }

//    qDebug() << querymodel->lastError();

}

Dialog::~Dialog()
{
    dbOne.close();
    dbTwo.close();

    delete ui;
}

