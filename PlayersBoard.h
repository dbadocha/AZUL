#pragma once

#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QVector>
#include <QGraphicsPixmapItem>

#include "FloorLine.h"
#include "PatternLines.h"

#define TILES_ROWS 5

class PlayersBoard : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

private:
	int points = 0;
	QSize tileSize = {10, 10};
	FloorLine* floorLine;
	PatternLines* patternLines;

	void loadPixmap();
	void initFloorLine();
	void initPatternLines();

public:
	PlayersBoard(QObject *parent = 0);
	~PlayersBoard();
	void resize(QSize newSize);
};