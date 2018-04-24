#include "Level.h"
#include "Input.h"
Level::Level() {

}

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	delete player;
	player = new Player();
	player->setPosition(0, 0);
	player->setTexture("res/player/player.png");
	player->setTextureRect(sf::IntRect(0,0,36,54));
	
	input = in;
	window = hwnd;
}
Level::~Level()
{
}

void Level::update()
{
	// Update logic
}

void Level::handleInput()
{
	// if space is pressed output to console
	if (input->isKeyDown(sf::Keyboard::D))
	{
		input->setKeyUp(sf::Keyboard::D);
		std::cout << "D was pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::X)) {
		input->setKeyUp(sf::Keyboard::X);
		std::cout << "X was pressed\n";
		alive = false;
	}
}


bool Level::isAlive() {
	return alive;
}

void Level::levelLoopInterface() {
	update();
	handleInput();
	render();
}

void Level::render()
{
	beginDraw();

	player->render(window);
	
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