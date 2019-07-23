#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QVector>
#include "TileSlot.h"

class TileSlotLines : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
private:
	int slotLineID = 0;
	QVector <TileSlot*> tileSlotLine;
	int tilesAmount = 0;
	void initializeSlots(int amount, QSize tileSize, double spacing);

protected:
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
	void dropEvent(QGraphicsSceneDragDropEvent *event);

public:
	TileSlotLines(int slotLineID, int amount, QSize size, double spacing, QGraphicsItem *parent = 0);
	~TileSlotLines();

	void highlight(int amount, slotHighlightColor color);
	void addTiles(QVector <Tile*> * inputTiles);
	void emptySlots();
	int size();
	int getID();
};