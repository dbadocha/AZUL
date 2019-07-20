#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QVector>
#include "TileSlot.h"

class TileSlotLines : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
private:
	QVector <TileSlot*> slotLine;
	int tilesAmount = 0;
	void initializeSlots(int amount, QSize tileSize, int spacing);	

public:
	TileSlotLines(QObject *parent);
	TileSlotLines(int amount, QSize size, int spacing, QObject *parent);
	~TileSlotLines();

	void highlight(int amount, slotHighlightColor color);
	void addTiles(QVector <Tile*> * slotLine);
};
