#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(320, 500);
    this->setMinimumSize(320, 500);

    this->setWindowTitle("计算器");

    QFont f("仿宋", 20);
    ui->dataLineEdit->setFont(f);

    //在按钮上放图片
    QIcon icon("/home/infty/Desktop/left");
    ui->delButton->setIcon(icon);

    //改变按钮背景颜色
    ui->equalButton->setStyleSheet("background:blue");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_oneBuitton_clicked()
{
    expression += "1";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_twoButton_clicked()
{
    expression += "2";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_threeButton_clicked()
{
    expression += "3";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_fourButton_clicked()
{
    expression += "4";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_fiveButton_clicked()
{
    expression += "5";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_sixButton_clicked()
{
    expression += "6";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_sevenButton_clicked()
{
    expression += "7";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_eightButton_clicked()
{
    expression += "8";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_nineButton_clicked()
{
    expression += "9";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_zeroButton_clicked()
{
    expression += "0";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_leftButton_clicked()
{
    expression += "(";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_rightButton_clicked()
{
    expression += ")";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_addButton_clicked()
{
    expression += "+";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_subButton_clicked()
{
    expression += "-";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_mulButton_clicked()
{
    expression += "*";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_divButton_clicked()
{
    expression += "/";
    ui->dataLineEdit->setText(expression);
}

void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->dataLineEdit->clear();
}

void Widget::on_delButton_clicked()
{
    expression.chop(1);//删除最后一个字符
    ui->dataLineEdit->setText(expression);
}

void Widget::on_equalButton_clicked()
{
    QStack<int> s_num, s_opt;

    char opt[128] = {0};
    int i = 0, tmp = 0, num1, num2;

    //把QString转换成char *
    QByteArray ba;
    ba.append(expression);
    strcpy(opt, ba.data());

    while(opt[i] != '\0' || s_opt.empty() != true)
    {
        if(opt[i] >= '0' && opt[i] <= '9')
        {
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if(opt[i] < '0' || opt[i] > '9')
            {
                s_num.push(tmp);
                tmp = 0;
            }
        }
        else
        {
            if(s_opt.empty() == true || Priority(opt[i]) > Priority(s_opt.top())
                    || (s_opt.top() == '(' && opt[i] != ')'))
            {
                s_opt.push(opt[i]);
                i++;
                continue;
            }
            if(s_opt.top() == '(' && opt[i] == ')')
            {
                s_opt.pop();
                i++;
                continue;
            }
            if(Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] == ')' && s_opt.top() != '(')
                    || (opt[i] == '\0' && s_opt.empty() != true))
            {
                char ch = s_opt.top();
                s_opt.pop();
                switch (ch) {
                    case '+':
                        num1 = s_num.top(); s_num.pop();
                        num2 = s_num.top(); s_num.pop();
                        s_num.push(num1 + num2);
                        break;
                    case '-':
                        num1 = s_num.top(); s_num.pop();
                        num2 = s_num.top(); s_num.pop();
                        s_num.push(num1 - num2);
                        break;
                    case '*':
                        num1 = s_num.top(); s_num.pop();
                        num2 = s_num.top(); s_num.pop();
                        s_num.push(num1 * num2);
                        break;
                   case '/':
                        num1 = s_num.top(); s_num.pop();
                        num2 = s_num.top(); s_num.pop();
                        s_num.push(num1 / num2);
                        break;
                }
            }
        }
    }
    ui->dataLineEdit->setText(QString::number(s_num.top()));
    expression.clear();
}

//判断符号优先级
int Widget::Priority(char ch)
{
    switch(ch)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
