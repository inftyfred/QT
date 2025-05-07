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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLineEdit *ipLineEdit;
    QLineEdit *portLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *recvLineEdit;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 70, 121, 61));
        ipLineEdit = new QLineEdit(Widget);
        ipLineEdit->setObjectName(QString::fromUtf8("ipLineEdit"));
        ipLineEdit->setGeometry(QRect(130, 210, 141, 41));
        portLineEdit = new QLineEdit(Widget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(130, 290, 141, 41));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 220, 101, 31));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 290, 101, 31));
        recvLineEdit = new QLineEdit(Widget);
        recvLineEdit->setObjectName(QString::fromUtf8("recvLineEdit"));
        recvLineEdit->setGeometry(QRect(40, 390, 281, 81));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 356, 91, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">\346\234\215\345\212\241\345\231\250</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\256\242\346\210\267\347\253\257\345\234\260\345\235\200</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\256\242\346\210\267\347\253\257\347\253\257\345\217\243</p></body></html>", nullptr));
        label_4->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\216\245\346\224\266\345\214\272</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
