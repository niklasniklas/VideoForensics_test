#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <opencv2\opencv.hpp>

int main(int argc, char *argv[])
{
	cv::Mat;

	QApplication a(argc, argv);
	MainWindow w;
	a.installEventFilter(&w);
	w.show();
	return a.exec();
}
