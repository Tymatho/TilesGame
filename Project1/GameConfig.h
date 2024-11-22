#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <string>
#include <utility>

// static constexpr to export constants everywhere by calling TileConfig::VALUE
// constexpr is a constant computed with the compiler and not with the code
struct TileConfig {
    static constexpr int TILE_COLUMNS_NUMBER = 6;
    static constexpr int TILE_ROWS_COLUMN = 6;
    static constexpr int TILE_SIZE = TILE_COLUMNS_NUMBER * TILE_ROWS_COLUMN;
};

struct GridConfig {
    static constexpr int GRID_COLUMNS_NUMBER = 20; //Number of columns
    static constexpr int GRID_ROWS_NUMBER = 20;  // Number of rows
    static constexpr int GRID_SIZE = GRID_COLUMNS_NUMBER * GRID_ROWS_NUMBER;
};

struct WindowConfig {
    static constexpr int WINDOW_VERTICAL_OFFSET = 75;
    static constexpr int WINDOW_COLUMNS_NUMBER = TileConfig::TILE_SIZE * GridConfig::GRID_COLUMNS_NUMBER;
    static constexpr int WINDOW_ROWS_NUMBER = TileConfig::TILE_SIZE * GridConfig::GRID_ROWS_NUMBER + WINDOW_VERTICAL_OFFSET;
    static constexpr int WINDOW_SIZE = WINDOW_COLUMNS_NUMBER * WINDOW_ROWS_NUMBER;
    static constexpr const char* WINDOW_TITLE = "Tiles Game";
};

struct AudioConfig {
    static constexpr const char* BACKGROUND_MUSIC = "Sounds/backgroundMusic.mp3";
    static constexpr const char* TILES_DESTROYED_SOUND_1 = "Sounds/tilesDestroyed1.ogg";
    static constexpr const char* TILES_DESTROYED_SOUND_2 = "Sounds/tilesDestroyed2.ogg";
    static constexpr const char* TILES_DESTROYED_SOUND_3 = "Sounds/tilesDestroyed3.ogg";
    static constexpr const char* TILES_DESTROYED_SOUND_4 = "Sounds/tilesDestroyed4.ogg";
    static constexpr const char* WIN_MUSIC = "Sounds/winMusic.wav";
};

struct Directions {
    static constexpr std::pair<int, int> Right = { 1, 0 };
    static constexpr std::pair<int, int> Left = { -1, 0 };
    static constexpr std::pair<int, int> Up = { 0, -1 };
    static constexpr std::pair<int, int> Down = { 0, 1 };
};

#endif