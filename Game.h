#pragma once
#include "Villain.h"
#include "Item.h"
class Game
{
private:

	sf::RenderWindow* window;
	std::map<std::string, sf::Texture*> textures;

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
	void initVillains();
	void initItems();

public:
	Game();
	~Game();
	//update functions
	void run();

	void updatePollEvent();
	void updateWorld();
	void updateVillains();
	void updateItems();
	void update();

	//render functions
	void renderWorld();
	void render();
};

