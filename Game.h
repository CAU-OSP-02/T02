#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Villain.h"
#include "Item.h"

class Game
{
private:

	//Window
	sf::RenderWindow* window;

	//Player
	Player* player;

	//Bullets
	std::vector<Bullet*>bullets;

	//Villain
	std::vector<Villain*>villains;
	float spawnTimerVillain;
	float spawnTimerVillainMax;

	//Item
	std::vector<Item*>items;
	float spawnTimerItem;
	float spawnTimerItemMax;

	float itemEffectTimer;
	float itemEffectTimerMax;

	//World
	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackground;

	//GUI
	sf::Font font;
	sf::Text titleText;
	sf::Text pointText;
	sf::Text highPointText;
	sf::Text gameOverText;
	sf::Text gameRetryText;
	sf::Text playerHpText;
	sf::Text playerAttackText;
	sf::Text playerSpeedText;

	sf::Text gameStoryTitleText;
	sf::Text gameStoryText;
	
	sf::Text gameComponentTitleText;
	sf::Text gameVillainText;
	sf::Text gameItemText;
	sf::Text gameVillainComponentText;
	sf::Text gameItemComponentText;

	sf::Text gameManipulationTitleText;
	sf::Text gameManipulationText;
	sf::Text gameKeyText;

	//Systems
	unsigned points;
	unsigned highPoints;

	int level = 0;
	int state = 0;
	int itemBtn = 0;

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::RectangleShape playerHpBarBot;
	sf::RectangleShape playerAbility;
	sf::RectangleShape playerItem;

	//init functions
	void initWindow();
	void initGui();
	void initSystem();
	void initWorld();
	void initPlayer();
	void initBullet();
	void initVillains();
	void initItems();
	void initGame();

public:
	Game();
	~Game();

	void updateDelete();
	//update functions
	void run();

	void updatePollEvent();
	void updateWorld();
	void updateInput();
	void updateGui();
	void updateCombat();
	void updatePlayer();
	void updateBullets();
	void updateVillains();
	void updateItems();
	void updateReset();
	void update();

	//render functions
	void renderGui();
	void renderWorld();
	void renderObjects();
	void render();
};