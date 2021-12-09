#include "FingerPrincess.hpp"

//Constructor
Villain::Villain()
{
	name = "FINGP";

	villainHP = 5;
	villainSpeed = 10;
}

//Destructor
Villain::~Villain()
{
	
}


void Villain::attack()
{
	
	// Villain's attack

}


void Villian::update()
{
	//  REVISED - 20211209
	//  Automating the villain's attack on the player
	
	this->attack();
}

