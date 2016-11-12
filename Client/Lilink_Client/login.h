#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QVector>

namespace Ui {
class Login;
}

class Node
{
public:
    QString name;
    QString usrDescribe;
    QString telephoneNumber;
    QString qqNumber;
    QString others;
    Node() = default;
    void setNodeValue(QString _name, QString _describe, QString _tel, QString _qq, QString _oth) {
        name = _name;
        usrDescribe = _describe;
        telephoneNumber = _tel;
        qqNumber = _qq;
        others = _oth;
    }
       // name(_name), usrDescribe(_describe), telephoneNumber(_tel), qqNumber(_qq), others(_oth) {}
};

class Login : public QDialog
{
    Q_OBJECT

public:

    friend class MainWindow;

    explicit Login(QWidget *parent = 0);
    ~Login();

signals:
    void acceptusr();

private slots:
    void on_buttonBox_accepted();
    void checkUsr();

private:
    Ui::Login *ui;

    QString *usr;
    QString *pas;
    bool loginState;
    QVector<Node>usrInfo;
};

#endif // LOGIN_H
