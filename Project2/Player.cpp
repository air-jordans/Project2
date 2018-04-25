#include "Player.h"
#include <iostream>
Player::Player()
{
	sprite.setPosition(400, 300);
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
	sprite.setPosition(sf::Vector2f(400 - 36/2, 450 - 60/2));
	
	std::cout << "texture address loaded:   " << "0x" << &tex << "\n";
}

void Player::setTextureRect(sf::IntRect rect) {
	sprite.setTextureRect(rect);
}

void Player::render(sf::RenderWindow* window) {
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

void Player::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

void Player::setVelocity(float x, float y) {
	velocity.x = x;
	velocity.y = y;
}

void Player::move() {
	position.x += velocity.x;
	position.y += velocity.y;
}
