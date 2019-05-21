#pragma once

#include <QObject>
#include <string.h>

#include "Enum.h"

class TilesManager : public QObject
{
	Q_OBJECT

private:
	TileField TilesPouch[5] = {};
	TileField TilesBin[5] = {};

public:
	TilesManager(QObject *parent);
	~TilesManager();
	TileColor DrawTile();
	void ReturnTilesToBin(TileColor, int);
	int GetTilesCount();
	void RefillPouch();
	std::string getTilesPouch();
	std::string getTilesBin();
};