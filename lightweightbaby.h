#ifndef LIGHTWEIGHTBABY_H
#define LIGHTWEIGHTBABY_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QProgressBar>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QCoreApplication>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class lightweightbaby; }
QT_END_NAMESPACE

class lightweightbaby : public QMainWindow
{
    Q_OBJECT

public:
    lightweightbaby(QWidget *parent = nullptr);
    ~lightweightbaby();

private slots:
    void on_selectButton_clicked();
    void on_startButton_clicked();
    void on_cancelButton_clicked();
    void on_exitButton_clicked();
    void on_finishButton_clicked();

private:
    Ui::lightweightbaby *ui;
    QString selectedDirectory;
    bool isCancelled;
    bool isProcessCompleted;

    int countFiles(const QString &dirPath);
    void findHeavyFiles(const QString &dirPath, int &processedFiles, int totalFiles);
    QVector<QPair<QString, qint64>> getLargestFiles(const QString &dirPath);
};

#endif
