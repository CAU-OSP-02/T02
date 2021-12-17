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
}

void Game::initWorld()
{
	this->worldBackgroundTexture.loadFromFile("Images/background.jpg");
	this->worldBackground.setTexture(this->worldBackgroundTexture);
	this->worldBackground.setScale(1.3f, 1.1f);
}

void Game::initPlayer()
{
	this->player = new Player();
	this->player->setPosition(500, 600);
}

void Game::initBullet()
{

}

void Game::initVillains()
{
	this->spawnTimerVillainMax = 40.f;
	this->spawnTimerVillain = this->spawnTimerVillainMax;
}

void Game::initItems()
{
	this->spawnTimerItemMax = 200.f;
	this->spawnTimerItem = this->spawnTimerItemMax;
}

Game::Game()
{
	this->initWindow();
	this->initWorld();
	this->initPlayer();
	this->initVillains();
	this->initItems();
}

Game::~Game()
{
	delete this->window;

	delete this->player;

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
		if (this->player->getHp() > 0)
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

	// 창 밖으로 나가면 삭제이긴 한데 넣어도 그만 안 넣어도 그만
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

void Game::updateItems()
{
	this->spawnTimerItem += 0.5f;
	if (this->spawnTimerItem >= spawnTimerItemMax)
	{
		this->items.push_back(new Item(
			250.f,
			100.f,
			1));
		this->spawnTimerItem = 0.f;
	}

	unsigned counter = 0;
	for (auto* item : this->items)
	{
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

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
		this->bullets.push_back(new Bullet(
			this->player->getPosition().x + this->player->getBounds().width / 2.f - 30,
			this->player->getPosition().y,
			0.f, -1.f, 5.f));
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}

		++counter;
	}
}

void Game::update()
{
	this->updateWorld();

	this->updateInput();
	
	this->updatePlayer();

	this->updateBullets();

	this->updateVillains();

	this->updateItems();
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	this->renderWorld();

	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}


	for (auto* villain : this->villains)
	{
		villain->render(this->window);
	}

	for (auto* item : this->items)
	{
		item->render(this->window);
	}

	this->window->display();
}

