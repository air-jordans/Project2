#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();
private:
	sf::RectangleShape rect;
	sf::CircleShape circle;
	float speed;
	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	sf::RectangleShape rect4;
	sf::Font arial;
	sf::Text text1;
	sf::RenderWindow* window;
	sf::Event event;
	void beginDraw();
	void endDraw();
};