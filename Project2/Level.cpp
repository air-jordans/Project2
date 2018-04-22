#include "Level.h"
#include "Input.h"
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rect1.setSize(sf::Vector2f(100, 100));
	rect1.setPosition(400, 300);
	rect1.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(50, 50));
	rect2.setPosition(425, 325);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(25, 25));
	rect3.setPosition(437, 337);
	rect3.setFillColor(sf::Color::Blue);

	rect4.setSize(sf::Vector2f(40, 40));
	rect4.setPosition(600, 400);
	rect4.setFillColor(sf::Color::Green);

	arial.loadFromFile("arial.ttf");

	text1.setFont(arial);
	text1.setString("Hello World");
	text1.setCharacterSize(24);
	//text1.setColor()
	
	circle.setRadius(15);
	circle.setPosition(300,300);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Magenta);
	//circle.setOutlineThickness(2.f);

	//speed = 100.f;
	
	window = hwnd;
}
Level::~Level()
{
}
void Level::update()
{

	rect4.setOrigin(5, 20);
	
}
void Level::handleInput()
{
	Input input;
	// if space is pressed output to console
	if (input.isKeyDown(sf::Keyboard::D))
		{
			input.setKeyUp(sf::Keyboard::D);
			std::cout<< "D was pressed\n";
		}

	}
void Level::render()
{
	beginDraw();
	//renders the rectangle in the program
	window->draw(rect);
	//renders the circle in the program
	window->draw(circle);
	//window->draw(rect1);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(rect4);
	window->draw(text1);
	
	endDraw();
}
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}
void Level::endDraw()
{
	window->display();
}