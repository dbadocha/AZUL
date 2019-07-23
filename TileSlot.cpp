#include "TileSlot.h"

TileSlot::TileSlot(QPoint point, QSize size, QGraphicsRectItem *parent)
	: QGraphicsRectItem(point.x(), point.y(), size.width(), size.height(), parent)
{
	setAcceptDrops(true);
}

TileSlot::~TileSlot()
{
}


void TileSlot::resize(QSize size) {
	resizeSlot(size);
	resizeTile(size);
}

void TileSlot::resizeSlot(QSize size)
{
	qreal x = this->rect().x();
	qreal y = this->rect().y();
	this->setRect(x, y, size.width(), size.height());
}

void TileSlot::resizeTile(QSize size)
{
	if (slotTile != NULL)
		slotTile->resize(size);
}

void TileSlot::highlight(slotHighlightColor color)
{
	switch (color)
	{
	case slotHighlightColor::OFF:
		this->setBrush(QColor(0, 0, 0, 0));
		break;
	case slotHighlightColor::GREEN:
		this->setBrush(QColor(0, 255, 0, 100));
		break;
	case slotHighlightColor::BLUE:
		this->setBrush(QColor(0, 0, 255, 100));
		break;
	case slotHighlightColor::RED:
		this->setBrush(QColor(255, 0, 0, 100));
	}
}

void TileSlot::addTile(Tile* tileToken)
{
	slotTile = tileToken;
	int width = this->rect().size().width();
	int height = this->rect().size().height();
	resizeTile(QSize(width, height));
}

int TileSlot::isEmpty()
{
	if (slotTile == NULL)
		return 1;
	else
		return 0;
}

Tile* TileSlot::returnTile()
{
	Tile* ret = slotTile;
	slotTile = NULL;
	return ret;
}


void TileSlot::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
	this->highlight(slotHighlightColor::BLUE);
}

void TileSlot::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
	this->highlight(slotHighlightColor::OFF);
}