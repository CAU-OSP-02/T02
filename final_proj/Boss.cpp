#include "Boss.h"
#include "Boss.h"

Boss::Boss(float posX, float posY, int type)
{
	this->type = type;

	if (type == 1)
	{
		// 1. ²Á´ë ¼±¹è
		this->texture_1.loadFromFile("Images/characters/Senior/Senior_left.png");
		this->texture_2.loadFromFile("Images/characters/Senior/Senior_right.png");
		this->shape.setTexture(texture_1);
		this->shape.setScale(0.3f, 0.3f);
		this->shape.setPosition(posX, posY);

		this->hpMax = 5;
		this->speed = rand() % 3 + 2;
		this->damage = 2;
		this->point = 15;
		this->attackCoolMax = 100.f;
	}

	else if (type == 2)
	{
		// 2. ±³¼ö´Ô
		this->texture_1.loadFromFile("Images/characters/Professor/Professor_left.png");
		this->texture_2.loadFromFile("Images/characters/Professor/Professor_right.png");

		this->shape.setTexture(texture_1);
		this->shape.setPosition(posX, posY);

		this->hpMax = 50;
		this->speed = 3;
		this->damage = 2;
		this->point = 30;
		this->attackCoolMax = 50.f;
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

Boss::~Boss()
{
}


const sf::FloatRect Boss::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const sf::Vector2f Boss::getPosition() const
{
	return this->shape.getPosition();
}

const int& Boss::getHp() const
{
	return this->hp;
}

const int& Boss::getHpMax() const
{
	return this->hpMax;
}

const int& Boss::getPoints() const
{
	return point;
}

const sf::Vector2f& Boss::getDir() const
{
	return this->dir;
}

const int& Boss::getType() const
{
	return this->type;
}

void Boss::setHp(const int hp)
{
	this->hp = hp;
}

void Boss::loseHp(const int damage)
{
	this->hp -= damage;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Boss::setDir(float X, float Y)
{
	this->dir.x = X;
	this->dir.y = Y;
}

void Boss::setBound(bool a)
{
	reachTrue = a;
}

const int& Boss::getDamage() const
{
	return this->damage;
}

const float& Boss::getAttackSpeed() const
{
	return this->attackCool;
}

const bool Boss::canAttack()
{
	if (this->attackCool >= this->attackCoolMax)
	{
		this->attackCool = 0.f;
		return true;
	}
	return false;
}

void Boss::updateAttack()
{
	if (this->attackCool < this->attackCoolMax)
	{
		this->attackCool += 0.5f;
	}
}

void Boss::move()
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

void Boss::update()
{
	updateAttack();

	if (reachTrue == true)
	{
		this->move();
	}

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

void Boss::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->hpBarBack);
	target->draw(this->hpBar);
}