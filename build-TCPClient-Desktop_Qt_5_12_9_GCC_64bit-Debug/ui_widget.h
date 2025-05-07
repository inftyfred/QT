/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *addEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *portEdit;
    QPushButton *connectButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        addEdit = new QLineEdit(Widget);
        addEdit->setObjectName(QString::fromUtf8("addEdit"));
        addEdit->setGeometry(QRect(140, 140, 113, 25));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 40, 71, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 130, 91, 31));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 200, 91, 31));
        portEdit = new QLineEdit(Widget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setGeometry(QRect(140, 200, 113, 25));
        connectButton = new QPushButton(Widget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(30, 290, 89, 25));
        cancelButton = new QPushButton(Widget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(220, 290, 89, 25));
        cancelButton->raise();
        addEdit->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        portEdit->raise();
        connectButton->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\256\242\346\210\267\347\253\257</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267</p></body></html>", nullptr));
        connectButton->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        cancelButton->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
