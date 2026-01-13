#pragma once
#include <SFML/Graphics.hpp>

class Mouse
{
private:
	bool leftClicked;
	sf::Vector2i mousePos;

public:
	Mouse();
	void update(sf::RenderWindow& window);

	bool isLeftClicked() const;
	sf::Vector2i getMousePos() const;
};

