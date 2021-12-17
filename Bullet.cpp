#include "Bullet.h"

Bullet::Bullet(float posX, float posY, float dirX, float dirY, float)
{
	this->texture.loadFromFile("Images/bullet.png");
	this->shape.setTexture(this->texture);
	this->shape.scale(0.06f, 0.06f);

	this->shape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = 5.f;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
