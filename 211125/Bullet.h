#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
private:

	sf::Sprite shape;

	sf::Vector2f direction;
	float movementSpeed;

public:
	Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movement_speed);
	virtual ~Bullet();

	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

#endif BULLET_H