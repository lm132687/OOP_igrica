#pragma once
#include <SFML/Graphics.hpp>

class Patient{
private:
	sf::Sprite patientSprite;
	sf::Texture patientTexture;

	sf::Texture patient_talkingTexture;
	sf::Sprite patient_talkingSprite;
public:
	Patient(float x, float y);
	
	void update();
	void render(sf::RenderTarget& target);
	void patient_talking();
	void apply_scale();
	void patient_normal();

	sf::FloatRect getBounds() const;
};

