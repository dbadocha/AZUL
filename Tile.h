#pragma once

#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "Enum.h"
#include "ui_Tile.h"
#include "TileSlotContainer.h"

class TileSlotContainer;
class Tile : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

private:
	TileColor m_color;
	TileSlotContainer* containerHandler;
	void loadPixmap();
	void changeCursor(TileColor newColor);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);

public:
	void slotChange(TileSlotContainer* newSlot);
	Tile(TileColor color, TileSlotContainer *parent = 0);
	~Tile();
	void changeColor(TileColor color);
	void resize(QSize newSize);
	TileColor getColor();
};