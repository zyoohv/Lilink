#include "usrinfo.h"
#include "ui_usrinfo.h"

UsrInfo::UsrInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsrInfo)
{
    ui->setupUi(this);

    isBreak = false;
}

UsrInfo::~UsrInfo()
{
    delete ui;
}

void UsrInfo::ShowInfo(ManInfo *thisMan)
{
    ui->Title->setText(QString("%1").arg(thisMan->getUsrId()));

    ui->showUsrInfo->clear();
    ui->showUsrInfo->append(QString("Name: ") + thisMan->getName());
    ui->showUsrInfo->append(QString("Information: ") + thisMan->getInformation());
    ui->showUsrInfo->append(thisMan->getInfoContent());
}

void UsrInfo::on_BreakLink_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::question(this, tr("warning"), tr("Are your sure to delete the friend?"), QMessageBox::Yes|QMessageBox::No);
    if (rb == QMessageBox::Yes) {
        isBreak = true;
    }
}
