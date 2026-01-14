#include "Patient.h"

Patient::Patient(float x, float y)
{
	this->patientTexture.loadFromFile("Patients/luka.png");
	this->patient_talkingTexture.loadFromFile("Patients/luka_talking.png");
	this->patientSprite.setTexture(this->patientTexture);
	this->patientSprite.setPosition(481.f, 10.f);
	this->patientSprite.setScale(280.f / patientTexture.getSize().x,
		584.f / patientTexture.getSize().y);

	dialogLines = {
		"Luka: Just get it over with.",
		"Player: What seems to be the problem?",
		"Luka: Just came in for a check up. But hurry up I have\n things to do.",
		"Player: Ok...",
		"Player: What do you want to check?",

		"Aurora: Hi... I need your help...",
		"Player: What seems to be the problem?",
		"Aurora: I can't stop coughing...khkh..",
		"Player: Ok, don't worry I will check  you.",
		"Player: What do you want to check?",
	};


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

const vector<string>& Patient::getDialog() const
{
	return dialogLines;
}

