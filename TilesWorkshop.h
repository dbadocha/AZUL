#pragma once

#include <QWidget>
#include <QGridLayout>

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "Tile.h"

//#include "Tiles.h"
//#include "Enum.h"

class TilesWorkshop : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	TilesWorkshop(QGraphicsItem *parent = 0);
	~TilesWorkshop();
	//void Refill(Tiles *GameTiles);
	void ClearWorkshop();
	void resize(QSize newSize);
	void addTiles();

private:
	Tile *WorkshopTiles[4];
	void addLayout();
	void initTiles();
	void loadPixmap();
};

