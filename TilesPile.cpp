#include "TilesPile.h"

TilesPile::TilesPile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	for (TileColor color : TileColorIterator()) {
		TilesSet[static_cast<int>(color) - 1].Color = color;
		TilesSet[static_cast<int>(color) - 1].TilesCount = 0;
	}
}

TilesPile::~TilesPile()
{
}


void TilesPile::ReturnToBin(TilesManager & oTiles, TileColor color)
{
	int tmp_count = TilesSet[static_cast<int>(color) - 1].TilesCount;
	oTiles.ReturnTilesToBin(color, tmp_count);
	TilesSet[static_cast<int>(color) - 1].TilesCount = 0;
}