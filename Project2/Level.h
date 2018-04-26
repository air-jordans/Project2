#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "Player.h"
#include "GameStar.h"
#include "CompletionBar.h"
#include "Asteroid.h"
class Level {
public:
	Level();
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	
	bool isAlive();
	void levelLoopInterface();
	float speedX = 0;
private:
	int finishLine = 10000;
	long gameTime = 0;
	bool alive = true;
	bool paused = true;
	bool checkFinish();
	void update();
	void handleInput();
	void updateAsteroids();
	void render();
	void handleGameMenuInput();
	void renderGameMenu();
	void renderAsteroids();
	void updateBackground();
	void drawBackground();
	void drawTimer();
	void initStars();
	void initGameMenu();
	void initCompletionBar();
	void initTimerText();
	void initAsteroids();
	void setFinish(int fin);
	void setMusic(sf::String filename);
	void exitLevel();
	void beginDraw();
	void endDraw();

	Player* player = 0;
	Input* input;
	CompletionBar cb;
	sf::Music levelMusic;
	sf::RenderWindow* window;
	sf::Text timerDisplay;
	sf::Font arial;
	sf::Texture gameMenuTex;
	sf::Sprite gameMenu;
	sf::Clock timer;
	std::vector<GameStar> stars;
	std::vector<Asteroid> asteroids;
};