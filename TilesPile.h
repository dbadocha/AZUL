#pragma once

#include <QWidget>

#include "ui_TilesPile.h"
#include "TilesManager.h"
#include "Enum.h"

class TilesPile : public QWidget
{
	Q_OBJECT

public:
	TilesPile(QWidget *parent = Q_NULLPTR);
	~TilesPile();
	void Print();
	void ReturnToBin(TilesManager &, TileColor);
	int TakeColor(TileColor &);

private:
	Ui::TilesPile ui;
	TileField TilesSet[5] = {};
	int test = 0;
	//Player *FirstPlayer = {Null};
};