#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr; //za inicjalizirat 
	this->textbox = nullptr;
	this->text = nullptr;

	activeBox = 0;//kad 0 onda je nista, 1 box1, 2 box2
	currentPatientIndex = 0;
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
	patients.emplace_back("Patients/luka.png", "Patients/luka_talking.png", 481.f, 10.f); //Luka
	patients.back().setInfection(InfectionStatus::Infected);
	patients.back().setDialog({
		"Luka: Just get it over with.",
		"Player: What seems to be the problem?",
		"Luka: Just came in for a check up.",
		"Player: What do you want to check?"
		});
	patients.back().patient_normal();
	

	patients.emplace_back("Patients/kid.png", "Patients/kid_talking.png", 481.f, 10.f); //Toma
	patients.back().setInfection(InfectionStatus::Healthy);
	patients.back().setDialog({
		"Kid: Hi! I'm Toma!",
		"Player: Hi Toma! What seems to be the problem?",
		"Toma: Oh my mom just said I needed a check up.",
		"Player: What do you want to check?"
		});
	patients.back().patient_normal();

	patients.emplace_back("Patients/jessica.png", "Patients/jessica_talking.png", 481.f, 10.f); //Jessica
	patients.back().setInfection(InfectionStatus::Infected);
	patients.back().setDialog({
		"Jessica: Hi.",
		"Player: What seems to be the problem?",
		"Jessica: Well I saw some symptoms on TV",
		"Jessica: ...and I'm not sure if it's the symptom or\n chili in my mouth.",
		"Player: What?",
		"Jessica: Ummm yeah I had a family dinner.",
		"Player: Okay...",
		"Player: What do you want to check?"
		});
	patients.back().patient_normal();
	
	patients.emplace_back("Patients/baka.png", "Patients/baka_talking.png", 481.f, 10.f); //Baka
	patients.back().setInfection(InfectionStatus::Infected);
	patients.back().setDialog({
		"Granny: Hello.",
		"Player: Hi, what seems to be the problem?",
		"Granny: Well thy self simply arrived for a checkup.",
		"Granny: Would thou love to have some\n tea and biscuits with me, after this?",
		"Player No thank you granny...",
		"Granny: Alas! A plague on both your houses.",
		"Player: What do you want to check?"
		});
	patients.back().patient_normal();

	patients.emplace_back("Patients/shy_lady.png", "Patients/shy_lady_talking.png", 481.f, 10.f); //Aurora
	patients.back().setInfection(InfectionStatus::Healthy);
	patients.back().setDialog({
		"Aurora: Hi... I need your help...",
		"Player: What seems to be the problem?",
		"Aurora: I can't stop coughing...",
		"Player: What do you want to check?"
		});
	patients.back().patient_normal();

	//postavila sam pointer na prvog pacijenta
	if (!patients.empty()){
		activePatient = &patients[0];
	}
	//luka
	patients[0].setBoxTextures(1, "boxes/luka_leg.png");
	patients[0].setBoxTextures(2, "boxes/luka_moouth.png");
	//toma
	patients[1].setBoxTextures(1, "boxes/kid_bite.png");
	patients[1].setBoxTextures(2, "boxes/kid_mouth.png");
	//jessica
	patients[2].setBoxTextures(1, "boxes/jessica_bite.png");
	patients[2].setBoxTextures(2, "boxes/jessica_mouth.png");
	//box3 i box4 za pacijente nakon 2. i 4.
	patients[2].setBoxTextures(3, "boxes/jessica_body.png");
	//baka
	patients[3].setBoxTextures(1, "boxes/baka_bite.png");
	patients[3].setBoxTextures(2, "boxes/baka_mouth.png");
	patients[3].setBoxTextures(3, "boxes/baka_body.png");
	//aurora
	patients[4].setBoxTextures(1, "boxes/shy_girl_bite.png");
	patients[4].setBoxTextures(2, "boxes/shy_girl_mouth.png");
	patients[4].setBoxTextures(3, "boxes/shy_girl_body.png");
	patients[4].setBoxTextures(4, "boxes/shy_girl_skin.png");
}

