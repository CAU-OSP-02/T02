#include "Enemy_Bullet.h"

Enemy_Bullet::Enemy_Bullet(float posX, float posY, float dirX, float dirY, float)
{
	this->texture.loadFromFile("Images/enemybullet.png");
	this->shape.setTexture(this->texture);
	this->shape.scale(0.06f, 0.06f);

	this->shape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = 5.f;
}

Enemy_Bullet::~Enemy_Bullet()
{
}

const sf::FloatRect Enemy_Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Enemy_Bullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void Enemy_Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}