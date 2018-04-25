#include "GameStar.h"
#include <iostream>


GameStar::GameStar()
{
	rect.setFillColor(sf::Color::White);
}


GameStar::~GameStar()
{
}

void GameStar::setWindow(sf::RenderWindow* window) {
	GameStar::window = window;
}

void GameStar::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
	rect.setPosition(position);
}

float GameStar::getX() {
	return position.x;
}

float GameStar::getY() {
	return position.y;
}

float GameStar::getVDiffPercent() {
	return vdiff;
}

void GameStar::setVDiffPercent(float vdiff) {
	GameStar::vdiff = vdiff;
}

void GameStar::setSize(float size) {
	rect.setSize(sf::Vector2f(size, size));
}

// render method for the star
void GameStar::render() {
	window->draw(rect);
}