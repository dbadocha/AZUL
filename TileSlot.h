#pragma once

#include <QObject>
#include <QGraphicsRectItem>

#include "Tile.h"
#include "TilesManager.h"

enum class slotHighlightColor
{OFF, GREEN, BLUE, RED};

class TileSlot : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

private:
	Tile* slotTile = NULL;
	void resizeSlot(QSize size);
	void resizeTile(QSize size);

public:
	TileSlot(QPoint point, QSize size, QGraphicsRectItem *parent);
	~TileSlot();

	void resize(QSize size);
	void highlight(slotHighlightColor color);
	void addTile(Tile* tileToken);
	int isEmpty();
	Tile* returnTile();
};
