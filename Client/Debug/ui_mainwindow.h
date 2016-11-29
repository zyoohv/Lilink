/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLog_in;
    QAction *actionLog_out;
    QAction *actionAcount_info;
    QAction *actionName;
    QAction *actionTelephone;
    QAction *actionQq;
    QAction *actionVcf;
    QAction *actionDoc;
    QAction *actionPdf;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout;
    QPushButton *buttonAdd;
    QPushButton *buttonRemove;
    QPushButton *buttonSync;
    QPushButton *buttonExportvcf;
    QMenuBar *menuBar;
    QMenu *menuLilink;
    QMenu *menuEdit;
    QMenu *menuExport_as;
    QMenu *menuFind;
    QMenu *menuFind_by;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(594, 358);
        actionLog_in = new QAction(MainWindow);
        actionLog_in->setObjectName(QStringLiteral("actionLog_in"));
        actionLog_out = new QAction(MainWindow);
        actionLog_out->setObjectName(QStringLiteral("actionLog_out"));
        actionAcount_info = new QAction(MainWindow);
        actionAcount_info->setObjectName(QStringLiteral("actionAcount_info"));
        actionName = new QAction(MainWindow);
        actionName->setObjectName(QStringLiteral("actionName"));
        actionTelephone = new QAction(MainWindow);
        actionTelephone->setObjectName(QStringLiteral("actionTelephone"));
        actionQq = new QAction(MainWindow);
        actionQq->setObjectName(QStringLiteral("actionQq"));
        actionVcf = new QAction(MainWindow);
        actionVcf->setObjectName(QStringLiteral("actionVcf"));
        actionDoc = new QAction(MainWindow);
        actionDoc->setObjectName(QStringLiteral("actionDoc"));
        actionPdf = new QAction(MainWindow);
        actionPdf->setObjectName(QStringLiteral("actionPdf"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setAutoFillBackground(false);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonAdd = new QPushButton(centralWidget);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));

        gridLayout->addWidget(buttonAdd, 0, 0, 1, 1);

        buttonRemove = new QPushButton(centralWidget);
        buttonRemove->setObjectName(QStringLiteral("buttonRemove"));

        gridLayout->addWidget(buttonRemove, 0, 1, 1, 1);

        buttonSync = new QPushButton(centralWidget);
        buttonSync->setObjectName(QStringLiteral("buttonSync"));

        gridLayout->addWidget(buttonSync, 1, 0, 1, 1);

        buttonExportvcf = new QPushButton(centralWidget);
        buttonExportvcf->setObjectName(QStringLiteral("buttonExportvcf"));

        gridLayout->addWidget(buttonExportvcf, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 20));
        menuLilink = new QMenu(menuBar);
        menuLilink->setObjectName(QStringLiteral("menuLilink"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuExport_as = new QMenu(menuEdit);
        menuExport_as->setObjectName(QStringLiteral("menuExport_as"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QStringLiteral("menuFind"));
        menuFind_by = new QMenu(menuFind);
        menuFind_by->setObjectName(QStringLiteral("menuFind_by"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuLilink->menuAction());
        menuBar->addAction(menuFind->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuLilink->addAction(actionLog_in);
        menuLilink->addAction(actionLog_out);
        menuLilink->addAction(actionAcount_info);
        menuEdit->addAction(menuExport_as->menuAction());
        menuExport_as->addAction(actionVcf);
        menuExport_as->addAction(actionDoc);
        menuExport_as->addAction(actionPdf);
        menuFind->addAction(menuFind_by->menuAction());
        menuFind_by->addAction(actionName);
        menuFind_by->addAction(actionTelephone);
        menuFind_by->addAction(actionQq);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lilink", 0));
        actionLog_in->setText(QApplication::translate("MainWindow", "log in", 0));
        actionLog_out->setText(QApplication::translate("MainWindow", "log out", 0));
        actionAcount_info->setText(QApplication::translate("MainWindow", "acount info.", 0));
        actionName->setText(QApplication::translate("MainWindow", "name", 0));
        actionTelephone->setText(QApplication::translate("MainWindow", "telephone", 0));
        actionQq->setText(QApplication::translate("MainWindow", "qq", 0));
        actionVcf->setText(QApplication::translate("MainWindow", "vcf", 0));
        actionDoc->setText(QApplication::translate("MainWindow", "doc", 0));
        actionPdf->setText(QApplication::translate("MainWindow", "pdf", 0));
        buttonAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        buttonRemove->setText(QApplication::translate("MainWindow", "Remove", 0));
        buttonSync->setText(QApplication::translate("MainWindow", "Sync", 0));
        buttonExportvcf->setText(QApplication::translate("MainWindow", "export(vcf)", 0));
        menuLilink->setTitle(QApplication::translate("MainWindow", "Lilink", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuExport_as->setTitle(QApplication::translate("MainWindow", "Export as", 0));
        menuFind->setTitle(QApplication::translate("MainWindow", "Find", 0));
        menuFind_by->setTitle(QApplication::translate("MainWindow", "Search by ...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
