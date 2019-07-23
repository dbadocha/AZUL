#include "FloorLine.h"

FloorLine::FloorLine(QPoint point, QSize tileSize, double spacing, QGraphicsItem *parent)
	: QGraphicsRectItem(parent)
	, floorSlotLine(10, 7, tileSize, spacing, this)
{
	this->setPos(point);
}

FloorLine::~FloorLine()
{
}

int FloorLine::countPoints(){
	int points = 0;
	for (int i = 1; i < floorTiles.size(); ++i) {
		if (i > 6) {
			points += 3;
			continue;
		}
		points += 1 + trunc(i / 3);
	}
	return points;
}

void FloorLine::addTiles(QVector<Tile*> * tileVector) {
	floorTiles += *tileVector;
	floorSlotLine.addTiles(tileVector);
}

void FloorLine::reinitialize()
{
	floorSlotLine.emptySlots();
	emptyLine();
}

void FloorLine::emptyLine()
{
	for (int i = floorTiles.size() - 1; i >= 0; --i) {
		delete floorTiles[i];
		floorTiles[i] = NULL;
		floorTiles.pop_back();
	}
}