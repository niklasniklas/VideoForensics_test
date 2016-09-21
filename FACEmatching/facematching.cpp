#include "facematching.h"
#include <QFileDialog>
#include <QListWidget>
#include <QDirIterator>
#include <QStringList>

#include <windows.h>


FACEmatching::FACEmatching(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QDirIterator it("E:/6.Testdata/Bilder", QDir::Files);
	while (it.hasNext()) {
		QString str1 = it.fileName();
		QString str2 = it.filePath();

		it.next();

	}
	
	widg.show();
	ui.labelMatch->setText("");

	ui.listDBWidget->setFlow(QListView::LeftToRight);

	cv::Mat image = cv::imread("E:\\6.Testdata\\Bilder\\polisen.png");
	ui.widgetPolisen->showImage(image);
	
	QObject::connect(this, SIGNAL(newFileList(QString)), this, SLOT(updateFilenameLabel(QString)));
}

FACEmatching::~FACEmatching()
{
	widg.close();
}

void FACEmatching::on_findButton_clicked()
{

	cv::VideoCapture *movie;
	cv::Mat3b frame;
	movie = new cv::VideoCapture("E:\\6.Testdata\\SL\\FHP-P112.avi");

	int frameStart = 613; //608
	movie->set(CV_CAP_PROP_POS_FRAMES,double(frameStart));

	for(int i=frameStart;i<618; i++)
	{
		*movie >> frame;
		widg.updateImg(&frame,i);
		if(movie->get(CV_CAP_PROP_POS_FRAMES) > 620)
			break;
	}

	cv::Mat img;
	cv::resize(widg.imgROIface, img, cv::Size(), 4, 4, cv::INTER_CUBIC);

	ui.imgWidget2->showImage(img);


	on_searchButton_clicked();



	//if(fileNames.isEmpty())
	//	return;

	//std::string str = fileNames.at(0).toStdString();
	//cv::Mat image = cv::imread(str);




//	ui.imgWidget->showImage(image);

	//for(int i; i<fileNames.size(); i++) 
	//{
	//	std::string str = fileNames.at(i).toStdString();
	//	cv::Mat image = cv::imread(str);
	//	ui.imgWidget->showImage(image);
	//}

}

void FACEmatching::on_loadButton_clicked()
{
	QFileDialog dlg(this);
	dlg.setNameFilter(tr("Images (*.png *.gif *.jpg *.bmp)")); //Filters the file-types to select
	dlg.setViewMode(QFileDialog::Detail);
//	QString fileName = QFileDialog::getOpenFileName(this, tr("Select Left Image File"), "D:/", tr("Images (*.png *.gif *.jpg *.bmp)"));
//	QString fileName = dlg.getOpenFileName(this, tr("Select Left Image File"), "D:/", tr("Images (*.png *.gif *.jpg *.bmp)"));
	fileNames.empty();
	fileNames = QFileDialog::getOpenFileNames(this, tr("Select Left Image File"), "E:\\6.Testdata\\Bilder", tr("Images (*.png *.gif *.jpg *.bmp);;All files (*.*)"));

	if(fileNames.isEmpty())
		return;

	QString str;
	str = fileNames.first();

//	ui.fileName->setText(str);

	emit newFileList(str);
	index = 0;
//	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	ui.labelMatch->setText("");

}

void FACEmatching::updateFilenameLabel(QString str)
{
	ui.fileName->setText(str);
	//std::string str1 = str.toStdString();
	//cv::Mat image = cv::imread(str1);
	//ui.imgWidget->showImage(image);

}

void FACEmatching::on_nextButton_clicked()
{
	QString str;
	index++;

	if(index < fileNames.size())
	{
		str = fileNames.at(index);
		updateFilenameLabel(str);
		std::string str1 = fileNames.at(index).toStdString();
		cv::Mat image = cv::imread(str1);
		cv::Mat image2;

//		cv::Size size(287,387);//the dst image size,e.g.100x100
		cv::Size size(350,470);//the dst image size,e.g.100x100
		cv::resize(image,image2,size);//resize image

		ui.imgWidget->showImage(image2);
	} else {
		index = fileNames.size();
	}

	ui.labelResultat->setText("");
	ui.labelMatch->setText("");


	// loop runt QList
	//for (int i = 0; i < list.size(); ++i) {
	//	if (list.at(i) == "Jane")
	//		cout << "Found Jane at position " << i << endl;
	//}
}

