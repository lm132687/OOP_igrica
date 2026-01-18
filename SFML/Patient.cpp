#include "Patient.h"
#include <iostream>

Patient::Patient(const std::string& textureFile, const std::string& talkingTextureFile, float x, float y)
{
	if (!patientTexture.loadFromFile(textureFile))
		std::cerr << "Failed to load texture: " << textureFile << std::endl;
	if (!patient_talkingTexture.loadFromFile(talkingTextureFile))
		std::cerr << "Failed to load texture: " << talkingTextureFile << std::endl;

	patientSprite.setTexture(patientTexture);
	patientSprite.setPosition(x, y);
	apply_scale();

	active = true;     // pacijent je aktivan
	result = PatientResult::None;
	infection = InfectionStatus::Healthy; // default

	dialogLines.clear();

	//this->patientTexture.setOutlineColor(sf::Color::White);
	//outline da se bolje vidi posto ce pozadina bit tamnija 
}

bool Patient::isActive() const { return active; }
void Patient::deactivate() { active = false; }

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

void Patient::report()
{
	result = PatientResult::Reported;
	active = false;
}

void Patient::letGo()
{
	result = PatientResult::LetGo;
	active = false;
}

void Patient::back()
{
	result = PatientResult::Back;
}

bool Patient::isInfected() const
{
	return infection == InfectionStatus::Infected;
}

PatientResult Patient::getResult() const
{
	return result;
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

void Patient::setDialog(const vector<string>& lines)
{
	dialogLines = lines;
}

void Patient::setInfection(InfectionStatus status)
{
	infection = status;
}

void Patient::setBoxTextures(int boxIndex, const std::string& boxFile)
{
	switch (boxIndex) {
	case 1: box1Texture.loadFromFile(boxFile); box1Sprite.setTexture(box1Texture); break;
	case 2: box2Texture.loadFromFile(boxFile); box2Sprite.setTexture(box2Texture); break;
	case 3: box3Texture.loadFromFile(boxFile); box3Sprite.setTexture(box3Texture); break;
	case 4: box4Texture.loadFromFile(boxFile); box4Sprite.setTexture(box4Texture); break;
	}
	
	box1Sprite.setPosition(70.f, 50.f);
	box2Sprite.setPosition(70.f, 50.f);
	box3Sprite.setPosition(70.f, 50.f);
	box4Sprite.setPosition(70.f, 50.f);
}


void Patient::addSymptomBotun(const Botun& botun)
{
	symptomBotuns.push_back(botun);
}

Botun& Patient::getSymptomBotun(size_t index)
{
	return symptomBotuns.at(index);
}

size_t Patient::getSymptomCount() const
{
	return symptomBotuns.size();
}