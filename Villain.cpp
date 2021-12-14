#include "Villain.h"

Villain::Villain(float posX, float posY, int type)
{
	if (type == 1)
	{
		// 1. �ΰ� ��������
		this->texture_1.loadFromFile("Images/bullet.png");
		this->shape.scale(0.2f, 0.2f);

		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);

		this->hpMax = 5;
		this->speed = 10;
	}

	else if (type == 2)
	{
		// 2. �ｺ Ʈ���̳�
		this->texture_2.loadFromFile("Images/health_trainer.jpg");

		this->shape.setTexture(texture_2);
		this->shape.setPosition(posX, posY);

		this->hpMax = 7;
		this->speed = 10;
	}

	else if (type == 3)
	{
		// 3. ���� ����
		this->texture_3.loadFromFile("Images/bus_member.jpg");

		this->shape.setTexture(texture_3);
		this->shape.setPosition(posX, posY);

		this->hpMax = 5;
		this->speed = 15;
	}

	this->hp = this->hpMax;
}

Villain::~Villain()
{
}


const sf::FloatRect Villain::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Villain::getHp() const
{
	return this->hp;
}

const int& Villain::getHpMax() const
{
	return this->hpMax;
}

void Villain::setHp(const int hp)
{
	this->hp = hp;
}

void Villain::loseHp(const int damage)
{
	this->hp -= damage;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

const int& Villain::getDamage() const
{
	return this->damage;
}

const float& Villain::getAttackSpeed() const
{
	return this->attackTimeMax;
}

void Villain::move()
{
	this->shape.move(0, 10);
}

void Villain::update()
{
	this->move();
}

void Villain::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}