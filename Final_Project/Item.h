#pragma once
#include "Headers.h"

class Item
{
private:

	sf::Sprite shape;
	sf::Texture texture_1;
	sf::Vector2f direction;

	int type = 0;
	
	float attackSpeed = 0.f;
	float speed = 0.f;
	float ratio = 0.f;
	int hp = 0;

public:
	//type�� ���� �� ������ ������.
	// 1. �Ȱ�
	// 2. ����
	// 3. Ŀ��
	// 4. ������

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