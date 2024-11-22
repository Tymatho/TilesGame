#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "GameConfig.h"
#include "AudioManager.h"

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void render();
	void checkGameOver();
	bool isCoordinatesValid(int x, int y);
	void drawText(const char* text, float x, float y);

private:
	Grid grid;
	AudioManager audio;
	sf::RenderWindow window;
	bool gameOver;
};

#endif // GAME_H
