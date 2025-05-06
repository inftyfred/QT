// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseModelBtn_clicked();
    void on_browseImageBtn_clicked();
    void on_browseOutputBtn_clicked();
    void on_processBtn_clicked();
    void handleProcessOutput();
    void handleProcessFinished(int exitCode);

private:
    Ui::MainWindow *ui;
    QProcess *m_process;

    void updateUiState(bool processing);
    void showError(const QString &message);
    void appendLog(const QString &message);
};

#endif // MAINWINDOW_H
