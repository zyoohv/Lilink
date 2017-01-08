#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tableWidget->viewport()->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    loginDialog = new Login(this);
    loginState = false;
    connect(loginDialog, SIGNAL(receivedUsrPassWord(QString*,QString*)),
            this, SLOT(on_checkUsrnamePassword(QString*,QString*)));

    usrInformationDialog = new UsrInfo(this);
    connect(usrInformationDialog, SIGNAL(breakFrindsLink(ManInfo*)),
            this, SLOT(on_deleteFriendLink(ManInfo*)));

    changeMyInformationDialog = new ChangeMyInfo(this);

    addNewFriendDialog = new AddNewFriend(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitUsrInfo()
{
    /*
     * get user's information from remote mysql
     * store them to friendsinfors
     * initilize according friendsinfos.
     */
    friendsList->clear();
    friendsList = GetFriendsList(fundamentalId);

    ui->tableWidget->setColumnCount(2);
    QStringList m_Header;
    m_Header << QString("name") << QString("more information");
    ui->tableWidget->setHorizontalHeaderLabels(m_Header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(friendsList->size() - 1);
    for (int i = 1; i < friendsList->size(); i++) {
        ui->tableWidget->setItem(i - 1, 0, new QTableWidgetItem(friendsList->at(i)->getName()));
        ui->tableWidget->setItem(i - 1, 1, new QTableWidgetItem(friendsList->at(i)->getInformation()));
    }

    qDebug() << "initUsrInfo finished.";
}

void MainWindow::on_checkUsrnamePassword(QString* usrname, QString* password)
{
    if (CheckPasswd(usrname, password, fundamentalId)) {
        qDebug() << "Checking Password Success!";
        loginState = true;
        loginDialog->close();
        InitUsrInfo();
    }
    else {
        QMessageBox::warning(this, tr("Warning"), tr("Password Error!"));
    }
}

void MainWindow::on_actionLog_in_triggered()
{
    /* Log in
     */
    if (loginState) {
        QMessageBox::warning(this, tr("Warning"), tr("Log out first plsase!"));
        return ;
    }
    loginDialog->exec();
}

void MainWindow::on_actionLog_out_triggered()
{
    /* Log Out
     */
    if (!loginState) {
        QMessageBox::warning(this, tr("Warning"), tr("Log in first plsase!"));
        return ;
    }

    Clearlog();
}

void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) return ;
    int indexValue = index.row() + 1;

    /*
     * show information detail
     * and support break link.
     */
    usrInformationDialog->ShowInfo(friendsList->at(indexValue));
    usrInformationDialog->exec();
}

void MainWindow::on_actionAcount_info_triggered()
{
    if (!loginState) {
        QMessageBox::warning(this, tr("Warning"), tr("Log in first plsase!"));
        return ;
    }
    changeMyInformationDialog->InitChangeMan(friendsList->at(0));
    changeMyInformationDialog->exec();
}

void MainWindow::on_deleteFriendLink(ManInfo *thisMan)
{
    DeleteFriendLink(friendsList->at(0)->getFundamentalId(), thisMan->getFundamentalId());
    InitUsrInfo();
}

void MainWindow::Clearlog()
{
    ui->tableWidget->clear();

    friendsList->clear();
    loginState = false;
}

void MainWindow::on_buttonRefresh_clicked()
{
    if (!loginState) return ;
    InitUsrInfo();
    QMessageBox::warning(this, tr("Warning"), tr("Refresh Successful!"));
}

void MainWindow::on_buttonAdd_clicked()
{
    if (!loginState) return ;
    addNewFriendDialog->initDialogInformation(friendsList);
    addNewFriendDialog->exec();
    InitUsrInfo();
}
