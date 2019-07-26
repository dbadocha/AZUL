#pragma once

#include "TileSlotContainer.h"

class TileSlotSquare : public TileSlotContainer
{
private:
	int perLine = 0;
	void initializeSlots();

public:
	TileSlotSquare(int perLine, int amount, QSize tileSize, double spacing, QGraphicsItem *parent = 0);
	~TileSlotSquare();
	int width();
	int height();
};