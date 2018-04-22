#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class MenuButton
{
public:
	MenuButton(sf::RenderWindow* hwnd);
	~MenuButton();
	void render();
	void setRect(sf::IntRect rect);
	void setTexture(sf::String str);
	bool isSelected();
	void setSelected(bool select);
private:
	sf::RenderWindow* window;
	sf::RectangleShape transparentRect;
	sf::Texture tex;
	sf::Sprite sprite;
	bool selected = false;
};
