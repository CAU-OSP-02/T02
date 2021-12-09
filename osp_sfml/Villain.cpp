#include "Villain.hpp"

//Constructor
Villain::Villain()
{
	name = "VILLAIN";

	villainHP = 5;
	villainSpeed = 10;
}

//Destructor
Villain::~Villain()
{
	cout << "Villain Die!!" << endl;
}



//Function
const int& Villain::getHp() const
{
	return this->villainHP;
}

void Villain::setHP(const int HP)
{
	this->villainHP = HP;
}

void Villain::loseHP(const int damage)
{
	this->villainHP -= damage;
	if (this->villainHP < 0)
	{
		this->villainHP = 0;
	}
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
