#include "addnewfriend.h"
#include "ui_addnewfriend.h"

AddNewFriend::AddNewFriend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewFriend)
{
    ui->setupUi(this);
}

AddNewFriend::~AddNewFriend()
{
    delete ui;
}

void AddNewFriend::initDialogInformation(QList<ManInfo*> *thisFriendsList)
{
    ui->textEdit->clear();
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);
    ui->addButton->setEnabled(true);
    friendsList = thisFriendsList;
}

void AddNewFriend::on_addButton_clicked()
{
    ui->addButton->setEnabled(false);
    ui->progressBar->show();
    ui->progressBar->setValue(0);
    QStringList idList = ui->textEdit->toPlainText().split("\n", QString::SkipEmptyParts);
    ui->textEdit->clear();
    for (int i = 0; i < idList.length(); i++) {
        ui->progressBar->setValue((i + 1) * 100 / idList.length());
        if (AppendNewFriend(friendsList, idList.at(i))) {
            ui->textEdit->insertHtml(QString("<b style=\"color: green\">") + idList.at(i) + QString("[success]</b><br>"));
        }
        else {
            ui->textEdit->insertHtml(QString("<b style=\"color:red\">") + idList.at(i) + QString("[failed]</b><br>"));
        }
    }
}
