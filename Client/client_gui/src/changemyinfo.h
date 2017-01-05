/*
 * Usage:
 *
 * 1. initilize the maninfo.
 *      InitChangeMan(ManInfo *changeMan)
 * 2. exec()
 *
 * Function:
 *
 * 1. Edit the information of the user.
 * 2. Apply to change usr id.
 *
 */

#ifndef CHANGEMYINFO_H
#define CHANGEMYINFO_H

#include "lilink.h"
#include "maninfo.h"

namespace Ui {
class ChangeMyInfo;
}

class ChangeMyInfo : public QDialog
{
    Q_OBJECT

public:

    explicit ChangeMyInfo(QWidget *parent = 0);
    ~ChangeMyInfo();

    void InitChangeMan(ManInfo *changeMan);

private:
    Ui::ChangeMyInfo *ui;

    ManInfo* thisMan;
};

#endif // CHANGEMYINFO_H
