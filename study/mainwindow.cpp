#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //连接信号与槽
    //谁发出信号 发出啥信号 发给谁 怎么处理
    connect(ui->cmdlineEdit, SIGNAL(returnPressed()), this, SLOT(on_commitButton_clicked()));

    connect(ui->cancelButton, &QPushButton::clicked, this, &MainWindow::on_cancelButton_clicked);

    connect(ui->browseButton, &QPushButton::clicked, [this]()
    {
        QMessageBox::information(this, "信息", "点击浏览");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_commitButton_clicked()
{
    //获取lineedit数据
    QString program = ui->cmdlineEdit->text();
    //创建Process对象
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}

void MainWindow::on_cancelButton_clicked()
{
    this->close();
}
