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

	this->playerLevelText.setFont(this->font);
	this->playerLevelText.setFillColor(sf::Color::Black);

	this->playerAttackText.setFont(this->font);
	this->playerAttackText.setFillColor(sf::Color::Black);

	this->playerSpeedText.setFont(this->font);
	this->playerSpeedText.setFillColor(sf::Color::Black);

	this->playerHpBar.setFillColor(sf::Color(200, 20, 20, 100));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 100));

	this->playerHpBarBot.setFillColor(sf::Color(184, 184, 178, 100));

	this->playerAbility.setFillColor(sf::Color(184, 184, 178, 100));
}

void Game::initSystem()
{
	music.openFromFile("Audios/background.ogg");
	finger.loadFromFile("Audios/finger.ogg");
	health.loadFromFile("Audios/health.ogg");
	bus.loadFromFile("Audios/bus.ogg");
	latte.loadFromFile("Audios/latte.ogg");

	sound_1.setBuffer(finger);
	sound_2.setBuffer(health);
	sound_3.setBuffer(bus);
	sound_4.setBuffer(latte);

	this->music.setLoop(true);
	this->music.play();

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
	this->ui.setCenter(720, 540);
	this->zoom = 1.f;
}

void Game::initPlayer()
{
	this->player = new Player();
	this->level = 1;
	this->points = 400;
	this->player->setPosition(1000, 1000);
}

void Game::initBullet()
{
	bullets.clear();
}

void Game::initVillains()
{
	villains.clear();
	this->spawnTimerVillainMax = 200.f;
	this->spawnTimerVillain = this->spawnTimerVillainMax;

	this->villainTimerMax = 100.f;
	this->villainTimer = 0.f;
}

void Game::initBosses()
{
	bosses.clear();
	enemyBullets.clear();
	this->spawnTimerBossMax = 1000.f;
	this->spawnTimerBoss = this->spawnTimerBossMax;
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
	this->initBosses();
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

	for (Bullet* i : this->bullets)
	{
		delete i;
	}

	for (Item* i : this->items)
	{
		delete i;
	}

	for (Villain* i : this->villains)
	{
		delete i;
	}

	for (EnemyBullet* i : this->enemyBullets)
	{
		delete i;
	}

	for (Boss* i : bosses)
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
				float(rand() % 8200),
				rand() % (level) + 1));
		}

		else if (this->state == 1)
		{
			this->villains.push_back(new Villain(
				100,
				float(rand() % 8200),
				rand() % (level) + 1));
		}

		else if (this->state == 2)
		{
			this->villains.push_back(new Villain(
				float(rand() % 8200),
				-100,
				rand() % (level) + 1));
		}

		else if (this->state == 3)
		{
			this->villains.push_back(new Villain(
				float(rand() % 8200),
				100,
				rand() % (level) + 1));
		}

		this->spawnTimerVillain = 0.f;
	}
	

	unsigned counter = 0;
	for (Villain* villain : this->villains)
	{
		villain->update();

		float x = this->player->getPosition().x - villain->getPosition().x;
		float y = this->player->getPosition().y - villain->getPosition().y;
		float r = sqrt(x * x + y * y);

		villain->setDir(x / r, y / r);

		if (villain->getBounds().intersects(this->player->getBounds()))
		{
			if (villain->getType() == 1)
			{
				this->sound_1.play();
				sound_1.setPlayingOffset(sf::seconds(0.7));
			}

			if (villain->getType() == 2)
			{
				this->sound_2.play();
			}

			if (villain->getType() == 3)
			{
				this->sound_3.play();
			}

			this->player->loseHP(this->villains.at(counter)->getDamage());
			this->player->setSpeed(this->player->getSpeed() - this->villains.at(counter)->getSpeedDown());
			this->villainBtn = 1;
			this->villainTimer = 0.f;
			delete this->villains.at(counter);
			this->villains.erase(this->villains.begin() + counter);
		}
		++counter;
	}

}

