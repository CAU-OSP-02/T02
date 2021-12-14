#pragma once
#include "Headers.h"

class Item
{
private:

	sf::Sprite shape;
	sf::Texture texture_1;
	sf::Texture texture_2;
	sf::Texture texture_3;
	sf::Texture texture_4;
	sf::Vector2f direction;

	int type = 0;
	
	float attackSpeed = 0.f;
	float speed = 0.f;
	float ratio = 0.f;
	int hp = 0;

public:
	//type에 따라서 네 가지로 나뉜다.
	// 1. 안경
	// 2. 연필
	// 3. 커피
	// 4. 스쿠터

	Item(float posX, float posY, int type);
	~Item();

	const sf::FloatRect getBounds() const;
	const int& getType() const;
	const float& getAttackSpeed() const;
	const float& getSpeed() const;
	const float& getRatio() const;
	const int& getHp() const;
	void render(sf::RenderTarget* target);
};