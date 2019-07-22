#pragma once

#include <QObject>
#include "TileSlotLines.h"

class PatternLines : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

private:
	QVector<TileSlotLines*> slotLines;
public:
	
	PatternLines(QGraphicsObject *parent);
	~PatternLines();
};
