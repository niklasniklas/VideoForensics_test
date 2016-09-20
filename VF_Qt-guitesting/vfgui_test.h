#ifndef VFGUI_TEST_H
#define VFGUI_TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_vfgui_test.h"

class VFgui_test : public QMainWindow
{
	Q_OBJECT

public:
	VFgui_test(QWidget *parent = 0);
	~VFgui_test();

private:
	Ui::VFgui_testClass ui;
};

#endif // VFGUI_TEST_H
