#pragma once
#include "../Header/Entity.h"
class Enemy : public Entity
{
public:
	Enemy(sf::RenderWindow& pWindowRef, sf::Vector2f pPos) : Entity(pWindowRef, pPos) { enemySetup(); };
	virtual ~Enemy();

	void enemySetup();
	void update(sf::Clock pDeltaTime) override;
private:
	int enemyHealth;

	eEntityType entityType = ENEMY;
};

