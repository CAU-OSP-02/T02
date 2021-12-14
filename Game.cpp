#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(width, height)
		, "OSP_T02_Team2"
		, sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["VILLAINS"] = new sf::Texture();
	this->textures["VILLAINS"]->loadFromFile("Images/bullet.png");
}

void Game::initWorld()
{
	this->worldBackgroundTexture.loadFromFile("Images/background.jpg");
	this->worldBackground.setTexture(this->worldBackgroundTexture);
	this->worldBackground.setScale(1.3f, 1.1f);
}

void Game::initVillains()
{
	this->spawnTimerVillainMax = 40.f;
	this->spawnTimerVillain = this->spawnTimerVillainMax;
}

Game::Game()
{
	this->initWindow();
	this->initWorld();
	this->initVillains();
}

Game::~Game()
{
	delete this->window;

	for (auto* i : this->villains)
	{
		delete i;
	}
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();
		this->update();
		this->render();
	}
}

void Game::updatePollEvent()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateVillains()
{
	this->spawnTimerVillain += 0.5f;
	if (this->spawnTimerVillain >= spawnTimerVillainMax)
	{
		this->villains.push_back(new Villain(
			250.f,
			-100.f,
			1));
		this->spawnTimerVillain = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* villain : this->villains)
	{
		villain->update();

		if (villain->getBounds().top > this->window->getSize().y)
		{
			delete this->villains.at(counter);
			this->villains.erase(this->villains.begin() + counter);
		}

		/*
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->looseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		++counter;
		*/
	}
}

void Game::updateWorld()
{
}

void Game::update()
{
	this->updateVillains();

	this->updateWorld();
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	this->renderWorld();

	for (auto* villain : this->villains)
	{
		villain->render(this->window);
	}

	this->window->display();
}

