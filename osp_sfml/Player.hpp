#pragma once
#include "Entity.hpp"


class Player : public Entity //Inheritance
{
public:
	bool powerBool;			// If player goes forward

	float playerSpeed;		// Player's speed
	float maxSpeed;			// Player's MaxSpeed

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	int playerHP;			// Player's HP
	int playerHP_MAX;		// Player's MAX HP

	int playerSCORE;		// Player's SCORE

	int playerBullet;		//number of player's bullets

	

	//Constructor
	Player();
	//Destructor
	virtual ~Player();


	//Function
	const int& getHp() const;
	const int& getHpMax() const;
	void setHP(const int HP);
	void loseHP(const int damage);


	void update();

};



