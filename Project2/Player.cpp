#include "Player.h"
#include <iostream>
Player::Player()
{
	sprite.setPosition(400, 300);
	sprite.setOrigin(36 / 2, 60 / 2);
}


Player::~Player()
{
}

void Player::isAccelerating(bool accel) {
	accelerating = accel;
}

void Player::setTexture(sf::String filename) {
	tex = sf::Texture();

	if (!tex.loadFromFile(filename)) {
		// error
	}
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(400, 450));
	
}

void Player::setTextureRect(sf::IntRect rect) {
	sprite.setTextureRect(rect);
}

void Player::render(sf::RenderWindow* window) {
	sprite.setRotation(rotation);

	if (accelerating) {
		if (frameCount > 1) {
			std::cout << currentSprite;
			sprite.setTextureRect(sf::IntRect(0, currentSprite * 60, 36, 60));
			currentSprite+=1;
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
		sprite.setTextureRect(sf::IntRect(0,0,36,60));
		frameCount = 21;
	}

	window->draw(sprite);
}

float Player::getX() {
	return position.x;
}

float Player::getY() {
	return position.y;
}

float Player::getXVelocity() {
	return velocity.x;
}

float Player::getYVelocity() {
	return velocity.y;
}

float Player::getXAcceleration() {
	return acceleration.x;
}

float Player::getYAcceleration() {
	return acceleration.y;
}

float Player::getRotation() {
	return rotation;
}

void Player::setXPosition(float x) {
	position.x = x;
}

void Player::setYPosition(float y) {
	position.y = y;
}

void Player::setXVelocity(float x) {
	velocity.x = x;
}

void Player::setYVelocity(float y) {
	velocity.y = y;
}

void Player::setXAcceleration(float x) {
	acceleration.x = x;
}

void Player::setYAcceleration(float y) {
	acceleration.y = y;
}

void Player::setRotation(float rot) {
	rotation = rot;
}

void Player::move() {
	position.x += velocity.x;
	position.y += velocity.y;

	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
}
