#include "Player.h"

Player::Player()
{
	this->normalTexture.loadFromFile("Player/player.png");
	this->talkingTexture.loadFromFile("Player/player_talking.png");
	this->menuTexture.loadFromFile("Player/player_menu.png");
	this->umTexture.loadFromFile("Player/player_um.png");
	this->stressTexture.loadFromFile("Player/player_stress.png");

	this->playerSprite.setTexture(this->normalTexture);

	this->playerSprite.setScale(10.f, 10.f);
	this->position = sf::Vector2f(10.f, 70.f);
	
	this->playerSprite.setScale(
		750.f / this->playerSprite.getTexture()->getSize().x,
		550.f / this->playerSprite.getTexture()->getSize().y
	);

	this->playerSprite.setPosition(10.f, 70.f);

	this->playerSprite.setOrigin(0.f, 0.f);
	this->clicking = false;
}

void Player::update(const sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	/*this->position = sf::Vector2f(
		static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)
	);*/

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

//applyscale za svaki slucaj ako su teksture drugacijih dimenzija
void Player::applyScale()
{
	this->playerSprite.setScale(
		750.f / this->playerSprite.getTexture()->getSize().x,
		550.f / this->playerSprite.getTexture()->getSize().y
	);
}

void Player::player_normal()
{
	this->playerSprite.setTexture(this->normalTexture);
	applyScale();
}

void Player::player_talking()
{
	this->playerSprite.setTexture(this->talkingTexture);
	applyScale();
}

void Player::player_menu()
{
	this->playerSprite.setTexture(this->menuTexture);
	applyScale();
}

void Player::player_um()
{
	this->playerSprite.setTexture(this->umTexture);
	applyScale();
}

void Player::player_stress()
{
	this->playerSprite.setTexture(this->stressTexture);
	applyScale();
}

sf::FloatRect Player::getBounds() const
{
	return this->playerSprite.getGlobalBounds();
}

