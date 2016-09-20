#include "imagemodel.h"

ImageModel::ImageModel(QMainWindow *parent)
	: QObject(parent)
{
	it = filelist.begin();
	currentImageIndex = 1;

	connect(this, SIGNAL(updateImage()), parent, SLOT(updateView()));
//	connect(this, SIGNAL(updateImage()), this, SLOT(processImage()));
}

ImageModel::~ImageModel()
{

}


void ImageModel::addImage(std::string str)
{
	filelist.push_back(str);
}

int ImageModel::count(void)
{
	return filelist.size();
}

void ImageModel::processImage()
{
	int a = 0;
}

void ImageModel::nextImage()
{
	it++;
	currentImageIndex++;
	if (it != filelist.end())
	{
		currentImage = cv::imread(*it);
	} else {
		it--;
		currentImageIndex--;
	}

	emit updateImage();
}

void ImageModel::initModel()
{		
	it = filelist.begin();
	currentImageIndex = 1;
	currentImage = cv::imread(*it);
	emit updateImage();
}

void ImageModel::editImage(int x, int y)
{
	if (currentImage.empty())
		return;
	cv::circle(currentImage, cv::Point(x, y), 4, cv::Scalar(0, 255, 0));
	emit updateImage();
}


