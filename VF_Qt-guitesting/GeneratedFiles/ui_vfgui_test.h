/********************************************************************************
** Form generated from reading UI file 'vfgui_test.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VFgui_testClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VFgui_testClass)
    {
        if (VFgui_testClass->objectName().isEmpty())
            VFgui_testClass->setObjectName(QStringLiteral("VFgui_testClass"));
        VFgui_testClass->resize(600, 400);
        menuBar = new QMenuBar(VFgui_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        VFgui_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VFgui_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VFgui_testClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(VFgui_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        VFgui_testClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(VFgui_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VFgui_testClass->setStatusBar(statusBar);

        retranslateUi(VFgui_testClass);

        QMetaObject::connectSlotsByName(VFgui_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *VFgui_testClass)
    {
        VFgui_testClass->setWindowTitle(QApplication::translate("VFgui_testClass", "VFgui_test", 0));
    } // retranslateUi

};

namespace Ui {
    class VFgui_testClass: public Ui_VFgui_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VFGUI_TEST_H
