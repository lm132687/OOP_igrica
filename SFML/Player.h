#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	sf::Vector2f position;
	bool clicking;
public:
	Player();

	void update(const sf::RenderWindow& window);
	void render(sf::RenderTarget& target);

	bool isClicking() const;
	//set position je left(x), top(y), set size je width, height
	/*getBounds vraća nevidljivi pravokutnik koji okružuje objekt.
	provjerava je li botun npr unutar tih granica kad kliknemo*/
	sf::FloatRect getBounds() const;
};

/*klik na lika
if (player.getBounds().intersects(character.getBounds()) &&
    player.isClicking())
{
    // započni dijalog
}

klik na botun
if (button.getBounds().contains(mousePos))
{
	// izbor
}
*/