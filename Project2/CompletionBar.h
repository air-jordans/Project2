#pragma once
#include "SFML/Graphics.hpp"
class CompletionBar
{
public:
	CompletionBar();
	~CompletionBar();
	void setRenderWindow(sf::RenderWindow* hwnd);
	void render();
	void setPercentage(float percent);
	void setColor(sf::Color color);
private:
	float percentage = 0;
	sf::RectangleShape rect;
	sf::RenderWindow* window;
};

