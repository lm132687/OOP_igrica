#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.h"
using namespace std;
class Text
{
private:
	sf::Text text;
	float padding = 20.f;
public:
	Text(const sf::Font& font, unsigned int size);
	void setText(const sf::String& str);
	void attachTo(const TextBox& box);
	void draw(sf::RenderWindow& window);
};

