#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtConcurrent>
#include <QProgressDialog>
#include <qtconcurrentmap.h>
#include <QMap>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_pbStart_clicked();

	void progressRangeChanged(int min, int max);

	void finished();

private:
	Ui::MainWindow *ui;

	QFutureWatcher<void> imageCreating;
};

#endif // MAINWINDOW_H
