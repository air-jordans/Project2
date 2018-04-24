#include "Menu.h"


Menu::Menu(sf::RenderWindow* hwnd, Input* inp)
// Initialize the global buttons
	: playButton(hwnd), settingsButton(hwnd), scoresButton(hwnd), exitButton(hwnd),
		menuInstructions(hwnd), splash(hwnd)
{
	window = hwnd;
	input = inp;
	initButtons();
	initStars();
	setMusic("res/music/menu1.wav");
	playMusic();
}

Menu::~Menu()
{
}

void Menu::initStars() {
	// create vector of Star's of size 200
	menuStars = std::vector<MenuStar>(200);

	// Seed random number generation
	srand(40);

	// Get the size of the window
	sf::Vector2u windowSize = window->getSize();

	// Set initial start position, direction and size of each star
	for (int i = 0; i < menuStars.size(); i++) {
		// Pass each star a pointer to the window
		menuStars[i].setWindow(window);
		int x = (int) (((double)rand() / RAND_MAX) * windowSize.x);
		int y = (int) (((double)rand() / RAND_MAX) * windowSize.y);
		menuStars[i].setPosition(x, y);
		menuStars[i].setInitialDirection();
		menuStars[i].setSize((float)(((double)rand() / RAND_MAX) * 2.5));
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

	splash.setTexture("res/splash.png");
	splash.setRect(sf::IntRect(0,0,600,100));

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

	menuInstructions.setTexture("res/menuInstructions.png");
	menuInstructions.setRect(sf::IntRect(0, height - 40, 800, 50));
}

void Menu::setMusic(sf::String filename) {
	if (!menuMusic.openFromFile(filename)) {
		// error
	}
	menuMusic.setVolume(20);
	menuMusic.setLoop(true);
}

void Menu::playMusic() {
	menuMusic.play();
}

void Menu::stopMusic() {
	menuMusic.stop();
}

void Menu::render() {
	//Clear background
	window->clear(sf::Color::Black);

	renderBackground();
	
	splash.render();
	playButton.render();
	settingsButton.render();
	scoresButton.render();
	exitButton.render();
	menuInstructions.render();

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
			window->close();
		}
		else if (currentSelected == play) {
			playButtonSelected = true;
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