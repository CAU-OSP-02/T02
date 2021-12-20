#include "Villain.h"

Villain::Villain(float posX, float posY, int type)
{
	this->type = type;

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
	}

	else if (type == 2)
	{
		// 2. 헬스 트레이너
		this->texture_1.loadFromFile("Images/characters/Trainer/Trainer_left.png");
		this->texture_2.loadFromFile("Images/characters/Trainer/Trainer_right.png");

		this->shape.setTexture(texture_2);
		this->shape.setPosition(posX, posY);

		this->hpMax = 7;
		this->speed = 3;
		this->damage = 2;
		this->point = 10;
	}

	else if (type == 3)
	{
		// 3. 팀플 버스
		this->texture_1.loadFromFile("Images/characters/BusMember/BusMember_left.png");
		this->texture_2.loadFromFile("Images/characters/BusMember/BusMember_right.png");
		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);
		this->shape.scale(0.5f, 0.5f);

		this->hpMax = 3;
		this->speed = 6;
		this->speedDown = 2;
		this->point = 10;
	}

	this->dir.x = 0.f;
	this->dir.y = -1.f;
	this->attackCool = this->attackCoolMax;
	this->hp = this->hpMax;

	this->hpBar.setFillColor(sf::Color(255, 20, 20, 100));
	this->hpBar.setSize(sf::Vector2f(
		this->shape.getGlobalBounds().width * 1.5f, 
		this->shape.getGlobalBounds().height / 10));

	this->hpBarBack = this->hpBar;
	this->hpBarBack.setFillColor(sf::Color(25, 25, 25, 100));
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

const int& Villain::getType() const
{
	return this->type;
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

	float hpPercent = static_cast<float>(this->hp) / this->hpMax;

	this->hpBar.setSize(sf::Vector2f(
		this->shape.getGlobalBounds().width * 1.5f * hpPercent,
		this->shape.getGlobalBounds().height / 10));
	
	this->hpBar.setPosition(
		this->shape.getPosition().x - this->shape.getGlobalBounds().width * 0.25,
		this->shape.getPosition().y - 20);

	this->hpBarBack.setPosition(
		this->shape.getPosition().x - this->shape.getGlobalBounds().width * 0.25,
		this->shape.getPosition().y - 20);
}

void Villain::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->hpBarBack);
	target->draw(this->hpBar);
}
