#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:

    explicit Login(QWidget *parent = 0);
    ~Login();

signals:
    void receivedUsrPassWord(QString*, QString*);

private slots:
    void on_buttonBox_accepted();

    void on_rememberMe_toggled(bool checked);

    void on_buttonBox_rejected();

private:
    Ui::Login *ui;

    bool rememberPasswd;
};

#endif // LOGIN_H
