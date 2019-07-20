#pragma once

#include <QVector>

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "TilesManager.h"
#include "TilesWorkshop.h"
#include "TilesPile.h"
#include "PlayersBoard.h"
#include "TileSlot.h"

#define M_PI 3.14159265358979323846

class GameBoard : public QGraphicsView
{
	Q_OBJECT

private:
	QVector<TilesWorkshop*> gameWorkshops;
	QVector<TilesWorkshop*>::iterator gameWorkshopsIterator;

	QVector<PlayersBoard*> playerBoard;
	QVector<PlayersBoard*>::iterator playerBoardIterator;

	TilesPile * pile = NULL;
	QGraphicsScene * scene = NULL;
	int workshopsAmount = 0;
	const int resizeFactor = 5;
	void addLayout();
	void createNewGame(int);
	
public:
	GameBoard(QWidget *parent = 0);
	~GameBoard();
	void FillWorkshops();
};