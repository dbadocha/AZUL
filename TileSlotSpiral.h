#pragma once

#include "TileSlotContainer.h"

enum Dir {UP, RIGHT, DOWN, LEFT};

class TileSlotSpiral : public TileSlotContainer
{
private:
	int memPosX = 0, memPosY = 0;
	//void addSlot();
	void initSlot();
	void rearangeSlotsPos();
	QPoint getNextPosition();

public:
	void addSlot();
	TileSlotSpiral(QSize tileSize, double spacing, QGraphicsItem *parent = 0);
	~TileSlotSpiral();
	void addTiles(QVector<Tile *> tilesToAdd);
	int width();
	int height();
};
