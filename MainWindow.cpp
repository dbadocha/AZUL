#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	_gameboard = NULL;
	this->setAttributes();
	this->addBackground();
	this->addMenu();
	this->show();
}

void MainWindow::setAttributes() {
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setFixedSize(QSize(900, 900));
}

MainMenu *MainWindow::addMenu() {
	_mainmenu = new MainMenu(this);
	int widgetWidth = (this->width() - _mainmenu->width()) / 2;
	int heightWidth = (this->height() - _mainmenu->height()) / 1.1;
	_mainmenu->move(widgetWidth, heightWidth);
	return _mainmenu;
}

void MainWindow::addBackground() {
	QPixmap background(":/images/Resources/Images/Background.jpg");
	background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, background);
	this->setPalette(palette);
}

void MainWindow::on_NewGame_clicked() {
	createNewGame();
}

void MainWindow::on_Settings_clicked() {
	QMessageBox::information(this, "Settings", "działa\t\t");
}

void MainWindow::on_ExitGame_clicked() {
	exit(0);
}

MainWindow::~MainWindow()
{
}

GameBoard *MainWindow::createNewGame() {
	_gameboard = new GameBoard(this);
	return _gameboard;
}