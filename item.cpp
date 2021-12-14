#include "item.h"

Item::Item(float posX, float posY, int type)
{
	if (type == 1)
	{
		// 1. 안경
		this->texture_1.loadFromFile("Images/glasses.png");

		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);

	}

	else if (type == 2)
	{
		// 2. 연필
		this->texture_2.loadFromFile("Images/pencil.png");

		this->shape.setTexture(texture_2);
		this->shape.setPosition(posX, posY);
	}

	else if (type == 3)
	{
		// 3. 커피
		this->texture_3.loadFromFile("Images/coffee.png");

		this->shape.setTexture(texture_3);
		this->shape.setPosition(posX, posY);

		this->hpMax += 3;
	}

	else if (type == 4)
	{
		this->texture_4.loadFromFile("Images/escooter.png");

		this->shape.setTexture(texture_4);
		this->shape.setPosition(posX, posY);

		this->speed += 3;
	}
}

Item::~Item()
{
}

const sf::FloatRect Item::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Item::getHp() const
{
	return this->hp;
}

const int& Item::getHpMax() const
{
	return this->hpMax;
}

void Item::setHp(const int hp)
{
	this->hp = hp;
}

void Item::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
