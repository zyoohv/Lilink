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

#include "lilink.h"
#include "maninfo.h"

namespace Ui {
class UsrInfo;
}

class UsrInfo : public QDialog
{
    Q_OBJECT

public:

    explicit UsrInfo(QWidget *parent = 0);
    ~UsrInfo();

    void ShowInfo(ManInfo *showMan);

signals:

    breakFrindsLink(ManInfo *thisMan);

private slots:
    void on_BreakLink_clicked();

private:
    Ui::UsrInfo *ui;

    ManInfo *thisMan;
};

#endif // USRINFO_H
