#include "Menu.h"


Menu::Menu(sf::RenderWindow* hwnd, Input* inp)
// Initialize the global buttons
	: playButton(hwnd), settingsButton(hwnd), scoresButton(hwnd), exitButton(hwnd)
{
	window = hwnd;
	input = inp;
	initButtons();
	initStars();
}

Menu::~Menu()
{
}

void Menu::initStars() {
	// create vector of Star's of size 200
	menuStars = std::vector<Star>(200);

	// Seed random number generation
	srand(40);

	// Get the size of the window
	sf::Vector2u windowSize = window->getSize();

	// Set initial start position, direction and size of each star
	for (int i = 0; i < menuStars.size(); i++) {
		// Pass each star a pointer to the window
		menuStars[i].setWindow(window);
		int x = ((double)rand() / RAND_MAX) * windowSize.x;
		int y = ((double)rand() / RAND_MAX) * windowSize.y;
		menuStars[i].setPosition(x, y);
		menuStars[i].setInitialDirection();
		menuStars[i].setSize(((double)rand() / RAND_MAX) * 2.5);
	}
}

// Initialize buttons
void Menu::initButtons() {
	sf::Vector2u size = window->getSize();
	int buttonWidth = 300;
	int buttonHeight = 60;
	int width = size.x;
	int height = size.y;

	// Intitialize the splash art
	sf::Texture tex;
	if (!tex.loadFromFile("res/splash.png")) {
		// error
	}
	splash.setTexture(tex);
	splash.setPosition(sf::Vector2f(0, 0));

	// Set relevant values to button variables
	playButton.setTexture("res/playButton.png");
	playButton.setRect(sf::IntRect(width / 2 - buttonWidth / 2, 180, buttonWidth, buttonHeight));
	playButton.setSelected(true);

	settingsButton.setTexture("res/optionsButton.png");
	settingsButton.setRect(sf::IntRect(width / 2 - buttonWidth / 2, 280, buttonWidth, buttonHeight));

	scoresButton.setTexture("res/scoreButton.png");
	scoresButton.setRect(sf::IntRect(width / 2 - buttonWidth / 2, 380, buttonWidth, buttonHeight));

	exitButton.setTexture("res/exitButton.png");
	exitButton.setRect(sf::IntRect(width / 2 - buttonWidth / 2, 480, buttonWidth, buttonHeight));
}

void Menu::render() {
	//Clear background
	window->clear(sf::Color::Black);

	renderBackground();

	window->draw(splash);

	playButton.render();
	settingsButton.render();
	scoresButton.render();
	exitButton.render();

	//Display 
	window->display();
}

// Handle input while in the menu
void Menu::handleInput() {
	if (input->isKeyDown(sf::Keyboard::Down) || input->isKeyDown(sf::Keyboard::S)) {
		input->setKeyUp(sf::Keyboard::Down);
		input->setKeyUp(sf::Keyboard::S);
		switch (currentSelected) {
		case 0:
			playButton.setSelected(false);
			settingsButton.setSelected(true);
			currentSelected++;
			break;
		case 1:
			settingsButton.setSelected(false);
			scoresButton.setSelected(true);
			currentSelected++;
			break;
		case 2:
			scoresButton.setSelected(false);
			exitButton.setSelected(true);
			currentSelected++;
			break;
		case 3:
			exitButton.setSelected(false);
			playButton.setSelected(true);
			currentSelected = 0;
			break;
		}
	}
	if (input->isKeyDown(sf::Keyboard::Up) || input->isKeyDown(sf::Keyboard::W)) {
		input->setKeyUp(sf::Keyboard::Up);
		input->setKeyUp(sf::Keyboard::W);
		switch (currentSelected) {
		case 0:
			playButton.setSelected(false);
			exitButton.setSelected(true);
			currentSelected = 3;
			break;
		case 1:
			settingsButton.setSelected(false);
			playButton.setSelected(true);
			currentSelected--;
			break;
		case 2:
			scoresButton.setSelected(false);
			settingsButton.setSelected(true);
			currentSelected--;
			break;
		case 3:
			exitButton.setSelected(false);
			scoresButton.setSelected(true);
			currentSelected--;
			break;
		}
	}
	if (input->isKeyDown(sf::Keyboard::Return)) {
		if (currentSelected == exit) {
			// Exit the program
			std::cout << "wtf\n";
			window->close();
		}
		else if (currentSelected == play) {
			// create level and run
		}
		else if (currentSelected == options) {
			// go to options menu
		}
		else if (currentSelected == scores) {
			// uhhhh, figure out what goes here
		}
	}
}

void Menu::renderBackground() {
	// Render starry background
	for (int i = 0; i < menuStars.size(); i++) {
		menuStars[i].render();
		menuStars[i].move();
		//std::cout << i;
	}
}

void Menu::menuLoopInterface() {
	render();
	handleInput();
}