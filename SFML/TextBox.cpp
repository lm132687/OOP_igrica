#include "TextBox.h"

TextBox::TextBox()
{	
	textboxTexture.loadFromFile("boxes/textbox.png");
	textboxSprite.setTexture(textboxTexture);
}

void TextBox::setPosition(const sf::Vector2f& pos)
{
	textboxSprite.setPosition(pos);
}

void TextBox::setSize(const sf::Vector2f& size)
{
	sf::Vector2u texSize = textboxSprite.getTexture()->getSize();
	textboxSprite.setScale(
		size.x / texSize.x,
		size.y / texSize.y
	);
}

sf::FloatRect TextBox::getBounds() const
{
	return sf::FloatRect();
}

void TextBox::draw(sf::RenderWindow& window)
{
	window.draw(textboxSprite);
}

