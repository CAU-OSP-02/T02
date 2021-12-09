#pragma once
#include "Villain.hpp"

class FingerPrincess : public Villain
{
public:
	float villainSpeed;	// Villain's speed
	float maxSpeed;		// Villain's max speed

        int villainHP;		// Villain's HP

	//Constructor
	Villain();
	
	//Destructor
	~Villain();


	void update();
	
};






	



