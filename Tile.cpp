#include "Tile.h"


Tile::Tile(TileColor color, QGraphicsItem *parent)
	: QGraphicsPixmapItem(parent)
{
	m_color = color;
	changeCursor(color);
	loadPixmap();
}

Tile::~Tile()
{
}

void Tile::changeColor(TileColor color) {
	this->m_color = color;
	changeCursor(color);
	this->loadPixmap();
	this->update();
}



void Tile::loadPixmap()
{
	QPixmap tmp;
	switch (m_color) {
	case TileColor::BLUE:
		tmp.load(":/images/Resources/Images/TileBlue.jpg");
		break;
	case TileColor::BLACK:
		tmp.load(":/images/Resources/Images/TileBlack.jpg");
		break;
	case TileColor::WHITE:
		tmp.load(":/images/Resources/Images/TileWhite.jpg");
		break;
	case TileColor::RED:
		tmp.load(":/images/Resources/Images/TileRed.jpg");
		break;
	case TileColor::YELLOW:
		tmp.load(":/images/Resources/Images/TileYellow.jpg");
		break;
	}

	setPixmap(tmp);
}

void Tile::changeCursor(TileColor newColor) {
	if (newColor == TileColor::NONE) {
		this->setCursor(Qt::ArrowCursor);
		setAcceptedMouseButtons(Qt::NoButton);
	}
	else {
		this->setCursor(Qt::OpenHandCursor);
		setAcceptedMouseButtons(Qt::LeftButton);
	}
}

void Tile::resize(QSize newSize)
{
	this->setPixmap(this->pixmap().scaled(newSize));
	this->update();
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	this->setCursor(Qt::ClosedHandCursor);
}

void Tile::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	changeCursor(m_color);
}

void Tile::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{

	QDrag *drag = new QDrag(this);
	QMimeData *mimeData = new QMimeData;
	drag->setMimeData(mimeData);
	drag->setPixmap(this->pixmap());
	drag->setHotSpot(QPoint(15, 20));
	drag->exec();
	changeCursor(m_color);
}

TileColor Tile::getColor()
{
	return m_color;
}