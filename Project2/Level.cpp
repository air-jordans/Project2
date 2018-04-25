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
	player->setXPosition(0);
	player->setYPosition(0);
	player->setTexture("res/player/player.png");
	player->setTextureRect(sf::IntRect(0,0,36,60));

	initStars();
	initGameMenu();
	initCompletionBar();
	initTimerText();
	setMusic("res/music/level0.wav");
	

}
Level::~Level()
{
}

void Level::setMusic(sf::String filename) {
	if (!levelMusic.openFromFile(filename)) {
		// error
	}
	levelMusic.setVolume(10);
	levelMusic.setLoop(true);
}

void Level::setFinish(int fin) {
	finishLine = fin;
}

void Level::initGameMenu() {
	gameMenuTex = sf::Texture();
	if (!gameMenuTex.loadFromFile("res/pauseSplash.png")) {
		// error
	}
	gameMenu.setTexture(gameMenuTex);
	gameMenu.setPosition(sf::Vector2f(100,100));
}

void Level::initStars() {
	stars = std::vector<GameStar>(250);

	for (int i = 0; i < stars.size(); i++) {
		stars[i].setWindow(window);
		stars[i].setPosition(((double) rand() / RAND_MAX) * window->getSize().x, ((double)rand() / RAND_MAX) * window->getSize().y);
		stars[i].setVDiffPercent((double) rand() / RAND_MAX);
		stars[i].setSize(1+((double)rand() / RAND_MAX) * 1);
	}

}

void Level::initCompletionBar() {
	cb.setRenderWindow(window);
	cb.setColor(sf::Color::Green);
	cb.setPercentage(0);
}

void Level::initTimerText() {
	arial = sf::Font();
	if (!arial.loadFromFile("arial.ttf")) {
		// error
	}

	timerDisplay.setFillColor(sf::Color::White);
	timerDisplay.setPosition(sf::Vector2f(0, 0));
	timerDisplay.setCharacterSize(20);
	timerDisplay.setStyle(sf::Text::Regular);
	timerDisplay.setFont(arial);
}

void Level::updateBackground() {
	for (int i = 0; i < stars.size(); i++) {
		float newX = stars[i].getX() - player->getXVelocity() * stars[i].getVDiffPercent();
		float newY = stars[i].getY() + player->getYVelocity() * stars[i].getVDiffPercent();
		stars[i].setPosition(newX, newY);
	
		if (stars[i].getX() < -5) {
			stars[i].setPosition(window->getSize().x + 5,((double) rand() / RAND_MAX) * window->getSize().y);
		}
		else if (stars[i].getX() > window->getSize().x+5) {
			stars[i].setPosition(-1, ((double)rand() / RAND_MAX) * window->getSize().y);
		}
		else if (stars[i].getY() < -5) {
			stars[i].setPosition(((double)rand() / RAND_MAX) * window->getSize().x, window->getSize().y+5);
		}
		else if (stars[i].getY() > window->getSize().y + 5) {
			stars[i].setPosition(((double)rand() / RAND_MAX) * window->getSize().x, -5);
		}
	}
}

void Level::update()
{
	player->move();
	updateBackground();
	cb.setPercentage(player->getY() / (float)finishLine);
}

void Level::handleInput()
{
	// if space is pressed output to console
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		player->setXAcceleration(sin(player->getRotation() / 180 * 3.14159265) * 0.2);
		player->setYAcceleration(cos(player->getRotation() / 180 * 3.14159265) * 0.2);
	}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		player->setXAcceleration(-sin(player->getRotation() / 180 * 3.14159265) * 0.2);
		player->setYAcceleration(-cos(player->getRotation() / 180 * 3.14159265) * 0.2);
	}
	else {
		player->setXAcceleration(0);
		player->setYAcceleration(0);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		player->setRotation(player->getRotation() + 4);
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		player->setRotation(player->getRotation() - 4);
	}
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		input->setKeyUp(sf::Keyboard::Escape);
		gameTime += timer.getElapsedTime().asMilliseconds();
		paused = true;
		levelMusic.pause();
	}
}


bool Level::isAlive() {
	return alive;
}

void Level::levelLoopInterface() {
	if (!paused) {
		update();
		handleInput();
	}
	beginDraw();
	render();
	if (paused) {
		handleGameMenuInput();
		renderGameMenu();
	}
	endDraw();
}

void Level::handleGameMenuInput() {
	if (input->isKeyDown(sf::Keyboard::Return)) {
		input->setKeyUp(sf::Keyboard::Return);
		paused = false;
		timer.restart();
		levelMusic.play();
	}
	if (input->isKeyDown(sf::Keyboard::X)) {
		input->setKeyUp(sf::Keyboard::X);
		alive = false;
	}
}

void Level::renderGameMenu() {
	window->draw(gameMenu);
}

void Level::render()
{
	drawBackground();
	cb.render();
	drawTimer();
	player->render(window);
}

void Level::drawTimer() {
	if (paused) {
		std::string str = std::to_string((double)(gameTime / 100) / 10);
		str = str.substr(0, str.size() - 5);
		timerDisplay.setString(str);
	}
	else {
		std::string str = std::to_string((double)((gameTime + timer.getElapsedTime().asMilliseconds()) / 100) / 10);
		str = str.substr(0, str.size() - 5);
		timerDisplay.setString(str);
	}
	window->draw(timerDisplay);
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