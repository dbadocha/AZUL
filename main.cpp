#include <QApplication>
#include <cstdlib>
#include <ctime>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
	srand(static_cast<int>(time(NULL)));
	//Game gra;
	//gra.CreateNewGame(2);
	//gra.FillWorkshops();
	//gra.PrintWorkshops();
	//std::cout << gra.getTilesPouch();
	//std::cout << gra.getTilesBin();

	QApplication app(argc, argv);

	MainWindow *window = new MainWindow();

	return app.exec();
}