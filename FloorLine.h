#pragma once

#include <QObject>

class FloorLine : public QObject
{
	Q_OBJECT

public:
	FloorLine(QObject *parent);
	~FloorLine();
};
