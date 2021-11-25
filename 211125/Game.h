#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS

#include <map>
#include <string>
#include <sstream>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Item.h"

#include <SFML/Audio.hpp>

class Game
{
private:
	sf::RenderWindow* window;

	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	Player* player;

	float spawnTimerEnemy;
	float spawnTimerEnemyMax;
	float spawnTimerItem;
	float spawnTimerItemMax;
	std::vector<Enemy*>enemies;
	std::vector<Item*>items;


	float hpValue = 5;

	//GUI
	sf::Font font;
	sf::Text titleText;
	sf::Text pointText;
	sf::Text highPointText;
	sf::Text gameOverText;

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::RectangleShape playerHpBarBot;


	//Systems
	unsigned points;
	unsigned highPoints;

	//World
	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackground;

	//private functions
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorld();
	void initSystem();
	void initEnemies();
	void InitItems();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//functions
	void run();


	void updatePollEvents();
	void updateInput();
	void updateBullets();
	void updateEnemies();
	void updateItems();
	void updateCombat();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void update();

	void renderGUI();
	void renderWorld();
	void render();
};

#endif // !1

