#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr; //za inicjalizirat 
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	//mozemo napraviti this->videoMode.Desktop, ponudit ce do kraja tako
	//da samo odmah nam uzme sirinu i visinu
	this->window = new sf::RenderWindow(this->videoMode, "Are You Human?", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);//update i render u mainu se izvrsavaju 144 puta u sec
	//jer nam framrate limit moze bit prevelik pa ce nam laggat
}

void Game::initPatients()
{
	patients.emplace_back(10.f, 10.f);
}

void Game::initMenu()
{
	this->menuTexture.loadFromFile("menu/menu_1simptom.png");
	this->menuSprite.setTexture(this->menuTexture);
}

void Game::initBackground()
{
	this->backgroundTexture.loadFromFile("Background/hospital.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);

}

Game::Game() 
{
	this->initVariables();
	this->initWindow();
	this->initBackground();
	this->initPatients();
}

Game::~Game() {
	delete this->window;
}

bool Game::running() const
{
	return this->window->isOpen();
}

void Game::updateMousePos()
{
	/* 
		Update-a mouse poziciju, prati poziciju misa samo unutar window-a (Vector2i)
	*/
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);//refrence
}

void Game::pollEvents()
{
	//OS i window
	//event- sve sta korisnik radi, sta se sve dogodilo
	while (this->window->pollEvent(this->ev))//dok god ima novih dogadanja obradi ih
	{
		if (this->ev.type == sf::Event::Closed)
			this->window->close();

		if (this->ev.type == sf::Event::KeyPressed &&
			this->ev.key.code == sf::Keyboard::Escape)
			this->window->close();

		if (this->ev.key.code == sf::Keyboard::E)
		{
			if (!menuOpen)
			{
				this->initMenu();
				menuOpen = true;
			}
			else {
				menuOpen = false;
			}
		}
	}
}

void Game::update() {
	//koristi nam za obradivanje input-a, pamcenje poz misa...
	this->pollEvents();

	this->player.update(*this->window);
	for (auto& p : this->patients)
	{
		p.update();
	}

	this->updateMousePos();
}

void Game::render()
{
	/*Rendera game object-e
	clear old frame
	render new objects
	display frame in window...
	pozadina, objekt, tekst, UI
	render uvijek ide redom clear draw display*/
	this->window->clear();
	//backgroud draw

	this->window->draw(this->backgroundSprite);
	//popravi
	if (menuOpen)
	{
		this->window->draw(this->menuSprite);
	}
	//Ovdje cemo crtati
	for (auto& p : this->patients)
	{
		p.render(*this->window);
	}
	//this->player->render(*this->window);
	//this->patient->render(*this->window);
	//this->window->draw(this->pat);

	this->window->display();
}
