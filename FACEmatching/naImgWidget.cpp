#include "naImgWidget.h"
//#include <opencv2/objdetect/objdetect.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>


naImgWidget::naImgWidget(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);

//	std::string face_cascade_name = "E:\\7.DEP\\OpenCV_3.1.0\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt_tree.xml";
	std::string face_cascade_name = "E:\\7.DEP\\OpenCV_2.4.4\\data\\haarcascades\\haarcascade_frontalface_alt_tree.xml";
	bool ok = face_cascade.load(face_cascade_name);

	//cv::Mat image = cv::imread("D:\\6.Testdata\\Bilder\\faces\\omst_bilder\\#person039_214_bakom_bast-bast.bmp", true);
	//ui.naImgWidget->showImage(image);


}


naImgWidget::~naImgWidget(void)
{

}


void naImgWidget::updateImg(cv::Mat *img, int no)
{
	if(no>=608)
		detectAndDisplay(img,no);
	ui.naImgWidget->showImage(*img);
}

// Function Headers
void naImgWidget::detectAndDisplay(cv::Mat *frame, int no)
{
	// se även: http://stackoverflow.com/questions/20757147/opencv-and-cdetect-face-in-image

	// Global variables
	// Copy this file from opencv/data/haarscascades to target folder

	// moved to constructor
	//std::string face_cascade_name = "D:\\7.DEP\\OpenCV_2.4.4\\data\\haarcascades\\haarcascade_frontalface_alt_tree.xml";
	//cv::CascadeClassifier face_cascade;
	//face_cascade.load(face_cascade_name);

	std::vector<cv::Rect> faces;
	cv::Mat frame_gray;

	cvtColor(*frame, frame_gray, cv::COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	// Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.10, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(40, 40));

	for( size_t i = 0; i < faces.size(); i++ )
	{
		cv::Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
		if(no < 619) {
			rectangle(*frame, cv::Point(faces[i].x,faces[i].y),cv::Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height),cv::Scalar(0,0,255),1,4,0);
			cv::Rect rec(faces[i]);
			imgROIface = (*frame)(rec).clone();
			rectangle(*frame, rec, cv::Scalar(0, 255, 0), 3, 4, 0);

		} else {
			cv::Rect rec(faces[i]);
			//rectangle(*frame, cv::Point(faces[i].x,faces[i].y),cv::Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height),cv::Scalar(0,255,0),1,4,0);
			imgROIface = (*frame)(rec).clone();
			rectangle(*frame, rec, cv::Scalar(0,255,0),3,4,0);
		/*	cv::Mat originalImage;
			cv::Rect faceRect;
			cv::Mat croppedFaceImage;

			croppedFaceImage = originalImage(faceRect).clone();
			Or alternatively:

			originalImage(faceRect).copyTo(croppedImage);
		*/
		}

		//ellipse( frame, center, cv::Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0 );
	}

//	ellipse(frame_gray,cv::Point(40,40),cv::Size(20,20),0,0,360,cv::Scalar(255,0,255),4,8,0);
}