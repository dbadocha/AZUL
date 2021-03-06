#pragma once

#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "Enum.h"
#include "ui_Tile.h"

class Tile : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	Tile(TileColor color, QGraphicsItem *parent = 0);
	~Tile();
	void changeColor(TileColor color);
	void resize(QSize newSize);
	TileColor getColor();

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
	//QMimeData * mimeData(const QModelIndexList &indexes);

private:
	TileColor m_color;
	void loadPixmap();
	void changeCursor(TileColor newColor);
};