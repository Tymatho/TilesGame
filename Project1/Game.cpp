#include "Game.h"
#include <string>

Game::Game()
	: window(sf::VideoMode(WindowConfig::WINDOW_COLUMNS_NUMBER, WindowConfig::WINDOW_ROWS_NUMBER), WindowConfig::WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close),
	gameOver(false), grid(), audio()
{
	sf::Image icon;
	if (icon.loadFromFile("Pictures/icon.png")) {
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}
	run();
}

void Game::run() {
	audio.playSound(AudioConfig::BACKGROUND_MUSIC, true, 35.00);
	while (window.isOpen()) {
		processEvents();
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (!gameOver && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			int x = event.mouseButton.x / TileConfig::TILE_SIZE;
			int y = (event.mouseButton.y - WindowConfig::WINDOW_VERTICAL_OFFSET) / TileConfig::TILE_SIZE;  // Ajustement avec le décalage
			if (isCoordinatesValid(x, y)) {
				if (grid.eliminateTiles(x, y)) {
					audio.playRandomTileDestroySound();
				}
			}
			checkGameOver();
		}
	}
}

void Game::render() {
	window.clear();
	std::string scoreText = "Score : " + std::to_string(grid.getScore());
	drawText(scoreText.c_str(), WindowConfig::WINDOW_COLUMNS_NUMBER / 4, 0);
	if (gameOver) {
		drawText("Game Over", WindowConfig::WINDOW_COLUMNS_NUMBER / 4, WindowConfig::WINDOW_ROWS_NUMBER / 2 - 25);
	}
	else {
		grid.draw(window);
	}

	window.display();
}

void Game::checkGameOver() {
	if (!grid.canEliminateTiles() && !gameOver) {
		gameOver = true;
		audio.stopSound(AudioConfig::BACKGROUND_MUSIC);
		audio.playSound(AudioConfig::WIN_MUSIC, true);
	}
}

bool Game::isCoordinatesValid(int x, int y) {
	return x >= 0 && x < GridConfig::GRID_COLUMNS_NUMBER && y >= 0 && y < GridConfig::GRID_ROWS_NUMBER;
}

void Game::drawText(const char* textToRender, float x, float y) {
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text(textToRender, font, 50);
	text.setFillColor(sf::Color::White);
	text.setPosition(x,y);
	window.draw(text);
}