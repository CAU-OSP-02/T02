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
	std::vector<Bullet*> bullets;

	//Villain
	std::vector<Villain*>villains;
	float spawnTimerVillain;
	float spawnTimerVillainMax;

	//Item
	std::vector<Item*>items;
	float spawnTimerItem;
	float spawnTimerItemMax;

	//World
	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackground;

	//init functions
	void initWindow();
	void initTextures();
	void initWorld();
	void initPlayer();
	void initBullet();
	void initVillains();
	void initItems();

public:
	Game();
	~Game();
	//update functions
	void run();

	void updatePollEvent();
	void updateWorld();
	void updateInput();

	void updatePlayer();
	void updateBullets();
	void updateVillains();
	void updateItems();
	void update();

	//render functions
	void renderWorld();
	void render();
};