#include "../Header/PerlinGen.h"


PerlinObj::PerlinObj(int pWidth)
{
	mapWidth = pWidth;
	

}

PerlinObj::~PerlinObj()
{
	
}

void PerlinObj::objSetup()
{
	heightMapImage.create(mapWidth, mapHeight);
}

void PerlinObj::GeneratePerlinNoise()
{
	//SetPerlinGradient();
	SetNoiseParam();
	heightMapBuilder.SetSourceModule(perlin);
	heightMapBuilder.SetDestNoiseMap(heightMapNP);
	heightMapBuilder.SetDestSize(mapWidth, mapHeight);
	heightMapBuilder.SetBounds(1.0, 6.0, 1.0, 5.0);
	heightMapBuilder.Build();
	RenderMap();	
}

void PerlinObj::GenerateMountainNoise()
{
	SetMountainGradient();
	SetNoiseParam();
	heightMapBuilder.SetSourceModule(mountainTerrain);
	heightMapBuilder.SetDestNoiseMap(heightMapNP);
	heightMapBuilder.SetDestSize(mapWidth, mapHeight);
	heightMapBuilder.SetBounds(1.0, 10.0, 1.0, 5.0);
	heightMapBuilder.Build();
	RenderMap();
}

void PerlinObj::GenerateBillowNoise()
{
	SetMountainGradient();
	SetNoiseParam();
	heightMapBuilder.SetSourceModule(baseFlatTerrain);
	heightMapBuilder.SetDestNoiseMap(heightMapNP);
	heightMapBuilder.SetDestSize(mapWidth, mapHeight);
	heightMapBuilder.SetBounds(1.0, 6.0, 1.0, 5.0);
	heightMapBuilder.Build();
	RenderMap();
}

void PerlinObj::GenerateRandom()
{
	srand((unsigned)time(0));
	scaledRandomNumber = (int)rand();
	
	noiseSeed = scaledRandomNumber;
}

void PerlinObj::SetPerlinGradient()
{
	renderer.ClearGradient();
	renderer.AddGradientPoint(-1.0000, noise::utils::Color(0, 0, 128, 255)); // deeps
	renderer.AddGradientPoint(-0.2500, utils::Color(0, 0, 255, 255)); // shallow
	renderer.AddGradientPoint(0.0000, utils::Color(0, 128, 255, 255)); // shore
	renderer.AddGradientPoint(0.0625, utils::Color(240, 240, 64, 255)); // sand
	renderer.AddGradientPoint(0.1250, utils::Color(32, 160, 0, 255)); // grass
	renderer.AddGradientPoint(0.3750, utils::Color(224, 224, 0, 255)); // dirt
	renderer.AddGradientPoint(0.7500, utils::Color(128, 128, 128, 255)); // rock
	renderer.AddGradientPoint(1.0000, utils::Color(255, 255, 255, 255)); // snow

	renderer.EnableLight();
	renderer.SetLightContrast(3.0);
}

void PerlinObj::SetMountainGradient()
{
	renderer.ClearGradient();
	renderer.AddGradientPoint(-1.00, utils::Color(32, 160, 0, 255)); // grass
	renderer.AddGradientPoint(-0.25, utils::Color(224, 224, 0, 255)); // dirt
	renderer.AddGradientPoint(0.25, utils::Color(128, 128, 128, 255)); // rock
	renderer.AddGradientPoint(1.00, utils::Color(255, 255, 255, 255)); // snow
}

void PerlinObj::SetNoiseParam()
{
	perlin.SetFrequency(noiseFreq);
	perlin.SetPersistence(noisePersist);
	//perlin.SetLacunarity(noiseLac);
	//perlin.SetNoiseQuality();
	perlin.SetOctaveCount(noiseOctive);
	perlin.SetSeed(noiseSeed);

	mountainTerrain.SetFrequency(noiseFreq);
	//mountainTerrain.SetPersistence(noisePersist);
	//mountainTerrain.SetLacunarity(noiseLac);
	//mountainTerrain.SetNoiseQuality();
	mountainTerrain.SetOctaveCount(noiseOctive);
	mountainTerrain.SetSeed(noiseSeed);

	baseFlatTerrain.SetFrequency(noiseFreq);
	baseFlatTerrain.SetPersistence(noisePersist);
	//baseFlatTerrain.SetLacunarity(noiseLac);
	//baseFlatTerrain.SetNoiseQuality();
	baseFlatTerrain.SetOctaveCount(noiseOctive);
	baseFlatTerrain.SetSeed(noiseSeed);
}

void PerlinObj::RenderMap()
{
	renderer.SetSourceNoiseMap(heightMapNP);
	renderer.SetDestImage(image);

	renderer.Render();

	writer.SetSourceImage(image);


	writer.SetDestFilename("workingMap.bmp");
	writer.WriteDestFile();

	heightMapTexture.loadFromFile("workingMap.bmp");
	heightMapSprite.setTexture(heightMapTexture);
}

sf::Sprite PerlinObj::GetSprite()
{
	return heightMapSprite;
}
