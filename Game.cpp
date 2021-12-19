#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(width, height)
		, "OSP_T02_Team2"
		, sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}


void Game::initGui()
{
	this->font.loadFromFile("Fonts/FIGHTT3_.ttf");

	this->titleText.setFont(this->font);
	this->titleText.setCharacterSize(50);
	this->titleText.setFillColor(sf::Color::Black);
	this->titleText.setPosition(20.f, 0.f);
	this->titleText.setString("[23 : 58]");

	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(70);
	this->pointText.setFillColor(sf::Color::Black);
	this->pointText.setPosition(600.f, 30.f);

	this->highPointText.setFont(this->font);
	this->highPointText.setCharacterSize(30);
	this->highPointText.setFillColor(sf::Color::Black);
	this->highPointText.setPosition(630.f, 0.f);

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(150);
	this->gameOverText.setFillColor(sf::Color::Black);
	this->gameOverText.setPosition(750.f, 350.f);
	this->gameOverText.setString("GAME OVER");

	this->gameRetryText.setFont(this->font);
	this->gameRetryText.setCharacterSize(50);
	this->gameRetryText.setFillColor(sf::Color::Red);
	this->gameRetryText.setPosition(570.f, 530.f);
	this->gameRetryText.setString("Try Again? (Y / N)");

	this->gameOverText.setPosition(
		this->window->getSize().x / 2 - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2 - this->gameOverText.getGlobalBounds().height / 2.f - 100);
;
	this->playerHpText.setFont(this->font);
	this->playerHpText.setCharacterSize(40);
	this->playerHpText.setFillColor(sf::Color::White);
	this->playerHpText.setPosition(720 - playerHpText.getGlobalBounds().width / 2 - 40.f, 900.f);

	this->playerAttackText.setFont(this->font);
	this->playerAttackText.setCharacterSize(30);
	this->playerAttackText.setFillColor(sf::Color::Blue);
	this->playerAttackText.setPosition(720 - playerAttackText.getGlobalBounds().width / 2 - 370.f, 890.f);

	this->playerSpeedText.setFont(this->font);
	this->playerSpeedText.setCharacterSize(30);
	this->playerSpeedText.setFillColor(sf::Color::Magenta);
	this->playerSpeedText.setPosition(720 - playerAttackText.getGlobalBounds().width / 2 - 370.f, 920.f);

	this->playerHpBar.setSize(sf::Vector2f(300.f, 50.f));
	this->playerHpBar.setFillColor(sf::Color(200, 20, 20, 100));
	this->playerHpBar.setPosition(sf::Vector2f(570.f, 900.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 100));

	this->playerHpBarBot.setSize(sf::Vector2f(320.f, 70.f));
	this->playerHpBarBot.setFillColor(sf::Color(184, 184, 178, 100));
	this->playerHpBarBot.setPosition(sf::Vector2f(560.f, 890.f));

	this->playerAbility.setSize(sf::Vector2f(200.f, 70.f));
	this->playerAbility.setFillColor(sf::Color(184, 184, 178, 100));
	this->playerAbility.setPosition(sf::Vector2f(300.f, 890.f));

	this->playerItem.setSize(sf::Vector2f(200.f, 200.f));
	this->playerItem.setFillColor(sf::Color(184, 184, 178, 100));
	this->playerItem.setPosition(sf::Vector2f(30.f, 800.f));

	this->gameStoryTitleText.setFont(this->font);
	this->gameStoryTitleText.setStyle(sf::Text::Bold);
	this->gameStoryTitleText.setCharacterSize(100);
	this->gameStoryTitleText.setFillColor(sf::Color::Black);
	this->gameStoryTitleText.setPosition(500.f, 200.f);
	this->gameStoryTitleText.setString("Game Story");
	
	this->gameStoryText.setFont(this->font);
	this->gameStoryText.setCharacterSize(40);
	this->gameStoryText.setFillColor(sf::Color::Black);
	this->gameStoryText.setPosition(50.f, 400.f);
	this->gameStoryText.setString("One day, villains who interfere with his college life come to ordinary college student Kim Ye-gong!\nIf you encounter villains such as Finger Princess, fitness trainer,\nggondae seniors, and freerider(team bus members), you will die.\nIt's over when you defeat the villains and get rid of the final boss, the professor\nWill Kim Ye-gong be able to finish the semester safely avoiding villains? ");

	this->gameComponentTitleText.setFont(this->font);
	this->gameComponentTitleText.setStyle(sf::Text::Bold);
	this->gameComponentTitleText.setCharacterSize(100);
	this->gameComponentTitleText.setFillColor(sf::Color::Black);
	this->gameComponentTitleText.setPosition(500.f, 150.f);
	this->gameComponentTitleText.setString("Component");

	this->gameVillainText.setFont(this->font);
	this->gameVillainText.setStyle(sf::Text::Bold);
	this->gameVillainText.setCharacterSize(40);
	this->gameVillainText.setFillColor(sf::Color::Black);
	this->gameVillainText.setPosition(100.f, 300.f);
	this->gameVillainText.setString("Villian --------------------- Ability");

	this->gameVillainComponentText.setFont(this->font);
	this->gameVillainComponentText.setCharacterSize(30);
	this->gameVillainComponentText.setFillColor(sf::Color::Black);
	this->gameVillainComponentText.setPosition(50.f, 400.f);
	this->gameVillainComponentText.setString("FingerPrincess                >>>>>                  Bump into a player\n\n     Trainer                         >>>>>                  Bump into a player\n\n   BusMember                   >>>>>                  Bump into a player\n\n     Senior                         >>>>>                        Bullet attack\n\nProfessor(Boss)         >>>>>                        Bullet attack");

	this->gameItemText.setFont(this->font);
	this->gameItemText.setStyle(sf::Text::Bold);
	this->gameItemText.setCharacterSize(40);
	this->gameItemText.setFillColor(sf::Color::Black);
	this->gameItemText.setPosition(800.f, 300.f);
	this->gameItemText.setString("Item --------------------- Function");

	this->gameItemComponentText.setFont(this->font);
	this->gameItemComponentText.setCharacterSize(30);
	this->gameItemComponentText.setFillColor(sf::Color::Black);
	this->gameItemComponentText.setPosition(750.f, 400.f);
	this->gameItemComponentText.setString("Glasses                   >>>>>            Increase the map magnification\n\nPencil                     >>>>>          Increase attack power\n\nCoffee                    >>>>>           Speed up of attack speed\n\nScooter                >>>>>                   Speed up");

	this->gameManipulationTitleText.setFont(this->font);
	this->gameManipulationTitleText.setStyle(sf::Text::Bold);
	this->gameManipulationTitleText.setCharacterSize(100);
	this->gameManipulationTitleText.setFillColor(sf::Color::Black);
	this->gameManipulationTitleText.setPosition(500.f, 150.f);
	this->gameManipulationTitleText.setString("Manipulation");

	this->gameManipulationText.setFont(this->font);
	this->gameManipulationText.setStyle(sf::Text::Bold);
	this->gameManipulationText.setCharacterSize(40);
	this->gameManipulationText.setFillColor(sf::Color::Black);
	this->gameManipulationText.setPosition(500.f, 300.f);
	this->gameManipulationText.setString("Key --------------------- Function");

	this->gameKeyText.setFont(this->font);
	this->gameKeyText.setCharacterSize(30);
	this->gameKeyText.setFillColor(sf::Color::Black);
	this->gameKeyText.setPosition(515.f, 400.f);
	this->gameKeyText.setString("W                      >>>>>                       Forward\n\nA                      >>>>>                            Left\n\nS                      >>>>>                           Back\n\nD                      >>>>>                           Right\n\nSpacebar         >>>>>                       Attack");
	
	
}

