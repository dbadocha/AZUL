#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent)
{
	this->resize(parent->size());

	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, parent->size().width(), parent->size().height());
	setBackgroundBrush(QBrush(QImage(":/images/Resources/Images/Table.jpg")));
	setScene(scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(parent->size().width(), parent->size().height());

	this->createNewGame(1);
	this->show();
}

GameBoard::~GameBoard()
{
	//delete GameTiles;
	//GameTiles = NULL;

	for (TilesWorkshop* i : gameWorkshops){
		delete i;
		i = NULL;
	}

	delete scene;
	scene = NULL;
}

void GameBoard::createNewGame(int PlayersCount)
{
	workshopsAmount = 2 * PlayersCount + 1;
	for (int i = 0; i <= workshopsAmount; ++i)
	{
		TilesWorkshop * tmp = new TilesWorkshop(i);
		gameWorkshops.push_back(tmp);
		scene->addItem(tmp);
	}

	for (int i = 0; i < PlayersCount; ++i) {
		PlayersBoard * tmp = new PlayersBoard();
		playerBoard.push_back(tmp);
		playerBoard[i]->setPos(QPoint(50, 50));
		scene->addItem(tmp);
	}

	pile = new TilesPile();
	scene->addItem(pile);


	this->addLayout();
}

void GameBoard::addLayout() {
	int posX = 0, posY = 0;
	int r = this->height() / 4;
	float a = 0;
	int newWorkshopSize = (this->width() + this->height()) / (2 * resizeFactor);
	int newPileSize = 2 * r - newWorkshopSize;
	int offsetX = this->width() / 2;
	int offsetY = this->height() / 3;

	for (gameWorkshopsIterator = gameWorkshops.begin(); gameWorkshopsIterator != gameWorkshops.end(); ++gameWorkshopsIterator)
	{
		posX = r * sin(a) + offsetX - newWorkshopSize / 2;
		posY = r * cos(a) + offsetY - newWorkshopSize / 2;
		a += 2 * M_PI / workshopsAmount;
		(*gameWorkshopsIterator)->setPos(posX, posY);
		(*gameWorkshopsIterator)->resize(QSize(newWorkshopSize, newWorkshopSize));
		(*gameWorkshopsIterator)->addTiles();
	}

	for (playerBoardIterator = playerBoard.begin(); playerBoardIterator != playerBoard.end(); ++playerBoardIterator)
	{

		int newPlayerBoardSize = (this->width() + this->height()) / 4;
		//(*playerBoardIterator)->setPos(posX, posY);
		(*playerBoardIterator)->resize(QSize(newPlayerBoardSize, newPlayerBoardSize));
	}

	posX = offsetX - newPileSize / 2;
	posY = offsetY - newPileSize / 2;
	pile->setPos(posX, posY);
	pile->resize(QSize(newPileSize, newPileSize));
}


void GameBoard::FillWorkshops()
{
	//for (GameWorkshopsIterator = GameWorkshops.begin(); GameWorkshopsIterator != GameWorkshops.end(); ++GameWorkshopsIterator) {
		//(*GameWorkshopsIterator)->Refill(GameTiles);
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