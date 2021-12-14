#pragma once
#include "Villain.hpp"

class Trainer : public Villain
{
public:
	float villainSpeed;	// Villain's speed
	float maxSpeed;		// Villain's max speed
	float attackSpeed;	// Villain's attack speed

        int villainHP;		// Villain's HP

	//Constructor
	Trainer();
	
	//Destructor
	~Trainer();


	void update();
	
};






	