void Game::initSystem()
{
	FILE *file = NULL;
		
	if (fopen_s(&file, "score.dat", "rt") == 0)
	{
		highPoints = 0;
	}
	else
	{
		fscanf_s(file, "%d", &highPoints);
		fclose(file);
	}

	this->points = 0;
}

void Game::initWorld()
{
	this->worldBackgroundTexture.loadFromFile("Images/Map/Map.png");
	this->worldBackground.setTexture(this->worldBackgroundTexture);
	this->worldBackground.setScale(4.f, 4.f);
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
	this->spawnTimerItem = 0.f;

	this->itemEffectTimerMax = 100.f;
	this->itemEffectTimer = 0.f;
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
		{
			this->update();
		}

		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				initGame();
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				this->window->close();
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
			rand() % 1440,
			rand() % 1080,
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

			}
			else if (this->items.at(counter)->getType() == 2)
			{
				this->player->setDamage(3.f);
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

	if (this->spawnTimerItem > this->itemEffectTimer)
	{
		this->player->setAttackSpeed(6.f);
		this->player->setSpeed(5.f);
		this->itemBtn = 0;
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

	this->updateReset();
	
	this->updatePlayer();

	this->updateBullets();

	this->updateVillains();

	this->updateItems();

	this->updateCombat();
}

void Game::renderGui()
{
	//this->window->draw(this->titleText);

	//this->window->draw(this->pointText);
	//this->window->draw(this->highPointText);

	//this->window->draw(this->playerHpBarBot);
	//this->window->draw(this->playerHpBarBack);
	//this->window->draw(this->playerHpBar);
	//this->window->draw(this->playerAbility);
	//this->window->draw(this->playerItem);

	//this->window->draw(this->playerHpText);
	//this->window->draw(this->playerAttackText);
	//this->window->draw(this->playerSpeedText);

	//this->window->draw(this->gameStoryTitleText);
	//this->window->draw(this->gameStoryText);

	//this->window->draw(this->gameComponentTitleText);
	//this->window->draw(this->gameVillainText);
	//this->window->draw(this->gameVillainComponentText);
	//this->window->draw(this->gameItemText);
	//this->window->draw(this->gameItemComponentText);

	//this->window->draw(this->gameManipulationTitleText);
	//this->window->draw(this->gameManipulationText);
	//this->window->draw(this->gameKeyText);

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

	this->renderGui();

	if (this->player->getHp() > 0)
	{
		this->renderObjects();
	}
	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->gameOverText);
		this->window->draw(this->gameRetryText);
	}

	this->window->display();
}