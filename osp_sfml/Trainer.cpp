#include "Trainer.hpp"

//Constructor
Trainer::Trainer()
{
	name = "TRAINER";

<<<<<<< HEAD
	villainHP = 5;
=======
	villainHP = 7;
>>>>>>> f402315bf2cd73dfd8c6f8b950415c317b90dbfb
	villainSpeed = 10;
}

//Destructor
Trainer::~Trainer()
{
	
}


void Trainer::attack()
{
	
	// Villain's attack

}


void Trainer::update()
{
	//  REVISED - 20211209
	//  Automating the villain's attack on the player
	
	this->attack();
}


