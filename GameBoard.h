#pragma once

#include <QWidget>
#include <QVector>
#include <QGridLayout>
#include <QPainter>

#include "ui_GameBoard.h"
#include "TilesManager.h"
#include "TilesWorkshop.h"

class GameBoard : public QWidget
{
	Q_OBJECT

private:
	Ui::GameBoard ui;
	QWidget *m_parent = nullptr;
	QGridLayout *layout = nullptr;
	//Tiles *GameTiles = nullptr;
	QVector<TilesWorkshop*> GameWorkshops;
	QVector<TilesWorkshop*>::iterator GameWorkshopsIterator;
	int WorkshopsAmount = 0;
	void addLayout();
	
public:
	explicit GameBoard(QWidget *parent = nullptr);
	~GameBoard();
	void CreateNewGame(int);
	void FillWorkshops();
	TilesWorkshop *CreateWorkshop();
	void GameBoard::paintEvent(QPaintEvent *);
};