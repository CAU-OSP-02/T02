#include "Entity.hpp"


// Constructor
Entity::Entity()
{
	xPos = 0;	// x position
	yPos = 0;	// y position
	dX = 0;		// delta X
	dY = 0;		// delta Y
	
	R = 0.0f;	// radius
	angle =0;	// angle

	life = 1; 
}

// Destructor
Entity::~Entity()
{

}


// Functions
void Entity::settings(Animation& a, int x, int y, float Angle , int radius)
{       
	anim = a;	// Apply animation

	xPos = x;
	yPos = y;

	
	angle = Angle;
	R = radius;     // Collision-check boundary

}

void Entity::update()
{

}

void Entity::draw(sf::RenderWindow& window) //drawing entity on the screen
{
	anim.sprite.setPosition(xPos, yPos);
	anim.sprite.setRotation(angle + 90);
	window.draw(anim.sprite);


	
	// Coliision Check
	sf::CircleShape circle(R);
	circle.setFillColor(sf::Color(255, 0, 0, 170));
	circle.setPosition(xPos, yPos);
	circle.setOrigin(R, R);

	// window.draw(circle);

}

string Entity::getName()
{
	return name;
}
