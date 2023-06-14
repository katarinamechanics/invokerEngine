#pragma once
#include "../Header/Tile.h"


class TileController
{
public:
	TileController(sf::RenderWindow& pWindowRef, const int pMapHeight, const int pMapWidth);
	~TileController();

	void update(sf::Clock deltaTime, sf::Vector2i& pMousePos);
	void draw(sf::RenderWindow& pWindow);

	void setTextureAtlas();
	void createbackground();


private:
	sf::RenderWindow& windowRef;
	sf::Vector2i mousePos;

	sf::Texture textureAtlas1;

	const int tileWidth = 64;
	const int tileHeight = 64;

	const int mapHeight  = 16;
	const int mapWidth = 30;

	std::vector<Tile*> tileMap;

}; // create tile grid

