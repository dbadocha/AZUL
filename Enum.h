#pragma once

#include <map>
#include <iostream>

//**************************************************************************
template <typename C, C beginVal, C endVal>
class Iterator {
	typedef typename std::underlying_type<C>::type val_t;
	int val = 0;
public:
	Iterator() : val(static_cast<val_t>(beginVal)) {}
	Iterator(const C & f) : val(static_cast<val_t>(f)) {}

	Iterator operator++() {
		++val;
		return *this;
	}

	C operator*() { return static_cast<C>(val); }

	Iterator begin() { return *this; } //default ctor is good

	Iterator end() {
		static const Iterator endIter = ++Iterator(endVal); // cache it
		return endIter;
	}

	bool operator!=(const Iterator& i) { return val != i.val; }
};

//**************************************************************************
enum class TileColor { NONE, BLUE, BLACK, WHITE, RED, YELLOW };

static std::map<TileColor, std::string> TileColorMap = {
	{TileColor::NONE, "NONE"},
	{TileColor::BLUE, "BLUE"},
	{TileColor::BLACK, "BLACK"},
	{TileColor::WHITE, "WHITE"},
	{TileColor::RED, "RED"},
	{TileColor::YELLOW, "YELLOW"}
};

inline std::ostream& operator<< (std::ostream& out, const TileColor f)
{
	if (TileColorMap.find(f) != TileColorMap.end())
		return out << TileColorMap[f];
	return out << "ERROR";
}

inline std::string operator+=(std::string& in, const TileColor f) {
	std::string nowy = "";
	return in += (TileColorMap[f] + ":\t");
}

typedef Iterator<TileColor, TileColor::BLUE, TileColor::YELLOW> TileColorIterator;

//**************************************************************************

struct TileField {
	TileColor Color = {};
	int TilesCount = {};
};