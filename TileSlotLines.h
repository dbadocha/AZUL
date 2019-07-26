#pragma once

#include "TileSlotContainer.h"

class TileSlotLines : public TileSlotContainer
{
	Q_OBJECT
private:
	void initializeSlots();

public:
	TileSlotLines(int amount, QSize size, double spacing, QGraphicsItem *parent = 0);
	~TileSlotLines();
	int width();
	int height();
};