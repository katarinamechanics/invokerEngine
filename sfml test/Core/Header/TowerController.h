#pragma once

#include "../Header/EntityController.h"
#include "../Header/GuiObject.h"
#include "../Header/TileController.h"

class TowerController
{
public:

	TowerController(EntityController& pECRef, sf::RenderWindow& pWindowRef, GuiObject& pGuiConRef, TileController& pTileConRef);
	~TowerController();

	void requestEntityListUpdate(sf::Clock& pDeltaTime);
	void createEnemy();
	void createTower();
	void createProjectile();

	void update(sf::Clock& pDeltaTime);
private:

	EntityController& ECRef;
	sf::RenderWindow& windowRef;
	GuiObject& GuiConRef;
	TileController& TileConRef;
	

	unsigned int playerLives;
	unsigned int playerGold;
	unsigned int waveNumber;
};

