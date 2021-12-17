#pragma once

#include "Header.hpp"


class Animation
{
public:

	float Frame ;
	float frameSpeed ;

	sf::Sprite sprite;
	std::vector<sf::IntRect>frames;

	//Constructor
	Animation();
	//Destructor
	virtual ~Animation();


	Animation(sf::Texture& t, int x, int y, int w, int h, int count, float Speed);

	void frameUpdate();
	bool frameIsEnd();

};


