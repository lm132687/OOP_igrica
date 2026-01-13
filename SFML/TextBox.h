#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class TextBox
{
private:
	sf::Texture textboxTexture;
	sf::Sprite textboxSprite;
public:
	TextBox();

	void setSize(const sf::Vector2f& size);
	sf::FloatRect getBounds() const;
	void setPosition(const sf::Vector2f& pos);
	void draw(sf::RenderWindow& window);
};

