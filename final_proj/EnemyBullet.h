#pragma once
#include "Headers.h"
class EnemyBullet
{
private:
	sf::Texture texture;
	sf::Sprite shape;
	int type;

	sf::Vector2f direction;
	float movementSpeed;

public:
	EnemyBullet(float posX, float posY, float dirX, float dirY, int type);
	~EnemyBullet();

	const sf::FloatRect getBounds() const;
	const int& getType() const;

	void update();
	void render(sf::RenderTarget* target);
};

