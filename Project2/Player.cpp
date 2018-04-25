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

float Player::getXAcceleration() {
	return acceleration.x;
}

float Player::getYAcceleration() {
	return acceleration.y;
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

void Player::move() {
	position.x += velocity.x;
	position.y += velocity.y;

	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
}
