#pragma once
#include "Headers.h"

class Enemy_Bullet
{
private:
	sf::Texture texture;
	sf::Sprite shape;

	sf::Vector2f direction;
	float movementSpeed;

public:
	Enemy_Bullet(float posX, float posY, float dirX, float dirY, float);
	~Enemy_Bullet();

	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

