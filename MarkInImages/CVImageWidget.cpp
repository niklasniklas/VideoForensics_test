#include "CVImageWidget.h"
#include <qmouseEvent>
#include <mainwindow.h>

//
//CVImageWidget::CVImageWidget(void)
//{
//}
//
//
//CVImageWidget::~CVImageWidget(void)
//{
//}

void CVImageWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->type() == QMouseEvent::MouseButtonPress)
	{
		int a = 0;
		int b = (_parent)->images->count();
	}
}
