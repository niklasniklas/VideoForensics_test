#include "mainwindow.h"
#include <qfiledialog.h>
#include <qdiriterator.h>
#include <qmouseEvent>


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	images = new ImageModel(this);

	connect(this, SIGNAL(ImagesLoaded()), images, SLOT(initModel()));
	connect(this, SIGNAL(ImageEdited(int, int)), images, SLOT(editImage(int, int)));
}

MainWindow::~MainWindow()
{

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
	QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
	if (event->type() == QEvent::MouseMove)
	{
		statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
	}
	//if (event->type() == QEvent::MouseButtonPress)
	//{
	//	if (obj == (QObject*)&ui.ImageWidget)
	//		return false;

	//	if (insideImageWidget(mouseEvent->pos().x(), mouseEvent->pos().y()))
	//	{ 		
	//		//ui.clickPosLabel->setText("Inside Widget");
	//		printDotInImage(mouseEvent->pos().x(), mouseEvent->pos().y());
	//	} else {
	//		ui.clickPosLabel->setText("Outside Widget");
	//	}
	//}

	return false;
}

bool MainWindow::insideImageWidget(int mouseX, int mouseY)
{

	int X1 = ui.ImageWidget->pos().x();
	int X2 = ui.ImageWidget->pos().x() + ui.ImageWidget->size().width();
	int Y1 = ui.ImageWidget->pos().y();
	int Y2 = ui.ImageWidget->pos().y() + ui.ImageWidget->size().height();

	if ((mouseX >= ui.ImageWidget->pos().x()) &&
		(mouseX <= ui.ImageWidget->pos().x() + ui.ImageWidget->size().width()) &&
		(mouseY >= ui.ImageWidget->pos().y()) &&
		(mouseY <= ui.ImageWidget->pos().y() + ui.ImageWidget->size().height()))
	{
		QString str;
		str.sprintf("(%d,%d)", mouseX - ui.ImageWidget->pos().x(), mouseY - ui.ImageWidget->pos().y());
		ui.clickPosLabel->setText(str);
		return true;
	}

	return false;
}


void MainWindow::printDotInImage(int mouseX, int mouseY)
{
	int imgX = mouseX - ui.ImageWidget->pos().x();
	int imgY = mouseY - ui.ImageWidget->pos().y();

	emit ImageEdited(imgX,imgY);
}


void MainWindow::on_loadDir_clicked()
{
	QFileDialog dlg(this);
	dlg.setNameFilter(tr("Images (*.png *.gif *.jpg *.bmp)")); //Filters the file-types to select
	dlg.setViewMode(QFileDialog::Detail);
	QStringList fileNames;

	fileNames.empty();
	fileNames = QFileDialog::getOpenFileNames(this, tr("Select Image Files"), "E:\\6.Testdata\\Bilder\\faces\\omst_bilder", tr("Images (*.png *.gif *.jpg *.bmp);;All files (*.*)"));

	if (fileNames.isEmpty())
		return;

	for (int i = 0; i < fileNames.length(); i++)
	{
		std::string str = fileNames.at(i).toStdString();
		images->addImage(str);
	}

	emit ImagesLoaded();

}


void MainWindow::updateView()
{
	ui.ImageWidget->showImage(images->currentImage);

	QString str;
	str.sprintf("%d (%d)", images->currentImageIndex, images->count());
	ui.labelText->setText(str);
}


void MainWindow::on_nextImageButton_clicked()
{
	images->nextImage();
}


void MainWindow::on_processImageButton_clicked()
{
	images->processImage();
}


void MainWindow::on_testButton_clicked()
{

}
