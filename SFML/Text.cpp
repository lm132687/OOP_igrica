#include "Text.h"

Text::Text(const sf::Font& font, unsigned int size)
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(sf::Color::White);
}

void Text::setText(const sf::String& str)
{
	text.setString(str);
}

void Text::attachTo(const TextBox& box)
{
	auto bounds = box.getBounds();
	auto textBounds = text.getLocalBounds();

	text.setPosition(
		bounds.left + padding - textBounds.left,
		bounds.top + padding - textBounds.top
	);
}

void Text::draw(sf::RenderWindow& window)
{
	window.draw(text);
}
