#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Tile.h"
#include "GameConfig.h"
#include "Scorer.h"

class Grid {
public:
    Grid();
    bool canEliminateTiles() const;
    bool eliminateTiles(int x, int y);
    void draw(sf::RenderWindow& window);
    int getScore();

private:
    void initialize();
    bool hasAdjacentSameColor(int x, int y) const;
    int getTileIndex(int x, int y) const;
    TileColor getNextTileColor(const TileColor& currentColor);

private:
    //Use one array to speed up operations in memory
    Tile tiles[GridConfig::GRID_SIZE];
    std::pair<int, int> directions[4] = { Directions::Right, Directions::Left, Directions::Down, Directions::Up };
    Scorer score;;
};

#endif // GRID_H
