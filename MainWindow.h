#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_MainWindow.h"
#include "mainmenu.h"
#include "GameBoard.h"
#include <QGridLayout>

class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	Ui::MainWindowClass ui;
	MainMenu *_mainmenu = nullptr;
	GameBoard *_gameboard = nullptr;
	MainMenu *addMenu();
	GameBoard *createNewGame();
	void addBackground();
	void setAttributes();
	

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();


public slots:
	void on_ExitGame_clicked();
	void on_Settings_clicked();
	void on_NewGame_clicked();
};