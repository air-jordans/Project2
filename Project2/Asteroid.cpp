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
void Asteroid::setTextureRef(sf::Texture* tex) {
	sprite.setTexture((*tex));
}

void Asteroid::setTextureRect(sf::IntRect rect) {
	sprite.setTextureRect(rect);
}

void Asteroid::render(sf::RenderWindow* window) {
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

