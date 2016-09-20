#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "imagemodel.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	bool eventFilter(QObject *obj, QEvent *event);

	ImageModel *images;

public slots:


signals:
	void ImagesLoaded();
	void ImageEdited(int x, int y);

private slots:
	void on_loadDir_clicked();
	void on_testButton_clicked();
	void on_nextImageButton_clicked();
	void on_processImageButton_clicked();
	void updateView();

private:
	Ui::MainWindowClass ui;
	bool insideImageWidget(int mouseX, int mouseY);
	void printDotInImage(int mouseX, int mouseY);
};

#endif // MAINWINDOW_H
