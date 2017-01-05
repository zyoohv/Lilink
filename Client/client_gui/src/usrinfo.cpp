#include "usrinfo.h"
#include "ui_usrinfo.h"

UsrInfo::UsrInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsrInfo)
{
    ui->setupUi(this);
}

UsrInfo::~UsrInfo()
{
    delete ui;
}

void UsrInfo::ShowInfo(ManInfo *showMan)
{
    thisMan = showMan;
    ui->Title->setText(QString("%1").arg(thisMan->getUsrId()));

    ui->showUsrInfo->clear();
    ui->showUsrInfo->append(QString("Name: ") + thisMan->getName());
    ui->showUsrInfo->append(QString("Information: ") + thisMan->getInformation());
    ui->showUsrInfo->append(thisMan->getInfoContent());
}

void UsrInfo::on_BreakLink_clicked()
{
    QMessageBox::StandardButton makeSure = QMessageBox::question(this, tr("warning"), tr("Are your sure to delete the friend?"), QMessageBox::Yes|QMessageBox::No);
    if (makeSure == QMessageBox::Yes) {
        emit breakFrindsLink(thisMan);
    }
}
