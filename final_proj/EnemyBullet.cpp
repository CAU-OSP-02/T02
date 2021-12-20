#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(float posX, float posY, float dirX, float dirY, int type)
{
	this->type = type;
	if (this->type == 1)
		this->texture.loadFromFile("Images/items/latte.png");
	if (this->type == 2)
		this->texture.loadFromFile("Images/items/pdf.png");

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

const int& EnemyBullet::getType() const
{
	return this->type;
}

void EnemyBullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void EnemyBullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
