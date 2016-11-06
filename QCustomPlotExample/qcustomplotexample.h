#ifndef QCUSTOMPLOTEXAMPLE_H
#define QCUSTOMPLOTEXAMPLE_H

#include <QtWidgets/QMainWindow>
#include "ui_qcustomplotexample.h"

class QCustomPlotExample : public QMainWindow
{
	Q_OBJECT

public:
	QCustomPlotExample(QWidget *parent = 0);
	~QCustomPlotExample();

private:
	Ui::QCustomPlotExampleClass ui;
};

#endif // QCUSTOMPLOTEXAMPLE_H
