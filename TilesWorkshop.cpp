#include "TilesWorkshop.h"

TilesWorkshop::TilesWorkshop(int workshopID, QGraphicsItem *parent)
	: QGraphicsPixmapItem(parent)
{
	this->workshopID = workshopID;
	this->loadPixmap();
}

TilesWorkshop::~TilesWorkshop()
{
	for (int i = 0, j = 0; i < 4; ++i) {
		delete workshopTiles[i];
		workshopTiles[i] = NULL;
	}
}

void TilesWorkshop::addTiles() {
	this->initTiles();
	this->addLayout();
}

int TilesWorkshop::getID()
{
	return this->workshopID;
}

int TilesWorkshop::getTilesAmount(TileColor color)
{
	int colorAmount = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (workshopTiles[i]->getColor() == color)
			++colorAmount;
	}
	return colorAmount;
}

void TilesWorkshop::initTiles() {
	for (int i = 0, j = 0; i < 4; ++i) {
		workshopTiles[i] = new Tile(TileColor::NONE, this);
	}
}

void TilesWorkshop::addLayout() {
	
	int baseSize = (this->pixmap().width() + this->pixmap().height()) / 2;
	int newTileSize = baseSize / 5;
	int tileOffset = newTileSize / 2;

	int spacing = (baseSize / 10);
	int offset = (baseSize - spacing - 2 * newTileSize) / 2;

	for (int i = 0, j = 0; i < 4; ++i) {
		//temporary color
		workshopTiles[i] = new Tile(TileColor::RED, this);

		int posX = (offset + (spacing + newTileSize) * (i % 2));
		int posY = (offset + (spacing + newTileSize) * (j % 2));

		workshopTiles[i]->setPos(posX, posY);

		if (i % 2)
			j++;

		int newSize = (this->pixmap().width() + this->pixmap().height()) / (2 * 5);
		workshopTiles[i]->resize(QSize(newSize, newSize));
	}
	this->update();
}

//void TilesWorkshop::Refill(Tiles *GameTiles)
//{
//	for (int i = 0; i < 4; ++i) {
//		WorkshopTiles[i] = GameTiles->DrawTile();
//	}
//}

void TilesWorkshop::clearWorkshop()
{
	for (int i = 0; i < 4; ++i) {
		workshopTiles[i]->changeColor(TileColor::NONE);
	}
}

void TilesWorkshop::loadPixmap()
{
	QPixmap tmp(":/images/Resources/Images/Workshop.jpg");
	this->setPixmap(tmp);
}

void TilesWorkshop::resize(QSize newSize)
{
	this->setPixmap(this->pixmap().scaled(newSize));
	this->update();
}
