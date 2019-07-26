#include "TileSlotSpiral.h"

TileSlotSpiral::TileSlotSpiral(QSize tileSize, double spacing, QGraphicsItem *parent)
	: TileSlotContainer(0, tileSize, spacing, parent)
{
	setAcceptDrops(false);
	initSlot();
}

TileSlotSpiral::~TileSlotSpiral()
{
}

int TileSlotSpiral::width()
{
	if (!tilesAmount)
		return 0;

	int len = ceil(sqrt(tilesAmount));
	return (len) * tileSize.width() + (len - 1) * spacing;
}

int TileSlotSpiral::height()
{
	if (!tilesAmount)
		return 0;

	int len = round(sqrt(tilesAmount));
	return (len)* tileSize.width() + (len - 1) * spacing;
}

void TileSlotSpiral::addSlot()
{
	tileSlots.push_back(new TileSlot(getNextPosition(), tileSize, this));
	++tileSlotsAmount;
	int posX = tileSlots.back()->x();
	int posY = tileSlots.back()->y();
	this->setRect(0, 0, this->width(), this->height());
}

void TileSlotSpiral::initSlot()
{
	for (int i = 0; i < 3; ++i)
	{
		addSlot();
	}
}

QPoint TileSlotSpiral::getNextPosition()
{
	if (!tileSlotsAmount)
		return QPoint(0, 0);

	int dir1 = static_cast<int>(ceil(sqrt(tileSlotsAmount))) % 2;
	int dir2 = static_cast<int>(round(sqrt(tileSlotsAmount))) % 2;
	
	if (!dir1 && !dir2)
		memPosX += tileSize.width() + spacing;
	else if (dir1 && !dir2)
		memPosY += tileSize.height() + spacing;
	else if (dir1 && dir2)
		memPosX -= tileSize.width() + spacing;
	else if (!dir1 && dir2)
		memPosY -= tileSize.height() + spacing;

	return QPoint(memPosX, memPosY);
}
