#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent)
{
	this->resize(parent->size());

	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, 800, 600);
	setBackgroundBrush(QBrush(QImage(":/images/Resources/Images/Table.jpg")));
	setScene(scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(800, 600);

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

	delete scene;
	scene = NULL;
}

void GameBoard::CreateNewGame(int PlayersCount)
{
	WorkshopsAmount = 2 * PlayersCount + 1;
	for (int i = 0; i <= WorkshopsAmount; ++i)
	{
		GameWorkshops.push_back(CreateWorkshop());
	}
	this->addLayout();
}

void GameBoard::addLayout() {
	int PosX = 0, PosY = 0;
	int r = this->height() / 5;
	float pi = 3.1415926535;
	float a = 0;

	for (GameWorkshopsIterator = GameWorkshops.begin(); GameWorkshopsIterator != GameWorkshops.end(); ++GameWorkshopsIterator)
	{
		PosX = r * sin(a) + (this->width() - this->width() / 5) / 2;
		PosY = r * cos(a) + (this->width() - this->width() / 5) / 2.5;
		a += 2 * pi / WorkshopsAmount;
		(*GameWorkshopsIterator)->setPos(PosX, PosY);

		int newSize = (this->width() + this->height()) / (2 * 5);
		(*GameWorkshopsIterator)->resize(QSize(newSize, newSize));
		scene->addItem(*GameWorkshopsIterator);

		(*GameWorkshopsIterator)->addTiles();
	}
}


void GameBoard::FillWorkshops()
{
	//for (GameWorkshopsIterator = GameWorkshops.begin(); GameWorkshopsIterator != GameWorkshops.end(); ++GameWorkshopsIterator) {
		//(*GameWorkshopsIterator)->Refill(GameTiles);
}

TilesWorkshop *GameBoard::CreateWorkshop() {
	TilesWorkshop *workshop = new TilesWorkshop();
	return workshop;
}

//void GameBoard::paintEvent(QPaintEvent *)
//{
//	QPixmap _pixmapBg(":/images/Resources/Images/Table.jpg");
//	QPainter paint(this);
//	auto winSize = size();
//	auto pixmapRatio = (float)_pixmapBg.width() / _pixmapBg.height();
//	auto windowRatio = (float)winSize.width() / winSize.height();
//	auto newWidth = (int)(winSize.height() / windowRatio);
//	paint.drawPixmap(0, 0, winSize.width(), winSize.height(), _pixmapBg);
//}