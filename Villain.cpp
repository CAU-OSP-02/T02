#include "Villain.h"

Villain::Villain(float posX, float posY, int type)
{
	if (type == 1)
	{
		// 1. 핑거 프린세스
		this->texture_1.loadFromFile("Images/characters/FingerPrincess/FingerPrincess_left.png");
		this->texture_2.loadFromFile("Images/characters/FingerPrincess/FingerPrincess_right.png");
		this->shape.scale(0.5f, 0.5f);

		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);

		this->hpMax = 5;
		this->speed = 2;
		this->damage = 2;
		this->point = 10;
		this->attackCoolMax = 6.f;
	}

	else if (type == 2)
	{
		// 2. 헬스 트레이너
		this->texture_1.loadFromFile("Images/health_trainer.jpg");

		this->shape.setTexture(texture_2);
		this->shape.setPosition(posX, posY);

		this->hpMax = 7;
		this->speed = 10;
		this->damage = 2;
		this->point = 10;
		this->attackCoolMax = 6.f;
	}

	else if (type == 3)
	{
		// 3. 팀플 버스
		this->texture_1.loadFromFile("Images/bus_member.jpg");

		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);

		this->hpMax = 5;
		this->speed = 15;
		this->speedDown = 3;
		this->point = 10;
	}

	else if (type == 4)
	{
		// 4. 꼰대 선배
		this->texture_1.loadFromFile("Images/bus_member.jpg");

		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);

		this->hpMax = 5;
		this->speed = 10;
		this->damage = 2;
		this->point = 15;
		this->attackCoolMax = 6.f;
	}

	else if (type == 5)
	{
		// 5. 교수님
		this->texture_1.loadFromFile("Images/bus_member.jpg");

		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);

		this->hpMax = 13;
		this->speed = 10;
		this->damage = 2;
		this->point = 20;
		this->attackCoolMax = 5.f;
	}

	this->dir.x = 0.f;
	this->dir.y = -1.f;
	this->attackCool = this->attackCoolMax;
	this->hp = this->hpMax;
}

Villain::~Villain()
{
}


const sf::FloatRect Villain::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const sf::Vector2f Villain::getPosition() const
{
	return this->shape.getPosition();
}

const int& Villain::getHp() const
{
	return this->hp;
}

const int& Villain::getHpMax() const
{
	return this->hpMax;
}

const int& Villain::getPoints() const
{
	return point;
}

const sf::Vector2f& Villain::getDir() const
{
	return this->dir;
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

void Villain::setDir(float X, float Y)
{
	this->dir.x = X;
	this->dir.y = Y;
}

const int& Villain::getDamage() const
{
	return this->damage;
}

const float& Villain::getAttackSpeed() const
{
	return this->attackCool;
}

const float& Villain::getSpeedDown() const
{
	return this->speedDown;
}

void Villain::move()
{	
	if (this->dir.x <= 0)
	{
		this->shape.setTexture(this->texture_1);
	}
	else if (this->dir.x > 0)
	{
		this->shape.setTexture(this->texture_2);
	}
	this->shape.move(dir.x * this->speed, dir.y * this->speed);
}

void Villain::update()
{
	this->move();
}

void Villain::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
