#pragma once
#include "SFML/Graphics.hpp"
class GameStar
{
public:
	GameStar();
	~GameStar();
	void setWindow(sf::RenderWindow* window);
	void setPosition(float x, float y);
	void setVDiffPercent(float vdiff);
	void setSize(float size);
	void move();
	void render();
	float getX();
	float getY();
	float getVDiffPercent();
private:
	float vdiff;
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::RenderWindow* window;
};

