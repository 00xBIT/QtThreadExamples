//https://stackoverflow.com/questions/28898509/qfuturewatcher-firing-progress-signals-only-once-with-zeros

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
