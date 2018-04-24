#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::RenderWindow* hwnd);
	Player();
	~Player();
	void render(sf::RenderWindow* window);
	void move();
	void setPosition(float x, float y);
	void setTexture(sf::String filename);
	void setTextureRect(sf::IntRect rect);
private:
	float x = 0;
	float y = 0;
	float vx = 0;
	float vy = 0;
	float ax = 0;
	float ay = 0;
	sf::Texture tex;
	sf::Sprite sprite;
};

