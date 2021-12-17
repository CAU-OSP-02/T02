#pragma once
#include "Headers.h"

class Player //Inheritance
{
private:

	sf::Sprite shape;
	sf::Texture texture;

	bool powerBool;			// If player goes forward
		
	float playerSpeed;		// Player's speed
	float maxSpeed;			// Player's MaxSpeed

	int playerHp;			// Player's HP
	int playerHpMax;		// Player's MAX HP

	int playerDamage;		// Player's Damage
	int playerScore;		// Player's SCORE

	int playerBullet;		//number of player's bullets

	float attackCool;		// player's attackCoolDown
	float attackCoolMax;	// player's attackCool Max

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

	const int& getScore() const;
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPosition() const;

	//TO ���� �����̴� �� ���Ƿ� ������ �α� ������ �ٲ㵵 ���� ��� �����ϴ�
	void move(const float X, const float Y);

	//���� attackCool�� attackCoolMax���� Ŀ���� ������ �ϴ� ������� ���ݼӵ� ����
	//�׷��� update �Լ��� �־��
	const bool canAttack();
	void updateAttack();

	void update();
	void render(sf::RenderTarget& target);
};