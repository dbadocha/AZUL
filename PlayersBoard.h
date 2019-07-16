#pragma once

#include "Tile.h"
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QVector>
#include <QGraphicsPixmapItem>

#define TILES_ROWS 5

class PlayersBoard : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

private:
	int points = 0;
	QVector<QVector<Tile*>> finishedTiles;
	QVector<QVector<Tile*>> unfinishedTiles;
	QVector<Tile*> trashedTiles;

	void loadPixmap();

	void initFinishedTiles();
	void initUnfinishedTiles();

	void putInTrash(TileColor color, int amount);

	void drawTrashedTiles();
	void drawPointsMarker();
	void drawUnfinishedTiles();
	void drawFinishedTiles();

	int countTrashTilesPionts();
	void emptyTrashPiles();

public:
	PlayersBoard(QObject *parent = 0);
	~PlayersBoard();
	void resize(QSize newSize);
};