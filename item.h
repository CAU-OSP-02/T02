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

	float speed;
	int hp;
	int hpMax;

public:
	//type에 따라서 세 가지로 나뉜다.
	// 1. 안경
	// 2. 연필
	// 3. 커피
	// 4. 스쿠터

	Item(float posX, float posY, int type);
	~Item();

	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(const int hp);
	void render(sf::RenderTarget* target);
};

