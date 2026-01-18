#pragma once
#include <SFML/Graphics.hpp>
#include "Mouse.h"

class Botun
{
private:
	sf::Texture botunTexture_1;//dan 1
	sf::Texture botunTexture_2;//dan 1
	sf::Texture botunTexture_3;//dan 2
	sf::Texture botunTexture_4;//dan 3
	
	sf::Texture botunReportTexture;
	sf::Texture botunLetGoTexture;
	sf::Texture botunBackTexture;

	sf::Sprite botunSprite;
public:
	Botun();

	void setSize(const sf::Vector2f& size);
	sf::FloatRect getBounds() const;
	void setPosition(const sf::Vector2f& pos);
	void bite();
	void mouth();
	void skin();
	void body();
	void botunReport();
	void botunLetGo();
	void botunBack();
	void draw(sf::RenderWindow& window);
	bool isClicked(Mouse& mouse);
	
};

