#include "TilesWorkshop.h"

TilesWorkshop::TilesWorkshop(QGraphicsItem *parent)
	: QGraphicsPixmapItem(parent)
	
{
	loadPixmap();
	initializeSlotLines();
}

void TilesWorkshop::initializeSlotLines()
{
	int width = this->pixmap().width() / 4.5;
	int height = this->pixmap().height() / 4.5;
	double spacing = this->pixmap().width() / 10;
	slotLines = new TileSlotSquare(2, 4, QSize(width, height), spacing, this);

	int x = this->pixmap().width() / 2 - slotLines->width() / 2;
	int y = this->pixmap().height() / 2 - slotLines->height() / 2;
	slotLines->setPos(x, y);
}

int TilesWorkshop::getID()
{
	return this->workshopID;
}

void TilesWorkshop::loadPixmap()
{
	QPixmap tmp(":/images/Resources/Images/Workshop.jpg");
	/////////////////////temp///////////////////
	this->setPixmap(tmp.scaled(200, 200, Qt::KeepAspectRatio));
}

TilesWorkshop::~TilesWorkshop()
{
}
