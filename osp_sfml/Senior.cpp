#include "Senior.hpp"

//Constructor
Senior::Senior()
{
	name = "SENIOR";

	villainHP = 5;
	villainSpeed = 10;
	attackSpeed = 10;
}

//Destructor
Senior::~Senior()
{
	
}


void Senior::attack()
{
	
	// Villain's attack

}


void Senior::update()
{
	//  REVISED - 20211209
	//  Automating the villain's attack on the player
	
	this->attack();
}