void Game::initMenu()
{
	symptomTextures.resize(4);
	symptomSprites.resize(4);

	symptomTextures[0].loadFromFile("menu/menu_1simptom.png");
	symptomTextures[1].loadFromFile("menu/menu_2_simptom.png");
	symptomTextures[2].loadFromFile("menu/menu_3simptom.png");
	symptomTextures[3].loadFromFile("menu/menu_4simptom.png");

	for (int i = 0; i < 4; i++)
	{
		symptomSprites[i].setTexture(symptomTextures[i]);
		symptomSprites[i].setPosition(8.f, 10.f);
		symptomSprites[i].setScale(
			800.f / symptomTextures[i].getSize().x,
			600.f / symptomTextures[i].getSize().y
		);
	}
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
	//dan2
	this->botun3 = new Botun();
	this->botun3->body();
	this->botun3->setPosition({ 310.f, 530.f });
	//dan3
	this->botun4 = new Botun();
	this->botun4->skin();
	this->botun4->setPosition({ 480.f, 530.f });
}

void Game::initBox()
{
	reportBotun = new Botun();
	reportBotun->botunReport();
	reportBotun->setPosition({ 120.f, 250.f });

	letGoBotun = new Botun();
	letGoBotun->botunLetGo();
	letGoBotun->setPosition({ 235.f, 250.f });

	backBotun = new Botun();
	backBotun->botunBack();
	backBotun->setPosition({ 350.f, 250.f });
}

void Game::initBackground()
{
	this->backgroundTexture.loadFromFile("Background/hospital.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);
}

void Game::initEnding()
{
	goodEndingTexture.loadFromFile("Background/good_ending.png");
	goodEndingSprite.setTexture(goodEndingTexture);

	badEndingTexture.loadFromFile("Background/bad_ending.png");
	badEndingSprite.setTexture(badEndingTexture);

	endingText = new Text(this->font, 28);
	endingText->setPosition({ 200.f, 420.f });
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initBackground();
	this->initPatients();
	this->initTextBox();
	this->initBox();
	this->initMenu();
	this->initEnding();
}

Game::~Game() {
	delete this->text;
	delete this->textbox;
	delete this->window;
	delete endingText;
}

bool Game::running() const
{
	return this->window->isOpen();
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

		if (ev.type == sf::Event::KeyPressed &&
			ev.key.code == sf::Keyboard::E)
		{
			menuOpen = !menuOpen;
			currentSymptomIndex = 0;

			if (menuOpen)
				player.player_menu();
			else
				player.player_normal();
		}

		//navigacija
		if (menuOpen && ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Right &&
				currentSymptomIndex < symptomSprites.size() - 1)
			{
				currentSymptomIndex++;
			}
			else if (ev.key.code == sf::Keyboard::Left &&
				currentSymptomIndex > 0)
			{
				currentSymptomIndex--;
			}
		}
		
	}
}

