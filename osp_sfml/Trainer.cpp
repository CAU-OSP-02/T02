#include "Trainer.hpp"

//Constructor
Trainer::Trainer()
{
	name = "TRAINER";

	villainHP = 7;
	villainSpeed = 10;
	attackSpeed = 10;
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


