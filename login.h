#ifndef LOGIN_H
#define LOGIN_H
#include <QtSql>
#include <QMainWindow>
#include <QDebug>
#include <QFileInfo>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include "empinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase employeeInfo;
};
#endif // LOGIN_H
