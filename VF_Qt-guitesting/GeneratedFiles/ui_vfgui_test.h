/********************************************************************************
** Form generated from reading UI file 'vfgui_test.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VFGUI_TEST_H
#define UI_VFGUI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "cvimagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_VFgui_testClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    CVImageWidget *imgWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VFgui_testClass)
    {
        if (VFgui_testClass->objectName().isEmpty())
            VFgui_testClass->setObjectName(QStringLiteral("VFgui_testClass"));
        VFgui_testClass->resize(1055, 806);
        centralWidget = new QWidget(VFgui_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 481, 381));
        imgWidget = new CVImageWidget(centralWidget);
        imgWidget->setObjectName(QStringLiteral("imgWidget"));
        imgWidget->setGeometry(QRect(589, 120, 421, 331));
        VFgui_testClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VFgui_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1055, 26));
        VFgui_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VFgui_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VFgui_testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VFgui_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VFgui_testClass->setStatusBar(statusBar);

        retranslateUi(VFgui_testClass);

        QMetaObject::connectSlotsByName(VFgui_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *VFgui_testClass)
    {
        VFgui_testClass->setWindowTitle(QApplication::translate("VFgui_testClass", "VFgui_test", 0));
        label->setText(QApplication::translate("VFgui_testClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class VFgui_testClass: public Ui_VFgui_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VFGUI_TEST_H
