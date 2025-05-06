// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_process(new QProcess(this))
{
    ui->setupUi(this);

    // 初始化UI状态study
    setWindowTitle("AI 图像处理器");
    resize(800, 600);

    // 连接信号槽
    connect(m_process, &QProcess::readyReadStandardOutput,
            this, &MainWindow::handleProcessOutput);
    connect(m_process, QOverload<int>::of(&QProcess::finished),
            this, &MainWindow::handleProcessFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseModelBtn_clicked()
{
    QString path = QFileDialog::getOpenFileName(
        this, "选择模型文件", "",
        "模型文件 (*.onnx *.pt *.model);;所有文件 (*.*)");
    if (!path.isEmpty()) {
        ui->modelPathEdit->setText(path);
    }
}

void MainWindow::on_browseImageBtn_clicked()
{
    QString path = QFileDialog::getOpenFileName(
        this, "选择图片文件", "",
        "图片文件 (*.png *.jpg *.jpeg *.bmp);;所有文件 (*.*)");
    if (!path.isEmpty()) {
        ui->imagePathEdit->setText(path);
    }
}

void MainWindow::on_browseOutputBtn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(
        this, "选择输出目录", QDir::homePath());
    if (!dir.isEmpty()) {
        ui->outputPathEdit->setText(dir);
    }
}

void MainWindow::on_processBtn_clicked()
{
    const QString modelPath = ui->modelPathEdit->text();
    const QString imagePath = ui->imagePathEdit->text();
    const QString outputDir = ui->outputPathEdit->text();

    // 验证输入有效性
    if (!QFile::exists(modelPath)) {
        showError("模型文件路径无效");
        return;
    }
    if (!QFile::exists(imagePath)) {
        showError("图片文件路径无效");
        return;
    }
    if (!QDir(outputDir).exists()) {
        showError("输出目录无效");
        return;
    }

    // 准备执行命令
    QString program = "your_processor";
    QStringList arguments;
    arguments << modelPath << imagePath << outputDir;

    appendLog("启动处理进程...");
    appendLog(QString("命令: %1 %2 %3 %4")
              .arg(program, modelPath, imagePath, outputDir));

    m_process->start(program, arguments);
    updateUiState(true);
}

void MainWindow::handleProcessOutput()
{
    const QString output = QString::fromLocal8Bit(m_process->readAllStandardOutput());
    appendLog("输出: " + output.trimmed());
}

void MainWindow::handleProcessFinished(int exitCode)
{
    updateUiState(false);
    if (exitCode == 0) {
        appendLog("处理成功完成！");
        QMessageBox::information(this, "完成", "图片处理成功！");
    } else {
        const QString error = QString::fromLocal8Bit(m_process->readAllStandardError());
        appendLog("错误: " + error);
        showError(QString("处理失败 (代码: %1)\n%2").arg(exitCode).arg(error));
    }
}

void MainWindow::updateUiState(bool processing)
{
    ui->processBtn->setEnabled(!processing);
    ui->browseModelBtn->setEnabled(!processing);
    ui->browseImageBtn->setEnabled(!processing);
    ui->browseOutputBtn->setEnabled(!processing);
}

void MainWindow::showError(const QString &message)
{
    QMessageBox::critical(this, "错误", message);
    appendLog("错误: " + message);
}

void MainWindow::appendLog(const QString &message)
{
    const QString timestamp = QDateTime::currentDateTime().toString("[hh:mm:ss]");
    ui->logText->appendPlainText(timestamp + " " + message);
}
