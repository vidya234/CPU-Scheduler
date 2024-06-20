/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QPushButton *addProcessButton;
    QPushButton *startButton;
    QTableWidget *processTable;
    QTextEdit *outputText;
    QChartView *comparisonChart;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        addProcessButton = new QPushButton(centralwidget);
        addProcessButton->setObjectName(QString::fromUtf8("addProcessButton"));
        addProcessButton->setGeometry(QRect(20, 20, 150, 40));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(180, 20, 150, 40));
        processTable = new QTableWidget(centralwidget);
        if (processTable->columnCount() < 8)
            processTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        processTable->setObjectName(QString::fromUtf8("processTable"));
        processTable->setGeometry(QRect(20, 80, 960, 250));
        outputText = new QTextEdit(centralwidget);
        outputText->setObjectName(QString::fromUtf8("outputText"));
        outputText->setGeometry(QRect(20, 340, 960, 200));
        comparisonChart = new QChartView(centralwidget);
        comparisonChart->setObjectName(QString::fromUtf8("comparisonChart"));
        comparisonChart->setGeometry(QRect(20, 560, 960, 200));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CPU Scheduler", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        addProcessButton->setText(QCoreApplication::translate("MainWindow", "Add Process", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start Scheduling", nullptr));
        QTableWidgetItem *___qtablewidgetitem = processTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = processTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Arrival", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = processTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Burst", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = processTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = processTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = processTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Finish", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = processTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Waiting", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = processTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Turnaround", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
