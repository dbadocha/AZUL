#include <QApplication>
#include <cstdlib>
#include <ctime>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
	srand(static_cast<int>(time(NULL)));

	QApplication app(argc, argv);

	MainWindow *window = new MainWindow();

	return app.exec();
}