#ifndef EMPINFO_H
#define EMPINFO_H

#include <QDialog>

namespace Ui {
class empInfo;
}

class empInfo : public QDialog
{
    Q_OBJECT

public:
    explicit empInfo(QWidget *parent = nullptr);
    ~empInfo();

private:
    Ui::empInfo *ui;
};

#endif // EMPINFO_H
