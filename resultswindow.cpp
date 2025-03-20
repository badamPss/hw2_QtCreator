#include "resultswindow.h"
#include "ui_resultswindow.h"

ResultsWindow::ResultsWindow(const QVector<QPair<QString, qint64>>& largestFiles, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);
    populateTable(largestFiles);
}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::populateTable(const QVector<QPair<QString, qint64>>& largestFiles)
{
    ui->tableWidget->setRowCount(largestFiles.size());

    for (int i = 0; i < largestFiles.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(largestFiles[i].first));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(largestFiles[i].second)));
    }
}

void ResultsWindow::on_exitButton_clicked()
{
    this->close();
}
