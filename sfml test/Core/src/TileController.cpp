#include "../Header/TileController.h"


TileController::TileController(sf::RenderWindow& pWindowRef, const int pMapHeight, const int pMapWidth)
	:
	windowRef(pWindowRef)
{
	setTextureAtlas();
	createbackground();
}

TileController::~TileController()
{
}

void TileController::update(sf::Clock deltaTime, sf::Vector2i& pMousePos)
{
	mousePos = pMousePos;

	for (auto& tempTile : tileMap)
	{
		tempTile->Update(pMousePos);
	}
}

void TileController::draw(sf::RenderWindow& pWindow)
{
	for (auto& tempTile : tileMap)
	{
		tempTile->Draw();
	}
}

void TileController::setTextureAtlas()
{
	sf::Texture tempTexture;
	if (!tempTexture.loadFromFile("Resources/Image/Tilemap/Tileset-Terrain2.png"))
	{
		std::cout << "error loaduing textire atlas" << std::endl;
	}
	std::cout << "atlas loaded" << std::endl;
	textureAtlas1 = tempTexture;
}

void TileController::createbackground()
{
	int tempID = 0;
	for (int y = 0; y < mapHeight; y++)
	{
		tempID++; //give tiles an ID
		for (int x = 0; x < mapWidth; x++)
		{
			tileMap.push_back(new Tile(windowRef, sf::Vector2f(x * tileWidth, y * tileHeight), textureAtlas1, Grass));
			std::cout << "X: " << x * tileWidth << std::endl;
		}
	}
}


