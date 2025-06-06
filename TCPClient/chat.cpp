#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);

    socket = s;
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_sendButton_clicked()
{
    QByteArray ba;
    ba.append(ui->mesLineEdit->text());//QString转ba
    socket->write(ba);//发送数据
}

void Chat::on_clearButton_clicked()
{
    ui->mesLineEdit->clear();
}
