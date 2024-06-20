// MainWindow.cpp

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Process.h"
#include "SchedulingSelector.cpp"

#include <QInputDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>

using namespace Qt;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addProcessButton, &QPushButton::clicked, this, &MainWindow::addProcess);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startScheduling);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addProcess() {
    bool ok;
    int pid = QInputDialog::getInt(this, "Process ID", "Enter Process ID:", 0, 0, 100, 1, &ok);
    if (!ok) return;

    int arrival = QInputDialog::getInt(this, "Arrival Time", "Enter Arrival Time:", 0, 0, 100, 1, &ok);
    if (!ok) return;

    int burst = QInputDialog::getInt(this, "Burst Time", "Enter Burst Time:", 0, 1, 100, 1, &ok);
    if (!ok) return;

    int priority = QInputDialog::getInt(this, "Priority", "Enter Priority (optional, default 0):", 0, 0, 10, 1, &ok);
    if (!ok) return;

    Process process(pid, arrival, burst, priority);
    processes.push_back(process);

    // Add to table
    int row = ui->processTable->rowCount();
    ui->processTable->insertRow(row);
    ui->processTable->setItem(row, 0, new QTableWidgetItem(QString::number(pid)));
    ui->processTable->setItem(row, 1, new QTableWidgetItem(QString::number(arrival)));
    ui->processTable->setItem(row, 2, new QTableWidgetItem(QString::number(burst)));
    ui->processTable->setItem(row, 3, new QTableWidgetItem(QString::number(priority)));
}

void MainWindow::startScheduling() {
    if (processes.empty()) {
        QMessageBox::warning(this, "No Processes", "Please add at least one process.");
        return;
    }

    auto results = compareAlgorithms(processes);
    displayResults(results);
    createComparisonChart(results);
}

void MainWindow::displayResults(const std::vector<SchedulingResult>& results) {
    QString output;
    for (const auto& result : results) {
        output += QString("Algorithm: %1\n").arg(QString::fromStdString(result.algorithm));
        for (const auto& process : result.processes) {
            output += QString("PID: %1, Start: %2, Finish: %3, Waiting: %4, Turnaround: %5\n")
                          .arg(process.pid)
                          .arg(process.start)
                          .arg(process.finish)
                          .arg(process.waiting)
                          .arg(process.turnaround);
        }
        output += QString("Avg. Waiting Time: %1, Avg. Turnaround Time: %2\n\n")
                      .arg(result.avgWaitingTime)
                      .arg(result.avgTurnaroundTime);
    }

    ui->outputText->setPlainText(output);
}

void MainWindow::createComparisonChart(const std::vector<SchedulingResult>& results) {
    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();

    QStringList categories;
    for (const auto& result : results) {
        QBarSet *set = new QBarSet(QString::fromStdString(result.algorithm));
        *set << result.avgWaitingTime << result.avgTurnaroundTime;
        series->append(set);
        categories << "Avg. Waiting Time" << "Avg. Turnaround Time";
    }

    chart->addSeries(series);
    chart->setTitle("Algorithm Performance Comparison");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();

    // Find the maximum value among all the bar sets
    qreal maxValue = 0;
    for (auto set : series->barSets()) {
        for (int i = 0; i < set->count(); ++i) {
            if ((*set)[i] > maxValue) {
                maxValue = (*set)[i];
            }
        }
    }

    axisY->setRange(0, maxValue);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ui->comparisonChart->setChart(chart);
}


