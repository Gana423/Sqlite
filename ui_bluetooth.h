/********************************************************************************
** Form generated from reading UI file 'bluetooth.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTH_H
#define UI_BLUETOOTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Bluetooth
{
public:
    QPushButton *ok_Button;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Bluetooth)
    {
        if (Bluetooth->objectName().isEmpty())
            Bluetooth->setObjectName(QStringLiteral("Bluetooth"));
        Bluetooth->resize(312, 71);
        ok_Button = new QPushButton(Bluetooth);
        ok_Button->setObjectName(QStringLiteral("ok_Button"));
        ok_Button->setGeometry(QRect(220, 40, 80, 23));
        lineEdit = new QLineEdit(Bluetooth);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 291, 21));

        retranslateUi(Bluetooth);

        QMetaObject::connectSlotsByName(Bluetooth);
    } // setupUi

    void retranslateUi(QDialog *Bluetooth)
    {
        Bluetooth->setWindowTitle(QApplication::translate("Bluetooth", "Bluetooth", 0));
        ok_Button->setText(QApplication::translate("Bluetooth", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class Bluetooth: public Ui_Bluetooth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTH_H
