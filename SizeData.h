#pragma once

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QGraphicsScene>

class SizeData
{

public:
	QSize boardSize;
	QSize tileSize;
	QGraphicsScene scene;

	SizeData();
	~SizeData();
};
