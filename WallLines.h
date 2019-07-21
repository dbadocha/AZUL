#pragma once

#include <QObject>

class WallLines : public QObject
{
	Q_OBJECT

public:
	WallLines(QObject *parent);
	~WallLines();
};
