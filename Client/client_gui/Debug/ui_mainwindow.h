/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
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
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonAdd;
    QPushButton *buttonRefresh;
    QMenuBar *menuBar;
    QMenu *menuLilink;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(251, 358);
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
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonAdd = new QPushButton(centralWidget);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));

        horizontalLayout->addWidget(buttonAdd);

        buttonRefresh = new QPushButton(centralWidget);
        buttonRefresh->setObjectName(QStringLiteral("buttonRefresh"));

        horizontalLayout->addWidget(buttonRefresh);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 251, 23));
        menuLilink = new QMenu(menuBar);
        menuLilink->setObjectName(QStringLiteral("menuLilink"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuLilink->menuAction());
        menuLilink->addAction(actionLog_in);
        menuLilink->addAction(actionLog_out);
        menuLilink->addAction(actionAcount_info);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lilink", Q_NULLPTR));
        actionLog_in->setText(QApplication::translate("MainWindow", "log in", Q_NULLPTR));
        actionLog_out->setText(QApplication::translate("MainWindow", "log out", Q_NULLPTR));
        actionAcount_info->setText(QApplication::translate("MainWindow", "acount info.", Q_NULLPTR));
        actionName->setText(QApplication::translate("MainWindow", "name", Q_NULLPTR));
        actionTelephone->setText(QApplication::translate("MainWindow", "telephone", Q_NULLPTR));
        actionQq->setText(QApplication::translate("MainWindow", "qq", Q_NULLPTR));
        actionVcf->setText(QApplication::translate("MainWindow", "vcf", Q_NULLPTR));
        actionDoc->setText(QApplication::translate("MainWindow", "doc", Q_NULLPTR));
        actionPdf->setText(QApplication::translate("MainWindow", "pdf", Q_NULLPTR));
        buttonAdd->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        buttonRefresh->setText(QApplication::translate("MainWindow", "Refresh", Q_NULLPTR));
        menuLilink->setTitle(QApplication::translate("MainWindow", "Lilink", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
