#include "Scorer.h"

Scorer::Scorer() : score(0) {};

int Scorer::getScore() {
	return score;
}

void Scorer::addScore(int points) {
	score += points;
}