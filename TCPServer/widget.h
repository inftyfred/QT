#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <mythread.h>

#define PORT   9000

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void newClientHandler();
    void threadSlot(QByteArray b);
    //void recvSlot();

private:
    Ui::Widget *ui;
    QTcpServer *server;
};
#endif // WIDGET_H
