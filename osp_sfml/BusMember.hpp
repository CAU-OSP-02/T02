#pragma once
#include "Villain.hpp"

class BusMember : public Villain
{
public:
	float villainSpeed;	// Villain's speed
	float maxSpeed;		// Villain's max speed

        int villainHP;		// Villain's HP

	//Constructor
	BusMember();
	
	//Destructor
	~BusMember();


	void update();
	
};





