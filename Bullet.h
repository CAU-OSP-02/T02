#pragma once
#include "Headers.h"
class Bullet
{
private:
	sf::Texture texture;
	sf::Sprite shape;

	sf::Vector2f direction;
	float movementSpeed;

public:
	Bullet(float posX, float posY, float dirX, float dirY, float);
	~Bullet();

	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

