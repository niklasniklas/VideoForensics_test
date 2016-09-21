#pragma once

#include <QtWidgets/QDialog>
#include "ui_ImgWidget.h"

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class naImgWidget : public QWidget
{
	Q_OBJECT

public:
	naImgWidget(QWidget *parent = 0);
	~naImgWidget(void);

	void updateImg(cv::Mat *img, int no);

	cv::CascadeClassifier face_cascade;

	cv::Mat imgROIface;

	void detectAndDisplay(cv::Mat *frame, int no);

private:
	Ui::Form ui;

};

