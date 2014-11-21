#pragma once
#define OFFSET 15
#define TRISIZE 10 
#include "GlobalValues.h"
#include "Triangle.h"

enum SpawnType
{
	SPWN_ARROW,
	SPWN_LINE,
	SPWN_DIAGONAL,
	SPWN_CIRCLE
};


class Spawner
{

private:
	Triangle rightSpawn; 
	Triangle spawned[5];
	uint8_t spawnedSize; 

	void SpawnArrow(GlobalDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnCircle(GlobalDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnDiagonal(GlobalDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnLine(GlobalDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY);

	void UpdateValue(Triangle *tri, uint16_t posX, uint16_t posY, GlobalDirection dir); 

public:
	Spawner() : spawnedSize(0)
	{
		// FILL ARRAY.
		for (uint8_t i = 0; i < 5; i++)
		{
			spawned[i] = Triangle(); 
		}
		rightSpawn = Triangle(); 
	};
	~Spawner() {};

	void Update(); 
	void Render(Adafruit_ST7735 *tftDisplay);
	void Spawn(uint8_t amount, SpawnType spwnType, GlobalDirection correctDirection);
	void RandomSpawn(uint8_t amount); 
	
};

