#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "Tile.h"

class TilesWorkshop : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

private:
	int workshopID = 0;
	Tile *workshopTiles[4];
	void addLayout();
	void initTiles();
	void loadPixmap();

public:
	TilesWorkshop(int workshopID, QGraphicsItem *parent = 0);
	~TilesWorkshop();
	//void Refill(Tiles *GameTiles);
	void clearWorkshop();
	void resize(QSize newSize);
	void addTiles();
	int getID();
	int getTilesAmount(TileColor color);
};

//QGraphicsEllipseItem