#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
class Star
{
public:
	Star();
	~Star();

	void setWindow(sf::RenderWindow* window);
	void setPosition(int x, int y);
	void setSize(float size);
	void setDirection(float direction);
	void setInitialDirection();
	void move();
	void render();
private:
	float calculateSpeed(float x, float y);
	sf::RenderWindow* window;
	sf::RectangleShape rect;
	float speed = 0;
	float diretion = 0;
};

