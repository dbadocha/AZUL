#pragma once

#include <QObject>

#include "TileSlotLines.h"

class FloorLine : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

private:
	QSize tileSize = { 200, 200 };

	QVector<Tile*> floorTiles;
	TileSlotLines floorSlotLine;
	void emptyLine();

public:
	FloorLine(QPoint point, QSize tileSize, double spacing, QGraphicsItem *parent);
	~FloorLine();
	int countPoints();
	void addTiles(QVector<Tile*> * tileVector);
	void reinitialize();
};

