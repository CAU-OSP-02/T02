#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture_1;
	sf::Texture texture_2;
	sf::Texture texture_3;


	//Private Functions
	void initVariables(int value);
	void initTexture();
	void initSprite(int value);


	float movementspeed;

	float attackCooldown;
	float attackCooldownMax;

	int hp;
	int hpMax;

public:
	Player(int player);
	virtual ~Player();

	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;

	//Modifiers

	void setPosition(const float x, const float y);
	void setRotation(const float degree);
	void setHp(const int hp);
	void looseHp(const int value);
	//Functions

	void move(const float dirX, const float dirY);

	const bool canAttack();
	void updateAttack();

	void update();
	void render(sf::RenderTarget& target);
};

#endif PLAYER_H