#pragma once

#include "Tile.h"
#include "TileSlotLines.h"

#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QVector>
#include <QGraphicsPixmapItem>

#include "FloorLine.h"

#define TILES_ROWS 5

class PlayersBoard : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

private:
	int points = 0;

	FloorLine* floorLine;

	QVector<QVector<Tile*>> finishedTiles;
	QVector<QVector<Tile*>> unfinishedTiles;

	void loadPixmap();

	void initFloorLine();
	void initFinishedTiles();
	void initUnfinishedTiles();

	void drawTrashedTiles();
	void drawPointsMarker();
	void drawUnfinishedTiles();
	void drawFinishedTiles();

public:
	PlayersBoard(QGraphicsScene * scene, QObject *parent = 0);
	~PlayersBoard();
	void resize(QSize newSize);
};