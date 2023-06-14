#pragma once
#include "../Header/GuiObject.h"
#include "../Header/Auxillary.h"

class Tile
{
public:
	Tile(sf::RenderWindow& pWindowRef, sf::Vector2f pPos, sf::Texture& pTextureAtlas, eTileType pTileType);
	~Tile();

	void Update(sf::Vector2i pMousePos);
	void Draw();
	//bool checkMousePos();

	void tileSetup();

	void setHover(bool pIsHover);
	bool getHover();
	void checkHover(sf::Vector2i& pMousePos);

protected:
	sf::RenderWindow& windowRef;
	sf::Vector2f position;
	sf::Sprite entitySprite;
	sf::Vector2i mousePos;

	sf::Texture debugTexture;
	sf::Texture& textureAtlas;

	sf::Color tint = sf::Color(255, 0, 0, 128);

	int tileIndex;
	const int tileWidth = 32;
	const int tileHeight = 32;

	bool isHover;

	eTileType tileType;
};

