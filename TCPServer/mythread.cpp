#include "mythread.h"

myThread::myThread(QTcpSocket *s)
{
    socket = s;
}

void myThread::run()
{
    //接收客户端的消息
    connect(socket, &QTcpSocket::readyRead, this, &myThread::recvSlot);

}


void myThread::recvSlot()
{
   //qDebug() << socket->readAll();
    QByteArray ba = socket->readAll();
    emit sendToWidget(ba);  //发送信号
}
