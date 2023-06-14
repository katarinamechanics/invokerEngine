#include "../Header/EntityController.h"


#include <vector>

EntityController::EntityController(sf::RenderWindow& pWindowRef)
	:
	windowRef(pWindowRef)
{
	
}

EntityController::~EntityController()
{
}

void EntityController::addEntity()
{
	entityStack.push_back(new Tower(windowRef, sf::Vector2f(debugPosX, debugPosY)));
	entityStack.back()->debugSetTexture();
}

void EntityController::update(sf::Clock deltaTime)
{
	for (auto& entity : entityStack) 
	{
		entity->update(deltaTime);
	}
}

void EntityController::draw(sf::RenderWindow& pWindow)
{
	for (auto& entity : entityStack) 
	{
		entity->debugDrawEntity();
	}
}
