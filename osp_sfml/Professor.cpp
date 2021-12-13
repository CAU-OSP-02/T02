#include "Professor.hpp"

//Constructor
Professor::Professor()
{
	name = "PROFESSOR";

	villainHP = 5;
	villainSpeed = 10;
}

//Destructor
Professor::~Professor()
{
	
}


void Professor::attack()
{
	
	// Villain's attack

}


void Professor::update()
{
	//  REVISED - 20211209
	//  Automating the villain's attack on the player
	
	this->attack();
}



