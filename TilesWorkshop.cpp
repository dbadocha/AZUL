#include "TilesWorkshop.h"

TilesWorkshop::TilesWorkshop(QGraphicsItem *parent)
	: QGraphicsPixmapItem(parent)
{
	this->loadPixmap();
}

TilesWorkshop::~TilesWorkshop()
{
	for (int i = 0, j = 0; i < 4; ++i) {
		delete WorkshopTiles[i];
		WorkshopTiles[i] = NULL;
	}
}

void TilesWorkshop::addTiles() {
	this->initTiles();
	this->addLayout();
}

void TilesWorkshop::initTiles() {
	for (int i = 0, j = 0; i < 4; ++i) {
		WorkshopTiles[i] = new Tile(TileColor::NONE, this);
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
		WorkshopTiles[i] = new Tile(TileColor::RED, this);

		int PosX = (offset + (spacing + newTileSize) * (i % 2));
		int PosY = (offset + (spacing + newTileSize) * (j % 2));

		WorkshopTiles[i]->setPos(PosX, PosY);

		if (i % 2)
			j++;

		int newSize = (this->pixmap().width() + this->pixmap().height()) / (2 * 5);
		WorkshopTiles[i]->resize(QSize(newSize, newSize));

		this->scene()->addItem(WorkshopTiles[i]);
	}
	this->update();
}

//void TilesWorkshop::Refill(Tiles *GameTiles)
//{
//	for (int i = 0; i < 4; ++i) {
//		WorkshopTiles[i] = GameTiles->DrawTile();
//	}
//}

void TilesWorkshop::ClearWorkshop()
{
	for (int i = 0; i < 4; ++i) {
		WorkshopTiles[i]->changeColor(TileColor::NONE);
	}
}

void TilesWorkshop::loadPixmap()
{
	QPixmap tmp(":/images/Resources/Images/Workshop.jpg");
	setPixmap(tmp);
}

void TilesWorkshop::resize(QSize newSize)
{
	this->setPixmap(this->pixmap().scaled(newSize));

	this->update();
}