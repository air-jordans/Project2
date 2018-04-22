#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "MenuButton.h"
#include "Star.h"
class Menu
{
public:
	Menu(sf::RenderWindow* hwnd, Input* inp);
	~Menu();
	void initButtons();
	void initStars();
	void render();
	void renderBackground();
	void handleInput();
	void menuLoopInterface();
private:
	Input* input;
	sf::RenderWindow* window;
	sf::Sprite splash;
	MenuButton playButton;
	MenuButton settingsButton;
	MenuButton scoresButton;
	MenuButton exitButton;
	std::vector<Star> menuStars;
	int currentSelected = 0;
	const int play = 0;
	const int options = 1;
	const int scores = 2;
	const int exit = 3;
};

