/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "cvimagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    CVImageWidget *ImageWidget;
    QPushButton *loadDir;
    QLabel *labelText;
    QPushButton *testButton;
    QPushButton *nextImageButton;
    QPushButton *processImageButton;
    QLabel *clickPosLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1068, 883);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ImageWidget = new CVImageWidget(centralWidget);
        ImageWidget->setObjectName(QStringLiteral("ImageWidget"));
        ImageWidget->setGeometry(QRect(20, 130, 501, 681));
        ImageWidget->setMouseTracking(true);
        ImageWidget->setAutoFillBackground(true);
        loadDir = new QPushButton(centralWidget);
        loadDir->setObjectName(QStringLiteral("loadDir"));
        loadDir->setGeometry(QRect(860, 110, 131, 51));
        labelText = new QLabel(centralWidget);
        labelText->setObjectName(QStringLiteral("labelText"));
        labelText->setGeometry(QRect(540, 640, 131, 41));
        testButton = new QPushButton(centralWidget);
        testButton->setObjectName(QStringLiteral("testButton"));
        testButton->setGeometry(QRect(770, 490, 141, 61));
        nextImageButton = new QPushButton(centralWidget);
        nextImageButton->setObjectName(QStringLiteral("nextImageButton"));
        nextImageButton->setGeometry(QRect(700, 100, 91, 31));
        processImageButton = new QPushButton(centralWidget);
        processImageButton->setObjectName(QStringLiteral("processImageButton"));
        processImageButton->setGeometry(QRect(890, 250, 91, 31));
        clickPosLabel = new QLabel(centralWidget);
        clickPosLabel->setObjectName(QStringLiteral("clickPosLabel"));
        clickPosLabel->setGeometry(QRect(670, 650, 47, 13));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1068, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        loadDir->setText(QApplication::translate("MainWindowClass", "Load Images", 0));
        labelText->setText(QApplication::translate("MainWindowClass", "TextLabel", 0));
        testButton->setText(QApplication::translate("MainWindowClass", "TEST button", 0));
        nextImageButton->setText(QApplication::translate("MainWindowClass", "Next Image", 0));
        processImageButton->setText(QApplication::translate("MainWindowClass", "Process Image", 0));
        clickPosLabel->setText(QApplication::translate("MainWindowClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
