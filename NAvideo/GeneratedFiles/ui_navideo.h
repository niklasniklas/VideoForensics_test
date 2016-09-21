/********************************************************************************
** Form generated from reading UI file 'navideo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIDEO_H
#define UI_NAVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_NAvideoClass
{
public:
    QWidget *centralWidget;
    QVideoWidget *moviewidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *NAvideoClass)
    {
        if (NAvideoClass->objectName().isEmpty())
            NAvideoClass->setObjectName(QStringLiteral("NAvideoClass"));
        NAvideoClass->resize(997, 755);
        centralWidget = new QWidget(NAvideoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        moviewidget = new QVideoWidget(centralWidget);
        moviewidget->setObjectName(QStringLiteral("moviewidget"));
        moviewidget->setGeometry(QRect(270, 130, 511, 381));
        NAvideoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NAvideoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 997, 21));
        NAvideoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NAvideoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NAvideoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NAvideoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NAvideoClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(NAvideoClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        NAvideoClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        retranslateUi(NAvideoClass);

        QMetaObject::connectSlotsByName(NAvideoClass);
    } // setupUi

    void retranslateUi(QMainWindow *NAvideoClass)
    {
        NAvideoClass->setWindowTitle(QApplication::translate("NAvideoClass", "NAvideo", 0));
    } // retranslateUi

};

namespace Ui {
    class NAvideoClass: public Ui_NAvideoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIDEO_H
