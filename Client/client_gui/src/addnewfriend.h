#ifndef ADDNEWFRIEND_H
#define ADDNEWFRIEND_H

#include "lilink.h"
#include "database.h"

namespace Ui {
class AddNewFriend;
}

class AddNewFriend : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewFriend(QWidget *parent = 0);
    ~AddNewFriend();

    void initDialogInformation(QList<ManInfo*> *thisFriendsList);

private slots:
    void on_addButton_clicked();

private:
    Ui::AddNewFriend *ui;

    QList<ManInfo*> *friendsList;
};

#endif // ADDNEWFRIEND_H
