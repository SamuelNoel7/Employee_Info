#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Samuel Noel/Pictures/Saved Pictures/wall.jpg");
    ui->label_pic->setPixmap(pix);

    employeeInfo = QSqlDatabase::addDatabase("QSQLITE");
    employeeInfo.setDatabaseName("D:/Kagada/Employees.db");
    if(!employeeInfo.open())
            ui->label->setText("Failed to open the database");

    else
        ui->label->setText("connected..");
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    QString username,password;
    username = ui->empUsername->text();
    password = ui->empPassword->text();

    if(!employeeInfo.open())
      {
        qDebug()<<"Failed to open the database";
        return;
    }
    QSqlQuery qry;
    if(qry.exec("select * from tbl_Employeeinfo where username ='"+username+"' and password = '"+password+"'"))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->label->setText("username and password is correct");
            this->hide();
            empInfo empInfo;
            empInfo.setModal(true);
            empInfo.exec();
        }
        if(count>1)
            ui->label->setText("Duplicater username and password");
        if(count<1)
            ui->label->setText("username and password is incorrect");
    }


}

