/********************************************************************************
** Form generated from reading UI file 'changemyinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ChangeMyInfo
{
public:
    QLabel *label;

    void setupUi(QDialog *ChangeMyInfo)
    {
        if (ChangeMyInfo->objectName().isEmpty())
            ChangeMyInfo->setObjectName(QStringLiteral("ChangeMyInfo"));
        ChangeMyInfo->resize(240, 320);
        label = new QLabel(ChangeMyInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 130, 111, 31));

        retranslateUi(ChangeMyInfo);

        QMetaObject::connectSlotsByName(ChangeMyInfo);
    } // setupUi

    void retranslateUi(QDialog *ChangeMyInfo)
    {
        ChangeMyInfo->setWindowTitle(QApplication::translate("ChangeMyInfo", "Change information", 0));
        label->setText(QApplication::translate("ChangeMyInfo", "Waitting for you!", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangeMyInfo: public Ui_ChangeMyInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEMYINFO_H
