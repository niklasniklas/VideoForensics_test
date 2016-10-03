#include "vfgui_test.h"
#include <opencv2\opencv.hpp>
#include <qstandardpaths.h>

VFgui_test::VFgui_test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*
	// i Widget
	cv::Mat img = cv::imread("E:\\6.Testdata\\Bilder\\lena.png");
//	cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\boldt.jpg");
	ui.imgWidget->showImage(img);


	// I PixMap
	cv::Mat img2;
	img2 = img.clone();
	cvtColor(img2, img2, cv::COLOR_BGR2RGB);
	QImage qtimg = QImage((const unsigned char*)(img2.data), img2.cols, img2.rows, QImage::Format_RGB888);

	QSize siz = ui.label->size();
	ui.label->setPixmap(QPixmap::fromImage(qtimg));
	ui.label->resize(siz);
	//	ui.label->resize(ui.label->pixmap()->size());
*/
	QString str1 = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::DesktopLocation);
	QString str2 = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::DocumentsLocation);

	ui.label->setText(str2);


}

VFgui_test::~VFgui_test()
{

}
