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
	//type�� ���� �� ������ ������.
	// 1. �Ȱ�
	// 2. ����
	// 3. Ŀ��
	// 4. ������

	Item(float posX, float posY, int type);
	~Item();

	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(const int hp);
	void render(sf::RenderTarget* target);
};

