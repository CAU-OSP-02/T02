#pragma once

#include "Animation.hpp"


// Base of all objects
class Entity
{
public: // Can access to child class
	
	float xPos;	//x position
	float yPos;	//y position
	float dX;	//delta X
	float dY;	//delta Y
	
	float R;	//radius
	float angle;    //angle

	bool life;	//object's life


	std::string name;
	Animation anim;	//sprite's animation



	//Constructor
	Entity();
	//Destructor
	virtual ~Entity();
	

	//functions
	void settings(Animation& a, int x, int y, float Angle = 0.0f, int radius = 1);

	virtual void update();
	void draw(sf::RenderWindow& window); //drawing entity on the screen
	virtual string getName();


};


