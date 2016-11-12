/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *username;
    QLineEdit *usrInput;
    QLabel *password;
    QLineEdit *pasInput;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(240, 140);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        username = new QLabel(Login);
        username->setObjectName(QStringLiteral("username"));

        gridLayout->addWidget(username, 0, 0, 1, 1);

        usrInput = new QLineEdit(Login);
        usrInput->setObjectName(QStringLiteral("usrInput"));

        gridLayout->addWidget(usrInput, 0, 1, 1, 1);

        password = new QLabel(Login);
        password->setObjectName(QStringLiteral("password"));

        gridLayout->addWidget(password, 1, 0, 1, 1);

        pasInput = new QLineEdit(Login);
        pasInput->setObjectName(QStringLiteral("pasInput"));

        gridLayout->addWidget(pasInput, 1, 1, 1, 1);

        checkBox = new QCheckBox(Login);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 2, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(Login);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        username->setText(QApplication::translate("Login", "username:", 0));
        password->setText(QApplication::translate("Login", "password:", 0));
        checkBox->setText(QApplication::translate("Login", "Remember me", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
