#include "Patient.h"

Patient::Patient(float x, float y)
{
	this->patientTexture.loadFromFile("Patients/shy_lady.png");
	this->patientSprite.setTexture(this->patientTexture);
	this->patientSprite.setPosition(10.f, 10.f);
	this->patientSprite.setScale(800.f / patientTexture.getSize().x,
		600.f / patientTexture.getSize().y);


	//this->patientTexture.setOutlineColor(sf::Color::White);
	//outline da se bolje vidi posto ce pozadina bit tamnija 
}

void Patient::update()
{
	//health, movement
}

void Patient::render(sf::RenderTarget& target)
{
	target.draw(this->patientSprite);
}

sf::FloatRect Patient::getBounds() const
{
	return patientSprite.getGlobalBounds();
}
