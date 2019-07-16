#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "Tile.h"

class TilesWorkshop : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

private:
	Tile *WorkshopTiles[4];
	void addLayout();
	void initTiles();
	void loadPixmap();

public:
	TilesWorkshop(QGraphicsItem *parent = 0);
	~TilesWorkshop();
	//void Refill(Tiles *GameTiles);
	void ClearWorkshop();
	void resize(QSize newSize);
	void addTiles();
};

//QGraphicsEllipseItem