#include "TilesPile.h"

TilesPile::TilesPile(QSize tileSize, QGraphicsItem *parent)
	: QGraphicsEllipseItem(parent)
{
	tileContainer = new TileSlotSpiral(tileSize, tileSize.width() / 10, this);
}

TilesPile::~TilesPile()
{
}