#pragma once

#include "../Header/Enemy.h"
#include "../Header/Tower.h"

class EntityController
{
public:
	EntityController(sf::RenderWindow& pWindowRef);
	~EntityController();

	//Entity createEntity(sf::Vector2f pPosition);
	void addEntity();
	void update(sf::Clock deltaTime);
	void draw(sf::RenderWindow& pWindow);

	float debugPosX;
	float debugPosY;
private:
	std::vector<Entity*> entityStack;
	sf::RenderWindow& windowRef;
};
