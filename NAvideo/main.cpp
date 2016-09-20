#include <navideo.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NAvideo w;
	w.show();
	return a.exec();
}
