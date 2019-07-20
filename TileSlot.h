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
	TileSlot(QObject *parent);
	TileSlot(QPoint point, QSize size, QObject *parent);
	~TileSlot();

	void resize(QSize size);
	void highlight(slotHighlightColor color);
	void addTile(Tile* tileToken);
	Tile* returnTile();
};
