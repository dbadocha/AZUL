#pragma once

#include <QWidget>
#include <QPainter>

#include "Enum.h"
#include "ui_Tile.h"

class Tile : public QWidget
{
	Q_OBJECT

public:
	Tile(TileColor color, QWidget *parent = nullptr);
	~Tile();
	void changeColor(TileColor color);

private:
	QWidget *m_parent = nullptr;
	Ui::Tile ui;
	void paintEvent(QPaintEvent *);
	TileColor m_color;
};
