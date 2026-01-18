#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Patient.h"
#include "Player.h"
#include "TextBox.h"
#include "Text.h"
#include "Mouse.h"
#include "Dijalog.h"
#include "Botun.h"
#include "DecisionTracker.h"
#include <vector>
using namespace std;
/*
Klasa koja se ponasa kao game engine
*/
enum class GameState
{
	Playing,
	GoodEnding,
	BadEnding
};
class Game
{
private:
	//Window da kad kliknemo play nam pop-uppa
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;//event ima default inicijalizaciju

	//slika background
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	//Mouse pozicija, click
	Mouse mouse;
	bool hoveringReport = false;

	//Game objects
	vector<Patient> patients;
	int currentPatientIndex;
	Player player;

	//player menu(magazin)
	bool menuOpen = false;
	vector<sf::Sprite> symptomSprites;
	std::vector<sf::Texture> symptomTextures;

	int currentSymptomIndex = 0;
	bool symptomMenuOpen = false;

	//textbox, text, font, botun
	sf::Font font;
	TextBox* textbox;
	Text* text;

	Botun* botun1;
	Botun* botun2;
	Botun* botun3;
	Botun* botun4;

	Botun* reportBotun;
	Botun* letGoBotun;
	Botun* backBotun;
	//slika s simptomima
	int activeBox;

	sf::Texture box1Texture;
	sf::Texture box2Texture;
	sf::Sprite box1Sprite;
	sf::Sprite box2Sprite;


	//kad pricaju
	Dijalog dijalog;
	Patient* activePatient = nullptr;

	//odluka, good i bad ending
	DecisionTracker decisionTracker;
	GameState gameState = GameState::Playing;
	sf::Texture goodEndingTexture;
	sf::Sprite goodEndingSprite;

	sf::Texture badEndingTexture;
	sf::Sprite badEndingSprite;

	TextBox* endingTextBox = nullptr;
	Text* endingText = nullptr;

	void initVariables();
	void initWindow();
	void initBackground();
	void initPatients();
	void initMenu();
	void initTextBox();
	void initBox();
	void initEnding();
public:
	Game();
	virtual ~Game();

	bool running() const;

	void pollEvents();
	void update();
	void render();
};

