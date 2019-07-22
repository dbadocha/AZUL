#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QVector>
#include "TileSlot.h"

class TileSlotLines : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
private:
	QVector <TileSlot*> tileSlotLine;
	int tilesAmount = 0;
	void initializeSlots(int amount, QSize tileSize, double spacing);

public:
	TileSlotLines(int amount, QSize size, double spacing, QGraphicsItem *parent = 0);
	~TileSlotLines();

	void highlight(int amount, slotHighlightColor color);
	void addTiles(QVector <Tile*> * inputTiles);
	void emptySlots();
	int size();
};
