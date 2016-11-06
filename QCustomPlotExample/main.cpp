#include "qcustomplotexample.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QCustomPlotExample w;
	w.show();
	return a.exec();
}
