#include "../Header/StateController.h"

StateController::StateController(GuiObject& pGuiConRef, sf::RenderWindow& pWindowRef, EntityController& pECRef, sf::Clock& pDeltaTime, TileController& pTileConRef)
	:
	GuiConRef(pGuiConRef),
	windowRef(pWindowRef),
	ECRef(pECRef),
	deltaTime(pDeltaTime),
	TileConRef(pTileConRef)
{
	//TowerCon = TowerController(ECRef, windowRef, GuiConRef);
	std::cout << "statecontroller" << std::endl;
}

StateController::~StateController()
{
}

void StateController::createTowerController()
{
}

void StateController::changeStateToMain()
{
}

void StateController::changeStateToTowerMain()
{
}

void StateController::changeStateToTower()
{
}

void StateController::update(sf::Clock& pDeltaTime)
{
	TowerCon.update(pDeltaTime);

}
