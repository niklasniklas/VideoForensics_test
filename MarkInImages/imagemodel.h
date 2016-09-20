#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QObject>
#include <opencv2\opencv.hpp>
#include <QtWidgets/QMainWindow>

class ImageModel : public QObject
{
	Q_OBJECT

public:
	ImageModel(QMainWindow *parent);
	~ImageModel();

	void addImage(std::string str);
	void nextImage();
	int count(void);
	void processImage();

	cv::Mat currentImage;
	int currentImageIndex;

public slots:


signals:
	void updateImage(void);

private slots:
	   void initModel();
	   void editImage(int x, int y);

private:
	std::list<std::string> filelist;
	std::list<std::string>::iterator it;
	
};

#endif // IMAGEMODEL_H
