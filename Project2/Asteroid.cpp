#include "Asteroid.h"
#include <iostream>
Asteroid::Asteroid()
{
	sprite.setPosition(400, 300);
	sprite.setOrigin(36 / 2, 60 / 2);
}


Asteroid::~Asteroid()
{
}

void Asteroid::isAccelerating(bool accel) {
	accelerating = accel;
}

void Asteroid::setTexture(sf::String filename) {
	tex = sf::Texture();

	if (!tex.loadFromFile(filename)) {
		// error
	}
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(400, 450));

}

void Asteroid::setTextureRect(sf::IntRect rect) {
	sprite.setTextureRect(rect);
}

void Asteroid::render(sf::RenderWindow* window) {
	sprite.setRotation(rotation);

	if (accelerating) {
		if (frameCount > 1) {
			std::cout << currentSprite;
			sprite.setTextureRect(sf::IntRect(0, currentSprite * 60, 36, 60));
			currentSprite += 1;
			if (currentSprite > 20) {
				currentSprite = 1;
			}
			frameCount = 0;
		}
		else {
			frameCount++;
		}
	}
	else {
		sprite.setTextureRect(sf::IntRect(0, 0, 36, 60));
		frameCount = 21;
	}

	window->draw(sprite);
}

float Asteroid::getX() {
	return position.x;
}

float Asteroid::getY() {
	return position.y;
}

float Asteroid::getXVelocity() {
	return velocity.x;
}

float Asteroid::getYVelocity() {
	return velocity.y;
}

float Asteroid::getXAcceleration() {
	return acceleration.x;
}

float Asteroid::getYAcceleration() {
	return acceleration.y;
}

float Asteroid::getRotation() {
	return rotation;
}

void Asteroid::setXPosition(float x) {
	position.x = x;
}

void Asteroid::setYPosition(float y) {
	position.y = y;
}

void Asteroid::setXVelocity(float x) {
	velocity.x = x;
}

void Asteroid::setYVelocity(float y) {
	velocity.y = y;
}

void Asteroid::setXAcceleration(float x) {
	acceleration.x = x;
}

void Asteroid::setYAcceleration(float y) {
	acceleration.y = y;
}

void Asteroid::setRotation(float rot) {
	rotation = rot;
}

void Asteroid::move() {
	position.x += velocity.x;
	position.y += velocity.y;

	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
}

