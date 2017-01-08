/********************************************************************************
** Form generated from reading UI file 'addnewfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWFRIEND_H
#define UI_ADDNEWFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddNewFriend
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QPushButton *addButton;

    void setupUi(QDialog *AddNewFriend)
    {
        if (AddNewFriend->objectName().isEmpty())
            AddNewFriend->setObjectName(QStringLiteral("AddNewFriend"));
        AddNewFriend->resize(448, 252);
        verticalLayout = new QVBoxLayout(AddNewFriend);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(AddNewFriend);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        progressBar = new QProgressBar(AddNewFriend);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        addButton = new QPushButton(AddNewFriend);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddNewFriend);

        QMetaObject::connectSlotsByName(AddNewFriend);
    } // setupUi

    void retranslateUi(QDialog *AddNewFriend)
    {
        AddNewFriend->setWindowTitle(QApplication::translate("AddNewFriend", "Dialog", Q_NULLPTR));
        addButton->setText(QApplication::translate("AddNewFriend", "Add", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddNewFriend: public Ui_AddNewFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWFRIEND_H
