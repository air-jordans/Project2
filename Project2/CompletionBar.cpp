#include "CompletionBar.h"



CompletionBar::CompletionBar()
{
	rect.setPosition(sf::Vector2f(792,0));
	rect.setSize(sf::Vector2f(2,600));
}


CompletionBar::~CompletionBar()
{
}

void CompletionBar::setRenderWindow(sf::RenderWindow* hwnd) {
	window = hwnd;
}

void CompletionBar::render() {
	window->draw(rect);
}

void CompletionBar::setColor(sf::Color color) {
	rect.setFillColor(color);
}

void CompletionBar::setPercentage(float percent) {
	rect.setPosition(sf::Vector2f(798, 600 - percent * 600));
	rect.setSize(sf::Vector2f(2, percent * 600));
}
