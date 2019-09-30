#include "taskdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
#ifndef QT_NO_CONCURRENT

	QApplication a(argc, argv);
	TaskDialog w;
	w.show();
	return a.exec();

#else
	QApplication app(argc, argv);
	QString text("Qt Concurrent is not yet supported on this platform");

	QLabel *label = new QLabel(text);
	label->setWordWrap(true);

	label->show();
	qDebug() << text;

	app.exec();
#endif
}
