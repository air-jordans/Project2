#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "MenuButton.h"
#include "MenuStar.h"
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
	int currentSelected = 0;
	const int PLAY = 0;
	const int OPTIONS = 1;
	const int SCORES = 2;
	const int EXIT = 3;
	Input* input;
	MenuButton playButton;
	MenuButton settingsButton;
	MenuButton scoresButton;
	MenuButton exitButton;
	MenuButton menuInstructions;
	MenuButton splash;
	sf::RenderWindow* window;
	sf::Music menuMusic;
	std::vector<MenuStar> menuStars;	
};

