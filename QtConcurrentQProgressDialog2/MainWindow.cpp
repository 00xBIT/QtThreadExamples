#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace QtConcurrent;

void task(int &iteration)
{
	const int work = 9999999;
	volatile int v = 0;
	for (int j = 0; j < work; ++j)
		++v;
}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pbStart_clicked()
{
	QList<int> list;
	QVector<int> vector;
	QMap<int, int> map;		//not working with QtConcurrent::map()
	for (int i = 0; i < ui->sbTaskCount->value(); ++i)
	{
		list.append(i);
		vector.append(i);
		map.insert(i, i);
	}

	QProgressDialog dialog;
	dialog.setLabelText(QString("Progressing using %1 thread(s)...").arg(QThread::idealThreadCount()));

	QObject::connect(&watcher, &QFutureWatcher<void>::finished, &dialog, &QProgressDialog::reset);
	QObject::connect(&watcher, &QFutureWatcher<void>::finished, this, &MainWindow::finished);
	QObject::connect(&dialog, &QProgressDialog::canceled, &watcher, &QFutureWatcher<void>::cancel);
	QObject::connect(&watcher, &QFutureWatcher<void>::progressRangeChanged, &dialog, &QProgressDialog::setRange);
	QObject::connect(&watcher, &QFutureWatcher<void>::progressRangeChanged, this, &MainWindow::progressRangeChanged);
	QObject::connect(&watcher, &QFutureWatcher<void>::progressValueChanged, &dialog, &QProgressDialog::setValue);

//	watcher.setFuture(QtConcurrent::map(list, task));
	watcher.setFuture(QtConcurrent::map(vector, task));
//	watcher.setFuture(QtConcurrent::map(map, task));

	dialog.exec();

	watcher.waitForFinished();
}

void MainWindow::progressRangeChanged(int min, int max)
{
	qDebug() << "range changed" << min << max;
}

void MainWindow::finished()
{
	qDebug() << "finished";

	qDebug() << "Canceled?" << watcher.future().isCanceled();
}
