#include "Game.h"

//private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720)
				, "OSP_T02_Team2"
				, sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Images/bullet.png");
}

void Game::initGUI()
{
	this->font.loadFromFile("Fonts/FIGHTT3_.ttf");

	this->titleText.setFont(this->font);
	this->titleText.setCharacterSize(70);
	this->titleText.setFillColor(sf::Color::Black);
	this->titleText.setPosition(20.f, 20.f);
	this->titleText.setString("OPEN SOURCE");

	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(50);
	this->pointText.setFillColor(sf::Color::Black);
	this->pointText.setPosition(20.f, 100.f);

	this->highPointText.setFont(this->font);
	this->highPointText.setCharacterSize(50);
	this->highPointText.setFillColor(sf::Color::Black);
	this->highPointText.setPosition(20.f, 150.f);

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(300);
	this->gameOverText.setFillColor(sf::Color::Black);
	this->gameOverText.setPosition(650.f, 250.f);
	this->gameOverText.setString("GAME OVER");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2 - this->gameOverText.getGlobalBounds().width/2.f,
		this->window->getSize().y / 2 - this->gameOverText.getGlobalBounds().height/2.f - 100);


	this->playerHpBar.setSize(sf::Vector2f(230.f, 30.f));
	this->playerHpBar.setFillColor(sf::Color(200, 20, 20, 100));
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 220.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 100));

	this->playerHpBarBot.setSize(sf::Vector2f(240.f, 40.f));
	this->playerHpBarBot.setFillColor(sf::Color(184, 184, 178, 100));
	this->playerHpBarBot.setPosition(sf::Vector2f(15.f, 215.f));
}

void Game::initWorld()
{
	this->worldBackgroundTexture.loadFromFile("Images/background.jpg");
	this->worldBackground.setTexture(this->worldBackgroundTexture);
	this->worldBackground.setScale(1.3f, 1.1f);
}

void Game::initSystem()
{
	FILE* file = fopen("score.dat", "rt");
	if (file == 0)
	{
		highPoints = 0;
	}
	else
	{
		fscanf(file, "%d", &highPoints);
		fclose(file);
	}

	this->points = 0;
}

void Game::initEnemies()
{
	this->spawnTimerEnemyMax = 40.f;
	this->spawnTimerEnemy = this->spawnTimerEnemyMax;
}

void Game::InitItems()
{
	this->spawnTimerItemMax = 280.f;
	this->spawnTimerItem = this->spawnTimerItemMax;
}

void Game::initPlayer()
{
	this->player = new Player(1);
}
//Constructor
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
	this->initSystem();
	this->initPlayer();
	this->initEnemies();
	this->InitItems();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	for (auto &i : this->textures)
	{
		delete i.second;
	}

	for (auto *i : this->bullets)
	{
		delete i;
	}

	for (auto* i : this->enemies)
	{
		delete i;
	}
}

//functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();
		if(this->player->getHp() > 0)
			this->update();
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateInput()
{	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
		this->bullets.push_back(new Bullet(this->textures["BULLET"], 
		this->player->getPos().x + this->player->getBounds().width/2.f - 30,
		this->player->getPos().y,
		0.f, -1.f, 5.f));

}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto *bullet : this->bullets)
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

void Game::updateEnemies()
{
	//Spawn
	this->spawnTimerEnemy += 0.5f;
	if (this->spawnTimerEnemy >= spawnTimerEnemyMax)
	{
		this->enemies.push_back(new Enemy(rand() % 750 + 250.f, -100.f));
		this->spawnTimerEnemy = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		if (enemy->getBounds().top > this->window->getSize().y)
		{
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->looseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		++counter;
	}
}

void Game::updateItems()
{
	//Spawn
	this->spawnTimerItem += 0.5f;
	if (this->spawnTimerItem >= spawnTimerItemMax)
	{
		this->items.push_back(new Item(rand() % 750 + 250.f, -100.f));
		this->spawnTimerItem = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* item : this->items)
	{
		item->update();

		if (item->getBounds().top > this->window->getSize().y)
		{
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
		}
		else if (item->getBounds().intersects(this->player->getBounds()))
		{
			this->player->looseHp(this->items.at(counter)->getDamage());
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
		}
		++counter;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;

		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();

				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
		}
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	std::stringstream ss_2;

	ss << "SCORE: " << this->points;
	ss_2 << "BEST SCORE: " << this->highPoints;

	this->pointText.setString(ss.str());
	this->highPointText.setString(ss_2.str());

	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(230.f * hpPercent, this->playerHpBar.getSize().y));
}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
	if (this->player->getBounds().left < 180.f)
	{
		this->player->setPosition(180.f, this->player->getBounds().top);
	}

	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}

	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y + 20)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y + 20 - this->player->getBounds().height);
	}
	
}

void Game::update()
{

	this->updateInput();

	this->player->update();

	this->updateCollision();

	this->updateBullets();

	this->updateCombat();

	this->updateEnemies();

	this->updateItems();

	this->updateGUI();

	this->updateWorld();
}

void Game::renderGUI()
{
	this->window->draw(this->titleText);
	this->window->draw(this->pointText);
	this->window->draw(this->highPointText);

	this->window->draw(this->playerHpBarBot);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);

}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	this->renderWorld();

	//Draw all the stuffs
	this->player->render(*this->window);

	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	for (auto* item : this->items)
	{
		item->render(this->window);
	}

	this->renderGUI();

	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->gameOverText);
		if (points > highPoints)
		{
			FILE* file = fopen("score.dat", "wt");
			fprintf(file, "%d", points);
			fclose(file);
		}
	}

	this->window->display();
}