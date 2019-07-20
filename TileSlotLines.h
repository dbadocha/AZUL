#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QVector>
#include "TileSlot.h"

class TileSlotLines : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
private:
	QVector <TileSlot*> slotLine;
	QVector <TileSlot*>::iterator slotLineIterator;
	void initializeSlots();
	void createSlots(int amount, QSize tileSize);
	void layoutSlots(int amount, QSize tileSize);
	

public:
	TileSlotLines(QObject *parent);
	TileSlotLines(int amount, QSize size, int spacing, QObject *parent);
	~TileSlotLines();
};
