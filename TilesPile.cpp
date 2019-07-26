#include "TilesPile.h"

TilesPile::TilesPile(QGraphicsItem *parent)
	: QGraphicsEllipseItem(parent)
{
	for (TileColor color : TileColorIterator()) {
		TilesSet[static_cast<int>(color) - 1].Color = color;
		TilesSet[static_cast<int>(color) - 1].TilesCount = 0;
	}
	this->setRect(0, 0, 10, 10);
	this->setPen(Qt::NoPen);
}

TilesPile::~TilesPile()
{
	for (PileIterator = Pile.begin(); PileIterator != Pile.end(); ++PileIterator) {
		delete (*PileIterator);
		PileIterator = NULL;
		Pile.erase(PileIterator);
	}
}


void TilesPile::returnToBin(TilesManager & oTiles, TileColor color)
{
	int tmp_count = TilesSet[static_cast<int>(color) - 1].TilesCount;
	oTiles.ReturnTilesToBin(color, tmp_count);
	TilesSet[static_cast<int>(color) - 1].TilesCount = 0;
}

void TilesPile::resize(QSize newSize)
{
	QRectF tmp = this->rect();
	tmp.setSize(newSize);
	this->setRect(tmp);
}

void TilesPile::addTile(TileColor newTile)
{
	//Tile * tmp = new Tile(newTile, this);
	//int newSize = this->rect().width()  / 8;
	//newSize = tmp->pixmap().width() / 2.5;
	//tmp->resize(QSize(newSize, newSize));
	//Pile.push_back(tmp);
	//rearangeTilePos();
}


int TilesPile::takeColor(TileColor colorToTake)
{
	return 0;
}

void TilesPile::rearangeTilePos()
{
	int tilesAmount = Pile.size();

	float a = 0;
	int tileSize = 40, offset = 0, spacing = 3;
	int pileSize = this->rect().width();
	int posX = 0, posY = 0;
	tileSize = Pile[0]->pixmap().width();

	offset = pileSize / 2 - tileSize / 2;

	int direction = 0, distance = 0;
	PileIterator = Pile.begin();

	(*PileIterator)->setPos(posX + offset, posY + offset);
	++PileIterator;

	while (PileIterator != Pile.end())
	{
		if (direction == 2 || direction == 0)
			++distance;

		for (int i = 0; i < distance && PileIterator != Pile.end(); ++i) {

			switch (direction) {
			case 0:
				posX += tileSize + spacing;
				break;
			case 1:
				posY += tileSize + spacing;
				break;
			case 2:
				posX -= tileSize + spacing;
				break;
			case 3:
				posY -= tileSize + spacing;
				break;
			}
			(*PileIterator)->setPos(posX + offset, posY + offset);
			++PileIterator;
		}

		if (direction > 3)
			direction = 0;
		else
			++direction;
	}
}