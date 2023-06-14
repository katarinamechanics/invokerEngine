
#include "../Header/Tile.h"

Tile::Tile(sf::RenderWindow& pWindowRef, sf::Vector2f pPos, sf::Texture& pTextureAtlas, eTileType pTileType)
	:
	windowRef(pWindowRef),
	position(pPos),
	textureAtlas(pTextureAtlas),
	tileType(pTileType)
{
	tileSetup();
}

Tile::~Tile()
{
}

void Tile::Update(sf::Vector2i pMousePos)
{
	mousePos = pMousePos;

	checkHover(pMousePos);
}

void Tile::Draw()
{
	if (isHover == true)
	{
		entitySprite.setColor(tint);
	}
	else
	{
		entitySprite.setColor(sf::Color::White);
	}

	windowRef.draw(entitySprite);
}

void Tile::tileSetup()
{
	entitySprite.setTexture(textureAtlas);

	switch (tileType)
	{
	case Grass: // 6h , 19 w
		entitySprite.setTextureRect(sf::IntRect(608, 192, tileWidth, tileHeight));
	}

	entitySprite.setPosition(position);
	entitySprite.setScale(2.0f, 2.0f);

}

void Tile::setHover(bool pIsHover)
{
	isHover = pIsHover;
}

bool Tile::getHover()
{
	return isHover;
}

void Tile::checkHover(sf::Vector2i& pMousePos)
{
	if (((pMousePos.x > position.x) && (pMousePos.x < (position.x + 64))) && ((pMousePos.y > position.y) && (pMousePos.y < (position.y + 64))))
	{
		isHover = true;
	}
	else
	{
		isHover =  false;
	}
	
}
