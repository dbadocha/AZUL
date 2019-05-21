#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QWidget(parent)
{
	m_parent = parent;
	ui.setupUi(this);
	this->resize(parent->size());
	this->CreateNewGame(2);
	this->show();
}

GameBoard::~GameBoard()
{
	//delete GameTiles;
	//GameTiles = NULL;

	for (TilesWorkshop* i : GameWorkshops){
		delete i;
		i = NULL;
	}
}

void GameBoard::CreateNewGame(int PlayersCount)
{
	//GameTiles = new Tiles;

	WorkshopsAmount = 2 * PlayersCount + 1;
	for (int i = 0; i <= WorkshopsAmount; ++i)
	{
		GameWorkshops.push_back(CreateWorkshop());
	}
	this->addLayout();
}

void GameBoard::addLayout() {
	//GameTiles = new Tiles;
	int PosX = 0, PosY = 0;
	int r = 200;
	float pi = 3.1415926535;
	float a = 0;

	for (GameWorkshopsIterator = GameWorkshops.begin(); GameWorkshopsIterator != GameWorkshops.end(); ++GameWorkshopsIterator)
	{
		PosX = r * sin(a) + (this->width() - this->width() / 5) / 2;
		PosY = r * cos(a) + (this->width() - this->width() / 5) / 2.5;
		a += 2 * pi / WorkshopsAmount;
		(*GameWorkshopsIterator)->move(PosX, PosY);
	}
}


void GameBoard::FillWorkshops()
{
	//for (GameWorkshopsIterator = GameWorkshops.begin(); GameWorkshopsIterator != GameWorkshops.end(); ++GameWorkshopsIterator) {
		//(*GameWorkshopsIterator)->Refill(GameTiles);
}

TilesWorkshop *GameBoard::CreateWorkshop() {
	TilesWorkshop *workshop = new TilesWorkshop(this);
	return workshop;
}

void GameBoard::paintEvent(QPaintEvent *)
{
	QPixmap _pixmapBg(":/Resources/Resources/Table.jpg");
	QPainter paint(this);
	auto winSize = size();
	auto pixmapRatio = (float)_pixmapBg.width() / _pixmapBg.height();
	auto windowRatio = (float)winSize.width() / winSize.height();
	auto newWidth = (int)(winSize.height() / windowRatio);
	paint.drawPixmap(0, 0, winSize.width(), winSize.height(), _pixmapBg);
}