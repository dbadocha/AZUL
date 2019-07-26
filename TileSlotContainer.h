#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QVector>
#include <QDebug>

#include "TileSlot.h"
#include "Tile.h"


class Tile;
class TileSlot;
enum class slotHighlightColor;

class TileSlotContainer : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
private:
	uint32_t containerID = reinterpret_cast<uint32_t>(this);


protected:
	QVector <TileSlot*> tileSlots;
	int tilesAmount = 0;
	int tileSlotsAmount = 0;
	QSize tileSize = { 0, 0 };
	double spacing = 0.0;

	void initializeSlots(int amount, QSize tileSize, double spacing);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
	void dropEvent(QGraphicsSceneDragDropEvent *event);

public:
	TileSlotContainer(int amount, QSize tileSize, double spacing, QGraphicsItem *parent = 0);
	~TileSlotContainer();

	void addTiles(QVector <Tile*> * inputTiles);
	void highlight(int amount, slotHighlightColor color);
	int getColorAmount(TileColor color);
	void emptySlots();
	int size();
	int getID();
};