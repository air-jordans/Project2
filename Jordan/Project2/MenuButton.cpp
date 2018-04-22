#include "MenuButton.h"

MenuButton::MenuButton(sf::RenderWindow* hwnd)
{
	transparentRect.setFillColor(sf::Color(255, 255, 255, 100));

	// Initialize Menu
	window = hwnd;
}


MenuButton::~MenuButton()
{
}

void MenuButton::setTexture(sf::String str) {
	if (!tex.loadFromFile(str)) {
		// error
	}
	sprite.setTexture(tex);
}

void MenuButton::setSelected(bool select) {
	selected = select;
}

bool MenuButton::isSelected() {
	return selected;
}


void MenuButton::setRect(sf::IntRect rect) {
	transparentRect.setSize(sf::Vector2f(rect.width, rect.height));
	transparentRect.setPosition(rect.left, rect.top);
	sprite.setPosition(rect.left, rect.top);
}

void MenuButton::render() {
	window->draw(sprite);
	if (selected) {
		window->draw(transparentRect);
	}
}

