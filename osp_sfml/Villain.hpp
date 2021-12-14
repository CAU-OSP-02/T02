#pragma once
#include "Entity.hpp"

class Villain : public Entity
{
public:
	float villainSpeed;	// Villain's speed
	float maxSpeed;		// Villain's max speed
	float attackSpeed;	// Villain's attack speed

	sf::RectangleShape villianHpBar;
	sf::RectangleShape villianHpBarBack;

	int villainHP;		// Villain's HP



	//Constructor
	Villain();
	
	//Destructor
	~Villain();


	//Function
	const int& getHp() const;
	const int& getHpMax() const;
	void setHP(const int HP);
	void loseHP(const int damage);

	void attack(); // Villain's attack skill

	void update();
	
};


