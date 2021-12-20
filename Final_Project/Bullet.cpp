#include "Bullet.h"

Bullet::Bullet(float posX, float posY, float dirX, float dirY)
{
	this->texture.loadFromFile("Images/items/book_left.png");
	this->shape.setTexture(this->texture);
	this->shape.scale(0.2f, 0.2f);

	this->shape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = 8.f;
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
	this->shape.move(this->movementSpeed * this->direction.x, this->movementSpeed * this->direction.y);
	this->shape.rotate(1.f);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
