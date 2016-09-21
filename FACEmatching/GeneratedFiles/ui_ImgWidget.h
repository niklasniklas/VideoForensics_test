/********************************************************************************
** Form generated from reading UI file 'ImgWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGWIDGET_H
#define UI_IMGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "cvimagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    CVImageWidget *naImgWidget;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(805, 604);
        naImgWidget = new CVImageWidget(Form);
        naImgWidget->setObjectName(QStringLiteral("naImgWidget"));
        naImgWidget->setGeometry(QRect(0, 0, 800, 600));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGWIDGET_H
