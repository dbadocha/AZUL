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

	initializeSlots(amount, tileSize, spacing);
}

TileSlotLines::~TileSlotLines()
{
}

void TileSlotLines::highlight(int amount, slotHighlightColor color)
{
	int lineSize = slotLine.size();
	for (int i = 0; i < amount && i < lineSize; ++i)
	{
		slotLine[i]->highlight(color);
	}
}

void TileSlotLines::addTiles(QVector<Tile*>* inputTiles)
{
	//////////////////////////////////////
	//in progress
	/////////////////////////////////
	Tile * tileToken = NULL;

	for (int i = inputTiles->size(), j = 0; i != 0; --i, ++j)
	{
		tileToken = inputTiles->at(i);
		slotLine[j]->addTile(tileToken);
	}
}

void TileSlotLines::initializeSlots(int amount, QSize tileSize, int spacing)
{
	QPoint tilePosition;
	int x = 0;
	tilePosition.setY(0);
	for (int i = 0; i < amount; ++i)
	{
		x = i * (tileSize.width() + spacing);
		tilePosition.setX(x);
		slotLine.push_back(new TileSlot(tilePosition, tileSize, this));
	}
}

