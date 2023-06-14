#include "../Header/GuiObject.h"

GuiObject::GuiObject(sf::RenderWindow& pWindowRef, EntityController& pECRef)
	:
	windowRef(pWindowRef),
	ECRef(pECRef)
{
	ImGui::SFML::Init(windowRef);

}

GuiObject::~GuiObject()
{
}

void GuiObject::renderFrame(sf::Clock pDeltaTime)
{

	ImGui::SFML::Update(windowRef, pDeltaTime.getElapsedTime());

	renderMainMenu();

}

void GuiObject::renderMainMenu()
{
	ImGui::Begin("Main Menu");

	ImGui::Text("Debug Mode");

	if (ImGui::Button("Tower"))
	{
		//controllerRef.setStateToPerlin();
	}
	if (ImGui::Button("do it to em"))
	{
		ECRef.addEntity();
	}
	if (ImGui::Button("Exit"))
	{

	}

	ImGui::SliderFloat("posX", &ECRef.debugPosX, 0.0f, 1900.0f);
	ImGui::SliderFloat("posY", &ECRef.debugPosY, 0.0f, 1000.0f);

	ImGui::End();
}

void GuiObject::renderTowerMenu()
{
}
