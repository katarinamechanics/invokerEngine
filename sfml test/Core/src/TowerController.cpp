#include "../Header/TowerController.h"



TowerController::TowerController(EntityController& pECRef, sf::RenderWindow& pWindowRef, GuiObject& pGuiConRef, TileController& pTileConRef)
	:
	ECRef(pECRef),
	windowRef(pWindowRef),
	GuiConRef(pGuiConRef),
	TileConRef(pTileConRef)
{
	std::cout << "tower controller" << std::endl;
}

TowerController::~TowerController()
{
}

void TowerController::requestEntityListUpdate(sf::Clock& pDeltaTime)
{
	ECRef.update(pDeltaTime);
}

void TowerController::createEnemy()
{
}

void TowerController::createTower()
{
}

void TowerController::createProjectile()
{
}

void TowerController::update(sf::Clock& pDeltaTime)
{
	requestEntityListUpdate(pDeltaTime);

}
