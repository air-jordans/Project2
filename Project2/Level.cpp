#include "Level.h"
#include "Input.h"
#include "Player.h"
Level::Level() {

}

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	input = in;
	window = hwnd;


	delete player;
	player = new Player();
	player->setPosition(0, 0);
	player->setTexture("res/player/player.png");
	player->setTextureRect(sf::IntRect(0,0,36,60));

	initStars();
	
	
}
Level::~Level()
{
}


void Level::initStars() {
	stars = std::vector<GameStar>(250);

	for (int i = 0; i < stars.size(); i++) {
		stars[i].setWindow(window);
		stars[i].setPosition(((double) rand() / RAND_MAX) * window->getSize().x, ((double)rand() / RAND_MAX) * window->getSize().y);
		stars[i].setVDiffPercent((double) rand() / RAND_MAX);
		stars[i].setSize(((double)rand() / RAND_MAX) * 2);
	}

}

void Level::updateBackground() {
	for (int i = 0; i < stars.size(); i++) {
		float newX = stars[i].getX() + player->getXVelocity() * stars[i].getVDiffPercent();
		float newY = stars[i].getY() + player->getYVelocity() * stars[i].getVDiffPercent();
		stars[i].setPosition(newX, newY);
	
		if (stars[i].getX() < 0) {
			stars[i].setPosition(window->getSize().x,((double) rand() / RAND_MAX) * window->getSize().y);
		}
		else if (stars[i].getX() > window->getSize().x) {
			stars[i].setPosition(0, ((double)rand() / RAND_MAX) * window->getSize().y);
		}
		else if (stars[i].getY() < 0) {
			stars[i].setPosition(((double)rand() / RAND_MAX) * window->getSize().x, window->getSize().y);
		}
		else if (stars[i].getY() > window->getSize().y) {
			stars[i].setPosition(((double)rand() / RAND_MAX) * window->getSize().x, 0);
		}
	}
}

void Level::update()
{
	// Update logic
	player->move();
	updateBackground();
}

void Level::handleInput()
{
	// if space is pressed output to console
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		player->setAcceleration(0.0,0.1);
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		player->setAcceleration(0.0, -0.1);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		player->setAcceleration(-0.1, 0.0);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		player->setAcceleration(0.1, -0.0);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		player->setAcceleration(0.0, 0.0);
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		player->setAcceleration(0.0, 0.0);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		player->setAcceleration(0.0, 0.0);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		player->setAcceleration(0.1, 0.0);
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

	drawBackground();
	player->render(window);

	endDraw();
}

void Level::drawBackground() {
	for (int i = 0; i < stars.size(); i++) {
		stars[i].render();
	}
}

void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}
void Level::endDraw()
{
	window->display();
}