#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lilink.h"
#include "login.h"
#include "usrinfo.h"
#include "changemyinfo.h"
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLog_in_triggered();

    void on_actionLog_out_triggered();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_actionAcount_info_triggered();

    void on_checkUsrnamePassword(QString*, QString*);

    void on_deleteFriendLink(ManInfo*);

private:

    void InitUsrInfo();

    void Clearlog();

    Ui::MainWindow *ui;

    Login *loginDialog;
    UsrInfo *usrInformationDialog;
    ChangeMyInfo *changeMyInformationDialog;

    /*  friendsinfo information:
     *  at index 0, it's user's information
     *  so the friends' information begin with the index of the 1
     */
    QList<ManInfo*> *friendsList;

    QString *usrName;
    QString *passWord;
    int fundamentalId;
    bool loginState;
};

#endif // MAINWINDOW_H
