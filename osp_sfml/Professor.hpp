#pragma once
#include "Villain.hpp"

class Professor : public Villain
{
public:
	float villainSpeed;	// Villain's speed
	float maxSpeed;		// Villain's max speed
	float attackSpeed;	// Villain's attackspeed

        int villainHP;		// Villain's HP

	//Constructor
	Professor();
	
	//Destructor
	~Professor();


	void update();
	
};






	


