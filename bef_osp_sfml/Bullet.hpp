#pragma once
#include "Entity.hpp"

class Bullet : public Entity
{
public:

	//Constructor
	Bullet();

	//Destructor
	virtual ~Bullet();

	//Function
	void update();

};


