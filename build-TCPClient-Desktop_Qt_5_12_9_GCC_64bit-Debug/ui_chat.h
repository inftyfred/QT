/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QLabel *label;
    QLineEdit *mesLineEdit;
    QPushButton *clearButton;
    QPushButton *sendButton;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(400, 300);
        label = new QLabel(Chat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 10, 141, 61));
        mesLineEdit = new QLineEdit(Chat);
        mesLineEdit->setObjectName(QString::fromUtf8("mesLineEdit"));
        mesLineEdit->setGeometry(QRect(60, 80, 271, 71));
        clearButton = new QPushButton(Chat);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(60, 210, 89, 25));
        sendButton = new QPushButton(Chat);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(230, 210, 89, 25));

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", nullptr));
        label->setText(QApplication::translate("Chat", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">\350\276\223\345\205\245\344\277\241\346\201\257</span></p></body></html>", nullptr));
        clearButton->setText(QApplication::translate("Chat", "\346\270\205\347\251\272", nullptr));
        sendButton->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
