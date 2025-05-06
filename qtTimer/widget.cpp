#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    picID = 2;
    //图片路径
    QPixmap pix("/home/infty/qt_prj/qtTimer/subset/1.jpg");
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    //开启定时器，返回定时器的编号
    myTimerID = this->startTimer(TIMEOUT);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() != myTimerID)
        return ;
    QString path("/home/infty/qt_prj/qtTimer/subset/");
    path += QString::number(picID);
    path += ".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picID++;
    if(6 == picID)
    {
        picID = 1;
    }
}

void Widget::on_finishButton_clicked()
{
    //关闭定时器
    this->killTimer(myTimerID);
}
