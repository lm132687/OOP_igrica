#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

class Mouse
{
private:
	bool leftClicked;
	bool prevClicked;
	sf::Vector2i mousePos;

public:
	Mouse();
	void update(sf::RenderWindow& window);

	bool isLeftClicked() const;
	sf::Vector2i getMousePos() const;
};

