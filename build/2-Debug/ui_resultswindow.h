/********************************************************************************
** Form generated from reading UI file 'resultswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTSWINDOW_H
#define UI_RESULTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultsWindow
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *ResultsWindow)
    {
        if (ResultsWindow->objectName().isEmpty())
            ResultsWindow->setObjectName("ResultsWindow");
        ResultsWindow->resize(400, 300);
        tableWidget = new QTableWidget(ResultsWindow);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 10, 380, 250));

        retranslateUi(ResultsWindow);

        QMetaObject::connectSlotsByName(ResultsWindow);
    } // setupUi

    void retranslateUi(QWidget *ResultsWindow)
    {
        ResultsWindow->setWindowTitle(QCoreApplication::translate("ResultsWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ResultsWindow", "\320\244\320\260\320\271\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ResultsWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 (\320\261\320\260\320\271\321\202\321\213)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultsWindow: public Ui_ResultsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTSWINDOW_H
