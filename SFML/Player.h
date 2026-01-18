#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite playerSprite;

	sf::Texture normalTexture;
	sf::Texture talkingTexture;
	sf::Texture menuTexture;

	sf::Vector2f position;
	bool clicking;

public:
	Player();

	void update(const sf::RenderWindow& window);
	void render(sf::RenderTarget& target);

	bool isClicking() const;

	void applyScale();
	//mijenjanje reakcija playera
	void player_normal();
	void player_talking();
	void player_menu();

	//set position je left(x), top(y), set size je width, height
	/*getBounds vraća nevidljivi pravokutnik koji okružuje objekt.
	provjerava je li botun npr unutar tih granica kad kliknemo*/
	sf::FloatRect getBounds() const;
};
