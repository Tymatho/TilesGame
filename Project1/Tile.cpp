#include "Tile.h"

Tile::Tile(const TileColor& color) : color(color) {}

TileColor Tile::getColor() const {
	return color;
}

void Tile::setColor(const TileColor& newColor) {
	color = newColor;
}

sf::Color Tile::getSFColorFromTileColor(const TileColor& tileColor) {
	switch (tileColor) {
	case TileColor::Yellow: 
		return sf::Color::Yellow;
	case TileColor::Magenta: 
		return sf::Color::Magenta;
	case TileColor::Cyan: 
		return sf::Color::Cyan;
	case TileColor::Eliminated: 
		return sf::Color::Black;
	default: return sf::Color::Black;
	}
}

TileColor Tile::getTileColorByInt(int color) {
	switch (color) {
	case 1: 
		return TileColor::Yellow;
	case 2: 
		return TileColor::Magenta;
	case 3: 
		return TileColor::Cyan;
	case 0: 
		return TileColor::Eliminated;
	default: 
		return TileColor::Eliminated;
	}
}