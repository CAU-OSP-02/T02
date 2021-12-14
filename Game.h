#pragma once
#include "Villain.h"
class Game
{
private:

	sf::RenderWindow* window;
	std::map<std::string, sf::Texture*> textures;

	//Villain
	std::vector<Villain*>villains;
	float spawnTimerVillain;
	float spawnTimerVillainMax;
	//world

	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackground;

	//init functions
	void initWindow();
	void initTextures();
	void initWorld();
	void initVillains();

public:
	Game();
	~Game();
	//update functions
	void run();

	void updatePollEvent();
	void updateVillains();
	void updateWorld();
	void update();

	//render functions
	void renderWorld();
	void render();
};

