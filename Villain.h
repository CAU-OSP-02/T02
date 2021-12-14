#pragma once
#include "Headers.h"

class Villain
{
private:
	
	sf::Sprite shape;
	sf::Texture texture_1;
	sf::Vector2f direction;

	float speed;
	int hp;
	int hpMax;


public:
	//type�� ���� �� ������ ������.
	//1. �ΰ� ��������
	//2. �ｺ Ʈ���̳�
	//3. ���� ����

	Villain(float posX, float posY, int type);
	~Villain();

	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(const int hp);
	void loseHp(const int damage);

	void attack();
	void move();
	void update();
	void render(sf::RenderTarget* target);
};

