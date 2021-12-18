#pragma once
#include "Headers.h"

class Player //Inheritance
{
private:

	sf::Sprite shape;
	sf::Texture texture_1;
	sf::Texture texture_2;

	bool powerBool;			// If player goes forward
		
	float playerSpeed;		// Player's speed
	float maxSpeed;			// Player's MaxSpeed

	int playerHp;			// Player's HP
	int playerHpMax;		// Player's MAX HP

	int playerDamage;		// Player's Damage

	float attackCool;		// player's attackCoolDown
	float attackCoolMax;	// player's attackCool Max

	sf::Vector2f dir;

public:
	//Constructor
	Player();
	//Destructor
	virtual ~Player();


	//Function
	void setPosition(const float X, const float Y);
	const int& getHp() const;
	const int& getHpMax() const;
	void setHP(const int HP);
	void loseHP(const int damage);
	void setDirection(float X, float Y);
	void setDamage(int x);
	void setAttackSpeed(float x);
	void setSpeed(float x);

	const int getDamage() const;
	const float getAttackSpeed() const;
	const float getSpeed() const;
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPosition() const;
	const sf::Vector2f& getDirection() const;

	void move(float X, float Y);

	//만약 attackCool이 attackCoolMax보다 커지면 공격을 하는 방식으로 공격속도 설정
	//그래서 update 함수에 넣어둠
	const bool canAttack();
	void updateAttack();

	void update();
	void render(sf::RenderTarget& target);
};