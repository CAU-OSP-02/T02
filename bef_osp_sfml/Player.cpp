#include "Player.hpp"

//Constructor
Player::Player()
{
	name = "PLAYER";

	playerHP_MAX = 15;
	playerHP = playerHP_MAX;
	playerSCORE = 0;

	playerBullet = 30;
}

//Destructor
Player::~Player()
{
	cout << "Player Die!!" << endl;
}



//Function

const int& Player::getHp() const
{
	return this->playerHP;
}
const int& Player::getHpMax() const
{
	return this->playerHP_MAX;
}


void Player::setHP(const int HP)
{
	this->playerHP = HP;
}
void Player::loseHP(const int damage)
{
	this->playerHP -= damage;

	if (this->playerHP < 0)
	{
		this->playerHP = 0;
	}
}


void Player::update()
{
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

}