void Game::update() {

	this->pollEvents();

	if (gameState != GameState::Playing)
		return;

	this->mouse.update(*this->window);

	if (activeBox != 0)
	{
		if (reportBotun->isClicked(mouse))
		{
			decisionTracker.evaluate(
				activePatient->isInfected(),
				true
			);

			activePatient->report();
			currentPatientIndex++;
			if (currentPatientIndex < patients.size())
				activePatient = &patients[currentPatientIndex];
			else
				activePatient = nullptr; //kraj svih pacijenata

			activeBox = 0;
			dijalog.stop();
			return;
		}
		if (letGoBotun->isClicked(mouse))
		{
			decisionTracker.evaluate(
				activePatient->isInfected(),
				false
			);

			activePatient->report();
			currentPatientIndex++;
			if (currentPatientIndex < patients.size())
			{ 
				activePatient = &patients[currentPatientIndex];
			}
			else{
				activePatient = nullptr;
				if (decisionTracker.getWrong() == 0)
				{
					gameState = GameState::GoodEnding;
					endingText->setText(
						"You saved the city.\n"
						"But for how long?"
					);
				}
				else
				{
					gameState = GameState::BadEnding;
					endingText->setText(
						"Your actions have consequences.\n"
						"The city is doomed."
					);
				}
			}
			activeBox = 0;
			dijalog.stop();
			return;
		}
		if (backBotun->isClicked(mouse))
		{
			if (activePatient)
				activePatient->back();

			activeBox = 0;
		}
		return;//da bokliram sve ostalo
	}


	this->player.update(*this->window);
	for (auto& p : this->patients)
	{
		p.update();
	}

	if (activePatient)
		activePatient->update();

	// dijalog
	if (dijalog.isActive())
	{
		//pomocu ove recenice ulazi se u choice mode
		if (dijalog.getCurrentDijalog() == "Player: What do you want to check?")
			dijalog.enterChoice();

		if (dijalog.isInChoice())
		{
			if (botun1->isClicked(mouse)) { dijalog.leaveChoice(); activeBox = 1; return; }
			if (botun2->isClicked(mouse)) { dijalog.leaveChoice(); activeBox = 2; return; }
			if (currentPatientIndex >= 2 && botun3->isClicked(mouse)) { dijalog.leaveChoice(); activeBox = 3; return; }
			if (currentPatientIndex >= 4 && botun4->isClicked(mouse)) { dijalog.leaveChoice(); activeBox = 4; return; }

			text->setText(dijalog.getCurrentDijalog());
			return;
		}

		if (mouse.isLeftClicked())
		{
			dijalog.next();
			if (!dijalog.isActive() && activePatient)
			{
				activePatient->patient_normal();
			}
		}

		text->setText(dijalog.getCurrentDijalog());
		return;
	}
	
	if (mouse.isLeftClicked() && activePatient)
	{
		if (activePatient->getBounds().contains(static_cast<sf::Vector2f>(mouse.getMousePos())))
		{
			dijalog.start(activePatient->getDialog());
			player.player_talking();
			activePatient->patient_talking();
			text->setText(dijalog.getCurrentDijalog());
		}
	}
	if (!dijalog.isActive() && activePatient)
	{
		activePatient->patient_normal();
		player.player_normal();
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

	//pacijent se crta samo kad je aktivan
	if (activePatient && activePatient->isActive())
		activePatient->render(*window);
	/*
	for (auto& p : patients)
	{
		if (p.isActive())
		{
			p.render(*window);
		}
	}*/


	if (this->dijalog.isActive())
	{
		this->textbox->draw(*this->window);
		this->text->draw(*this->window);
		if (dijalog.isInChoice())
		{
			this->botun1->draw(*this->window);
			this->botun2->draw(*this->window);
			if (currentPatientIndex >= 2) this->botun3->draw(*this->window); //nakon dva pacijenta
			if (currentPatientIndex >= 4) this->botun4->draw(*this->window); //nakon četiri pacijenta
		}
	}

	if (activeBox >= 1 && activeBox <= 4)
	{
		this->window->draw(activePatient->getBoxSprite(activeBox));

		reportBotun->draw(*this->window);
		letGoBotun->draw(*this->window);
		backBotun->draw(*this->window);
	}

	if (menuOpen)
	{
		this->window->draw(symptomSprites[currentSymptomIndex]);
	}

	this->player.render(*this->window);

	//this->patient->render(*this->window);
	//this->window->draw(this->pat);

	if (gameState == GameState::GoodEnding)
	{
		window->draw(goodEndingSprite);
		endingText->draw(*window);
	}
	else if (gameState == GameState::BadEnding)
	{
		window->draw(badEndingSprite);
		endingText->draw(*window);
	}

	this->window->display();
}
