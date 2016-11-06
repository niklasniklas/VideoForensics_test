/********************************************************************************
** Form generated from reading UI file 'qcustomplotexample.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCUSTOMPLOTEXAMPLE_H
#define UI_QCUSTOMPLOTEXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_QCustomPlotExampleClass
{
public:
    QWidget *centralWidget;
    QCustomPlot *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QCustomPlotExampleClass)
    {
        if (QCustomPlotExampleClass->objectName().isEmpty())
            QCustomPlotExampleClass->setObjectName(QStringLiteral("QCustomPlotExampleClass"));
        QCustomPlotExampleClass->resize(1037, 738);
        centralWidget = new QWidget(QCustomPlotExampleClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 971, 661));
        QCustomPlotExampleClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QCustomPlotExampleClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1037, 26));
        QCustomPlotExampleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QCustomPlotExampleClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QCustomPlotExampleClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QCustomPlotExampleClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QCustomPlotExampleClass->setStatusBar(statusBar);

        retranslateUi(QCustomPlotExampleClass);

        QMetaObject::connectSlotsByName(QCustomPlotExampleClass);
    } // setupUi

    void retranslateUi(QMainWindow *QCustomPlotExampleClass)
    {
        QCustomPlotExampleClass->setWindowTitle(QApplication::translate("QCustomPlotExampleClass", "QCustomPlotExample", 0));
    } // retranslateUi

};

namespace Ui {
    class QCustomPlotExampleClass: public Ui_QCustomPlotExampleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCUSTOMPLOTEXAMPLE_H
