#include "PatternLines.h"

void PatternLines::initializeSlotLines(QSize tileSize, double spacing)
{
	double posX = 0;
	double posY = 0;
	for (int i = 0, j = 4; i < 5; ++i, --j)
	{
		posX = j * (tileSize.width() + spacing);
		posY = i * (tileSize.height() + spacing);
		slotLines.push_back(new TileSlotLines(i+1, tileSize, spacing, this));
		slotLines[i]->setPos(posX, posY);
	}
}

PatternLines::PatternLines(QPoint point, QSize tileSize, double spacing, QGraphicsItem *parent)
	: QGraphicsRectItem(parent)
{
	this->setPos(point.x(), point.y());
	initializeSlotLines(tileSize, spacing);
}



PatternLines::~PatternLines()
{
}
