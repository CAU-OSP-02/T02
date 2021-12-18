#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1440, 1080)
		, "OSP_T02_Team2"
		, sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initGui()
{
	this->font.loadFromFile("Fonts/FIGHTT3_.ttf");

	this->titleText.setFont(this->font);
	this->titleText.setFillColor(sf::Color::Black);
	this->titleText.setString("[23 : 58]");

	this->pointText.setFont(this->font);
	this->pointText.setFillColor(sf::Color::Black);

	this->highPointText.setFont(this->font);
	this->highPointText.setFillColor(sf::Color::Black);

	this->gameOverText.setFont(this->font);
	this->gameOverText.setFillColor(sf::Color::Black);
	this->gameOverText.setString("GAME OVER");

	this->gameRetryText.setFont(this->font);
	this->gameRetryText.setFillColor(sf::Color::Red);
	this->gameRetryText.setString("Try Again? (Y / N)");

	this->playerHpText.setFont(this->font);
	this->playerHpText.setFillColor(sf::Color::White);

	this->playerAttackText.setFont(this->font);
	this->playerAttackText.setFillColor(sf::Color::Blue);

	this->playerSpeedText.setFont(this->font);
	this->playerSpeedText.setFillColor(sf::Color::Magenta);

	this->playerHpBar.setFillColor(sf::Color(200, 20, 20, 100));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 100));

	this->playerHpBarBot.setFillColor(sf::Color(184, 184, 178, 100));

	this->playerAbility.setFillColor(sf::Color(184, 184, 178, 100));

	this->playerItem.setFillColor(sf::Color(184, 184, 178, 100));
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

void Game::initWorld()
{
	this->worldBackgroundTexture.loadFromFile("Images/Map/Map.png");
	this->worldBackground.setTexture(this->worldBackgroundTexture);

	this->view.setViewport(sf::FloatRect(0, 0, 1, 1));
	this->zoom = 1.f;
}

void Game::initPlayer()
{
	this->player = new Player();
	this->level = 1;
	this->points = 190;
	this->player->setPosition(4000, 4000);
}

void Game::initBullet()
{
	bullets.clear();
}

void Game::initVillains()
{
	villains.clear();
	this->spawnTimerVillainMax = 100.f;
	this->spawnTimerVillain = this->spawnTimerVillainMax;
}

void Game::initItems()
{
	items.clear();
	this->spawnTimerItemMax = 200.f;
	this->spawnTimerItem = 0.f;

	this->itemEffectTimerMax = 100.f;
	this->itemEffectTimer = 0.f;
}

void Game::initGame()
{
	this->initSystem();
	this->initPlayer();
	this->initVillains();
	this->initItems();
}

Game::Game()
{
	this->initWindow();

	this->initGame();
	this->initGui();
	this->initWorld();
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
		{
			this->update();
		}

		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				saveHigh();
				this->player->setHP(this->player->getHpMax());

				initGame();
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				saveHigh();
				this->window->close();
			}
		}

		this->render();
	}
}

void Game::saveHigh()
{
	if (points > highPoints)
	{
		FILE* file = fopen("score.dat", "wt");
		fprintf(file, "%d", points);
		fclose(file);
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

		if (this->state == 0)
		{
			this->villains.push_back(new Villain(
				-100,
				rand() % 8200,
				rand() % level + 1));
		}

		else if (this->state == 1)
		{
			this->villains.push_back(new Villain(
				100,
				rand() % 8200,
				rand() % level + 1));
		}

		else if (this->state == 2)
		{
			this->villains.push_back(new Villain(
				rand() % 8200,
				-100,
				rand() % level + 1));
		}

		else if (this->state == 3)
		{
			this->villains.push_back(new Villain(
				rand() % 8200,
				100,
				rand() % level + 1));
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
			this->player->loseHP(this->villains.at(counter)->getDamage());
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
			rand() % 8400 - 200,
			rand() % 8400 - 200,
			rand() % 4 + 1));

		this->spawnTimerItem = 0.f;
	}

	unsigned counter = 0;
	for (auto* item : this->items)
	{
		if (item->getBounds().intersects(this->player->getBounds()))
		{
			if (this->items.at(counter)->getType() == 1)
			{
				this->zoom = 1.8f;
			}
			else if (this->items.at(counter)->getType() == 2)
			{
				this->player->setDamage(1.f);
			}
			else if (this->items.at(counter)->getType() == 3)
			{
				this->player->setHP(
					this->player->getHp() +
					this->items.at(counter)->getHp());
			}
			else if (this->items.at(counter)->getType() == 4)
			{
				this->player->setSpeed(10.f);
			}

			itemBtn = 1;
			spawnTimerItem = 0;
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
		}
		++counter;
	}
}

void Game::updateReset()
{
	if (itemBtn == 1)
	{
		this->itemEffectTimer += 0.5f;
	}

	if (this->itemEffectTimer > this->itemEffectTimerMax)
	{
		this->player->setSpeed(5.f);
		this->zoom = 1.f;
		this->itemBtn = 0;
		this->itemEffectTimer = 0.f;
	}
}

