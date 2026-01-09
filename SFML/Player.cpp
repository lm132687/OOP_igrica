#include "Player.h"

Player::Player()
{
	this->playerTexture.loadFromFile("Player/player.png");
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setScale(10.f, 10.f);
	this->position = sf::Vector2f(10.f, 70.f);
	this->playerSprite.setScale(750.f / playerTexture.getSize().x,
		550.f / playerTexture.getSize().y);

	this->playerSprite.setOrigin(0.f, 0.f);
	this->clicking = false;
}

void Player::update(const sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	/*this->position = sf::Vector2f(
		static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)
	);*/
	this->playerSprite.setPosition(this->position);

	this->clicking = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
}

bool Player::isClicking() const
{
	return this->clicking;
}

sf::FloatRect Player::getBounds() const
{
	return this->playerSprite.getGlobalBounds();
}
