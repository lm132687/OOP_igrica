#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite playerSprite;

	sf::Texture normalTexture;
	sf::Texture talkingTexture;
	sf::Texture menuTexture;
	sf::Texture umTexture;
	sf::Texture stressTexture;

	sf::Vector2f position;
	bool clicking;

public:
	Player();

	void update(const sf::RenderWindow& window);
	void render(sf::RenderTarget& target);

	bool isClicking() const;

	//mijenjanje reakcija player-a
	sf::Texture getTexture() const;
	sf::Sprite getSprite() const;

	void applyScale();

	void player_normal();
	void player_talking();
	void player_menu();
	void player_um();
	void player_stress();

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