#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr; //za inicjalizirat 
	this->textbox = nullptr;
	this->text = nullptr;

	activeBox = 0;//kad 0 onda je nista, 1 box1, 2 box2
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

void Game::initTextBox()
{
	this->font.loadFromFile("Fonts/mockclays_regular.ttf");

	this->textbox = new TextBox();
	this->textbox->setPosition({ 187.f, 422.f });
	this->text = new Text(this->font, 22);
	this->text->setPosition({ 240.f, 445.f });

	//dan1
	this->botun1 = new Botun();
	this->botun1->bite();
	this->botun1->setPosition({ 310.f, 472.f });
	//dan1
	this->botun2 = new Botun();
	this->botun2->mouth();
	this->botun2->setPosition({ 480.f, 468.f });
	/*
	//dan2
	this->botun3 = new Botun();
	this->botun3->body();
	this->botun3->setPosition({ 310.f, 528.f });
	//dan3
	this->botun4 = new Botun();
	this->botun4->skin();
	this->botun4->setPosition({ 490.f, 528.f });
	*/
}

void Game::initBox()
{
	this->box1Texture.loadFromFile("boxes/luka_leg.png");
	this->box1Sprite.setTexture(this->box1Texture);
	this->box1Sprite.setPosition({ 70.f, 50.f });

	this->box2Texture.loadFromFile("boxes/luka_mouth.png");
	this->box2Sprite.setTexture(this->box2Texture);
	this->box2Sprite.setPosition(200.f, 100.f);
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
	this->initTextBox();
	this->initBox();
}

Game::~Game() {
	delete this->text;
	delete this->textbox;
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
	//refrence
	//provjerit mouose poziciju jel iznad patienta i ako je u poll events provjerit is button pressed 
	//da pokrene razgovor (inittalking())
	
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

		if (this->ev.type==sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::E)
		{
			if (!menuOpen)
			{
				this->initMenu();
				player.player_menu();
				menuOpen = true;
			}
			else {
				player.player_normal();
				menuOpen = false;
			}
		}
	}
}

void Game::update() {
	//koristi nam za obradivanje input-a, pamcenje poz misa...
	this->pollEvents();

	this->mouse.update(*this->window);

	if (activeBox != 0)
	{
		if (mouse.isLeftClicked())
		{
			activeBox = 0;
		}

		return;
	}

	this->player.update(*this->window);
	for (auto& p : this->patients)
	{
		p.update();
	}

	if (dijalog.isActive())
	{
		//aktivirati chocie na ovoj liniji
		if (dijalog.getCurrentDijalog() == "Player: What do you want to check?")
		{
			dijalog.enterChoice();
		}

		//choice mode
		if (dijalog.isInChoice())
		{
			if (botun1->isClicked(mouse))
			{
				dijalog.leaveChoice();
				activeBox = 1;;
				return;
			}
			else if (botun2->isClicked(mouse))
			{
				dijalog.leaveChoice();
				activeBox = 2;
				return;
			}

			text->setText(dijalog.getCurrentDijalog());
			return;
		}

		//normalni dijalog
		if (mouse.isLeftClicked())
		{
			dijalog.next();

			if (!dijalog.isActive())
			{
				player.player_normal();

				if (activePatient)
				{
					activePatient->patient_normal();
					activePatient = nullptr;
				}

				return;
			}
		}

		text->setText(dijalog.getCurrentDijalog());
		return;
	}

	if (mouse.isLeftClicked())
	{
		for (auto& patient : this->patients)
		{
			if (patient.getBounds().contains(static_cast<sf::Vector2f>(mouse.getMousePos())))
			{
				//patient.patient_talking();
				this->dijalog.start(patient.getDialog());
				activePatient = &patient;
				
				player.player_talking();
				patient.patient_talking();

				text->setText(this->dijalog.getCurrentDijalog());
				break;
			}
		}
	}



	/*
	if (mouse.isLeftClicked())
	{
		sf::Vector2i mouseposs = sf::Mouse::getPosition(*this->window);
		sf::Vector2f mousee = (*this->window).mapPixelToCoords(mouseposs);
		for(auto& patient : this->patients)
		{
			if (patient.getBounds().contains(mousee))
			{
				patient.patient_talking();
			}
		}
	}
	*/
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
	
	//Ovdje cemo crtati
	for (auto& p : this->patients)
	{
		p.render(*this->window);
	}

	if (this->dijalog.isActive())
	{
		this->textbox->draw(*this->window);
		this->text->draw(*this->window);
		if (dijalog.isInChoice())
		{
			this->botun1->draw(*this->window);
			this->botun2->draw(*this->window);
			//this->botun3->draw(*this->window);
			//this->botun4->draw(*this->window);
		}
	}

	if (activeBox == 1)
	{
		this->window->draw(this->box1Sprite);
	}
	if (activeBox == 2)
	{
		this->window->draw(this->box2Sprite);
	}

	if (menuOpen)
	{
		this->window->draw(this->menuSprite);
	}

	this->player.render(*this->window);

	//this->patient->render(*this->window);
	//this->window->draw(this->pat);

	this->window->display();
}
