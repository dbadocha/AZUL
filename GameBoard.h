#pragma once

#include <QWidget>
#include <QVector>

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "ui_GameBoard.h"
#include "TilesManager.h"
#include "TilesWorkshop.h"

class GameBoard : public QGraphicsView
{
	Q_OBJECT

private:
	QVector<TilesWorkshop*> GameWorkshops;
	QVector<TilesWorkshop*>::iterator GameWorkshopsIterator;
	QGraphicsScene * scene = NULL;
	int WorkshopsAmount = 0;
	void addLayout();
	
public:
	GameBoard(QWidget *parent = 0);
	~GameBoard();

	void CreateNewGame(int);
	void FillWorkshops();
	TilesWorkshop *CreateWorkshop();
};