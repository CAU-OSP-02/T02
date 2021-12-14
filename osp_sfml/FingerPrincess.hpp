#pragma once
#include "Villain.hpp"

class FingerPrincess : public Villain
{
public:
	float villainSpeed;	// Villain's speed
	float maxSpeed;		// Villain's max speed
	float attackSpeed;	// Villain's attack speed

        int villainHP;		// Villain's HP

	//Constructor
	FingerPrincess();
	
	//Destructor
	~FingerPrincess();


	void update();
	
};






	



