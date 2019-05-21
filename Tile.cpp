#include "Tile.h"


Tile::Tile(TileColor color, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_parent = parent;
	m_color = color;
	this->setFixedSize(parent->size() / 5);
}

Tile::~Tile()
{
}

void Tile::changeColor(TileColor color) {
	this->m_color = color;
	this->update();
}

void Tile::paintEvent(QPaintEvent *)
{
	QPixmap _pixmapBg;
	switch (m_color) {
	case TileColor::BLUE:
		_pixmapBg.load(":/Resources/Resources/TileBlue.jpg");
		break;
	case TileColor::BLACK:
		_pixmapBg.load(":/Resources/Resources/TileBlack.jpg");
		break;
	case TileColor::WHITE:
		_pixmapBg.load(":/Resources/Resources/TileWhite.jpg");
		break;
	case TileColor::RED:
		_pixmapBg.load(":/Resources/Resources/TileRed.jpg");
		break;
	case TileColor::YELLOW:
		_pixmapBg.load(":/Resources/Resources/TileYellow.jpg");
		break;
	}
	QPainter paint(this);
	auto winSize = this->size();
	auto pixmapRatio = (float)_pixmapBg.width() / _pixmapBg.height();
	auto windowRatio = (float)winSize.width() / winSize.height();
	auto newWidth = (float)(winSize.width() / windowRatio);
	auto newHeight = (float)(winSize.height());
	paint.drawPixmap(0, 0, newWidth, newHeight, _pixmapBg);
}