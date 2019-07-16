#include "PlayersBoard.h"

PlayersBoard::PlayersBoard(QObject *parent)
	: QObject(parent)
{
	this->loadPixmap();
	this->initFinishedTiles();
	this->initUnfinishedTiles();
	//this->putInTrash(TileColor::YELLOW, 10);
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

void PlayersBoard::putInTrash(TileColor color, int amount) {
	for (int i = 0; i < amount; ++i) {
		trashedTiles.push_back(new Tile(color, this));
	}
	drawTrashedTiles();
}

void PlayersBoard::drawTrashedTiles() {
	int posX = this->pixmap().width() / 40;
	int posY = this->pixmap().height() / 2.38;
	int width = this->pixmap().width() / 27;
	int height = this->pixmap().height() / 27;

	for (int i = 0; i < trashedTiles.size(); ++i) {
		if (i > 6) {
			trashedTiles[i]->hide();
		}
		trashedTiles[i]->setPos(posX, posY);
		trashedTiles[i]->resize(QSize(width, height));
		posX += this->pixmap().width() / 21.5;
	}
}

int PlayersBoard::countTrashTilesPionts() {
	int points = 0;
	for (int i = 1; i < trashedTiles.size(); ++i) {
		if (i > 6) {
			points += 3;
			continue;
		}
		points += 1 + trunc(i / 3);
	}
	return points;
}

void PlayersBoard::emptyTrashPiles()
{
	for (int i = trashedTiles.size() - 1; i >= 0; --i) {
		delete trashedTiles[i];
		trashedTiles[i] = NULL;
	}
}