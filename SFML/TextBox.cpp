#include "TextBox.h"
/*
TextBox::TextBox()
{	
	textboxTexture.loadFromFile("boxes/textbox.png");
	textboxSprite.setTexture(textboxTexture);
}

void TextBox::setPosition(const sf::Vector2f& pos)
{
	textboxSprite.setPosition(pos);
	updateLayout();
}

void TextBox::setSize(const sf::Vector2f& size)
{
	boxSize = size;

	sf::Vector2u texSize = textboxSprite.getTexture()->getSize();
	textboxSprite.setScale(
		boxSize.x / texSize.x,
		boxSize.y / texSize.y
	);

	updateLayout();
}
void TextBox::updateLayout()
{
	sf::FloatRect bounds = text.getLocalBounds();

	text.setPosition(
		textboxSprite.getPosition().x + padding - bounds.left,
		textboxSprite.getPosition().y + padding - bounds.top
	);
}

void TextBox::setBottomRight(const sf::RenderWindow& window, float margin)
{
	sf::Vector2u win = window.getSize();

	textboxSprite.setPosition(
		win.x - boxSize.x - margin,
		win.y - boxSize.y - margin
	);

	updateLayout();
}

void TextBox::draw(sf::RenderWindow& window)
{
	window.draw(textboxSprite);
	window.draw(text);
}*/