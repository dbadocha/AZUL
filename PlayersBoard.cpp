#include "PlayersBoard.h"

PlayersBoard::PlayersBoard(QGraphicsScene * scene, QObject *parent)
	: QObject(parent)
{
	scene->addItem(this);

	this->loadPixmap();
	initFloorLine();
	//this->initFinishedTiles();
	//this->initUnfinishedTiles();

}

void PlayersBoard::initFloorLine() {
	int posX = this->pixmap().width() / 45;
	int posY = this->pixmap().height() / 2.47;
	int width = this->pixmap().width() / 27;
	int height = this->pixmap().height() / 27;
	double spacing = this->pixmap().width() / 117;

	QPoint point = {posX, posY};
	QSize size = {width, height};

	floorLine = new FloorLine(point, size, 7.5, this);
}

PlayersBoard::~PlayersBoard()
{
}

void PlayersBoard::loadPixmap()
{
	QPixmap tmp(":/images/Resources/Images/Player'sBoard.jpg");
	this->setPixmap(tmp);
}

void PlayersBoard::resize(QSize newSize)
{
	this->setPixmap(this->pixmap().scaled(newSize));
	this->update();
}

void PlayersBoard::initFinishedTiles() {
	finishedTiles.resize(TILES_ROWS);
	for (int i = 0; i < TILES_ROWS; ++i)
		for (int j = 0; j < TILES_ROWS; ++j) {
			finishedTiles[i].push_back(new Tile(TileColor::NONE, this));
		}
}

void PlayersBoard::initUnfinishedTiles() {
	unfinishedTiles.resize(TILES_ROWS);
	for (int i = 0; i < TILES_ROWS; ++i)
		for (int j = 0; j < i + 1; ++j) {
			unfinishedTiles[i].push_back(new Tile(TileColor::NONE, this));
		}
}