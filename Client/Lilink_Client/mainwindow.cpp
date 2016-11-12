#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lg = new Login(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lg;
}

void MainWindow::initUsrInfo()
{
    /*
     * example.
     * in fact we need get the information from service.
     */
    Node now;
    now.setNodeValue("zyoohv", "silly man", "18683629056", "1711577732", "I love you !");
    lg->usrInfo.push_back(now);


    for (int i = 0; i < lg->usrInfo.size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(lg->usrInfo[i].name));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(lg->usrInfo[i].usrDescribe));
    }
}

void MainWindow::on_actionLog_in_triggered()
{
    if(lg->loginState == true) {
        return ;
    }
    lg->exec();
    ui->tableWidget->setColumnCount(2);
    QStringList m_Header;
    m_Header << QString("name") << QString("info.");
    ui->tableWidget->setHorizontalHeaderLabels(m_Header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    initUsrInfo();
}

void MainWindow::on_actionLog_out_triggered()
{
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->clear();
    lg->loginState = false;
    lg->usrInfo.clear();
}
