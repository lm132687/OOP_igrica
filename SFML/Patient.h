#pragma once
#include <SFML/Graphics.hpp>

class Patient{
private:
	sf::Sprite patientSprite;
	sf::Texture patientTexture;
public:
	Patient(float x, float y);
	
	void update();
	void render(sf::RenderTarget& target);

	sf::FloatRect getBounds() const;
};

