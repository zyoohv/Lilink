/*
 * Usage:
 *
 * 1. initilize.
 *      ShowInfo(ManInfo *changeMan)
 * 2. exec()
 *
 * Function:
 *
 * 1. Show details of the usr
 * 2. Break the Link(also can be seen as deleting the friend).
 *
 */

#ifndef USRINFO_H
#define USRINFO_H

#include <QDialog>
#include <QMessageBox>
#include "maninfo.h"

namespace Ui {
class UsrInfo;
}

class UsrInfo : public QDialog
{
    Q_OBJECT

public:

    friend class MainWindow;

    explicit UsrInfo(QWidget *parent = 0);
    ~UsrInfo();

private slots:
    void on_BreakLink_clicked();

private:
    Ui::UsrInfo *ui;

    void ShowInfo(ManInfo *thisMan);

    bool isBreak;
};

#endif // USRINFO_H
