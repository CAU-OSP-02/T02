#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(float posX, float posY, float dirX, float dirY)
{
	this->texture.loadFromFile("Images/items/latte.png");
	this->shape.setTexture(this->texture);
	this->shape.scale(0.1f, 0.1f);

	this->shape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = 5.f;
}

EnemyBullet::~EnemyBullet()
{
}

const sf::FloatRect EnemyBullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void EnemyBullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void EnemyBullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
