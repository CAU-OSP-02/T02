#pragma once
#include "Headers.h"
class EnemyBullet
{
private:
	sf::Texture texture;
	sf::Sprite shape;

	sf::Vector2f direction;
	float movementSpeed;

public:
	EnemyBullet(float posX, float posY, float dirX, float dirY);
	~EnemyBullet();

	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

