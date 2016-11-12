#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->pasInput->setEchoMode(QLineEdit::Password);

    loginState = false;
    usrInfo.clear();

    connect(this, SIGNAL(acceptusr()), this, SLOT(close()));
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{
    usr = new QString(ui->usrInput->text());
    pas = new QString(ui->pasInput->text());
    ui->pasInput->clear();
    checkUsr();
}

void Login::checkUsr()
{
    /*
     * example: usr=zyoohv, pas=zyoohv123
     */
    if (*usr == QString("zyoohv") && *pas == QString("zyoohv123")) {
        loginState = true;
        emit acceptusr();
    }
}
