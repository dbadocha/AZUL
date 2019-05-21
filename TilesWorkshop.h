#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QPainter>

#include "Tile.h"
#include "ui_TilesWorkshop.h"
//#include "Tiles.h"
//#include "Enum.h"

class TilesWorkshop : public QWidget
{
	Q_OBJECT

public:
	explicit TilesWorkshop(QWidget *parent = nullptr);
	~TilesWorkshop();
	//void Refill(Tiles *GameTiles);
	void ClearWorkshop();
	void paintEvent(QPaintEvent *);

private:
	Ui::TilesWorkshop ui;
	Tile *WorkshopTiles[4];
	void addLayout();
	void initTiles();
};

