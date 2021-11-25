#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	unsigned pointCount = rand() % 10 + 3;

	sf::CircleShape shape;
	int type;
	float speed;
	int hp;
	int hpmax;
	int damage;
	int points;

	void initShapes();
	void initVariables();

public:
	Enemy(float posX, float posY);
	virtual ~Enemy();

	//Acess

	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;


	void update();
	void render(sf::RenderTarget* target);
};
#endif