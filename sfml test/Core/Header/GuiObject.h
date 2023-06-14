#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "imgui/imgui_impl_opengl3.h"
#include "../Header/PerlinGen.h"
#include "../Header/EntityController.h"

class GuiObject
{
public:
	GuiObject(sf::RenderWindow& pWindowRef, EntityController& pECRef);
	~GuiObject();

	void renderFrame(sf::Clock pDeltaTime);
	void renderMainMenu();
	void renderTowerMenu();

private:

	sf::RenderWindow& windowRef;

	EntityController& ECRef;

};

