#include "TileSlotLines.h"

TileSlotLines::TileSlotLines(int amount, QSize tileSize, double spacing, QGraphicsItem *parent)
	: QGraphicsRectItem(parent)
{
	int width = amount * tileSize.width() + (amount - 1) * spacing;
	int height = tileSize.height();
	this->setRect(0, 0, width, height);
	this->initializeSlots(amount, tileSize, spacing);
}

TileSlotLines::~TileSlotLines()
{
}

void TileSlotLines::highlight(int amount, slotHighlightColor color)
{
	int lineSize = tileSlotLine.size();
	for (int i = 0; i < amount && i < lineSize; ++i)
	{
		tileSlotLine[i]->highlight(color);
	}
}

void TileSlotLines::addTiles(QVector<Tile*>* inputTiles)
{
	Tile * tileToken = NULL;

	for (int i = tilesAmount; i < tileSlotLine.size(); ++i)
	{
		if (tileSlotLine[i]->isEmpty())
		{
			tileToken = inputTiles->at(i);
			tileSlotLine[i]->addTile(tileToken);
			++tilesAmount;
		}
	}
}

void TileSlotLines::emptySlots()
{
	for (int i = tileSlotLine.size() - 1; i >= 0; --i) {
		delete tileSlotLine[i];
		tileSlotLine[i] = NULL;
	}
}

void TileSlotLines::initializeSlots(int amount, QSize tileSize, double spacing)
{
	QPoint tilePosition;
	int x = 0;
	tilePosition.setY(0);
	for (int i = 0; i < amount; ++i)
	{
		x = i * (tileSize.width() + spacing);
		tilePosition.setX(x);
		tileSlotLine.push_back(new TileSlot(tilePosition, tileSize, this));
		tileSlotLine[i]->highlight(slotHighlightColor::GREEN);
	}
}

int TileSlotLines::size()
{
	return tileSlotLine.size();
}