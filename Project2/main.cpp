#include "Level.h"
#include "Input.h"
#include "Menu.h"
#include <chrono>
#include <thread>
void main()
{
	// Create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Kessel Run", sf::Style::Close);

	//Inialise Menu object
	Input input;
	Menu menu(&window, &input);

	//time
	sf::Clock clock;
	float deltaTime;

	// Game loop
	while (window.isOpen())
	{
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
				break;
			case sf::Event::KeyPressed:
				// update input class
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				//update input class
				input.setKeyUp(event.key.code);
				break;
			default:
				// don't handle other events
				break;
			}
		}

		menu.menuLoopInterface();

		// Run at 60 fps
		sf::Time timeTaken = clock.getElapsedTime();
		if (timeTaken.asMilliseconds() <= 33) {
			std::this_thread::sleep_for(std::chrono::milliseconds(33 - timeTaken.asMilliseconds()));
		}
	}
}
