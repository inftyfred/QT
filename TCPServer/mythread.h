#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QDebug>

class myThread :public QThread
{
    Q_OBJECT
public:
    explicit myThread(QTcpSocket *s);
    void run();//需要重写run函数，线程函数的入口

private slots:
    void recvSlot();

signals:
    void sendToWidget(QByteArray b);

private:
    QTcpSocket *socket;

};

#endif // MYTHREAD_H
