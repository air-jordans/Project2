#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	void setMusic(sf::String filename);
	void playMusic();
	void stopMusic();
	bool playButtonSelected = false;
private:
	Input* input;
	sf::RenderWindow* window;
	MenuButton playButton;
	MenuButton settingsButton;
	MenuButton scoresButton;
	MenuButton exitButton;
	MenuButton menuInstructions;
	MenuButton splash;
	std::vector<Star> menuStars;
	int currentSelected = 0;
	const int play = 0;
	const int options = 1;
	const int scores = 2;
	const int exit = 3;
	sf::Music menuMusic;
};

