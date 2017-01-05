 #include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->pasInput->setEchoMode(QLineEdit::Password);

    rememberPasswd = false;
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{
    emit receivedUsrPassWord(new QString(ui->usrInput->text()), new QString(ui->pasInput->text()));

    if (!rememberPasswd) {
        ui->pasInput->clear();
    }
}

void Login::on_rememberMe_toggled(bool checked)
{
    rememberPasswd = checked;
}

void Login::on_buttonBox_rejected()
{
    this->close();
}
