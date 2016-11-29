/********************************************************************************
** Form generated from reading UI file 'usrinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRINFO_H
#define UI_USRINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UsrInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Title;
    QTextBrowser *showUsrInfo;
    QHBoxLayout *horizontalLayout;
    QPushButton *BreakLink;
    QLabel *State;

    void setupUi(QDialog *UsrInfo)
    {
        if (UsrInfo->objectName().isEmpty())
            UsrInfo->setObjectName(QStringLiteral("UsrInfo"));
        UsrInfo->resize(240, 320);
        verticalLayout = new QVBoxLayout(UsrInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Title = new QLabel(UsrInfo);
        Title->setObjectName(QStringLiteral("Title"));

        verticalLayout->addWidget(Title);

        showUsrInfo = new QTextBrowser(UsrInfo);
        showUsrInfo->setObjectName(QStringLiteral("showUsrInfo"));

        verticalLayout->addWidget(showUsrInfo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BreakLink = new QPushButton(UsrInfo);
        BreakLink->setObjectName(QStringLiteral("BreakLink"));

        horizontalLayout->addWidget(BreakLink);

        State = new QLabel(UsrInfo);
        State->setObjectName(QStringLiteral("State"));

        horizontalLayout->addWidget(State);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UsrInfo);

        QMetaObject::connectSlotsByName(UsrInfo);
    } // setupUi

    void retranslateUi(QDialog *UsrInfo)
    {
        UsrInfo->setWindowTitle(QApplication::translate("UsrInfo", "usr information", 0));
        Title->setText(QApplication::translate("UsrInfo", "Usrinfo.", 0));
        BreakLink->setText(QApplication::translate("UsrInfo", "BreakLink", 0));
        State->setText(QApplication::translate("UsrInfo", "State: link", 0));
    } // retranslateUi

};

namespace Ui {
    class UsrInfo: public Ui_UsrInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRINFO_H
