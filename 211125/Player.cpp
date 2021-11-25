#include "player.h"

void Player::initVariables(int value)
{
	this->movementspeed = 4.f;
	this->attackCooldownMax = 14.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100; 
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	this->texture_1.loadFromFile("Images/spaceship.png");
	this->texture_2.loadFromFile("images/background.jpg");
	this->texture_3.loadFromFile("images/bullet.png");
}

void Player::initSprite(int value) 
{
	if (value == 1)
		this->sprite.setTexture(this->texture_1);
	if (value == 2)
		this->sprite.setTexture(this->texture_2);
	if (value == 3)
		this->sprite.setTexture(this->texture_3);


	this->sprite.scale(0.2f, 0.2f);

	this->sprite.setPosition(600, 550);
}

Player::Player(int player)
{
	this->initVariables(player);
	this->initTexture();
	this->initSprite(player);
}

Player::~Player()
{
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::looseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
	if (this->hp > this->hpMax)
		this->hp = this->hpMax;
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementspeed * dirX, this->movementspeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >=  this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

//fucntions
void Player::update() 
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}