#include "Grid.h"
#include "GameConfig.h"
#include <stack>
#include <cstdlib>
#include <ctime>

Grid::Grid() : score() {
    initialize();
}

void Grid::initialize() {
    std::srand(static_cast<unsigned>(std::time(0)));
    for (int index = 0; index < GridConfig::GRID_SIZE; ++index) {
        tiles[index] = Tile(Tile::getTileColorByInt(std::rand() % 3 + 1));
    }
}

int Grid::getTileIndex(int x, int y) const {
    return x * GridConfig::GRID_ROWS_NUMBER + y;
}

bool Grid::hasAdjacentSameColor(int x, int y) const {
    TileColor color = tiles[getTileIndex(x, y)].getColor();
    for (const auto& dir : directions) {
        int nextTileX = x + dir.first;
        int nextTileY = y + dir.second;
        if (nextTileX >= 0 && nextTileY >= 0 &&
            nextTileX < GridConfig::GRID_COLUMNS_NUMBER && nextTileY < GridConfig::GRID_ROWS_NUMBER &&
            tiles[getTileIndex(nextTileX, nextTileY)].getColor() == color) {
            return true;
        }
    }
    return false;
}

bool Grid::canEliminateTiles() const {
    for (int i = 0; i < GridConfig::GRID_COLUMNS_NUMBER; ++i) {
        for (int j = 0; j < GridConfig::GRID_ROWS_NUMBER; ++j) {
            if (tiles[getTileIndex(i, j)].getColor() != TileColor::Eliminated &&
                hasAdjacentSameColor(i, j)) {
                return true;
            }
        }
    }
    return false;
}

TileColor Grid::getNextTileColor(const TileColor& currentTileColor) {
    switch (currentTileColor) {
    case TileColor::Cyan:
        return TileColor::Magenta;
    case TileColor::Magenta:
        return TileColor::Yellow;
    case TileColor::Yellow:
        return TileColor::Cyan;
    default:
        return TileColor::Cyan;
    }
}

bool Grid::eliminateTiles(int x, int y) {
    TileColor color = tiles[getTileIndex(x, y)].getColor();
    if (color == TileColor::Eliminated || !hasAdjacentSameColor(x, y))
        return false;

    std::stack<std::pair<int, int>> tileStack;
    tileStack.push({ x, y });
    std::vector<std::pair<int, int>> removedTiles;

    // Eliminate Tiles
    while (!tileStack.empty()) {
        int topTileX = tileStack.top().first;
        int topTileY = tileStack.top().second;
        tileStack.pop();

        if (tiles[getTileIndex(topTileX, topTileY)].getColor() == color) {
            tiles[getTileIndex(topTileX, topTileY)].setColor(TileColor::Eliminated);
            removedTiles.push_back({ topTileX, topTileY });

            for (const auto& dir : directions) {
                int nx = topTileX + dir.first;
                int ny = topTileY + dir.second;
                if (nx >= 0 && ny >= 0 &&
                    nx < GridConfig::GRID_COLUMNS_NUMBER && ny < GridConfig::GRID_ROWS_NUMBER &&
                    tiles[getTileIndex(nx, ny)].getColor() == color) {
                    tileStack.push({ nx, ny });
                }
            }
        }
    }

    score.addScore(removedTiles.size());

    // Change color of adjacent tiles
    for (const auto& tile : removedTiles) {
        for (const auto& dir : directions) {
            int nx = tile.first + dir.first;
            int ny = tile.second + dir.second;
            if (nx >= 0 && ny >= 0 &&
                nx < GridConfig::GRID_COLUMNS_NUMBER && ny < GridConfig::GRID_ROWS_NUMBER &&
                tiles[getTileIndex(nx, ny)].getColor() != TileColor::Eliminated) {
                tiles[getTileIndex(nx, ny)].setColor(getNextTileColor(tiles[getTileIndex(nx, ny)].getColor()));
            }
        }
    }
    return true;
}

void Grid::draw(sf::RenderWindow& window) {
    for (int i = 0; i < GridConfig::GRID_COLUMNS_NUMBER; ++i) {
        for (int j = 0; j < GridConfig::GRID_ROWS_NUMBER; ++j) {
            sf::RectangleShape tileShape(sf::Vector2f(TileConfig::TILE_SIZE - 1, TileConfig::TILE_SIZE - 1));
            tileShape.setPosition((float)i * TileConfig::TILE_SIZE, (float)j * TileConfig::TILE_SIZE + WindowConfig::WINDOW_VERTICAL_OFFSET);
            tileShape.setFillColor(Tile::getSFColorFromTileColor(tiles[getTileIndex(i, j)].getColor()));
            window.draw(tileShape);
        }
    }
}

int Grid::getScore() {
    return score.getScore();
}