#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QList>

#include "TilesManager.h"
#include "Tile.h"
#include "Enum.h"

#define M_PI 3.14159265358979323846

class TilesPile : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT

private:
	QList<Tile*> Pile;
	QList<Tile*>::iterator PileIterator;
	TileField TilesSet[5] = {};
	int test = 0;

	void rearangeTilePos();

public:
	TilesPile(QGraphicsItem *parent = 0);
	~TilesPile();
	void returnToBin(TilesManager &, TileColor);
	void resize(QSize newSize);
	int takeColor(TileColor colorToTake);
	void addTile(TileColor newTile);

};