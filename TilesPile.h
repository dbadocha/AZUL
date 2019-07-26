#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QList>

#include "TilesManager.h"
#include "TileSlotSpiral.h"
#include "Enum.h"

#define M_PI 3.14159265358979323846

class TilesPile : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT

private:
	TileSlotSpiral* tileContainer;

public:
	TilesPile(QSize tileSize, QGraphicsItem *parent = 0);
	~TilesPile();
};