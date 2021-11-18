#include "empinfo.h"
#include "ui_empinfo.h"

empInfo::empInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::empInfo)
{
    ui->setupUi(this);
}

empInfo::~empInfo()
{
    delete ui;
}
