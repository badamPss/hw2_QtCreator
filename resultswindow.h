#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsWindow(const QVector<QPair<QString, qint64>>& largestFiles, QWidget *parent = nullptr);
    ~ResultsWindow();

private slots:
    void on_exitButton_clicked();

private:
    Ui::ResultsWindow *ui;
    void populateTable(const QVector<QPair<QString, qint64>>& largestFiles);
};

#endif
