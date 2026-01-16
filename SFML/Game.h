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
#include <vector>
using namespace std;
/*
Klasa koja se ponasa kao game engine
*/

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

	//Game objects
	vector<Patient> patients;
	Player player;

	//player menu(magazin)
	sf::Sprite menuSprite;
	sf::Texture menuTexture;
	bool menuOpen = false;

	//textbox, text, font, botun
	sf::Font font;
	TextBox* textbox;
	Text* text;
	Botun* botun1;
	Botun* botun2;
	Botun* botun3;
	Botun* botun4;
	
	//slika s simptomima
	int activeBox;

	sf::Texture box1Texture;
	sf::Texture box2Texture;
	sf::Sprite box1Sprite;
	sf::Sprite box2Sprite;

	//kad pricaju
	Dijalog dijalog;
	Patient* activePatient = nullptr;

	void initVariables();
	void initWindow();
	void initBackground();
	void initPatients();
	void initMenu();
	void initTextBox();
	void initBox();
public:
	Game();
	virtual ~Game();

	bool running() const;

	void updateMousePos();
	void pollEvents();
	void update();
	void render();
};

