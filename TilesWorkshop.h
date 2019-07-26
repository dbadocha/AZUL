#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "Tile.h"
#include "TileSlotSquare.h"

class TilesWorkshop : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

private:
	uint32_t workshopID = reinterpret_cast<uint32_t>(this);
	TileSlotSquare* slotLines;
	void initializeSlotLines();
	void loadPixmap();

public:
	TilesWorkshop(QGraphicsItem *parent = 0);
	~TilesWorkshop();

	int getID();
};