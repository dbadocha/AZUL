#pragma once

#include <QObject>
#include <QGraphicsRectItem>

#include "Tile.h"
#include "TilesManager.h"

enum class highlightColor
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
	TileSlot(QSize size, QObject *parent);
	~TileSlot();

	void resize(QSize size);
	void highlight(highlightColor color);
	void addTile(Tile* tileToken);
	Tile* returnTile();
};
