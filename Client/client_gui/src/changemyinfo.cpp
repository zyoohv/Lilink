#include "changemyinfo.h"
#include "ui_changemyinfo.h"

ChangeMyInfo::ChangeMyInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeMyInfo)
{
    ui->setupUi(this);
}

ChangeMyInfo::~ChangeMyInfo()
{
    delete ui;
}

void ChangeMyInfo::InitChangeMan(ManInfo *changeMan)
{
    thisMan = changeMan;

    ui->usrId->setText(QString::number(thisMan->getUsrId(), 10));

    ui->nameLineEdit->setText(thisMan->getName());
    ui->infoLineEdit->setText(thisMan->getInformation());
    ui->textBrowser->setText(thisMan->getInfoContent());
}
