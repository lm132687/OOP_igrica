#include "Botun.h"

Botun::Botun()
{
	botunTexture_1.loadFromFile("boxes/botun_1.png");
	botunTexture_2.loadFromFile("boxes/botun_2.png");
	botunTexture_3.loadFromFile("boxes/botun_3.png");
	botunTexture_4.loadFromFile("boxes/botun_4.png");
	
	botunLetGoTexture.loadFromFile("boxes/botun_letgo.png");
	botunReportTexture.loadFromFile("boxes/botun_report.png");
	botunBackTexture.loadFromFile("boxes/botun_back.png");
}

void Botun::setPosition(const sf::Vector2f& pos)
{
	botunSprite.setPosition(pos);
}

void Botun::setSize(const sf::Vector2f& size)
{
	sf::Vector2u texSize = botunSprite.getTexture()->getSize();
	botunSprite.setScale(
		size.x / texSize.x,
		size.y / texSize.y
	);
}

sf::FloatRect Botun::getBounds() const
{
	return sf::FloatRect();
}

void Botun::bite()
{
	this->botunSprite.setTexture(this->botunTexture_1);
	this->botunSprite.setScale(
		100.f / this->botunSprite.getTexture()->getSize().x,
		50.f / this->botunSprite.getTexture()->getSize().y
	);
}

void Botun::mouth()
{
	this->botunSprite.setTexture(this->botunTexture_2);
	this->botunSprite.setScale(
		120.f / this->botunSprite.getTexture()->getSize().x,
		56.f / this->botunSprite.getTexture()->getSize().y
	);
}

void Botun::body()
{
	this->botunSprite.setTexture(this->botunTexture_3);
	this->botunSprite.setScale(
		100.f / this->botunSprite.getTexture()->getSize().x,
		50.f / this->botunSprite.getTexture()->getSize().y
	);
}

void Botun::botunReport()
{
	this->botunSprite.setTexture(this->botunReportTexture);
	this->botunSprite.setScale(
		100.f / this->botunSprite.getTexture()->getSize().x,
		50.f / this->botunSprite.getTexture()->getSize().y
	);
}

void Botun::botunLetGo()
{
	this->botunSprite.setTexture(this->botunLetGoTexture);
	this->botunSprite.setScale(
		100.f / this->botunSprite.getTexture()->getSize().x,
		50.f / this->botunSprite.getTexture()->getSize().y
	);
}

void Botun::botunBack()
{
	this->botunSprite.setTexture(this->botunBackTexture);
	this->botunSprite.setScale(
		100.f / this->botunSprite.getTexture()->getSize().x,
		50.f / this->botunSprite.getTexture()->getSize().y
	);
}

void Botun::skin()
{
	this->botunSprite.setTexture(this->botunTexture_4);
	this->botunSprite.setScale(
		100.f / this->botunSprite.getTexture()->getSize().x,
		50.f / this->botunSprite.getTexture()->getSize().y
	);
}

void Botun::draw(sf::RenderWindow& window)
{
	window.draw(botunSprite);
}

bool Botun::isClicked(Mouse& mouse)
{
	return mouse.isLeftClicked() &&
	botunSprite.getGlobalBounds().contains(
	static_cast<sf::Vector2f>(mouse.getMousePos()));
	
}
