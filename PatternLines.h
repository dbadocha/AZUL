#pragma once

#include <QObject>
#include <QVector>
#include "TileSlotLines.h"

class PatternLines : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

private:
	QVector<TileSlotLines*> slotLines;
	void initializeSlotLines(QSize tileSize, double spacing);

public:
	PatternLines(QPoint point, QSize tileSize, double spacing, QGraphicsItem *parent);
	~PatternLines();
};
