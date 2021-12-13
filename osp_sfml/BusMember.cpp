#include "BusMember.hpp"

//Constructor
BusMember::BusMember()
{
	name = "BUSMEMBER";

	villainHP = 5;
	villainSpeed = 10;
}

//Destructor
BusMember::~BusMember()
{
	
}


void BusMember::attack()
{
	
	// Villain's attack

}


void BusMember::update()
{
	//  REVISED - 20211209
	//  Automating the villain's attack on the player
	
	this->attack();
}



