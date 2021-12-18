#pragma once
#include "Headers.h"

class Villain
{
private:
	
	sf::Sprite shape;
	sf::Texture texture_1;
	sf::Texture texture_2;
	sf::Vector2f direction;

	float speed = 0.f;
	float attackCool = 0.f;
	float attackCoolMax = 0.f;
	sf::Vector2f dir;
	int point = 0;
	int hp = 0;
	int hpMax = 0;
	int damage = 0;
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
	const sf::Vector2f getPosition() const;
	const int& getHp() const;
	const int& getHpMax() const;
	const int& getPoints() const;
	const sf::Vector2f& getDir() const;

	void setHp(const int hp);
	void loseHp(const int damage);
	void setDir(float X, float Y);
	const int& getDamage() const;
	const float& getAttackSpeed() const;
	const float& getSpeedDown() const;

	void move();
	void update();
	void render(sf::RenderTarget* target);
};