void Game::updateBosses()
{
	this->spawnTimerBoss += 0.5f;

	if (level == 4)
	{
		if (this->spawnTimerBoss >= spawnTimerBossMax)
		{
			this->state_1 = rand() % 4;

			if (this->state == 0)
			{
				this->bosses.push_back(new Boss(
					-100,
					float(rand() % 8200),
					1));
			}

			else if (this->state == 1)
			{
				this->bosses.push_back(new Boss(
					100,
					float(rand() % 8200),
					1));
			}

			else if (this->state == 2)
			{
				this->bosses.push_back(new Boss(
					float(rand() % 8200),
					-100,
					1));
			}

			else if (this->state == 3)
			{
				this->bosses.push_back(new Boss(
					float(rand() % 8200),
					100,
					1));
			}
			this->spawnTimerBoss = 0.f;
		}
	}

	for (Boss* boss : this->bosses)
	{
		boss->update();

		float x = this->player->getPosition().x - boss->getPosition().x;
		float y = this->player->getPosition().y - boss->getPosition().y;
		float r = sqrt(x * x + y * y);

		boss->setDir(x / r, y / r);

		if (x * x + y * y < 16000)
		{
			boss->setBound(false);
		}
		else
		{
			boss->setBound(true);
		}
	}

	for (Boss* boss : this->bosses)
	{
		if (boss->canAttack())
		{
			this->enemyBullets.push_back(new EnemyBullet(
				boss->getPosition().x + boss->getBounds().width / 2.f,
				boss->getPosition().y + boss->getBounds().height / 2.f,
				boss->getDir().x,
				boss->getDir().y));
		}
	}
}

