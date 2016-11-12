#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    friend class Login;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLog_in_triggered();
    void on_actionLog_out_triggered();

private:

    void initUsrInfo();

    Ui::MainWindow *ui;

    Login *lg;
};

#endif // MAINWINDOW_H
