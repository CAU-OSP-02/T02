#include "FingerPrincess.hpp"

//Constructor
FingerPrincess::FingerPrincess()
{
	name = "FING_P";

	villainHP = 5;
	villainSpeed = 10;
}

//Destructor
FingerPrincess::~FingerPrincess()
{
	
}


void FingerPrincess::attack()
{
	
	// Villain's attack

}


void FingerPrincess::update()
{
	//  REVISED - 20211209
	//  Automating the villain's attack on the player
	
	this->attack();
}

