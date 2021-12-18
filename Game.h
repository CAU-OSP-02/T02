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

	//Systems
	unsigned points;
	unsigned highPoints;

	int state = 0;

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::RectangleShape playerHpBarBot;

	//init functions
	void initWindow();
	void initTextures();
	void initGui();
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
	void update();

	//render functions
	void renderGui();
	void renderWorld();
	void render();
};