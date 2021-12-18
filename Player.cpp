#include "Player.h"

//Constructor
Player::Player()
{
	//texture
	this->texture_1.loadFromFile("Images/main_character-1.png");
	this->texture_2.loadFromFile("Images/main_character-2.png");
	this->shape.setTexture(texture_1);
	this->shape.setScale(0.5f, 0.5f);

	//abilities
	this->powerBool = false;
	this->playerHpMax = 15;
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
		this->shape.setScale(0.5f, 0.5f);
	}
	else if (this->dir.x > 0)
	{
		this->shape.setTexture(texture_2);
		this->shape.setScale(0.5f, 0.5f);
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

const float Player::getAttackSpeed() const
{
	return this->attackCoolMax;
}

void Player::setSpeed(float x) 
{
	this->playerSpeed = x;
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


