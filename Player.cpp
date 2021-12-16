#include "Player.h"

//Constructor
Player::Player()
{
	//texture
	this->texture.loadFromFile("Images/spaceship.png");
	this->shape.setTexture(this->texture);
	this->shape.scale(0.2f, 0.2f);

	//abilities
	this->powerBool = false;
	this->playerHpMax = 15;
	this->playerHp = playerHpMax;

	this->maxSpeed = 5;
	this->playerSpeed = this->maxSpeed;

	this->playerDamage = 2;
	this->playerScore = 0;

	this->playerBullet = 30;
	this->attackCoolMax = 6;
	this->attackCool = 0;
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
}

void Player::loseHP(const int damage)
{
	this->playerHp -= damage;

	if (this->playerHp < 0)
	{
		this->playerHp = 0;
	}
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

const int& Player::getScore() const
{
	return playerScore;
}

void Player::move(const float X, const float Y)
{
	this->shape.move(this->playerSpeed * X, this->playerSpeed * Y);
}

const sf::FloatRect Player::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const sf::Vector2f& Player::getPosition() const
{
	return this->shape.getPosition();
}

void Player::update()
{
	this->updateAttack();
	//임의로 각주 처리해둠
	/*
	if (powerBool) // if the player goes forward, POWER UP!
	{
		dX += cos(angle * DEGTORADI) * 0.2;
		dY += sin(angle * DEGTORADI) * 0.2;
	}
	else // else power down...
	{
		dX *= 0.99;
		dY *= 0.99;
	}


	playerSpeed = sqrt(dX * dX + dY * dY);
	maxSpeed = 15.0f;


	if (playerSpeed > maxSpeed)
	{
		dX *= maxSpeed / playerSpeed;
		dY *= maxSpeed / playerSpeed;
	}


	xPos += dX;
	yPos += dY;


	// :NEED TO BE ADDED:
	// The appropriate screen movement when the player moves.
	*/
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

