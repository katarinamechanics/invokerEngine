#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <iostream>

class Entity
{
public:
	enum eEntityType
	{
		DEBUG,
		TOWER,
		ENEMY
	};

	Entity(sf::RenderWindow& pWindowRef, sf::Vector2f pPos);
	virtual ~Entity();

	void debugDrawEntity();
	void debugCheckTexture();
	void debugSetTexture();
	eEntityType debugReturnType();

	virtual void update(sf::Clock pDeltaTime);
protected:
	sf::Sprite entitySprite;
	sf::Vector2f position;

	sf::Texture debugTexture;
	sf::Texture textureAtlas;

	sf::RenderWindow& windowRef;

	float moveSpeed = 20.0f;

	eEntityType entityType = DEBUG;

private:

};

