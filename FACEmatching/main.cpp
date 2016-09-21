#include <facematching.h>
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FACEmatching w;
	w.setWindowIcon(QIcon("E:\\6.Testdata\\Bilder\\polisen2.png"));
	w.show();
	return a.exec();
}
