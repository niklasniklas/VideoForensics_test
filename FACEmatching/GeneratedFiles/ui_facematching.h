/********************************************************************************
** Form generated from reading UI file 'facematching.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEMATCHING_H
#define UI_FACEMATCHING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include "cvimagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_FACEmatchingClass
{
public:
    CVImageWidget *imgWidget;
    QLabel *labelMatch;
    QPushButton *findButton;
    CVImageWidget *imgWidget2;
    QLabel *fileName;
    QPushButton *nextButton;
    QPushButton *loadButton;
    QPushButton *opendb_Button;
    QLabel *labelResultat;
    QPushButton *evaluateButton;
    QPushButton *prevButton;
    QListWidget *listDBWidget;
    QPushButton *searchButton;
    QPushButton *clearButton;
    CVImageWidget *widgetPolisen;

    void setupUi(QDialog *FACEmatchingClass)
    {
        if (FACEmatchingClass->objectName().isEmpty())
            FACEmatchingClass->setObjectName(QStringLiteral("FACEmatchingClass"));
        FACEmatchingClass->resize(946, 992);
        imgWidget = new CVImageWidget(FACEmatchingClass);
        imgWidget->setObjectName(QStringLiteral("imgWidget"));
        imgWidget->setGeometry(QRect(10, 70, 351, 491));
        labelMatch = new QLabel(imgWidget);
        labelMatch->setObjectName(QStringLiteral("labelMatch"));
        labelMatch->setGeometry(QRect(10, 190, 331, 111));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(56);
        font.setBold(true);
        font.setWeight(75);
        labelMatch->setFont(font);
        findButton = new QPushButton(FACEmatchingClass);
        findButton->setObjectName(QStringLiteral("findButton"));
        findButton->setGeometry(QRect(450, 10, 261, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Engravers MT"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        findButton->setFont(font1);
        imgWidget2 = new CVImageWidget(FACEmatchingClass);
        imgWidget2->setObjectName(QStringLiteral("imgWidget2"));
        imgWidget2->setGeometry(QRect(380, 140, 241, 201));
        fileName = new QLabel(FACEmatchingClass);
        fileName->setObjectName(QStringLiteral("fileName"));
        fileName->setGeometry(QRect(30, 620, 341, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Narrow"));
        fileName->setFont(font2);
        nextButton = new QPushButton(FACEmatchingClass);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(240, 580, 75, 23));
        loadButton = new QPushButton(FACEmatchingClass);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(370, 80, 75, 23));
        opendb_Button = new QPushButton(FACEmatchingClass);
        opendb_Button->setObjectName(QStringLiteral("opendb_Button"));
        opendb_Button->setGeometry(QRect(450, 70, 261, 51));
        opendb_Button->setFont(font1);
        labelResultat = new QLabel(FACEmatchingClass);
        labelResultat->setObjectName(QStringLiteral("labelResultat"));
        labelResultat->setGeometry(QRect(390, 420, 231, 221));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Black"));
        font3.setPointSize(72);
        font3.setBold(true);
        font3.setWeight(75);
        labelResultat->setFont(font3);
        labelResultat->setFrameShape(QFrame::StyledPanel);
        labelResultat->setAlignment(Qt::AlignCenter);
        evaluateButton = new QPushButton(FACEmatchingClass);
        evaluateButton->setObjectName(QStringLiteral("evaluateButton"));
        evaluateButton->setGeometry(QRect(380, 360, 291, 51));
        evaluateButton->setFont(font1);
        prevButton = new QPushButton(FACEmatchingClass);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        prevButton->setGeometry(QRect(20, 580, 75, 23));
        listDBWidget = new QListWidget(FACEmatchingClass);
        listDBWidget->setObjectName(QStringLiteral("listDBWidget"));
        listDBWidget->setGeometry(QRect(10, 790, 931, 191));
        searchButton = new QPushButton(FACEmatchingClass);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(20, 660, 211, 41));
        searchButton->setFont(font1);
        clearButton = new QPushButton(FACEmatchingClass);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(20, 720, 75, 23));
        widgetPolisen = new CVImageWidget(FACEmatchingClass);
        widgetPolisen->setObjectName(QStringLiteral("widgetPolisen"));
        widgetPolisen->setGeometry(QRect(10, 10, 251, 51));

        retranslateUi(FACEmatchingClass);

        QMetaObject::connectSlotsByName(FACEmatchingClass);
    } // setupUi

    void retranslateUi(QDialog *FACEmatchingClass)
    {
        FACEmatchingClass->setWindowTitle(QApplication::translate("FACEmatchingClass", "FACEmatching", 0));
        labelMatch->setText(QString());
        findButton->setText(QApplication::translate("FACEmatchingClass", "Show Video", 0));
        fileName->setText(QApplication::translate("FACEmatchingClass", "TextLabel", 0));
        nextButton->setText(QApplication::translate("FACEmatchingClass", "Next", 0));
        loadButton->setText(QApplication::translate("FACEmatchingClass", "load DB", 0));
        opendb_Button->setText(QApplication::translate("FACEmatchingClass", "Open DataBase", 0));
        labelResultat->setText(QString());
        evaluateButton->setText(QApplication::translate("FACEmatchingClass", "Evaluate", 0));
        prevButton->setText(QApplication::translate("FACEmatchingClass", "Prev", 0));
        searchButton->setText(QApplication::translate("FACEmatchingClass", "Search", 0));
        clearButton->setText(QApplication::translate("FACEmatchingClass", "clear", 0));
    } // retranslateUi

};

namespace Ui {
    class FACEmatchingClass: public Ui_FACEmatchingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEMATCHING_H
