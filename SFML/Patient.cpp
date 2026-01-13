#include "Patient.h"

Patient::Patient(float x, float y)
{
	this->patientTexture.loadFromFile("Patients/luka.png");
	this->patient_talkingTexture.loadFromFile("Patients/luka_talking.png");
	this->patientSprite.setTexture(this->patientTexture);
	this->patientSprite.setPosition(481.f, 10.f);
	this->patientSprite.setScale(280.f / patientTexture.getSize().x,
		584.f / patientTexture.getSize().y);


	//this->patientTexture.setOutlineColor(sf::Color::White);
	//outline da se bolje vidi posto ce pozadina bit tamnija 
}

void Patient::update()
{
	//health, movement
}

void Patient::apply_scale()
{
	this->patientSprite.setScale(
		280.f / this->patientSprite.getTexture()->getSize().x,
		584.f / this->patientSprite.getTexture()->getSize().y
	);
}

void Patient::render(sf::RenderTarget& target)
{
	target.draw(this->patientSprite);
}

void Patient::patient_normal()
{
	this->patientSprite.setTexture(this->patientTexture);
	apply_scale();
	
}

void Patient::patient_talking()
{
	this->patientSprite.setTexture(this->patient_talkingTexture);
	apply_scale();
}

sf::FloatRect Patient::getBounds() const
{
	return patientSprite.getGlobalBounds();
}

