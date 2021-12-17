#include "BusMember.hpp"

//Constructor
BusMember::BusMember()
{
	name = "BUSMEMBER";

	villainHP = 5;
<<<<<<< HEAD
	villainSpeed = 10;
=======
	villainSpeed = 14;
>>>>>>> f402315bf2cd73dfd8c6f8b950415c317b90dbfb
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



