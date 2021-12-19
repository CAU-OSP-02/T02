#include "Player.h"

//Constructor
Player::Player()
{
	//texture
	this->texture_1.loadFromFile("Images/characters/Main/main_left.png");
	this->texture_2.loadFromFile("Images/characters/Main/main_right.png");
	this->shape.setTexture(texture_1);
	this->shape.setScale(0.5f, 0.5f);

	//abilities
	this->rotateTimeMax = 10.f;
	this->rotateTime = this->rotateTimeMax;
	this->playerHpMax = 20;
	this->playerHp = playerHpMax;

	this->maxSpeed = 5;
	this->playerSpeed = this->maxSpeed;

	this->playerDamage = 2;

	this->attackCoolMax = 6;
	this->attackCool = 0;

	this->setDirection(0.f, -1.f);
}

//Destructor
Player::~Player()
{
}

//Function
void Player::setPosition(float X, float Y)
{
	this->shape.setPosition(X, Y);
}

const int& Player::getHp() const
{
	return this->playerHp;
}
const int& Player::getHpMax() const
{
	return this->playerHpMax;
}

void Player::setHP(const int hp)
{
	this->playerHp = hp;

	if (playerHp > playerHpMax)
	{
		this->playerHp = this->playerHpMax;
	}
}

void Player::loseHP(const int damage)
{
	this->playerHp -= damage;

	if (this->playerHp < 0)
	{
		this->playerHp = 0;
	}
}

void Player::setDirection(float X, float Y)
{
	this->dir.x = X;
	this->dir.y = Y;
}

void Player::setDamage(int x)
{
	this->playerDamage += x;
}

const bool Player::canAttack()
{
	if (this->attackCool >= this->attackCoolMax)
	{
		this -> attackCool = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->attackCool < this->attackCoolMax)
	{
		this->attackCool += 0.5f;
	}
}

void Player::move(float X, float Y)
{
	this->setDirection(X, Y);
	this->shape.move(this->playerSpeed * dir.x, this->playerSpeed * dir.y);

	if (this->dir.x <= 0)
	{
		this->shape.setTexture(texture_1);
	}
	else if (this->dir.x > 0)
	{
		this->shape.setTexture(texture_2);
	}
}

const sf::FloatRect Player::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const sf::Vector2f& Player::getPosition() const
{
	return this->shape.getPosition();
}

void Player::setAttackSpeed(float x)
{
	this->attackCoolMax = x;
}

const int Player::getDamage() const
{
	return this->playerDamage;
}

const float Player::getAttackSpeed() const
{
	return this->attackCoolMax;
}

void Player::setSpeed(float x) 
{
	this->playerSpeed = x;

	if (this->playerSpeed >= 10)
	{
		this->playerSpeed = 10;
	}

	if (this->playerSpeed <= 1)
	{
		this->playerSpeed = 1;
	}
}

const float Player::getSpeed() const 
{
	return playerSpeed;
}

const sf::Vector2f& Player::getDirection() const
{
	return this->dir;
}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}