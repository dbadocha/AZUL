#include "PlayersBoard.h"

PlayersBoard::PlayersBoard(QObject *parent)
	: QObject(parent)
{
	loadPixmap();
	int width = this->pixmap().width() / 27;
	int height = this->pixmap().height() / 27;
	tileSize = { width, height };

	initFloorLine();
	initPatternLines();
}

void PlayersBoard::initFloorLine() {
	int posX = this->pixmap().width() / 45;
	int posY = this->pixmap().height() / 2.47;
	double spacing = this->pixmap().width() / 124.0;
	QPoint point = {posX, posY};

	floorLine = new FloorLine(point, tileSize, spacing, this);
}


void PlayersBoard::initPatternLines()
{
	int posX = this->pixmap().width() / 40;
	int posY = this->pixmap().height() / 5.9;
	double spacing = this->pixmap().width() / 220.0;
	QPoint point = { posX, posY };

	patternLines = new PatternLines(point, tileSize, spacing, this);
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