/********************************************************************************
** Form generated from reading UI file 'changemyinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEMYINFO_H
#define UI_CHANGEMYINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChangeMyInfo
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *usrId;
    QPushButton *pushButton;
    QLabel *name;
    QLineEdit *nameLineEdit;
    QLabel *information;
    QLineEdit *infoLineEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *InfoContent;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ChangeMyInfo)
    {
        if (ChangeMyInfo->objectName().isEmpty())
            ChangeMyInfo->setObjectName(QStringLiteral("ChangeMyInfo"));
        ChangeMyInfo->resize(240, 320);
        verticalLayout_2 = new QVBoxLayout(ChangeMyInfo);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        usrId = new QLabel(ChangeMyInfo);
        usrId->setObjectName(QStringLiteral("usrId"));

        gridLayout->addWidget(usrId, 0, 0, 1, 1);

        pushButton = new QPushButton(ChangeMyInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        name = new QLabel(ChangeMyInfo);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 1, 0, 1, 1);

        nameLineEdit = new QLineEdit(ChangeMyInfo);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 1, 1, 1, 1);

        information = new QLabel(ChangeMyInfo);
        information->setObjectName(QStringLiteral("information"));

        gridLayout->addWidget(information, 2, 0, 1, 1);

        infoLineEdit = new QLineEdit(ChangeMyInfo);
        infoLineEdit->setObjectName(QStringLiteral("infoLineEdit"));

        gridLayout->addWidget(infoLineEdit, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        InfoContent = new QLabel(ChangeMyInfo);
        InfoContent->setObjectName(QStringLiteral("InfoContent"));

        horizontalLayout->addWidget(InfoContent);

        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(ChangeMyInfo);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        saveButton = new QPushButton(ChangeMyInfo);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_2->addWidget(saveButton);

        cancelButton = new QPushButton(ChangeMyInfo);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(ChangeMyInfo);

        QMetaObject::connectSlotsByName(ChangeMyInfo);
    } // setupUi

    void retranslateUi(QDialog *ChangeMyInfo)
    {
        ChangeMyInfo->setWindowTitle(QApplication::translate("ChangeMyInfo", "Change information", Q_NULLPTR));
        usrId->setText(QApplication::translate("ChangeMyInfo", "usrId", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ChangeMyInfo", "Apply Change Id", Q_NULLPTR));
        name->setText(QApplication::translate("ChangeMyInfo", "Name", Q_NULLPTR));
        information->setText(QApplication::translate("ChangeMyInfo", "Information", Q_NULLPTR));
        InfoContent->setText(QApplication::translate("ChangeMyInfo", "InfoContent", Q_NULLPTR));
        saveButton->setText(QApplication::translate("ChangeMyInfo", "Save", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ChangeMyInfo", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeMyInfo: public Ui_ChangeMyInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEMYINFO_H
