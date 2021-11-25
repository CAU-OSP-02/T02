#include "Item.h"

void Item::initVariables()
{
	this->type   = 0;
	this->speed = static_cast<float>(this->pointCount / 1.5);
	this->damage = (-1) * pointCount;
}

void Item::initShapes()
{
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(255, 255, 255));
}

Item::Item(float posX, float posY)
{
	this->initVariables();
	this->initShapes();

	this->shape.setPosition(posX, posY);
}

Item::~Item()
{

}

//Access

const sf::FloatRect Item::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Item::getPoints() const
{
	return this->points;
}

const int& Item::getDamage() const
{
	return this->damage;
}

void Item::update()
{
	this->shape.move(0.f, this->speed);
}

void Item::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
