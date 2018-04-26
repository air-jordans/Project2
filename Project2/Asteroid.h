#pragma once
#include <SFML/Graphics.hpp>

class Asteroid
{
public:
	Asteroid();
	~Asteroid();
	void render(sf::RenderWindow* window);
	void move();
	float getX();
	float getY();
	float getXVelocity();
	float getYVelocity();
	float getXAcceleration();
	float getYAcceleration();
	float getRotation();
	void setXVelocity(float x);
	void setYVelocity(float y);
	void setXPosition(float x);
	void setYPosition(float y);
	void setXAcceleration(float x);
	void setYAcceleration(float y);
	void setRotation(float rot);
	void setTextureRef(sf::Texture* tex);
	void setTextureRect(sf::IntRect rect);
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Texture* tex = 0;
	sf::Sprite sprite;
	float rotation = 0;
};
