#include "MenuStar.h"


MenuStar::MenuStar()
{
	rect.setFillColor(sf::Color::White);
}


MenuStar::~MenuStar()
{
}


void MenuStar::setWindow(sf::RenderWindow* window) {
	MenuStar::window = window;
}

void MenuStar::setPosition(int x, int y) {
	rect.setPosition(x, y);
}

void MenuStar::setSize(float size) {
	rect.setSize(sf::Vector2f(size, size));
}

void MenuStar::setDirection(float direction) {
	MenuStar::diretion = direction;
}

// Calculate a (wrong) initial direction for the stars
void MenuStar::setInitialDirection() {
	sf::Vector2u windowSize = window->getSize();
	sf::Vector2f pos = rect.getPosition();
	setDirection(-atan2(windowSize.x / 2 - pos.x, windowSize.y / 2 - pos.y));
}

void MenuStar::move() {
	// Update the position
	sf::Vector2f pos = rect.getPosition();
	rect.setPosition(pos.x + speed * cos(diretion), pos.y + speed * sin(diretion));

	// set the speed to the max of calculateSpeed and some value
	// so that the stars have a min speed
	speed = fmax(calculateSpeed(pos.x, pos.y), 1);

	// Get the size of the drawable window
	sf::Vector2u windowSize = window->getSize();

	// If the star passes outside the screen, reset it to the center
	if (pos.x > windowSize.x || pos.x < 0 || pos.y > windowSize.y || pos.y < 0) {
		setPosition(window->getSize().x / 2, window->getSize().y / 2);
		setDirection(((double)rand() / RAND_MAX) * 3.1415 * 2);
	}
}

// Calculate sqauredDist from center and divide by some constant for speed
float MenuStar::calculateSpeed(float x, float y) {
	sf::Vector2u windowSize = window->getSize();
	float squaredDist = pow(windowSize.x / 2 - x, 2) + pow(windowSize.y / 2 - y, 2);
	return squaredDist / 2000;
}

// render method for the star
void MenuStar::render() {
	// make the stars in the middle smaller, otherwise it looks funky
	// quite inefficient due to copying of the object, probably should keep original
	// object and adjust it's size parameters
	/*if (speed < 0.8) {
		sf::Vector2f oldSize = rect.getSize();
		float size = 1 +((double)rand() / RAND_MAX)*1.5;
		rect.setSize(sf::Vector2f(size,size));
		window->draw(rect);
		rect.setSize(oldSize);
	}
	else {*/
		window->draw(rect);
	//}
}