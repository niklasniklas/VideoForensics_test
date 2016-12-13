#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>


//QtWidgets / QMainWindow

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWidget w;
	w.show();
	return a.exec();

//	QCoreApplication a(argc, argv);


//	return a.exec();
}
