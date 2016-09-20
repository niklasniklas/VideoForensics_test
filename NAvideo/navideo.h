#ifndef NAVIDEO_H
#define NAVIDEO_H

#include <QtWidgets/QMainWindow>
#include <ui_navideo.h>

class NAvideo : public QMainWindow
{
	Q_OBJECT

public:
	NAvideo(QWidget *parent = 0);
	~NAvideo();

private:
	Ui::NAvideoClass ui;
};

#endif // NAVIDEO_H
