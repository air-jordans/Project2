#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "Player.h"
#include "GameStar.h"
class Level {
public:
	Level();
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void render();
	bool isAlive();
	void levelLoopInterface();
	float speedX = 0;
private:
	void update();
	void handleInput();
	void updateBackground();
	void drawBackground();
	void initStars();
	void setMusic(sf::String filename);
	Player* player = 0;
	sf::RenderWindow* window;
	void beginDraw();
	void endDraw();
	bool alive = true;
	Input* input;
	std::vector<GameStar> stars;
	sf::Music levelMusic;
};