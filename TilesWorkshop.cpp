#include "TilesWorkshop.h"

TilesWorkshop::TilesWorkshop(QWidget *parent) : QWidget(parent)
{
	this->setFixedSize(parent->size()/5);
	ui.setupUi(this);
	this->initTiles();
	this->addLayout();
}

TilesWorkshop::~TilesWorkshop()
{
}

void TilesWorkshop::initTiles() {
	for (int i = 0, j = 0; i < 4; ++i) {
		WorkshopTiles[i] = new Tile(TileColor::NONE, this);
	}
}

void TilesWorkshop::addLayout() {
	int spacing = (this->width() / 10);
	int offset = (this->width() - spacing - 2* WorkshopTiles[0]->width()) / 2;

	for (int i = 0, j = 0; i < 4; ++i) {
		WorkshopTiles[i] = new Tile(TileColor::RED, this);
		int PosX = (offset + (spacing + WorkshopTiles[0]->width()) * (i % 2));
		int PosY = (offset + (spacing + WorkshopTiles[0]->width()) * (j % 2));
		WorkshopTiles[i]->move(PosX, PosY);

		if (i % 2)
			j++;
	}
	this->update();
}

//void TilesWorkshop::Refill(Tiles *GameTiles)
//{
//	for (int i = 0; i < 4; ++i) {
//		WorkshopTiles[i] = GameTiles->DrawTile();
//	}
//}

//void TilesWorkshop::ClearWorkshop()
//{
//	for (int i = 0; i < 4; ++i) {
//		WorkshopTiles[i] = TileColor::NONE;
//	}
//}

void TilesWorkshop::paintEvent(QPaintEvent *)
{
	QPixmap _pixmapBg(":/Resources/Resources/Workshop.jpg");
	QPainter paint(this);
	auto winSize = size();
	auto pixmapRatio = (float)_pixmapBg.width() / _pixmapBg.height();
	auto windowRatio = (float)winSize.width() / winSize.height();
	auto newWidth = (float)(winSize.width() / windowRatio);
	auto newHeight = (float)(winSize.height());
	paint.drawPixmap(0, 0, newWidth, newHeight, _pixmapBg);
}