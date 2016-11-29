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
    connect(loginDialog, SIGNAL(receivedUsrPassWord(QString*,QString*)),
            this, SLOT(on_checkUsrnamePassword(QString*,QString*)));

    usrInformationDialog = new UsrInfo(this);
    changeMyInformationDialog = new ChangeMyInfo(this);

    loginState = false;

    db = new QSqlDatabase;
    SetDatabase(db);
    if (!db->open()) {
        QMessageBox::warning(this, tr("Warning"), tr("NetWork Error!"));
        this->close();
    }
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

    friendsList = GetFriendsList(fundamentalId, db);

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
    if (CheckPasswd(usrname, password, fundamentalId, db)) {
        loginState = true;
        loginDialog->close();
        InitUsrInfo();
    }
}

void MainWindow::on_actionLog_in_triggered()
{
    /*
     * Log in
     */
    if (loginState) {
        QMessageBox::warning(this, tr("Warning"), tr("Log out first plsase!"));
        return ;
    }

    loginDialog->exec();
}

void MainWindow::on_actionLog_out_triggered()
{
    /*
     * Log Out
     */
    if (!loginState) {
        QMessageBox::warning(this, tr("Warning"), tr("Log in first plsase!"));
        return ;
    }

    Clearlog();
}

void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return ;
    int indexValue = index.row();
    /*
     * show some information when be clicked
     * on mainwindow.
     * not sure how and what to show.
     */
}

void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) return ;
    int indexValue = index.row();

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

void MainWindow::Clearlog()
{
    ui->tableWidget->clear();
    ui->textBrowser->clear();

    friendsList->clear();
    loginState = false;
}
