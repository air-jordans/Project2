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

	
	bool isAlive();
	void levelLoopInterface();
	float speedX = 0;
private:
	bool alive = true;
	bool paused = true;
	void update();
	void handleInput();
	void render();
	void handleGameMenuInput();
	void renderGameMenu();
	void updateBackground();
	void drawBackground();
	void initStars();
	void initGameMenu();
	void setMusic(sf::String filename);
	void beginDraw();
	void endDraw();

	Player* player = 0;
	Input* input;
	sf::Music levelMusic;
	sf::RenderWindow* window;
	sf::Texture gameMenuTex;
	sf::Sprite gameMenu;
	std::vector<GameStar> stars;
};