#pragma once
#include "Headers.h"
class Boss
{
private:
	sf::Sprite shape;
	sf::Texture texture_1;
	sf::Texture texture_2;
	sf::RectangleShape hpBar;
	sf::RectangleShape hpBarBack;
	sf::Vector2f direction;
	 
	float speed = 0.f;
	float attackCool = 0.f;
	float attackCoolMax = 0.f;
	int type = 0;
	sf::Vector2f dir;
	int point = 0;
	int hp = 0;
	int hpMax = 0;
	int damage = 0;
	
	bool reachTrue = true;

public:
	Boss(float posX, float posY, int type);
	~Boss();

	const sf::FloatRect getBounds() const;
	const sf::Vector2f getPosition() const;
	const int& getHp() const;
	const int& getHpMax() const;
	const int& getPoints() const;
	const sf::Vector2f& getDir() const;
	const int& getType() const;

	void setHp(const int hp);
	void loseHp(const int damage);
	void setDir(float X, float Y);
	void setBound(bool a);
	const int& getDamage() const;
	const float& getAttackSpeed() const;
	const bool canAttack();
	void updateAttack();

	void move();
	void update();
	void render(sf::RenderTarget* target);
};

