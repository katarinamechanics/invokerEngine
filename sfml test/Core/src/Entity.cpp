#include "../Header/Entity.h"

Entity::Entity(sf::RenderWindow& pWindowRef, sf::Vector2f pPos)
	:
	windowRef(pWindowRef),
	position(pPos)
{
	sf::Texture tempTexture;
	if (!tempTexture.loadFromFile("Resources/Image/icon50.png"))
	{
		std::cout << "error loaduing textire" << std::endl;
	}

	if (tempTexture.getSize() == sf::Vector2u(0, 0))
	{
		std::cout << "Texture size is 0, 0" << std::endl;
	}

	entitySprite.setPosition(position);

	debugTexture = tempTexture;
}

Entity::~Entity()
{
}

void Entity::debugDrawEntity()
{	
	windowRef.draw(entitySprite);
}

void Entity::debugCheckTexture()
{
	if (entitySprite.getTexture() == nullptr) {
		std::cout << "Sprite doesn't have a texture set!" << std::endl;
	}
}

void Entity::debugSetTexture()
{
	entitySprite.setTexture(debugTexture);
}

Entity::eEntityType Entity::debugReturnType()
{
	return entityType;
}


void Entity::update(sf::Clock pDeltaTime)
{
	float distaceToMove = moveSpeed * pDeltaTime.getElapsedTime().asSeconds();

	sf::Vector2f newPosition = position + sf::Vector2f(distaceToMove, 0.0f);

	entitySprite.setPosition(newPosition);

	position = newPosition;

	std::cout << entityType << std::endl;
}
