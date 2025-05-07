#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QTcpSocket;//创建socket对象

    ui->addEdit->setText("127.0.0.1");
    ui->portEdit->setText("9000");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_cancelButton_clicked()
{
    this->close();
}

void Widget::on_connectButton_clicked()
{
    //获取ip地址和端口号
    QString ip = ui->addEdit->text();
    QString port = ui->portEdit->text();

    //连接服务器
    socket->connectToHost(QHostAddress(ip), port.toShort());

    //连接服务器成功，socket对象会发出一个信号
    connect(socket, &QTcpSocket::connected, [this]()
    {
        QMessageBox::information(this, "连接提示", "连接成功！");

        this->hide();//连接成功隐藏界面

        Chat *c = new Chat(socket);//堆空间创建
        c->show();
    });

    connect(socket, &QTcpSocket::disconnected, [this]()
    {
        QMessageBox::information(this, "连接提示", "连接失败");
    });
}
