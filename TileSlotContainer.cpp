#include "TileSlotContainer.h"

TileSlotContainer::TileSlotContainer(int amount, QSize tileSize, double spacing, QGraphicsItem *parent)
	: QGraphicsRectItem(parent)
{
	this->tileSlotsAmount = amount;
	this->tileSize = tileSize;
	this->spacing = spacing;
}

TileSlotContainer::~TileSlotContainer()
{
}

void TileSlotContainer::addTiles(QVector<Tile*>* inputTiles)
{
	Tile * tileToken = NULL;

	for (int i = tilesAmount; i < tileSlots.size(); ++i)
	{
		if (tileSlots[i]->isEmpty())
		{
			tileToken = inputTiles->at(i);
			tileSlots[i]->addTile(tileToken);
			++tilesAmount;
		}
	}
}

void TileSlotContainer::emptySlots()
{
	for (int i = tileSlots.size() - 1; i >= 0; --i) {
		delete tileSlots[i];
		tileSlots[i] = NULL;
	}
	tilesAmount = 0;
}

int TileSlotContainer::size()
{
	return tileSlots.size();
}

void TileSlotContainer::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
	this->highlight(7, slotHighlightColor::BLUE);
}

void TileSlotContainer::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
	this->highlight(7, slotHighlightColor::OFF);
}

void TileSlotContainer::dropEvent(QGraphicsSceneDragDropEvent *event)
{

	//if (event->mimeData()->hasFormat(PiecesList::puzzleMimeType())) {
	//	QByteArray pieceData = event->mimeData()->data(PiecesList::puzzleMimeType());
	//	QDataStream dataStream(&pieceData, QIODevice::ReadOnly);
	//	QPixmap pixmap;
	//	QPoint location;
	//	dataStream >> pixmap >> location;

	//	addPiece(pixmap, location);

	//	event->setDropAction(Qt::MoveAction);
	//	event->accept();
	//}
	//else {
	//	event->ignore();
	//}

	this->highlight(7, slotHighlightColor::RED);
}

int TileSlotContainer::getID()
{
	return containerID;
}

void TileSlotContainer::initializeSlots(int amount, QSize tileSize, double spacing)
{
	QPoint tilePosition;
	int x = 0;
	tilePosition.setY(0);
	tileSlotsAmount = amount;
	for (int i = 0; i < amount; ++i)
	{
		x = i * (tileSize.width() + spacing);
		tilePosition.setX(x);
		tileSlots.push_back(new TileSlot(tilePosition, tileSize, this));
	}
}

int TileSlotContainer::getColorAmount(TileColor color)
{
	int colorAmount = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (tileSlots[i]->getColor() == color)
			++colorAmount;
	}
	return colorAmount;
}

void TileSlotContainer::highlight(int amount, slotHighlightColor color)
{
	int lineSize = tileSlots.size();
	for (int i = 0; i < amount && i < lineSize; ++i)
	{
		tileSlots[i]->highlight(color);
	}
}