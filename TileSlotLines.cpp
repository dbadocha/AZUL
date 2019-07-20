#include "TileSlotLines.h"

TileSlotLines::TileSlotLines(QObject *parent)
	: QObject(parent)
{
}

TileSlotLines::TileSlotLines(int amount, QSize tileSize, int spacing, QObject *parent)
	: QObject(parent)
{
	int width = amount * tileSize.width() + (amount - 1) * spacing;
	int height = tileSize.height();

	this->setRect(0, 0, width, height);
}

TileSlotLines::~TileSlotLines()
{
}

void TileSlotLines::createSlots(int amount, QSize tileSize)
{
	for (int i = 0; i < amount; ++i)
	{
		slotLine.push_back(new TileSlot(tileSize, this));
	}
}
