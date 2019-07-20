#include "TileSlot.h"

TileSlot::TileSlot(QObject *parent)
	: QObject(parent)
{
}

TileSlot::TileSlot(QSize size, QObject *parent)
	: QObject(parent), QGraphicsRectItem(0, 0, size.width(), size.height())
{

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

void TileSlot::highlight(highlightColor color)
{
	switch (color)
	{
	case highlightColor::OFF:
		this->setBrush(QColor(0, 0, 0, 0));
		break;
	case highlightColor::GREEN:
		this->setBrush(QColor(0, 255, 0, 255));
		break;
	case highlightColor::BLUE:
		this->setBrush(QColor(0, 0, 255, 255));
		break;
	case highlightColor::RED:
		this->setBrush(QColor(255, 0, 0, 255));
	}
}

void TileSlot::addTile(Tile* tileToken)
{
	slotTile = tileToken;
	int width = this->rect().size().width();
	int height = this->rect().size().height();
	resizeTile(QSize(width, height));
}

Tile* TileSlot::returnTile()
{
	Tile* ret = slotTile;
	slotTile = NULL;
	return ret;
}