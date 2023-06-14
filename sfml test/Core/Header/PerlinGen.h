#pragma once

#include <SFML/Graphics.hpp>
#include <noise/noise.h>
#include <iostream>

#include <random>
#include <chrono>
#include <vector>

#include <utility>
#include <type_traits>
#include <typeinfo>

#include "noise/noiseutils.h"

class PerlinObj
{
public:
	PerlinObj(int pWidth);
	~PerlinObj();
	void objSetup();
	void GeneratePerlinNoise();
	void GenerateMountainNoise();
	void GenerateBillowNoise();

	void GenerateRandom();

	void SetPerlinGradient();
	void SetMountainGradient();

	void SetNoiseParam();

	void RenderMap();

	sf::Sprite GetSprite();
	float noiseFreq; //0-1
	float noisePersist;//0-1
	float noiseLac; //1.5-3.5
	int noiseOctive = 4;
	int noiseSeed = 1;

private:
	noise::module::Perlin perlin;
	noise::module::RidgedMulti mountainTerrain;
	noise::module::Billow baseFlatTerrain;

	noise::utils::NoiseMap heightMapNP;
	noise::utils::NoiseMapBuilderPlane heightMapBuilder;

	
	utils::WriterBMP writer;

	noise::utils::RendererImage renderer;
	noise::utils::Image image;

	int mapWidth;
	const static int mapHeight = 1080;

	double xCoord, yCoord;
	float normalizedHeight;
	int randNumb;
	float scaledRandomNumber;


	sf::Image heightMapImage;
	sf::Texture heightMapTexture;
	sf::Sprite heightMapSprite;
};
