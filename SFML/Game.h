#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Patient.h"
#include "Player.h"

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

	//Mouse pozicija
	sf::Vector2i mousePosWindow;

	//Game objects
	vector<Patient> patients;
	Player player;

	void initVariables();
	void initWindow();
	void initBackground();
	void initPatients();
public:
	Game();
	virtual ~Game();

	bool running() const;

	void updateMousePos();
	void pollEvents();
	void update();
	void render();
};