void Game::updateItems() 
{
	this->spawnTimerItem += 0.5f;
	if (this->spawnTimerItem >= spawnTimerItemMax)
	{
		this->items.push_back(new Item(
			rand() % 8200 + 200,
			rand() % 8200 + 200,
			rand() % 4 + 1));

		this->spawnTimerItem = 0.f;
	}

	unsigned counter = 0;
	for (Item* item : this->items)
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
			itemEffectTimer = 0.f;
			spawnTimerItem = 0.f;
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

	if (villainBtn == 1)
	{
		this->villainTimer += 0.5f;
	}

	if (this->villainTimer > this->villainTimerMax)
	{
		this->player->setSpeed(5.f);
		this->villainBtn = 0;
		this->villainTimer = 0.f;
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

	if (points >= 400)
	{
		this->level = 3;
	}

	if (points >= 700)
	{
		this->level = 4;
	}
}

void Game::updateGui()
{
	std::stringstream ss;
	std::stringstream ss_2;
	std::stringstream hpContext;
	std::stringstream playerLevel;
	std::stringstream playerAttack;
	std::stringstream playerSpeed;

	ss << "SCORE : " << this->points;
	ss_2 << "BEST SCORE : " << this->highPoints;

	hpContext << this->player->getHp() << " / " << this->player->getHpMax() << endl;
	playerLevel << "Level : " << this->level << endl;
	playerAttack << "Attack : " << this->player->getDamage() << endl;
	playerSpeed << "Speed : " << this->player->getSpeed() << endl;

	this->pointText.setString(ss.str());
	this->highPointText.setString(ss_2.str());
	this->playerHpText.setString(hpContext.str());
	this->playerLevelText.setString(playerLevel.str());
	this->playerAttackText.setString(playerAttack.str());
	this->playerSpeedText.setString(playerSpeed.str());

	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

	// size
	this->titleText.setCharacterSize(50 * zoom);
	this->pointText.setCharacterSize(70 * zoom);
	this->highPointText.setCharacterSize(30 * zoom);
	this->gameOverText.setCharacterSize(150 * zoom);
	this->gameRetryText.setCharacterSize(50 * zoom);
	this->playerHpText.setCharacterSize(40 * zoom);
	this->playerLevelText.setCharacterSize(30 * zoom);
	this->playerAttackText.setCharacterSize(30 * zoom);
	this->playerSpeedText.setCharacterSize(30 * zoom);
	this->playerHpBar.setSize(sf::Vector2f(300.f * zoom * hpPercent, 50.f * zoom));
	this->playerHpBarBack.setSize(sf::Vector2f(300.f * zoom, 50.f * zoom));
	this->playerHpBarBot.setSize(sf::Vector2f(320.f * zoom, 70.f * zoom));
	this->playerAbility.setSize(sf::Vector2f(200.f * zoom, 120.f * zoom));


	this->titleText.setPosition(view.getCenter().x - 700.f * zoom, view.getCenter().y - 540.f * zoom);
	this->pointText.setPosition(view.getCenter().x - 120.f * zoom, view.getCenter().y - 510.f * zoom);
	this->highPointText.setPosition(view.getCenter().x - 60.f * zoom, view.getCenter().y - 540.f * zoom);
	this->gameOverText.setPosition(
		view.getCenter().x - this->gameOverText.getGlobalBounds().width / 2.f,
		view.getCenter().y - this->gameOverText.getGlobalBounds().height / 2.f - 100.f * zoom);
	this->gameRetryText.setPosition(
		view.getCenter().x - this->gameRetryText.getGlobalBounds().width / 2.f,
		view.getCenter().y - this->gameRetryText.getGlobalBounds().height / 2.f + 100.f * zoom);
	this->playerHpText.setPosition(
		view.getCenter().x - playerHpText.getGlobalBounds().width / 2,
		view.getCenter().y + 360.f * zoom);
	this->playerLevelText.setPosition(view.getCenter().x - 370.f * zoom, view.getCenter().y + 335.f * zoom);
	this->playerAttackText.setPosition(view.getCenter().x - 370.f * zoom, view.getCenter().y + 365.f * zoom);
	this->playerSpeedText.setPosition(view.getCenter().x - 370.f * zoom, view.getCenter().y + 395.f * zoom);

	this->playerHpBar.setPosition(view.getCenter().x - 150.f * zoom, view.getCenter().y + 360.f * zoom);
	this->playerHpBarBack.setPosition(view.getCenter().x - 150.f * zoom, view.getCenter().y + 360.f * zoom);
	this->playerHpBarBot.setPosition(view.getCenter().x - 160.f * zoom, view.getCenter().y + 350.f * zoom);
	this->playerAbility.setPosition(view.getCenter().x - 420.f * zoom, view.getCenter().y + 330.f * zoom);
}

void Game::updateCombat()
{
	for (size_t i = 0; i < this->villains.size(); ++i)
	{
		bool enemy_deleted = false;

		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->villains[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{

				

				this->villains[i]->setHp(this->villains[i]->getHp() - this->player->getDamage());

				if (this->villains[i]->getHp() <= 0)
				{
					this->points += this->villains[i]->getPoints();

					delete this->villains[i];
					this->villains.erase(this->villains.begin() + i);

					enemy_deleted = true;
				}
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
			}
		}
	}

	for (size_t i = 0; i < this->bosses.size(); ++i)
	{
		bool enemy_deleted = false;

		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->bosses[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{

				this->bosses[i]->setHp(this->bosses[i]->getHp() - this->player->getDamage());

				if (this->bosses[i]->getHp() <= 0)
				{
					this->points += this->bosses[i]->getPoints();

					delete this->bosses[i];
					this->bosses.erase(this->bosses.begin() + i);

					enemy_deleted = true;
				}
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
			}
		}
	}

	for (size_t k = 0; k < this->enemyBullets.size(); k++)
	{
		if (this->player->getBounds().intersects(this->enemyBullets[k]->getBounds()))
		{
			this->player->setHP(this->player->getHp() - 2);
			delete this->enemyBullets[k];
			this->enemyBullets.erase(this->enemyBullets.begin() + k);
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

	for (Bullet* bullet : this->bullets)
	{
		bullet->update();

		if (bullet->getBounds().top + bullet->getBounds().height <= view.getCenter().y - 540.f * zoom
			|| bullet->getBounds().top >= view.getCenter().y + 540.f * zoom
			|| bullet->getBounds().left + bullet->getBounds().width <= view.getCenter().x - 720.f * zoom
			|| bullet->getBounds().left >= view.getCenter().x + 720.f * zoom)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}

		++counter;
	}

	unsigned counter_1 = 0;

	for (EnemyBullet* enemyBullet : this->enemyBullets)
	{
		enemyBullet->update();

		if (enemyBullet->getBounds().top + enemyBullet->getBounds().height <= view.getCenter().y - 800.f * zoom
			|| enemyBullet->getBounds().top >= view.getCenter().y + 800.f * zoom
			|| enemyBullet->getBounds().left + enemyBullet->getBounds().width <= view.getCenter().x - 1200.f * zoom
			|| enemyBullet->getBounds().left >= view.getCenter().x + 1200.f * zoom)
		{
			delete this->enemyBullets.at(counter_1);
			this->enemyBullets.erase(this->enemyBullets.begin() + counter_1);
		}

		++counter_1;
	}
}

void Game::update()
{
	this->updateWorld();

	this->updateInput();

	this->updateReset();

	this->updateLevel();

	this->updateCollision();

	this->updatePlayer();

	this->updateBullets();

	this->updateVillains();

	this->updateBosses();

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

	this->window->draw(this->playerHpText);
	this->window->draw(this->playerLevelText);
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

	for (Bullet* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (Villain* villain : this->villains)
	{
		villain->render(this->window);
	}

	for (EnemyBullet* enemyBullet : this->enemyBullets)
	{
		enemyBullet->render(this->window);
	}

	for (Boss* boss : this->bosses)
	{
		boss->render(this->window);
	}

	for (Item* item : this->items)
	{
		item->render(this->window);
	}
}

void Game::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	this->renderWorld();

	if (this->player->getHp() > 0)
	{
		this->renderObjects();
	}

	this->renderGui();

	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->gameOverText);
		this->window->draw(this->gameRetryText);
	}

	this->window->display();
}