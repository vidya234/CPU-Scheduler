#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Process.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addProcess();
    void startScheduling();
    void displayResults(const std::vector<SchedulingResult>& results);
    void createComparisonChart(const std::vector<SchedulingResult>& results);

private:
    Ui::MainWindow *ui;
    std::vector<Process> processes;
};

#endif // MAINWINDOW_H
