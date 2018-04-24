#include "Player.h"
#include <iostream>
Player::Player()
{
	sprite.setPosition(400, 300);
}


Player::~Player()
{
}

void Player::setTexture(sf::String filename) {
	tex = sf::Texture();

	if (!tex.loadFromFile(filename)) {
		// error
	}
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(400 - 36/2, 450 - 54/2));
	
	std::cout << "texture address loaded:   " << "0x" << &tex << "\n";
}

void Player::setTextureRect(sf::IntRect rect) {
	sprite.setTextureRect(rect);
}

void Player::render(sf::RenderWindow* window) {
	window->draw(sprite);
}

void Player::setPosition(float x, float y) {
	Player::x = x;
	Player::y = y;
}

void Player::move() {
	x += vx;
	y += vy;
}