void FACEmatching::on_prevButton_clicked()
{
	QString str;
	index--;

	if(index >= 0)
	{
		str = fileNames.at(index);
		updateFilenameLabel(str);
		std::string str1 = fileNames.at(index).toStdString();
		cv::Mat image = cv::imread(str1);
		cv::Mat image2;

//		cv::Size size(287,387);//the dst image size,e.g.100x100
		cv::Size size(350,470);//the dst image size,e.g.100x100
		cv::resize(image,image2,size);//resize image

		ui.imgWidget->showImage(image2);
	} else {
		index = 0;
	}

	ui.labelResultat->setText("");
	ui.labelMatch->setText("");


}



void FACEmatching::on_opendb_Button_clicked()
{
	ui.listDBWidget->setIconSize(QSize(100,100));

	if(fileNames.isEmpty())
		return;

	for(int i=0; i<fileNames.size(); i++) 
	{
		QString str = fileNames.at(i);
		QString str2, str3;
		str3 = "ID nr. " + str2.setNum(i);
		QListWidgetItem *item1 = new QListWidgetItem(QIcon(str), str3, ui.listDBWidget);
		ui.listDBWidget->insertItem(0, item1);
	}

	ui.listDBWidget->show();

	ui.labelMatch->setText("");

}
/* old code: seperate widgetwindow
void FACEmatching::on_opendb_Button_clicked()
{
	QListWidget* list = new QListWidget();
	list->setIconSize(QSize(100,100));

	if(fileNames.isEmpty())
		return;

	for(int i=0; i<fileNames.size(); i++) 
	{
		QString str = fileNames.at(i);
		QString str2, str3;
		str3 = "ID nr. " + str2.setNum(i);
		QListWidgetItem *item1 = new QListWidgetItem(QIcon(str), str3, list);
		list->insertItem(0, item1);
	}

	list->show();
	

}
*/

void FACEmatching::on_evaluateButton_clicked()
{

	QString str;
	str = fileNames.at(index);
	updateFilenameLabel(str);
	std::string str1 = fileNames.at(index).toStdString();
	cv::Mat image = cv::imread(str1);
	cv::Mat image2;

	cv::Size size(350,470);//the dst image size,e.g.100x100
	cv::resize(image,image2,size);//resize image
	widg.detectAndDisplay(&image2,620);
	ui.imgWidget->showImage(image2);

	Sleep(2000);
	if(index == 2)
		ui.labelResultat->setText("+3");
	else if(index == 4)
		ui.labelResultat->setText("-2");
	else 
		ui.labelResultat->setText("-1");

	ui.labelMatch->setText("");


}

void FACEmatching::on_listDBWidget_itemSelectionChanged()
{
	int ii = ui.listDBWidget->currentRow();

	QString str;
	str = fileNames.at(ii);
	updateFilenameLabel(str);
	std::string str1 = fileNames.at(ii).toStdString();
	cv::Mat image = cv::imread(str1);
	cv::Mat image2;

	cv::Size size(350,470);//the dst image size,e.g.100x100
	cv::resize(image,image2,size);//resize image

	ui.imgWidget->showImage(image2);
	ui.labelResultat->setText("");

	ui.labelMatch->setText("");
	
	index = ii;


}

void FACEmatching::on_searchButton_clicked()
{

	if(fileNames.isEmpty())
		return;

	QString str;

	cv::Mat image, image2;

	for(int i=0; i<fileNames.size(); i++) 
	{
		str = fileNames.at(i);
		updateFilenameLabel(str);
		std::string str1 = fileNames.at(i).toStdString();
		image = cv::imread(str1);

		cv::Size size(350,470);//the dst image size,e.g.100x100
		cv::resize(image,image2,size);//resize image
//		widg.detectAndDisplay(&image2,620);
		ui.imgWidget->showImage(image2);
		Sleep(100);

	}

	str = fileNames.at(2);
	updateFilenameLabel(str);
	std::string str1 = fileNames.at(2).toStdString();
	image = cv::imread(str1);

	cv::Size size(350,470);//the dst image size,e.g.100x100
	cv::resize(image,image2,size);//resize image
	ui.imgWidget->showImage(image2);

	Sleep(400);
	widg.detectAndDisplay(&image2,620);

	ui.imgWidget->showImage(image2);
	Sleep(500);

	ui.labelMatch->setText("MATCH");

	

	index = 2;

}

void FACEmatching::on_clearButton_clicked()
{
	QString str;
	cv::Mat image, image2;

	str = fileNames.at(index);
	updateFilenameLabel(str);
	std::string str1 = fileNames.at(index).toStdString();
	image = cv::imread(str1);

	cv::Size size(350,470);//the dst image size,e.g.100x100
	cv::resize(image,image2,size);//resize image
	ui.imgWidget->showImage(image2);

	ui.labelMatch->setText("");
}