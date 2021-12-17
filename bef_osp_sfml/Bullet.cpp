#include "Bullet.hpp"

//Constructor
Bullet::Bullet()
{
	name = "BULLET";
}

//Destructor
Bullet::~Bullet()
{

}

//Function
void Bullet::update()
{
	dX = cos(angle * DEGTORADI) * 6;
	dY = sin(angle * DEGTORADI) * 6;

	angle += rand() % 7 - 3;

	xPos += dX;
	yPos += dY;
	
	// If bullets go out of the screen
	if (xPos > screenW || xPos<0 || yPos>screenH || yPos < 0)
	{
		life = 0;
	}

}
