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

void Game::initGui()
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
		this->window->getSize().x / 2 - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2 - this->gameOverText.getGlobalBounds().height / 2.f - 100);


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
	this->spawnTimerVillainMax = 100.f;
	this->spawnTimerVillain = this->spawnTimerVillainMax;
}

void Game::initItems()
{
	this->spawnTimerItemMax = 200.f;
	//this->spawnTimerItem = 0.f;

	this->itemEffectTimerMax = 100.f;
	//this->itemEffectTimer = 0.f;
}

void Game::initGame()
{
	this->initPlayer();
	this->initVillains();
	this->initItems();
}

Game::Game()
{
	this->initWindow();
	this->initWorld();
	this->initGui();

	this->initGame();
}

Game::~Game()
{
	delete this->window;

	this->updateDelete();
}

void Game::updateDelete()
{
	delete this->player;

	for (auto* i : this->bullets)
	{
		delete i;
	}
	for (auto* i : this->items)
	{
		delete i;
	}

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
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				updateDelete();
				initGame();
			}
		}

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
		this->state = rand() % 4;

		if (this-> state == 0)
		{
			this->villains.push_back(new Villain(
				-100,
				rand() % 1080,
				1));
		}

		else if (this->state == 1)
		{
			this->villains.push_back(new Villain(
				100,
				rand() % 1080,
				1));
		}

		else if (this->state == 2)
		{
			this->villains.push_back(new Villain(
				rand() % 1440,
				-100,
				1));
		}

		else if (this->state == 3)
		{
			this->villains.push_back(new Villain(
				rand() % 1440,
				100,
				1));
		}

		this->spawnTimerVillain = 0.f;
	}

	unsigned counter = 0;
	for (auto* villain : this->villains)
	{
		villain->update();

		float x = this->player->getPosition().x - villain->getPosition().x;
		float y = this->player->getPosition().y - villain->getPosition().y;
		float r = sqrt(x * x + y * y);

		villain->setDir(x / r, y / r);

		if (villain->getBounds().intersects(this->player->getBounds()))
		{
			//this->player->loseHP(this->villains.at(counter)->getDamage());
			delete this->villains.at(counter);
			this->villains.erase(this->villains.begin() + counter);
		}
		++counter;
	}
}

void Game::updateItems()
{
	this->spawnTimerItem += 0.5f;
	if (this->spawnTimerItem >= spawnTimerItemMax)
	{
		this->items.push_back(new Item(
			rand() % 1440,
			rand() % 1080,
			2));

		this->spawnTimerItem = 0.f;
	}

	unsigned counter = 0;
	for (auto* item : this->items)
	{
		cout << item << endl;
		if (item->getBounds().intersects(this->player->getBounds()))
		{
			if (this->items.at(counter)->getType() == 1)
			{

			}
			else if (this->items.at(counter)->getType() == 2)
			{
				//this->player->setAttackSpeed(3.f);
			}
			else if (this->items.at(counter)->getType() == 3)
			{
				this->player->setHP(
					this->player->getHp() +
					this->items.at(counter)->getHp());
			}
			else if (this->items.at(counter)->getType() == 4)
			{
				this->player->setSpeed(
					this->player->getSpeed() +
					this->items.at(counter)->getSpeed());
			}
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
		}
		++counter;
	}
}

void Game::updateWorld()
{
}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(
			this->player->getPosition().x + this->player->getBounds().width / 2.f,
			this->player->getPosition().y + this->player->getBounds().height / 2.f,
			this->player->getDirection().x,
			this->player->getDirection().y));
	}
}

void Game::updateGui()
{
	/*std::stringstream ss;
	std::stringstream ss_2;

	ss << "SCORE: " << this->points;
	ss_2 << "BEST SCORE: " << this->highPoints;

	this->pointText.setString(ss.str());
	this->highPointText.setString(ss_2.str());
	*/

	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(230.f * hpPercent, this->playerHpBar.getSize().y));
}

void Game::updateCombat()
{
	for (int i = 0; i < this->villains.size(); ++i)
	{
		bool enemy_deleted = false;

		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->villains[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->villains[i]->getPoints();

				delete this->villains[i];
				this->villains.erase(this->villains.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
		}
	}
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

		if (bullet->getBounds().top + bullet->getBounds().height < 0.f
			|| bullet->getBounds().top > 1080
			|| bullet->getBounds().left + bullet->getBounds().width < 0.f
			|| bullet->getBounds().left > 1440)
		{
			cout << bullet << endl;
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}

		++counter;
	}
}

void Game::update()
{
	this->updateWorld();

	this->updateGui();

	this->updateInput();
	
	this->updatePlayer();

	this->updateBullets();

	this->updateVillains();

	this->updateItems();

	this->updateCombat();
}

void Game::renderGui()
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

	this->renderGui();

	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->gameOverText);
	}

	this->window->display();
}