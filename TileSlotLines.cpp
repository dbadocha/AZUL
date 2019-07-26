#include "TileSlotLines.h"

TileSlotLines::TileSlotLines(int amount, QSize tileSize, double spacing, QGraphicsItem *parent)
	: TileSlotContainer(amount, tileSize, spacing, parent)
{
	setAcceptDrops(true);
	this->initializeSlots();
}

TileSlotLines::~TileSlotLines()
{
}

int TileSlotLines::width()
{
	return tileSlotsAmount * tileSize.width() + (tileSlotsAmount - 1) * spacing;
}

int TileSlotLines::height()
{
	return tileSize.height();
}


void TileSlotLines::initializeSlots()
{
	QPoint tilePosition;
	int x = 0;
	tilePosition.setY(0);
	for (int i = 0; i < tileSlotsAmount; ++i)
	{
		x = i * (tileSize.width() + spacing);
		tilePosition.setX(x);
		tileSlots.push_back(new TileSlot(tilePosition, tileSize, this));
		////////////////////////////////////temp/////////////////////
		tileSlots[i]->highlight(slotHighlightColor::GREEN);
	}
}

