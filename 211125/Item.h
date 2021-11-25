#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

class Item
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
	Item(float posX, float posY);
	virtual ~Item();

	//Acess

	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;


	void update();
	void render(sf::RenderTarget* target);
};
#endif