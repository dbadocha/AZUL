#pragma once

#include <QObject>

class PatternLines : public QObject
{
	Q_OBJECT

public:
	PatternLines(QObject *parent);
	~PatternLines();
};
