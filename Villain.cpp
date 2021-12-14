#include "Villain.h"

Villain::Villain(float posX, float posY, int type)
{
	if (type == 1)
	{
		this->texture_1.loadFromFile("Images/bullet.png");
		// 1. 핑거 프린세스
		this->shape.setTexture(texture_1);

		this->shape.setPosition(posX, posY);
		this->hpMax = 5;
		this->speed = 10;
	}

	else if (type == 2)
	{
		// 2. 헬스 트레이너
	}

	else if (type == 3)
	{
		// 3. 팀플 버스
	}

	this->hp = hpMax;
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

void Villain::attack()
{

}

void Villain::move()
{
	this->shape.move(0, 10);
}

void Villain::update()
{
	this->move();
	this->attack();
}

void Villain::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
