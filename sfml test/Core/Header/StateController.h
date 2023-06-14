#pragma once

#include "../Header/EntityController.h"
#include "../Header/TowerController.h"
#include "../Header/GuiObject.h"
#include "../Header/TileController.h"

class StateController
{
public:
	enum eState
	{
		MAIN,
		TOWERMAIN,
		TOWER
	};

	StateController(GuiObject& pGuiConRef, sf::RenderWindow& pWindowRef, EntityController& pECRef, sf::Clock& pDeltaTime, TileController& pTileConRef);
	~StateController();

	void createTowerController();

	void changeStateToMain();
	void changeStateToTowerMain();
	void changeStateToTower();
	void update(sf::Clock& pDeltaTime);

private:
	GuiObject& GuiConRef;
	sf::RenderWindow& windowRef;
	sf::Clock& deltaTime;
	EntityController& ECRef;
	TileController& TileConRef;
	TowerController TowerCon = TowerController(ECRef, windowRef, GuiConRef, TileConRef);
	

	eState currentState;
};

