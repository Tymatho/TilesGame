#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum class TileColor {
	Eliminated = 0,
	Yellow = 1,
	Magenta = 2,
	Cyan = 3
};

class Tile {
public:
	Tile(const TileColor& color = TileColor::Cyan);
	void setColor(const TileColor& color);
	static sf::Color getSFColorFromTileColor(const TileColor& colorEnum);
	static TileColor getTileColorByInt(int color);
	TileColor getColor() const;

private:
	TileColor color;
};

#endif
