#include "item.h"

Item::Item(float posX, float posY, int type)
{
	if (type == 1)
	{
		// 1. 안경
		this->texture_1.loadFromFile("Images/glasses.png");

		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);
		this->ratio = 3.f;
	}

	else if (type == 2)
	{
		// 2. 연필
		this->texture_2.loadFromFile("Images/pencil.png");

		this->shape.setTexture(texture_2);
		this->shape.setPosition(posX, posY);
		this->attackSpeed = 3.f;
	}

	else if (type == 3)
	{
		// 3. 커피
		this->texture_3.loadFromFile("Images/coffee.png");

		this->shape.setTexture(texture_3);
		this->shape.setPosition(posX, posY);
		this->hp = 3;
	}

	else if (type == 4)
	{
		// 4. 스쿠터
		this->texture_4.loadFromFile("Images/escooter.png");

		this->shape.setTexture(texture_4);
		this->shape.setPosition(posX, posY);
		this->speed = 3.f;
	}
}

Item::~Item()
{
}

const sf::FloatRect Item::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Item::getType() const
{
	return this->type;
}

const float& Item::getAttackSpeed() const
{
	return this->attackSpeed;
}

const float& Item::getSpeed() const
{
	return this->speed;
}

const float& Item::getRatio() const
{
	return this->ratio;
}

const int& Item::getHp() const
{
	return this->hp;
}

void Item::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
