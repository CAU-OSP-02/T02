
#pragma once

#include "Header.hpp"

#include "Animation.hpp"
#include "Entity.hpp"
#include "Audio.hpp"

#include "Player.hpp"
#include "Villain.hpp"
#include "Bullet.hpp"
#include "FingerPrincess.hpp"
#include "Senior.hpp"


class Settings
{
public:
	// Constructor
	Settings();
	// Destructor
	virtual ~Settings();

	// Functions
	void runGame(sf::RenderWindow& window);

};
