#include "Enemy.h"

void Enemy::initVariables()
{
	this -> type   = 0;
	this -> speed  = static_cast<float>(this->pointCount/1.5);
	this -> hp     = hpmax;
	this -> hpmax  = static_cast<int>(this->pointCount);
	this -> damage = this->pointCount;
	this -> points = 5 * pointCount;
}

void Enemy::initShapes()
{
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 225 + 1, rand() % 225 + 1, rand() % 255 + 1, 255));
}

Enemy::Enemy(float posX, float posY)
{
	this->initVariables();
	this->initShapes();

	this->shape.setPosition(posX, posY);
}

Enemy::~Enemy()
{

}

//Access

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

void Enemy::update()
{
	this->shape.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
