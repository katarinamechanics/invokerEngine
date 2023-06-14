#pragma once
#include "../Header/Entity.h"

class Tower : public Entity
{
public:
	Tower(sf::RenderWindow& pWindowRef, sf::Vector2f pPos) : Entity(pWindowRef, pPos) { towerSetup(); };
	virtual ~Tower();

	void towerSetup();

	void update(sf::Clock pDeltaTime) override;
private:
	eEntityType entityType = TOWER;

	float attackSpeed;
};

