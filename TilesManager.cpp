#include "TilesManager.h"

TilesManager::TilesManager(QObject *parent)
	: QObject(parent)
{
	for (TileColor color : TileColorIterator())
	{
		TilesPouch[static_cast<int>(color) - 1].Color = color;
		TilesBin[static_cast<int>(color) - 1].Color = color;
		TilesPouch[static_cast<int>(color) - 1].TilesCount = 20;
		TilesBin[static_cast<int>(color) - 1].TilesCount = 0;
	}
}

TilesManager::~TilesManager()
{
}


TileColor TilesManager::DrawTile()
{
	int PouchTitleAmount = GetTilesCount();
	if (PouchTitleAmount < 1)
		TilesManager::RefillPouch();

	int value = rand() % PouchTitleAmount + 1;
	for (int i = 0, count = 0; i < 5; i++) {
		count += TilesPouch[i].TilesCount;
		if (value <= count) {
			TilesPouch[i].TilesCount -= 1;
			return TilesPouch[i].Color;
		}
	}
	return TileColor::NONE;
}

void TilesManager::ReturnTilesToBin(TileColor color, int amount)
{
	TilesBin[static_cast<int>(color) - 1].TilesCount += amount;
}

int TilesManager::GetTilesCount()
{
	int TilesCount = 0;
	for (int i = 0; i < 5; i++)
		TilesCount += TilesPouch[i].TilesCount;
	return TilesCount;
}

void TilesManager::RefillPouch()
{
	for (int i = 0; i < 5; i++) {
		TilesPouch[i].TilesCount += TilesBin[i].TilesCount;
		TilesBin[i].TilesCount = 0;
	}
}

std::string TilesManager::getTilesPouch()
{
	std::string tmp = "TilesPouch:\n";
	for (int i = 0; i < 5; ++i) {
		tmp += TilesPouch[i].Color;
		tmp += std::to_string(TilesPouch[i].TilesCount);
		tmp += '\n';
	}
	tmp += '\n';
	return tmp;
}

std::string TilesManager::getTilesBin()
{
	std::string tmp = "TilesBin:\n";
	for (int i = 0; i < 5; ++i) {
		tmp += TilesBin[i].Color;
		tmp += std::to_string(TilesBin[i].TilesCount);
		tmp += '\n';
	}
	tmp += '\n';
	return tmp;
}