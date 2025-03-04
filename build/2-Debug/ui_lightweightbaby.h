/********************************************************************************
** Form generated from reading UI file 'lightweightbaby.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTWEIGHTBABY_H
#define UI_LIGHTWEIGHTBABY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lightweightbaby
{
public:
    QWidget *centralwidget;
    QLabel *welcomeLabel;
    QLabel *directoryLabel;
    QPushButton *selectButton;
    QPushButton *startButton;
    QPushButton *cancelButton;
    QPushButton *exitButton;
    QProgressBar *progressBar;
    QTextEdit *resultDisplay;
    QPushButton *finishButton;

    void setupUi(QMainWindow *lightweightbaby)
    {
        if (lightweightbaby->objectName().isEmpty())
            lightweightbaby->setObjectName("lightweightbaby");
        lightweightbaby->resize(503, 400);
        centralwidget = new QWidget(lightweightbaby);
        centralwidget->setObjectName("centralwidget");
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(10, 10, 481, 20));
        directoryLabel = new QLabel(centralwidget);
        directoryLabel->setObjectName("directoryLabel");
        directoryLabel->setGeometry(QRect(10, 40, 481, 20));
        selectButton = new QPushButton(centralwidget);
        selectButton->setObjectName("selectButton");
        selectButton->setGeometry(QRect(10, 70, 100, 30));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(120, 70, 100, 30));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(230, 70, 101, 31));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(370, 290, 111, 91));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(10, 110, 481, 20));
        progressBar->setValue(0);
        resultDisplay = new QTextEdit(centralwidget);
        resultDisplay->setObjectName("resultDisplay");
        resultDisplay->setGeometry(QRect(10, 150, 341, 231));
        resultDisplay->setReadOnly(true);
        finishButton = new QPushButton(centralwidget);
        finishButton->setObjectName("finishButton");
        finishButton->setGeometry(QRect(370, 150, 111, 91));
        finishButton->setVisible(false);
        lightweightbaby->setCentralWidget(centralwidget);

        retranslateUi(lightweightbaby);

        QMetaObject::connectSlotsByName(lightweightbaby);
    } // setupUi

    void retranslateUi(QMainWindow *lightweightbaby)
    {
        lightweightbaby->setWindowTitle(QCoreApplication::translate("lightweightbaby", "lightweightbaby", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("lightweightbaby", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203 LIGHTWEIGHTBABY!", nullptr));
        directoryLabel->setText(QCoreApplication::translate("lightweightbaby", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\320\260\321\217 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217: ", nullptr));
        selectButton->setText(QCoreApplication::translate("lightweightbaby", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        startButton->setText(QCoreApplication::translate("lightweightbaby", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        cancelButton->setText(QCoreApplication::translate("lightweightbaby", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        exitButton->setText(QCoreApplication::translate("lightweightbaby", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        finishButton->setText(QCoreApplication::translate("lightweightbaby", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lightweightbaby: public Ui_lightweightbaby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTWEIGHTBABY_H
