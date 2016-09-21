#ifndef FACEMATCHING_H
#define FACEMATCHING_H

#include <QtWidgets/QDialog>
#include "ui_facematching.h"
#include <naImgWidget.h>

class FACEmatching : public QDialog
{
	Q_OBJECT

public:
	FACEmatching(QWidget *parent = 0);
	~FACEmatching();

signals:
	void newFileList(QString str);

private slots:
	void on_loadButton_clicked();
	void on_nextButton_clicked();
	void on_prevButton_clicked();
	void on_findButton_clicked();
	void on_opendb_Button_clicked();
	void on_evaluateButton_clicked();
	void on_listDBWidget_itemSelectionChanged();
	void on_searchButton_clicked();
	void on_clearButton_clicked();

	void updateFilenameLabel(QString str);


private:
	Ui::FACEmatchingClass ui;
	QStringList fileNames;

	int index;
	naImgWidget widg;

};

#endif // FACEMATCHING_H
