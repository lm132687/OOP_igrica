#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "TextBox.h"

using namespace std;
class Text
{
private:
	sf::Text text;
	float padding = 20.f;
	Mouse mouse;
public:
	Text(const sf::Font& font, unsigned int size);
	void setPosition(const sf::Vector2f& pos);
	void setText(const sf::String& str);
	void attachTo(const TextBox& box);
	void draw(sf::RenderWindow& window);
	void Talking();
};