void Game::updateWorld()
{
	this->view.setCenter(
		this->player->getPosition().x + this->player->getBounds().width / 2,
		this->player->getPosition().y + this->player->getBounds().height / 2);

	this->view.setSize(sf::Vector2f(1440 * zoom, 1080 * zoom));
	this->window->setView(view);

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

void Game::updateLevel()
{
	if (points >= 150)
	{
		this->level = 2;
	}

	else if (points >= 400)
	{
		this->level = 3;
	}

	else if (points >= 700)
	{
		this->level = 4;
	}
}

void Game::updateGui()
{
	std::stringstream ss;
	std::stringstream ss_2;
	std::stringstream hpContext;
	std::stringstream playerAttack;
	std::stringstream playerSpeed;

	ss << "SCORE : " << this->points;
	ss_2 << "BEST SCORE : " << this->highPoints;

	hpContext << this->player->getHp() << " / " << this->player->getHpMax() << endl;
	playerAttack << "Attack : " << this->player->getDamage() << endl;
	playerSpeed << "Speed : " << this->player->getSpeed() << endl;

	this->pointText.setString(ss.str());
	this->highPointText.setString(ss_2.str());
	this->playerHpText.setString(hpContext.str());
	this->playerAttackText.setString(playerAttack.str());
	this->playerSpeedText.setString(playerSpeed.str());

	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

	// size
	this->titleText.setCharacterSize(50 * zoom);
	this->pointText.setCharacterSize(70 * zoom);
	this->highPointText.setCharacterSize(30 * zoom);
	this->gameOverText.setCharacterSize(150 * zoom);
	this->playerHpText.setCharacterSize(40 * zoom);
	this->playerAttackText.setCharacterSize(30 * zoom);
	this->playerSpeedText.setCharacterSize(30 * zoom);
	this->playerHpBar.setSize(sf::Vector2f(300.f * zoom, 50.f * zoom));
	this->playerHpBarBack.setSize(sf::Vector2f(300.f * zoom, 50.f * zoom));
	this->playerHpBarBot.setSize(sf::Vector2f(320.f * zoom, 70.f * zoom));
	this->playerAbility.setSize(sf::Vector2f(200.f * zoom, 70.f * zoom));
	this->playerItem.setSize(sf::Vector2f(200.f * zoom, 200.f * zoom));

	this->titleText.setPosition(view.getCenter().x - 700.f * zoom, view.getCenter().y - 540.f * zoom);
	this->pointText.setPosition(view.getCenter().x - 120.f * zoom, view.getCenter().y - 510.f * zoom);
	this->highPointText.setPosition(view.getCenter().x - 60.f * zoom, view.getCenter().y - 540.f * zoom);
	this->gameOverText.setPosition(
		view.getCenter().x - this->gameOverText.getGlobalBounds().width / 2.f,
		view.getCenter().y - this->gameOverText.getGlobalBounds().height / 2.f - 100);
	this->playerHpText.setPosition(
		view.getCenter().x - playerHpText.getGlobalBounds().width / 2,
		view.getCenter().y + 360.f * zoom);
	this->playerAttackText.setPosition(view.getCenter().x - 370.f * zoom, view.getCenter().y + 350.f * zoom);
	this->playerSpeedText.setPosition(view.getCenter().x - 370.f * zoom, view.getCenter().y + 380.f * zoom);

	this->playerHpBar.setPosition(view.getCenter().x - 150.f * zoom, view.getCenter().y + 360.f * zoom);
	this->playerHpBarBack.setPosition(view.getCenter().x - 150.f * zoom, view.getCenter().y + 360.f * zoom);
	this->playerHpBarBot.setPosition(view.getCenter().x - 160.f * zoom, view.getCenter().y + 350.f * zoom);
	this->playerAbility.setPosition(view.getCenter().x - 420.f * zoom, view.getCenter().y + 350.f * zoom);
	this->playerItem.setPosition(view.getCenter().x - 690.f * zoom, view.getCenter().y + 260.f * zoom);
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

void Game::updateCollision()
{
	if (this->player->getBounds().left < 20.f)
	{
		this->player->setPosition(20.f, this->player->getBounds().top);
	}

	else if (this->player->getBounds().left + this->player->getBounds().width >= 8457 - 20)
	{
		this->player->setPosition(8457 - 20 - this->player->getBounds().width, this->player->getBounds().top);
	}

	if (this->player->getBounds().top < 20.f)
	{
		this->player->setPosition(this->player->getBounds().left, 20.f);
	}

	else if (this->player->getBounds().top + this->player->getBounds().height >= 8457 + 20)
	{
		this->player->setPosition(this->player->getBounds().left, 8457 + 20 - this->player->getBounds().height);
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

		if (bullet->getBounds().top + bullet->getBounds().height <= 0.f
			|| bullet->getBounds().top >= 8457
			|| bullet->getBounds().left + bullet->getBounds().width <= 0.f
			|| bullet->getBounds().left >= 8457)
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

	this->updateReset();

	this->updateCollision();

	this->updatePlayer();

	this->updateBullets();

	this->updateVillains();

	this->updateItems();

	this->updateCombat();

	this->updateGui();
}

void Game::renderGui()
{
	this->window->draw(this->titleText);

	this->window->draw(this->pointText);
	this->window->draw(this->highPointText);

	this->window->draw(this->playerHpBarBot);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	this->window->draw(this->playerAbility);
	this->window->draw(this->playerItem);

	this->window->draw(this->playerHpText);
	this->window->draw(this->playerAttackText);
	this->window->draw(this->playerSpeedText);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::renderObjects()
{
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
}

void Game::render()
{
	this->window->clear();

	this->renderWorld();

	if (this->player->getHp() > 0)
	{
		this->renderObjects();
	}

	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->gameOverText);
		this->window->draw(this->gameRetryText);
	}


	this->renderGui();

	this->window->display();
}