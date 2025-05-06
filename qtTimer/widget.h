#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#define TIMEOUT (1 * 1000) //1s

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    virtual void timerEvent(QTimerEvent *event);
    ~Widget();

private slots:
    void on_startButton_clicked();

    void on_finishButton_clicked();

    void timeoutSlot();

private:
    Ui::Widget *ui;
    int myTimerID;
    int picID;
};
#endif // WIDGET_H
