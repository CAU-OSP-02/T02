#pragma once
#include "Headers.h"

class Villain
{
private:
	
	sf::Sprite shape;
	sf::Texture texture_1;
	sf::Texture texture_2;
	sf::Texture texture_3;
	sf::Texture texture_4;
	sf::Texture texture_5;
	sf::Vector2f direction;

	float speed = 0.f;
	float attackCool = 0.f;
	float attackCoolMax = 0.f;
	int hp = 0.f;
	int hpMax = 0.f;
	int damage = 0.f;
	float speedDown = 0.f;


public:
	//type에 따라서 디섯 가지로 나뉜다.
	// 1. 핑거 프린세스
	// 2. 헬스 트레이너
	// 3. 팀플 버스
	// 4. 꼰대 선배

	Villain(float posX, float posY, int type);
	~Villain();

	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(const int hp);
	void loseHp(const int damage);
	const int& getDamage() const;
	const float& getAttackSpeed() const;
	const float& getSpeedDown() const;

	void move();
	void update();
	void render(sf::RenderTarget* target);
};

