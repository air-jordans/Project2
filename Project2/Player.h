#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
	void render(sf::RenderWindow* window);
	void move();
	void isAccelerating(bool accel);
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
	void setTexture(sf::String filename);
	void setTextureRect(sf::IntRect rect);
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Texture tex;
	sf::Sprite sprite;
	
	int frameCount = 0;
	int currentSprite = 0;
	bool accelerating = false;
	float rotation = 0;
};

