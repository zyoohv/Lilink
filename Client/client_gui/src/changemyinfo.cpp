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

    ui->usrId->setText(thisMan->getUsrId());

    ui->nameLineEdit->setText(thisMan->getName());
    ui->infoLineEdit->setText(thisMan->getInformation());
    ui->textEdit->setPlainText(thisMan->getInfoContent());
}

void ChangeMyInfo::on_pushButton_clicked()
{
    QUuid newId = QUuid::createUuid();
    ui->usrId->setText(newId.toString());
}

void ChangeMyInfo::on_cancelButton_clicked()
{
    this->close();
}

void ChangeMyInfo::on_saveButton_clicked()
{
    thisMan->setName(ui->nameLineEdit->text());
    thisMan->setInformation(ui->infoLineEdit->text());
    thisMan->setInfoContent(ui->textEdit->toPlainText());
    thisMan->setUsrId(ui->usrId->text());

    ApplyUsrInfo(thisMan);
    this->close();
}
