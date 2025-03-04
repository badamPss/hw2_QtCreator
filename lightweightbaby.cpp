#include "lightweightbaby.h"
#include "ui_lightweightbaby.h"
#include <QApplication>
#include "resultswindow.h"

lightweightbaby::lightweightbaby(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::lightweightbaby),
    isCancelled(false),
    isProcessCompleted(false)
{
    ui->setupUi(this);
}

lightweightbaby::~lightweightbaby()
{
    delete ui;
}

void lightweightbaby::on_selectButton_clicked()
{
    ui->finishButton->setVisible(false);

    QString dir = QFileDialog::getExistingDirectory(this, "Выберите директорию", QDir::homePath());

    if (!dir.isEmpty()) {
        selectedDirectory = dir;
        ui->directoryLabel->setText("Выбранная директория: " + selectedDirectory);

        isCancelled = false;
        isProcessCompleted = false;

        ui->progressBar->setValue(0);
    }
}


void lightweightbaby::on_startButton_clicked()
{
    if (!selectedDirectory.isEmpty()) {
        isCancelled = false;
        isProcessCompleted = false;
        ui->resultDisplay->clear();
        ui->progressBar->setValue(0);
        ui->resultDisplay->show();

        int totalFiles = countFiles(selectedDirectory);
        int processedFiles = 0;

        findHeavyFiles(selectedDirectory, processedFiles, totalFiles);
    }
}

void lightweightbaby::on_cancelButton_clicked()
{
    isCancelled = true;
    ui->resultDisplay->append("Операция прервана пользователем.");
}

void lightweightbaby::on_exitButton_clicked()
{
    QApplication::quit();
}

void lightweightbaby::on_finishButton_clicked()
{
    ui->resultDisplay->append("Результаты готовы.");

    QVector<QPair<QString, qint64>> largestFiles = getLargestFiles(selectedDirectory);

    ResultsWindow *resultsWindow = new ResultsWindow(largestFiles);
    resultsWindow->show();
}


void lightweightbaby::findHeavyFiles(const QString &dirPath, int &processedFiles, int totalFiles)
{
    if (isCancelled || isProcessCompleted) {
        return;
    }

    QDir dir(dirPath);
    QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QFileInfo &fileInfo : files) {
        if (isCancelled || isProcessCompleted) {
            return;
        }

        if (fileInfo.isDir()) {
            findHeavyFiles(fileInfo.absoluteFilePath(), processedFiles, totalFiles);
            if (isCancelled || isProcessCompleted) {
                return;
            }
        } else {
            ui->resultDisplay->append(fileInfo.fileName() + " - " + QString::number(fileInfo.size()) + " байт");
            processedFiles++;

            int progress = (processedFiles * 100) / totalFiles;
            ui->progressBar->setValue(progress);

            QCoreApplication::processEvents();
        }
    }

    if (!isCancelled && !isProcessCompleted && processedFiles >= totalFiles) {
        ui->progressBar->setValue(100);
        ui->resultDisplay->append("Все файлы проверены.");
        ui->finishButton->setVisible(true);
        isProcessCompleted = true;
    }
}

int lightweightbaby::countFiles(const QString &dirPath)
{
    QDir dir(dirPath);
    int count = 0;

    QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    count += files.size();

    QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &dirInfo : dirs) {
        count += countFiles(dirInfo.absoluteFilePath());
    }

    return count;
}

QVector<QPair<QString, qint64>> lightweightbaby::getLargestFiles(const QString &dirPath)
{
    QVector<QPair<QString, qint64>> filesWithSizes;
    QDir dir(dirPath);

    QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : files) {
        filesWithSizes.append(qMakePair(fileInfo.absoluteFilePath(), fileInfo.size()));
    }

    QFileInfoList subDirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &subDir : subDirs) {
        filesWithSizes.append(getLargestFiles(subDir.absoluteFilePath()));
    }

    std::sort(filesWithSizes.begin(), filesWithSizes.end(), [](const QPair<QString, qint64> &a, const QPair<QString, qint64> &b) {
        return a.second > b.second;
    });

    if (filesWithSizes.size() > 5) {
        filesWithSizes = filesWithSizes.mid(0, 5);
    }

    return filesWithSizes;
}


