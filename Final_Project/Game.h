#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Villain.h"
#include "EnemyBullet.h"
#include "Item.h"
#include "Boss.h"

class Game
{
private:

	//Window
	sf::RenderWindow* window;

	sf::View view;
	sf::View ui;

	sf::Music music;
	sf::SoundBuffer finger;
	sf::SoundBuffer health;
	sf::SoundBuffer bus;
	sf::SoundBuffer latte;
	sf::SoundBuffer professor;

	sf::SoundBuffer coffee;
	sf::SoundBuffer glasses;
	sf::SoundBuffer pencil;
	sf::SoundBuffer scooter;

	sf::Sound sound_1;
	sf::Sound sound_2;
	sf::Sound sound_3;
	sf::Sound sound_4;
	sf::Sound sound_5;

	sf::Sound sound_6;
	sf::Sound sound_7;
	sf::Sound sound_8;
	sf::Sound sound_9;

	//Player
	Player* player;

	//Bullets
	std::vector<Bullet*>bullets;

	//EnemyBullets
	std::vector<EnemyBullet*>enemyBullets;

	//Bosses
	std::vector<Boss*>bosses;

	//Villain
	std::vector<Villain*>villains;
	float spawnTimerVillain;
	float spawnTimerVillainMax;

	float villainTimer;
	float villainTimerMax;

	float spawnTimerBoss;
	float spawnTimerBossMax;

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
	sf::Text playerLevelText;
	sf::Text playerAttackText;
	sf::Text playerSpeedText;

	//Systems
	FILE* file = NULL;
	unsigned points;
	unsigned highPoints;

	float zoom = 1.f;
	bool profTrue;
	bool gameOver;
	int level = 1;
	int state = 0;
	int state_1 = 0;
	int itemBtn = 0;
	int villainBtn = 0;

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::RectangleShape playerHpBarBot;
	sf::RectangleShape playerAbility;

	//init functions
	void initWindow();
	void initGui();
	void initSystem();
	void initWorld();
	void initPlayer();
	void initBullet();
	void initVillains();
	void initBosses();
	void initItems();
	void initGame();

public:
	Game();
	~Game();

	void updateDelete();
	//update functions
	void run();
	void saveHigh();

	void updatePollEvent();
	void updateWorld();
	void updateInput();
	void updateLevel();
	void updateGui();
	void updateCombat();
	void updateCollision();
	void updatePlayer();
	void updateBullets();
	void updateVillains();
	void updateBosses();
	void updateItems();
	void updateReset();
	void update();

	//render functions
	void renderGui();
	void renderWorld();
	void renderObjects();
	void render();
};