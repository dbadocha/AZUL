#include "TileSlotSquare.h"

TileSlotSquare::TileSlotSquare(int sideSize, QSize tileSize, double spacing, QGraphicsItem *parent)
	: TileSlotContainer(pow(sideSize, 2), tileSize, spacing, parent)
{
	this->sideSize = sideSize;
	setAcceptDrops(false);
	this->initializeSlots();
}

TileSlotSquare::~TileSlotSquare()
{
}

int TileSlotSquare::width()
{
	return sideSize * tileSize.width() + (sideSize - 1) * spacing;
}

int TileSlotSquare::height()
{
	return width();
}

void TileSlotSquare::initializeSlots()
{
	int x = 0, y = 0;
	for (int i = 0; i < sideSize; ++i)
	{
		y = i * (tileSize.width() + spacing);
		for (int j = 0; j < sideSize; ++j)
		{
			x = j * (tileSize.width() + spacing);
			tileSlots.push_back(new TileSlot(QPoint(x, y), tileSize, this));
			////////////////////////////////////temp/////////////////////
			tileSlots.back()->highlight(slotHighlightColor::GREEN);
		}
	}
}