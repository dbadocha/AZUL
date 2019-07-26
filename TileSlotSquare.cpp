#include "TileSlotSquare.h"

TileSlotSquare::TileSlotSquare(int perLine, int amount, QSize tileSize, double spacing, QGraphicsItem *parent)
	: TileSlotContainer(amount, tileSize, spacing, parent)
{
	this->perLine = perLine;
	setAcceptDrops(false);
	this->initializeSlots();
}

TileSlotSquare::~TileSlotSquare()
{
}

int TileSlotSquare::width()
{
	return perLine * tileSize.width() + (perLine - 1) * spacing;
}

int TileSlotSquare::height()
{
	int linesAmount = (tileSlotsAmount / perLine);
	return linesAmount * tileSize.width() + (linesAmount - 1) * spacing;
}

void TileSlotSquare::initializeSlots()
{
	int x = 0, y = 0;
	for (int i = 0; i < tileSlotsAmount / perLine; ++i)
	{
		y = i * (tileSize.width() + spacing);
		for (int j = 0; j < perLine; ++j)
		{
			x = j * (tileSize.width() + spacing);
			tileSlots.push_back(new TileSlot(QPoint(x, y), tileSize, this));
			////////////////////////////////////temp/////////////////////
			tileSlots[i]->highlight(slotHighlightColor::GREEN);
		}
	}
}