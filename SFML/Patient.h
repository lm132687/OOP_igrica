#pragma once
#include <SFML/Graphics.hpp>
#include "Botun.h"
using namespace std;

enum class PatientResult
{
	None,
	Reported,
	LetGo,
	Back
};
enum class InfectionStatus
{
	Healthy,
	Infected
};
class Patient {
private:
	sf::Sprite patientSprite;
	sf::Texture patientTexture;

	sf::Texture patient_talkingTexture;

	InfectionStatus infection;

	vector<string> dialogLines;

	bool active = true;
	PatientResult result = PatientResult::None;

	sf::Texture box1Texture;
	sf::Texture box2Texture;
	sf::Texture box3Texture;
	sf::Texture box4Texture;

	sf::Sprite box1Sprite;
	sf::Sprite box2Sprite;
	sf::Sprite box3Sprite;
	sf::Sprite box4Sprite;

	vector<Botun> symptomBotuns;

public:
	Patient(const std::string& textureFile, const std::string& talkingTextureFile, float x, float y);

	bool isActive() const;
	void deactivate();

	void update();
	void render(sf::RenderTarget& target);
	void patient_talking();
	void apply_scale();
	void patient_normal();

	void report();
	void letGo();
	void back();

	bool isInfected() const;
	PatientResult getResult() const;
	sf::FloatRect getBounds() const;

	const vector<string>& getDialog() const;
	void setDialog(const vector<string>& lines);
	void setInfection(InfectionStatus status);
	sf::Sprite& getBoxSprite(int boxIndex) {
		switch (boxIndex) {
		case 1: return box1Sprite;
		case 2: return box2Sprite;
		case 3: return box3Sprite; // novi box3
		case 4: return box4Sprite; // novi box4
		default: return box1Sprite;
		}
	}
	void setBoxTextures(int boxIndex, const std::string& boxFile);
	

	void addSymptomBotun(const Botun& botun);
	Botun& getSymptomBotun(size_t index);
	size_t getSymptomCount() const;
};

