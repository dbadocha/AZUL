#pragma once

#include <QObject>
#include <string.h>

#include "Enum.h"
//#include "TileSlotContainer.h"

class TilesManager : public QObject
{
	Q_OBJECT

private:
	TileField TilesPouch[5] = {};
	TileField TilesBin[5] = {};

	TileColor DrawColor();

public:
	TilesManager(QObject *parent);
	~TilesManager();
	void ReturnTilesToBin(TileColor, int);
	int GetTilesCount();
	void RefillPouch();
	std::string getTilesPouch();
	std::string getTilesBin();
};